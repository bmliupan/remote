#include "inc/data.h"

bool toggleState = true;
bool display_flag = true; //序号显示与否标记位
uint8_t edit_flag = normalFlag; //编辑模式标记
uint8_t keyValue[66] = {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,\
                       0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,\
                       0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,\
                       0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,\
                       0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,\
                       0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,\
                       0xff,0xff,0xff,0xff,0xff,0xff}; //保存键值

uint8_t keyFlag[66] = {nonInputFlag,nonInputFlag,nonInputFlag,nonInputFlag,nonInputFlag,\
                       nonInputFlag,nonInputFlag,nonInputFlag,nonInputFlag,nonInputFlag,\
                       nonInputFlag,nonInputFlag,nonInputFlag,nonInputFlag,nonInputFlag,\
                       nonInputFlag,nonInputFlag,nonInputFlag,nonInputFlag,nonInputFlag,\
                       nonInputFlag,nonInputFlag,nonInputFlag,nonInputFlag,nonInputFlag,\
                       nonInputFlag,nonInputFlag,nonInputFlag,nonInputFlag,nonInputFlag,\
                       nonInputFlag,nonInputFlag,nonInputFlag,nonInputFlag,nonInputFlag,\
                       nonInputFlag,nonInputFlag,nonInputFlag,nonInputFlag,nonInputFlag,\
                       nonInputFlag,nonInputFlag,nonInputFlag,nonInputFlag,nonInputFlag,\
                       nonInputFlag,nonInputFlag,nonInputFlag,nonInputFlag,nonInputFlag,\
                       nonInputFlag,nonInputFlag,nonInputFlag,nonInputFlag,nonInputFlag,\
                       nonInputFlag,nonInputFlag,nonInputFlag,nonInputFlag,nonInputFlag,\
                       nonInputFlag,nonInputFlag,nonInputFlag,nonInputFlag,nonInputFlag,\
                       nonInputFlag}; //保存按键模式标记

uint8_t userCode[4] = {0};

uint8_t translate[66] = {
    55,56,57,58,59,60,61,62,63,64,65,\
    45,46,47,48,49,50,51,52,53,54,\
    36,37,38,39,40,41,42,43,44,\
    28,29,30,31,32,33,34,35,\
    21,22,23,24,25,26,27,\
    15,16,17,18,19,20,\
    10,11,12,13,14,\
     6, 7, 8, 9,\
     3, 4, 5,\
     1, 2,\
     0
};

uint8_t translist[66] = {
    65,\
    63,64,\
    60,61,62,\
    56,57,58,59,\
    51,52,53,54,55,\
    45,46,47,48,49,50,\
    38,39,40,41,42,43,44,\
    30,31,32,33,34,35,36,37,\
    21,22,23,24,25,26,27,28,29,\
    11,12,13,14,15,16,17,18,19,20,\
     0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10
};


