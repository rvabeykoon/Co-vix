#include "mainscreen.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Add Splash Screen
    QSplashScreen *splash=new QSplashScreen;
    splash->setPixmap(QPixmap(":/Co-vix Images/Splashscreen.png"));
    splash->show();

    MainScreen w;
    QTimer::singleShot(3500,splash,SLOT(close()));
    QTimer::singleShot(3500,&w,SLOT(show()));
    return a.exec();
}
