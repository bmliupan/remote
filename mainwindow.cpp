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

int a[][2] = {};
int hightC = 0;
int widthC = 0;
QLineEdit * lEdit[78];

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
     if(hightC == ui->lineEdit_001->size().rheight() &&
         widthC == ui->lineEdit_001->size().rwidth())return;
     QPainter painter(this);
     QPen pen;
     pen.setColor(QColor(0,80,128));
     pen.setWidth(4);
     painter.setPen(pen);
     int i = 0;
     QObjectList list = children();
     foreach( QObject *obj , list)
     {
         if (obj->metaObject()->className() == QStringLiteral("QWidget")){
             QObjectList list2 = obj->children();
             foreach (QObject *obj1, list2){
                 if (obj1->inherits("QLineEdit")){
                     QLineEdit *b = qobject_cast<QLineEdit*>(obj1);
                     if (b == ui->lineEdit_user_TV) continue;
                     if (b == ui->lineEdit_user_STB) continue;
                     a[i][0] = b->geometry().x();
                     a[i][1] = b->geometry().y();
                     i ++;
                 }
             }
         }
     }

     hightC = ui->lineEdit_001->size().rheight();
     widthC = ui->lineEdit_001->size().rwidth();
     int xInterval = ui->lineEdit_003->geometry().x() - ui->lineEdit_002->geometry().x();
     int yInterval = ui->lineEdit_002->geometry().y() - ui->lineEdit_001->geometry().y();
     int num = i;
     for (i = 0; i < num; i++) {
         /* 控件上方线段 */
         int xStart = a[i][0] + widthC/2;
         int yStart = a[i][1];
         int xEnd = xStart;
         int yEnd = a[i][1] - yInterval + hightC/2;
         painter.drawLine(QPointF(xStart,yStart),QPointF(xEnd,yEnd));
         /* 控件下方线段 */

         /* 控件左边线段 */
         xStart = a[i][0];
         yStart = a[i][1] + hightC/2;
         xEnd = a[i][0] + xInterval/2 - 2;// - width/2;
         yEnd = yStart;
         painter.drawLine(QPointF(xStart,yStart),QPointF(xEnd,yEnd));
         /* 控件右边线段 */



     }
   painter.drawLine(QPointF(ui->lineEdit_001->geometry().x(), ui->lineEdit_001->geometry().y()), QPointF(ui->lineEdit_001->geometry().x(), ui->lineEdit_001->geometry().y()+100));
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

void MainWindow::on_pushButton_3_clicked()
{
    display_flag = !display_flag;
    if(display_flag) {
        ui->pushButton_3->setText("显示序号");
        ui->label_001->setText("K01");
        ui->label_002->setText("K02");
        ui->label_003->setText("K03");
        ui->label_004->setText("K04");
        ui->label_005->setText("K05");
        ui->label_006->setText("K06");
        ui->label_007->setText("K07");
        ui->label_008->setText("K08");
        ui->label_009->setText("K09");
        ui->label_010->setText("K10");
        ui->label_011->setText("K11");
        ui->label_012->setText("K12");
        ui->label_013->setText("K13");
        ui->label_014->setText("K14");
        ui->label_015->setText("K15");
        ui->label_016->setText("K16");
        ui->label_017->setText("K17");
        ui->label_018->setText("K18");
        ui->label_019->setText("K19");
        ui->label_020->setText("K20");
        ui->label_021->setText("K21");
        ui->label_022->setText("K22");
        ui->label_023->setText("K23");
        ui->label_024->setText("K24");
        ui->label_025->setText("K25");
        ui->label_026->setText("K26");
        ui->label_027->setText("K27");
        ui->label_028->setText("K28");
        ui->label_029->setText("K29");
        ui->label_030->setText("K30");
        ui->label_031->setText("K31");
        ui->label_032->setText("K32");
        ui->label_033->setText("K33");
        ui->label_034->setText("K34");
        ui->label_035->setText("K35");
        ui->label_036->setText("K36");
        ui->label_037->setText("K37");
        ui->label_038->setText("K38");
        ui->label_039->setText("K39");
        ui->label_040->setText("K40");
        ui->label_041->setText("K41");
        ui->label_042->setText("K42");
        ui->label_043->setText("K43");
        ui->label_044->setText("K44");
        ui->label_045->setText("K45");
        ui->label_046->setText("K46");
        ui->label_047->setText("K47");
        ui->label_048->setText("K48");
        ui->label_049->setText("K49");
        ui->label_050->setText("K50");
        ui->label_051->setText("K51");
        ui->label_052->setText("K52");
        ui->label_053->setText("K53");
        ui->label_054->setText("K54");
        ui->label_055->setText("K55");
        ui->label_056->setText("K56");
        ui->label_057->setText("K57");
        ui->label_058->setText("K58");
        ui->label_059->setText("K59");
        ui->label_060->setText("K60");
        ui->label_061->setText("K61");
        ui->label_062->setText("K62");
        ui->label_063->setText("K63");
        ui->label_064->setText("K64");
        ui->label_065->setText("K65");
        ui->label_066->setText("K66");
    } else {
        ui->pushButton_3->setText("显示连接");
        ui->label_001->setText("3-4"); //K01
        ui->label_002->setText("3-5"); //K02
        ui->label_003->setText("4-5"); //K03
        ui->label_004->setText("3-6"); //K04
        ui->label_005->setText("4-6"); //K05
        ui->label_006->setText("5-6"); //K06
        ui->label_007->setText("3-7"); //K07
        ui->label_008->setText("4-7"); //K08
        ui->label_009->setText("5-7"); //K09
        ui->label_010->setText("6-7"); //K10
        ui->label_011->setText("3-8"); //K11
        ui->label_012->setText("4-8"); //K12
        ui->label_013->setText("5-8"); //K13
        ui->label_014->setText("6-8"); //K14
        ui->label_015->setText("7-8"); //K15
        ui->label_016->setText("3-9"); //K16
        ui->label_017->setText("4-9"); //K17
        ui->label_018->setText("5-9"); //K18
        ui->label_019->setText("6-9"); //K19
        ui->label_020->setText("7-9"); //K20
        ui->label_021->setText("8-9"); //K21
        ui->label_022->setText("3-10"); //K22
        ui->label_023->setText("4-10"); //K23
        ui->label_024->setText("5-10"); //K24
        ui->label_025->setText("6-10"); //K25
        ui->label_026->setText("7-10"); //K26
        ui->label_027->setText("8-10"); //K27
        ui->label_028->setText("9-10"); //K28
        ui->label_029->setText("3-11"); //K29
        ui->label_030->setText("4-11"); //K30
        ui->label_031->setText("5-11"); //K31
        ui->label_032->setText("6-11"); //K32
        ui->label_033->setText("7-11"); //K33
        ui->label_034->setText("8-11"); //K34
        ui->label_035->setText("9-11"); //K35
        ui->label_036->setText("10-11"); //K36
        ui->label_037->setText("3-12"); //K37
        ui->label_038->setText("4-12"); //K38
        ui->label_039->setText("5-12"); //K39
        ui->label_040->setText("6-12"); //K40
        ui->label_041->setText("7-12"); //K41
        ui->label_042->setText("8-12"); //K42
        ui->label_043->setText("9-12"); //K43
        ui->label_044->setText("10-12"); //K44
        ui->label_045->setText("11-12"); //K45
        ui->label_046->setText("3-13"); //K46
        ui->label_047->setText("4-13"); //K47
        ui->label_048->setText("5-13"); //K48
        ui->label_049->setText("6-13"); //K49
        ui->label_050->setText("7-13"); //K50
        ui->label_051->setText("8-13"); //K51
        ui->label_052->setText("9-13"); //K52
        ui->label_053->setText("10-13"); //K53
        ui->label_054->setText("11-13"); //K54
        ui->label_055->setText("12-13"); //K55
        ui->label_056->setText("3-1"); //K56
        ui->label_057->setText("4-1"); //K57
        ui->label_058->setText("5-1"); //K58
        ui->label_059->setText("6-1"); //K59
        ui->label_060->setText("7-1"); //K60
        ui->label_061->setText("8-1"); //K61
        ui->label_062->setText("9-1"); //K62
        ui->label_063->setText("10-1"); //K63
        ui->label_064->setText("11-1"); //K64
        ui->label_065->setText("12-1"); //K65
        ui->label_066->setText("13-1"); //K66
    }
}

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

