# PES-Assignment-6
# BreakfastSerial

## Objective of the Assignment <br/>
Configure UART to process the strings typed on terminal and react accordingly. <br/>
If user enters "Author" or "author", the name of the user should be displayed on the terminal over the UART. <br/>
User can get the hexdump on mentioning the start address and the number of bytes that can be upto 640 in decimals. <br/>
If user types "Help", the information about all the supported commands appear on the screen. <br/>
If user types any invalid input, the message pops up on the terminal stating the user has entered an invalid input. <br/>

## Implementation
1) Developed the Circular Buffer for multiple instances to work with Rxbuf and Txbuf buffers. <br/>
2) Tested the circular buffer using the test suit provided by Prof. Howdy Pierce. <br/>
3) Configured UART as per the requirements mentioned in the write-up, configured it for 2-Stop bits, 8 bit data, No parity and 38400 Baud Rate. <br/>
4) Sysclock configuration was provided by Prof. Howdy Pierce.
5) Hexdump was also developed from Assignment-1 and used the simple logic with shift operators demostrated by Prof. Howdy in the class. <br/>
6) Command interpreter was implemented using the snippet provided by Prof. Howdy, and implemented personal logic to accomplish the command interpreter part. <br/>

Two buffers are used to accomplish the task namely Txbuf (transmit buffer) and Rxbuf (Receive buffer). Whenever the user presses any key, the interrupt<br/>
triggers, the flow goes into the UART Interrupt handler and performes the operations, the character is scanned and enqueued in the receive buffer, <br/>
the character is extracted using putchar() and stored in other variable, while performing putchar(), the character gets enqueued in the Transmit buffer and <br/>
triggers the interrupt which then goes into the handler and dequeues the character from the transmit buffer.<br/>
__sys_write() and __sys_read() are implemented to link the system input/output commands with it. <br/><br/>

## Extra Credit
1) "Help" feature was implemented correctly that shows the information about all the supported commands appear on the screen.
2) "Info" feature was not implemented due to some errors.










