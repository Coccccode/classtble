#include "classinfodialog.h"
#include "ui_classinfodialog.h"
#include <QCheckBox>
classinfoDialog::classinfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::classinfoDialog)
{
    ui->setupUi(this);
    for(int i=0;i<17;i++){
        a.append(0);
    }
}

classinfoDialog::~classinfoDialog()
{
    delete ui;
}
void classinfoDialog::on_checkBox_16_stateChanged(int arg1)
{

    if(arg1==Qt::Checked){
        ui->checkBox->setCheckState(Qt::Checked);
        ui->checkBox_2->setCheckState(Qt::Checked);
        ui->checkBox_3->setCheckState(Qt::Checked);
        ui->checkBox_4->setCheckState(Qt::Checked);
        ui->checkBox_5->setCheckState(Qt::Checked);
        ui->checkBox_6->setCheckState(Qt::Checked);
        ui->checkBox_7->setCheckState(Qt::Checked);
        ui->checkBox_8->setCheckState(Qt::Checked);
    }
    else{
        ui->checkBox->setCheckState(Qt::Unchecked);
        ui->checkBox_2->setCheckState(Qt::Unchecked);
        ui->checkBox_3->setCheckState(Qt::Unchecked);
        ui->checkBox_4->setCheckState(Qt::Unchecked);
        ui->checkBox_5->setCheckState(Qt::Unchecked);
        ui->checkBox_6->setCheckState(Qt::Unchecked);
        ui->checkBox_7->setCheckState(Qt::Unchecked);
        ui->checkBox_8->setCheckState(Qt::Unchecked);
    }
}

void classinfoDialog::on_checkBox_17_stateChanged(int arg1)
{

    if(arg1==Qt::Checked){
        ui->checkBox_9->setCheckState(Qt::Checked);
        ui->checkBox_10->setCheckState(Qt::Checked);
        ui->checkBox_11->setCheckState(Qt::Checked);
        ui->checkBox_12->setCheckState(Qt::Checked);
        ui->checkBox_13->setCheckState(Qt::Checked);
        ui->checkBox_14->setCheckState(Qt::Checked);
        ui->checkBox_15->setCheckState(Qt::Checked);
    }
    else{
        ui->checkBox_9->setCheckState(Qt::Unchecked);
        ui->checkBox_10->setCheckState(Qt::Unchecked);
        ui->checkBox_11->setCheckState(Qt::Unchecked);
        ui->checkBox_12->setCheckState(Qt::Unchecked);
        ui->checkBox_13->setCheckState(Qt::Unchecked);
        ui->checkBox_14->setCheckState(Qt::Unchecked);
        ui->checkBox_15->setCheckState(Qt::Unchecked);
    }
}

void classinfoDialog::on_checkBox_6_stateChanged(int arg1)
{
       if(arg1==Qt::Checked){
           a[0]=1;
       }
       else{
           a[0]=0;
       }
}

void classinfoDialog::on_checkBox_4_stateChanged(int arg1)
{
    if(arg1==Qt::Checked){
        a[1]=1;
    }
    else{
        a[1]=0;
    }
}

void classinfoDialog::on_checkBox_3_stateChanged(int arg1)
{
    if(arg1==Qt::Checked){
        a[2]=1;
    }
    else{
        a[2]=0;
    }
}

void classinfoDialog::on_checkBox_5_stateChanged(int arg1)
{
    if(arg1==Qt::Checked){
        a[3]=1;
    }
    else{
        a[3]=0;
    }
}

void classinfoDialog::on_checkBox_stateChanged(int arg1)
{
    if(arg1==Qt::Checked){
        a[4]=1;
    }
    else{
        a[4]=0;
    }
}

void classinfoDialog::on_checkBox_7_stateChanged(int arg1)
{
    if(arg1==Qt::Checked){
        a[5]=1;
    }
    else{
        a[5]=0;
    }
}

void classinfoDialog::on_checkBox_2_stateChanged(int arg1)
{
    if(arg1==Qt::Checked){
        a[6]=1;
    }
    else{
        a[6]=0;
    }
}

void classinfoDialog::on_checkBox_8_stateChanged(int arg1)
{
    if(arg1==Qt::Checked){
        a[7]=1;
    }
    else{
        a[7]=0;
    }
}
void classinfoDialog::on_checkBox_9_stateChanged(int arg1)
{
    if(arg1==Qt::Checked){
        a[8]=1;
    }
    else{
        a[8]=0;
    }
}

void classinfoDialog::on_checkBox_10_stateChanged(int arg1)
{
    if(arg1==Qt::Checked){
        a[9]=1;
    }
    else{
        a[9]=0;
    }
}

void classinfoDialog::on_checkBox_11_stateChanged(int arg1)
{
    if(arg1==Qt::Checked){
        a[10]=1;
    }
    else{
        a[10]=0;
    }
}

void classinfoDialog::on_checkBox_12_stateChanged(int arg1)
{
    if(arg1==Qt::Checked){
        a[11]=1;
    }
    else{
        a[11]=0;
    }
}

void classinfoDialog::on_checkBox_13_stateChanged(int arg1)
{
    if(arg1==Qt::Checked){
        a[12]=1;
    }
    else{
        a[12]=0;
    }
}

void classinfoDialog::on_checkBox_14_stateChanged(int arg1)
{
    if(arg1==Qt::Checked){
        a[13]=1;
    }
    else{
        a[13]=0;
    }
}

void classinfoDialog::on_checkBox_15_stateChanged(int arg1)
{
    if(arg1==Qt::Checked){
        a[14]=1;
    }
    else{
        a[14]=0;
    }
}

void classinfoDialog::on_buttonBox_accepted()
{
        emit sendData(a);
}


void classinfoDialog::on_comboBox_currentIndexChanged(int index)
{
    choose=index;
}
