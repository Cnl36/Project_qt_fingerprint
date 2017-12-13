#ifndef LOGINPWWINDOW_H
#define LOGINPWWINDOW_H

#include "mainwindow.h"
#include <QWidget>
#include "userwindow.h"
#include <QSqlQuery>
#include <QDebug>
namespace Ui {
class LoginPwWindow ;
}

class LoginPwWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoginPwWindow(QWidget *parent = 0);
    ~LoginPwWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::LoginPwWindow *ui;
};

#endif // LOGINPWWINDOW_H
