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
	uint32_t hex_num = 0;
	while (1)
	{
		FirstDisplay.Send_Hex(reinterpret_cast<uint8_t*>(&hex_num), 4);
		hex_num++;
		_delay_ms(500);
		FirstDisplay.Clear_Display();
	}

}