#include"i2c.h"
#include"oledchar.h"
#include"ds1302.h"

                   

uchar  singletime[13];

void display()
{	 
     //time_change();
   	 singletime[0]=TIME[6]/16;//���ʮλ
	 singletime[1]=TIME[6]%16;//��ĸ�λ
	 singletime[2]=TIME[4]/16;//�µ�ʮλ
	 singletime[3]=TIME[4]%16;//�µĸ�λ
	 singletime[4]=TIME[3]/16;//�յ�ʮλ
	 singletime[5]=TIME[3]%16;//�յĸ�λ
	 singletime[6]=TIME[2]/16;//ʱ��ʮλ��24ʱ��
	 singletime[7]=TIME[2]%16;//ʱ�ĸ�λ
	 singletime[8]=TIME[1]/16;//�ֵ�ʮλ
	 singletime[9]=TIME[1]%16;//�ֵĸ�λ
	 singletime[10]=TIME[0]/16;//���ʮλ
	 singletime[11]=TIME[0]%16;//��ĸ�λ
	 singletime[12]=TIME[5]%16;//���ڼ�



}



void main()
{
     
     uchar i,j,k;
	
	 oled_initial(); 
     Ds1302Init();
	 
	



	for(i=2;i<6;i++)//��ʾ����ʱ���ĸ���
	{
	  oled_put_char_16x16(i,0,1);
	  for(j=0;j<32;j++)
	  {
	    oled_Write_data(zifu[i-2][j]);
	  }

	}
	 
	 for(i=0;i<3;i++)//��ʾ�����������ַ�
	 {
	    oled_put_char_16x16(2+2*i,1,1);
		for(j=0;j<32;j++)
		{
		oled_Write_data(zifu[i+4][j]);
		}
	 }

	 for(i=0;i<2;i++)//��ʾ�����ַ�
	 {
	      oled_put_char_16x16(2+i,2,1);
		  
		  for(j=0;j<32;j++)
		  {	
		    	    oled_Write_data(zifu[i+7][j]);
		 		
				    
		  }

	 }

	 for(i=0;i<2;i++)//��ʾð��
	 {
	    oled_put_char_16x16(6+3*i,3,0);
		for(j=0;j<16;j++)
		{
		  oled_Write_data(number[25][j]);
		}
	 }


	 for(i=0;i<2;i++)//��ʾ��ݵ�ǰ��λ20
	 {
	    oled_put_char_16x16(i,1,0);
		for(j=0;j<16;j++)
		{
		  oled_Write_data(number[17-2*i][j]);
		}
	 }

	 while(1)
	 {
	 
        Ds1302ReadTime();
		time_change();
	    display();

	 

	 for(k=0;k<3;k++)//��ʾ������������
	 {
	 for(i=0;i<2;i++)
	 {
	   	oled_put_char_16x16(i+2+4*k,1,0);
		for(j=0;j<16;j++)
		{ 
		   oled_Write_data(number[15+singletime[i+2*k]][j]);
		}
	 }
	 }

	  oled_put_char_16x16(4,2,1);
	  for(j=0;j<32;j++)
	  {
	 
	  oled_Write_data(zifu[8+singletime[12]][j]);//��ʾ���ڼ�
	  }


	 
	 
	 
	 for(k=0;k<3;k++)
	 {
	 for(i=0;i<2;i++)
	 {
	   	oled_put_char_16x16(i+4+3*k,3,0);
		for(j=0;j<16;j++)
		{ 
		   oled_Write_data(number[15+singletime[i+2*k+6]][j]);
		}
	 }
	 }

	 }
	
	 


	
	
	

		
}