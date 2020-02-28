#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
extern QString countnum;
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    Ui::Dialog *ui;
private slots:
    void on_buttonBox_accepted();
private:
public:
signals:
    void signa();
};

#endif // DIALOG_H
