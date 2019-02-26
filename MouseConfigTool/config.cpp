#include "config.h"
#include "ui_config.h"
#include <QFileDialog>

Config::Config(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Config)
{
    ui->setupUi(this);
    this->setWindowTitle("用户设置");
    this->setFixedSize(450,400); // 固定窗口大小
    ui->updateHexName->setReadOnly(true); // 读取文件路径只读
}

Config::~Config()
{
    delete ui;
}

char Config::ConvertHexChar(char ch)
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

void Config::StringToHex(QString str, QByteArray &sendData)
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

void Config::BinToInt(QByteArray &data, QString strBin)
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

void Config::IntToBin(int data, QByteArray &binData)
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

void Config::bufferCountsToLHStr(int ndata, QByteArrayList &aldata)
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

void Config::hexSizeToLHStr(int ndata, QByteArrayList &aldata)
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

void Config::on_selectHexFileBtn_clicked()
{
    hexFileHandler();
}

void Config::on_updateButton_clicked()
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

void Config::hexFileHandler()
{
    QFile file;
    QString f = QFileDialog::getOpenFileName(this,QString("选择升级文件"),QString("./"));
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

void Config::on_confirmBtn_clicked()
{
    this->close();
}

void Config::on_cancelBtn_clicked()
{
    this->close();
}
