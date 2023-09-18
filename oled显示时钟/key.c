#include"key.h"


uchar status=0;
uchar flag=0;

void key1()
{  
   k1=1;
   if(k1==0)
   {
     delay(1000);//延时10微秒
	 if(k1==1)
	 {
	   	flag=!flag;
	 }
	 while(!k1);
   }
  
}

void key2()//选择变量
{
  k2=1;
  if(k2==0&&flag==1)
  {
     delay(1000);
	 if(k2==0)
	 {
	   status++;
	   status=status%6;//status从0到5
	   //0代表年，1代表月，2代表日，3代表时，4代表分，5代表秒
	 }
	 while(!k2);
  }
}

void key3()//加
{
  k3=1;
  if(k3==0&&flag==1)
  {
    delay(1000);
	if(k3==0)
	{
	  switch(status)
	  {
	    case 0:TIME2[0]++;//年
		        if(TIME2[0]==100)
				TIME2[0]=0;
				break;
		case 1: TIME2[2]++;//月
		        TIME[2]=TIME[2]%13;
				break;
	    case 2: TIME2[3]++;	//日
		        if(TIME2[2]%2==1)//如果是单月
				   TIME2[3]%=32;
				if(TIME2[2]%2==0&&TIME2[2]!=2)//如果为不是2的双月
				   TIME2[3]%=31;
				if(TIME2[2]==2&&TIME2[0]%4==0)//如果为闰月
	  			   TIME2[3]%=30;
				else			//如果为平月
				   TIME2[3]%=29;
                break;

		case 3:	TIME2[4]++;	//时
		        TIME2[4]%=24;
				break;
		case 4: TIME2[5]++;//分
		        TIME2[5]%= 60;
				break;
		case 5 : TIME2[6]++; //秒
		         TIME2[6]%=60;
				 break;

	   }
	}
	while(!k3);
  }
}

