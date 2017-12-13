#ifndef UPDATEWINDOW_H
#define UPDATEWINDOW_H
#include <QWidget>
#include "mainwindow.h"
#include "mysql.h"
#include <QSqlQuery>
#include <QString>
#include <QDebug>
#include <QSqlError>
#include <QSqlDatabase>

namespace Ui {
class updatewindow;
}

class updatewindow : public QWidget
{
    Q_OBJECT

public:
    explicit updatewindow(QWidget *parent = 0);
    ~updatewindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::updatewindow *ui;
};

#endif // UPDATEWINDOW_H
