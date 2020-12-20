#ifndef LTFILEPARAMETER_H
#define LTFILEPARAMETER_H
#include <QApplication>

//初始化模块
#define    IO_P1UPRE_ADDR                          100+4*0x0D17
#define    IO_P2UPRE_ADDR                          100+4*0x0D19
#define    IO_P1TSM_ADDR                           100+4*0x0D1B
#define    IO_P2TSM_ADDR                           100+4*0x0D1D
#define    IO_P1WAKE_ADDR                          100+4*0x0D1F
#define    IO_P2WAKE_ADDR                          100+4*0x0D21
#define    IO_P1MODE_ADDR                          100+4*0x0D23
#define    IO_P2MODE_ADDR                          100+4*0x0D25
#define    IO_P1DATA_ADDR                          100+4*0x0D27
#define    IO_P2DATA_ADDR                          100+4*0x0D29

//按键扫描模块
#define    KEY_START_ADDR                          100+4*0x0092
#define    KEY_P2MODE_ADDR                         100+4*0x0099
#define    KEY_P1MODE_ADDR                         100+4*0x009C
#define    KEY_P2DATA_ADDR                         100+4*0x00A0
#define    KEY_P1DATA_ADDR                         100+4*0x00A3
#define    CHECK_IO_ADDR                           100+4*0x00AA

//小红灯亮灭模块
#define    LIGHT_ON_M_ADDR                         100+4*0x0DD0
#define    LIGHT_ON_D_ADDR                         100+4*0x0DD1
#define    LIGHT_OFF_M_ADDR                        100+4*0x0DD3
#define    LIGHT_OFF_D_ADDR                        100+4*0x0DD4

//学习时红灯闪烁方法模块                
#define    LEARN_KEY_PRESS_ADDR                    100+4*0x04C0
#define    LEARN_KEY_FREE_ADDR                     100+4*0x04D2
#define    LEARN_WAIT_IR_ADDR                      100+4*0x0512

//编码格式用户码按键键值
#define    KEY_DATA_ADDR                           100+4*0x0E1C
#define    TV_USER_FORMAT_ADDR                     100+4*0x0E6A
#define    TV_USER_CODE1_ADDR                      100+4*0x0E6C
#define    TV_USER_CODE2_ADDR                      100+4*0x0E6E
#define    TV_USER_CODE3_ADDR                      100+4*0x0E70
#define    TV_USER_CODE4_ADDR                      100+4*0x0E72
#define    STB_USER_FORMAT_ADDR                    100+4*0x0E75
#define    STB_USER_CODE1_ADDR                     100+4*0x0E77
#define    STB_USER_CODE2_ADDR                     100+4*0x0E79
#define    STB_USER_CODE3_ADDR                     100+4*0x0E7B
#define    STB_USER_CODE4_ADDR                     100+4*0x0E7D

//学习设置键和学习按键配置
#define    SET_KEY_ADDR1                           100+4*0x0048
#define    SET_KEY_ADDR2                           100+4*0x04BE
#define    SET_KEY_ADDR3                           100+4*0x04C4
#define    SET_KEY_ADDR4                           100+4*0x04DC
#define    LEARN_KEY_ADDR                          100+4*0x0E8A
#define    SET_OUTPUT_ADDRS1                       100+4*0x04B0
#define    SET_OUTPUT_ADDRS2                       100+4*0x04B1
#define    SET_INPUT_SADDR                         100+4*0x04B6
#define    SET_OUTPUT_ADDR1                        100+4*0x04FC
#define    SET_OUTPUT_ADDR2                        100+4*0x04FD
#define    SET_OUTPUT_ADDR3                        100+4*0x04FE
#define    SET_OUTPUT_ADDR4                        100+4*0x04FF
#define    SET_INPUT_ADDR                          100+4*0x0509

#endif // LTFILEPARAMETER_H
