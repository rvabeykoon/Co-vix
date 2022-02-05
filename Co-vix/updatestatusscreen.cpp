#include "updatestatusscreen.h"
#include "ui_updatestatusscreen.h"
#include "homescreen.h"

Updatestatusscreen::Updatestatusscreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Updatestatusscreen)
{
    ui->setupUi(this);
    this->setFixedSize(1200,750); //Size Fixed Window


    //Add Regular Expression

    QRegularExpression rx("^(?:19|20)?\\d{2}[0-9]{10}|[0-9]{9}[X|V]$");
    QValidator *validator = new QRegularExpressionValidator(rx, this);

    ui->lineEdit_6->setValidator(validator);

    // Check Database Connection

    if(!conn.connOpen())
    {
        QMessageBox::information(this,"Database Connection","Database Connection Is Not Successful. Please Try Again.");
    }

}

Updatestatusscreen::~Updatestatusscreen()
{
    delete ui;
}

void Updatestatusscreen::on_backButton_clicked()
{
    this->hide();
    Homescreen homewin;
    homewin.setModal(true);
    homewin.exec();
}


void Updatestatusscreen::on_searchButton_clicked()
{
    conn.connOpen(); //Open the database connection

    //Data Showing

    QString nic;
    nic= ui->lineEdit_6->text();

    if(ui->lineEdit_6->text().isEmpty())
    {
        QMessageBox::information(this,"Invalid Data","You Have Entered An Invalid Data. Please Try Again.");

    }else
    {
        QSqlQuery query("SELECT NAME, AGE , FIRSTDOSEDATE , FIRSTDOSETYPE , SECONDDOSEDATE , SECONDDOSETYPE , THIRDDOSEDATE , THIRDDOSETYPE  FROM VACCINATED where NIC='"+nic+"' ");

        if(query.next())
        {

            ui->searchButton->setVisible(false);
            ui->nameLbl_3->setText( query.value(0).toString());
            ui->nameLbl_8->setText( query.value(1).toString());

            ui->lineEdit_7->setText( query.value(2).toString());
            ui->lineEdit_5->setText( query.value(3).toString());

            ui->lineEdit_8->setText( query.value(4).toString());
            ui->lineEdit_9->setText( query.value(5).toString());

            ui->lineEdit_11->setText( query.value(6).toString());
            ui->lineEdit_10->setText( query.value(7).toString());

            ui->updateButton->setVisible(false);

            ui->lineEdit_7->setReadOnly(true);
            ui->lineEdit_5->setReadOnly(true);
            ui->lineEdit_8->setReadOnly(true);
            ui->lineEdit_9->setReadOnly(true);
            ui->lineEdit_10->setReadOnly(true);
            ui->lineEdit_11->setReadOnly(true);



        } else
        {

            QMessageBox::information(this,"Invalid Data","Sorry! No Results Found.... Please Try Again.");
            ui->lineEdit_6->clear();

        }

    }

    conn.connClose(); //Close the database connection
}


void Updatestatusscreen::on_confirmButton_clicked()
{
    ui->updateButton->setVisible(true);
    ui->lineEdit_7->setReadOnly(false);
    ui->lineEdit_5->setReadOnly(false);
    ui->lineEdit_8->setReadOnly(false);
    ui->lineEdit_9->setReadOnly(false);
    ui->lineEdit_10->setReadOnly(false);
    ui->lineEdit_11->setReadOnly(false);
}


void Updatestatusscreen::on_updateButton_clicked()
{
    QString nic, fddate,fdtype,sddate,sdtype,tddate,tdtype;

    nic= ui->lineEdit_6->text();

    fddate= ui->lineEdit_7->text();
    fdtype= ui->lineEdit_5->text();

    sddate= ui->lineEdit_8->text();
    sdtype= ui->lineEdit_9->text();

    tddate= ui->lineEdit_11->text();
    tdtype= ui->lineEdit_10->text();


    if(ui->lineEdit_5->text().isEmpty() )
    {
        fddate = " - ";
        fdtype = " - ";
    }else
    {
        fddate= ui->lineEdit_7->text();
    }

    if(ui->lineEdit_9->text().isEmpty())
    {
        sddate = " - ";
        sdtype = " - ";
    }else
    {
        sddate= ui->lineEdit_8->text();
    }

    if(ui->lineEdit_10->text().isEmpty())
    {
        tddate = " - ";
        tdtype = " - ";
    }else
    {
        tddate= ui->lineEdit_11->text();
    }

    if(!conn.connOpen()){
        qDebug()<<"failed to open the db";
        return;
    }

    conn.connOpen(); //Open the database connection

    //Data Update

    QSqlQuery qry;
    qry.prepare("UPDATE VACCINATED set FIRSTDOSEDATE ='"+ fddate +"' ,  FIRSTDOSETYPE ='"+ fdtype +"' , SECONDDOSEDATE ='"+ sddate +"' , SECONDDOSETYPE ='"+ sdtype +"' , THIRDDOSEDATE ='"+ tddate +"' , THIRDDOSETYPE ='"+ tdtype +"' where NIC='"+nic+"' ");

    if(qry.exec())
    {
         QMessageBox::information(this,"UPDATE RECORD","SUCCESSFUL !!");
         conn.connClose(); //Close the database connection

         ui->searchButton->setVisible(true);
         ui->lineEdit_6->clear();

         ui->nameLbl_3->clear();
         ui->nameLbl_3->clear();

         ui->lineEdit_7->clear();
         ui->lineEdit_5->clear();
         ui->lineEdit_8->clear();
         ui->lineEdit_9->clear();
         ui->lineEdit_10->clear();
         ui->lineEdit_11->clear();

    }else
    {
        QMessageBox::information(this," NOT UPDATE RECORD", qry.lastError().text());
        ui->searchButton->setVisible(true);
    }
}

