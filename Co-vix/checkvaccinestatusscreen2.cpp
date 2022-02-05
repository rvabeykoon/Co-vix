#include "checkvaccinestatusscreen2.h"
#include "ui_checkvaccinestatusscreen2.h"
#include "homescreen.h"

Checkvaccinestatusscreen2::Checkvaccinestatusscreen2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Checkvaccinestatusscreen2)
{
    ui->setupUi(this);
    this->setFixedSize(1200,750); //Size Fixed Window

    //Add Regular Expression

    QRegularExpression rx("^(?:19|20)?\\d{2}[0-9]{10}|[0-9]{9}[X|V]$");
    QValidator *validator = new QRegularExpressionValidator(rx, this);

    ui->lineEdit->setValidator(validator);

    // Check Database Connection

    if(!conn.connOpen())
    {
        QMessageBox::information(this,"Database Connection","Database Connection Is Not Successful. Please Try Again.");
    }
}

Checkvaccinestatusscreen2::~Checkvaccinestatusscreen2()
{
    delete ui;
}

void Checkvaccinestatusscreen2::on_checkButton_clicked()
{
    conn.connOpen(); //Open the database connection

    //Create Data Searching Process Using SQL

    QString nic;
    nic= ui->lineEdit->text();

    if(ui->lineEdit->text().isEmpty())
    {
        QMessageBox::information(this,"Invalid Data","You Have Entered An Invalid Data. Please Try Again.");

    }else
    {
        QSqlQuery query("SELECT NAME, FIRSTDOSEDATE , FIRSTDOSETYPE , SECONDDOSEDATE , SECONDDOSETYPE , THIRDDOSEDATE , THIRDDOSETYPE  FROM VACCINATED where NIC='"+nic+"' ");

        if(query.next())
        {

            ui->checkButton->setVisible(false);
            ui->nameLbl->setText("01. Name : "+query.value(0).toString());
            ui->firstdosLbl->setText("02. Date Of First Dose of Covid Vaccine And Vaccine Type : "+ query.value(1).toString()+" & "+query.value(2).toString() );
            ui->sendoseLbl->setText("03. Date Of Second Dose of Covid Vaccine And Vaccine Type : "+ query.value(3).toString()+" & "+query.value(4).toString());
            ui->thirddoseLbl->setText("04. Date Of Third Dose of Covid Vaccine And Vaccine Type : "+ query.value(5).toString()+" & "+query.value(6).toString());


        } else
        {

            QMessageBox::information(this,"Invalid Data","Sorry! No Results Found.... Please Try Again.");
            ui->lineEdit->clear();

        }

    }

    conn.connClose(); //Close the database connection

}


void Checkvaccinestatusscreen2::on_clearButton_clicked()
{
    ui->lineEdit->clear();
    ui->checkButton->setVisible(true);
    ui->nameLbl->setText("01. Name : ");
    ui->firstdosLbl->setText("02. Date Of First Dose of Covid Vaccine And Vaccine Type : " );
    ui->sendoseLbl->setText("03. Date Of Second Dose of Covid Vaccine And Vaccine Type : ");
    ui->thirddoseLbl->setText("04. Date Of Third Dose of Covid Vaccine And Vaccine Type : ");
}


void Checkvaccinestatusscreen2::on_backButton_clicked()
{
    this->hide();
    Homescreen homewin;
    homewin.setModal(true);
    homewin.exec();

}

