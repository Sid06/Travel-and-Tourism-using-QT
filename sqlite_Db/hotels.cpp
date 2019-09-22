#include "hotels.h"
#include "ui_hotels.h"
#include "QMessageBox"
hotels::hotels(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hotels)
{
    ui->setupUi(this);
}

hotels::~hotels()
{
    delete ui;
}

void hotels::on_pushButton_clicked()
{
    QMessageBox::information(this,tr("Successfully Booked"),tr("Your Hotel has been Booked. Thankyou to give a chance to serve you best"));
    this->hide();
}

void hotels::on_pushButton_2_clicked()
{
    QMessageBox::information(this,tr("Successfully Booked"),tr("Your Hotel has been Booked. Thankyou to give a chance to serve you best"));
    this->hide();
}

void hotels::on_pushButton_3_clicked()
{
    QMessageBox::information(this,tr("Successfully Booked"),tr("Your Hotel has been Booked. Thankyou to give a chance to serve you best"));
    this->hide();
}

void hotels::on_pushButton_4_clicked()
{
    QMessageBox::information(this,tr("Successfully Booked"),tr("Your Hotel has been Booked. Thankyou to give a chance to serve you best"));
    this->hide();
}

void hotels::on_pushButton_5_clicked()
{
    QMessageBox::information(this,tr("Successfully Booked"),tr("Your Hotel has been Booked. Thankyou to give a chance to serve you best"));
    this->hide();
}
