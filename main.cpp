#include "mainwindow.h"
#include <QSplashScreen>
#include <QPixmap>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap bootUI(":/pic/picture/boot.png");
    QSplashScreen bootScreen(bootUI);
    bootScreen.show();

    MainWindow w;
    w.show();

    bootScreen.finish(&w);

    return a.exec();
}
