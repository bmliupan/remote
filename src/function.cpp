#include "inc/function.h"
#include <QFileDialog>
#include <QDataStream>
#include <qdatetime.h>

int char2int(char data)
{
    char t[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    for (int i = 0; i < 16; i ++) {
        if (data == t[i]) return i;
    }
    return 100;
}


bool checkInput(QString text, int num)
{
    char *s = NULL;
    int numH = 100, numL = 100;
    keyFlag[num] = nonInputFlag; //初始标记没有输入
    QByteArray ba = text.toLatin1();
    s = ba.data();
    int length = strlen(s);
    if (length > 3) return false;
    for (int i = 0; i < length; i ++){
        if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 32; // 将小写字母改成大写
    }
    if (s[0] == 'S' && s[1] == 'E' && s[2] == 'T') {
        keyFlag[num] = setFlag; //如果输入字符为set，则将其设为设置键
        return true;
    }
    if (length == 0) {
        keyFlag[num] = nonInputFlag;
        return true;
    }
    if (length == 2) {
        numH = char2int(s[0]);
        numL = char2int(s[1]);
        if (numH > 15 || numL > 15) {
            keyFlag[num] = invalidFlag;
            return false;
        }
        keyValue[num] = (numH * 16) + numL;     //保存按键数据
        keyFlag[num] = edit_flag;               //保存标记
        return true;
    }
    keyFlag[num] = invalidFlag;
    return false;
}

uint16_t calculate_verifycode(QByteArray dataBuff)
{
    uint16_t buffCode = 0;
    uint8_t xorNum[4] = {0};
    for (int i = 0; i < dataBuff.size(); ) {
        xorNum[3] = xorNum[3] ^ dataBuff[i++];
        xorNum[2] = xorNum[2] ^ dataBuff[i++];
        xorNum[1] = xorNum[1] ^ dataBuff[i++];
        xorNum[0] = xorNum[0] ^ dataBuff[i++];
    }
    buffCode = xorNum[3] * 0x1000 + xorNum[2] * 0x0100 + xorNum[1] * 0x0010 + xorNum[0] * 0x0001;
    return buffCode;
}

uint8_t getFormatNum(QString format)
{
    uint8_t i = 0;
    for (i = 0; i < 47; i++) {
        if(formatStr[i] == format)return i;
    }
    return 100;
}

uint16_t setStateIO(uint8_t pin, IOState state)
{
    if (pin == 1) return 0;
    return ioPinState[state][pin - 2];
}

uint16_t setLevelIO(uint8_t pin, IOLevel level)
{
    if (pin == 1) return 0;
    return ioPinLevel[level][pin - 2];
}


uint16_t judgeIO(uint8_t pin)
{
    if (pin >13 || pin < 3) return  0;
    return ioData[pin - 3];
}
