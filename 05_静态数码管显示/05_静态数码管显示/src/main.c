#include <reg51.h>
 
unsigned char NixieTable[]={
 
0x3f,0x06,0x5b,0x4f,
 
0x66,0x6d,0x7d,0x07,
 
0x7f,0x6f,0x77,0x7c,
 
0x39,0x5e,0x79,0x71, 0x00};
 
 
void Nixie(unsigned char Location,Number)
{
	switch(Location)
	{
		case 1:
			P24=1;P23=1;P22=1;break;
		case 2:
			P24=1;P23=1;P22=0;break;
		case 3:
			P24=1;P23=0;P22=1;break;
		case 4:
			P24=1;P23=0;P22=0;break;
		case 5:
			P24=0;P23=1;P22=1;break;
		case 6:
			P24=0;P23=1;P22=0;break;
		case 7:
			P24=0;P23=0;P22=1;break;
		case 8:
			P24=0;P23=0;P22=0;break;
	}
	P0=NixieTable[Number];
}
 
void main()
{
//	P24=1;  //Controls a nixie tube
//	P23=0;
//	P22=1;
//	P0=0x7D;  //value is 6
	Nixie(2,3);
	while(1)
	{
		
	}
}
十二、单片机实操十：动态数码管显示
1、在指定路径下创建工程并添加新文件

2、编写程序

动态清零，数字消影，来实现动态数码管显示，这是单片机不断扫描来成像的，将耗费大量CPU资源。因此，硬件电路一般会加1640的芯片来驱动，将大量减少扫描带来的CPU损耗。

#include <STC89C5xRC.H>
 
unsigned char NixieTable[]={
 
0x3f,0x06,0x5b,0x4f,
 
0x66,0x6d,0x7d,0x07,
 
0x7f,0x6f,0x77,0x7c,
 
0x39,0x5e,0x79,0x71, 0x00};
 
void Delay(unsigned int xms)		//@12.000MHz
{
	unsigned char i, j;
	while(xms)
	{
	i = 2;
	j = 239;
	do
	{
		while (--j);
	} while (--i);
	xms--;
	}
}
 
void Nixie(unsigned char Location,Number)
{
	switch(Location)
	{
		case 1:
			P24=1;P23=1;P22=1;break;
		case 2:
			P24=1;P23=1;P22=0;break;
		case 3:
			P24=1;P23=0;P22=1;break;
		case 4:
			P24=1;P23=0;P22=0;break;
		case 5:
			P24=0;P23=1;P22=1;break;
		case 6:
			P24=0;P23=1;P22=0;break;
		case 7:
			P24=0;P23=0;P22=1;break;
		case 8:
			P24=0;P23=0;P22=0;break;
	}
	P0=NixieTable[Number];
	Delay(1);  // Shadow elimination
	P0=0x00;  //  reset
}
 
void main()
{
	while(1)
	{
		Nixie(1,1);
		Nixie(2,2);
		Nixie(3,3);
	}
}
