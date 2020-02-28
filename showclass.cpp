#include "showclass.h"
#include "ui_showclass.h"
#include <QMessageBox>
#include <QStandardItem>
#include <QStandardItemModel>
#include <stdio.h>
showClass::showClass(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::showClass)
{
    head=new Node();
    ui->setupUi(this);
}

showClass::~showClass()
{
    delete ui;
}
int showClass::calcWeek(QDate startTime){
    int flag=0;
    while(1){
        if(startTime.dayOfWeek()!=1){
        startTime=startTime.addDays(1);
        flag=1;
        }
        else {
            break;
        }
    }
    QDate end=QDate::currentDate();
    int week=startTime.daysTo(end)/7+1+flag;
    return week;
}
void showClass::getHead(Node *pHead){
    head=pHead;
}
QString showClass:: transform(int week){
    switch (week){
            case 1:
                return "星期一";break;
            case 2:
                return "星期二";break;
            case 3:
                return "星期三";break;
            case 4:
                return "星期四";break;
            case 5:
                return "星期五";break;
            case 6:
                return "星期六";break;
            case 7:
               return "星期日";break;
    }
}
void showClass::findTodayClass(){
    head=head->next;
    QStandardItemModel *ItemModel=new QStandardItemModel();
    while(head){
        qDebug()<<head->data.start<<head->data.end;
        if(head->data.term==term&&transform(weekNum)==head->data.weekInfo
        &&weekDay>=head->data.start&&weekDay<=head->data.end){//如果条件符合则输出判断是否在所在周
                QString string = head->data.subjectName+"课时:"+
                        QString::number(head->data.classTime) +"地点:"
                        +head->data.place+"老师:"+head->data.teacher;
                QStandardItem *item = new QStandardItem(string);
                ItemModel->appendRow(item);
        }
        head=head->next;
    }
    ui->listView->setModel(ItemModel);
}
void showClass::on_pushButton_clicked()
{
    if(ui->pushButton->text().trimmed()=="确定"){
    int y=ui->lineEdit->text().toInt();
    int m=ui->lineEdit_2->text().toInt();
    int d=ui->lineEdit_3->text().toInt();
    term=ui->comboBox->currentIndex()+1;
    QDate start(y,m,d);
    weekDay=calcWeek(start);
    weekNum=QDate::currentDate().dayOfWeek();
    ui->label->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->lineEdit->hide();
    ui->lineEdit_2->hide();
    ui->lineEdit_3->hide();
    ui->comboBox->hide();
    ui->label_4->setText(QString("第%1周周%2").arg(weekDay).arg(weekNum));
    findTodayClass();
    ui->pushButton->setText("关闭");
    }
    else{
        this->close();
    }
}
