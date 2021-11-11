/*
 * @file: main.c
 *
 * @date: 26th October 2021
 * @tools: MCUXpresso IDE by NXP
 * @author: .zip file of the project was provided by
 * Howdy Pierce, howdy.pierce@colorado.edu
 */

#include "common_headers.h"

int main(void)
{
	sysclock_init(); //initialization of sysclock
	Init_UART0(38400); //initialization of UART (38400 in this case)

	test_cbuff(); //circular buffer test file

	printf("Welcome to BreakfastSerial!\r\n");

	while(1)
	{
		putchar('?');
		putchar(' ');
		logger();
	}
	return 0;
}
