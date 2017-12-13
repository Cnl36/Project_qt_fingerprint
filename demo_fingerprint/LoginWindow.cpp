#include "LoginWindow.h"
#include "ui_LoginWindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_pushButton_3_clicked()
{
    this->close();
    LoginPwWindow *l1=new LoginPwWindow();
    l1->show();
}

void LoginWindow::on_pushButton_4_clicked()
{
    this->close();
    userwindow *u3 = new userwindow();
    u3->show();



}
void LoginWindow::on_pushButton_5_clicked()
{
    this->close();


}
