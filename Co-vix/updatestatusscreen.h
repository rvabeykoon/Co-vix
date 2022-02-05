#ifndef UPDATESTATUSSCREEN_H
#define UPDATESTATUSSCREEN_H

#include <QDialog>
#include "mainscreen.h"

namespace Ui {
class Updatestatusscreen;
}

class Updatestatusscreen : public QDialog
{
    Q_OBJECT

    //Connect With MainScreen Class

    MainScreen conn;

public:
    explicit Updatestatusscreen(QWidget *parent = nullptr);
    ~Updatestatusscreen();

private slots:
    void on_backButton_clicked();

    void on_searchButton_clicked();

    void on_confirmButton_clicked();

    void on_updateButton_clicked();

private:
    Ui::Updatestatusscreen *ui;
};

#endif // UPDATESTATUSSCREEN_H
