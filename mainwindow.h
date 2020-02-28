#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "head.h"
#include "form.h"
#include "showclass.h"
#include "classinfodialog.h"
#include "certificationdialog.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void openExcel(QString fileName); //打开Excel
    Dialog *count=new Dialog();//统计界面
    QVariant readAll(QAxObject *sheet);//读取Excel
    void castVariant2ListListVariant(const QVariant &var);//将其写入TableWidget
    List *l=new List();//链表类
    Form *insertWidget=new Form();//自定义界面
    DataType insert;//获取自定义界面的数据
    void writeExcel(DataType data,QString path);//将自定义插入的数据存入Excel中
    QString path;//文件路径
    void searchLinklist(QString a);//查找
    void casttoTableWidget(int &row,Node *tmp);//将该节点数据放入TableWidgeT
    void castListtoTableWidget();//将整个链表数据放入TableWidget中
    QStringList headers;//保存表头
    QVariantList rowData;//读取Excel中的数据暂存
    showClass *DateWidget=new showClass();//显示当天的课程数据
    classinfoDialog *showDialog=new classinfoDialog();//显示筛选数据
    QVector<int> b;//从筛选条件界面传参致主界面的数据暂存
    void showHeaders();//显示表头
public slots:
    void cli();//接收统计的筛选条件
    void receiveData(DataType a);//接受insert数据的槽函数
    void receiveData(QVector<int>  a);//接受筛选条件
private slots:
    void on_pushButton_3_clicked();//升序排序槽函数
    void on_pushButton_5_clicked();//降序排序的槽函数

    void on_pushButton_2_clicked();//统计的槽函数

    void on_pushButton_clicked();//查找的槽函数

    void on_pushButton_4_clicked();//插入自定义的槽函数

    void on_pushButton_7_clicked();//显示的槽函数

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
