#include "mainwindow.h"
#include <QSplashScreen>
#include <QPixmap>
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap bootUI(":/pic/picture/boot.png");
    QSplashScreen bootScreen(bootUI);
    bootScreen.show();

/*    QFile file(":/qss/qss/global.qss"); // load qss table
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    qApp->setStyleSheet(styleSheet);

    file.close(); */

    MainWindow w;
    w.show();

    bootScreen.finish(&w);

    return a.exec();
}
