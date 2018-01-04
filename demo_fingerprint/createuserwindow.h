#ifndef CREATEUSERWINDOW_H
#define CREATEUSERWINDOW_H
#include "mysql.h"
#include <QWidget>
#include "mainwindow.h"
#include "finger.h"
#include <QSqlQuery>
#include <QString>
#include <QDate>
#include <QRadioButton>
#include <QSqlDatabase>
#include "mysql.h"
#include <QSqlError>
#include <QDebug>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include "finger.h"
namespace Ui {
class createuserwindow;
}

class createuserwindow : public QWidget
{
    Q_OBJECT

   public:

    explicit createuserwindow(QWidget *parent = 0);
    ~createuserwindow();

private slots:

    void on_pushButton_clicked();
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:

    Ui::createuserwindow *ui;

};

#endif // CREATEUSERWINDOW_H
