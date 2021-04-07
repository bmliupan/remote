#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "function.h"
#include "data.h"
#include "ltFileParameter.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QDataStream>
#include <QPainter>
#include <qdatetime.h>
#include <QSignalMapper>
#include <QTextStream>
#include <windows.h>
#include "libxl.h"

int hightC = 0;
int widthC = 0;

using namespace libxl;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_A->setStyleSheet("color:red;");
    ui->label_B->setStyleSheet("color:red;");
    ui->label_C->setStyleSheet("color:red;");
    setWindowIcon(QIcon(":/icon/mcu.ico"));
    lEdit[0] = qobject_cast<QLineEdit *>(ui->lineEdit_001);
    lEdit[1] = qobject_cast<QLineEdit *>(ui->lineEdit_002);
    lEdit[2] = qobject_cast<QLineEdit *>(ui->lineEdit_003);
    lEdit[3] = qobject_cast<QLineEdit *>(ui->lineEdit_004);
    lEdit[4] = qobject_cast<QLineEdit *>(ui->lineEdit_005);
    lEdit[5] = qobject_cast<QLineEdit *>(ui->lineEdit_006);
    lEdit[6] = qobject_cast<QLineEdit *>(ui->lineEdit_007);
    lEdit[7] = qobject_cast<QLineEdit *>(ui->lineEdit_008);
    lEdit[8] = qobject_cast<QLineEdit *>(ui->lineEdit_009);
    lEdit[9] = qobject_cast<QLineEdit *>(ui->lineEdit_010);
    lEdit[10] = qobject_cast<QLineEdit *>(ui->lineEdit_011);
    lEdit[11] = qobject_cast<QLineEdit *>(ui->lineEdit_012);
    lEdit[12] = qobject_cast<QLineEdit *>(ui->lineEdit_013);
    lEdit[13] = qobject_cast<QLineEdit *>(ui->lineEdit_014);
    lEdit[14] = qobject_cast<QLineEdit *>(ui->lineEdit_015);
    lEdit[15] = qobject_cast<QLineEdit *>(ui->lineEdit_016);
    lEdit[16] = qobject_cast<QLineEdit *>(ui->lineEdit_017);
    lEdit[17] = qobject_cast<QLineEdit *>(ui->lineEdit_018);
    lEdit[18] = qobject_cast<QLineEdit *>(ui->lineEdit_019);
    lEdit[19] = qobject_cast<QLineEdit *>(ui->lineEdit_020);
    lEdit[20] = qobject_cast<QLineEdit *>(ui->lineEdit_021);
    lEdit[21] = qobject_cast<QLineEdit *>(ui->lineEdit_022);
    lEdit[22] = qobject_cast<QLineEdit *>(ui->lineEdit_023);
    lEdit[23] = qobject_cast<QLineEdit *>(ui->lineEdit_024);
    lEdit[24] = qobject_cast<QLineEdit *>(ui->lineEdit_025);
    lEdit[25] = qobject_cast<QLineEdit *>(ui->lineEdit_026);
    lEdit[26] = qobject_cast<QLineEdit *>(ui->lineEdit_027);
    lEdit[27] = qobject_cast<QLineEdit *>(ui->lineEdit_028);
    lEdit[28] = qobject_cast<QLineEdit *>(ui->lineEdit_029);
    lEdit[29] = qobject_cast<QLineEdit *>(ui->lineEdit_030);
    lEdit[30] = qobject_cast<QLineEdit *>(ui->lineEdit_031);
    lEdit[31] = qobject_cast<QLineEdit *>(ui->lineEdit_032);
    lEdit[32] = qobject_cast<QLineEdit *>(ui->lineEdit_033);
    lEdit[33] = qobject_cast<QLineEdit *>(ui->lineEdit_034);
    lEdit[34] = qobject_cast<QLineEdit *>(ui->lineEdit_035);
    lEdit[35] = qobject_cast<QLineEdit *>(ui->lineEdit_036);
    lEdit[36] = qobject_cast<QLineEdit *>(ui->lineEdit_037);
    lEdit[37] = qobject_cast<QLineEdit *>(ui->lineEdit_038);
    lEdit[38] = qobject_cast<QLineEdit *>(ui->lineEdit_039);
    lEdit[39] = qobject_cast<QLineEdit *>(ui->lineEdit_040);
    lEdit[40] = qobject_cast<QLineEdit *>(ui->lineEdit_041);
    lEdit[41] = qobject_cast<QLineEdit *>(ui->lineEdit_042);
    lEdit[42] = qobject_cast<QLineEdit *>(ui->lineEdit_043);
    lEdit[43] = qobject_cast<QLineEdit *>(ui->lineEdit_044);
    lEdit[44] = qobject_cast<QLineEdit *>(ui->lineEdit_045);
    lEdit[45] = qobject_cast<QLineEdit *>(ui->lineEdit_046);
    lEdit[46] = qobject_cast<QLineEdit *>(ui->lineEdit_047);
    lEdit[47] = qobject_cast<QLineEdit *>(ui->lineEdit_048);
    lEdit[48] = qobject_cast<QLineEdit *>(ui->lineEdit_049);
    lEdit[49] = qobject_cast<QLineEdit *>(ui->lineEdit_050);
    lEdit[50] = qobject_cast<QLineEdit *>(ui->lineEdit_051);
    lEdit[51] = qobject_cast<QLineEdit *>(ui->lineEdit_052);
    lEdit[52] = qobject_cast<QLineEdit *>(ui->lineEdit_053);
    lEdit[53] = qobject_cast<QLineEdit *>(ui->lineEdit_054);
    lEdit[54] = qobject_cast<QLineEdit *>(ui->lineEdit_055);
    lEdit[55] = qobject_cast<QLineEdit *>(ui->lineEdit_056);
    lEdit[56] = qobject_cast<QLineEdit *>(ui->lineEdit_057);
    lEdit[57] = qobject_cast<QLineEdit *>(ui->lineEdit_058);
    lEdit[58] = qobject_cast<QLineEdit *>(ui->lineEdit_059);
    lEdit[59] = qobject_cast<QLineEdit *>(ui->lineEdit_060);
    lEdit[60] = qobject_cast<QLineEdit *>(ui->lineEdit_061);
    lEdit[61] = qobject_cast<QLineEdit *>(ui->lineEdit_062);
    lEdit[62] = qobject_cast<QLineEdit *>(ui->lineEdit_063);
    lEdit[63] = qobject_cast<QLineEdit *>(ui->lineEdit_064);
    lEdit[64] = qobject_cast<QLineEdit *>(ui->lineEdit_065);
    lEdit[65] = qobject_cast<QLineEdit *>(ui->lineEdit_066);
    lEdit[66] = qobject_cast<QLineEdit *>(ui->lineEdit_067);
    lEdit[67] = qobject_cast<QLineEdit *>(ui->lineEdit_068);
    lEdit[68] = qobject_cast<QLineEdit *>(ui->lineEdit_069);
    lEdit[69] = qobject_cast<QLineEdit *>(ui->lineEdit_070);
    lEdit[70] = qobject_cast<QLineEdit *>(ui->lineEdit_071);
    lEdit[71] = qobject_cast<QLineEdit *>(ui->lineEdit_072);
    lEdit[72] = qobject_cast<QLineEdit *>(ui->lineEdit_073);
    lEdit[73] = qobject_cast<QLineEdit *>(ui->lineEdit_074);
    lEdit[74] = qobject_cast<QLineEdit *>(ui->lineEdit_075);
    lEdit[75] = qobject_cast<QLineEdit *>(ui->lineEdit_076);
    lEdit[76] = qobject_cast<QLineEdit *>(ui->lineEdit_077);
    lEdit[77] = qobject_cast<QLineEdit *>(ui->lineEdit_078);
    keyLabel[0] = qobject_cast<QLabel *>(ui->label_001);
    keyLabel[1] = qobject_cast<QLabel *>(ui->label_002);
    keyLabel[2] = qobject_cast<QLabel *>(ui->label_003);
    keyLabel[3] = qobject_cast<QLabel *>(ui->label_004);
    keyLabel[4] = qobject_cast<QLabel *>(ui->label_005);
    keyLabel[5] = qobject_cast<QLabel *>(ui->label_006);
    keyLabel[6] = qobject_cast<QLabel *>(ui->label_007);
    keyLabel[7] = qobject_cast<QLabel *>(ui->label_008);
    keyLabel[8] = qobject_cast<QLabel *>(ui->label_009);
    keyLabel[9] = qobject_cast<QLabel *>(ui->label_010);
    keyLabel[10] = qobject_cast<QLabel *>(ui->label_011);
    keyLabel[11] = qobject_cast<QLabel *>(ui->label_012);
    keyLabel[12] = qobject_cast<QLabel *>(ui->label_013);
    keyLabel[13] = qobject_cast<QLabel *>(ui->label_014);
    keyLabel[14] = qobject_cast<QLabel *>(ui->label_015);
    keyLabel[15] = qobject_cast<QLabel *>(ui->label_016);
    keyLabel[16] = qobject_cast<QLabel *>(ui->label_017);
    keyLabel[17] = qobject_cast<QLabel *>(ui->label_018);
    keyLabel[18] = qobject_cast<QLabel *>(ui->label_019);
    keyLabel[19] = qobject_cast<QLabel *>(ui->label_020);
    keyLabel[20] = qobject_cast<QLabel *>(ui->label_021);
    keyLabel[21] = qobject_cast<QLabel *>(ui->label_022);
    keyLabel[22] = qobject_cast<QLabel *>(ui->label_023);
    keyLabel[23] = qobject_cast<QLabel *>(ui->label_024);
    keyLabel[24] = qobject_cast<QLabel *>(ui->label_025);
    keyLabel[25] = qobject_cast<QLabel *>(ui->label_026);
    keyLabel[26] = qobject_cast<QLabel *>(ui->label_027);
    keyLabel[27] = qobject_cast<QLabel *>(ui->label_028);
    keyLabel[28] = qobject_cast<QLabel *>(ui->label_029);
    keyLabel[29] = qobject_cast<QLabel *>(ui->label_030);
    keyLabel[30] = qobject_cast<QLabel *>(ui->label_031);
    keyLabel[31] = qobject_cast<QLabel *>(ui->label_032);
    keyLabel[32] = qobject_cast<QLabel *>(ui->label_033);
    keyLabel[33] = qobject_cast<QLabel *>(ui->label_034);
    keyLabel[34] = qobject_cast<QLabel *>(ui->label_035);
    keyLabel[35] = qobject_cast<QLabel *>(ui->label_036);
    keyLabel[36] = qobject_cast<QLabel *>(ui->label_037);
    keyLabel[37] = qobject_cast<QLabel *>(ui->label_038);
    keyLabel[38] = qobject_cast<QLabel *>(ui->label_039);
    keyLabel[39] = qobject_cast<QLabel *>(ui->label_040);
    keyLabel[40] = qobject_cast<QLabel *>(ui->label_041);
    keyLabel[41] = qobject_cast<QLabel *>(ui->label_042);
    keyLabel[42] = qobject_cast<QLabel *>(ui->label_043);
    keyLabel[43] = qobject_cast<QLabel *>(ui->label_044);
    keyLabel[44] = qobject_cast<QLabel *>(ui->label_045);
    keyLabel[45] = qobject_cast<QLabel *>(ui->label_046);
    keyLabel[46] = qobject_cast<QLabel *>(ui->label_047);
    keyLabel[47] = qobject_cast<QLabel *>(ui->label_048);
    keyLabel[48] = qobject_cast<QLabel *>(ui->label_049);
    keyLabel[49] = qobject_cast<QLabel *>(ui->label_050);
    keyLabel[50] = qobject_cast<QLabel *>(ui->label_051);
    keyLabel[51] = qobject_cast<QLabel *>(ui->label_052);
    keyLabel[52] = qobject_cast<QLabel *>(ui->label_053);
    keyLabel[53] = qobject_cast<QLabel *>(ui->label_054);
    keyLabel[54] = qobject_cast<QLabel *>(ui->label_055);
    keyLabel[55] = qobject_cast<QLabel *>(ui->label_056);
    keyLabel[56] = qobject_cast<QLabel *>(ui->label_057);
    keyLabel[57] = qobject_cast<QLabel *>(ui->label_058);
    keyLabel[58] = qobject_cast<QLabel *>(ui->label_059);
    keyLabel[59] = qobject_cast<QLabel *>(ui->label_060);
    keyLabel[60] = qobject_cast<QLabel *>(ui->label_061);
    keyLabel[61] = qobject_cast<QLabel *>(ui->label_062);
    keyLabel[62] = qobject_cast<QLabel *>(ui->label_063);
    keyLabel[63] = qobject_cast<QLabel *>(ui->label_064);
    keyLabel[64] = qobject_cast<QLabel *>(ui->label_065);
    keyLabel[65] = qobject_cast<QLabel *>(ui->label_066);
    keyLabel[66] = qobject_cast<QLabel *>(ui->label_067);
    keyLabel[67] = qobject_cast<QLabel *>(ui->label_068);
    keyLabel[68] = qobject_cast<QLabel *>(ui->label_069);
    keyLabel[69] = qobject_cast<QLabel *>(ui->label_070);
    keyLabel[70] = qobject_cast<QLabel *>(ui->label_071);
    keyLabel[71] = qobject_cast<QLabel *>(ui->label_072);
    keyLabel[72] = qobject_cast<QLabel *>(ui->label_073);
    keyLabel[73] = qobject_cast<QLabel *>(ui->label_074);
    keyLabel[74] = qobject_cast<QLabel *>(ui->label_075);
    keyLabel[75] = qobject_cast<QLabel *>(ui->label_076);
    keyLabel[76] = qobject_cast<QLabel *>(ui->label_077);
    keyLabel[77] = qobject_cast<QLabel *>(ui->label_078);
    pinLabel[0] = qobject_cast<QLabel *>(ui->labela);
    pinLabel[1] = qobject_cast<QLabel *>(ui->labelb);
    pinLabel[2] = qobject_cast<QLabel *>(ui->labelc);
    pinLabel[3] = qobject_cast<QLabel *>(ui->labeld);
    pinLabel[4] = qobject_cast<QLabel *>(ui->labele);
    pinLabel[5] = qobject_cast<QLabel *>(ui->labelf);
    pinLabel[6] = qobject_cast<QLabel *>(ui->labelg);
    pinLabel[7] = qobject_cast<QLabel *>(ui->labelh);
    pinLabel[8] = qobject_cast<QLabel *>(ui->labeli);
    pinLabel[9] = qobject_cast<QLabel *>(ui->labelj);
    pinLabel[10] = qobject_cast<QLabel *>(ui->labelk);
    pinLabel[11] = qobject_cast<QLabel *>(ui->labell);
    pinLabel[12] = qobject_cast<QLabel *>(ui->labelm);

    QSignalMapper *signal_mapper = new QSignalMapper(this);
    connect(signal_mapper, SIGNAL(mapped(const QString &)), this, SLOT(input_KeyNUM(QString)));
    for (int i = 0; i < 78; i ++) {
        signal_mapper->setMapping(lEdit[i], QString::number(i, 10));
        connect(lEdit[i], SIGNAL(editingFinished()), signal_mapper, SLOT(map()));
    }

    connect(ui->menu_get_excel, SIGNAL(triggered()), this, SLOT(menu_get_excel()));
    connect(ui->menu_put_excel, SIGNAL(triggered()), this, SLOT(menu_put_excel()));
    connect(ui->menu_about, SIGNAL(triggered()), this, SLOT(menu_about()));

    QString currentFilePath = QDir::currentPath() + QString("/temp.data");  // generate current path
    if (QFile::exists(currentFilePath)) {                                           // create temp.data file, if it is exisit, open it!
        QFile tempFile(currentFilePath);
        if (!tempFile.open(QIODevice::ReadOnly|QIODevice::Text)) {
            qDebug("file open failed!!!");
            return;
        }
        QTextStream readText(&tempFile);
        for (int i = 0; i < TOTALKEYNUM; i++) {
            lEdit[i]->setText(readText.readLine());
        }
        ui->comboBox_A->setCurrentText(readText.readLine());
        ui->comboBox_B->setCurrentText(readText.readLine());
        ui->comboBox_C->setCurrentText(readText.readLine());
        ui->comboBox_LED->setCurrentText(readText.readLine());
        ui->comboBox_SetKey->setCurrentText(readText.readLine());
        ui->comboBox_STB_Format->setCurrentText(readText.readLine());
        ui->comboBox_TV_Format->setCurrentText(readText.readLine());
        tempFile.close();
    }

    return;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::input_KeyNUM(QString text)
{

    int index = text.toInt();
    qDebug("index value is %d", index);
    if (lEdit[index] == nullptr) return;
    if (!edit_flag) {
        lEdit[index]->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        lEdit[index]->setStyleSheet("background-color:rgba(255,0,0,255)");
    }
    if (checkInput(lEdit[index]->text(), index) == false) {
        QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
    qDebug("current keyvalue is %x", keyValue[index]);

    return;
}

 void MainWindow::paintEvent(QPaintEvent *)
 {
     QPainter painter(this);
     QPen pen;
     if (ui->comboBox_LED->currentText() == "红灯接14脚") {
        pen.setColor(QColor(0,80,128));
     } else {
        pen.setColor(QColor(0,170,17));
     }
     pen.setWidth(4);
     painter.setPen(pen);
     int i = 0;
     int a[12][2] = {};

     a[0][0] = lEdit[0]->geometry().x();
     a[0][1] = lEdit[0]->geometry().y();
     a[1][0] = lEdit[2]->geometry().x();
     a[1][1] = lEdit[2]->geometry().y();
     a[2][0] = lEdit[5]->geometry().x();
     a[2][1] = lEdit[5]->geometry().y();
     a[3][0] = lEdit[9]->geometry().x();
     a[3][1] = lEdit[9]->geometry().y();
     a[4][0] = lEdit[14]->geometry().x();
     a[4][1] = lEdit[14]->geometry().y();
     a[5][0] = lEdit[20]->geometry().x();
     a[5][1] = lEdit[20]->geometry().y();
     a[6][0] = lEdit[27]->geometry().x();
     a[6][1] = lEdit[27]->geometry().y();
     a[7][0] = lEdit[35]->geometry().x();
     a[7][1] = lEdit[35]->geometry().y();
     a[8][0] = lEdit[44]->geometry().x();
     a[8][1] = lEdit[44]->geometry().y();
     a[9][0] = lEdit[54]->geometry().x();
     a[9][1] = lEdit[54]->geometry().y();
     a[10][0] = lEdit[65]->geometry().x();
     a[10][1] = lEdit[65]->geometry().y();
     a[11][0] = lEdit[77]->geometry().x();
     a[11][1] = lEdit[77]->geometry().y();

     int hightL = ui->label_001->size().rheight();
     hightC = ui->lineEdit_001->size().rheight();
     widthC = ui->lineEdit_001->size().rwidth();
//     qDebug("lineEdit001 x is %d, y is %d", a[0][0], a[0][1]);
//     qDebug("label001 x is %d, y is %d", ui->label_001->geometry().x(),ui->label_001->geometry().y());


     int xInterval = ui->lineEdit_002->geometry().x() - ui->lineEdit_003->geometry().x();
     for (i = 0; i < 12; i++) {
         int xStart = a[i][0] - xInterval + widthC/2;
         int yStart = a[i][1] + hightC/2 + ui->menu->size().rheight();
         int xEnd = a[0][0] + widthC + 6;
         int yEnd = yStart;
         if (i == 11) xStart = a[i][0] + 5;
         //画横线
         painter.drawLine(QPointF(xStart,yStart),QPointF(xEnd,yEnd));
         //画竖线
         xEnd = xStart;
         yEnd = a[11][1] + hightL;
         if (i != 11) painter.drawLine(QPointF(xStart,yStart),QPointF(xEnd,yEnd));
     }
     int xStart = a[0][0] + widthC/2;
     int yStart = ui->labela->geometry().y() + ui->labela->size().rheight()/2 + ui->menu->size().rheight();
     int xEnd = a[0][0] + widthC + 6;
     int yEnd = yStart;
     painter.drawLine(QPointF(xStart,yStart),QPointF(xEnd,yEnd));
     xEnd = xStart;
     yEnd = a[11][1] + hightC;
     painter.drawLine(QPointF(xStart,yStart),QPointF(xEnd,yEnd));

     return;
 }

//生成烧录文件
void MainWindow::on_pushButton_2_clicked()
{

    uint8_t normalKeyNum =0;
    uint8_t learnKeyNum =0;
    uint8_t setKeyNum = 0;
    uint8_t totalKeyNum =0;
    uint8_t setKeyValue = 0;
    uint8_t learnKeyList[10] = {77,77,77,77,77,77,77,77,77,77};

    for (int i = 0; i < TOTALKEYNUM; i++) { // before generate program file, reload data and check it!
        if (checkInput(lEdit[i]->text(), i) == false) {
            QMessageBox::information(NULL, "警告", "当前输入存在不合法字段，请检查！！！");
            return;
        }
    }
    for (int i = 0; i < TOTALKEYNUM; i++) {
        if(keyFlag[i] == normalFlag) normalKeyNum ++;
        if(keyFlag[i] == learnFlag) {
            learnKeyList[learnKeyNum++] = translist[i];
            if(learnKeyNum > 10) {
                  QMessageBox::critical(NULL, tr("错误"), tr("学习按键数超过最大支持数10个！"));
                  return;
            }
        }
        if(keyFlag[i] == setFlag) {
            setKeyNum ++;
            setKeyValue = translist[i];
        }
        if(keyFlag[i] == invalidFlag) {
            QMessageBox::critical(NULL, tr("错误"), tr("当前页面存在错误键值输入，请检查！"));
            return;
        }
    }

    if(setKeyNum != 1) {
        QMessageBox::critical(NULL, tr("错误"), tr("有且只有一个学习设置按键！"));
        return;
    }

    totalKeyNum = normalKeyNum + learnKeyNum + setKeyNum;
    QFile file(":/lt/ltFile/new.lt");

    if(!file.open(QIODevice::ReadOnly)) {
      qDebug("open source file failed!");
      return;
    }

    QByteArray fileData;
    uint16_t verifyCode = 0;
    fileData = file.readAll();
/*    verifyCode = calculate_verifycode(fileData);
    if(verifyCode != 0x6C78) {
        QMessageBox::critical(NULL, tr("资源文件损坏"), tr("源文件验证码：0x6C78\n目前文件验证码：0x%1").arg(verifyCode,4,16));
        return;
    } */
    /* 写入键码数据 */
    uint16_t index = KEY_DATA_ADDR;//读入键值首地址
    for (uint8_t j = 0; j < TOTALKEYNUM; j ++) {
        fileData[index++] = (uint8_t)((keyValue[translate[j]] >> 12) & 0x000f);
        fileData[index++] = (uint8_t)((keyValue[translate[j]] >> 8) & 0x000f);
        fileData[index++] = (uint8_t)((keyValue[translate[j]] >> 4) & 0x000f);
        fileData[index++] = (uint8_t)((keyValue[translate[j]] >> 0) & 0x000f);
    }
    /* 写入用户码数据 */
    fileData[STB_USER_CODE1_ADDR + 2] = userCodeSTB[0] & 0x0f;
    fileData[STB_USER_CODE1_ADDR + 3] = userCodeSTB[1] & 0x0f;
    fileData[STB_USER_CODE2_ADDR + 2] = userCodeSTB[2] & 0x0f;
    fileData[STB_USER_CODE2_ADDR + 3] = userCodeSTB[3] & 0x0f;
    fileData[STB_USER_CODE3_ADDR + 2] = userCodeSTB[4] & 0x0f;
    fileData[STB_USER_CODE3_ADDR + 3] = userCodeSTB[5] & 0x0f;
    fileData[STB_USER_CODE4_ADDR + 2] = userCodeSTB[6] & 0x0f;
    fileData[STB_USER_CODE4_ADDR + 3] = userCodeSTB[7] & 0x0f;

    fileData[TV_USER_CODE1_ADDR + 2] = userCodeTV[0] & 0x0f;
    fileData[TV_USER_CODE1_ADDR + 3] = userCodeTV[1] & 0x0f;
    fileData[TV_USER_CODE2_ADDR + 2] = userCodeTV[2] & 0x0f;
    fileData[TV_USER_CODE2_ADDR + 3] = userCodeTV[3] & 0x0f;
    fileData[TV_USER_CODE3_ADDR + 2] = userCodeTV[4] & 0x0f;
    fileData[TV_USER_CODE3_ADDR + 3] = userCodeTV[5] & 0x0f;
    fileData[TV_USER_CODE4_ADDR + 2] = userCodeTV[6] & 0x0f;
    fileData[TV_USER_CODE4_ADDR + 3] = userCodeTV[7] & 0x0f;
    /* 写入格式值 */
    index = getFormatNum(ui->comboBox_STB_Format->currentText());
    if (index == 100) return;
    fileData[STB_USER_FORMAT_ADDR + 2] = (index & 0xf0) >> 4;
    fileData[STB_USER_FORMAT_ADDR + 3] = index & 0x0f;

    index = getFormatNum(ui->comboBox_TV_Format->currentText());
    if (index == 100) return;
    fileData[TV_USER_FORMAT_ADDR + 2] = (index & 0xf0) >> 4;
    fileData[TV_USER_FORMAT_ADDR + 3] = index & 0x0f;

    /* 写入学习按键键值 */
    index = LEARN_KEY_ADDR;
    for (uint8_t j = 0; j < 10; j ++) {
        index ++;
        index ++;
        fileData[index++] = (learnKeyList[j] & 0xf0) >> 4;
        fileData[index++] = learnKeyList[j] & 0x0f;
    }

    /* 修改红灯闪烁方法 */
    uint16_t lightOnAddr = (LIGHT_ON_M_ADDR - 100)/4;
    uint16_t lightOffAddr = (LIGHT_OFF_M_ADDR - 100)/4;
    if (ui->comboBox_A->currentText() == "长亮") {
        fileData[LEARN_KEY_PRESS_ADDR + 1] = (lightOnAddr & 0x0f00) >> 8;
        fileData[LEARN_KEY_PRESS_ADDR + 2] = (lightOnAddr & 0x00f0) >> 4;
        fileData[LEARN_KEY_PRESS_ADDR + 3] = lightOnAddr & 0x000f;
    } else {
        fileData[LEARN_KEY_PRESS_ADDR + 1] = (lightOffAddr & 0x0f00) >> 8;
        fileData[LEARN_KEY_PRESS_ADDR + 2] = (lightOffAddr & 0x00f0) >> 4;
        fileData[LEARN_KEY_PRESS_ADDR + 3] = lightOffAddr & 0x000f;
    }
    if (ui->comboBox_B->currentText() == "长亮") {
        fileData[LEARN_KEY_FREE_ADDR + 1] = (lightOnAddr & 0x0f00) >> 8;
        fileData[LEARN_KEY_FREE_ADDR + 2] = (lightOnAddr & 0x00f0) >> 4;
        fileData[LEARN_KEY_FREE_ADDR + 3] = lightOnAddr & 0x000f;
    } else {
        fileData[LEARN_KEY_FREE_ADDR + 1] = (lightOffAddr & 0x0f00) >> 8;
        fileData[LEARN_KEY_FREE_ADDR + 2] = (lightOffAddr & 0x00f0) >> 4;
        fileData[LEARN_KEY_FREE_ADDR + 3] = lightOffAddr & 0x000f;
    }
    if (ui->comboBox_C->currentText() == "长亮") {
        fileData[LEARN_WAIT_IR_ADDR + 1] = (lightOnAddr & 0x0f00) >> 8;
        fileData[LEARN_WAIT_IR_ADDR + 2] = (lightOnAddr & 0x00f0) >> 4;
        fileData[LEARN_WAIT_IR_ADDR + 3] = lightOnAddr & 0x000f;
    } else {
        fileData[LEARN_WAIT_IR_ADDR + 1] = (lightOffAddr & 0x0f00) >> 8;
        fileData[LEARN_WAIT_IR_ADDR + 2] = (lightOffAddr & 0x00f0) >> 4;
        fileData[LEARN_WAIT_IR_ADDR + 3] = lightOffAddr & 0x000f;
    }

    /* 修改小红灯亮灭灯程序 */
    uint16_t dataBuff = 0;
    if (ui->comboBox_LED->currentText() == "红灯接14脚") {
        /* 设置14脚亮灯 */
        dataBuff = ioPinState[1][14-2];
        fileData[LIGHT_ON_M_ADDR + 0] = (dataBuff & 0xf000) >> 12;
        fileData[LIGHT_ON_M_ADDR + 1] = (dataBuff & 0x0f00) >> 8;
        fileData[LIGHT_ON_M_ADDR + 2] = (dataBuff & 0x00f0) >> 4;
        fileData[LIGHT_ON_M_ADDR + 3] = (dataBuff & 0x000f) >> 0;
        dataBuff = ioPinLevel[0][14-2];
        fileData[LIGHT_ON_D_ADDR + 0] = (dataBuff & 0xf000) >> 12;
        fileData[LIGHT_ON_D_ADDR + 1] = (dataBuff & 0x0f00) >> 8;
        fileData[LIGHT_ON_D_ADDR + 2] = (dataBuff & 0x00f0) >> 4;
        fileData[LIGHT_ON_D_ADDR + 3] = (dataBuff & 0x000f) >> 0;
        /* 设置14脚灭灯 */
        dataBuff = ioPinState[1][14-2];
        fileData[LIGHT_OFF_M_ADDR + 0] = (dataBuff & 0xf000) >> 12;
        fileData[LIGHT_OFF_M_ADDR + 1] = (dataBuff & 0x0f00) >> 8;
        fileData[LIGHT_OFF_M_ADDR + 2] = (dataBuff & 0x00f0) >> 4;
        fileData[LIGHT_OFF_M_ADDR + 3] = (dataBuff & 0x000f) >> 0;
        dataBuff = ioPinLevel[1][14-2];
        fileData[LIGHT_OFF_D_ADDR + 0] = (dataBuff & 0xf000) >> 12;
        fileData[LIGHT_OFF_D_ADDR + 1] = (dataBuff & 0x0f00) >> 8;
        fileData[LIGHT_OFF_D_ADDR + 2] = (dataBuff & 0x00f0) >> 4;
        fileData[LIGHT_OFF_D_ADDR + 3] = (dataBuff & 0x000f) >> 0;
    } else {
        /* 设置2脚亮灯 */
        dataBuff = ioPinState[1][2-2];
        fileData[LIGHT_ON_M_ADDR + 0] = (dataBuff & 0xf000) >> 12;
        fileData[LIGHT_ON_M_ADDR + 1] = (dataBuff & 0x0f00) >> 8;
        fileData[LIGHT_ON_M_ADDR + 2] = (dataBuff & 0x00f0) >> 4;
        fileData[LIGHT_ON_M_ADDR + 3] = (dataBuff & 0x000f) >> 0;
        dataBuff = ioPinLevel[0][2-2];
        fileData[LIGHT_ON_D_ADDR + 0] = (dataBuff & 0xf000) >> 12;
        fileData[LIGHT_ON_D_ADDR + 1] = (dataBuff & 0x0f00) >> 8;
        fileData[LIGHT_ON_D_ADDR + 2] = (dataBuff & 0x00f0) >> 4;
        fileData[LIGHT_ON_D_ADDR + 3] = (dataBuff & 0x000f) >> 0;
        /* 设置2脚灭灯 */
        dataBuff = ioPinState[1][2-2];
        fileData[LIGHT_OFF_M_ADDR + 0] = (dataBuff & 0xf000) >> 12;
        fileData[LIGHT_OFF_M_ADDR + 1] = (dataBuff & 0x0f00) >> 8;
        fileData[LIGHT_OFF_M_ADDR + 2] = (dataBuff & 0x00f0) >> 4;
        fileData[LIGHT_OFF_M_ADDR + 3] = (dataBuff & 0x000f) >> 0;
        dataBuff = ioPinLevel[1][2-2];
        fileData[LIGHT_OFF_D_ADDR + 0] = (dataBuff & 0xf000) >> 12;
        fileData[LIGHT_OFF_D_ADDR + 1] = (dataBuff & 0x0f00) >> 8;
        fileData[LIGHT_OFF_D_ADDR + 2] = (dataBuff & 0x00f0) >> 4;
        fileData[LIGHT_OFF_D_ADDR + 3] = (dataBuff & 0x000f) >> 0;
    }
    /* 学习设置键 */
    fileData[SET_KEY_ADDR1 + 2] = (setKeyValue & 0xf0) >> 4;
    fileData[SET_KEY_ADDR1 + 3] = setKeyValue & 0x0f;
    fileData[SET_KEY_ADDR2 + 2] = (setKeyValue & 0xf0) >> 4;
    fileData[SET_KEY_ADDR2 + 3] = setKeyValue & 0x0f;
    fileData[SET_KEY_ADDR3 + 2] = (setKeyValue & 0xf0) >> 4;
    fileData[SET_KEY_ADDR3 + 3] = setKeyValue & 0x0f;
    fileData[SET_KEY_ADDR4 + 2] = (setKeyValue & 0xf0) >> 4;
    fileData[SET_KEY_ADDR4 + 3] = setKeyValue & 0x0f;
    /* 学习退出IO口设置 */
    QString * pin = nullptr;
    if (ui->comboBox_LED->currentText() == "红灯接14脚") {
        pin = pinA;
    } else {
        pin = pinB;
    }

    uint8_t pin1 = 0;
    uint8_t pin2 = 0;
    getKeyPin(translate[setKeyValue], pin, &pin1, &pin2);

    qDebug("pin1 is %d", pin1);
    qDebug("pin2 is %d", pin2);
    if (pin1 == 1) {
        dataBuff = 0;
    } else {
        dataBuff = ioPinState[1][pin1-2];
    }
    fileData[SET_OUTPUT_ADDR1 + 0] = (dataBuff & 0xf000) >> 12;
    fileData[SET_OUTPUT_ADDR1 + 1] = (dataBuff & 0x0f00) >> 8;
    fileData[SET_OUTPUT_ADDR1 + 2] = (dataBuff & 0x00f0) >> 4;
    fileData[SET_OUTPUT_ADDR1 + 3] = (dataBuff & 0x000f) >> 0;
    fileData[SET_OUTPUT_ADDRS1 + 0] = (dataBuff & 0xf000) >> 12;
    fileData[SET_OUTPUT_ADDRS1 + 1] = (dataBuff & 0x0f00) >> 8;
    fileData[SET_OUTPUT_ADDRS1 + 2] = (dataBuff & 0x00f0) >> 4;
    fileData[SET_OUTPUT_ADDRS1 + 3] = (dataBuff & 0x000f) >> 0;
    if (pin1 == 1) {
        dataBuff = 0;
    } else {
        dataBuff = ioPinLevel[0][pin1-2];
    }
    fileData[SET_OUTPUT_ADDR2 + 0] = (dataBuff & 0xf000) >> 12;
    fileData[SET_OUTPUT_ADDR2 + 1] = (dataBuff & 0x0f00) >> 8;
    fileData[SET_OUTPUT_ADDR2 + 2] = (dataBuff & 0x00f0) >> 4;
    fileData[SET_OUTPUT_ADDR2 + 3] = (dataBuff & 0x000f) >> 0;
    fileData[SET_OUTPUT_ADDRS2 + 0] = (dataBuff & 0xf000) >> 12;
    fileData[SET_OUTPUT_ADDRS2 + 1] = (dataBuff & 0x0f00) >> 8;
    fileData[SET_OUTPUT_ADDRS2 + 2] = (dataBuff & 0x00f0) >> 4;
    fileData[SET_OUTPUT_ADDRS2 + 3] = (dataBuff & 0x000f) >> 0;
    dataBuff = ioPinState[0][pin2-2];
    fileData[SET_OUTPUT_ADDR3 + 0] = (dataBuff & 0xf000) >> 12;
    fileData[SET_OUTPUT_ADDR3 + 1] = (dataBuff & 0x0f00) >> 8;
    fileData[SET_OUTPUT_ADDR3 + 2] = (dataBuff & 0x00f0) >> 4;
    fileData[SET_OUTPUT_ADDR3 + 3] = (dataBuff & 0x000f) >> 0;
    dataBuff = ioPinLevel[0][pin2-2];
    fileData[SET_OUTPUT_ADDR4 + 0] = (dataBuff & 0xf000) >> 12;
    fileData[SET_OUTPUT_ADDR4 + 1] = (dataBuff & 0x0f00) >> 8;
    fileData[SET_OUTPUT_ADDR4 + 2] = (dataBuff & 0x00f0) >> 4;
    fileData[SET_OUTPUT_ADDR4 + 3] = (dataBuff & 0x000f) >> 0;

    dataBuff = ioData[pin2 - 2];
    fileData[SET_INPUT_ADDR + 0] = (dataBuff & 0xf000) >> 12;
    fileData[SET_INPUT_ADDR + 1] = (dataBuff & 0x0f00) >> 8;
    fileData[SET_INPUT_ADDR + 2] = (dataBuff & 0x00f0) >> 4;
    fileData[SET_INPUT_ADDR + 3] = (dataBuff & 0x000f) >> 0;
    dataBuff = dataBuff - 0x0800;   //判0跳转改为判1跳转
    fileData[SET_INPUT_SADDR + 0] = (dataBuff & 0xf000) >> 12;
    fileData[SET_INPUT_SADDR + 1] = (dataBuff & 0x0f00) >> 8;
    fileData[SET_INPUT_SADDR + 2] = (dataBuff & 0x00f0) >> 4;
    fileData[SET_INPUT_SADDR + 3] = (dataBuff & 0x000f) >> 0;
    /* io 初始化 */
    if (ui->comboBox_LED->currentText() == "红灯接14脚") {
        fileData[IO_P1TSM_ADDR + 2] =  (0XFF & 0xf0) >> 4;
        fileData[IO_P1TSM_ADDR + 3] =  (0XFF & 0x0f) >> 0;
        fileData[IO_P2TSM_ADDR + 2] =  (0x0F & 0xf0) >> 4;
        fileData[IO_P2TSM_ADDR + 3] =  (0X0F & 0x0f) >> 0;
        fileData[IO_P1WAKE_ADDR + 2] = (0XFF & 0xf0) >> 4;
        fileData[IO_P1WAKE_ADDR + 3] = (0XFF & 0x0f) >> 0;
        fileData[IO_P2WAKE_ADDR + 2] = (0X0F & 0xf0) >> 4;
        fileData[IO_P2WAKE_ADDR + 3] = (0X0F & 0x0f) >> 0;
        fileData[IO_P1MODE_ADDR + 2] = (0X00 & 0xf0) >> 4;
        fileData[IO_P1MODE_ADDR + 3] = (0X00 & 0x0f) >> 0;
        fileData[IO_P2MODE_ADDR + 2] = (0X30 & 0xf0) >> 4;
        fileData[IO_P2MODE_ADDR + 3] = (0X30 & 0x0f) >> 0;
        fileData[IO_P1DATA_ADDR + 2] = (0X00 & 0xf0) >> 4;
        fileData[IO_P1DATA_ADDR + 3] = (0X00 & 0x0f) >> 0;
        fileData[IO_P2DATA_ADDR + 2] = (0X30 & 0xf0) >> 4;
        fileData[IO_P2DATA_ADDR + 3] = (0X30 & 0x0f) >> 0;
    } else {
        fileData[IO_P1TSM_ADDR + 2] =  (0XFE & 0xf0) >> 4;
        fileData[IO_P1TSM_ADDR + 3] =  (0XFE & 0x0f) >> 0;
        fileData[IO_P2TSM_ADDR + 2] =  (0x1F & 0xf0) >> 4;
        fileData[IO_P2TSM_ADDR + 3] =  (0X1F & 0x0f) >> 0;
        fileData[IO_P1WAKE_ADDR + 2] = (0XFE & 0xf0) >> 4;
        fileData[IO_P1WAKE_ADDR + 3] = (0XFE & 0x0f) >> 0;
        fileData[IO_P2WAKE_ADDR + 2] = (0X1F & 0xf0) >> 4;
        fileData[IO_P2WAKE_ADDR + 3] = (0X1F & 0x0f) >> 0;
        fileData[IO_P1MODE_ADDR + 2] = (0X01 & 0xf0) >> 4;
        fileData[IO_P1MODE_ADDR + 3] = (0X01 & 0x0f) >> 0;
        fileData[IO_P2MODE_ADDR + 2] = (0X20 & 0xf0) >> 4;
        fileData[IO_P2MODE_ADDR + 3] = (0X20 & 0x0f) >> 0;
        fileData[IO_P1DATA_ADDR + 2] = (0X01 & 0xf0) >> 4;
        fileData[IO_P1DATA_ADDR + 3] = (0X01 & 0x0f) >> 0;
        fileData[IO_P2DATA_ADDR + 2] = (0X20 & 0xf0) >> 4;
        fileData[IO_P2DATA_ADDR + 3] = (0X20 & 0x0f) >> 0;
    }

    /* 修改键扫 */
    if (ui->comboBox_LED->currentText() == "红灯接14脚") {
        fileData[KEY_START_ADDR + 2] = 0x10 >> 4;
        fileData[KEY_START_ADDR + 3] = 0x10 & 0x0f;
        fileData[KEY_P2MODE_ADDR + 2] = 0x30 >> 4;
        fileData[KEY_P2MODE_ADDR + 3] = 0x30 & 0x0f;
        fileData[KEY_P1MODE_ADDR + 2] = 0x00 >> 4;
        fileData[KEY_P1MODE_ADDR + 3] = 0x00 & 0x0f;
        fileData[CHECK_IO_ADDR + 1] = 0x08;
    } else {
        fileData[KEY_START_ADDR + 2] = 0x20 >> 4;
        fileData[KEY_START_ADDR + 3] = 0x20 & 0x0f;
        fileData[KEY_P2MODE_ADDR + 2] = 0x20 >> 4;
        fileData[KEY_P2MODE_ADDR + 3] = 0x20 & 0x0f;
        fileData[KEY_P1MODE_ADDR + 2] = 0x01 >> 4;
        fileData[KEY_P1MODE_ADDR + 3] = 0x01 & 0x0f;
        fileData[CHECK_IO_ADDR + 1] = 0x09;
    }
    /* 生成校验码 */
    verifyCode = calculate_verifycode(fileData);
    QDateTime current_time = QDateTime::currentDateTime();
    QString StrCurrentTime = current_time.toString("yyyyMMdd-hhmmss");
    QFile newFile(tr("%1/%2[checksum-0x%3].lt").arg(QDir::currentPath()).arg(StrCurrentTime).arg(verifyCode,4,16));
    newFile.open(QIODevice::ReadWrite);
    newFile.write(fileData);
    QMessageBox::information(NULL, tr("生成信息："),
                             tr("普通按键个数：%1个\n学习按键个数：%2个\n总共按键个数：%3个\n校验码：0x%4").arg(normalKeyNum).arg(learnKeyNum).arg(totalKeyNum).arg(verifyCode,4,16));

    return;
}
//更改编辑状态
void MainWindow::on_pushButton_1_clicked()
{
    edit_flag = (!edit_flag)&0x01;
    if(edit_flag) {
        ui->pushButton_1->setText("学习按键编辑");
        ui->pushButton_1->setStyleSheet("color:red");
    } else {
        ui->pushButton_1->setText("普通按键编辑");
        ui->pushButton_1->setStyleSheet("color:black");
    }

}
//更改显示连接还是按键编号
void MainWindow::on_pushButton_3_clicked()
{
    display_flag = !display_flag;
    if(display_flag) {
        ui->pushButton_3->setText("显示序号");
        for (int i = 0; i < 78; i ++) {
            QString text = "K";
            text.append(QString::number(i + 1, 10));
            keyLabel[i]->setText(text);
        }
    } else {
        ui->pushButton_3->setText("显示连接");
        QString * pin = nullptr;
        if (ui->comboBox_LED->currentText() == "红灯接14脚") {
            pin = pinA;
        } else {
            pin = pinB;
        }
        int k = 0;
        for (int j = 0; j < 13;) {
            for (int i = 0; i < j; i ++) {
                QString connect = "";
                connect.append(pin[j]);
                connect.append("-");
                connect.append(pin[i]);
                keyLabel[k++]->setText(connect);
            }
            j ++;
        }
    }
}

//机顶盒用户码输入
void MainWindow::on_lineEdit_user_STB_editingFinished()
{
    char *stringBuff = NULL;
    formatSTB = ui->comboBox_STB_Format->currentText();
    QByteArray user = ui->lineEdit_user_STB->text().toLatin1();
    stringBuff = user.data();
    uint8_t length = strlen(stringBuff);
    uint8_t userLength = 4;
    if (formatSTB == "3010") userLength = 2;
    if (formatSTB == "7051") userLength = 8;
    if (length != userLength) {
        QMessageBox::critical(NULL, tr("警告"), tr("用户码长度错误，请检查！！！\n"
                                                 "当前格式为%1,用户码长度应为%2位").arg(formatSTB).arg(userLength));
        return;
    }
    for (int i = 0; i < userLength; i ++) {
        if (stringBuff[i] >= 'a' && stringBuff[i] <= 'z') stringBuff[i] = stringBuff[i] - 32; // 将小写字母改成大写
    }
    for (int i = 0; i < length; i ++) {
        int temp = char2int(stringBuff[i]);
        if((temp > 15)) {
            QMessageBox::critical(NULL, "警告", "用户码输入非法字符，请检查！！！");
            return;
        }
        userCodeSTB[i] = temp;
    }
}

//学习区用户码输入
void MainWindow::on_lineEdit_user_TV_editingFinished()
{
    char *stringBuff = NULL;
    formatTV = ui->comboBox_TV_Format->currentText();
    QByteArray user = ui->lineEdit_user_TV->text().toLatin1();
    stringBuff = user.data();
    uint8_t length = strlen(stringBuff);
    uint8_t userLength = 4;
    if (formatTV == "3010") userLength = 2;
    if (formatTV == "7051") userLength = 8;
    if (length != userLength) {
        QMessageBox::critical(NULL, tr("警告"), tr("用户码长度错误，请检查！！！\n"
                                                 "当前格式为%1,用户码长度应为%2位").arg(formatTV).arg(userLength));
        return;
    }
    for (int i = 0; i < userLength; i ++) {
        if (stringBuff[i] >= 'a' && stringBuff[i] <= 'z') stringBuff[i] = stringBuff[i] - 32; // 将小写字母改成大写
    }
    for (int i = 0; i < length; i ++) {
        int temp = char2int(stringBuff[i]);
        if((temp > 15)) {
            QMessageBox::critical(NULL, "警告", "用户码输入非法字符，请检查！！！");
            return;
        }
        userCodeTV[i] = temp;
    }
}

void MainWindow::on_comboBox_LED_currentTextChanged()
{
    QString *pin;
    if (ui->comboBox_LED->currentText() == "红灯接14脚") {
        pin = pinA;
    } else {
        pin = pinB;
    }
    for (int i = 0; i < 13; i ++) {
        QString s = {"Pin"};
        s.append(pin[i]);
        pinLabel[i]->setText(s);
    }
    int k = 0;
    for (int j = 0; j < 13;) {
        for (int i = 0; i < j; i ++) {
            QString connect = "";
            connect.append(pin[j]);
            connect.append("-");
            connect.append(pin[i]);
            keyLabel[k++]->setText(connect);
        }
        j ++;
    }
    paintEvent(NULL);

    return;
}

void MainWindow::menu_get_excel()
{
    QString filePath = QFileDialog::getOpenFileName(this,
                                                    tr("导入excel文件"),
                                                    "D:",
                                                    tr("原理图文件(*.xls *.xlsx);;"));
    if (filePath == "") return; //取消对话框则直接退出
    Book *book = NULL;
    if (filePath.endsWith("xls", Qt::CaseSensitive)) {
        book = xlCreateBook(); //xlCreateBook for xls
    } else {
        book = xlCreateXMLBook(); //xlCreateBook for xlsx
    }
    book->setKey(L"TommoT", L"windows-2421220b07c2e10a6eb96768a2p7r6gc");
    if (book->load(filePath.toStdWString().c_str())) {
        qDebug("excel 打开成功");
        Sheet *sheet = book->getSheet(0);
        QString s = "";
        if (sheet->cellType(12, 116) == 2) {
            s = QString::fromStdWString(sheet->readStr(12, 116));
        }
        int (*array)[78][2] = nullptr;
        if (s == "FC-2204") {
            array = &newAxes;
        } else {
            array = &axes;
        }
        for (uint8_t i = 0; i < 78; i++) {
            lEdit[i]->setText("");                  //写入界面控件前，先清除数据
        }
        for (uint8_t i = 0; i < 78; i++) {
            CellType ct = sheet->cellType((*array)[i][0], (*array)[i][1]);
            qDebug("cell type is %d", ct);
            if (ct == 2) {
                qDebug("当前单元格为字符格式");
                lEdit[i]->setText(QString::fromStdWString(sheet->readStr((*array)[i][0], (*array)[i][1])));
            } else if (ct == 1) {
                qDebug("当前单元格为数值格式");
                lEdit[i]->setText(QString::number((int)sheet->readNum((*array)[i][0], (*array)[i][1])));
            }
        }
        book->release();
        QMessageBox::information(this, tr("正确"), tr("文件读取成功！"));
    } else {
        QMessageBox::information(this, tr("错误"), tr("文件读取失败！"));
    }

    return;
}

void MainWindow::menu_put_excel()
{
    Book *book = NULL;
    book = xlCreateBook(); //xlCreateBook for xlsx
    if (book == nullptr) {
        qDebug("create book failed!");
        return;
    }
    book->setKey(L"TommoT", L"windows-2421220b07c2e10a6eb96768a2p7r6gc");

    if (book->load(L"C:/example.xls")) {
        qDebug("资源文件导入成功！");
        Sheet *sheet = book->getSheet(0);
        CellType ct = sheet->cellType(newAxes[1][0], newAxes[1][1]);
        qDebug("cell type is %d", ct);
        for (int i = 0; i < 78; i ++) {
            sheet->writeStr(newAxes[i][0], newAxes[i][1], reinterpret_cast<const wchar_t *>(lEdit[i]->text().utf16()));
        }
        if (book->save(L"new.xls")) {
            book->release();
        } else {
            QMessageBox::information(this, tr("错误"), tr("导出excel文件失败！"));
            book->release();
        }
    } else {
        QMessageBox::information(this, tr("错误"), tr("资源文件损坏！"));
    }

    return;
}

void MainWindow::menu_about()
{
    static const QDate buildDate = QLocale( QLocale::English ).toDate( QString(__DATE__).replace("  ", " 0"), "MMM dd yyyy");
    static const QTime buildTime = QTime::fromString(__TIME__, "hh:mm:ss");

    QMessageBox::information(NULL,
        tr("关于软件"),
        tr("填码软件版本：%1\n"
        "软件更新日期：%2%3\n"
        "芯片程序版本：%4\n"
        "程序更新日期：%5\n"
        "源码校验信息：%6")\
        .arg("1.8.0.0")\
        .arg(buildDate.toString("yyyy.MM.dd"),buildTime.toString("  hh:mm:ss"))\
        .arg("1.9.0.0")\
        .arg("2020年12月22日")\
        .arg("0000000"));
}


void MainWindow::on_comboBox_SetKey_currentTextChanged(const QString &arg1)
{
    QFont ft;
    ft.setPointSize(11);

    if (arg1 == "发码") {
        if (exitKeyComboBox1 == nullptr) {
            exitKeyComboBox1 = new(QComboBox);
            if (exitKeyComboBox1 != nullptr) {
                ui->gridLayout->addWidget(exitKeyComboBox1,1,3,0);
                exitKeyComboBox1->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding, QSizePolicy::ComboBox));
                exitKeyComboBox1->addItems(keyList);
                QObject::connect(exitKeyComboBox1, SIGNAL(activated(const QString &)), this, SLOT(on_comboBox_PowerKey_activated(const QString &)));
            }
        }
        if (exitKeyComboBox2 == nullptr) {
            exitKeyComboBox2 = new(QComboBox);
            if (exitKeyComboBox2 != nullptr) {
                ui->gridLayout->addWidget(exitKeyComboBox2,1,4,0);
                exitKeyComboBox2->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding, QSizePolicy::ComboBox));
                exitKeyComboBox2->addItems(keyList);
                QObject::connect(exitKeyComboBox2, SIGNAL(activated(const QString &)), this, SLOT(on_comboBox_exitKey1_activated(const QString &)));
            }
        }
        if (exitKeyComboBox3 == nullptr) {
            exitKeyComboBox3 = new(QComboBox);
            if (exitKeyComboBox3 != nullptr) {
                ui->gridLayout->addWidget(exitKeyComboBox3,1,5,0);
                exitKeyComboBox3->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding, QSizePolicy::ComboBox));
                exitKeyComboBox3->addItems(keyList);
                exitKeyComboBox3->addItem("所有键");
                QObject::connect(exitKeyComboBox3, SIGNAL(activated(const QString &)), this, SLOT(on_comboBox_exitKey2_activated(const QString &)));
            }
        }
        if (exitKeyLabel1 == nullptr) {
            exitKeyLabel1 = new(QLabel);
            if (exitKeyLabel1 != nullptr) {
                ui->gridLayout->addWidget(exitKeyLabel1,0,3,0);
                exitKeyLabel1->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding, QSizePolicy::Label));
                exitKeyLabel1->setText("Power键选择");
                exitKeyLabel1->setAlignment(Qt::AlignBottom);
                exitKeyLabel1->setFont(ft);
            }
        }
        if (exitKeyLabel2 == nullptr) {
            exitKeyLabel2 = new(QLabel);
            if (exitKeyLabel2 != nullptr) {
                ui->gridLayout->addWidget(exitKeyLabel2,0,4,0);
                exitKeyLabel2->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding, QSizePolicy::Label));
                exitKeyLabel2->setText("等待波形退出");
                exitKeyLabel2->setAlignment(Qt::AlignBottom);
                exitKeyLabel2->setFont(ft);
            }
        }
        if (exitKeyLabel3 == nullptr) {
            exitKeyLabel3 = new(QLabel);
            if (exitKeyLabel3 != nullptr) {
                ui->gridLayout->addWidget(exitKeyLabel3,0,5,0);
                exitKeyLabel3->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding, QSizePolicy::Label));
                exitKeyLabel3->setText("等待按键退出");
                exitKeyLabel3->setAlignment(Qt::AlignBottom);
                exitKeyLabel3->setFont(ft);
            }
        }
    } else {
        if (exitKeyComboBox1 != nullptr) {
            delete exitKeyComboBox1;
            exitKeyComboBox1 = nullptr;
        }
        if (exitKeyComboBox2 != nullptr) {
            delete exitKeyComboBox2;
            exitKeyComboBox2 = nullptr;
        }
        if (exitKeyComboBox3 != nullptr) {
            delete exitKeyComboBox3;
            exitKeyComboBox3 = nullptr;
        }
        if (exitKeyLabel1 != nullptr) {
            delete exitKeyLabel1;
            exitKeyLabel1 = nullptr;
        }
        if (exitKeyLabel2 != nullptr) {
            delete exitKeyLabel2;
            exitKeyLabel2 = nullptr;
        }
        if (exitKeyLabel3 != nullptr) {
            delete exitKeyLabel3;
            exitKeyLabel3 = nullptr;
        }
    }
}

void MainWindow::on_comboBox_PowerKey_activated(const QString &arg1)
{
    qDebug("powerkey: your select is %ls",  qUtf16Printable(arg1));
}

void MainWindow::on_comboBox_exitKey1_activated(const QString &arg1)
{
    qDebug("wait wave come: your select is %ls",  qUtf16Printable(arg1));
}

void MainWindow::on_comboBox_exitKey2_activated(const QString &arg1)
{
    qDebug("wait key press: your select is %ls",  qUtf16Printable(arg1));
}


void MainWindow::on_pushButton_clear_clicked()
{
    QMessageBox *msgBox = new QMessageBox(QMessageBox::Question, tr("选择"), tr("请确认是否清除！"), QMessageBox::Yes|QMessageBox::No);
    msgBox->button(QMessageBox::Yes)->setText("是");
    msgBox->button(QMessageBox::No)->setText("否");

    int rc = msgBox->exec();

    if (rc == QMessageBox::Yes) {
        for (int i = 0; i < TOTALKEYNUM; i++) {
            lEdit[i]->setText("");
        }

        on_comboBox_SetKey_currentTextChanged("不发码");
    }

    return;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    qDebug("exit main window!");
    QString currentFilePath = QDir::currentPath() + QString("/temp.data");  // generate current path
    QFile tempFile(currentFilePath);                                            // create temp.data file, if it is exisit, open it!
    if (!tempFile.open(QIODevice::WriteOnly|QIODevice::Text)) {
        qDebug("file open failed!!!");
        return;
    }
    QTextStream textRecord(&tempFile);
    for (int i = 0; i < TOTALKEYNUM; i++) {
        textRecord << lEdit[i]->text() <<endl;
    }

    textRecord << ui->comboBox_A->currentText() <<endl;
    textRecord << ui->comboBox_B->currentText() <<endl;
    textRecord << ui->comboBox_C->currentText() <<endl;
    textRecord << ui->comboBox_LED->currentText() <<endl;
    textRecord << ui->comboBox_SetKey->currentText() <<endl;
    textRecord << ui->comboBox_STB_Format->currentText() <<endl;
    textRecord << ui->comboBox_TV_Format->currentText() <<endl;


    tempFile.close(); // finish file operation, close it

    SetFileAttributes((LPCWSTR)currentFilePath.unicode(),FILE_ATTRIBUTE_HIDDEN);    // make tempdata file become hidden file

    event->accept(); // accepted exit signal, program exit

    return;
}
