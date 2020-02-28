#ifndef LIST_H
#define LIST_H
#include <QString>
#include <QVariant>
#include <QDebug>
struct DataType{
    int start;
    int end;
    QString subjectName;//学科名
    int classTime;
    QString place;
    QString teacher;
    QString week;
    int term;
    QString weekInfo;
};

struct Node{
    DataType data;
    Node *pre;
    Node *next;
};
class List      //构造一个双向链表
{
private:
    Node * pHead,*pTail;
    int length;
    Node *p;
public:
    List(){
           pHead = new Node();
           pHead->pre = nullptr;
           pHead->next = pHead;
           pTail=pHead;
    }
    void insert(DataType data)//其数据为data
    {
        Node *node =new Node();//创建数据为data的新节点
        node->data=data;
        pTail->next=node;
        node->next=nullptr;
        int flag=0;
        if(node->data.week.left(2).toInt()>=1&&node->data.week.toInt()<=9){
            node->data.start=node->data.start*10+node->data.week.toInt();
            flag=1;
        }
        if(flag)
            node->data.end=(node->data.week.remove("周")
            .remove("-")).toInt()%100;
        else {
            node->data.end=(node->data.week.remove("周").remove(node->data.week.left(1)).remove("-")).toInt();
        }
        pTail=node;
    }
    void insertQvariant(const QVariant &var){//将QVariant数据插入双向链表
        QVariantList varRows = var.toList();
        if (varRows.isEmpty())
        {
            return;
        }
        int rowCount = varRows.size();
        QVariantList rowData;
        p=new Node();
        p=pHead;
        for (int i = 0; i < rowCount; ++i)
        {
            rowData = varRows[i].toList();
            if(i!=0)
            {
                int flag=0;
                Node *q=new Node();
                q->data.subjectName=rowData[0].toString();
                q->data.classTime=rowData[1].toInt();
                q->data.place=rowData[2].toString();
                q->data.teacher=rowData[3].toString();
                q->data.week=rowData[4].toString();
                q->data.term=rowData[5].toInt();
                q->data.weekInfo=rowData[6].toString();
                QString temp=q->data.week;
                q->data.start=q->data.week.left(1).toInt();
                if(q->data.week.left(2).toInt()>=1&&q->data.week.toInt()<=9){
                    q->data.start=q->data.start*10+q->data.week.toInt();
                    flag=1;
                }
                if(flag)
                    q->data.end=(q->data.week.remove("周")
                    .remove("-")).toInt()%100;
                else {
                    q->data.end=(q->data.week.remove("周").remove(q->data.week.left(1)).remove("-")).toInt();
                }
                q->data.week=temp;
                q->data.subjectName=rowData[0].toString();
                q->next=nullptr;
                q->pre=pTail;
                pTail->next=q;
                pTail=q;
            }
        }
    }
    void travese(){//遍历用于验证
        Node *temp=new Node();
        temp=pHead->next;
        qDebug()<<endl;
        while(temp){
            qDebug()<<temp->data.classTime;
            temp=temp->next;
        }
    }
    Node *getPhead(){//返回头节点
        return pHead;
    }
    Node *getPTail(){//返回尾节点
        return pTail;
    }
    int lengthlist(){//计算链表长度
        Node *p;
        p = pHead;
        p = p->next;
        int coun = 0;
        while(p!=pHead)
        {
            coun++;
            p = p->next;
        }
        length=coun;
        return coun;
    }
    void  QuickSort(Node* head, Node* end)//链表快排升序
    {
        if (head == end||head->next == end)//为空或只有一个数则返回
            return;
        Node*  key = new Node();//开始节点
        Node*  prev = new Node();//中间节点
        Node*  cur = new Node();//结束节点
        key=head;
        prev=head;
        cur=head->next;
        while (cur!=end)
        {
            if (cur->data.classTime < key->data.classTime)
            {
                prev = prev->next;
                swapdata(prev->data, cur->data);
            }
            cur = cur->next;
        }
        swapdata(key->data, prev->data);
        QuickSort(key, prev);
        QuickSort(prev->next, end);
    }
    void  QuickSortRelease(Node* head, Node* end)//链表快排降序
    {
        if (head == end||head->next == end)//为空或只有一个数则返回
            return;
        Node*  key = new Node();
        Node*  prev = new Node();
        Node*  cur = new Node();
        key=head;
        prev=head;
        cur=head->next;
        while (cur!=end)
        {
            if (cur->data.classTime > key->data.classTime)
            {
                prev = prev->next;
                swapdata(prev->data, cur->data);
            }
            cur = cur->next;
        }
        swapdata(key->data, prev->data);
        QuickSortRelease(key, prev);
        QuickSortRelease(prev->next, end);
    }
    void swapdata(DataType &a,DataType &b){//交换数据
        DataType tmp;
        tmp=a;
        a=b;
        b=tmp;
    }
    ~List(){
        Node * q;
        Node * p=pHead->next;
        while(p!=NULL)
        {
            q=p;
            p=p->next;
            delete q;
        }
        p=NULL;
        q=NULL;
    }
};
#endif // LIST_H
