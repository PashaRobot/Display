/*
 * Display1.cpp
 *
 * Created: 29.09.2021 12:15:10
 * Author : Pavel Bezdelev
 */ 

#include <avr/io.h>
#include "HD44780.h"

uint8_t ABV[] = "�����Ũ���������";
uint8_t PRS[] = "����������������";
uint8_t YAabv[] = "���������������";
uint8_t OPR[] = "������������������";
uint8_t uya[] = "��";
uint8_t proverka[] = "��������";
uint8_t yazyka[] = "�������� �����";

HD44780 FirstDisplay;

int main(void)
{
    while (1) 
    {
		FirstDisplay.Set_X_Y(5, 1);
		FirstDisplay.Send_String(proverka);
		FirstDisplay.Set_X_Y(2, 2);
		FirstDisplay.Send_String(yazyka);
		_delay_ms(3000);
		FirstDisplay.Clear_Display();
		FirstDisplay.Send_String(ABV);
		FirstDisplay.Set_X_Y(1, 2);
		FirstDisplay.Send_String(PRS);
		_delay_ms(5000);
		FirstDisplay.Clear_Display();
		FirstDisplay.Send_String(YAabv);
		FirstDisplay.Set_X_Y(1, 2);
		FirstDisplay.Send_String(OPR);
		_delay_ms(5000);
		FirstDisplay.Clear_Display();
		FirstDisplay.Send_String(uya);
		_delay_ms(2000);
		FirstDisplay.Clear_Display();
    }
}