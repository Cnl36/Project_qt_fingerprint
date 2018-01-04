#include "LoginPwWindow.h"
#include "ui_LoginPwWindow.h"

LoginPwWindow::LoginPwWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginPwWindow)
{
    ui->setupUi(this);
    QPixmap pix1("/home/chunglinh/Pictures/set.jpg");
    ui->label_3->setPixmap(pix1.scaled(130,100,Qt::KeepAspectRatio));
    ui->line_3->hide();
    ui->line_4->hide();
    ui->line_5->hide();
    ui->line_6->hide();
    ui->line_7->hide();
    ui->line_9->hide();
    ui->line_10->hide();
    ui->label_4->hide();
    ui->label_9->hide();
    ui->label_15->hide();
    ui->label_21->hide();
    ui->label_5->hide();
    ui->label_7->hide();
    ui->label_8->hide();
    ui->pushButton_4->hide();
    ui->pushButton_5->hide();
}
LoginPwWindow::~LoginPwWindow()
{
    delete ui;
}

void LoginPwWindow::on_pushButton_3_clicked()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("db_fingerprint");
    db.setUserName("root");
    db.setPassword("root");

    bool ok=db.open();
    if(ok){
        qDebug()<<"connected";
   }else{
        qDebug()<<"connect faile";
   }

    QString username = ui->username_line->text();
    QString password = ui->ID_line->text();
    QSqlQuery query;

    if (query.exec("SELECT * FROM users WHERE name='"+username+"'and password='"+password+"'")){

        ui->line_3->show();
        ui->line_4->show();
        ui->line_5->show();
        ui->line_6->show();
        ui->line_7->show();
        ui->line_9->show();
        ui->line_10->show();
        ui->label_4->show();
        ui->label_9->show();
        ui->label_15->show();
        ui->label_21->show();
        ui->label_5->show();
        ui->label_7->show();
        ui->label_8->show();
        ui->pushButton_4->show();
        ui->pushButton_5->show();
        ui->label->hide();
        ui->label_2->hide();
        ui->line->hide();
        ui->line_2->hide();
        ui->ID_line->hide();
        ui->username_line->hide();
        while(query.next()){
            QString name = query.value(1).toString();
            QString ID = query.value(2).toString();
            QString birthday = query.value(3).toString();
            QString address = query.value(4).toString();
            QString gender = query.value(5).toString();
            QString phone = query.value(6).toString();
            QString password = query.value(7).toString();
            ui->label_20->setText(name);
            ui->label_10->setText(ID);
            ui->label_11->setText(birthday);
            ui->label_19->setText(gender);
            ui->label_13->setText(password);
            ui->label_14->setText(phone);
            ui->label_12->setText(address);

              }
       }
       else{
           qDebug()<<"chua dang nhap thanh cong";
       }
db.close();
}

void LoginPwWindow::on_pushButton_2_clicked()
{
    this->close();
    MainWindow *w5= new MainWindow();
    w5->show();

}

void LoginPwWindow::on_pushButton_4_clicked()
{
    this->close();
    updatewindow *u2 = new updatewindow();
    u2->show();
}
