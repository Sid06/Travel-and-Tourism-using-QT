#ifndef TABLEBOOKING_H
#define TABLEBOOKING_H
#include"home.h"
#include <QDialog>

namespace Ui {
class tableBooking;
}

class tableBooking : public QDialog
{
    Q_OBJECT

public:
    explicit tableBooking(QWidget *parent = 0);
    ~tableBooking();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::tableBooking *ui;
};

#endif // TABLEBOOKING_H
