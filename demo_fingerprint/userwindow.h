#ifndef USERWINDOW_H
#define USERWINDOW_H
#include <QWidget>
#include "finger.h"
#include "mysql.h"
#include "updatewindow.h"
#include <QMessageBox>
namespace Ui {
class userwindow;
}
class userwindow : public QWidget
{
    Q_OBJECT
public:
    explicit userwindow(QWidget *parent = 0);
    ~userwindow();
//    int take_user();

private slots:
    void on_confirm_button_clicked();

    void on_Quit_button_clicked();

    void on_pushButton_clicked();

private:
    Ui::userwindow *ui;

};

#endif // USERWINDOW_H
