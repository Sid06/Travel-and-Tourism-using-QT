#include "signup.h"
#include "ui_signup.h"
#include "QMessageBox"
signup::signup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
    login conn;
    if(!conn.connOpen())
    {
        ui->label_signup_status->setText("Not connected");
    }
    else
        ui->label_signup_status->setText("Connected...");

    ui->comboBox->addItem("male");
    ui->comboBox->addItem("female");
}

signup::~signup()
{
    delete ui;
}

void signup::on_pushButton_3_clicked()
{
    //this->hide();
    //login loginObj;
    //loginObj.setModal(true);
    //loginObj.exec();
}

void signup::on_pushButton_clicked()
{
    login conn;
    QString name,email,pswd,gender,contact;
    name=ui->lineEdit_signup_name->text();
    email=ui->lineEdit_signup_email->text();
    pswd=ui->lineEdit_signup_password->text();
    contact=ui->lineEdit_signup_contact->text();
    gender=ui->comboBox->currentText();
    if(!conn.connOpen())
    {
     qDebug()<<"Failed to open the Database";
     return;
    }
    conn.connOpen();
    QSqlQuery Qry;
    Qry.prepare("insert into user(name,email,password,gender,contact) values('"+name+"','"+email+"','"+pswd+"','"+gender+"','"+contact+"')");
    if(Qry.exec())
    {
       QMessageBox::information(this,tr("Successful"),tr("Your account has been created. Now, Please login again."));
       this->hide();
       conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),Qry.lastError().text());
    }
}
