#include "macrokey.h"
#include "ui_macrokey.h"
#include "keymap.h"
#include <QKeyEvent>
#include <QDebug>

MacroKey::MacroKey(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MacroKey)
{
    ui->setupUi(this);
    keyCodeMapInit();
    QKeyToStrMapInit();
    macroKeyGuiInit();
    ui->setMacroKey01Btn->installEventFilter(this); // 侧键 1 第一顺位事件监听
    ui->setMacroKey02Btn->installEventFilter(this); // 侧键 1 第二顺位事件监听
    ui->setMacroKey11Btn->installEventFilter(this); // 侧键 2 第一顺位事件监听
    ui->setMacroKey12Btn->installEventFilter(this); // 侧键 2 第二顺位事件监听
    ui->okLabel->installEventFilter(this); // ok 按钮事件监听
    ui->cancelLabel->installEventFilter(this); // cancel 按钮事件监听
}

MacroKey::~MacroKey()
{
    delete ui;
}

void MacroKey::macroKeyGuiInit()
{
    qssFile = new QFile(":/qss/qss/macrokey.qss",this);
    // 只读方式打开该文件
    qssFile->open(QFile::ReadOnly);
    // 读取文件全部内容
    QString styleSheet = QString(qssFile->readAll());
    // 为 QApplication 设置样式表
    qApp->setStyleSheet(styleSheet);
    qssFile->close();
    ui->setMacroKey01Btn->setCursor(QCursor(Qt::PointingHandCursor)); // 设置光标移动到侧键 1 第一顺位鼠标样式
    ui->setMacroKey02Btn->setCursor(QCursor(Qt::PointingHandCursor)); // 设置光标移动到侧键 1 第二顺位鼠标样式
    ui->setMacroKey11Btn->setCursor(QCursor(Qt::PointingHandCursor)); // 设置光标移动到侧键 2 第一顺位鼠标样式
    ui->setMacroKey12Btn->setCursor(QCursor(Qt::PointingHandCursor)); // 设置光标移动到侧键 2 第二顺位鼠标样式
}

bool MacroKey::eventFilter(QObject *obj, QEvent *event)
{
    if(qobject_cast<QLabel*>(obj) == ui->setMacroKey01Btn &&event->type() == QEvent::MouseButtonPress)
    {
        ui->setMacroKey01Btn->clear();
        macroKey= 0; // 当前选中侧键 1 第一顺位
        macroKey01 = 0; // reset 当前按键
        return true;
    }
    else if(qobject_cast<QLabel*>(obj) == ui->setMacroKey02Btn &&event->type() == QEvent::MouseButtonPress)
    {
        ui->setMacroKey02Btn->clear();
        macroKey= 1; // 当前选中侧键 1 第二顺位
        macroKey02 = 0; // reset 当前按键
        return true;
    }
    if(qobject_cast<QLabel*>(obj) == ui->setMacroKey11Btn &&event->type() == QEvent::MouseButtonPress)
    {
        ui->setMacroKey11Btn->clear();
        macroKey= 2; // 当前选中侧键 2 第一顺位
        macroKey11 = 0; // reset 当前按键
        return true;
    }
    else if(qobject_cast<QLabel*>(obj) == ui->setMacroKey12Btn &&event->type() == QEvent::MouseButtonPress)
    {
        ui->setMacroKey12Btn->clear();
        macroKey= 3; // 当前选中侧键 2 第二顺位
        macroKey12 = 0; // reset 当前按键
        return true;
    }
    else if(qobject_cast<QLabel*>(obj) == ui->okLabel &&event->type() == QEvent::MouseButtonPress)
    {
        this->hide();
        emit macroKey_signal(macroKey01,macroKey02,macroKey11,macroKey12);
        return true;
    }
    else if(qobject_cast<QLabel*>(obj) == ui->cancelLabel &&event->type() == QEvent::MouseButtonPress)
    {
        this->hide();
        return true;
    }
    else {
        return false;
    }
}

void MacroKey::keyPressEvent(QKeyEvent *event)
{

}

void MacroKey::keyReleaseEvent(QKeyEvent *event)
{
    QString Key = nullptr;
//    qDebug()<<event->key();
    qDebug()<<event->modifiers();
    switch(macroKey)
    {
        case 0:
            if(QKeyToStr.contains(event->key()))
            {
                ui->setMacroKey01Btn->setText(QKeyToStr[event->key()]);
            }
            if(keycode.contains(event->key()))
            {
                qDebug()<<keycode[event->key()];
                macroKey01 = keycode[event->key()];
//                if(QString(event->key()))
            }
            break;
        case 1:
            if(QKeyToStr.contains(event->key()))
            {
                ui->setMacroKey02Btn->setText(QKeyToStr[event->key()]);
            }
            if(keycode.contains(event->key()))
            {
                qDebug()<<keycode[event->key()];
                macroKey02 = keycode[event->key()];
//                if(QString(event->key()))
            }
            break;
        case 2:
            if(QKeyToStr.contains(event->key()))
            {
                ui->setMacroKey11Btn->setText(QKeyToStr[event->key()]);

            }
            if(keycode.contains(event->key()))
            {
                qDebug()<<keycode[event->key()];
                macroKey11 = keycode[event->key()];
    //                if(QString(event->key()))
            }
            break;
        case 3:
            if(QKeyToStr.contains(event->key()))
            {
                ui->setMacroKey12Btn->setText(QKeyToStr[event->key()]);
            }
            if(keycode.contains(event->key()))
            {
                qDebug()<<keycode[event->key()];
                macroKey12 = keycode[event->key()];
    //                if(QString(event->key()))
            }
            break;

        default: break;
    }
}

