#ifndef ADDSCREEN_H
#define ADDSCREEN_H

#include <QDialog>
#include "mainscreen.h"

namespace Ui {
class Addscreen;
}

class Addscreen : public QDialog
{
    Q_OBJECT

 //Connect With MainScreen Class

    MainScreen conn;


public:
    explicit Addscreen(QWidget *parent = nullptr);
    ~Addscreen();

private slots:
    void on_backButton_clicked();

    void on_saveButton_clicked();

private:
    Ui::Addscreen *ui;
};

#endif // ADDSCREEN_H
