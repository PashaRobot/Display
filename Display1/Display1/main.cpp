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

HD44780 FirstDisplay;

int main(void)
{
	FirstDisplay.Set_X_Y(2, 1);
	FirstDisplay.Send_String(PavelBezdelev);
	FirstDisplay.Set_X_Y(5, 2);
	FirstDisplay.Send_String(FE19_08B);
	
    while (1) 
    {
    }
}

