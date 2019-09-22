#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include<QtSql>
#include<QDebug>
#include<QFileInfo>
#include "home.h"
#include "signup.h"
namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase myDb;
    void connClose()
    {
        myDb.close();
        myDb.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen()
    {
        myDb = QSqlDatabase::addDatabase("QSQLITE");
        myDb.setDatabaseName("C:/SQlite2/userDetails.db");
        if(!myDb.open())
        {
            qDebug()<<("Not connected");
            return false;
        }
        else
            qDebug()<<("Connected...");
            return true;
    }

public:
    explicit login(QWidget *parent = 0);
    ~login();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::login *ui;

};

#endif // LOGIN_H
