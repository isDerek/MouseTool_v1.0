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
    ui->keyText->setReadOnly(true);
    // 进制光标 Focus 在下列控件，避免干扰到鼠标按键的捕获
    ui->confirmBtn->setFocusPolicy(Qt::NoFocus);
    ui->cancelBtn->setFocusPolicy(Qt::NoFocus);
    ui->keyText->setFocusPolicy(Qt::NoFocus);
    ui->recordHandlerTmr->setFocusPolicy(Qt::NoFocus);
    ui->keyFuc->setFocusPolicy(Qt::NoFocus);
    ui->startRecordBtn->setFocusPolicy(Qt::NoFocus);

    currentPage = ui->keyFuc->currentIndex(); // 当前页初始化
//    recordTotalTmr = new QTime;

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
        recordTotalTmr->start(); // 总计时器开始计时
        ui->startRecordBtn->setText("停止录制");
        RecordStatus = true;
    }
    else
    {
//        int a;
//        a = recordTotalTmr->elapsed();
//        qDebug()<<a;
//        qDebug()<<recordTotalTmr.elapsed(); // 总计时器开始计时
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

void Macros::on_confirmBtn_clicked()
{
    if(currentPage == 2)
    {
//       emit  macros_signal(QByt keyArray);  有问题
    }
}
