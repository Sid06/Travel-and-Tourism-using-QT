#ifndef LOGIN1_H
#define LOGIN1_H
#include "signup.h"
#include"home.h"
#include <QDialog>

namespace Ui {
class Login1;
}

class Login1 : public QDialog
{
    Q_OBJECT

public:
    explicit Login1(QWidget *parent = 0);
    ~Login1();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Login1 *ui;
};

#endif // LOGIN1_H
