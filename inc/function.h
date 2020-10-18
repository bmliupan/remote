#ifndef FUNCTION_H
#define FUNCTION_H
#include <QApplication>
#include "inc/data.h"

int char2int(char data);
bool checkInput(QString text, int num);
uint16_t calculate_verifycode(QByteArray dataBuff);
uint8_t getFormatNum(QString format);
uint16_t setStateIO(uint8_t pin, IOState state);
uint16_t setLevelIO(uint8_t pin, IOLevel level);
uint16_t judgeIO(uint8_t pin);
#endif // FUNCTION_H
