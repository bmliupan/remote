#ifndef FUNCTION_H
#define FUNCTION_H
#include <QApplication>


int char2int(char data);
bool checkInput(QString text, int num);
uint16_t calculate_verifycode(QByteArray dataBuff);
#endif // FUNCTION_H
