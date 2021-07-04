#ifndef FUNCTION_H
#define FUNCTION_H
#include <QApplication>
#include "data.h"

int char2int(char data);
bool checkInput(QString text, int num);
uint16_t calculate_verifycode(QByteArray dataBuff);
uint8_t getFormatNum(QString format);
void getKeyPin(uint8_t key, QString *pin, uint8_t *pinV1, uint8_t *pinV2);
uint8_t get_Current_LearnKey_Num(void);
uint8_t get_Current_LearnSetKey_Num(void);
uint8_t get_Current_LearnExitKey_Num(void);

#endif // FUNCTION_H
