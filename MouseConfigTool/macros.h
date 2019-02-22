#ifndef MACROS_H
#define MACROS_H

#include <QWidget>
#include <QTime>
#include <QTimer>


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


    void on_keyFuc_currentChanged(int index); // 切换页面处理事件

    void on_startRecordBtn_clicked(); // 确认按钮处理事件

    void on_confirmBtn_clicked(); // 取消按钮处理事件

    void on_closeWindowsBtn_clicked();

    void on_showWindowsBtn_clicked();

    void on_nextWebBtn_clicked();

    void on_beforeWebBtn_clicked();

    void on_resetScaleBtn_clicked();

    void on_cutBtn_clicked();

    void on_copyBtn_clicked();

    void on_pasteBtn_clicked();

    void on_resetBtn_clicked();

    void on_cancelBtn_clicked();

private:
    Ui::Macros *ui;
    bool RecordStatus = false; // 开启录制状态
    int currentPage;
    QByteArray keyArray;
    int keyArrayIndex = 0;

protected:
    void keyReleaseEvent(QKeyEvent *event);

signals:
    void macros_signal(QByteArray data);
};

#endif // MACROS_H
