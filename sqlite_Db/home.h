#ifndef HOME_H
#define HOME_H
#include <QDateTime>
#include <QDialog>
#include<QtSql>
#include<QDebug>
#include<QFileInfo>
#include "login.h"
#include"signup.h"
#include"hotels.h"
#include"cab_searching.h"
#include"tablebooking.h"
namespace Ui {
class home;
}

class home : public QDialog
{
    Q_OBJECT

public:
    explicit home(QWidget *parent = 0);
    ~home();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::home *ui;
};

#endif // HOME_H
