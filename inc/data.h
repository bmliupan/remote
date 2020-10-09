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

extern bool toggleState;
extern bool display_flag;
extern uint8_t edit_flag;
extern uint8_t keyValue[66];
extern uint8_t keyFlag[66];
extern uint8_t userCode[4];
extern uint8_t translate[66];
extern uint8_t translist[66];

#define MaxLearnKeyNum  7;

#endif // DATA_H
