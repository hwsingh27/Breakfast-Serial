/**
 * @file: hexdump.h
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

#ifndef HEXDUMP_H_
#define HEXDUMP_H_

#include "common_headers.h"

char Convert_to_hex(int x);
void Hexdump(void *addr, size_t nbytes);

#endif /* HEXDUMP_H_ */
