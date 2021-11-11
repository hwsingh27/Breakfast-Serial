/**
 * @file: circular_buff.h
 * @brief: seven functions have been implemented for working with circular buffer
 *
 * @author: Harshwardhan Singh, harshwardhan.singh@colorado.edu
 * @date: 08th November 2021
 * @references/citations: PES 2nd Assignment and suggestions
 * by Prof. Howdy Pierce.
 */

#ifndef CIRCULAR_BUFF_H_
#define CIRCULAR_BUFF_H_

#include "common_headers.h"

#define MAX_CAPACITY (256)

/**
 * @brief: structure cbuff_t with front and rear pointers,
 * capacity, items and the buffer with its maximum capacity
 */
typedef struct
{
	int front;
	int rear;
	size_t capacity;
	size_t items;
	uint8_t data[MAX_CAPACITY];
}cbuff_t;

void cbuff_init(cbuff_t *c);
uint8_t ifFull(cbuff_t *c);
uint8_t ifEmpty(cbuff_t *c);
size_t cbuff_length(cbuff_t *c);
size_t cbuff_enqueue(cbuff_t *c, void *buffer, size_t nbyte);
size_t cbuff_dequeue(cbuff_t *c, void *buffer, size_t nbyte);

#endif /* CIRCULAR_BUFF_H_ */
