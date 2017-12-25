#include "settingwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    settingWindow w;
    w.show();

    return a.exec();
}
