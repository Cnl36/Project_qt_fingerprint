#ifndef VERIFY1_H
#define VERIFY1_H

#include <QWidget>

namespace Ui {
class verify1;
}

class verify1 : public QWidget
{
    Q_OBJECT

public:
    explicit verify1(QWidget *parent = 0);
    ~verify1();

private slots:
    void on_verify_Button_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::verify1 *ui;
};

#endif // VERIFY1_H
