#ifndef CHECKVACCINESTATUSSCREEN2_H
#define CHECKVACCINESTATUSSCREEN2_H

#include <QDialog>
#include "mainscreen.h"

namespace Ui {
class Checkvaccinestatusscreen2;
}

class Checkvaccinestatusscreen2 : public QDialog
{
    Q_OBJECT

//Connect With MainScreen Class

    MainScreen conn;

public:
    explicit Checkvaccinestatusscreen2(QWidget *parent = nullptr);
    ~Checkvaccinestatusscreen2();

private slots:
    void on_checkButton_clicked();

    void on_clearButton_clicked();

    void on_backButton_clicked();

private:
    Ui::Checkvaccinestatusscreen2 *ui;
};

#endif // CHECKVACCINESTATUSSCREEN2_H
