#include "inc/data.h"

bool toggleState = true;
bool display_flag = true; //序号显示与否标记位
uint8_t edit_flag = normalFlag; //编辑模式标记
uint16_t keyValue[66] = {0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,\
                       0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,\
                       0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,\
                       0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,\
                       0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,\
                       0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,\
                       0xffff,0xffff,0xffff,0xffff,0xffff,0xffff}; //保存键值

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

uint8_t userCodeSTB[8] = {0};
uint8_t userCodeTV[8] = {0};
QString formatSTB = "";
QString formatTV = "";

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

uint8_t listenIO[66][2] = {
    {1,3},    //0
    {1,4},    //1
    {1,5},    //2
    {1,6},    //3
    {1,7},    //4
    {1,8},    //5
    {1,9},    //6
    {1,10},    //7
    {1,11},    //8
    {1,12},    //9
    {1,13},    //10
    {13,3},    //11
    {13,4},    //12
    {13,5},    //13
    {13,6},    //14
    {13,7},    //15
    {13,8},    //16
    {13,9},    //17
    {13,10},    //18
    {13,11},    //19
    {13,12},    //20
    {12,3},    //21
    {12,4},    //22
    {12,5},    //23
    {12,6},    //24
    {12,7},    //25
    {12,8},    //26
    {12,9},    //27
    {12,10},    //28
    {12,11},    //29
    {11,3},    //30
    {11,4},    //31
    {11,5},    //32
    {11,6},    //33
    {11,7},    //34
    {11,8},    //35
    {11,9},    //36
    {11,10},    //37
    {10,3},    //38
    {10,4},    //39
    {10,5},    //40
    {10,6},    //41
    {10,7},    //42
    {10,8},    //43
    {10,9},    //44
    {9,3},    //45
    {9,4},    //46
    {9,5},    //47
    {9,6},    //48
    {9,7},    //49
    {9,8},    //50
    {8,3},    //51
    {8,4},    //52
    {8,5},    //53
    {8,6},    //54
    {8,7},    //55
    {7,3},    //56
    {7,4},    //57
    {7,5},    //58
    {7,6},    //59
    {6,3},    //60
    {6,4},    //61
    {6,5},    //62
    {5,3},    //63
    {5,4},    //64
    {4,3}    //65
};

uint16_t ioData[11] = {
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
