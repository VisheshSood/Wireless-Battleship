/*
 * Project 5: NIOS Game
 * EE 371
 * Justin Allmaras, Sean Happenny, Vishesh Sood
 * 3/3/16
 * main.c
 *
 *
 * This program provides an interface to play a game with
 * another DE1 board using serial communication to communicate
 * between the boards.
 *
 */

#include "sys/alt_stdio.h"
#include "altera_avalon_pio_regs.h"
#include <stdio.h>
#include <string.h>

// Maximum number of chars allowed
#define MAX_INPUT_LENGTH 100
#define GAME_CMD_LENGTH 2
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
void transmitString(char buf[GAME_CMD_LENGTH]);
alt_u8 generateParity(char byte);
alt_u8 addParity(char byte);
void delay(int n);

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

  alt_putstr("Would you like to receive a string or a character? S/C\n");
  char c = alt_getchar();

  // Enter infinite loop to constantly monitor serial I/O
  while (1) {
	  switch (c) {
	  	  case 'S' :
	  	  case 's' :
	  		  alt_putstr("Enter S to send a string, R to receive.\n");
			  char tmp = alt_getchar();
			  //alt_getchar(); // Clear newline
			  if (tmp == 'S') {
				  alt_putstr("Enter string to send: ");
				  char sel = alt_getchar();
				  alt_getchar();
				  char buf[GAME_CMD_LENGTH];
				  int i;
				  for (i = 0; i < GAME_CMD_LENGTH; i++) {
					  buf[i] = 0;
				  }
				  int j = 0;
				  while (sel != '\n') {
					  buf[j] = sel;
					  sel = alt_getchar();
					  j++;
					  alt_putchar(sel);
				  }
				  transmitString(buf);
			  } else if (tmp == 'R') {
				  receiveString();
			  }
			  //receiveString();

		  	  break;
	  	  case 'C' :
	  	  case 'c' :
	  		  receiveChar();
	  		  transmitChar();
		  	  break;
	  }
  }

  return 0;
}

/**
 * Receives a single character from the serial in line
 */
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

/**
 * Receives and displays a series of characters
 */
void receiveString() {
	char buf[GAME_CMD_LENGTH];
	int i;
	for (i = 0; i < GAME_CMD_LENGTH; i++) {
		buf[i] = 0;
	}
	alt_u8 c = (alt_u8) IORD_ALTERA_AVALON_PIO_DATA(RX_ADDR);
	int j = 0;
	while (j < GAME_CMD_LENGTH && c != '\0') {
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
}

/**
 * Transmits a single character entered on the console
 */
void transmitChar() {
	char c = alt_getchar();
	if (c != '\n') {
		*LOAD = 0;
		delay(10);
		*TRANSMIT_ENABLE = 0;
		// Compute parity and append parity bit to word
		alt_u8 send = addParity(c);
		IOWR_ALTERA_AVALON_PIO_DATA(TX_ADDR, send);
		delay(10);
		// Signal char is loaded into transmit line
		*LOAD = 1;
		delay(10);
		*LOAD = 0;
		delay(10);
		*TRANSMIT_ENABLE = 1;
		while (*CHAR_SENT == 0) {
			delay(5);
		}
		IOWR_ALTERA_AVALON_PIO_DATA(LEDS_ADDR, send);
	} else {
		c = '\0';
	}
	// Signal transmit is done
	*LOAD = 0;
	*TRANSMIT_ENABLE = 0;
	// Clear newline
	//c = alt_getchar();
}

/**
 * Transmits each character in buf.
 */
void transmitString(char buf[GAME_CMD_LENGTH]) {
	int i;
	for (i = 0; i < GAME_CMD_LENGTH; i++) {
		char c = buf[i];
		if (c != 0) {
			*LOAD = 0;
			delay(10);
			*TRANSMIT_ENABLE = 0;
			// Compute parity and append parity bit to word
			alt_u8 send = addParity(c);
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
		} else {
			i = GAME_CMD_LENGTH;
		}
	}
	// Signal transmit is done
	*LOAD = 0;
	// Echo characters
	//displayString(buf);
	*TRANSMIT_ENABLE = 0;
}

/**
 * Nicely display the contents of buf
 */
void displayString(char *buf) {
	alt_putstr("String received: ");
	alt_putstr(buf);
	alt_putchar('\n');
}

/**
 * Generates a parity bit for even parity for the char byte
 * Returns the parity bit as an unsigned 8bit number
 */
alt_u8 generateParity(char byte) {
	int ones = 0;
	int i;
	for (i = 7; i >= 0; i--) {
		if (((byte >> i) & 0x01) == 1) {
			ones++;
		}
	}
	alt_u8 parity = ones % 2;
	return parity;
}

/**
 * Adds the parity bit to char c, shifting the bits of c
 * left 1 bit and putting the parity as the LSB
 * Returns the char c as an unsigned 8bit number
 */
alt_u8 addParity(char c) {
	// Compute parity and append parity bit to word
	alt_u8 parity = generateParity(c);
	// Shift parity bit to MSB of word
	//alt_u8 send = (parity << 7) | c;
	// Shift parity bit to LSB of word
	return (c << 1) | parity;
}

/**
 * A simple software delay function
 */
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
