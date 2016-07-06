/* 
 *           Function                  Description
 *        ===============  =====================================
 *        alt_printf       Only supports %s, %x, and %c ( < 1 Kbyte)
 *        alt_putstr       Smaller overhead than puts with direct drivers
 *                         Note this function doesn't add a newline.
 *        alt_putchar      Smaller overhead than putchar with direct drivers
 *        alt_getchar      Smaller overhead than getchar with direct drivers
 *
 */

#include "sys/alt_stdio.h"
#include "altera_avalon_pio_regs.h"
#include <unistd.h>

#define char_read (char*) 0x3050
#define char_recv (char*) 0x3060
#define data_in (char*) 0x3070
#define load (char*) 0x3080
#define char_sent (char*) 0x3090
#define trans_en (char*) 0x30a0
#define data_out (char*) 0x30b0
#define LEDs (char*) 0x30c0

unsigned char computeParity(char character) {
	character ^= character >> 4;
	character ^= character >> 2;
	character ^= character >> 1;
	character &= 1;
	return character;
}

int main() {
	unsigned char sent;
	unsigned char parity;
	unsigned char received;
	char choice;
	while(1) {
		alt_printf("--------------------------------------------------\n");
		alt_printf("Enter 's' to send or 'r' to print receive buffer: ");
		choice = alt_getchar();
		alt_getchar();
		if (choice == 's') {
			alt_printf("Please input a character to send: ");
			sent = alt_getchar();
			alt_getchar();
			//alt_printf("sent: %x\n", sent);
			parity = sent;
			parity = computeParity(parity);
			//alt_printf("parity: %x\n", parity);
			sent <<= 1;
			sent = parity + sent;
			//alt_printf("sent: %x\n", sent);
			*data_out = sent;
			usleep(5);
			*load = 1;
			usleep(5);
			*trans_en = 1;
			usleep(5);
			*load = 0;
			while (*char_sent == 0) {
				alt_printf("");
			}
			*trans_en = 0;
			usleep(5);
			alt_printf("...character transmitted\n");
		} else if (choice == 'r') {
			if (*char_recv == 1) {
				received = *data_in;
				parity = received & 1;
				received >>= 1;
				if (computeParity(received) == parity) {
					alt_printf("Character received: %c\n", received);
					*char_read = 1;
					usleep(5);
					*char_read = 0;
					*LEDs = *data_in;
				} else {
					alt_printf("Error: Received byte \"%c\" which has incorrect parity bit\n", *data_in);
					*char_read = 1;
					usleep(5);
					*char_read = 0;
				}
			} else {
				alt_printf("Receive buffer is empty\n");
			}
		} else {
			alt_printf("Please enter valid character\n");
		}
		usleep(5);
	}
	return 0;
}

