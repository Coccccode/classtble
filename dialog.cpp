#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
QString countnum="";//表示星期几筛选
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::on_buttonBox_accepted()
{
    countnum=ui->comboBox->currentText();
    qDebug()<<countnum;
    emit signa();//发送信号让主窗口接收信号方便筛选
}
