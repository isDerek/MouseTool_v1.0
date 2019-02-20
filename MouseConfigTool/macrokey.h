#ifndef MACROKEY_H
#define MACROKEY_H

#include <QDialog>
#include <QMap>

class QFile;
namespace Ui {
class MacroKey;
}

class MacroKey : public QDialog
{
    Q_OBJECT

public:
    explicit MacroKey(QWidget *parent = nullptr);
    ~MacroKey();

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    bool eventFilter(QObject *obj, QEvent *event);

private:
    Ui::MacroKey *ui;
    int macroKey;
    QFile *qssFile;
    int macroKey01 = 0;
    int macroKey02 = 0;
    int macroKey11 = 0;
    int macroKey12 = 0;
    void macroKeyGuiInit();

signals:
    void macroKey_signal(int macroKey01, int macroKey02, int macroKey11, int macroKey12);
};

#endif // MACROKEY_H
