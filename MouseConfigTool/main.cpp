#include "mouseconfigtool.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MouseConfigTool w;
    w.show();

    return a.exec();
}
