#ifndef LTFILEPARAMETER_H
#define LTFILEPARAMETER_H
#include <QApplication>

//初始化模块
#define    IO_P2UPRE_ADDR                          100+4*0x0CE1
#define    IO_P1TSM_ADDR                           100+4*0x0CE3
#define    IO_P2TSM_ADDR                           100+4*0x0CE5
#define    IO_P1WAKE_ADDR                          100+4*0x0CE7
#define    IO_P2WAKE_ADDR                          100+4*0x0CEA
#define    IO_P1MODE_ADDR                          100+4*0x0CED
#define    IO_P2MODE_ADDR                          100+4*0x0CEF
#define    IO_P1DATA_ADDR                          100+4*0x0CF1
#define    IO_P2DATA_ADDR                          100+4*0x0CF3

//按键扫描模块
#define    KEY_P2MODE_ADDR                         100+4*0x0097
#define    KEY_P1MODE_ADDR                         100+4*0x009A
#define    KEY_P2DATA_ADDR                         100+4*0x009E
#define    KEY_P1DATA_ADDR                         100+4*0x00A0

//小红灯亮灭模块
#define    LIGHT_ON_M_ADDR                         100+4*0x0D9A
#define    LIGHT_ON_D_ADDR                         100+4*0x0D9B
#define    LIGHT_OFF_M_ADDR                        100+4*0x0D9D
#define    LIGHT_OFF_D_ADDR                        100+4*0x0D9E

//学习时红灯闪烁方法模块
#define    LEARN_KEY_PRESS_ADDR                    100+4*0x049F
#define    LEARN_KEY_FREE_ADDR                     100+4*0x04B1
#define    LEARN_WAIT_IR_ADDR                      100+4*0x04F1

//编码格式用户码按键键值
#define    KEY_DATA_ADDR                           100+4*0x0DE6
#define    TV_USER_FORMAT_ADDR                     100+4*0x0E28
#define    TV_USER_CODE1_ADDR                      100+4*0x0E2A
#define    TV_USER_CODE2_ADDR                      100+4*0x0E2C
#define    TV_USER_CODE3_ADDR                      100+4*0x0E2E
#define    TV_USER_CODE4_ADDR                      100+4*0x0E30
#define    STB_USER_FORMAT_ADDR                    100+4*0x0E33
#define    STB_USER_CODE1_ADDR                     100+4*0x0E35
#define    STB_USER_CODE2_ADDR                     100+4*0x0E37
#define    STB_USER_CODE3_ADDR                     100+4*0x0E39
#define    STB_USER_CODE4_ADDR                     100+4*0x0E3B

//学习设置键和学习按键配置
#define    SET_KEY_ADDR1                           100+4*0x0049
#define    SET_KEY_ADDR2                           100+4*0x049D
#define    SET_KEY_ADDR3                           100+4*0x04A3
#define    SET_KEY_ADDR4                           100+4*0x04BB
#define    LEARN_KEY_ADDR                          100+4*0x0E48
#define    SET_OUTPUT_ADDR                         100+4*0x04DB
#define    SET_INPUT_ADDR                          100+4*0x04E8

#endif // LTFILEPARAMETER_H