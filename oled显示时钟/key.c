#include"key.h"


uchar status=0;
uchar flag=0;

void key1()
{  
   k1=1;
   if(k1==0)
   {
     delay(1000);//��ʱ10΢��
	 if(k1==1)
	 {
	   	flag=!flag;
	 }
	 while(!k1);
   }
  
}

void key2()//ѡ�����
{
  k2=1;
  if(k2==0&&flag==1)
  {
     delay(1000);
	 if(k2==0)
	 {
	   status++;
	   status=status%6;//status��0��5
	   //0�����꣬1�����£�2�����գ�3����ʱ��4����֣�5������
	 }
	 while(!k2);
  }
}

void key3()//��
{
  k3=1;
  if(k3==0&&flag==1)
  {
    delay(1000);
	if(k3==0)
	{
	  switch(status)
	  {
	    case 0:TIME2[0]++;//��
		        if(TIME2[0]==100)
				TIME2[0]=0;
				break;
		case 1: TIME2[2]++;//��
		        TIME[2]=TIME[2]%13;
				break;
	    case 2: TIME2[3]++;	//��
		        if(TIME2[2]%2==1)//����ǵ���
				   TIME2[3]%=32;
				if(TIME2[2]%2==0&&TIME2[2]!=2)//���Ϊ����2��˫��
				   TIME2[3]%=31;
				if(TIME2[2]==2&&TIME2[0]%4==0)//���Ϊ����
	  			   TIME2[3]%=30;
				else			//���Ϊƽ��
				   TIME2[3]%=29;
                break;

		case 3:	TIME2[4]++;	//ʱ
		        TIME2[4]%=24;
				break;
		case 4: TIME2[5]++;//��
		        TIME2[5]%= 60;
				break;
		case 5 : TIME2[6]++; //��
		         TIME2[6]%=60;
				 break;

	   }
	}
	while(!k3);
  }
}

