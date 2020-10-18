#ifndef LTFILEPARAMETER_H
#define LTFILEPARAMETER_H
#include <QApplication>

//初始化模块
#define    IO_P2UPRE_ADDR                          100+4*0x0CF3
#define    IO_P1TSM_ADDR                           100+4*0x0CF5
#define    IO_P2TSM_ADDR                           100+4*0x0CF7
#define    IO_P1WAKE_ADDR                          100+4*0x0CF9
#define    IO_P2WAKE_ADDR                          100+4*0x0CFC
#define    IO_P1MODE_ADDR                          100+4*0x0CFF
#define    IO_P2MODE_ADDR                          100+4*0x0D01
#define    IO_P1DATA_ADDR                          100+4*0x0D03
#define    IO_P2DATA_ADDR                          100+4*0x0D05

//按键扫描模块
#define    KEY_P2MODE_ADDR                         100+4*0x0099
#define    KEY_P1MODE_ADDR                         100+4*0x009C
#define    KEY_P2DATA_ADDR                         100+4*0x00A0
#define    KEY_P1DATA_ADDR                         100+4*0x00A2

//小红灯亮灭模块
#define    LIGHT_ON_M_ADDR                         100+4*0x0DAC
#define    LIGHT_ON_D_ADDR                         100+4*0x0DAD
#define    LIGHT_OFF_M_ADDR                        100+4*0x0DAF
#define    LIGHT_OFF_D_ADDR                        100+4*0x0DB0

//学习时红灯闪烁方法模块                
#define    LEARN_KEY_PRESS_ADDR                    100+4*0x04A1
#define    LEARN_KEY_FREE_ADDR                     100+4*0x04B3
#define    LEARN_WAIT_IR_ADDR                      100+4*0x04F3

//编码格式用户码按键键值
#define    KEY_DATA_ADDR                           100+4*0x0DF8
#define    TV_USER_FORMAT_ADDR                     100+4*0x0E3A
#define    TV_USER_CODE1_ADDR                      100+4*0x0E3C
#define    TV_USER_CODE2_ADDR                      100+4*0x0E3E
#define    TV_USER_CODE3_ADDR                      100+4*0x0E40
#define    TV_USER_CODE4_ADDR                      100+4*0x0E42
#define    STB_USER_FORMAT_ADDR                    100+4*0x0E45
#define    STB_USER_CODE1_ADDR                     100+4*0x0E47
#define    STB_USER_CODE2_ADDR                     100+4*0x0E49
#define    STB_USER_CODE3_ADDR                     100+4*0x0E4B
#define    STB_USER_CODE4_ADDR                     100+4*0x0E4D

//学习设置键和学习按键配置
#define    SET_KEY_ADDR1                           100+4*0x0049
#define    SET_KEY_ADDR2                           100+4*0x049F
#define    SET_KEY_ADDR3                           100+4*0x04A5
#define    SET_KEY_ADDR4                           100+4*0x04BD
#define    LEARN_KEY_ADDR                          100+4*0x0E5A
#define    SET_OUTPUT_ADDR1                        100+4*0x04DD
#define    SET_OUTPUT_ADDR2                        100+4*0x04DE
#define    SET_OUTPUT_ADDR3                        100+4*0x04DF
#define    SET_OUTPUT_ADDR4                        100+4*0x04E0
#define    SET_INPUT_ADDR                          100+4*0x04EA

#endif // LTFILEPARAMETER_H
