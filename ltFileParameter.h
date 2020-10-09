#ifndef LTFILEPARAMETER_H
#define LTFILEPARAMETER_H
#include <QApplication>

//初始化模块
#define IO_P1UPRE_ADDR  100+4*0x100
#define IO_P2UPRE_ADDR  100+4*0x100
#define IO_P1TSM_ADDR   100+4*0x100
#define IO_P2TSM_ADDR   100+4*0x100
#define IO_P1WAKE_ADDR  100+4*0x100
#define IO_P2WAKE_ADDR  100+4*0x100
#define IO_P1MODE_ADDR  100+4*0x100
#define IO_P2MODE_ADDR  100+4*0x100
#define IO_P1DATA_ADDR  100+4*0x100
#define IO_P2DATA_ADDR  100+4*0x100

//按键扫描模块
#define KEY_P2MODE_ADDR 100+4*0x100
#define KEY_P1MODE_ADDR 100+4*0x100
#define KEY_P2DATA_ADDR 100+4*0x100
#define KEY_P1DATA_ADDR 100+4*0x100

//小红灯亮灭模块
#define LIGHT_ON_M_ADDR 100+4*0x100
#define LIGHT_ON_D_ADDR 100+4*0x100
#define LIGHT_OFF_M_ADDR 100+4*0x100
#define LIGHT_OFF_D_ADDR 100+4*0x100

//学习时红灯闪烁方法模块
#define LEARN_KEY_PRESS_ADDR        100+4*0x100
#define LEARN_KEY_FREE_ADDR         100+4*0x100
#define LEARN_WAIT_IR_ADDR          100+4*0x100

//编码格式用户码按键键值
#define KEY_DATA_ADDR               100+4*0x100
#define TV_USER_FORMAT_ADDR         100+4*0x100
#define TV_USER_CODE1_ADDR          100+4*0x100
#define TV_USER_CODE2_ADDR          100+4*0x100
#define TV_USER_CODE3_ADDR          100+4*0x100
#define TV_USER_CODE4_ADDR          100+4*0x100
#define STB_USER_FORMAT_ADDR         100+4*0x100
#define STB_USER_CODE1_ADDR          100+4*0x100
#define STB_USER_CODE2_ADDR          100+4*0x100
#define STB_USER_CODE3_ADDR          100+4*0x100
#define STB_USER_CODE4_ADDR          100+4*0x100

//学习设置键和学习按键配置
#define SET_KEY_ADDR1                  100+4*0x100
#define SET_KEY_ADDR2                  100+4*0x100
#define SET_KEY_ADDR3                  100+4*0x100
#define SET_KEY_ADDR4                  100+4*0x100
#define LEARN_KEY_ADDR                 100+4*0x100
#define SET_OUTPUT_ADDR                 100+4*0x100
#define SET_INPUT_ADDR                  100+4*0x100



#endif // LTFILEPARAMETER_H
