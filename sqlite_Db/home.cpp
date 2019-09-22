#include "home.h"
#include "ui_home.h"
#include "QMessageBox"
home::home(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::home)
{
    ui->setupUi(this);
    login conn,homeObj;
    if(!conn.connOpen())
    {
        ui->label_home_status->setText("Not connected");
    }
    else
        ui->label_home_status->setText("Connected...");

    ui->comboBox->addItem("New Delhi");
    ui->comboBox->addItem("Jaipur");
    ui->comboBox->addItem("Mumbai");
    ui->comboBox->addItem("Pune");
    ui->comboBox->addItem("Kolkata");
    ui->comboBox->addItem("Goa");
    ui->combo_person->addItem("1");
    ui->combo_person->addItem("2");
    ui->combo_person->addItem("3");
    //for cabs
    ui->comboBox_4->addItem("New Delhi");
    ui->comboBox_4->addItem("Jaipur");
    ui->comboBox_4->addItem("Mumbai");
    ui->comboBox_4->addItem("Pune");
    ui->comboBox_4->addItem("Kolkata");
    ui->comboBox_4->addItem("Goa");
    //for resturants
    ui->comboBox_2->addItem("New Delhi");
    ui->comboBox_2->addItem("Jaipur");
    ui->comboBox_2->addItem("Mumbai");
    ui->comboBox_2->addItem("Pune");
    ui->comboBox_2->addItem("Kolkata");
    ui->comboBox_2->addItem("Goa");
    ui->comboBox_3->addItem("1");
    ui->comboBox_3->addItem("2");
    ui->comboBox_3->addItem("3");

}

home::~home()
{
    delete ui;
}



void home::on_pushButton_clicked()
{
    login conn;
    QString city,person;
    QString checkin_date,checkin_time,checkout_date,checkout_time;
    checkin_date=ui->checkin_date->text();
    checkin_time=ui->checkin_time->text();
    checkout_date=ui->chechout_date->text();
    checkout_time=ui->checkout_time->text();
    //QDateTime checkin,checkout;
    city=ui->comboBox->currentText();
   // checkin=ui->();
    person=ui->combo_person->currentText();
    //contact=ui->lineEdit_signup_contact->text();
    if(!conn.connOpen())
    {
     qDebug()<<"Failed to open the Database";
     return;
    }
    conn.connOpen();
    QSqlQuery Qry;
    Qry.prepare("insert into hotelBooking(city,checkin_date,checkin_time,checkout_date,checkout_time,persons) values('"+city+"','"+checkin_date+"','"+checkin_time+"','"+checkout_date+"','"+checkout_time+"','"+person+"')");
    if(Qry.exec())
    {
       QMessageBox::information(this,tr("Search"),tr("We found some hotels for you. Please press ok to view."));
       this->hide();
       hotels hotelObj;
       hotelObj.setModal(true);
       hotelObj.exec();

        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),Qry.lastError().text());
    }
}

void home::on_pushButton_3_clicked()
{
    login conn;
    QString source,destination,cab_date,cab_timing,cab_city;
    source=ui->source_cab->text();
    destination=ui->destination_cab->text();
    cab_date=ui->cab_date->text();
    cab_timing=ui->cab_time->text();
    //QDateTime checkin,checkout;
    cab_city=ui->comboBox_4->currentText();
   // checkin=ui->();
    //person=ui->combo_person->currentText();
    //contact=ui->lineEdit_signup_contact->text();
    if(!conn.connOpen())
    {
     qDebug()<<"Failed to open the Database";
     return;
    }
    conn.connOpen();
    QSqlQuery Qry;
    Qry.prepare("insert into cabDetails(City,source,destination,CabDate,CabTime) values('"+cab_city+"','"+source+"','"+destination+"','"+cab_date+"','"+cab_timing+"')");
    if(Qry.exec())
    {
       QMessageBox::information(this,tr("Search"),tr("Choose your cab and book it now."));
      this->hide();
        Cab_Searching cabsObj;
       cabsObj.setModal(true);
       cabsObj.exec();

        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),Qry.lastError().text());
    }
}

void home::on_pushButton_2_clicked()
{
    login conn;
    QString Tablename,TableCity,TablePerson,Book;
    Tablename=ui->tablename->text();
    //destination=ui->destination_cab->text();
    //cab_date=ui->cab_date->text();
    //cab_timing=ui->cab_time->text();
    //QDateTime checkin,checkout;
    TableCity=ui->comboBox_2->currentText();
    TablePerson=ui->comboBox_3->currentText();
   // checkin=ui->();
    //person=ui->combo_person->currentText();
    //contact=ui->lineEdit_signup_contact->text();
    if(!conn.connOpen())
    {
     qDebug()<<"Failed to open the Database";
     return;
    }
    conn.connOpen();
    QSqlQuery Qry;
    Qry.prepare("insert into TableBooking(Name,city,Person,Status) values('"+Tablename+"','"+TableCity+"','"+TablePerson+"','Booked')");
    if(Qry.exec())
    {
       QMessageBox::information(this,tr("Search"),tr("We found some best class resturants for you. Please press ok to view."));
      this->hide();
        tableBooking tbObj;
       tbObj.setModal(true);
       tbObj.exec();

        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),Qry.lastError().text());
    }
}

void home::on_pushButton_4_clicked()
{
    login conn;
    QString complaint_name,complaint_email,complaint_msg;
    complaint_name=ui->complaint_name->text();
    complaint_email=ui->complaint_email->text();
    complaint_msg=ui->complaint_msg->toPlainText();
    if(!conn.connOpen())
    {
     qDebug()<<"Failed to open the Database";
     return;
    }
    conn.connOpen();
    QSqlQuery Qry;
    Qry.prepare("insert into contact(name,email,msg) values('"+complaint_name+"','"+complaint_email+"','"+complaint_msg+"')");
    if(Qry.exec())
    {
       QMessageBox::information(this,tr("Complaint sent"),tr("Thankyou for contacting us. our costumer service executive will get back to you shortly."));

        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("error::"),Qry.lastError().text());
    }
}
