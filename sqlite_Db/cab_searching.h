#ifndef CAB_SEARCHING_H
#define CAB_SEARCHING_H
#include"home.h"
#include <QDialog>

namespace Ui {
class Cab_Searching;
}

class Cab_Searching : public QDialog
{
    Q_OBJECT

public:
    explicit Cab_Searching(QWidget *parent = 0);
    ~Cab_Searching();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Cab_Searching *ui;
};

#endif // CAB_SEARCHING_H
