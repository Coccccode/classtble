#ifndef CERTIFICATIONDIALOG_H
#define CERTIFICATIONDIALOG_H

#include <QDialog>

namespace Ui {
class certificationDialog;
}

class certificationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit certificationDialog(QWidget *parent = nullptr);
    ~certificationDialog();

private:
    Ui::certificationDialog *ui;
};

#endif // CERTIFICATIONDIALOG_H
