#ifndef __KEY_H_
#define __KEY_H_
#include"i2c.h"
#include"ds1302.h"
#include<reg52.h>



sbit k2=P3^0;
sbit k3=P3^2;
sbit k4=P3^3;
sbit k1=P3^1;
extern uchar status;
extern  uchar flag;

void key1();
void key2();
void key3();
void inint1();
void int1();
int CaculateWeekDay(int y,int m, int d);



#endif