/*
 * Display1.cpp
 *
 * Created: 29.09.2021 12:15:10
 * Author : Pavel Bezdelev
 */ 

#include <avr/io.h>
#include "HD44780.h"

HD44780 FirstDisplay; 

int main(void)
{
	uint8_t a = 0;
	uint16_t b = 0;
	int8_t c = 0;
	int32_t d = 0;

	while (1)
	{
		FirstDisplay.Clear_Display();
		FirstDisplay.Set_X_Y(1, 1);
		FirstDisplay.Send_Num(a);
		FirstDisplay.Set_X_Y(6, 1);
		FirstDisplay.Send_Num(b);
		FirstDisplay.Set_X_Y(1, 2);
		FirstDisplay.Send_Num(c);
		FirstDisplay.Set_X_Y(6, 2);
		FirstDisplay.Send_Num(d);
		a++;
		b++;
		c++;
		d++;
		_delay_ms(100);
	}
}