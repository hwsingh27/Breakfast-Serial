/**
 * @file: uart.h
 * @brief: Init_UART0() function has been called here to be used in
 * other files
 *
 * @author: Harshwardhan Singh, harshwardhan.singh@colorado.edu
 * @date: 8th November 2021
 *
 * @references/citations: Embedded Systems Fundamentals with
 * Arm Cortex-M based Microcontrollers
 * by Alexander G.Dean, GitHub repo and
 * KL25Z Reference Manual.
 * Referred https://community.nxp.com/t5/
 * LPCXpresso-IDE-FAQs/Using-printf/m-p/474799
 * for __sys_write() and __sys_read()
 */

#ifndef UART_H_
#define UART_H_

#include "common_headers.h"

void Init_UART0(uint32_t baud_rate);

extern cbuff_t Txbuf, Rxbuf;

#endif /* UART_H_ */
