#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include "mainwindow.h"
#include "LoginPwWindow.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
