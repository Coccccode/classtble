#ifndef SHOWCLASS_H
#define SHOWCLASS_H

#include <QWidget>
#include "head.h"
#include <QDate>
namespace Ui {
class showClass;
}

class showClass : public QWidget
{
    Q_OBJECT

public:
    explicit showClass(QWidget *parent = nullptr);
    ~showClass();
    int weekNum;//周几
    int weekDay;//第几周
    int term;//学期数
    int calcWeek(QDate startTime);//计算是开学第几周
    Node *head;
    void getHead(Node *pHead);//获得双向链表
    QString transform(int week);//将数字转换成字符串
    void findTodayClass();//找到当天的课程显示
private slots:
    void on_pushButton_clicked();

private:
    Ui::showClass *ui;
};

#endif // SHOWCLASS_H
