#ifndef CLASSINFODIALOG_H
#define CLASSINFODIALOG_H

#include <QDialog>

namespace Ui {
class classinfoDialog;
}

class classinfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit classinfoDialog(QWidget *parent = nullptr);
    int choose=0;
    ~classinfoDialog();
    QVector<int> a;//存储筛选信息
signals:
    void sendData(QVector<int>);
private slots:
    //多选框
    void on_checkBox_16_stateChanged(int arg1);

    void on_checkBox_17_stateChanged(int arg1);

    void on_checkBox_6_stateChanged(int arg1);

    void on_checkBox_4_stateChanged(int arg1);

    void on_checkBox_3_stateChanged(int arg1);

    void on_checkBox_5_stateChanged(int arg1);

    void on_checkBox_stateChanged(int arg1);

    void on_checkBox_7_stateChanged(int arg1);

    void on_checkBox_2_stateChanged(int arg1);

    void on_checkBox_8_stateChanged(int arg1);

    void on_checkBox_9_stateChanged(int arg1);

    void on_checkBox_10_stateChanged(int arg1);

    void on_checkBox_11_stateChanged(int arg1);

    void on_checkBox_12_stateChanged(int arg1);

    void on_checkBox_13_stateChanged(int arg1);

    void on_checkBox_14_stateChanged(int arg1);

    void on_checkBox_15_stateChanged(int arg1);

    void on_buttonBox_accepted();

    void on_checkBox_18_stateChanged(int arg1);

    void on_radioButton_2_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::classinfoDialog *ui;
};

#endif // CLASSINFODIALOG_H
