#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QMessageBox>

namespace Ui {
class MainScreen;
}

class MainScreen : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase mydb;

    void connClose()
    {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen()
    {
        mydb =  QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("C:/Users/abeyk/Desktop/Co-vix/Co-vix/Co-vix Database/co-vix.sqlite"); //add database path

        if(mydb.open()){
            qDebug()<<("connected");
            return true;
        }else{
            qDebug()<<("not connected");
            return false;
        }

    }

public:
    explicit MainScreen(QWidget *parent = nullptr);
    ~MainScreen();

private slots:


    void on_seach02BTN_clicked();

    void on_signinBTN_clicked();

    void on_searchBTN_clicked();

    void on_aboutusBTN_clicked();

private:
    Ui::MainScreen *ui;
};

#endif // MAINSCREEN_H
