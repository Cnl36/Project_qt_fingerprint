#include "userwindow.h"
#include "ui_userwindow.h"
#include "mainwindow.h"
#include <iostream>
#include <QPixmap>
#include <QPicture>
using namespace std;
userwindow::userwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userwindow)
{
    ui->setupUi(this);

QPixmap pix("/home/chunglinh/Pictures/print.pgm");
QPixmap pix1("/home/chunglinh/Pictures/set.jpg");
QPixmap pix2("/home/chunglinh/Pictures/print1.pgm");
ui->label_16->setPixmap(pix1.scaled(130,100,Qt::KeepAspectRatio));
ui->label->setPixmap(pix.scaled(180,170,Qt::KeepAspectRatio));
ui->label_19->setPixmap(pix2.scaled(180,170,Qt::KeepAspectRatio));
ui->label->hide();
ui->pushButton->hide();
ui->label_19->hide();
ui->label_20->hide();
  }

userwindow::~userwindow()
{
    delete ui;
}
struct fp_print_data **print_gallery;
char **usernames;
char **user_birthday;
char **user_ID;
char **user_phone;
char **user_address;
char **user_gender;
char **user_password;
char **user_code;
char *user;
struct fp_img *img = NULL;
 struct fp_img *new_img=NULL;
int *nr_minutiae;
void userwindow::on_confirm_button_clicked()
{


    MYSQL *con;
    init_mysql(con);
    char query[300];
    sprintf(query, "SELECT fingerprints.idfingerprints,fingerprints.finger_type,fingerprints.data, users.name,users.ID,users.birthday,users.address,users.gender,users.phone,users.password,fingerprints.users_idusers from fingerprints inner join users on fingerprints.users_idusers=users.idusers");
    if (mysql_query(con, query))
      {
        mysql_close(con);

      }

      MYSQL_RES *result = mysql_store_result(con);

      if (result == NULL)
      {
        mysql_close(con);

      }

      MYSQL_ROW row;

      int n_rows = mysql_num_rows(result);
     print_gallery = (fp_print_data**) malloc((n_rows + 1) * sizeof(fp_print_data*));
     usernames = (char**) malloc(n_rows * sizeof(char *));
      user_ID = (char**) malloc(n_rows * sizeof(char *));
      user_birthday = (char**) malloc(n_rows * sizeof(char *));
      user_address = (char**) malloc(n_rows * sizeof(char *));
      user_gender = (char**) malloc(n_rows * sizeof(char *));
      user_phone = (char**) malloc(n_rows * sizeof(char *));
      user_password = (char**) malloc(n_rows * sizeof(char *));
      user_code = (char**) malloc(n_rows * sizeof(char *));
      int index = 0;

     while ((row = mysql_fetch_row(result))) {
          user_ID[index]=row[4];
          user_birthday[index]=row[5];
          user_address[index]=row[6];
          user_gender[index]=row[7];
          user_phone[index]=row[8];
          user_password[index]=row[9];
          usernames[index] = row[3];
          user_code[index] = row[10];
       // qDebug()<<usernames[index];

      print_gallery[index++]= fp_print_data_from_data((unsigned char*)row[2], 12050);
     }
      print_gallery[index] = NULL; // it must be a NULL-terminated array

      int r =1;
      struct fp_dscv_dev *ddev;
      struct fp_dscv_dev **discovered_devs;
      struct fp_dev* dev;
      r = fp_init();
      if (r < 0) {
        qDebug() << "Failed to initialize libfprint\n";
        exit(1);
      }
      fp_set_debug(3);

      discovered_devs = fp_discover_devs();
      if (!discovered_devs) {
        qDebug() << "Could not discover devices\n";
      }
      ddev = discover_device(discovered_devs);
      if (!ddev) {
        qDebug() << "No devices detected.\n";


      }

      dev = fp_dev_open(ddev);


      fp_dscv_devs_free(discovered_devs);
      if (!dev) {
        qDebug() << "Could not open device.\n";
      }
ui->label_20->show();
      //qDebug() << "Opened device\n\n";



    size_t match_index;
    match_index = -1;
//struct fp_img *img = NULL;
   r = fp_identify_finger_img(dev, print_gallery,&match_index,&img);


    if (img) {



        new_img = fp_img_binarize(img);
        fp_img_save_to_file(new_img, "/home/chunglinh/Pictures/print1.pgm");
        fp_img_free(new_img);

    }

    if (r < 0) {
        printf("verification failed with error %d :(\n", r);

    }
    switch (r) {
    case FP_VERIFY_NO_MATCH:
        printf("NO MATCH!\n");

        qDebug()<<"not find match data";
        break;

    case FP_VERIFY_MATCH:
       printf("MATCH!\n");
       ui->label_8->setText(usernames[match_index]);
       ui->label_9->setText(user_ID[match_index]);
       ui->label_10->setText(user_gender[match_index]);
       ui->label_11->setText(user_birthday[match_index]);
       ui->label_12->setText(user_address[match_index]);
       ui->label_13->setText(user_password[match_index]);
       ui->label_14->setText(user_phone[match_index]);
       ui->label_18->setText(user_code[match_index]);
       ui->label->show();
       ui->label_19->show();
       ui->pushButton->show();
       ui->confirm_button->hide();
       break;
    case FP_VERIFY_RETRY:
        printf("Scan didn't quite work. Please try again.\n");
        break;
    case FP_VERIFY_RETRY_TOO_SHORT:
        printf("Swipe was too short, please try again.\n");
        break;
    case FP_VERIFY_RETRY_CENTER_FINGER:
        printf("Please center your finger on the sensor and try again.\n");
        break;
    case FP_VERIFY_RETRY_REMOVE_FINGER:
        printf("Please remove finger from the sensor and try again.\n");
        break;
}
     fp_print_data_free(*print_gallery);

fp_exit();
mysql_close(con);

}

void userwindow::on_Quit_button_clicked()
{
    this->close();
    MainWindow *w6 = new MainWindow();
    w6->show();
}

void userwindow::on_pushButton_clicked()
{
    this->close();
    updatewindow *i = new updatewindow();
    i->show();
}
