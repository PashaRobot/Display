/*
 * Display1.cpp
 *
 * Created: 29.09.2021 12:15:10
 * Author : Pavel Bezdelev
 */ 

#include <avr/io.h>
#include "HD44780.h"

uint8_t PavelBezdelev[] = "Павел Безделев";
uint8_t FE19_08B[] = "ФЭ19-08Б";
uint8_t Clear[] = "Очистка дисплея";

HD44780 FirstDisplay;

int main(void)
{
	while (1)
	{
		FirstDisplay.Set_X_Y(2, 1);
		FirstDisplay.Send_String(PavelBezdelev);
		FirstDisplay.Set_X_Y(5, 2);
		FirstDisplay.Send_String(FE19_08B);
		_delay_ms(5000);
		FirstDisplay.Clear_Display();
		FirstDisplay.Set_X_Y(1, 1);
		FirstDisplay.Send_String(Clear);
		_delay_ms(2000);
		FirstDisplay.Clear_Display();
		_delay_ms(2000);
	}
}