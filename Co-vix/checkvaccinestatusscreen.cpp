#include "checkvaccinestatusscreen.h"
#include "ui_checkvaccinestatusscreen.h"
#include "mainscreen.h"
#include "loginscreen.h"
#include "aboutus.h"

Checkvaccinestatusscreen::Checkvaccinestatusscreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Checkvaccinestatusscreen)
{
    ui->setupUi(this);
    this->setFixedSize(1200,750); //Size Fixed Window

    //Hiding & Showing UI Elements

    ui->errframe->setVisible(false);
    ui->nameLbl->setVisible(false);
    ui->firstdosLbl->setVisible(false);
    ui->sendoseLbl->setVisible(false);
    ui->thirddoseLbl->setVisible(false);
    ui->retryButton->setVisible(false);
    ui->clearButton->setVisible(false);

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

Checkvaccinestatusscreen::~Checkvaccinestatusscreen()
{
    delete ui;
}

void Checkvaccinestatusscreen::on_backButton_clicked()
{
    this->hide();
    MainScreen homewin;
    homewin.setModal(true);
    homewin.exec();
}


void Checkvaccinestatusscreen::on_checkButton_clicked()
{
    conn.connOpen(); //Open the database connection

    //Create Data Searching Process Using SQL

    QString nic;
    nic= ui->lineEdit->text();

    //Check lineEdit is Empty or not

    if(ui->lineEdit->text().isEmpty())
    {
        QMessageBox::information(this,"Invalid Data","You Have Entered An Invalid Data. Please Try Again.");

    }else
    {
        QSqlQuery query("SELECT NAME, FIRSTDOSEDATE , FIRSTDOSETYPE , SECONDDOSEDATE , SECONDDOSETYPE , THIRDDOSEDATE , THIRDDOSETYPE  FROM VACCINATED where NIC='"+nic+"' ");

        if(query.next())
        {
            ui->openframe->setVisible(false);
            ui->errframe->setVisible(false);
            ui->retryButton->setVisible(false);
            ui->checkButton->setVisible(false);
            ui->clearButton->setVisible(true);
            ui->nameLbl->setVisible(true);
            ui->firstdosLbl->setVisible(true);
            ui->sendoseLbl->setVisible(true);
            ui->thirddoseLbl->setVisible(true);

            ui->nameLbl->setText("01. Name : "+query.value(0).toString());
            ui->firstdosLbl->setText("02. Date Of First Dose of Covid Vaccine And Vaccine Type : "+ query.value(1).toString()+" & "+query.value(2).toString() );
            ui->sendoseLbl->setText("03. Date Of Second Dose of Covid Vaccine And Vaccine Type : "+ query.value(3).toString()+" & "+query.value(4).toString());
            ui->thirddoseLbl->setText("04. Date Of Third Dose of Covid Vaccine And Vaccine Type : "+ query.value(5).toString()+" & "+query.value(6).toString());


        } else
        {
            ui->errframe->setVisible(true);
            ui->retryButton->setVisible(true);
            ui->nameLbl->setVisible(false);
            ui->firstdosLbl->setVisible(false);
            ui->sendoseLbl->setVisible(false);
            ui->thirddoseLbl->setVisible(false);
            ui->openframe->setVisible(false);
            ui->clearButton->setVisible(false);
            ui->checkButton->setVisible(false);
        }

    }


    conn.connClose(); //Close the database connection
}


void Checkvaccinestatusscreen::on_clearButton_clicked()
{
    //Hiding & Showing UI Elements

    ui->errframe->setVisible(false);
    ui->nameLbl->setVisible(false);
    ui->firstdosLbl->setVisible(false);
    ui->sendoseLbl->setVisible(false);
    ui->thirddoseLbl->setVisible(false);
    ui->retryButton->setVisible(false);
    ui->clearButton->setVisible(false);
    ui->checkButton->setVisible(true);
    ui->openframe->setVisible(true);
    ui->lineEdit->clear();

}


void Checkvaccinestatusscreen::on_retryButton_clicked()
{
    //Hiding & Showing UI Elements

    ui->errframe->setVisible(false);
    ui->nameLbl->setVisible(false);
    ui->firstdosLbl->setVisible(false);
    ui->sendoseLbl->setVisible(false);
    ui->thirddoseLbl->setVisible(false);
    ui->retryButton->setVisible(false);
    ui->clearButton->setVisible(false);
    ui->checkButton->setVisible(true);
    ui->openframe->setVisible(true);
    ui->lineEdit->clear();
}


void Checkvaccinestatusscreen::on_homeBTN_clicked()
{
    this->hide();
    MainScreen homewin;
    homewin.setModal(true);
    homewin.exec();

}


void Checkvaccinestatusscreen::on_signinBTN_clicked()
{
    this->hide();
    LoginScreen loginwin;
    loginwin.setModal(true);
    loginwin.exec();
}


void Checkvaccinestatusscreen::on_aboutusBTN_clicked()
{
    this->hide();
    Aboutus checkvacwin;
    checkvacwin.setModal(true);
    checkvacwin.exec();
}

