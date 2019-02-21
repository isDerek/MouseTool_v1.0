#include "usbreadthread.h"
#include "mouseconfigtool.h"
#include <QThread>
#include <QDebug>
#include "hidapi.h"

static int res;
static hid_device *handle;

USBReadThread::USBReadThread(QObject *parent):QThread (parent)
{
    startHIDDeviceFlag = false;
}

void USBReadThread::run()
{
    unsigned char buf[64];
    QByteArray revData = 0;
    while(startHIDDeviceFlag)
    {
        //如果设备存在
        if(handle)
        {
            res = hid_read(handle,buf,64); // res 返回具体数值大小
            for(int i=0; i<res; i++)
            {
                revData[i] = buf[i];
            }
            if(res == 0)
            {

            }
            else
            {
               emit postRevData(revData);
            }
            msleep(100);
        }
    }
}

void USBReadThread::getOpenHIDDevice(unsigned short PID, unsigned short VID, bool isOpen)
{
    currentPID = PID;
    currentVID = VID;
    startHIDDeviceFlag = isOpen;
    qDebug()<<currentPID;
    qDebug()<<currentVID;
    if(isOpen)
    {
        handle = hid_open(currentVID,currentPID,nullptr);
        if(!handle)
        {
            emit postHIDDeviceOpen(false);
            return;
        }
        else{
            hid_set_nonblocking(handle,1);// 非阻塞，避免读 HID 设备时，关闭设备的时候，还在读函数阻塞，造成指针释放宕机
            emit postHIDDeviceOpen(true);
        }
    }
    else
    {
        if(handle)
        {
           hid_close(handle);
           emit postHIDDeviceOpen(false);
        }
    }
}

void USBReadThread::getProtocolData(QByteArray data)
{
    unsigned char *sendBuf;
    sendBuf = (unsigned char*)malloc(65);
    for(int i=0;i<65;i++)
    {
        sendBuf[i] = data[i];
//         qDebug()<<sendBuf[i];
    }
    hid_write(handle,sendBuf,65);// 65 是因为 QN9080 智迪协议上是 1 个 Report ID + 64 Bytes 数据
}
