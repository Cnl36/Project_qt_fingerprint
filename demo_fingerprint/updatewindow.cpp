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

void updatewindow::on_pushButton_4_clicked()
{
    QString p = ui->Line_code->text();
    QByteArray ba = p.toLatin1();
    char *q = ba.data();
    qDebug()<<*q;
    char *finger_type="first_finger";
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
    update_data_to_db(ret, ret_size,finger_type,q);


 out_close:
       fp_dev_close(dev);
 out:
       fp_exit();

   free(ret);
    fp_print_data_free(data);
}

void updatewindow::on_pushButton_5_clicked()
{
    QString p = ui->Line_code->text();
    QByteArray ba = p.toLatin1();
    char *q = ba.data();
    qDebug()<<*q;
    char *finger_type="second_finger";
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
    update_data_to_db(ret, ret_size,finger_type,q);


 out_close:
       fp_dev_close(dev);
 out:
       fp_exit();

   free(ret);
    fp_print_data_free(data);
}

void updatewindow::on_pushButton_6_clicked()
{
    QString p = ui->Line_code->text();
    QByteArray ba = p.toLatin1();
    char *q = ba.data();
    qDebug()<<*q;
    char *finger_type="third_finger";
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
    update_data_to_db(ret, ret_size,finger_type,q);


 out_close:
       fp_dev_close(dev);
 out:
       fp_exit();

   free(ret);
    fp_print_data_free(data);
}
