#include "mainwindow.h"
#include <QApplication>
extern "C" {
#include "finalcompiler.tab.h"
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    cifa();

    return a.exec();
}
