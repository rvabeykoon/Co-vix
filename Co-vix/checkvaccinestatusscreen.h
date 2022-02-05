#ifndef CHECKVACCINESTATUSSCREEN_H
#define CHECKVACCINESTATUSSCREEN_H

#include <QDialog>

#include "mainscreen.h"

namespace Ui {
class Checkvaccinestatusscreen;
}

class Checkvaccinestatusscreen : public QDialog
{
    Q_OBJECT

public:

    //Connect With MainScreen Class

    MainScreen conn;

    explicit Checkvaccinestatusscreen(QWidget *parent = nullptr);
    ~Checkvaccinestatusscreen();

private slots:
    void on_backButton_clicked();

    void on_checkButton_clicked();

    void on_clearButton_clicked();

    void on_retryButton_clicked();

    void on_homeBTN_clicked();

    void on_signinBTN_clicked();

    void on_aboutusBTN_clicked();

private:
    Ui::Checkvaccinestatusscreen *ui;
};

#endif // CHECKVACCINESTATUSSCREEN_H
