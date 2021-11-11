/**
 * @file: hexdump.c
 * @brief: two functions have been implemented one for converting the
 * integer to hexadecimal and another for computing the hexdump
 *
 * @author: Harshwardhan Singh, harshwardhan.singh@colorado.edu
 * @date: 10th November 2021
 * @references/citations: PES Assignment-1, Prof. Howdy Pierce's method of
 * performing hexdump discussed in the class after Assignment-1
 * and the implementation logic of hexdump function discussed
 * with Taher Ujjainwala
 */

#include "common_headers.h"

#define STRIDE (16)
#define MAXIMUM_SIZE (640)

#define RSHIFT_28 (28)
#define RSHIFT_24 (24)
#define RSHIFT_20 (20)
#define RSHIFT_16 (16)
#define RSHIFT_12 (12)
#define RSHIFT_8 (8)
#define RSHIFT_4 (4)

/**
 * @brief: function converts integer into hexadecimal
 *
 * @param: takes an integer number as an argument
 * @return: returns the hexadecimal character of the respective integer
 */
char Convert_to_hex(int n)
{
	if (n>=0 && n<10)
		return '0' + n;
	else if (n>=10 && n<16)
		return 'A' + n - 10;
}

/**
 * @brief: function performs the hexdump from the given address
 * and the number of bytes to be displayed
 *
 * @param: takes address (addr) as a pointer and nbytes as
 * total number of bytes to be displayed
 * @return: NULL (performs the hexdump)
 * @reference/citation: PES Assignment-1, Prof. Howdy Pierce's method of
 * performing hexdump discussed in the class after Assignment-1
 * and the implementation logic of hexdump function discussed
 * with Taher Ujjainwala
 */
void Hexdump(void *addr, size_t nbytes)
{
	  uint8_t *temp_addr = (uint8_t*)addr;
	  uint8_t *maximum = (uint8_t*)addr + nbytes;

	  //checks if the nbytes in the range of 0-640 inclusive
	  if(nbytes>MAXIMUM_SIZE)
	  {
		  printf("Enter value of length in the range of 0-640 or 0x00 to 0x280\r\n");
		  return;
	  }
	  if(nbytes == NULL)
	  {
		  printf("Enter the length\r\n");
		  return;
	  }

	  while(temp_addr<maximum)
	  {
		  // putchars are used for the execution of the addresses for every 16 bytes\
		  right shifting logic was discussed by Prof. Howdy in the class
		  putchar(Convert_to_hex(((uint32_t)(temp_addr) & 0xF0000000)>>RSHIFT_28));
		  putchar(Convert_to_hex(((uint32_t)(temp_addr) & 0x0F000000)>>RSHIFT_24));
		  putchar(Convert_to_hex(((uint32_t)(temp_addr) & 0x00F00000)>>RSHIFT_20));
		  putchar(Convert_to_hex(((uint32_t)(temp_addr) & 0x000F0000)>>RSHIFT_16));
		  putchar('_');
		  putchar(Convert_to_hex(((uint32_t)(temp_addr) & 0x0000F000)>>RSHIFT_12));
		  putchar(Convert_to_hex(((uint32_t)(temp_addr) & 0x00000F00)>>RSHIFT_8));
		  putchar(Convert_to_hex(((uint32_t)(temp_addr) & 0x000000F0)>>RSHIFT_4));
		  putchar(Convert_to_hex((uint32_t)(temp_addr) & 0x0000000F));
		  putchar(' ');
		  putchar(' ');

		  int k=0;
		  // this loop is used to print 16 bytes in every line for each address
		  while((k<STRIDE) && ((temp_addr+k) < maximum))
		  {
			  putchar(Convert_to_hex(temp_addr[k]>>RSHIFT_4));
			  putchar(Convert_to_hex(temp_addr[k] & 0x0F));
			  putchar(' ');
			  k++;
		  }
		  temp_addr=temp_addr+STRIDE;
		  putchar('\r');
		  putchar('\n');
	  }
}
