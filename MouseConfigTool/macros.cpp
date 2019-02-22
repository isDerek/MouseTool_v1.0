#include "macros.h"
#include "ui_macros.h"
#include <QDebug>
#include <QKeyEvent>
#include <QMap>
#include "key_map.h"

Macros::Macros(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Macros)
{
    ui->setupUi(this);
    keyCodeMapInit();
    QKeyToStrMapInit();
    this->setFixedSize(450,400); // 固定窗口大小
    this->setWindowTitle("命令编辑器");
    QIcon icon(":/hidmouse/images/mouseKey.png");
    this->setWindowIcon(icon);
    ui->keyText->setReadOnly(true);
    ui->showKeyText->setReadOnly(true);
    // 进制光标 Focus 在下列控件，避免干扰到鼠标按键的捕获
    ui->confirmBtn->setFocusPolicy(Qt::NoFocus);
    ui->cancelBtn->setFocusPolicy(Qt::NoFocus);
    ui->keyText->setFocusPolicy(Qt::NoFocus);
    ui->recordHandlerTmr->setFocusPolicy(Qt::NoFocus);
    ui->keyFuc->setFocusPolicy(Qt::NoFocus);
    ui->startRecordBtn->setFocusPolicy(Qt::NoFocus);

    currentPage = ui->keyFuc->currentIndex(); // 当前页初始化
}

Macros::~Macros()
{
    delete ui;
}

void Macros::on_keyFuc_currentChanged(int index)
{
    currentPage = index;
}

void Macros::on_startRecordBtn_clicked()
{


    //点击开始录制
    if(!RecordStatus)
    {
        ui->startRecordBtn->setText("停止录制");
        RecordStatus = true;
    }
    else
    {
        ui->startRecordBtn->setText("开始录制");
        RecordStatus = false;
    }
}

void Macros::keyReleaseEvent(QKeyEvent *event)
{
//    qDebug()<<event->key();
//    qDebug()<<event->modifiers();
   if(QKeyToStr.contains(event->key()))
   {
//    qDebug()<<keycode[event->key()];
    keyArray[keyArrayIndex] = char(keycode[event->key()]);
    keyArrayIndex++;
    ui->keyText->append(QKeyToStr[event->key()]);
   }
}

void Macros::on_closeWindowsBtn_clicked()
{
    keyArray.clear();
    ui->showKeyText->setText("Alt + F4");
    keyArray[0] = char(0xE2); // Alt
    keyArray[1] = char(0x3D); // F4
}

void Macros::on_showWindowsBtn_clicked()
{
    keyArray.clear();
    ui->showKeyText->setText("Windows 键 + D");
    keyArray[0] = char(0xE3); // Windows 键
    keyArray[1] = char(0x07); // D
}

void Macros::on_nextWebBtn_clicked()
{
    keyArray.clear();
    ui->showKeyText->setText("Ctrl + Tab");
    keyArray[0] = char(0xE0); // Ctrl
    keyArray[1] = char(0X2B); // Tab
}

void Macros::on_beforeWebBtn_clicked()
{
    keyArray.clear();
    ui->showKeyText->setText("Ctrl + Shift + Tab");
    keyArray[0] = char(0xE0); // Ctrl
    keyArray[1] = char(0xE1); // Shift
    keyArray[2] = char(0X2B); // Tab
}

void Macros::on_resetScaleBtn_clicked()
{
    keyArray.clear();
    ui->showKeyText->setText("Ctrl + 0");
    keyArray[0] = char(0xE0); // Ctrl
    keyArray[1] = char(0x1e); // 0
}

void Macros::on_cutBtn_clicked()
{
    keyArray.clear();
    ui->showKeyText->setText("Ctrl + X");
    keyArray[0] = char(0xE0); // Ctrl
    keyArray[1] = char(0x1B); // X
}

void Macros::on_copyBtn_clicked()
{
    keyArray.clear();
    ui->showKeyText->setText("Ctrl + C");
    keyArray[0] = char(0xE0); // Ctrl
    keyArray[1] = char(0x06); // C
}

void Macros::on_pasteBtn_clicked()
{
    keyArray.clear();
    ui->showKeyText->setText("Ctrl + V");
    keyArray[0] = char(0xE0); // Ctrl
    keyArray[1] = char(0x19); // V
}

void Macros::on_resetBtn_clicked()
{
    keyArray.clear();
    ui->showKeyText->setText("Ctrl + Y");
    keyArray[0] = char(0xE0); // Ctrl
    keyArray[1] = char(0x1C); // Y
}

void Macros::on_cancelBtn_clicked()
{
    keyArray.clear();
    ui->keyText->clear();
    ui->showKeyText->clear();
    this->hide();
}

void Macros::on_confirmBtn_clicked()
{
    if(currentPage == 0)
    {
       emit  macros_signal(keyArray);
    }
    if(currentPage == 1)
    {
       emit  macros_signal(keyArray);
    }
    if(currentPage == 2)
    {
       emit  macros_signal(keyArray);
    }
    this->hide();
}
