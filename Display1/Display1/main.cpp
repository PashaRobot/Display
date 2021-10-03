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
	while (1)
	{
		FirstDisplay.Set_X_Y(2, 1);
		FirstDisplay.Send_String("Павел Безделев");
		FirstDisplay.Set_X_Y(5, 2);
		FirstDisplay.Send_String("ФЭ19-08Б");
		_delay_ms(5000);
		FirstDisplay.Clear_Display();
		FirstDisplay.Set_X_Y(1, 1);
		FirstDisplay.Send_String("Очистка дисплея");
		_delay_ms(2000);
		FirstDisplay.Clear_Display();
		_delay_ms(2000);
	}
}