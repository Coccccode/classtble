#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include "head.h"
namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();
    DataType data;
signals:
    void sendData(DataType);//发送添加的数据给主窗口
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Form *ui;
};

#endif // FORM_H
