#include "usermodepro.h"
#include <QDebug>
UserModePro::UserModePro()
{

}

void UserModePro::getReportDataStr(QByteArray protocolData, char &ReportID, char &CMDStatus, char &CMDID, char &DataLSB, char &DataMSB, char &DataLength, QByteArray &data, int &checkSum)
{
    ReportID = protocolData[0];
    CMDStatus = protocolData[1];
    CMDID = protocolData[2];
    DataLSB = protocolData[3];
    DataMSB = protocolData[4];
    DataLength = protocolData[5];
    for(int i = 0; i<DataLength;i++)
    {
        data[i] = protocolData[6+i];
    }
    checkSum = protocolData[63];
}

// 设置协议包数据，并返回符合协议的数据包
QByteArray UserModePro::setReportDataStr(char ReportID, char CMDStatus, char CMDID, char DataLSB, char DataMSB, char DataLength, QByteArray data)
{
    QByteArray protocolData = nullptr;
    int dataSum = 0;
    protocolData[0] = ReportID;
    protocolData[1] = ReportID;
    protocolData[2] = CMDStatus;
    protocolData[3] = CMDID;
    protocolData[4] = DataLSB;
    protocolData[5] = DataMSB;
    protocolData[6] = DataLength;
    for(int i = 0; i<DataLength;i++)
    {
        protocolData[7+i] = data[i];
    }
    for( int j = 7+DataLength ;j<64;j++)
    {
        protocolData[j] = 0x00;
    }
    for(int h = 1;h<64;h++)
    {
        dataSum = dataSum + protocolData[h];
    }
    protocolData[64] = 0x55-(dataSum)&0xff;
    return protocolData;
}

// 按键 DPI 400 模式发送
void UserModePro::postDPIMode1Notify()
{
    QByteArray sendData,protocolData;
    sendData[0] = 0x00;// PDI 模式 1
    ReportID = 0x00;
    CMDStatus = 0x00;
    CMDID = 0x05;
    DataLSB = 0x00;
    DataMSB = 0x00;
    DataLength = 1; // strlen （0） 不认为有空间
    protocolData = setReportDataStr(ReportID,CMDStatus,CMDID,DataLSB,DataMSB,DataLength,sendData);
    usbReadThread.getProtocolData(protocolData);
}

// 按键 DPI 800 模式发送
void UserModePro::postDPIMode2Notify()
{
    QByteArray sendData,protocolData;
    sendData[0] = 0x01;// PDI 模式 2
    ReportID = 0x00;
    CMDStatus = 0x00;
    CMDID = 0x05;
    DataLSB = 0x00;
    DataMSB = 0x00;
    DataLength = strlen(sendData);
    protocolData = setReportDataStr(ReportID,CMDStatus,CMDID,DataLSB,DataMSB,DataLength,sendData);
    usbReadThread.getProtocolData(protocolData);
}

// 按键 DPI 1600 模式发送
void UserModePro::postDPIMode3Notify()
{
    QByteArray sendData,protocolData;
    sendData[0] = 0x02;// PDI 模式 3
    ReportID = 0x00;
    CMDStatus = 0x00;
    CMDID = 0x05;
    DataLSB = 0x00;
    DataMSB = 0x00;
    DataLength = strlen(sendData);
    protocolData = setReportDataStr(ReportID,CMDStatus,CMDID,DataLSB,DataMSB,DataLength,sendData);
    usbReadThread.getProtocolData(protocolData);
}

// 按键 DPI 4000 模式发送
void UserModePro::postDPIMode4Notify()
{
    QByteArray sendData,protocolData;
    sendData[0] = 0x03;// PDI 模式 4
    ReportID = 0x00;
    CMDStatus = 0x00;
    CMDID = 0x05;
    DataLSB = 0x00;
    DataMSB = 0x00;
    DataLength = strlen(sendData);
    protocolData = setReportDataStr(ReportID,CMDStatus,CMDID,DataLSB,DataMSB,DataLength,sendData);
    usbReadThread.getProtocolData(protocolData);
}
// 设备无灯效模式
void UserModePro::postRGBMode1Notify()
{
    QByteArray sendData,protocolData;
    sendData[0] = 0x00;// RGB 无灯效模式
    ReportID = 0x00;
    CMDStatus = 0x00;
    CMDID = 0x0B;
    DataLSB = 0x00;
    DataMSB = 0x00;
    DataLength = 1;
    protocolData = setReportDataStr(ReportID,CMDStatus,CMDID,DataLSB,DataMSB,DataLength,sendData);
    usbReadThread.getProtocolData(protocolData);
}
// 设备循环灯模式
void UserModePro::postRGBMode2Notify()
{
    QByteArray sendData,protocolData;
    sendData[0] = 0x01;// RGB 循环灯模式
    ReportID = 0x00;
    CMDStatus = 0x00;
    CMDID = 0x0B;
    DataLSB = 0x00;
    DataMSB = 0x00;
    DataLength = strlen(sendData);
    protocolData = setReportDataStr(ReportID,CMDStatus,CMDID,DataLSB,DataMSB,DataLength,sendData);
    usbReadThread.getProtocolData(protocolData);
}
// 设备呼吸灯模式
void UserModePro::postRGBMode3Notify()
{
    QByteArray sendData,protocolData;
    sendData[0] = 0x02;// RGB 呼吸灯模式
    ReportID = 0x00;
    CMDStatus = 0x00;
    CMDID = 0x0B;
    DataLSB = 0x00;
    DataMSB = 0x00;
    DataLength = strlen(sendData);
    protocolData = setReportDataStr(ReportID,CMDStatus,CMDID,DataLSB,DataMSB,DataLength,sendData);
    usbReadThread.getProtocolData(protocolData);
}
// 设备跑马灯模式
void UserModePro::postRGBMode4Notify()
{
    QByteArray sendData,protocolData;
    sendData[0] = 0x03;// RGB 跑马灯模式
    ReportID = 0x00;
    CMDStatus = 0x00;
    CMDID = 0x0B;
    DataLSB = 0x00;
    DataMSB = 0x00;
    DataLength = strlen(sendData);
    protocolData = setReportDataStr(ReportID,CMDStatus,CMDID,DataLSB,DataMSB,DataLength,sendData);
    usbReadThread.getProtocolData(protocolData);
}
// 按键宏模式
void UserModePro::postMacroKeyNotify(int macroKey01, int macroKey02, int macroKey11, int macroKey12)
{
    QByteArray sendData,protocolData;
    sendData[0] = char(macroKey01);// 侧键 1 第一顺位
    sendData[1] = char(macroKey02);// 侧键 1 第二顺位
    sendData[2] = char(macroKey11);// 侧键 2 第一顺位
    sendData[3] = char(macroKey12);// 侧键 2 第二顺位
    ReportID = 0x00;
    CMDStatus = 0x00;
    CMDID = 0x09;
    DataLSB = 0x00;
    DataMSB = 0x00;
    DataLength = 4;
    protocolData = setReportDataStr(ReportID,CMDStatus,CMDID,DataLSB,DataMSB,DataLength,sendData);
    usbReadThread.getProtocolData(protocolData);
}
// 设备进入配置模式
void UserModePro::postConfigModeNotify()
{
    QByteArray sendData,protocolData;
    sendData[0] = 0x01;// 激活配置模式
    ReportID = 0x00;
    CMDStatus = 0x00;
    CMDID = 0x03;
    DataLSB = 0x00;
    DataMSB = 0x00;
    DataLength = strlen(sendData);
    protocolData = setReportDataStr(ReportID,CMDStatus,CMDID,DataLSB,DataMSB,DataLength,sendData);
    usbReadThread.getProtocolData(protocolData);
}
// 设备进入正常模式
void UserModePro::postNormalModeNotify()
{
    QByteArray sendData,protocolData;
    sendData[0] = 0x00;// 正常模式
    ReportID = 0x00;
    CMDStatus = 0x00;
    CMDID = 0x03;
    DataLSB = 0x00;
    DataMSB = 0x00;
    DataLength = 1;
    protocolData = setReportDataStr(ReportID,CMDStatus,CMDID,DataLSB,DataMSB,DataLength,sendData);
    usbReadThread.getProtocolData(protocolData);
}
// 获取当前设备模式
void UserModePro::getCurrentDeviceMode()
{
    QByteArray sendData,protocolData;
    sendData[0] = 0x00;
    ReportID = 0x00;
    CMDStatus = 0x00;
    CMDID = 0x04;
    DataLSB = 0x00;
    DataMSB = 0x00;
    DataLength = 0;
    protocolData = setReportDataStr(ReportID,CMDStatus,CMDID,DataLSB,DataMSB,DataLength,sendData);
    usbReadThread.getProtocolData(protocolData);
}
// 获取当前 DPI
void UserModePro::getCurrentDPIMode()
{
    QByteArray sendData,protocolData;
    sendData[0] = 0x00;
    ReportID = 0x00;
    CMDStatus = 0x00;
    CMDID = 0x06;
    DataLSB = 0x00;
    DataMSB = 0x00;
    DataLength = 0;
    protocolData = setReportDataStr(ReportID,CMDStatus,CMDID,DataLSB,DataMSB,DataLength,sendData);
    usbReadThread.getProtocolData(protocolData);
}
// 获取当前灯效
void UserModePro::getCurrentRGBMode()
{
    QByteArray sendData,protocolData;
    sendData[0] = 0x00;
    ReportID = 0x00;
    CMDStatus = 0x00;
    CMDID = 0x0C;
    DataLSB = 0x00;
    DataMSB = 0x00;
    DataLength = 0;
    protocolData = setReportDataStr(ReportID,CMDStatus,CMDID,DataLSB,DataMSB,DataLength,sendData);
    usbReadThread.getProtocolData(protocolData);
}
// 获取当前电量
void UserModePro::getCurrentPower()
{
    QByteArray sendData,protocolData;
    sendData[0] = 0x00;
    ReportID = 0x00;
    CMDStatus = 0x00;
    CMDID = 0x0D;
    DataLSB = 0x00;
    DataMSB = 0x00;
    DataLength = 0;
    protocolData = setReportDataStr(ReportID,CMDStatus,CMDID,DataLSB,DataMSB,DataLength,sendData);
    usbReadThread.getProtocolData(protocolData);
}

void UserModePro::getCurrentMacroKeyConfig()
{
    QByteArray sendData,protocolData;
    sendData[0] = 0x00;
    ReportID = 0x00;
    CMDStatus = 0x00;
    CMDID = 0x0A;
    DataLSB = 0x00;
    DataMSB = 0x00;
    DataLength = 0;
    protocolData = setReportDataStr(ReportID,CMDStatus,CMDID,DataLSB,DataMSB,DataLength,sendData);
    usbReadThread.getProtocolData(protocolData);
}

void UserModePro::postEnterBootLoaderMode()
{
    QByteArray sendData,protocolData;
    sendData[0] = 0x00;
    ReportID = 0x00;
    CMDStatus = 0x00;
    CMDID = 0x11;
    DataLSB = 0x00;
    DataMSB = 0x00;
    DataLength = 0;
    protocolData = setReportDataStr(ReportID,CMDStatus,CMDID,DataLSB,DataMSB,DataLength,sendData);
    usbReadThread.getProtocolData(protocolData);
}

void UserModePro::postUpdateDeviceInfo(QByteArrayList recData)
{
    QByteArray sendData,protocolData;
    sendData[0] = char(recData[0].toInt());
    sendData[1] = char(recData[1].toInt());
    sendData[2] = char(recData[2].toInt());
    sendData[3] = char(recData[3].toInt());
    ReportID = 0x01;
    CMDStatus = 0x00;
    CMDID = 0x50;
    DataLSB = 0x00;
    DataMSB = 0x00;
    DataLength = 4;
    protocolData = setReportDataStr(ReportID,CMDStatus,CMDID,DataLSB,DataMSB,DataLength,sendData);
    usbReadThread.getProtocolData(protocolData);
}

void UserModePro::postUpdateFW(QByteArrayList alLHIndex, QByteArray data)
{
    QByteArray sendData,protocolData;
    sendData = data;
    ReportID = 0x01;
    CMDStatus = 0x00;
    CMDID = 0x51;
    DataLSB = char(alLHIndex[0].toInt());
    DataMSB = char(alLHIndex[1].toInt());
    DataLength = char(sendData.size());
    protocolData = setReportDataStr(ReportID,CMDStatus,CMDID,DataLSB,DataMSB,DataLength,sendData);
    usbReadThread.getProtocolData(protocolData);
}

void UserModePro::postExitBootLoaderMode()
{
    QByteArray sendData,protocolData;
    sendData[0] = 0x00;
    ReportID = 0x01;
    CMDStatus = 0x00;
    CMDID = 0x52;
    DataLSB = 0x00;
    DataMSB = 0x00;
    DataLength = 0x00;
    protocolData = setReportDataStr(ReportID,CMDStatus,CMDID,DataLSB,DataMSB,DataLength,sendData);
    usbReadThread.getProtocolData(protocolData);
}
