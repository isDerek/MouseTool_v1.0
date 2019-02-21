#ifndef MACROS_H
#define MACROS_H

#include <QWidget>
#include <QTime>



namespace Ui {
class Macros;
}

class Macros : public QWidget
{
    Q_OBJECT

public:
    explicit Macros(QWidget *parent = nullptr);
    ~Macros();

private slots:


    void on_keyFuc_currentChanged(int index);

    void on_startRecordBtn_clicked();

    void on_confirmBtn_clicked();

private:
    Ui::Macros *ui;
    QTime *recordTotalTmr = new QTime;
    QTime recordSingleTmr;
    bool RecordStatus = false; // 开启录制状态
    int currentPage;
    QByteArray keyArray;
    int keyArrayIndex = 0;

protected:
    void keyReleaseEvent(QKeyEvent *event);

signals:
    void macros_signal(QByteArray *data);
};

#endif // MACROS_H
