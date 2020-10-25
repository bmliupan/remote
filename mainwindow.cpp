#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "function.h"
#include "data.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QDataStream>
#include <QPainter>
#include <qdatetime.h>
#include <QSignalMapper>
#include "ltFileParameter.h"

int hightC = 0;
int widthC = 0;
QString pinA[] = {"2","3","4","5","6","7","8","9","10","11","12","13","1"};
QString pinB[] = {"3","4","5","6","7","8","9","10","11","12","13","14","1"};

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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::input_KeyNUM(QString text)
{

    int index = text.toInt();
    qDebug("index value is %d", index);
    lEdit[index]->setStyleSheet("background-color:rgba(255,0,0,255)");
    if (lEdit[index] == nullptr) return;
    if (!edit_flag) {
        lEdit[index]->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        lEdit[index]->setStyleSheet("background-color:rgba(255,0,0,255)");
    }
    if (checkInput(ui->lineEdit_001->text(), index) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }

    return;
}

 void MainWindow::paintEvent(QPaintEvent *)
 {
     QPainter painter(this);
     QPen pen;
     pen.setColor(QColor(0,80,128));
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

     hightC = ui->lineEdit_001->size().rheight();
     widthC = ui->lineEdit_001->size().rwidth();
     int xInterval = ui->lineEdit_002->geometry().x() - ui->lineEdit_003->geometry().x();
     for (i = 0; i < 12; i++) {
         int xStart = a[i][0] - xInterval + widthC/2;
         int yStart = a[i][1] + hightC/2 ;
         int xEnd = a[0][0] + widthC + 6;
         int yEnd = yStart;
         if (i == 11) xStart = a[i][0] + 5;
         //画横线
         painter.drawLine(QPointF(xStart,yStart),QPointF(xEnd,yEnd));
         //画竖线
         xEnd = xStart;
         yEnd = a[11][1];
         if (i != 11) painter.drawLine(QPointF(xStart,yStart),QPointF(xEnd,yEnd));
     }
     int xStart = a[0][0] + widthC/2;
     int yStart = a[0][1] - hightC/2 ;
     int xEnd = a[0][0] + widthC + 6;
     int yEnd = yStart;
     painter.drawLine(QPointF(xStart,yStart),QPointF(xEnd,yEnd));
     xEnd = xStart;
     yEnd = a[11][1];
     painter.drawLine(QPointF(xStart,yStart),QPointF(xEnd,yEnd));
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
    for (int i = 0; i < 66; i++) {
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
    for (uint8_t j = 0; j < 66; j ++) {
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
    uint16_t dataBuff;
    if (ui->comboBox_LED->currentText() == "红灯接14脚") {
        /* 设置14脚亮灯 */
        dataBuff = setStateIO(14, OutState);
        fileData[LIGHT_ON_M_ADDR + 0] = (dataBuff & 0xf000) >> 12;
        fileData[LIGHT_ON_M_ADDR + 1] = (dataBuff & 0x0f00) >> 8;
        fileData[LIGHT_ON_M_ADDR + 2] = (dataBuff & 0x00f0) >> 4;
        fileData[LIGHT_ON_M_ADDR + 3] = (dataBuff & 0x000f) >> 0;
        dataBuff = setLevelIO(14, lowLevel);
        fileData[LIGHT_ON_D_ADDR + 0] = (dataBuff & 0xf000) >> 12;
        fileData[LIGHT_ON_D_ADDR + 1] = (dataBuff & 0x0f00) >> 8;
        fileData[LIGHT_ON_D_ADDR + 2] = (dataBuff & 0x00f0) >> 4;
        fileData[LIGHT_ON_D_ADDR + 3] = (dataBuff & 0x000f) >> 0;
        /* 设置14脚灭灯 */
        dataBuff = setStateIO(14, OutState);
        fileData[LIGHT_OFF_M_ADDR + 0] = (dataBuff & 0xf000) >> 12;
        fileData[LIGHT_OFF_M_ADDR + 1] = (dataBuff & 0x0f00) >> 8;
        fileData[LIGHT_OFF_M_ADDR + 2] = (dataBuff & 0x00f0) >> 4;
        fileData[LIGHT_OFF_M_ADDR + 3] = (dataBuff & 0x000f) >> 0;
        dataBuff = setLevelIO(14, highLevel);
        fileData[LIGHT_OFF_D_ADDR + 0] = (dataBuff & 0xf000) >> 12;
        fileData[LIGHT_OFF_D_ADDR + 1] = (dataBuff & 0x0f00) >> 8;
        fileData[LIGHT_OFF_D_ADDR + 2] = (dataBuff & 0x00f0) >> 4;
        fileData[LIGHT_OFF_D_ADDR + 3] = (dataBuff & 0x000f) >> 0;
    } else {
        /* 设置2脚亮灯 */
        dataBuff = setStateIO(2, OutState);
        fileData[LIGHT_ON_M_ADDR + 0] = (dataBuff & 0xf000) >> 12;
        fileData[LIGHT_ON_M_ADDR + 1] = (dataBuff & 0x0f00) >> 8;
        fileData[LIGHT_ON_M_ADDR + 2] = (dataBuff & 0x00f0) >> 4;
        fileData[LIGHT_ON_M_ADDR + 3] = (dataBuff & 0x000f) >> 0;
        dataBuff = setLevelIO(2, lowLevel);
        fileData[LIGHT_ON_D_ADDR + 0] = (dataBuff & 0xf000) >> 12;
        fileData[LIGHT_ON_D_ADDR + 1] = (dataBuff & 0x0f00) >> 8;
        fileData[LIGHT_ON_D_ADDR + 2] = (dataBuff & 0x00f0) >> 4;
        fileData[LIGHT_ON_D_ADDR + 3] = (dataBuff & 0x000f) >> 0;
        /* 设置2脚灭灯 */
        dataBuff = setStateIO(2, OutState);
        fileData[LIGHT_OFF_M_ADDR + 0] = (dataBuff & 0xf000) >> 12;
        fileData[LIGHT_OFF_M_ADDR + 1] = (dataBuff & 0x0f00) >> 8;
        fileData[LIGHT_OFF_M_ADDR + 2] = (dataBuff & 0x00f0) >> 4;
        fileData[LIGHT_OFF_M_ADDR + 3] = (dataBuff & 0x000f) >> 0;
        dataBuff = setLevelIO(2, highLevel);
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
    dataBuff = setStateIO(listenIO[setKeyValue][0],OutState);
    fileData[SET_OUTPUT_ADDR1 + 0] = (dataBuff & 0xf000) >> 12;
    fileData[SET_OUTPUT_ADDR1 + 1] = (dataBuff & 0x0f00) >> 8;
    fileData[SET_OUTPUT_ADDR1 + 2] = (dataBuff & 0x00f0) >> 4;
    fileData[SET_OUTPUT_ADDR1 + 3] = (dataBuff & 0x000f) >> 0;  //写入指令 控制io状态
    dataBuff = setLevelIO(listenIO[setKeyValue][0],lowLevel);
    fileData[SET_OUTPUT_ADDR2 + 0] = (dataBuff & 0xf000) >> 12;
    fileData[SET_OUTPUT_ADDR2 + 1] = (dataBuff & 0x0f00) >> 8;
    fileData[SET_OUTPUT_ADDR2 + 2] = (dataBuff & 0x00f0) >> 4;
    fileData[SET_OUTPUT_ADDR2 + 3] = (dataBuff & 0x000f) >> 0;
    dataBuff = setStateIO(listenIO[setKeyValue][1],inState);
    fileData[SET_OUTPUT_ADDR3 + 0] = (dataBuff & 0xf000) >> 12;
    fileData[SET_OUTPUT_ADDR3 + 1] = (dataBuff & 0x0f00) >> 8;
    fileData[SET_OUTPUT_ADDR3 + 2] = (dataBuff & 0x00f0) >> 4;
    fileData[SET_OUTPUT_ADDR3 + 3] = (dataBuff & 0x000f) >> 0;
    dataBuff = setLevelIO(listenIO[setKeyValue][1],lowLevel);
    fileData[SET_OUTPUT_ADDR4 + 0] = (dataBuff & 0xf000) >> 12;
    fileData[SET_OUTPUT_ADDR4 + 1] = (dataBuff & 0x0f00) >> 8;
    fileData[SET_OUTPUT_ADDR4 + 2] = (dataBuff & 0x00f0) >> 4;
    fileData[SET_OUTPUT_ADDR4 + 3] = (dataBuff & 0x000f) >> 0;

    dataBuff = judgeIO(listenIO[setKeyValue][1]);
    fileData[SET_INPUT_ADDR + 0] = (dataBuff & 0xf000) >> 12;
    fileData[SET_INPUT_ADDR + 1] = (dataBuff & 0x0f00) >> 8;
    fileData[SET_INPUT_ADDR + 2] = (dataBuff & 0x00f0) >> 4;
    fileData[SET_INPUT_ADDR + 3] = (dataBuff & 0x000f) >> 0;

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
//读入lt文件
void MainWindow::on_pushButton_4_clicked()
{
    /*
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("文件对话框！"),
                                                    "D:",
                                                    tr("程序文件(*lt);;"));
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly))
    {
      qDebug("open source file failed!");
      return;
    }

    QByteArray fileData;
    fileData = file.readAll();
    */
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
}
