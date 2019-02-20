#include "mouseconfigtool.h"
#include "ui_mouseconfigtool.h"
#include "hidapi.h"
#include <QDebug>
#include <QFileDialog>

MouseConfigTool::MouseConfigTool(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MouseConfigTool)
{
    HIDDeviceIsOpen = false;
    ui->setupUi(this);
    mainGuiInit();
    hiddenMainGui();
    rfStatusTmr = new QTimer;
    connect(rfStatusTmr, SIGNAL(timeout()), this, SLOT(slot_rfStatusTmr()));
    rfStatusTmr->start(1000);
    ui->updateHexName->setReadOnly(true);
    connect(&usbReadThread, SIGNAL(postHIDDeviceOpen(bool)), this, SLOT(slot_getHIDDeviceIsOpen(bool)));// 接收线程传来设备是否开启的数据
    connect(&usbReadThread,SIGNAL(postRevData(QByteArray)),this,SLOT(slot_getRevData(QByteArray))); // 接收线程传来的数据
    connect(macroKey,SIGNAL(macroKey_signal(int, int, int, int)),this,SLOT(slot_getMacroKeyConfig(int, int, int, int)));
}

MouseConfigTool::~MouseConfigTool()
{
    delete ui;
}

void MouseConfigTool::mainGuiInit()
{
    mainQssFile = new QFile(":/qss/qss/mainWindows.qss",this);
    // 只读方式打开该文件
    mainQssFile->open(QFile::ReadOnly);
    // 读取文件全部内容
    QString styleSheet = QString(mainQssFile->readAll());
    // 为 QApplication 设置样式表
    qApp->setStyleSheet(styleSheet);
    mainQssFile->close();
}

void MouseConfigTool::hiddenMainGui()
{
    ui->getMacroKeyGroup->hide();
    ui->getCurrentDPIGroup->hide();
    ui->getCurrentLEDGroup->hide();
    ui->getDriverModeGroup->hide();
    ui->getCurrentPowerGroup->hide();
    ui->setDriverModeGroup->hide();
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
    setComboHIDBox();
    clearHIDDeviceInfoList();
}

void MouseConfigTool::getHIDDevceInfo()
{
    struct hid_device_info *devs, *cur_dev;
     devs = hid_enumerate(0x0, 0x0);
     cur_dev = devs;

     char HID[20],product[20],manufacturer[20],releaseNum[20],interfaceNum[20],
             VID[20],PID[20],usagePage[20],usage[20];
     while (cur_dev) {
 //        qDebug("Device Found\n  type: %04hx %04hx\n  path: %s\n  serial_number: %ls", cur_dev->vendor_id, cur_dev->product_id, cur_dev->path, cur_dev->serial_number);
 //        qDebug("\n");

    sprintf(HID,"VID:%x PID:%x",cur_dev->vendor_id,cur_dev->product_id);
    sprintf(product,"%ls",cur_dev->product_string);
    sprintf(manufacturer,"%ls",cur_dev->manufacturer_string);
    sprintf(releaseNum,"%hx",cur_dev->release_number);
    sprintf(interfaceNum,"%d",cur_dev->interface_number);
    sprintf(VID,"%x",cur_dev->vendor_id);
    sprintf(PID,"%x",cur_dev->product_id);
    sprintf(usagePage,"%d",cur_dev->usage_page);
    sprintf(usage,"%d",cur_dev->usage);
    HIDDeviceList.append(QString(HID));
    productList.append(QString(product));
    manufacturerList.append(QString(manufacturer));
    releaseNumList.append(QString(releaseNum));
    interfaceNumList.append(QString(interfaceNum));
    VIDList.append(QString(VID));
    PIDList.append(QString(PID));
    usagePageList.append(QString(usagePage));
    usageList.append(QString(usage));
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

void MouseConfigTool::setComboHIDBox()
{
    QStringList portItems;
    int portItemsCounts;
//    // 如果串口正在使用，然后串口定时刷新，当前串口字段依旧保留
//    if(m_serial->isOpen())
//    {
//      QString serialPort = m_serial->portName();
//      commPortList.insert(0,serialPort);
//    }
//    qDebug() << commPortList;
    if(! HIDDeviceList.isEmpty())
    {
        portItemsCounts = ui->comboHIDBox->count();
        for(int i = 0; i<portItemsCounts;i++)
        {
            portItems.append(ui->comboHIDBox->itemText(i));
        }
        if(portItems == HIDDeviceList)
        {
            return;
        }
        else
        {
          ui->comboHIDBox->clear();
          ui->comboHIDBox->addItems(HIDDeviceList);
        }
    }
    // 如果沒扫到 HID 设备，清空 HID 设备下拉框
    else
    {
        ui->comboHIDBox->clear();
    }
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
//    qDebug()<<"data 1:"<<aldata[1];
//    qDebug()<<"data 0:"<<aldata[0];
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
void MouseConfigTool::hexFileHandler()
{
    QFile file;
    QString f = QFileDialog::getOpenFileName(this,QString("选择文件"),QString("./"));
    file.setFileName(f);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QByteArray bufferLine;   // 读取文件每一行
        int HexSize = 0;
        alBufferLine.clear(); // 清空之前的 Buffer
        ui->updateHexName->setText(f);
        while(!file.atEnd())
        {
            bufferLine = file.readLine();
            bufferLine.remove(0,1);// 去掉冒号
            bufferLine.remove(bufferLine.size()-1,1);//过滤换行符
            HexSize += bufferLine.size();
            alBufferLine.append(bufferLine);

        }
        HexSize = HexSize / 2;
        hexSizeToLHStr(HexSize,alLHBufferSize);
        file.close();
    }
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


void MouseConfigTool::on_on_offBtn_clicked()
{
    unsigned short currentPID, currentVID;

    QString currentPIDText,currentVIDText;
    currentPIDText = ui->PIDLineEdit->text();
    currentVIDText = ui->VIDLineEdit->text();
//  下拉框选择端口打开，但是打开端口后，当前的串口并不能扫描出来，已被占用，显示有问题
//    currentPIDText = ui->comboHIDBox->currentText().right(4);
//    currentVIDText = ui->comboHIDBox->currentText().mid(4,4).simplified();
//    qDebug()<<currentPIDText;
//    qDebug()<<currentVIDText;
    currentPID = HexStrToUShort(currentPIDText,currentPIDText.length());
    currentVID = HexStrToUShort(currentVIDText,currentVIDText.length());
    usbReadThread.getOpenHIDDevice(currentPID,currentVID,!HIDDeviceIsOpen);// 调用线程函数去传递数据
    usbReadThread.start();
}
// 线程传递回来的设备是否开启参数，改变 UI 的开启关闭状态，同时将设备状态保存在当前类中
void MouseConfigTool::slot_getHIDDeviceIsOpen(bool isOpen)
{
    HIDDeviceIsOpen = isOpen;
    if(isOpen)
    {
        ui->on_offBtn->setText("关闭");
        ui->PIDLineEdit->setEnabled(false);
        ui->VIDLineEdit->setEnabled(false);
        HIDDeviceIsOpen = true;
    }
    else
    {
        HIDDeviceIsOpen = false;
        ui->on_offBtn->setText("打开");
        ui->PIDLineEdit->setEnabled(true);
        ui->VIDLineEdit->setEnabled(true);
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

void MouseConfigTool::slot_getMacroKeyConfig(int macroKey01, int macroKey02, int macroKey11, int macroKey12)
{
    if(HIDDeviceIsOpen)
    {
        userModePro.postMacroKeyNotify(macroKey01,macroKey02,macroKey11,macroKey12);
    }
}

void MouseConfigTool::on_getCurrentDeviceModeBtn_clicked()
{
    if(HIDDeviceIsOpen)
    {
        userModePro.getCurrentDeviceMode();
    }
}

void MouseConfigTool::on_getCurrentDPIModeBtn_clicked()
{
    if(HIDDeviceIsOpen)
    {
        userModePro.getCurrentDPIMode();
    }
}

void MouseConfigTool::on_getCurrentRGBModeBtn_clicked()
{
    if(HIDDeviceIsOpen)
    {
        userModePro.getCurrentRGBMode();
    }
}

void MouseConfigTool::on_getCurrentPowerBtn_clicked()
{
    if(HIDDeviceIsOpen)
    {
        userModePro.getCurrentPower();
    }
}

void MouseConfigTool::on_setMultiKeyBtn_clicked()
{
    if(HIDDeviceIsOpen)
    {
        macroKey->show();
    }
}


void MouseConfigTool::on_getMultiKeyBtn_clicked()
{
    if(HIDDeviceIsOpen)
    {
        userModePro.getCurrentMacroKeyConfig();
    }
}

void MouseConfigTool::on_selectHexFileBtn_clicked()
{
    if(HIDDeviceIsOpen)
    {
        hexFileHandler();
    }
}

void MouseConfigTool::on_updateButton_clicked()
{
    if(HIDDeviceIsOpen)
    {
        QString sBufferLine;
        QByteArray SendData;
        int nBufferLineIndex = 0;
        nBufferLineIndex = alBufferLine.size() - 1;
        userModePro.postEnterBootLoaderMode();
        userModePro.postUpdateDeviceInfo(alLHBufferSize);
        for(int i=0 ; i< alBufferLine.size(); i++)
        {
            bufferCountsToLHStr(nBufferLineIndex--,alLHBufferIndex);
            sBufferLine = alBufferLine[i];
            StringToHex(sBufferLine,SendData);
            userModePro.postUpdateFW(alLHBufferIndex, SendData);
        }
        userModePro.postExitBootLoaderMode();
        ui->updateHexName->clear();// 清空 Hex 文件路径
        alBufferLine.clear(); // 清空之前的 Buffer
        SendData.clear(); // 清空数据
    }
}
