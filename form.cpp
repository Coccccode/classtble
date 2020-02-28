#include "form.h"
#include "ui_form.h"
Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_2_clicked()
{
    this->close();
}
void Form::on_pushButton_clicked()
{
    data.subjectName="(自定义)"+ui->lineEdit->text();
    data.classTime=ui->lineEdit_2->text().toInt();
    data.place=ui->lineEdit_3->text();
    data.teacher=ui->lineEdit_4->text();
    data.week=ui->lineEdit_5->text();
    data.term=ui->lineEdit_6->text().toInt();
    data.weekInfo=ui->lineEdit_7->text();
    emit sendData(data);
    this->close();
}
