#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include <QDialog>
#include "mainscreen.h"

namespace Ui {
class LoginScreen;
}

class LoginScreen : public QDialog
{
    Q_OBJECT

    //Connect With MainScreen Class

    MainScreen conn;

public:
    explicit LoginScreen(QWidget *parent = nullptr);
    ~LoginScreen();

private slots:
    void on_signinButton_clicked();

    void on_backButton_clicked();

private:
    Ui::LoginScreen *ui;
};

#endif // LOGINSCREEN_H
