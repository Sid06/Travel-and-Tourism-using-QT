#ifndef HOTELS_H
#define HOTELS_H
#include"home.h"
#include <QDialog>

namespace Ui {
class hotels;
}

class hotels : public QDialog
{
    Q_OBJECT

public:
    explicit hotels(QWidget *parent = 0);
    ~hotels();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::hotels *ui;
};

#endif // HOTELS_H
