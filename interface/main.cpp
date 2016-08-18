#include "mainwindow.h"
#include <QApplication>
#include <QWidget>

/*Version 1.0.0 8/18/16*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
