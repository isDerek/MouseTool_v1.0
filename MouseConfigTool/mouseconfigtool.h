#ifndef MOUSECONFIGTOOL_H
#define MOUSECONFIGTOOL_H

#include <QMainWindow>
#include "usbreadthread.h"
#include "usermodepro.h"
#include "macros.h"
#include "config.h"
#include <QThread>
#include <QObject>
#include <QTimer>
#include <QFile>
#include <QTime>
#include <QPainter>
#include <QSystemTrayIcon>
class QFile; // 前置声明 QFile

namespace Ui {
class MouseConfigTool;
}

class MouseConfigTool : public QMainWindow
{
    Q_OBJECT

public:
    explicit MouseConfigTool(QWidget *parent = nullptr);
    ~MouseConfigTool();
    void Delay_Msec(int msec);
    void getHIDDevceInfo(); // 将 HID 设备信息添加进 List
    void clearHIDDeviceInfoList(); // 清空 HID 设备信息 List
    void StringToHex(QString str, QByteArray &sendData); // 字符串转 16 进制
    void IntToBin(int data,QByteArray &binData); // 10 进制转 2 进制
    void BinToInt(QByteArray &data,QString strBin); // 2 进制转 10 进制
    void hexSizeToLHStr(int ndata, QByteArrayList &aldata); // hex 文件大小转换为高地位字符串
    void bufferCountsToLHStr(int ndata, QByteArrayList &aldata); // 包数量转换为高地位字符串
    void paintEvent(QPaintEvent *); // 界面重绘
    void mousePressEvent(QMouseEvent *event); // 窗体拖动
    void mouseMoveEvent(QMouseEvent *event); // 窗体拖动
    void mouseReleaseEvent(QMouseEvent *event); // 窗体拖动
    void createActions();
    void createMenu();
    unsigned short HexStrToUShort(QString str, int length); // 16进制字符串转 Ushort
    char ConvertHexChar(char ch); // 字符转 16 进制

private:
    Ui::MouseConfigTool *ui;
    QStringList HIDDeviceList; // HID 设备显示
    QStringList productList; // 产品信息显示
    QStringList manufacturerList; // 厂商信息显示
    QStringList releaseNumList;// 发布号显示
    QStringList interfaceNumList; // 接口编号显示
    QStringList VIDList; // VID 显示
    QStringList PIDList; // PID 显示
    QStringList usagePageList; // 使用页数显示
    QStringList usageList;  // 使用页显示
    QByteArrayList alLHBufferSize; // 高低位数据包大小
    QByteArrayList alBufferLine; // hex 文件的每一行数据
    QByteArrayList alLHBufferIndex; // 高低位包数量索引
    QByteArray proData; // 数据包
    QTimer *rfStatusTmr; // 刷新状态栏，自动刷新端口定时器
    USBReadThread usbReadThread; // 读取 HID 设备消息线程
    UserModePro userModePro; // 用户模式协议类
    Macros *macros = new Macros; // 实例化 Macro 类
    Config *config = new Config; // 设置窗口类实例化
    QSystemTrayIcon *mSysTrayIcon = new QSystemTrayIcon; // 操作系统托盘操作类实例化
    QMenu *mMenu; // 托盘菜单项
    QAction *mShowMainAction; // 托盘菜单项的子项目--显示主界面
    QAction *mExitAppAction; // 托盘菜单项的子项目--退出
    bool HIDDeviceIsOpen; // hid 设备是否开启
    bool m_pressed; // 窗体拖动是否按下
    bool getCurrentMouseStatusFlag = true; // 获取鼠标当前状态（界面初始化只执行一次）
    char ReportID; // HID Device ReportID
    char CMDStatus; // 协议状态
    char CMDID = 0x00; // 协议 ID, 空闲态 ID 为 0
    char DataLSB; // 数据低位索引
    char DataMSB; // 数据高位索引
    char DataLength; // 数据长度
    int checkSum; // 检验位
    int macroKey = 0; // 初始化按键宏空闲状态， 1 代表设置侧键 1， 2 代表设置侧键 2
    QFile *mainQssFile; // 主界面样式文件
    QFile *macroKeyQssFile; // 主界面样式文件
    QFile *settingQssFile; // 用户设置样式文件
    QPoint m_movePos;// 窗体拖动位置
    void mainGuiInit(); // 主界面样式初始化
    void hiddenMainGui(); // 主界面部分样式隐藏

private slots:
    void slot_rfStatusTmr(); // 刷新 HID 设备定时器
    void slot_getHIDDeviceIsOpen(bool); // 获取 HID 线程返回是否开启了设备槽函数
    void slot_getRevData(QByteArray data); // 获取 HID 的数据槽函数
    void slot_getMacrosConfig(QByteArray);// 获取按键宏配置
    void on_DPIMode1Btn_clicked(); // DPI 400 按钮
    void on_DPIMode2Btn_clicked(); // DPI 800 按钮
    void on_DPIMode3Btn_clicked(); // DPI 1600 按钮
    void on_DPIMode4Btn_clicked(); // DPI 4000 按钮
    void on_RGBMode1Btn_clicked(); // RGB 无灯效按钮
    void on_RGBMode2Btn_clicked(); // RGB 循环灯按钮
    void on_RGBMode3Btn_clicked(); // RGB 呼吸灯按钮
    void on_RGBMode4Btn_clicked(); // RGB 跑马灯按钮
    void on_setConfigModeBtn_clicked(); // 设备进入配置模式按钮
    void on_setNormalModeBtn_clicked(); // 设备进入正常模式按钮
    void on_getCurrentDeviceModeBtn_clicked(); // 设备获取当前设备模式按钮
    void on_setMacroKey1Btn_clicked(); // 设备设置侧键一按键宏按钮
    void on_setMacroKey2Btn_clicked();// 设备设置侧键二按键宏按钮
    void on_closeBtn_clicked(); // 关闭窗口按钮
    void on_configBtn_clicked();// 设置图标按钮
    void on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason);// 系统托盘操作类槽函数
    void on_showMainAction();// 显示主界面
    void on_exitAppAction();// 退出主界面
};

#endif // MOUSECONFIGTOOL_H
