#ifndef HOMESCREEN_H
#define HOMESCREEN_H

#include <QDialog>

namespace Ui {
class Homescreen;
}

class Homescreen : public QDialog
{
    Q_OBJECT

public:
    explicit Homescreen(QWidget *parent = nullptr);
    ~Homescreen();

private slots:
    void on_addButton_clicked();

    void on_updateButton_clicked();

    void on_exitBTN_clicked();

    void on_checkButton_clicked();

    void on_viewButton_clicked();

private:
    Ui::Homescreen *ui;
};

#endif // HOMESCREEN_H
