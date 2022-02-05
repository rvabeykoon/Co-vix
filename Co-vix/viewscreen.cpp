#include "viewscreen.h"
#include "ui_viewscreen.h"

#include "homescreen.h"

Viewscreen::Viewscreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Viewscreen)
{
    ui->setupUi(this);
    this->setFixedSize(1200,750); //Size Fixed Window

    // Check Database Connection

    if(!conn.connOpen())
    {
        QMessageBox::information(this,"Database Connection","Database Connection Is Not Successful. Please Try Again.");
    }

    QSqlQueryModel *modal = new QSqlQueryModel();
    conn.connOpen(); //Open the database connection

    QSqlQuery*qry= new QSqlQuery(conn.mydb);

    qry->prepare("SELECT * FROM VACCINATED");

    qry->exec();
    modal-> setQuery(*qry);
    ui->tableView->setModel(modal);
    conn.connClose(); //Close the database connection

    qDebug() <<(modal->rowCount());

    //Add Regular Expression

    QRegularExpression rx("^(?:19|20)?\\d{2}[0-9]{10}|[0-9]{9}[X|V]$");
    QValidator *validator = new QRegularExpressionValidator(rx, this);

    ui->lineEdit->setValidator(validator);
}

Viewscreen::~Viewscreen()
{
    delete ui;
}

void Viewscreen::on_searchButton_clicked()
{
    if(ui->lineEdit->text().isEmpty())
    {
        QMessageBox::information(this,"Invalid Data","You Have Entered An Invalid Data. Please Try Again.");
        QSqlQueryModel *modal = new QSqlQueryModel();
        conn.connOpen(); //Open the database connection

        QSqlQuery*qry= new QSqlQuery(conn.mydb);

        qry->prepare("SELECT * FROM VACCINATED");

        qry->exec();
        modal-> setQuery(*qry);
        ui->tableView->setModel(modal);
        conn.connClose(); //Close the database connection

        qDebug() <<(modal->rowCount());

    }else
    {
    QSqlQueryModel *modal = new QSqlQueryModel();
    conn.connOpen(); //Open the database connection

    QSqlQuery*qry= new QSqlQuery(conn.mydb);
    QString nic;
    nic= ui->lineEdit->text();
    qry->prepare("SELECT * FROM VACCINATED where NIC='"+nic+"' ");

    qry->exec();
    modal-> setQuery(*qry);
    ui->tableView->setModel(modal);
    conn.connClose(); //Close the database connection
    qDebug() <<(modal->rowCount());

}
}


void Viewscreen::on_searchButton_2_clicked()
{
    QSqlQueryModel *modal = new QSqlQueryModel();
    conn.connOpen(); //Open the database connection

    QSqlQuery*qry= new QSqlQuery(conn.mydb);

    qry->prepare("SELECT * FROM VACCINATED");

    qry->exec();
    modal-> setQuery(*qry);
    ui->tableView->setModel(modal);
    conn.connClose(); //Close the database connection

    qDebug() <<(modal->rowCount());

    ui->lineEdit->clear();

}


void Viewscreen::on_backButton_clicked()
{
    this->hide();
    Homescreen homewin;
    homewin.setModal(true);
    homewin.exec();
}

