/*
 * Display1.cpp
 *
 * Created: 29.09.2021 12:15:10
 * Author : Pavel Bezdelev
 */ 

#include <avr/io.h>
#include "HD44780.h"

HD44780 FirstDisplay; 

uint8_t ArraySymbol[] =
{
	0b00000,
	0b01010,
	0b01010,
	0b00000,
	0b10001,
	0b01110,
	0b00000,
	0b00000,
};

int main(void)
{
	FirstDisplay.Set_Symbol(ArraySymbol);
	FirstDisplay.Send_Data(0);

	while (1)
	{	
	}
}