#ifndef LTFILEPARAMETER_H
#define LTFILEPARAMETER_H
#include <QApplication>

//初始化模块
#define    IO_P1UPRE_ADDR                          100+4*0x0DF9
#define    IO_P2UPRE_ADDR                          100+4*0x0DFB
#define    IO_P1TSM_ADDR                           100+4*0x0DFD
#define    IO_P2TSM_ADDR                           100+4*0x0DFF
#define    IO_P1WAKE_ADDR                          100+4*0x0E01
#define    IO_P2WAKE_ADDR                          100+4*0x0E03
#define    IO_P1MODE_ADDR                          100+4*0x0E05
#define    IO_P2MODE_ADDR                          100+4*0x0E07
#define    IO_P1DATA_ADDR                          100+4*0x0E09
#define    IO_P2DATA_ADDR                          100+4*0x0E0B

//按键扫描模块
#define    KEY_START_ADDR                          100+4*0x0092
#define    KEY_P2MODE_ADDR                         100+4*0x0099
#define    KEY_P1MODE_ADDR                         100+4*0x009C
#define    KEY_P2DATA_ADDR                         100+4*0x00A0
#define    KEY_P1DATA_ADDR                         100+4*0x00A3
#define    CHECK_IO_ADDR                           100+4*0x00AA

//小红灯亮灭模块
#define    LIGHT_ON_M_ADDR                         100+4*0x0EB2
#define    LIGHT_ON_D_ADDR                         100+4*0x0EB3
#define    LIGHT_OFF_M_ADDR                        100+4*0x0EB5
#define    LIGHT_OFF_D_ADDR                        100+4*0x0EB6

//学习时红灯闪烁方法模块                
#define    LEARN_KEY_PRESS_ADDR                    100+4*0x04C0
#define    LEARN_KEY_FREE_ADDR                     100+4*0x04D2
#define    LEARN_WAIT_IR_ADDR                      100+4*0x0512

//编码格式用户码按键键值
#define    KEY_DATA_ADDR                           100+4*0x0EFE
#define    TV_USER_FORMAT_ADDR                     100+4*0x0F4C
#define    TV_USER_CODE1_ADDR                      100+4*0x0F4E
#define    TV_USER_CODE2_ADDR                      100+4*0x0F50
#define    TV_USER_CODE3_ADDR                      100+4*0x0F52
#define    TV_USER_CODE4_ADDR                      100+4*0x0F54
#define    STB_USER_FORMAT_ADDR                    100+4*0x0F57
#define    STB_USER_CODE1_ADDR                     100+4*0x0F59
#define    STB_USER_CODE2_ADDR                     100+4*0x0F5B
#define    STB_USER_CODE3_ADDR                     100+4*0x0F5D
#define    STB_USER_CODE4_ADDR                     100+4*0x0F5F

//学习设置键和学习按键配置
#define    SET_KEY_ADDR1                           100+4*0x0048
#define    SET_KEY_ADDR2                           100+4*0x04BE
#define    SET_KEY_ADDR3                           100+4*0x04C4
#define    SET_KEY_ADDR4                           100+4*0x04DC
#define    LEARN_KEY_ADDR                          100+4*0x0F6C
#define    SET_OUTPUT_ADDRS1                       100+4*0x04B0
#define    SET_OUTPUT_ADDRS2                       100+4*0x04B1
#define    SET_INPUT_SADDR                         100+4*0x04B6
#define    SET_OUTPUT_ADDR1                        100+4*0x04FC
#define    SET_OUTPUT_ADDR2                        100+4*0x04FD
#define    SET_OUTPUT_ADDR3                        100+4*0x04FE
#define    SET_OUTPUT_ADDR4                        100+4*0x04FF
#define    SET_INPUT_ADDR                          100+4*0x0509

#endif // LTFILEPARAMETER_H
