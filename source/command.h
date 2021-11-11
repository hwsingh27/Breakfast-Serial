/**
 * @file: command.h
 * @brief: file mainly consists of two functions logger()
 * and process_command() which are called to be used in
 * other files
 *
 * @author: Harshwardhan Singh, harshwardhan.singh@colorado.edu
 * @date: 9th November 2021
 * @references/citations: Prof. Howdy Pierce's code snippet from
 * lecture on "Command Processing"
 *
 * Referred tolower() function from -
 * https://www.geeksforgeeks.org/tolower-function-in-c/
 * and isspace() function from -
 * https://www.geeksforgeeks.org/isspace-in-c-and-its-
 * application-to-count-whitespace-characters/
 */

#ifndef COMMAND_H_
#define COMMAND_H_

#include "common_headers.h"

void process_command(char *input);
void logger();

#endif /* COMMAND_H_ */
