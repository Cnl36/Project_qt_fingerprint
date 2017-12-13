#include "updatewindow.h"
#include "ui_updatewindow.h"

updatewindow::updatewindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::updatewindow)
{
    ui->setupUi(this);
    QPixmap pix1("/home/chunglinh/Pictures/set.jpg");
    ui->label_8->setPixmap(pix1.scaled(130,100,Qt::KeepAspectRatio));
}

updatewindow::~updatewindow()
{
    delete ui;
}

void updatewindow::on_pushButton_2_clicked()
{
    this->close();
    MainWindow *w7 = new MainWindow();
    w7->show();

}

void updatewindow::on_pushButton_clicked()
{

    QSqlDatabase firstdb=QSqlDatabase::addDatabase("QMYSQL");

    firstdb.setHostName("localhost");
    firstdb.setDatabaseName("db_fingerprint");
    firstdb.setUserName("root");
    firstdb.setPassword("root");

    if(firstdb.open()){
        QString name =ui->lineEdit->text();
        QString ID = ui->lineEdit_2->text();
        QString birthday = ui->lineEdit_3->text();
        QString address =ui->lineEdit_4->text();
        QString gender = "other";
        QString phone = ui ->lineEdit_5->text();
        QString password = ui->lineEdit_6->text();
        QString user_code = ui->Line_code->text();

        if (ui->radioButton_female->isChecked() == true)
             gender = "Female";
             else if (ui->radioButton_male->isChecked() == true)
             gender = "Male";
        QSqlQuery query;
        if (query.exec("update users set name='"+name+"',ID='"+ID+"',birthday='"+birthday+"',address='"+address+"',gender='"+gender+"',phone='"+phone+"',password='"+password+"' where idusers='"+user_code+"'"))
          {
    //        int currentID = query.lastInsertId().toInt();
             qDebug() << "Insert success.";
            }
             else
             {
            qDebug() << query.lastError().text();

            }
            }
            else
           {
             qDebug() << "Failed to connect to database.";

           }

    firstdb.close();



}
