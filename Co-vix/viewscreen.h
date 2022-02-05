#ifndef VIEWSCREEN_H
#define VIEWSCREEN_H

#include <QDialog>
#include "mainscreen.h"

namespace Ui {
class Viewscreen;
}

class Viewscreen : public QDialog
{
    Q_OBJECT

    //Connect With MainScreen Class

       MainScreen conn;

public:
    explicit Viewscreen(QWidget *parent = nullptr);
    ~Viewscreen();

private slots:
       void on_searchButton_clicked();

       void on_searchButton_2_clicked();

       void on_backButton_clicked();

private:
    Ui::Viewscreen *ui;
};

#endif // VIEWSCREEN_H
