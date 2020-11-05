#include "data.h"

bool toggleState = true;
bool display_flag = true; //序号显示与否标记位
uint8_t edit_flag = normalFlag; //编辑模式标记
uint16_t keyValue[78] = {0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,\
                       0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,\
                       0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,\
                       0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,\
                       0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,\
                       0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,\
                       0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,\
                       0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff}; //保存键值

uint8_t keyFlag[78] = {nonInputFlag,nonInputFlag,nonInputFlag,nonInputFlag,nonInputFlag,\
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
                       nonInputFlag,nonInputFlag,nonInputFlag,nonInputFlag,nonInputFlag,\
                       nonInputFlag,nonInputFlag,nonInputFlag,nonInputFlag,nonInputFlag,\
                       nonInputFlag,nonInputFlag,nonInputFlag}; //保存按键模式标记

uint8_t userCodeSTB[8] = {0};
uint8_t userCodeTV[8] = {0};
QString formatSTB = "";
QString formatTV = "";

uint8_t translate[78] = {
    66,67,68,69,70,71,72,73,74,75,76,77,\
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

uint8_t translist[78] = {
    77,\
    75,76,\
    72,73,74,\
    68,69,70,71,\
    63,64,65,66,67,\
    57,58,59,60,61,62,\
    50,51,52,53,54,55,56,\
    42,43,44,45,46,47,48,49,\
    33,34,35,36,37,38,39,40,41,\
    23,24,25,26,27,28,29,30,31,32,\
    12,13,14,15,16,17,18,19,20,21,22,\
     0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11
};

QString formatStr[] = {
    "3004",
    "50119P",
    "50462",
    "50560",
    "50560X",
    "6014C6X",
    "6014C5X",
    "6122X",
    "6122F",
    "6124C13",
    "6124C8",
    "6124C5",
    "7464",
    "AH5900134K",
    "7051",
    "7461X",
    "9012F",
    "9012X",
    "Custom6Bit",
    "DVB40bit",
    "HuiZhou",
    "JVC",
    "RCMM32",
    "RCMM24",
    "RCA38",
    "RCA56",
    "RCT311",
    "Sharp",
    "TopWay",
    "Y261",
    "MITC8D8",
    "Pioneer",
    "MiBox",
    "DreamDVB",
    "3010P38K",
    "3010P56K",
    "301036K",
    "301038K",
    "GeminiC10",
    "PhilipsRC6",
    "PhilipsRC6_38k",
    "PhilipsRC63",
    "Philips",
    "6014C5",
    "6014C6",
    "7461",
    "6122",
    "9012",
};

uint16_t ioPinState[2][13] = {
    {
    0x60C1, 	//B0BCLR	P1Mode.0
    0x61C1, 	//B0BCLR	P1Mode.1
    0x62C1, 	//B0BCLR	P1Mode.2
    0x63C1, 	//B0BCLR	P1Mode.3
    0x64C1, 	//B0BCLR	P1Mode.4
    0x65C1, 	//B0BCLR	P1Mode.5
    0x66C1, 	//B0BCLR	P1Mode.6
    0x67C1, 	//B0BCLR	P1Mode.7
    0x60C2, 	//B0BCLR	P2Mode.0
    0x61C2, 	//B0BCLR	P2Mode.1
    0x62C2, 	//B0BCLR	P2Mode.2
    0x63C2, 	//B0BCLR	P2Mode.3
    0x64C2   	//B0BCLR	P2Mode.4
    },
    {
    0x68C1, 	//B0BSET	P1Mode.0
    0x69C1, 	//B0BSET	P1Mode.1
    0x6AC1, 	//B0BSET	P1Mode.2
    0x6BC1, 	//B0BSET	P1Mode.3
    0x6CC1, 	//B0BSET	P1Mode.4
    0x6DC1, 	//B0BSET	P1Mode.5
    0x6EC1, 	//B0BSET	P1Mode.6
    0x6FC1, 	//B0BSET	P1Mode.7
    0x68C2, 	//B0BSET	P2Mode.0
    0x69C2, 	//B0BSET	P2Mode.1
    0x6AC2, 	//B0BSET	P2Mode.2
    0x6BC2, 	//B0BSET	P2Mode.3
    0x6CC2   	//B0BSET	P2Mode.4
    }
};

uint16_t ioPinLevel[2][13] = {
    {
    0x60D1, 	//B0BCLR	P1Data.0
    0x61D1, 	//B0BCLR	P1Data.1
    0x62D1, 	//B0BCLR	P1Data.2
    0x63D1, 	//B0BCLR	P1Data.3
    0x64D1, 	//B0BCLR	P1Data.4
    0x65D1, 	//B0BCLR	P1Data.5
    0x66D1, 	//B0BCLR	P1Data.6
    0x67D1, 	//B0BCLR	P1Data.7
    0x60D2, 	//B0BCLR	P2Data.0
    0x61D2, 	//B0BCLR	P2Data.1
    0x62D2, 	//B0BCLR	P2Data.2
    0x63D2, 	//B0BCLR	P2Data.3
    0x64D2   	//B0BCLR	P2Data.4
    },
    {
    0x68D1, 	//B0BSET	P1Data.0
    0x69D1, 	//B0BSET	P1Data.1
    0x6AD1, 	//B0BSET	P1Data.2
    0x6BD1, 	//B0BSET	P1Data.3
    0x6CD1, 	//B0BSET	P1Data.4
    0x6DD1, 	//B0BSET	P1Data.5
    0x6ED1, 	//B0BSET	P1Data.6
    0x6FD1, 	//B0BSET	P1Data.7
    0x68D2, 	//B0BSET	P2Data.0
    0x69D2, 	//B0BSET	P2Data.1
    0x6AD2, 	//B0BSET	P2Data.2
    0x6BD2, 	//B0BSET	P2Data.3
    0x6CD2   	//B0BSET	P2Data.4
    }
};

uint16_t ioData[12] = {
    0x78D1,
    0x79D1,
    0x7AD1,
    0x7BD1,
    0x7CD1,
    0x7DD1,
    0x7ED1,
    0x7FD1,
    0x78D2,
    0x79D2,
    0x7AD2,
    0x7BD2
};

QString pinA[] = {"2","3","4","5","6","7","8","9","10","11","12","13","1"};
QString pinB[] = {"3","4","5","6","7","8","9","10","11","12","13","14","1"};
