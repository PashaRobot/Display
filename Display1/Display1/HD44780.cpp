/* 
* HD44780.cpp
*
* Created: 29.09.2021 12:15:44
* Author: Pavel Bezdelev
*/


#include "HD44780.h"

// default constructor
HD44780::HD44780()
{
	PORTA_DIR = 0xFF;
	PORTB_DIR = 0xFF;
	_delay_ms(100);
	Send_Cmd(HD44780_Function_Set_8bit_2line_5x8_gc);
	_delay_ms(5);	// wait min 4.1ms
	Send_Cmd(HD44780_Function_Set_8bit_2line_5x8_gc);
	_delay_us(110); // wait min 100us
	Send_Cmd(HD44780_Function_Set_8bit_2line_5x8_gc);
	_delay_us(50); // wait min 37us

	Send_Cmd(HD44780_Function_Set_8bit_2line_5x8_gc);
	_delay_us(50); // wait min 37us

	Send_Cmd(HD44780_Display_Control_OFF_OFF_OFF_gc);
	_delay_us(50); // wait min 37us

	Send_Cmd(HD44780_Clear_Display_gc);
	_delay_ms(2); // wait min 37us

	Send_Cmd(HD44780_Entry_Mode_Set_ON_OFF_gc);
	_delay_us(50); // wait min 37us

	Send_Cmd(HD44780_Return_Home_gc);
	_delay_ms(2); // wait min 37us

	Send_Cmd(HD44780_Display_Control_ON_ON_ON_gc);
	_delay_us(50); // wait min 37us
	
} //HD44780

// default destructor
/*HD44780::~HD44780()
{
} //~HD44780
*/

void HD44780::Send_Cmd(uint8_t byte)
{
	PORTB_OUTCLR = 1;
	_PORTA_OUT_(byte);

	_delay_us(10);

	PORTB_OUTSET = 2;

	_delay_us(10);

	PORTB_OUTCLR = 2;

	_delay_us(10);
}

void HD44780::Send_Data(uint8_t byte)
{
	PORTB_OUTSET = 1;
	_PORTA_OUT_(byte);

	_delay_us(10);

	PORTB_OUTSET = 2;

	_delay_us(10);

	PORTB_OUTCLR = 2;

	_delay_us(10);
}

void HD44780::_PORTA_OUT_(uint8_t byte)
{
	PORTA_OUTCLR = 255;
	uint8_t j = 128;
	for (uint8_t i = 1; j > 0; i = i << 1){
		if (byte & i) PORTA_OUTSET = j;
		j = j >> 1;
	}
}

void HD44780::Send_String(uint8_t* str)
{
	uint8_t i = 0;
	while (*(str+i))    // Цикл действует пока не дойдет до 0, который стоит в конце строки
	{
		Send_Data(*(str+i));
		i++;
	}
}

void HD44780::Set_X_Y(uint8_t x, uint8_t y)
{
	if((y == 1) && (x >= 1 && x <= 16))
	{
		Send_Cmd(1 << 7 | (x - 1));
	}
	else if((y == 2) && (x >= 1 && x <= 16))
	{
		Send_Cmd(1 << 7 | (x + 63));
	}
	else
	Send_Cmd(1 << 7 | 0x0);
	_delay_us(40);
}

void HD44780::Clear_Display()
{
	Send_Cmd(1);
	_delay_ms(2);
}