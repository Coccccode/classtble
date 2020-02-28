#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    path=QString("c:\\Users\\admin\\Desktop\\2.xlsx").trimmed();
    openExcel(path);
    int i=15;
    while(i--){
        b.append(0);
    }
    DateWidget->show();
    DateWidget->getHead(l->getPhead());
}
void MainWindow::castListtoTableWidget(){
    ui->tableWidget->clear();
    foreach(auto item,rowData)
    {
        QString value = item.toString();
        headers.append(value);
    }
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    Node *tmp=new Node();
    tmp=l->getPhead()->next;
    int row=0;
    while(tmp){
        casttoTableWidget(row,tmp);
        tmp=tmp->next;
        row++;
    }
}
void MainWindow::searchLinklist(QString a){
    Node *p=new Node();
    p=l->getPhead()->next;
    int row=0;
    ui->tableWidget->clear();
    while(p){//遍历查找
        if(QString::number(p->data.term)==a||p->data.week==a||
                p->data.place==a||p->data.weekInfo==a||
                p->data.subjectName==a||QString::number(p->data.classTime)==a
                ||p->data.teacher==a)
        casttoTableWidget(row,p);
        p=p->next;
    }
}
void MainWindow::casttoTableWidget(int &row,Node *tmp){
    QString value1 = tmp->data.subjectName;
    QString value2 = QString::number(tmp->data.classTime);
    QString value3 = tmp->data.place;
    QString value4 = tmp->data.teacher;
    QString value5 = tmp->data.week;
    QString value6 = QString::number(tmp->data.term);
    QString value7 = tmp->data.weekInfo;
    QTableWidgetItem *item1 = new QTableWidgetItem(value1);
    QTableWidgetItem *item2 = new QTableWidgetItem(value2);
    QTableWidgetItem *item3 = new QTableWidgetItem(value3);
    QTableWidgetItem *item4 = new QTableWidgetItem(value4);
    QTableWidgetItem *item5 = new QTableWidgetItem(value5);
    QTableWidgetItem *item6= new QTableWidgetItem(value6);
    QTableWidgetItem *item7= new QTableWidgetItem(value7);
    ui->tableWidget->setItem(row, 0, item1);
    ui->tableWidget->setItem(row, 1, item2);
    ui->tableWidget->setItem(row, 2, item3);
    ui->tableWidget->setItem(row, 3, item4);
    ui->tableWidget->setItem(row, 4, item5);
    ui->tableWidget->setItem(row, 5, item6);
    ui->tableWidget->setItem(row, 6, item7);
}
void MainWindow::openExcel(QString fileName)
{
    QAxObject excel("Excel.Application");
    excel.setProperty("Visible", false);
    QAxObject *work_books = excel.querySubObject("WorkBooks");
    work_books->dynamicCall("Open(const QString&)", fileName);

    QAxObject *work_book = excel.querySubObject("ActiveWorkBook");
    QAxObject *work_sheets = work_book->querySubObject("WorkSheets");  //Sheets也可换用WorkSheets

    int sheet_count = work_sheets->property("Count").toInt();  //获取工作表数目
    if (sheet_count > 0)
    {
        QAxObject *work_sheet = work_book->querySubObject("WorkSheets(int)", 1);
        QVariant var = readAll(work_sheet);
        castVariant2ListListVariant(var);
        ui->label_2->setText("加载成功");
    }
    work_book->dynamicCall("Close()");
    excel.dynamicCall("QUIT()");

}
QVariant MainWindow::readAll(QAxObject *sheet)
{
    QVariant var;
    if (sheet != NULL && !sheet->isNull())
    {
        QAxObject *usedRange = sheet->querySubObject("UsedRange");
        if (NULL == usedRange || usedRange->isNull())
        {
            return var;
        }
        var = usedRange->dynamicCall("Value");
        delete usedRange;
    }
    return var;
}

void MainWindow::castVariant2ListListVariant(const QVariant &var)
{
    QVariantList varRows = var.toList();
    if (varRows.isEmpty())
    {
        return;
    }
    const int rowCount = varRows.size();
    l->insertQvariant(var);
    //l->travese();
    for (int i = 0; i < rowCount; ++i)
    {
        rowData = varRows[i].toList();

        if (i == 0)
        {
            foreach(auto item,rowData)
            {
                QString value = item.toString();
                headers.append(value);
            }
            ui->tableWidget->setColumnCount(headers.size()); //设置列数
            ui->tableWidget->setHorizontalHeaderLabels(headers);
        }
        else
        {
            int row = ui->tableWidget->rowCount();
            ui->tableWidget->setRowCount(row + 1);
            for (int j = 0; j < rowData.size(); j++)
            {
                QString value = rowData[j].toString();
                QTableWidgetItem *item = new QTableWidgetItem(value);
                ui->tableWidget->setItem(row, j, item);
            }
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_3_clicked()
{
   l->QuickSort(l->getPhead(),nullptr);
   l->travese();
   castListtoTableWidget();
}

void MainWindow::on_pushButton_5_clicked()
{
    l->QuickSortRelease(l->getPhead(),nullptr);
    castListtoTableWidget();
}
void MainWindow::cli(){
    Node *tmp=l->getPhead()->next;
    ui->tableWidget->clear();
    int row = 0;
    while(tmp){//将筛选数据放入TableWidget
        QString value1 = tmp->data.subjectName;
        QString value2 = QString::number(tmp->data.classTime);
        QString value3 = tmp->data.place;
        QString value4 = tmp->data.teacher;
        QString value5 = tmp->data.week;
        QString value6 = QString::number(tmp->data.term);
        QString value7 = tmp->data.weekInfo;
        if(value7!=countnum){
            tmp=tmp->next;
            continue;
        }
        QTableWidgetItem *item1 = new QTableWidgetItem(value1);
        QTableWidgetItem *item2 = new QTableWidgetItem(value2);
        QTableWidgetItem *item3 = new QTableWidgetItem(value3);
        QTableWidgetItem *item4 = new QTableWidgetItem(value4);
        QTableWidgetItem *item5 = new QTableWidgetItem(value5);
        QTableWidgetItem *item6= new QTableWidgetItem(value6);
        QTableWidgetItem *item7= new QTableWidgetItem(value7);
        ui->tableWidget->setItem(row, 0, item1);
        ui->tableWidget->setItem(row, 1, item2);
        ui->tableWidget->setItem(row, 2, item3);
        ui->tableWidget->setItem(row, 3, item4);
        ui->tableWidget->setItem(row, 4, item5);
        ui->tableWidget->setItem(row, 5, item6);
        ui->tableWidget->setItem(row, 6, item7);
        tmp=tmp->next;
        row++;
    }
}
void MainWindow::on_pushButton_2_clicked()
{
    count->show();
     connect(count,SIGNAL(signa()),this,SLOT(cli()));
}

void MainWindow::on_pushButton_clicked()
{
    showHeaders();
    searchLinklist(ui->lineEdit->text());
}
void MainWindow::receiveData(DataType a){
    insert=a;
    l->insert(a);
    writeExcel(a,path);
    QMessageBox::about(this,"提示","导入成功");
    castListtoTableWidget();
    ui->tableWidget->update();
}
void MainWindow::showHeaders(){
    foreach(auto item,rowData)
    {
        QString value = item.toString();
        headers.append(value);
    }
    ui->tableWidget->setHorizontalHeaderLabels(headers);
}
void MainWindow::receiveData(QVector<int> a){
   for(int i=0;i<=14;i++){
       b[i]=a[i];
   }
   Node *tmp=new Node();
   if(showDialog->choose==0){
       l->QuickSort(l->getPhead(),nullptr);
   }
   else if(showDialog->choose==1){
       l->QuickSortRelease(l->getPhead(),nullptr);
   }
   tmp=l->getPhead()->next;
   int row=0,flag=0;
   qDebug()<<22;
   ui->tableWidget->clear();
   showHeaders();
   while(tmp){
   for(int i=0;i<=7;i++){
       for(int j=8;j<=14;j++){
           if(b[i]&&b[j]&&i==tmp->data.term&&tmp->data.weekInfo==DateWidget->transform(j-7)){
                casttoTableWidget(row,tmp);
                row++;
                flag=1;
                break;
           }
       }
       if(flag==1){
           flag=0;
           break;
       }
   }
   tmp=tmp->next;
   }
}
void MainWindow::on_pushButton_4_clicked()
{
    insertWidget->show();
    connect(insertWidget,SIGNAL(sendData(DataType)),this,SLOT(receiveData(DataType)));
}
void MainWindow::writeExcel(DataType data,QString path){
    QAxObject *excel = NULL;    //本例中，excel设定为Excel文件的操作对象
    QAxObject *workbooks = NULL;
    QAxObject *workbook = NULL;  //Excel操作对象
    excel = new QAxObject("Excel.Application");
    excel->dynamicCall("SetVisible(bool)", false); //true 表示操作文件时可见，false表示为不可见
    workbooks = excel->querySubObject("WorkBooks");
    //————————————————按文件路径打开文件————————————————————
    workbook = workbooks->querySubObject("Open(QString&)",path);
    // 获取打开的excel文件中所有的工作sheet
    QAxObject * worksheets = workbook->querySubObject("WorkSheets");
    //—————————————————Excel文件中表的个数:——————————————————
    int iWorkSheet = worksheets->property("Count").toInt();
    // ————————————————获取第n个工作表 querySubObject("Item(int)", n);——————————
    QAxObject * worksheet = worksheets->querySubObject("Item(int)", 1);//本例获取第一个，最后参数填1
    //—————————获取该sheet的数据范围（可以理解为有数据的矩形区域）————
    QAxObject * usedrange = worksheet->querySubObject("UsedRange");
    //———————————————————获取行数———————————————
    QAxObject * rows = usedrange->querySubObject("Rows");
    int iRows = rows->property("Count").toInt();
    //————————————获取列数—————————
    QAxObject * columns = usedrange->querySubObject("Columns");
    int iColumns = columns->property("Count").toInt();
    //—————————————写入数据—————————————
    //获取F6的位置
    int tmpRow=iRows+1;//添加的行数是总行数+1
    int tmpColumns=iColumns;
    QString col;
    QString row;
    row=QString::number(tmpRow);
    QString tmpData[7];
    tmpData[0]=data.subjectName;
    tmpData[1]=QString::number(data.classTime);
    tmpData[2]=data.place;
    tmpData[3]=data.teacher;
    tmpData[4]=data.week;
    tmpData[5]=QString::number(data.term);
    tmpData[6]=data.weekInfo;
    qDebug()<<tmpColumns<<" "<<tmpRow;
    while(tmpColumns--){
        col='A'+iColumns-tmpColumns-1;
        QString tmp=col+row;
        QAxObject *range2 = worksheet->querySubObject("Range(QString)", tmp);
        //写入数据, 下一行，下一列
        range2->setProperty("Value", tmpData[iColumns-tmpColumns-1]);

    }
    workbook->dynamicCall("Save()");
    workbook->dynamicCall("Close()",false);
    excel->dynamicCall("Quit()");
}

void MainWindow::on_pushButton_7_clicked()
{
    showDialog->show();
    connect(showDialog,SIGNAL(sendData(QVector<int>)),this,SLOT(receiveData(QVector<int>)));
}

void MainWindow::on_pushButton_6_clicked()
{
    certificationDialog *dailog=new certificationDialog();
    dailog->show();
}
