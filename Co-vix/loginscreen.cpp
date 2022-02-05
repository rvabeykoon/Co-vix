#include "loginscreen.h"
#include "ui_loginscreen.h"
#include "homescreen.h"
#include "mainscreen.h"

LoginScreen::LoginScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginScreen)
{
    ui->setupUi(this);
    this->setFixedSize(1200,750);//Size Fixed Window

    // Check Database Connection

    if(!conn.connOpen())
    {
        QMessageBox::information(this,"Database Connection","Database Connection Is Not Successful. Please Try Again.");
    }

    //Add Regular Expression

    QRegularExpression rx("^\\d+$");
    QValidator *validator = new QRegularExpressionValidator(rx, this);

    ui->idlineEdit->setValidator(validator);
}

LoginScreen::~LoginScreen()
{
    delete ui;
}

void LoginScreen::on_signinButton_clicked()
{
    //Create Data Searching Process Using SQL For Loging

    QString id,pass;
    id= ui->idlineEdit->text();
    pass = ui->passlineEdit->text();

    if(!conn.connOpen()){
        qDebug()<<"failed to open the db";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("select ID , PASSWORD from STAFF where ID='"+id+"' and PASSWORD='"+pass+"' ");

    if(qry.exec()){

        int count;
        while(qry.next())
        {
            count++;
        }
        if(count == 1)
        {
            //Open New Window

            this->hide();
            Homescreen homenwin;
            homenwin.setModal(true);
            homenwin.exec();
            conn.connClose();
        }
        if(count>1)
        {

            QMessageBox::information(this,"login","User Id And Password Not Correct");
        }
        if(count<1)
        {

            QMessageBox::information(this,"login","user id and password Not correct");
        }

    }

    ui->idlineEdit->clear();
    ui->passlineEdit->clear();


}


void LoginScreen::on_backButton_clicked()
{
    this->hide();
    MainScreen homenwin;
    homenwin.setModal(true);
    homenwin.exec();
}

