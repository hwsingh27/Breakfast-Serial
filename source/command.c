/**
 * @file: command.c
 * @brief: file mainly consists of two functions logger()
 * and process_command()
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

#include "common_headers.h"

#define BACKSPACE (0x08)
#define SPACE (0x20)
#define NEXT_LINE (0x0A)
#define CARRIAGE_RET (0x0D)
#define SIZE 2000

/**
 * @brief: function reads the characters from the terminal
 * using UART, performs the functions with respect to the
 * keys pressed. Reads the string and calls the
 * process_command() function for further processing
 *
 * @param: NULL
 * @return: NULL
 */
void logger()
{
	char temp_buff[700];
	char* temp = &temp_buff[0]; // initializing the pointer pointing at the first element of temp_buff buffer

	char key; // key denotes the button pressed on the keyboard
	while(key!=CARRIAGE_RET) // check if carriage return is detected by pressing ENTER key
	{
		while (ifEmpty(&Rxbuf));
		cbuff_dequeue(&Rxbuf, &key, 1);
		putchar(key); //echo the characters on terminal over the UART
		if(key!=CARRIAGE_RET || key!=NEXT_LINE) // if key pressed is not ENTER and SPACE then enter inside
		{
			if(key!=BACKSPACE) // if BACKSPACE is not pressed then copy the character to temp_buff buffer
			{
				*temp++ = key;
			}
			else
			{
				printf(" \b"); // if BACKSPACE is pressed then remove the previous character
				temp--; // decrement the pointer pointing to temp_buff buffer to type the new character
			}
		 }
		if(key=='\r') // if ENTER key is pressed then store 0x0A in key
		{
			key=NEXT_LINE;
			printf("\r\n");
			break;
		}
	}
	*temp='\0';
	process_command(temp_buff); // calling process_command function for further processing
	temp =& temp_buff[0]; // make the pointer pointing to the first element of temp_buff buffer
}

/*
 * Operating using the function pointer
 */
typedef void (*command_handler)(const char* command);

/*
 * structure command_lut (command lookup table) is declared
 * with front pointer and function name
 */
typedef struct
{
	const char *front;
	command_handler function_name;
} command_lut;

/**
 * @brief: function prints name of the author for parsed command
 *
 * @param: string that is to be parsed i.e. takes command
 * as a parameter and work accordingly
 * @return: prints "Harshwardhan Singh" as the name of an author
 */
static void author_name(const char* command)
{
	printf("Harshwardhan Singh\r\n");
}

/**
 * @brief: function prints string for hexdump command
 * which was parsed
 *
 * @param: string that is to be parsed i.e. takes command
 * as a parameter and work accordingly
 * @return: prints hexdump of the given address and nbytes
 */
static void hex(const char* command)
{
	uint32_t address;
	size_t bytes;
	sscanf(command,"dump %x %i",&address,&bytes); // scan the address and number of bytes from command
	Hexdump((void*)address, bytes);
}

/**
 * @brief: function prints "Unknown Command" as a string
 * for parsed command
 *
 * @param: string that is to be parsed i.e. takes command
 * as a parameter and work accordingly
 * @return: prints "Unknown Command" for any invalid input
 */
static void invalid(const char* command)
{
	printf("Unknown Command: %s\r\n", command);
}

/**
 * @brief: function prints help message with information about the
 * valid commands
 *
 * @param: string that is to be parsed i.e. takes command
 * as a parameter and work accordingly
 * @return: prints help message with information about the
 * valid commands
 */
static void help(const char* command)
{
	printf("Type command: Author to print a string with your name.\r\n");
	printf("Type command: Dump with the starting address and number of bytes to print the hexdump of memory requested.\r\n");
}


static const command_lut commands[] =
{
		{"author", author_name},
		{"dump", hex},
		{"help", help},
		{"", invalid}
};

/**
 * @brief: function processes the string and calls the handler
 * functions accordingly.
 *
 * @param: string that is to be parsed, computed by the logger() function
 * @return: NULL
 */
void process_command(char *input)
{
	char temp_buff[SIZE];
	memset(temp_buff,0,SIZE); // set all bytes of temp_buff buffer as 0 for easy debugging
	char* temp1 = &temp_buff[0]; // temp1 is the pointer pointing to the 1st element of temp_buff buffer
	char* temp2 = &input[0]; // temp2 is the pointer pointing to the 1st element of the string passed for processing
	bool token = true; // initialize the token as true
	char front[50]; // temporary buffer used to match the string typed by the user the in the lookup table

	while(*temp2 != '\0')
	{
		if(token==true && isspace(*temp2)) // checks if token is true and any space in the input string
		{
			temp2++;
		}
		else if(token==false && isspace(*temp2)) // checks if token is false and any space in the input string
		{
			*temp1++ = ' '; // if the condition is true then space is appended
			token=true; // token is set to true
		}
		else
		{
			*temp1++ = tolower(*temp2++); // convert the character of the input string to lowercase and stores in temp_buff buffer
			token = false; // token is set to false
		}
	}
	*temp2 = '\0'; // makes the last element as null-terminated to denote the end of string
	sscanf(temp_buff,"%s",front); // scan the temp_buff string to front

	int num = sizeof(commands)/sizeof(command_lut); // computes the size of lookup table (4 in this case)

	int i=0;
	while(i<num-1)
	{
		if(strcmp(front, commands[i].front)==0) // compare front and the lookup table element
		{
			commands[i].function_name(temp_buff); // calls the handler functions accordingly
			temp1 = &temp_buff[0]; // make the pointer pointing to the first element of temp_buff buffer
			temp2 = &input[0]; // make the pointer pointing to the first element of input string
			return;
		}
		i++;
	}
	invalid(temp_buff); // calling the function for any invalid input by the user
	temp1 = &temp_buff[0]; // make the pointer pointing to the first element of temp_buff buffer
	temp2 = &input[0]; // make the pointer pointing to the first element of input string
	return;
}
