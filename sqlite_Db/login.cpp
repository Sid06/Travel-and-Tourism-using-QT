#include "login.h"
#include "ui_login.h"
#include "QMessageBox"
login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    //QPixmap pix("D:/QtProject/sqlite_Db/Images/loginPicutre.jpg");
  //  ui->label_pic->setPixmap(pix);
    if(!connOpen())
    {
        ui->label->setText("Not connected");
    }
    else
        ui->label->setText("Connected...");
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    QString email,pswd;
    email=ui->lineEdit_Email->text();
    pswd=ui->lineEdit_Password->text();
    if(!connOpen())
    {
     qDebug()<<"Failed to open the Database";
     return;
    }
    connOpen();
    QSqlQuery Qry;
    Qry.prepare("Select * from user where email='"+email +"'and password='"+pswd+"'");
    if(Qry.exec())
    {
        int count=0;
        while(Qry.next())
        {
            count++;
        }
        if(count==1)
        {
            ui->label->setText("Username and password is correct");
            connClose();
            this->hide();
            home homeObj;
            homeObj.setModal(true);
            homeObj.exec();
        }
        if(count>1)
        {
            QMessageBox::critical(this,tr("UnSuccessful try"),tr("Duplicate data entered."));
        }
        if(count<1)
        {
            QMessageBox::critical(this,tr("UnSuccessful try"),tr("Email and password are not correct"));
            //ui->label->setText("Email and password are not correct");
        }
    }
}

void login::on_pushButton_2_clicked()
{
    this->hide();
    signup signUpObj;
    signUpObj.setModal(true);
    signUpObj.exec();
}
