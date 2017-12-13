#include "createuserwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "verify1.h"
#include "identify_finger_window.h"
#include "LoginPwWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix1("/home/chunglinh/Pictures/set.jpg");
    ui->label->setPixmap(pix1.scaled(130,100,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_3_clicked()
{
 this->close();
}

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
    LoginWindow *l1 = new LoginWindow();
    l1->show();
}

void MainWindow::on_pushButton_clicked()
{
   this->close();
   createuserwindow *w1 = new createuserwindow();
   w1->show();
}

