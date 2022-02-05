#include "homescreen.h"
#include "ui_homescreen.h"
#include "addscreen.h"
#include "updatestatusscreen.h"
#include "checkvaccinestatusscreen2.h"
#include "viewscreen.h"

Homescreen::Homescreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Homescreen)
{
    ui->setupUi(this);
    this->setFixedSize(1200,750);//Size Fixed Window
}

//Connect All Connections

Homescreen::~Homescreen()
{
    delete ui;
}

void Homescreen::on_addButton_clicked()
{
    this->hide();
    Addscreen addwin;
    addwin.setModal(true);
    addwin.exec();
}


void Homescreen::on_updateButton_clicked()
{

    this->hide();
    Updatestatusscreen updwin;
    updwin.setModal(true);
    updwin.exec();
}


void Homescreen::on_exitBTN_clicked()
{
     QApplication::quit();
}


void Homescreen::on_checkButton_clicked()
{
    this->hide();
    Checkvaccinestatusscreen2 cekwin;
    cekwin.setModal(true);
    cekwin.exec();
}


void Homescreen::on_viewButton_clicked()
{
    this->hide();
    Viewscreen vwwin;
    vwwin.setModal(true);
    vwwin.exec();
}

