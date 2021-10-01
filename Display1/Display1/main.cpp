/*
 * Display1.cpp
 *
 * Created: 29.09.2021 12:15:10
 * Author : Pavel Bezdelev
 */ 

#include <avr/io.h>
#include "HD44780.h"

uint8_t PavelBezdelev[] = "Pavel Bezdelev";
uint8_t FE19_08B[] = "FE19-08B";
uint8_t ClearDisplay[] = "Clear Display";

HD44780 FirstDisplay;
void numbers()
{
	FirstDisplay.Set_X_Y(16, 2);
	FirstDisplay.Send_Data('5');
	_delay_ms(1000);
	FirstDisplay.Set_X_Y(16, 2);
	FirstDisplay.Send_Data('4');
	_delay_ms(1000);
	FirstDisplay.Set_X_Y(16, 2);
	FirstDisplay.Send_Data('3');
	_delay_ms(1000);
	FirstDisplay.Set_X_Y(16, 2);
	FirstDisplay.Send_Data('2');
	_delay_ms(1000);
	FirstDisplay.Set_X_Y(16, 2);
	FirstDisplay.Send_Data('1');
	_delay_ms(1000);
}

int main(void)
{	
    while (1) 
    {
		FirstDisplay.Set_X_Y(2, 1);
		FirstDisplay.Send_String(PavelBezdelev);
		FirstDisplay.Set_X_Y(5, 2);
		FirstDisplay.Send_String(FE19_08B);
		numbers();
		FirstDisplay.Clear_Display();
		FirstDisplay.Set_X_Y(2, 1);
		FirstDisplay.Send_String(ClearDisplay);
		_delay_ms(2000);
		FirstDisplay.Clear_Display();
		_delay_ms(2000);
    }
}

