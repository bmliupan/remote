#ifndef DATA_H
#define DATA_H
#include    <qapplication.h>

enum FlagType {
    normalFlag,     //机顶盒按键输入标记
    learnFlag,      //学习按键输入标记
    setFlag,        //设置键输入标记
    invalidFlag,    //无效输入标记
    nonInputFlag    //没有输入
};

enum ErrorType {
    E_OVER_LENGTH,      //输入字符超长
    E_OVER_LEARNKEY    //超出最大可支持学习按键数
};

enum IOState {
    inState,
    OutState
};

enum IOLevel {
    lowLevel,
    highLevel
};

extern bool toggleState;
extern bool display_flag;
extern uint8_t edit_flag;
extern uint8_t powerKey;
extern uint8_t exitKey1;
extern uint8_t exitKey2;
extern uint16_t keyValue[78];
extern uint8_t keyFlag[78];
extern uint8_t translate[78];
extern uint8_t translist[78];
extern uint8_t userCodeSTB[8];
extern uint8_t userCodeTV[8];
extern QString formatSTB;
extern QString formatTV;
extern QString formatStr[];
extern uint16_t ioPinState[2][13];
extern uint16_t ioPinLevel[2][13];
extern uint16_t ioData[12];
extern QString pinA[13];
extern QString pinB[13];
extern int axes[78][2];
extern int newAxes[78][2];
extern const QStringList keyList;

#define MaxLearnKeyNum  10;

#endif // DATA_H
