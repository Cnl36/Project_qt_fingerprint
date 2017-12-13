//#include "ui_identify_finger_window.h"
//#include <QtDebug>
//#include <mysql/mysql.h>
//#include "finger1.h"
//#include "identify_finger_window.h"
//#include <QProgressBar>

//identify_finger_window::identify_finger_window(QWidget *parent) :
//  QWidget(parent),
//  ui(new Ui::identify_finger_window)
//{
//  ui->setupUi(this);
//  this->move(0, 0);
// //  ui->progressBar->hide();


//}

//identify_finger_window::~identify_finger_window()
//{
//  delete ui;
//}

// struct fp_print_data **print_gallery;
// char **usernames;

//void identify_finger_window::on_pushButton_2_clicked()
//{



//    MYSQL *con;
//    init_mysql(con);
//    char query[300];
//    sprintf(query, "SELECT fingerprints.idfingerprints,fingerprints.data,users.name from fingerprints inner join users on fingerprints.idfingerprints=users.idusers");
//    if (mysql_query(con, query))
//      {
//        mysql_close(con);

//      }


//      MYSQL_RES *result = mysql_store_result(con);

//      if (result == NULL)
//      {
//        mysql_close(con);

//      }

//      MYSQL_ROW row;

//      int n_rows = mysql_num_rows(result);

//     print_gallery = (fp_print_data**) malloc((n_rows + 1) * sizeof(fp_print_data*));
//      usernames = (char**) malloc(n_rows * sizeof(char *));

//      int index = 0;
//      while ((row = mysql_fetch_row(result))) {

//       usernames[index] = row[2];
//        qDebug()<<usernames[index];
//      print_gallery[index++]= fp_print_data_from_data((unsigned char*)row[1], 12050);

//     }
//      print_gallery[index] = NULL; // it must be a NULL-terminated array
//      int r =1;
//      struct fp_dscv_dev *ddev;
//      struct fp_dscv_dev **discovered_devs;
//      struct fp_dev* dev;

//      r = fp_init();
//      if (r < 0) {
//        qDebug() << "Failed to initialize libfprint\n";
//        exit(1);
//      }
//      fp_set_debug(3);

//      discovered_devs = fp_discover_devs();
//      if (!discovered_devs) {
//        qDebug() << "Could not discover devices\n";
//        fp_exit();


//      }

//      ddev = discover_device(discovered_devs);
//      if (!ddev) {
//        qDebug() << "No devices detected.\n";
//        fp_exit();


//      }

//      dev = fp_dev_open(ddev);
//      fp_dscv_devs_free(discovered_devs);
//      if (!dev) {
//        qDebug() << "Could not open device.\n";
//fp_exit();
//      }

//      qDebug() << "Opened device\n\n";



////    QProgressBar *progressBar = ui->progressBar;
////    QLabel *label = this->findChild<QLabel *>("identifyMsg");
////    progressBar->show();
////    label->setText("Please enroll your finger!");
////    label->setStyleSheet("QLabel {color : blue; }");
////    qApp->processEvents();
//    size_t match_index;
//    match_index = -1;
////struct fp_img *img = NULL;
//   r = fp_identify_finger(dev, print_gallery,&match_index);
////    if (img) {
////        fp_img_save_to_file(img, "/home/chunglinh/Pictures/verify.pgm");
////        printf("Wrote scanned image to verify.pgm\n");
////        fp_img_free(img);
////    }
//    if (r < 0) {
//        printf("verification failed with error %d :(\n", r);

//    }
//    switch (r) {
//    case FP_VERIFY_NO_MATCH:
//        printf("NO MATCH!\n");

//        qDebug()<<"not find match data";
//        break;

//    case FP_VERIFY_MATCH:
//       printf("MATCH!\n");
//       qDebug()<<usernames[match_index];


//        break;
//    case FP_VERIFY_RETRY:
//        printf("Scan didn't quite work. Please try again.\n");
//        break;
//    case FP_VERIFY_RETRY_TOO_SHORT:
//        printf("Swipe was too short, please try again.\n");
//        break;
//    case FP_VERIFY_RETRY_CENTER_FINGER:
//        printf("Please center your finger on the sensor and try again.\n");
//        break;
//    case FP_VERIFY_RETRY_REMOVE_FINGER:
//        printf("Please remove finger from the sensor and try again.\n");
//        break;
//}

//   fp_print_data_free(*print_gallery);

//}


//void identify_finger_window::on_pushButton_clicked()
//{
//  this->close();
//  MainWindow *main = new MainWindow();
//  main->show();
//}
