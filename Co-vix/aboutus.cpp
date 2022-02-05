#include "aboutus.h"
#include "ui_aboutus.h"
#include "mainscreen.h"

Aboutus::Aboutus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Aboutus)
{
    ui->setupUi(this);
    this->setFixedSize(1200,750); //Size Fixed Window

}

Aboutus::~Aboutus()
{
    delete ui;
}

void Aboutus::on_backButton_clicked()
{
    this->hide();
    MainScreen homewin;
    homewin.setModal(true);
    homewin.exec();
}

