#include "tablebooking.h"
#include "ui_tablebooking.h"
#include"QMessageBox"
tableBooking::tableBooking(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tableBooking)
{
    ui->setupUi(this);
}

tableBooking::~tableBooking()
{
    delete ui;
}

void tableBooking::on_pushButton_clicked()
{
    QMessageBox::information(this,tr("Successfully Booked"),tr("Your table is booked. Thankyou to give a chance to serve you best"));
    this->hide();
}

void tableBooking::on_pushButton_2_clicked()
{
    QMessageBox::information(this,tr("Successfully Booked"),tr("Your table is booked. Thankyou to give a chance to serve you best"));
    this->hide();
}

void tableBooking::on_pushButton_3_clicked()
{
    QMessageBox::information(this,tr("Successfully Booked"),tr("Your table is booked. Thankyou to give a chance to serve you best"));
    this->hide();
}

void tableBooking::on_pushButton_4_clicked()
{
    QMessageBox::information(this,tr("Successfully Booked"),tr("Your table is booked. Thankyou to give a chance to serve you best"));
    this->hide();}

void tableBooking::on_pushButton_5_clicked()
{
    QMessageBox::information(this,tr("Successfully Booked"),tr("Your table is booked. Thankyou to give a chance to serve you best"));
    this->hide();
}
