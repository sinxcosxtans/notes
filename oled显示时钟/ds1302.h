#ifndef __DS1302_H_
#define __DS1302_H_

//---����ͷ�ļ�---//
#include<reg52.h>
#include<intrins.h>
#include"i2c.h"


//---�ض���ؼ���---//


//---����ds1302ʹ�õ�IO��---//
sbit DSIO=P3^4;
sbit RST=P3^5;
sbit SCLK=P3^6;

//---����ȫ�ֺ���---//
void Ds1302Write(uchar addr, uchar dat);
uchar Ds1302Read(uchar addr);
void Ds1302Init();
void Ds1302ReadTime();
void time_change();



//---����ȫ�ֱ���--//
extern uchar TIME[7];
extern uchar TIME2[7];	

#endif