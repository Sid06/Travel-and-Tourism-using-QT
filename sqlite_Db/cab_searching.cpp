#include "cab_searching.h"
#include "ui_cab_searching.h"
#include"QMessageBox"
Cab_Searching::Cab_Searching(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cab_Searching)
{
    ui->setupUi(this);
}

Cab_Searching::~Cab_Searching()
{
    delete ui;
}

void Cab_Searching::on_pushButton_clicked()
{
      QMessageBox::information(this,tr("Successfully Booked"),tr("We will Send you the confirmation with driver and cab details on your registered number"));
      this->hide();
}

void Cab_Searching::on_pushButton_3_clicked()
{
      //QMessageBox::information(this,tr("Successfully Booked"),tr("Thankyou to give a chance to serve you best"));
        QMessageBox::information(this,tr("Successfully Booked"),tr("We will Send you the confirmation with driver and cab details on your registered mobile number"));
        this->hide();
}

void Cab_Searching::on_pushButton_2_clicked()
{
    QMessageBox::information(this,tr("Successfully Booked"),tr("We will Send you the confirmation with driver and cab details on your registered mobile number"));
    this->hide();
}

void Cab_Searching::on_pushButton_5_clicked()
{
    QMessageBox::information(this,tr("Successfully Booked"),tr("We will Send you the confirmation with driver and cab details on your registered mobile number"));
    this->hide();
}

void Cab_Searching::on_pushButton_4_clicked()
{
    QMessageBox::information(this,tr("Successfully Booked"),tr("We will Send you the confirmation with driver and cab details on your registered number"));
    this->hide();
}
