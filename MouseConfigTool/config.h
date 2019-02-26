#ifndef CONFIG_H
#define CONFIG_H

#include <QWidget>
#include "usermodepro.h"
class QFile; // 前置声明 QFile

namespace Ui {
class Config;
}

class Config : public QWidget
{
    Q_OBJECT

public:
    explicit Config(QWidget *parent = nullptr);
    ~Config();

    void hexFileHandler();
    void bufferCountsToLHStr(int ndata, QByteArrayList &aldata);
    void IntToBin(int data, QByteArray &binData);
    void BinToInt(QByteArray &data, QString strBin);
    void StringToHex(QString str, QByteArray &sendData);
    char ConvertHexChar(char ch);
    void hexSizeToLHStr(int ndata, QByteArrayList &aldata);

private slots:
    void on_selectHexFileBtn_clicked();

    void on_updateButton_clicked();

    void on_confirmBtn_clicked();

    void on_cancelBtn_clicked();


private:
    Ui::Config *ui;
    UserModePro userModePro; // 用户模式协议类
    QByteArrayList alBufferLine; // hex 文件的每一行数据
    QByteArrayList alLHBufferIndex; // 高低位包数量索引
    QByteArrayList alLHBufferSize; // 高低位数据包大小
};

#endif // CONFIG_H
