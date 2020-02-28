#include "certificationdialog.h"
#include "ui_certificationdialog.h"

certificationDialog::certificationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::certificationDialog)
{
    ui->setupUi(this);
}

certificationDialog::~certificationDialog()
{
    delete ui;
}
