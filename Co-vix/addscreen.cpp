#include "addscreen.h"
#include "ui_addscreen.h"
#include "homescreen.h"

Addscreen::Addscreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Addscreen)
{
    ui->setupUi(this);

    this->setFixedSize(1200,750); //Size Fixed Window

    //Set Current Date

    QDate date = QDate::currentDate();
    ui->dateEdit->setDate(date);
    ui->dateEdit_2->setDate(date);
    ui->dateEdit_3->setDate(date);

    //Add Regular Expression

    QRegularExpression rx("^(?:19|20)?\\d{2}[0-9]{10}|[0-9]{9}[X|V]$");
    QValidator *validator = new QRegularExpressionValidator(rx, this);

    ui->niclineEdit->setValidator(validator);


    // Check Database Connection

    if(!conn.connOpen())
    {
        QMessageBox::information(this,"Database Connection","Database Connection Is Not Successful. Please Try Again.");
    }
}

Addscreen::~Addscreen()
{
    delete ui;
}

void Addscreen::on_backButton_clicked()
{
    this->hide();
    Homescreen homewin;
    homewin.setModal(true);
    homewin.exec();
}


void Addscreen::on_saveButton_clicked()
{
    QString name,nic,age,fddate,fdtype,sddate,sdtype,tddate,tdtype;

    name= ui->namelineEdit->text();
    nic= ui->niclineEdit->text();
    age= ui->agelineEdit->text();

    fddate= ui->dateEdit->text();
    fdtype= ui->type1lineEdit->text();

    sddate= ui->dateEdit_2->text();
    sdtype= ui->type2lineEdit->text();

    tddate= ui->dateEdit_3->text();
    tdtype= ui->type3lineEdit->text();

    //To prevent unnecessary date saving by timepicker

    if(ui->type1lineEdit->text().isEmpty())
    {
        fddate = " - ";
        fdtype = " - ";
    }else
    {
        fddate= ui->dateEdit->text();
    }

    if(ui->type2lineEdit->text().isEmpty())
    {
        sddate = " - ";
        sdtype = " - ";
    }else
    {
        sddate= ui->dateEdit_2->text();
    }

    if(ui->type3lineEdit->text().isEmpty())
    {
        tddate = " - ";
        tdtype = " - ";
    }else
    {
        tddate= ui->dateEdit_3->text();
    }

    //Debugging the database connection

    if(!conn.connOpen()){
        qDebug()<<"failed to open the db";
        return;
    }

    conn.connOpen(); //Open the database connection
    QSqlQuery qry;
    qry.prepare("insert into VACCINATED (NAME,NIC,AGE,FIRSTDOSEDATE,FIRSTDOSETYPE,SECONDDOSEDATE,SECONDDOSETYPE,THIRDDOSEDATE,THIRDDOSETYPE) values ('"+name+"','"+nic+"','"+age+"','"+fddate+"','"+fdtype+"','"+sddate+"','"+sdtype+"','"+tddate+"','"+tdtype+"') ");

    if(qry.exec())
    {
         QMessageBox::information(this,"ADD NEW RECORD"," ADD NEW RECORD SUCCESSFUL !!");
         conn.connClose(); //Close the database connection

         //Reset all UI design

         ui->namelineEdit->clear();
         ui->niclineEdit->clear();
         ui->agelineEdit->clear();

         ui->type1lineEdit->clear();
         ui->type2lineEdit->clear();
         ui->type3lineEdit->clear();

         //Set Current Date

         QDate date = QDate::currentDate();
         ui->dateEdit->setDate(date);
         ui->dateEdit_2->setDate(date);
         ui->dateEdit_3->setDate(date);


    }else
    {
        QMessageBox::information(this,"ADD NEW RECORD", qry.lastError().text());
    }

}

