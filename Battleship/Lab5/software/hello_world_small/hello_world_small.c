// Hunter Goforth, David Suh, Erin Long
// EE 371, Lab 3
//
// sram_tester.c is a driver which allows the Nios II processor to communicate
// with and store data onto the Verilog-developed SRAM module. The tester
// write data to the first 128 SRAM bytes and reads that data back out

#include "sys/alt_stdio.h"
#include "alt_types.h"
#include "altera_avalon_pio_regs.h"
#include <unistd.h>

// Create pointers to relevant processor I/O with SRAM
#define leds (char*) 0x30c0
#define data (char*) 0x3000
#define address (char*) 0x3010
#define chipSelect (char*) 0x3020
#define readnWrite (char*) 0x3030
#define notOutEn (char*) 0x3040

int main() {
	*chipSelect = 1;
	usleep(5);
	*chipSelect = 0;
	*readnWrite = 1;
	*notOutEn = 1;
	int i;

	// Writes the data 127...0 to the SRAM byte addresses 0...127
	alt_putstr("Begin writing...");
	//usleep(500000);
	for (i = 127; i >= 0; i--) {
		*address = 127 - i;
		*data = i;
		printf("%d, ", *data);
		//usleep(2);
		*readnWrite = 0;
		usleep(1);
		*readnWrite = 1;
		//usleep(2);
	}

	alt_putstr("\nDone writing...\nReading...\n");

	// Reads the test data written to SRAM, lighting LEDs on the DE1 corresponding to the data
	*readnWrite = 1;
	for (i = 127; i >= 0; i--) {
		*address = 127 - i;
		//usleep(2);
		*notOutEn = 0;
		usleep(1);
		printf("%d, ", *data);
		*leds = *data; // show data on LEDs
		usleep(100000);
		*notOutEn = 1;
		//usleep(2);
	}

	alt_putstr("\nDone reading...\n");
	return 0;
}
