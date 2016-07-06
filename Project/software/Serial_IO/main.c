/*
 * Project 4: NIOS Communications I/O System
 * EE 371
 * Justin Allmaras, Sean Happenny, Vishesh Sood
 * 2/16/16
 * main.c
 *
 *
 * This program provides a serial I/O interface to communicate
 * with another DE1 board.
 *
 */

#include "sys/alt_stdio.h"
#include "altera_avalon_pio_regs.h"
#include <stdio.h>
#include <string.h>

// Maximum number of chars allowed
#define MAX_INPUT_SIZE 100
// Define base addresses for inputs/outputs
#define LEDS_ADDR 0x000210f0
#define RX_ADDR 0x000210d0
#define TX_ADDR 0x000210c0
// Inputs
#define SWITCHES ((volatile char *) 0x000210e0)
#define RECEIVE ((volatile char *) RX_ADDR)
#define CHAR_RCVD ((volatile char *) 0x00021040)
#define CHAR_SENT ((volatile char *) 0x00021050)
#define DATAIN ((volatile char *) 0x000210a0)

// Outputs
#define LEDS ((char *) LEDS_ADDR)
#define TRANSMIT ((char *) TX_ADDR)
#define TRANSMIT_ENABLE ((char *) 0x00021020)
#define DATAOUT ((char *) 0x000210b0)
#define ENABLE ((char *) 0x00021090)
#define SELECT ((char *) 0x00021080)
#define READNWRITE ((char *) 0x00021070)
#define ADDRESS ((char *) 0x00021060)
#define LOAD ((char *) 0x00021030)

// Declare functions
void receiveChar();
void receiveString();
void displayString(char *buf);
void transmitChar();
void transmitString(char buf[MAX_INPUT_SIZE]);
alt_u8 generateParity(char byte);
void delay(int n);
unsigned int reverse(register unsigned int x);

int main(void) {
  // Print intro message
  alt_putstr("This interface allows you to send and receive signals over a serial interface.\n");

  // Setup base state
  /*
  *TRANSMIT_ENABLE = 0;
  delay(10);
  *TRANSMIT_ENABLE = 1;
  delay(10);
  *TRANSMIT_ENABLE = 0;
  */


/*
  // test parity
  char word = 'a';
  alt_u8 parity = generateParity(word);
  //alt_putstr("Parity of 'a':");
  //alt_putchar((char) parity);
  // Shift parity bit to MSB of word
  alt_u8 send = (parity << 7) | word;
 */

  //alt_putstr("Would you like to receive a string or a character? S/C\n");
  //char c = alt_getchar();

  // Enter infinite loop to constantly monitor serial I/O
  while (1) {
	  /*
	  switch (c) {
	  	  case 'S' :
	  	  case 's' :
		  	  receiveString();
		  	  break;
	  	  case 'C' :
	  	  case 'c' :
		  	  receiveChar();
		  	  break;
	  }
	  */
	  //receiveChar();
	  //transmitChar();
	  alt_putstr("Enter S to send a string, R to receive.\n");
	  char tmp = alt_getchar();
	  alt_getchar(); // Clear newline
	  if (tmp == 'S') {
		  alt_putstr("Enter string to send: ");
		  char c = alt_getchar();
		  alt_getchar();
		  char buf[MAX_INPUT_SIZE];
		  int i;
		  for (i = 0; i < MAX_INPUT_SIZE; i++) {
			  buf[i] = 0;
		  }
		  int j = 0;
		  while (c != '\n') {
			  buf[j] = c;
			  c = alt_getchar();
			  j++;
		  }
		  transmitString(buf);
	  } else if (tmp == 'R') {
		  receiveString();
	  }
	  receiveString();
  }

  return 0;
}

void receiveChar() {
	alt_u8 c = (alt_u8) IORD_ALTERA_AVALON_PIO_DATA(RX_ADDR);
	// Extract parity bit
	//alt_u8 sentParity = c >> 7;
	// Mask out the parity (8th) bit
	//char rcvd = c & 0x7f;
	// Extract parity bit
	alt_u8 sentParity = c & 0x01;
	// Mask out the parity (1st) bit
	char rcvd = (c & 0xfe) >> 1;

	// Compute parity and compare to the sent parity bit
	alt_u8 genParity = generateParity(rcvd);
	if (sentParity != genParity) {
		alt_putstr("Parity error in received character!\n");
		//alt_putchar(rcvd);
	} else {
		alt_putstr("Character received: ");
		alt_putchar(rcvd);
		alt_putchar('\n');
	}
}

void receiveString() {
	char buf[MAX_INPUT_SIZE];
	int i;
	for (i = 0; i < MAX_INPUT_SIZE; i++) {
		buf[i] = 0;
	}
	alt_u8 c = (alt_u8) IORD_ALTERA_AVALON_PIO_DATA(RX_ADDR);
	int j = 0;
	while (j < MAX_INPUT_SIZE && c != '\0') {
		alt_u8 c = (alt_u8) IORD_ALTERA_AVALON_PIO_DATA(RX_ADDR);
		// Extract parity bit
		//alt_u8 sentParity = c >> 7;
		// Mask out the parity (8th) bit
		//char rcvd = c & 0x7f;
		// Extract parity bit
		alt_u8 sentParity = c & 0x01;
		// Mask out the parity (1st) bit
		char rcvd = (c & 0xfe) >> 1;

		// Compute parity and compare to the sent parity bit
		alt_u8 genParity = generateParity(rcvd);
		if (sentParity != genParity) {
			alt_putstr("Refused: parity error in received character!\n");
		} else {
			buf[j] = rcvd;
			j++;
		}
	}
	displayString(buf);
	/*
	while (*flush != 1) {
		alt_u8 c = (alt_u8) IORD_ALTERA_AVALON_PIO_DATA(RX_ADDR);
		// Extract parity bit
		//alt_u8 sentParity = c >> 7;
		// Mask out the parity (8th) bit
		//char rcvd = c & 0x7f;
		// Extract parity bit
		alt_u8 sentParity = c & 0x01;
		// Mask out the parity (1st) bit
		char rcvd = (c & 0xfe) >> 1;

		// Compute parity and compare to the sent parity bit
		alt_u8 genParity = generateParity(rcvd);
		if (sentParity != genParity) {
			alt_putstr("Parity error in received character!\n");
		} else if (*print == 1) {
			buf[i] = rcvd;
			alt_putstr("String received: ");
			displayString(buf);
		}
		buf[i] = rcvd;
		i++;
	}
	*/

}

void transmitChar() {
	volatile char c = alt_getchar();
	if (c != '\n') {
		*LOAD = 0;
		delay(10);
		*TRANSMIT_ENABLE = 0;
		// Compute parity and append parity bit to word
		alt_u8 parity = generateParity(c);
		// Shift parity bit to MSB of word
		//alt_u8 send = (parity << 7) | c;
		// Shift parity bit to LSB of word
		alt_u8 send = (c << 1) | parity;
		IOWR_ALTERA_AVALON_PIO_DATA(TX_ADDR, send);
		delay(10);
		// Signal char is loaded into transmit line
		*LOAD = 1;
		delay(10);
		*LOAD = 0;
		delay(10);
		alt_u8 one = 1;
		IOWR_ALTERA_AVALON_PIO_DATA(0x00021020, one);
		while (*CHAR_SENT == 0) {
			delay(5);
		}
		IOWR_ALTERA_AVALON_PIO_DATA(LEDS_ADDR, send);
	}
	// Signal transmit is done
	*LOAD = 0;
	*TRANSMIT_ENABLE = 0;
	// Clear newline
	c = alt_getchar();
}

void transmitString(char buf[MAX_INPUT_SIZE]) {
	int i;
	for (i = 0; i < MAX_INPUT_SIZE; i++) {
		char c = buf[i];
		*LOAD = 0;
		delay(10);
		*TRANSMIT_ENABLE = 0;
		// Compute parity and append parity bit to word
		alt_u8 parity = generateParity(c);
		// Shift parity bit to MSB of word
		//alt_u8 send = (parity << 7) | c;
		// Shift parity bit to LSB of word
		alt_u8 send = (c << 1) | parity;
		IOWR_ALTERA_AVALON_PIO_DATA(TX_ADDR, send);
		delay(10);
		// Signal char is loaded into transmit line
		*LOAD = 1;
		delay(10);
		*LOAD = 0;
		delay(10);
		alt_u8 one = 1;
		IOWR_ALTERA_AVALON_PIO_DATA(0x00021020, one);
		while (*CHAR_SENT == 0) {
			delay(5);
		}
		IOWR_ALTERA_AVALON_PIO_DATA(LEDS_ADDR, send);
	}
	// Signal transmit is done
	*LOAD = 0;
	// Echo characters
	//displayString(buf);
	*TRANSMIT_ENABLE = 0;
}

void displayString(char *buf) {
	alt_putstr("String received: ");
	alt_putstr(buf);
	alt_putchar('\n');
}

alt_u8 generateParity(char byte) {
	int ones = 0;
	int i;
	for (i = 7; i >= 0; i--) {
		if ((byte >> i) & 0x01 == 1) {
			ones++;
		}
	}
	alt_u8 parity = ones % 2;
	return parity;
}

void delay(int n) {
	int i;
	int j;
	int count;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			count++;
		}
	}
}

unsigned int
reverse(register unsigned int x)
{
	x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));
	x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2));
	x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4));
	x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8));
	return((x >> 16) | (x << 16));

}
