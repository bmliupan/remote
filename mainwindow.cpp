#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "inc/function.h"
#include "inc/data.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QDataStream>
#include <qdatetime.h>
#include "ltFileParameter.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_A->setStyleSheet("color:red;");
    ui->label_B->setStyleSheet("color:red;");
    ui->label_C->setStyleSheet("color:red;");
    setWindowIcon(QIcon(":/icon/mcu.ico"));
}

MainWindow::~MainWindow()
{
    delete ui;
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

//键值输入
void MainWindow::on_lineEdit_001_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_001->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_001->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_001->text(), 0) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_002_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_002->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_002->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_002->text(), 1) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_003_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_003->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_003->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_003->text(), 2) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_004_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_004->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_004->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_004->text(), 3) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_005_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_005->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_005->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_005->text(), 4) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_006_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_006->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_006->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_006->text(), 5) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_007_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_007->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_007->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_007->text(), 6) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_008_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_008->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_008->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_008->text(), 7) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_009_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_009->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_009->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_009->text(), 8) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_010_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_010->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_010->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_010->text(), 9) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_011_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_011->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_011->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_011->text(), 10) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_012_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_012->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_012->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_012->text(), 11) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_013_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_013->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_013->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_013->text(), 12) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_014_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_014->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_014->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_014->text(), 13) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_015_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_015->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_015->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_015->text(), 14) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_016_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_016->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_016->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_016->text(), 15) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_017_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_017->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_017->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_017->text(), 16) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_018_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_018->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_018->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_018->text(), 17) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_019_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_019->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_019->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_019->text(), 18) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_020_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_020->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_020->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_020->text(), 19) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_021_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_021->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_021->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_021->text(), 20) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_022_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_022->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_022->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_022->text(), 21) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_023_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_023->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_023->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_023->text(), 22) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_024_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_024->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_024->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_024->text(), 23) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_025_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_025->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_025->setStyleSheet("background-color:rgba(255,0,0,255)");
    }


    if(checkInput(ui->lineEdit_025->text(), 24) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_026_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_026->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_026->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_026->text(), 25) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_027_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_027->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_027->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_027->text(), 26) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_028_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_028->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_028->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_028->text(), 27) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_029_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_029->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_029->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_029->text(), 28) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_030_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_030->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_030->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_030->text(), 29) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_031_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_031->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_031->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_031->text(), 30) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_032_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_032->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_032->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_032->text(), 31) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_033_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_033->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_033->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_033->text(), 32) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_034_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_034->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_034->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_034->text(), 33) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_035_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_035->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_035->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_035->text(), 34) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_036_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_036->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_036->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_036->text(), 35) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_037_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_037->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_037->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_037->text(), 36) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_038_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_038->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_038->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_038->text(), 37) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_039_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_039->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_039->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_039->text(), 38) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_040_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_040->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_040->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_040->text(), 39) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_041_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_041->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_041->setStyleSheet("background-color:rgba(255,0,0,255)");
    }


    if(checkInput(ui->lineEdit_041->text(), 40) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_042_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_042->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_042->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_042->text(), 41) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_043_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_043->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_043->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_043->text(), 42) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_044_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_044->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_044->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_044->text(), 43) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_045_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_045->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_045->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_045->text(), 44) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_046_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_046->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_046->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_046->text(), 45) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_047_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_047->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_047->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_047->text(), 46) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_048_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_048->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_048->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_048->text(), 47) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_049_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_049->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_049->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_049->text(), 48) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_050_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_050->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_050->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_050->text(), 49) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_051_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_051->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_051->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_051->text(), 50) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_052_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_052->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_052->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_052->text(), 51) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_053_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_053->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_053->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_053->text(), 52) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_054_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_054->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_054->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_054->text(), 53) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_055_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_055->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_055->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_055->text(), 54) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_056_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_056->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_056->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_056->text(), 55) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_057_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_057->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_057->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_057->text(), 56) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_058_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_058->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_058->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_058->text(), 57) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_059_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_059->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_059->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_059->text(), 58) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_060_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_060->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_060->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_060->text(), 59) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_061_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_061->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_061->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_061->text(), 60) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_062_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_062->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_062->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_062->text(), 61) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_063_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_063->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_063->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_063->text(), 62) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_064_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_064->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_064->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_064->text(), 63) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_065_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_065->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_065->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_065->text(), 64) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}

void MainWindow::on_lineEdit_066_editingFinished()
{
    if(!edit_flag) {
        ui->lineEdit_066->setStyleSheet("background-color:rgba(255,255,255,255)");
    } else {
        ui->lineEdit_066->setStyleSheet("background-color:rgba(255,0,0,255)");
    }

    if(checkInput(ui->lineEdit_066->text(), 65) == false) {
    QMessageBox::information(NULL, "警告", "输入不合法，请检查！！！");
    }
}



















