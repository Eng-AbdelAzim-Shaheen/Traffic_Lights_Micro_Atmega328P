/*
 * Traffic_Lights_C.c
 *
 * Created: 12/27/2022 6:19:08 PM
 * Author : Eng AbdelAzim Shaheen
 */ 

#define F_CPU 1035000UL
#include <avr/io.h>
#include <util/delay.h>

void count(int x)
{
	//0bvgfedcba 7-Segment Zero for Active
	int Seg[]={0b1000000,0b1111001,0b0100100,0b0110000,0b0011001,0b0010010,0b0000010,0b1111000,0b0000000,0b0010000};
	int y =0 ;
	
	if (x==3) {y=2;}
	else if (x==7) {y=9;}
	
	for(; x>0 ;x--)
	{
		if (PORTC==(PORTC|(1<<0)) && PORTC==(PORTC|(1<<5))) 
		{
			// R1 G2
			PORTB= Seg[y];
			PORTD= Seg[y-3];	
		}
		else if (PORTC==(PORTC|(1<<0)) && PORTC==(PORTC|(1<<4)))
		{
			// R1 Y2
			PORTB= Seg[y];
			PORTD= Seg[y];
		}
		else if (PORTC==(PORTC|(1<<2)) && PORTC==(PORTC|(1<<3)))
		{
			// G1 R2
			PORTB= Seg[y-3];
			PORTD= Seg[y];
		}
		else if (PORTC==(PORTC|(1<<1)) && PORTC==(PORTC|(1<<3)))
		{
			// Y1 R2
			PORTB= Seg[y];
			PORTD= Seg[y];
		}
		else if (PORTC==(PORTC|(1<<0)) && PORTC==(PORTC|(1<<3)))
		{
			// R1 R2
			PORTB= Seg[y];
			PORTD= Seg[y];
		}
		y--;
		_delay_ms(1000);
	}
}

int main(void)
{
	DDRB=0X7F;
	DDRC=0XFF;
	DDRD=0X7F;
	
    while (1) 
    {
			//     2GYRGYR1
			PORTC=0B100001; // R1 G2
			count(7);
			PORTC=0B010001; // R1 Y2
			count(3);
			PORTC=0B001100; // G1 R2
			count(7);
			PORTC=0B001010; // Y1 R2
			count(3);
    }
}

