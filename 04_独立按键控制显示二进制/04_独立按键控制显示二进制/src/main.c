
#include <reg51.h>
sbit P31=P3^1;
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
 
void main()
{
	unsigned char LEDNum=0;  // char max num is 255
	while(1)
	{
	if(P31==0)
	{
		Delay(20);
		while(P31==0);
		Delay(20);
		LEDNum++;
		P2=~LEDNum;
	}
	}
}
