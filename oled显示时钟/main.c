#include"i2c.h"
#include"oledchar.h"
#include"ds1302.h"

                   

uchar  singletime[13];

void display()
{	 
     //time_change();
   	 singletime[0]=TIME[6]/16;//年的十位
	 singletime[1]=TIME[6]%16;//年的个位
	 singletime[2]=TIME[4]/16;//月的十位
	 singletime[3]=TIME[4]%16;//月的个位
	 singletime[4]=TIME[3]/16;//日的十位
	 singletime[5]=TIME[3]%16;//日的个位
	 singletime[6]=TIME[2]/16;//时的十位，24时制
	 singletime[7]=TIME[2]%16;//时的个位
	 singletime[8]=TIME[1]/16;//分的十位
	 singletime[9]=TIME[1]%16;//分的个位
	 singletime[10]=TIME[0]/16;//秒的十位
	 singletime[11]=TIME[0]%16;//秒的个位
	 singletime[12]=TIME[5]%16;//星期几



}



void main()
{
     
     uchar i,j,k;
	
	 oled_initial(); 
     Ds1302Init();
	 
	



	for(i=2;i<6;i++)//显示简易时钟四个字
	{
	  oled_put_char_16x16(i,0,1);
	  for(j=0;j<32;j++)
	  {
	    oled_Write_data(zifu[i-2][j]);
	  }

	}
	 
	 for(i=0;i<3;i++)//显示年月日三个字符
	 {
	    oled_put_char_16x16(2+2*i,1,1);
		for(j=0;j<32;j++)
		{
		oled_Write_data(zifu[i+4][j]);
		}
	 }

	 for(i=0;i<2;i++)//显示星期字符
	 {
	      oled_put_char_16x16(2+i,2,1);
		  
		  for(j=0;j<32;j++)
		  {	
		    	    oled_Write_data(zifu[i+7][j]);
		 		
				    
		  }

	 }

	 for(i=0;i<2;i++)//显示冒号
	 {
	    oled_put_char_16x16(6+3*i,3,0);
		for(j=0;j<16;j++)
		{
		  oled_Write_data(number[25][j]);
		}
	 }


	 for(i=0;i<2;i++)//显示年份的前两位20
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

	 

	 for(k=0;k<3;k++)//显示年年月日数字
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
	 
	  oled_Write_data(zifu[8+singletime[12]][j]);//显示星期几
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