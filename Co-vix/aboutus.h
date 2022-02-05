#ifndef ABOUTUS_H
#define ABOUTUS_H

#include <QDialog>
#include "mainscreen.h"

namespace Ui {
class Aboutus;
}

class Aboutus : public QDialog
{
    Q_OBJECT

public:
    explicit Aboutus(QWidget *parent = nullptr);
    ~Aboutus();

private slots:
    void on_backButton_clicked();

private:
    Ui::Aboutus *ui;
};

#endif // ABOUTUS_H
