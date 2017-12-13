#include "verify1.h"
#include "ui_verify1.h"
#include "mainwindow.h"
#include "finger.h"
#include "createuserwindow.h"
#include "mysql.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QFileDialog>
#include <QMessageBox>
verify1::verify1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::verify1)
{
    ui->setupUi(this);
}

verify1::~verify1()
{
    delete ui;
}
void verify1::on_verify_Button_clicked()
{
    this->close();
    MainWindow *w3 = new MainWindow();
    w3->show();
}
int get_data_from_username( int idusers,struct fp_print_data *data1)
{
  return 0;
  MYSQL *con = mysql_init(NULL);
  if (con == NULL)
    {
        fprintf(stderr, "mysql_init() failed\n");
        exit(1);
    }


  if (mysql_real_connect(con, "localhost", "root", "root",
            "db_fingerprint", 3306, NULL, 0) == NULL)
    {
      mysql_close(con);
      return 2;
    }
  char query[300];
  sprintf(query, "SELECT image FROM users WHERE idusers=('%d')", idusers);
  if (mysql_query(con, query))
    {
      mysql_close(con);
      return 2;
    }

    MYSQL_RES *result = mysql_store_result(con);

    if (result == NULL)
    {
      mysql_close(con);
      return 2;
    }


    MYSQL_ROW row = mysql_fetch_row(result);

    unsigned long *lengths = mysql_fetch_lengths(result);

    if (lengths == NULL) {
      mysql_close(con);
      return 2;
    }

    data1 = fp_print_data_from_data((unsigned char*)row[0], lengths[0]);
    return 0;
}

void verify1::on_pushButton_2_clicked()
{
    struct fp_dev *dev;

    struct fp_print_data *data1;
   // int idusers;
    MYSQL *con = mysql_init(NULL);
    if (con == NULL)
      {
          fprintf(stderr, "mysql_init() failed\n");
          exit(1);
      }


    if (mysql_real_connect(con, "localhost", "root", "root",
              "db_fingerprint", 3306, NULL, 0) == NULL)
      {
        mysql_close(con);

      }
//    char query[300];
//    sprintf(query, "SELECT image FROM users");
//    if (mysql_query(con, query))

    if (mysql_query(con, "SELECT data FROM fingerprints where idfingerprints=1"))
      {
        mysql_close(con);

      }

      MYSQL_RES *result = mysql_store_result(con);

      if (result == NULL)
      {
        mysql_close(con);

      }
      MYSQL_ROW row = mysql_fetch_row(result);

      unsigned long *lengths = mysql_fetch_lengths(result);

      if (lengths == NULL) {
        mysql_close(con);

      }

      data1 = fp_print_data_from_data((unsigned char*)row[0], lengths[0]);
      if(!data1){
          qDebug()<<"error";
      }else
          qDebug()<<"true";

   int r = 1;
  // struct fp_dev *dev;

    struct fp_dscv_dev *ddev;
    struct fp_dscv_dev **discovered_devs;

   // struct fp_print_data *data;

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

    printf("Opened device. Loading previously enrolled right index finger "
        "data...\n");
//    data = enroll(dev);
//        if (!data)

//            goto out_close;

      //  unsigned char* ret;
       //            size_t ret_size;
       //            ret_size=fp_print_data_get_data(data,&ret);
       //            qDebug()<<ret_size;
//        FILE* pFile;
//        pFile = fopen("/home/chunglinh/Pictures/enroll1.bin", "wb");
//        if (pFile){
//         fwrite(ret,12050, 1, pFile);
//            fwrite(ret,12050,1,pFile);
//          printf("Wrote to file!");
//      }
//      else{
//            printf("Something wrong writiyng to File.");
//       }

//fclose(pFile);


//        QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
//       db.setHostName("localhost");
//       db.setDatabaseName("db_fingerprint");
//        db.setUserName("root");
//       db.setPassword("root");

//       if(db.open()){
//           qDebug()<<"thanhcong";
//       }
      // QString imagePath = QFileDialog::getSaveFileName(this,"Save image to","/home/chunglinh/Pictures","JPEG Image (*.pgm)");
//           QModelIndex index;
//           QSqlQueryModel model;
//           QByteArray bytes;

//           QSqlQuery query;
//           query.exec("select image from users where idusers = 11 ");
//           if (!query.exec())
//           {
//               QMessageBox::critical(this,"Query error",query.lastError().text());
//           }
//           else
//           {
    //           //Set model
//               model.setQuery(query);
//               index = model.index(0,0);
//               bytes = index.data().toByteArray();


    //           //Save image
//               QImage imageWrite;
//               imageWrite.loadFromData(bytes);
//               qDebug()<<bytes;
             //  imageWrite.save(imagePath,"pgm");

        //   }







//   r = fp_print_data_load(dev, RIGHT_INDEX,&data1);
//    if (r != 0) {
//        fprintf(stderr, "Failed to load fingerprint, error %d\n", r);
//        fprintf(stderr, "Did you remember to enroll your right index finger "
//            "first?\n");
//       goto out_close;
//   }


//   printf("Print loaded. Time to verify!\n");
   // do {
     //   char buffer[20];
 verify(dev,data1);
       //     break;
   //} while (1);
//free(ret);
//fp_print_data_free(data);
fp_print_data_free(data1);
//out_close:
//    fp_dev_close(dev);
out:
    fp_exit();

}
