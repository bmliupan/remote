#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

    //行编辑输入
    void on_lineEdit_001_editingFinished();
    void on_lineEdit_002_editingFinished();
    void on_lineEdit_003_editingFinished();
    void on_lineEdit_004_editingFinished();
    void on_lineEdit_005_editingFinished();
    void on_lineEdit_006_editingFinished();
    void on_lineEdit_007_editingFinished();
    void on_lineEdit_008_editingFinished();
    void on_lineEdit_009_editingFinished();
    void on_lineEdit_010_editingFinished();
    void on_lineEdit_011_editingFinished();
    void on_lineEdit_012_editingFinished();
    void on_lineEdit_013_editingFinished();
    void on_lineEdit_014_editingFinished();
    void on_lineEdit_015_editingFinished();
    void on_lineEdit_016_editingFinished();
    void on_lineEdit_017_editingFinished();
    void on_lineEdit_018_editingFinished();
    void on_lineEdit_019_editingFinished();
    void on_lineEdit_020_editingFinished();
    void on_lineEdit_021_editingFinished();
    void on_lineEdit_022_editingFinished();
    void on_lineEdit_023_editingFinished();
    void on_lineEdit_024_editingFinished();
    void on_lineEdit_025_editingFinished();
    void on_lineEdit_026_editingFinished();
    void on_lineEdit_027_editingFinished();
    void on_lineEdit_028_editingFinished();
    void on_lineEdit_029_editingFinished();
    void on_lineEdit_030_editingFinished();
    void on_lineEdit_031_editingFinished();
    void on_lineEdit_032_editingFinished();
    void on_lineEdit_033_editingFinished();
    void on_lineEdit_034_editingFinished();
    void on_lineEdit_035_editingFinished();
    void on_lineEdit_036_editingFinished();
    void on_lineEdit_037_editingFinished();
    void on_lineEdit_038_editingFinished();
    void on_lineEdit_039_editingFinished();
    void on_lineEdit_040_editingFinished();
    void on_lineEdit_041_editingFinished();
    void on_lineEdit_042_editingFinished();
    void on_lineEdit_043_editingFinished();
    void on_lineEdit_044_editingFinished();
    void on_lineEdit_045_editingFinished();
    void on_lineEdit_046_editingFinished();
    void on_lineEdit_047_editingFinished();
    void on_lineEdit_048_editingFinished();
    void on_lineEdit_049_editingFinished();
    void on_lineEdit_050_editingFinished();
    void on_lineEdit_051_editingFinished();
    void on_lineEdit_052_editingFinished();
    void on_lineEdit_053_editingFinished();
    void on_lineEdit_054_editingFinished();
    void on_lineEdit_055_editingFinished();
    void on_lineEdit_056_editingFinished();
    void on_lineEdit_057_editingFinished();
    void on_lineEdit_058_editingFinished();
    void on_lineEdit_059_editingFinished();
    void on_lineEdit_060_editingFinished();
    void on_lineEdit_061_editingFinished();
    void on_lineEdit_062_editingFinished();
    void on_lineEdit_063_editingFinished();
    void on_lineEdit_064_editingFinished();
    void on_lineEdit_065_editingFinished();
    void on_lineEdit_066_editingFinished();

    void on_lineEdit_user_STB_editingFinished();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
