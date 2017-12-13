#include "createuserwindow.h"
#include "ui_createuserwindow.h"
#include <QString>
#include <QSqlQueryModel>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mysql.h>
#include <mysql/mysql.h>
#include <string.h>
#include <QFileDialog>
#include <QMessageBox>
createuserwindow::createuserwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::createuserwindow)
{
    ui->setupUi(this);
    QPixmap pix1("/home/chunglinh/Pictures/set.jpg");
    ui->label_9->setPixmap(pix1.scaled(130,100,Qt::KeepAspectRatio));
   this->move(1,5);

}

createuserwindow::~createuserwindow()
{
    delete ui;
}

void createuserwindow::on_pushButton_clicked(){
    this->close();
   MainWindow *w2 = new MainWindow();
    w2->show();
}

int createuserwindow::create_user(void)
{
    int r = 1;
    struct fp_dscv_dev *ddev;
    struct fp_dscv_dev **discovered_devs;
    struct fp_dev *dev;
    struct fp_print_data *data;
   // QLabel *label =this->findChild<QLabel *>("news");
    printf("This program will enroll your right index finger, "
           "unconditionally overwriting any right-index print that was enrolled "
        "previously. If you want to continue, press enter, otherwise hit "
        "Ctrl+C\n");
       r = fp_init();
    if (r < 0) {
        fprintf(stderr, "Failed to initialize libfprint\n");
        exit(1);
     }
    fp_set_debug(3);

    discovered_devs = fp_discover_devs();
    if (!discovered_devs) {
         fprintf(stderr, "Could not discover devices\n");
         goto out;
     }

    ddev = discover_device(discovered_devs);
    if (!ddev) {
        fprintf(stderr, "No devices detected.\n");
         goto out;
     }

    dev = fp_dev_open(ddev);
    fp_dscv_devs_free(discovered_devs);
    if (!dev) {
    fprintf(stderr, "Could not open device.\n");
         goto out;
        }

    printf("Opened device. It's now time to enroll your finger.\n\n");
    data = enroll(dev);
    if (!data)
         goto out_close;
    unsigned char* ret;
    size_t ret_size;
    ret_size=fp_print_data_get_data(data,&ret);
        qDebug()<<ret_size;
   free(ret);
   fp_print_data_free(data);
   out_close:
      fp_dev_close(dev);
   out:
      fp_exit();

   return r;
}

void createuserwindow::on_pushButton_3_clicked(){

    QSqlDatabase firstdb=QSqlDatabase::addDatabase("QMYSQL");
    firstdb.setHostName("192.168.68.122");
    firstdb.setDatabaseName("db_fingerprint");
    firstdb.setUserName("user");
    firstdb.setPassword("password");

//    if(db.open()){
//        qDebug()<<"thanhcong";
//    }
//    QString imagePath = QFileDialog::getSaveFileName(this,"Save image to","/home/chunglinh/Pictures","JPEG Image (*.pgm)");
//        QModelIndex index;
//        QSqlQueryModel model;
//        QByteArray bytes;

//        QSqlQuery query;
//        query.exec("select image from users where idusers = 17 ");
//        if (!query.exec())
//        {
//            QMessageBox::critical(this,"Query error",query.lastError().text());
//        }
//        else
//        {
//            //Set model
//            model.setQuery(query);
//            index = model.index(0,0);
//            bytes = index.data().toByteArray();

//            //Save image
//            QImage imageWrite;
//            imageWrite.loadFromData(bytes);
//            qDebug()<<bytes;
//            imageWrite.save(imagePath,"pgm");

//        }
    if(firstdb.open()){
     QString name =ui->line_Name->text();
     QString ID =ui->line_ID->text();
     QString birthday =ui->dateEdit->text();
     QString address = ui->line_Ads->text();
     QString phone = ui->line_Phone->text();
     QString password = ui->line_Pw->text();
     QString gender = "other";

     QLabel *label = this->findChild<QLabel *>("news");

     if (ID.length() == 0 || password.length() == 0 || name.length() == 0 ||address.length() == 0 || phone.length() == 0 ) {
          label->setText("Please fill all information");
         label->setStyleSheet("QLabel {color : red; }");
         return;
    }


    if (ui->radio_female->isChecked() == true)
         gender = "Female";
         else if (ui->Radio_male->isChecked() == true)
         gender = "Male";
    QSqlQuery query;
    if (query.exec("INSERT INTO users (name, ID,birthday, address,gender,phone,password) VALUES ('" + name + "','" + ID + "','" + birthday + "','" + address + "','" + gender + "','"+ phone + "','"+password+"')"))
      {

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
   // firstdb.close();
}
void createuserwindow::on_pushButton_4_clicked()
{

    QString p = ui->Line_code->text();
    QByteArray ba = p.toLatin1();
    char *q = ba.data();
    qDebug()<<*q;
    char *finger_type="index finger";
    int r = 1;
    struct fp_dscv_dev *ddev;
    struct fp_dscv_dev **discovered_devs;
    struct fp_dev *dev;
    struct fp_print_data *data;

    printf("This program will enroll your right index finger, "
        "unconditionally overwriting any right-index print that was enrolled "
        "previously. If you want to continue, press enter, otherwise hit "
        "Ctrl+C\n");

    r = fp_init();
    if (r < 0) {
         fprintf(stderr, "Failed to initialize libfprint\n");
            exit(1);
    }
    fp_set_debug(3);

    discovered_devs = fp_discover_devs();
    if (!discovered_devs) {
         fprintf(stderr, "Could not discover devices\n");
        goto out;
    }

    ddev = discover_device(discovered_devs);
    if (!ddev) {
         fprintf(stderr, "No devices detected.\n");
         goto out;
    }

    dev = fp_dev_open(ddev);
    fp_dscv_devs_free(discovered_devs);
    if (!dev) {
         fprintf(stderr, "Could not open device.\n");
         goto out;
    }

    printf("Opened device. It's now time to enroll your finger.\n\n");

    data = enroll(dev);
    if (!data)
         goto out_close;
    unsigned char* ret;
    size_t ret_size;
    ret_size=fp_print_data_get_data(data,&ret);
    qDebug()<<ret_size;
    save_data_to_db(ret, ret_size,finger_type,q);


 out_close:
       fp_dev_close(dev);
 out:
       fp_exit();

   free(ret);
    fp_print_data_free(data);
}

void createuserwindow::on_pushButton_5_clicked()
{

    QString p = ui->Line_code->text();
    QByteArray ba = p.toLatin1();
    char *q = ba.data();
    qDebug()<<*q;
    char *finger_type="Midlle finger";
    int r = 1;
    struct fp_dscv_dev *ddev;
    struct fp_dscv_dev **discovered_devs;
    struct fp_dev *dev;
    struct fp_print_data *data;

    printf("This program will enroll your right index finger, "
        "unconditionally overwriting any right-index print that was enrolled "
        "previously. If you want to continue, press enter, otherwise hit "
        "Ctrl+C\n");

    r = fp_init();
    if (r < 0) {
         fprintf(stderr, "Failed to initialize libfprint\n");
            exit(1);
    }
    fp_set_debug(3);

    discovered_devs = fp_discover_devs();
    if (!discovered_devs) {
         fprintf(stderr, "Could not discover devices\n");
        goto out;
    }

    ddev = discover_device(discovered_devs);
    if (!ddev) {
         fprintf(stderr, "No devices detected.\n");
         goto out;
    }

    dev = fp_dev_open(ddev);
    fp_dscv_devs_free(discovered_devs);
    if (!dev) {
         fprintf(stderr, "Could not open device.\n");
         goto out;
    }

    printf("Opened device. It's now time to enroll your finger.\n\n");

    data = enroll(dev);
    if (!data)
         goto out_close;
    unsigned char* ret;
    size_t ret_size;
    ret_size=fp_print_data_get_data(data,&ret);
    qDebug()<<ret_size;
    save_data_to_db(ret, ret_size,finger_type,q);


 out_close:
       fp_dev_close(dev);
 out:
       fp_exit();

   free(ret);
    fp_print_data_free(data);
}

void createuserwindow::on_pushButton_6_clicked()
{
    QString p = ui->Line_code->text();
    QByteArray ba = p.toLatin1();
    char *q = ba.data();
    qDebug()<<*q;
    char *finger_type="Ring finger";
    int r = 1;
    struct fp_dscv_dev *ddev;
    struct fp_dscv_dev **discovered_devs;
    struct fp_dev *dev;
    struct fp_print_data *data;

    printf("This program will enroll your right index finger, "
        "unconditionally overwriting any right-index print that was enrolled "
        "previously. If you want to continue, press enter, otherwise hit "
        "Ctrl+C\n");

    r = fp_init();
    if (r < 0) {
         fprintf(stderr, "Failed to initialize libfprint\n");
            exit(1);
    }
    fp_set_debug(3);

    discovered_devs = fp_discover_devs();
    if (!discovered_devs) {
         fprintf(stderr, "Could not discover devices\n");
        goto out;
    }

    ddev = discover_device(discovered_devs);
    if (!ddev) {
         fprintf(stderr, "No devices detected.\n");
         goto out;
    }

    dev = fp_dev_open(ddev);
    fp_dscv_devs_free(discovered_devs);
    if (!dev) {
         fprintf(stderr, "Could not open device.\n");
         goto out;
    }

    printf("Opened device. It's now time to enroll your finger.\n\n");

    data = enroll(dev);
    if (!data)
         goto out_close;
    unsigned char* ret;
    size_t ret_size;
    ret_size=fp_print_data_get_data(data,&ret);
    qDebug()<<ret_size;
    save_data_to_db(ret, ret_size,finger_type,q);


 out_close:
       fp_dev_close(dev);
 out:
       fp_exit();

   free(ret);
    fp_print_data_free(data);
}
