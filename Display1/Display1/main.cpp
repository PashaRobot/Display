/*
 * Display1.cpp
 *
 * Created: 29.09.2021 12:15:10
 * Author : Pavel Bezdelev
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "HD44780.h"

HD44780 FirstDisplay(HD44780_Display_Control_ON_OFF_ON_gc, HD44780_Entry_Mode_Set_ON_OFF_gc); 

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

uint8_t ArraySymbol2[] =
{
	0b00000,
	0b01010,
	0b01010,
	0b00000,
	0b10001,
	0b01110,
	0b01110,
	0b00000,
};

int main(void)
{	
	FirstDisplay.Send_String("Безделев Павел ФЭ19-08Б");
	
	while (1)
	{		
		_delay_ms(400);
		FirstDisplay.Send_Cmd(HD44780_Shift_Control_Cursor_Right_gc);
	}
}