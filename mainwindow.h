#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"

#define TOTALKEYNUM     78

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QLineEdit *lEdit[78];
    QLabel *keyLabel[78];
    QLabel *pinLabel[13];
public slots:
    //按键响应
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

    //行编辑输入
    void on_lineEdit_user_STB_editingFinished();
    void on_lineEdit_user_TV_editingFinished();
    void input_KeyNUM(QString text);
    void menu_get_excel();
protected:
    void paintEvent(QPaintEvent *);
private slots:
    void on_comboBox_LED_currentTextChanged();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
