#include"key.h"


uchar status=0;
uchar flag=0;
uchar a;
int CaculateWeekDay(int y,int m, int d) //根据年月日来计算星期几,三个参数代表年月日,基姆拉尔森计算公式
{
 int iWeek;
if(m==1||m==2) {
m+=12;
y--;
}
 iWeek=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;//0-1，星期一到星期日
  return iWeek;

} 

void inint1()//中断1
{
    EA=1;
	EX1=1;
	IT1=1;


}

void int1()interrupt 2
{
   delay(1000);
   if(k4==0)
   {
    status=0;
    flag=!flag;
	if(flag==0)
	Ds1302Init();
	
   }
}





void key3()//选择变量
{
  k3=1;
  if(k3==0)
  {
     delay(1000);
	 if(k3==0)
	 {
	   status++;
	   status=status%6;//status从0到5
	   //5代表年，4代表月，3代表日，2代表时，1代表分，0代表秒
	 }
	 while(!k3);
  }
}

void key1()//加
{
  k1=1;
  if(k1==0)
  {
    delay(500);
	if(k1==0)
	{
	  TIME[status]++;
	  if((TIME[status]&0x0f)>9)
	  TIME[status]=TIME[status]+6;//换成bcd码
	  if(TIME[0]>0x59)TIME[0]=0;
	  if(TIME[1]>0x59)TIME[1]=0;
	  if(TIME[2]>0x23)TIME[2]=0;

	  if(TIME[4]%2==1)//月份为单月
	  {
	  if(TIME[3]>0x31)TIME[3]=1;
	  }
	    if(TIME[4]%2==0&&TIME[5]!=2)//月份为不为0的双月
	    {
	    if(TIME[3]>0x30)TIME[3]=1;
	    }
		  if(TIME[5]%4==0&&TIME[5]==2)//月份为闰月
	      {
	      if(TIME[3]>0x29)TIME[3]=1;
	      }  
		   if(TIME[5]%4!=0&&TIME[5]==2)//月份为平月
	       {
	        if(TIME[3]>0x28)TIME[3]=1;
	       } 
	  if(TIME[4]>0x12)TIME[4]=1;
	  if(TIME[5]>0x99)TIME[5]=0;
	   
	}
	while(!k3);
  }
}

void key2()//减
{
   k2=1;
   if(k2==0)
   {
      delay(1000);
	  if(k2==0)
	  {
	  if(TIME[0]==0||TIME[1]==0||TIME[2]==0||TIME[3]==1||TIME[4]==1||TIME[5]==1)a=1;
	  if(TIME[0]==0&&a==1)TIME[0]=0x60;
	  if(TIME[1]==0&&a==1)TIME[1]=0x60;
	  if(TIME[2]==0&&a==1)TIME[2]=0x24;

	  if(TIME[4]%2==1)//月份为单月
	  {
	  if(TIME[3]==1&&a==1)TIME[3]=0x32;
	  }
	    if(TIME[4]%2==0&&TIME[5]!=2)//月份为不为0的双月
	    {
	    if(TIME[3]==1||a==1)TIME[3]=0x31;
	    }
		  if(TIME[5]%4==0&&TIME[5]==2)//月份为闰月
	      {
	      if(TIME[3]==1&&a==1)TIME[3]=0x30;
	      }  
		   if(TIME[5]%4!=0&&TIME[5]==2)//月份为平月
	       {
	        if(TIME[3]==1&&a==1)TIME[3]=0x29;
	       } 
	  if(TIME[4]==1&&a==1)TIME[4]=0x13;
	  if(TIME[5]==0&&a==1)TIME[5]=0xa0;
	  TIME[status]--;
	  if((TIME[status]&0x0f)>9)
	  TIME[status]=TIME[status]-6;//换成bcd码
	  
	  }
	  while(!k2);
   }
}

