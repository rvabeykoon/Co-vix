#include "mainscreen.h"
#include "ui_mainscreen.h"
#include "loginscreen.h"
#include "checkvaccinestatusscreen.h"
#include "aboutus.h"

MainScreen::MainScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainScreen)
{
    ui->setupUi(this);
    this->setFixedSize(1200,750);//Size Fixed Window

    // Check Database Connection

    if(!connOpen())
    {
        QMessageBox::information(this,"Database Connection","Database Connection Is Not Successful. Please Try Again.");
    }

}

MainScreen::~MainScreen()
{
    delete ui;
}

//connect login screen


void MainScreen::on_seach02BTN_clicked()
{
    this->hide();
    Checkvaccinestatusscreen checkvacwin;
    checkvacwin.setModal(true);
    checkvacwin.exec();
}


void MainScreen::on_signinBTN_clicked()
{
    this->hide();
    LoginScreen loginwin;
    loginwin.setModal(true);
    loginwin.exec();
}


void MainScreen::on_searchBTN_clicked()
{
    this->hide();
    Checkvaccinestatusscreen checkvacwin;
    checkvacwin.setModal(true);
    checkvacwin.exec();
}


void MainScreen::on_aboutusBTN_clicked()
{
     this->hide();
     Aboutus checkvacwin;
     checkvacwin.setModal(true);
     checkvacwin.exec();

}

