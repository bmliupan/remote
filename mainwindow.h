#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QLineEdit * lEdit[78];
    QLabel *keyLabel[78];
    QLabel *pinLabel[13];
public slots:
    //按键响应
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

    //行编辑输入
    void on_lineEdit_user_STB_editingFinished();
    void on_lineEdit_user_TV_editingFinished();
    void input_KeyNUM(QString text);
protected:
    void paintEvent(QPaintEvent *);
private slots:
    void on_comboBox_LED_currentTextChanged();

private:
    Ui::MainWindow *ui;
};

typedef  enum{
    LINEEDIT001,
    LINEEDIT002,
    LINEEDIT003,
    LINEEDIT004,
    LINEEDIT005,
    LINEEDIT006,
    LINEEDIT007,
    LINEEDIT008,
    LINEEDIT009,
    LINEEDIT010,
    LINEEDIT011,
    LINEEDIT012,
    LINEEDIT013,
    LINEEDIT014,
    LINEEDIT015,
    LINEEDIT016,
    LINEEDIT017,
    LINEEDIT018,
    LINEEDIT019,
    LINEEDIT020,
    LINEEDIT021,
    LINEEDIT022,
    LINEEDIT023,
    LINEEDIT024,
    LINEEDIT025,
    LINEEDIT026,
    LINEEDIT027,
    LINEEDIT028,
    LINEEDIT029,
    LINEEDIT030,
    LINEEDIT031,
    LINEEDIT032,
    LINEEDIT033,
    LINEEDIT034,
    LINEEDIT035,
    LINEEDIT036,
    LINEEDIT037,
    LINEEDIT038,
    LINEEDIT039,
    LINEEDIT040,
    LINEEDIT041,
    LINEEDIT042,
    LINEEDIT043,
    LINEEDIT044,
    LINEEDIT045,
    LINEEDIT046,
    LINEEDIT047,
    LINEEDIT048,
    LINEEDIT049,
    LINEEDIT050,
    LINEEDIT051,
    LINEEDIT052,
    LINEEDIT053,
    LINEEDIT054,
    LINEEDIT055,
    LINEEDIT056,
    LINEEDIT057,
    LINEEDIT058,
    LINEEDIT059,
    LINEEDIT060,
    LINEEDIT061,
    LINEEDIT062,
    LINEEDIT063,
    LINEEDIT064,
    LINEEDIT065,
    LINEEDIT066,
    LINEEDIT067,
    LINEEDIT068,
    LINEEDIT069,
    LINEEDIT070,
    LINEEDIT071,
    LINEEDIT072,
    LINEEDIT073,
    LINEEDIT074,
    LINEEDIT075,
    LINEEDIT076,
    LINEEDIT077,
    LINEEDIT078
}LINEEDIT;

#endif // MAINWINDOW_H
