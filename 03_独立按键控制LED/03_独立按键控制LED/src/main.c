#include <reg51.h>
sbit P31=P3^1;
sbit P30=P3^0;
sbit P32=P3^2;
sbit P33=P3^3;
int main(void)
{
    while(1)
    {
        P2=0xFF;
        if(P31==0)
        {
            P2=0xFE;
        }
        else if (P31==1)
        {
            P2=0xFF;
        }
         if(P30==0)
        {
            P2=0xFD;
        }
        else if (P30==1)
        {
            P2=0xFF;
        }
         if(P32==0)
        {
            P2=0xFB;
        }
        else if (P32==1)
        {
            P2=0xFF;
        }
         if(P33==0)
        {
            P2=0xF7;
        }
        else if (P33==1)
        {
            P2=0xFF;
        }
    }
}