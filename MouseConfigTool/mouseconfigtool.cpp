#include "mouseconfigtool.h"
#include "ui_mouseconfigtool.h"
#include "hidapi.h"
#include <QDebug>
#include <QFileDialog>
#include "QMouseEvent"
#include <QBitmap>

MouseConfigTool::MouseConfigTool(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MouseConfigTool)
{
    this->setWindowFlag(Qt::FramelessWindowHint); // 隐藏标题栏
    this->setFixedSize(1000,750); // 固定窗口大小
    HIDDeviceIsOpen = false; // 设备初始化未开启
    ui->setupUi(this);
    mainGuiInit(); // 窗口 UI 初始化
    hiddenMainGui(); // 窗口 UI 隐藏
    QSystemTrayIconInit(); // 操作系统托盘图标初始化
    rfStatusTmr = new QTimer; // 查询 HID 设备定时器
    connect(rfStatusTmr, SIGNAL(timeout()), this, SLOT(slot_rfStatusTmr()));
    rfStatusTmr->start(1000);
    connect(&usbReadThread, SIGNAL(postHIDDeviceOpen(bool)), this, SLOT(slot_getHIDDeviceIsOpen(bool)));// 接收线程传来设备是否开启的数据
    connect(&usbReadThread,SIGNAL(postRevData(QByteArray)),this,SLOT(slot_getRevData(QByteArray))); // 接收线程传来的数据
    connect(macros,SIGNAL(macros_signal(QByteArray)),this,SLOT(slot_getMacrosConfig(QByteArray))); // 接收按键宏配置
}

MouseConfigTool::~MouseConfigTool()
{
    delete ui;
}

void MouseConfigTool::QSystemTrayIconInit()
{
    // 新建托盘要显示的 icon
    QIcon icon = QIcon(":/hidmouse/images/mouseLogo.png");
    // 将 icon 设到 QSystemtrayIcon 对象中
    mSysTrayIcon->setIcon(icon);
    // 当鼠标移动到托盘上的图标时，会显示此处设置的内容
    mSysTrayIcon->setToolTip(QObject::tr("WPI 鼠标配置工具"));
    // 给 QSystemTrayIcon 添加槽函数
    connect(mSysTrayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason)));
    // 创建显示主界面和退出的行为
    createActions();
    // 创建菜单项
    createMenu();
    // 在系统托盘显示此对象
    mSysTrayIcon->show();
}

void MouseConfigTool::mainGuiInit()
{
    // 主界面 qss 文件载入
    mainQssFile = new QFile(":/qss/qss/mainWindows.qss",this);
    // 只读方式打开该文件
    mainQssFile->open(QFile::ReadOnly);
    // 读取文件全部内容
    QString styleSheet = QString(mainQssFile->readAll());
    // 为 QApplication 设置样式表
    qApp->setStyleSheet(styleSheet);
    mainQssFile->close();

    // 按键宏界面 qss 文件载入
    macroKeyQssFile = new QFile(":/qss/qss/macrokey.qss",this);
    // 只读方式打开该文件
    macroKeyQssFile->open(QFile::ReadOnly);
    // 读取文件全部内容
    styleSheet = QString(macroKeyQssFile->readAll());
    // 为 QApplication 设置样式表
    macroKeyQssFile->close();
    macros->setStyleSheet(styleSheet);

    // 设置界面 qss 文件载入
    settingQssFile = new QFile(":/qss/qss/setting.qss",this);
    // 只读方式打开该文件
    settingQssFile->open(QFile::ReadOnly);
    // 读取文件全部内容
    styleSheet = QString(settingQssFile->readAll());
    // 为 QApplication 设置样式表
    settingQssFile->close();
    config->setStyleSheet(styleSheet);
}

void MouseConfigTool::hiddenMainGui()
{
    ui->getDriverModeGroup->hide();
    ui->setDriverModeGroup->hide();

    ui->mouseStatus->hide();
    ui->mouseBtn->hide();
    ui->currentDPIGroup->hide();
    ui->currentLEDGroup->hide();
    ui->marcroKeyGroup->hide();
    ui->missDeviceLabel->hide();
}

void MouseConfigTool::mouseMoveEvent(QMouseEvent *event)
{
    if (m_pressed
            && (event->buttons() && Qt::LeftButton)
            && (event->globalPos() - m_movePos).manhattanLength() > QApplication::startDragDistance())
        {
            QPoint movePos = event->globalPos() - m_movePos;
            this->move(movePos);
            m_movePos = event->globalPos() - pos();
        }

        return QMainWindow::mouseMoveEvent(event);
}

void MouseConfigTool::mousePressEvent(QMouseEvent *event)
{
    m_pressed = true;

    m_movePos = event->globalPos() - pos();

    return QMainWindow::mousePressEvent(event);
}

void MouseConfigTool::mouseReleaseEvent(QMouseEvent *event)
{
    m_pressed = false;

    return QMainWindow::mouseReleaseEvent(event);
}

void MouseConfigTool::paintEvent(QPaintEvent *)
{
    // 窗口圆角处理
    QBitmap bmp(this->size());
    bmp.fill();
    QPainter p(&bmp);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::black);
    p.drawRoundedRect(bmp.rect(),20,20);
    setMask(bmp);

    ui->closeBtn->setCursor(QCursor(Qt::PointingHandCursor)); // 鼠标移动到窗口关闭按钮样式
    ui->configBtn->setCursor(QCursor(Qt::PointingHandCursor)); // 鼠标移动到设置按钮样式
}

void MouseConfigTool::Delay_Msec(int msec)
{
    QTime _Time = QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime()<_Time)
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

char MouseConfigTool::ConvertHexChar(char ch)
{
    if((ch >= '0') && (ch <= '9'))
    {
        return ch-0x30;
    }
    else if(ch >= 'A' && ch <= 'F')
    {
        return ch-'A'+10;
    }
    else if(ch >= 'a' && ch <= 'f')
    {
        return ch-'a'+10;
    }
    else return ch-ch;
}

void MouseConfigTool::StringToHex(QString str, QByteArray &sendData)
{
    char hexdata,lowhexdata;
    int hexdatalen = 0;
    int len = str.length();
    sendData.resize(len/2);
    char lstr,hstr;
    for (int i=0; i<len;) {
        hstr=str[i].toLatin1();
        if(hstr == ' ')
        {
//            qDebug()<< tr("null");
            i++;
            continue;
        }
        i++;
        if(i>=len)
        {
//            qDebug()<< tr("over");
            break;
        }
        lstr = str[i].toLatin1();
        hexdata = ConvertHexChar(hstr);
        lowhexdata = ConvertHexChar(lstr);
        if((hexdata == 16) || (lowhexdata == 16))
        {
//            qDebug()<< tr("error");
            break;
        }
        else
        {
            hexdata =  hexdata *16 + lowhexdata;
        }
        i++;
//        qDebug("转化为16进制数：%d",hexdata);
        sendData[hexdatalen] = hexdata;
        hexdatalen++;
    }
    sendData.resize(hexdatalen);
//    qDebug()<<sendData.length();
}

void MouseConfigTool::slot_rfStatusTmr()
{
    getHIDDevceInfo();
    clearHIDDeviceInfoList();
    // 找到指定设备，并打开，向设备请求当前鼠标状态
    if(HIDDeviceIsOpen & getCurrentMouseStatusFlag)
    {
        qDebug()<<"1111";
        getCurrentMouseStatusFlag = false;
        userModePro.getMouseCurrentStatus();
        ui->mouseStatus->show();
        ui->mouseBtn->show();
        ui->currentDPIGroup->show();
        ui->currentLEDGroup->show();
        ui->marcroKeyGroup->show();
        ui->missDeviceLabel->hide();
    }
    else if(!HIDDeviceIsOpen)
    {
        hiddenMainGui();
        ui->missDeviceLabel->show();
    }
}

void MouseConfigTool::getHIDDevceInfo()
{
    struct hid_device_info *devs, *cur_dev;
     devs = hid_enumerate(0x0, 0x0);
     cur_dev = devs;
//     char HID[20],product[20],manufacturer[20],releaseNum[20],interfaceNum[20],
//             VID[20],PID[20],usagePage[20],usage[20];
     while (cur_dev) {
 //        qDebug("Device Found\n  type: %04hx %04hx\n  path: %s\n  serial_number: %ls", cur_dev->vendor_id, cur_dev->product_id, cur_dev->path, cur_dev->serial_number);
 //        qDebug("\n");
    // 查找到指定设备打开设备
//    if(cur_dev->vendor_id == 1133 && cur_dev->product_id == 49286)
    if(cur_dev->vendor_id == 6785 && cur_dev->product_id == 8247)
    {
        // 若指定设备开启成功，则关闭查询 HID 设备定时器
        if(HIDDeviceIsOpen)
        {
            rfStatusTmr->stop();
        }
        else
        {
            usbReadThread.getOpenHIDDevice(8247,6785,!HIDDeviceIsOpen);// 调用线程函数去传递数据
//            usbReadThread.getOpenHIDDevice(49286,1133,!HIDDeviceIsOpen);// 调用线程函数去传递数据
            usbReadThread.start();
        }
        break;
    }
//    sprintf(HID,"VID:%x PID:%x",cur_dev->vendor_id,cur_dev->product_id);
//    sprintf(product,"%ls",cur_dev->product_string);
//    sprintf(manufacturer,"%ls",cur_dev->manufacturer_string);
//    sprintf(releaseNum,"%hx",cur_dev->release_number);
//    sprintf(interfaceNum,"%d",cur_dev->interface_number);
//    sprintf(VID,"%x",cur_dev->vendor_id);
//    sprintf(PID,"%x",cur_dev->product_id);
//    sprintf(usagePage,"%d",cur_dev->usage_page);
//    sprintf(usage,"%d",cur_dev->usage);
//    HIDDeviceList.append(QString(HID));
//    productList.append(QString(product));
//    manufacturerList.append(QString(manufacturer));
//    releaseNumList.append(QString(releaseNum));
//    interfaceNumList.append(QString(interfaceNum));
//    VIDList.append(QString(VID));
//    PIDList.append(QString(PID));
//    usagePageList.append(QString(usagePage));
//    usageList.append(QString(usage));
//    qDebug()<<HIDDeviceList;
//         qDebug("  Manufacturer: %ls\n", cur_dev->manufacturer_string);
//         qDebug("  Product:      %ls\n", cur_dev->product_string);
//         qDebug("  Release:      %hx\n", cur_dev->release_number);
//         qDebug("  Interface:    %d\n", cur_dev->interface_number);
//         qDebug("  path:    %s\n", cur_dev->path);
//         qDebug("  vendor_id:    %x\n", cur_dev->vendor_id);
//         qDebug("  product_id:    %x\n", cur_dev->product_id);
//         qDebug("  usage_page:    %d\n", cur_dev->usage_page);
//         qDebug("  usage:    %d\n", cur_dev->usage);
//         qDebug("\n");
         cur_dev = cur_dev->next;
     }
     hid_free_enumeration(devs);
}




void MouseConfigTool::clearHIDDeviceInfoList()
{
    HIDDeviceList.clear();
    productList.clear();
    manufacturerList.clear();
    releaseNumList.clear();
    interfaceNumList.clear();
    VIDList.clear();
    PIDList.clear();
    usagePageList.clear();
    usageList.clear();
}

void MouseConfigTool::bufferCountsToLHStr(int ndata, QByteArrayList &aldata)
{
    int nQuotient,nRemainder;
    int count = 0;
    QByteArray binSize; // 二进制缓存
    QByteArray IntSize; // 十进制缓存
    QByteArrayList alBinSize; // 二进制 Hex 文件的大小
    // 拆分二进制字符串，并将每一部分二进制字符串转换为十进制
    IntToBin(ndata,binSize);
    nQuotient = binSize.size() / 8;
    nRemainder = binSize.size() % 8;
    for(int i = 0 ; i<2; i++)
    {
        if(1 - nQuotient > 0)
        {
            alBinSize.insert(0,"");
            nQuotient++;
        }
        else
        {
            if( count == 0)
            {
                alBinSize.insert(0,binSize.left(nRemainder));
                binSize.remove(0,nRemainder);
                count++;
            }
            else
            {
                alBinSize.insert(0,binSize.mid((count-1)*8,8));
                count++;
            }
        }
    }
    aldata.clear();
    BinToInt(IntSize,alBinSize[0]);
    aldata.append(IntSize);
    BinToInt(IntSize,alBinSize[1]);
    aldata.append(IntSize);
}

void MouseConfigTool::hexSizeToLHStr(int ndata, QByteArrayList &aldata)
{
    int nQuotient,nRemainder;
    int count = 0;
    QByteArray binSize; // 二进制缓存
    QByteArray IntSize; // 十进制缓存
    QByteArrayList alBinSize; // 二进制 Hex 文件的大小
    // 拆分二进制字符串，并将每一部分二进制字符串转换为十进制
    IntToBin(ndata,binSize);
    nQuotient = binSize.size() / 8;
    nRemainder = binSize.size() % 8;
    for(int i = 0 ; i<4; i++)
    {
        if(3 - nQuotient > 0)
        {
            alBinSize.insert(0,"");
            nQuotient++;
        }
        else
        {
            if( count == 0)
            {
                alBinSize.insert(0,binSize.left(nRemainder));
                binSize.remove(0,nRemainder);
                count++;
            }
            else
            {
                alBinSize.insert(0,binSize.mid((count-1)*8,8));
                count++;
            }
        }
    }
    aldata.clear();
    BinToInt(IntSize,alBinSize[0]);
    aldata.append(IntSize);
    BinToInt(IntSize,alBinSize[1]);
    aldata.append(IntSize);
    BinToInt(IntSize,alBinSize[2]);
    aldata.append(IntSize);
    BinToInt(IntSize,alBinSize[3]);
    aldata.append(IntSize);
//    qDebug()<<"data 3:"<<alBinSize[3];
//    qDebug()<<"data 2:"<<alBinSize[2];
//    qDebug()<<"data 1:"<<alBinSize[1];
//    qDebug()<<"data 0:"<<alBinSize[0];
//    qDebug()<<"data 3:"<<aldata[3];
//    qDebug()<<"data 2:"<<aldata[2];
//    qDebug()<<"data 1:"<<aldata[1];
//    qDebug()<<"data 0:"<<aldata[0];
}

void MouseConfigTool::BinToInt(QByteArray &data, QString strBin)
{
    QString decimal;
    int nDec = 0,nLen;
    int i,j,k;
    nLen = strBin.length();
    for (i = 0 ; i<nLen ; i++) {
        if(strBin[nLen-i-1]=="0")
        {
            continue;
        }
        else
        {
            k = 1;
            for(j=0;j<i;j++)
            {
                k=k*2;
            }
            nDec += k;
        }
    }
    decimal = QString::number(nDec);
    data = decimal.toLatin1();
}

void MouseConfigTool::IntToBin(int data, QByteArray &binData)
{
    int nYushu, nShang;
    QString strBin, strTemp;
    bool bContinue = true;
    while( bContinue )
    {
        nYushu = data % 2;
        nShang = data / 2;
        strBin = QString::number(nYushu) + strBin;
        strTemp = strBin;
        data = nShang;
        if( nShang == 0)
        {
            bContinue = false;
        }
    }
    int nTemp = strBin.length() % 4;
    switch (nTemp) {
        case 1:
            strTemp = "000"+strBin;
            strBin = strTemp;
            break;
        case 2:
            strTemp = "00" + strBin;
            strBin = strTemp;
            break;
        case 3:
            strTemp = "0" + strBin;
            strBin = strTemp;
            break;
        default:
            break;
    }
    binData = strBin.toLatin1();
}

unsigned short MouseConfigTool::HexStrToUShort(QString str, int length)
{
    // 初始化变量为 0 ，否则会由于不明因素造成数据紊乱
    unsigned short tempData = 0;
    int data = 0;
    for(int i = 0; i< length; i++)
    {
        if((str[i]>='A') && (str[i]<= 'F'))
            data = str[i].toLatin1() - 'A' +10; // 字符串转字符
        else if((str[i]>='a')&&(str[i])<='f')
            data = str[i].toLatin1() - 'a' + 10;
        else data = str[i].toLatin1()-'0';
        tempData = tempData*16+data;
    }
    return tempData;
}


// 线程传递回来的设备是否开启参数，改变 UI 的开启关闭状态，同时将设备状态保存在当前类中
void MouseConfigTool::slot_getHIDDeviceIsOpen(bool isOpen)
{
    HIDDeviceIsOpen = isOpen;
    if(isOpen)
    {
        HIDDeviceIsOpen = true;
    }
    else
    {
        HIDDeviceIsOpen = false;
        rfStatusTmr->start(1000); // 若设备关闭，重新查询 HID 设备
        getCurrentMouseStatusFlag = true; // 推送获取当前设备状态标志位
    }
}

void MouseConfigTool::slot_getRevData(QByteArray data)
{
//    qDebug()<<data;
    if(!data.isEmpty())
    {
        userModePro.getReportDataStr(data,ReportID,CMDStatus,CMDID,DataLSB,DataMSB,DataLength,proData,checkSum);
        data = data.toHex().toUpper().simplified();
        int len = data.count()/2;
        for(int i = 1; i<len+1; i++)
        {
            data.insert(3*i-1," ");
        }
        QString strRecv = QString::fromLocal8Bit(data);
    }
}

void MouseConfigTool::on_DPIMode1Btn_clicked()
{
    if(HIDDeviceIsOpen)
    {
        userModePro.postDPIMode1Notify();
    }
}

void MouseConfigTool::on_DPIMode2Btn_clicked()
{
    if(HIDDeviceIsOpen)
    {
        userModePro.postDPIMode2Notify();
    }
}

void MouseConfigTool::on_DPIMode3Btn_clicked()
{
    if(HIDDeviceIsOpen)
    {
        userModePro.postDPIMode3Notify();
    }
}

void MouseConfigTool::on_DPIMode4Btn_clicked()
{
    if(HIDDeviceIsOpen)
    {
        userModePro.postDPIMode4Notify();
    }
}

void MouseConfigTool::on_RGBMode1Btn_clicked()
{
    if(HIDDeviceIsOpen)
    {
        userModePro.postRGBMode1Notify();
    }
}

void MouseConfigTool::on_RGBMode2Btn_clicked()
{
    if(HIDDeviceIsOpen)
    {
        userModePro.postRGBMode2Notify();
    }
}

void MouseConfigTool::on_RGBMode3Btn_clicked()
{
    if(HIDDeviceIsOpen)
    {
        userModePro.postRGBMode3Notify();
    }
}

void MouseConfigTool::on_RGBMode4Btn_clicked()
{
    if(HIDDeviceIsOpen)
    {
        userModePro.postRGBMode4Notify();
    }
}

void MouseConfigTool::on_setConfigModeBtn_clicked()
{
    if(HIDDeviceIsOpen)
    {
        userModePro.postConfigModeNotify();
    }
}

void MouseConfigTool::on_setNormalModeBtn_clicked()
{
    if(HIDDeviceIsOpen)
    {
        userModePro.postNormalModeNotify();
    }
}

void MouseConfigTool::slot_getMacrosConfig(QByteArray data)
{
    if(HIDDeviceIsOpen)
    {
        switch (macroKey) {
            case 1: userModePro.postMacrosNotify(data,macroKey);
                break;
            case 2: userModePro.postMacrosNotify(data,macroKey);
                break;
            default: break;
        }
        macroKey = 0;
    }
}

void MouseConfigTool::on_getCurrentDeviceModeBtn_clicked()
{
    if(HIDDeviceIsOpen)
    {
        userModePro.getCurrentDeviceMode();
    }
}

void MouseConfigTool::on_setMacroKey1Btn_clicked()
{
    if(HIDDeviceIsOpen)
    {
        macroKey = 1;
        macros->show();
    }
}

void MouseConfigTool::on_setMacroKey2Btn_clicked()
{
    if(HIDDeviceIsOpen)
    {
        macroKey = 2;
        macros->show();
    }
}

void MouseConfigTool::on_configBtn_clicked()
{
    if(HIDDeviceIsOpen)
    {
        config->show();
    }
}

void MouseConfigTool::on_closeBtn_clicked()
{
    // 隐藏主窗口
    this->hide();
}

void MouseConfigTool::on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
    // 左键单击托盘图标，显示主界面
        case QSystemTrayIcon::Trigger:
            this->show();
            break;
        default:
            break;
    }
}

void MouseConfigTool::createActions()
{
    mShowMainAction = new QAction(QObject::tr("显示主界面"),this);
    connect(mShowMainAction,SIGNAL(triggered()),this,SLOT(on_showMainAction()));

    mExitAppAction = new QAction(QObject::tr("退出"),this);
    connect(mExitAppAction,SIGNAL(triggered()),this,SLOT(on_exitAppAction()));
}

void MouseConfigTool::createMenu()
{
    mMenu = new QMenu(this);
    // 新增菜单项---显示主界面
    mMenu->addAction(mShowMainAction);
    //增加分隔符
    mMenu->addSeparator();
    //新增菜单项---退出程序
    mMenu->addAction(mExitAppAction);
    //把QMenu赋给QSystemTrayIcon对象
    mSysTrayIcon->setContextMenu(mMenu);
}

void MouseConfigTool::on_showMainAction()
{
    this->show();
}

void MouseConfigTool::on_exitAppAction()
{
    this->close();
}
