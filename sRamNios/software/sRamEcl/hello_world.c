/*
 * "Hello World" example.
 *
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example
 * designs. It runs with or without the MicroC/OS-II RTOS and requires a STDOUT
 * device in your system's hardware.
 * The memory footprint of this hosted application is ~69 kbytes by default
 * using the standard reference design.
 *
 * For a reduced footprint version of this template, and an explanation of how
 * to reduce the memory footprint for a given application, see the
 * "small_hello_world" template.
 *
 */


#define LEDS ((char *) 0x00011070)
#define ADDRESS ((char* ) 0x00011030)
#define ENABLE ((char *) 0x00011050)
#define READNWRITE ((char *) 0x00011020)
#define DATA ((char *) 0x00011060)
#define CHIPSELECT ((char *) 0x00011040)


#include "sys/alt_stdio.h"

void udelay(int n);

int main()
{
  alt_putstr("Hello from Nios II!\n");

	*ENABLE = 0;
	*CHIPSELECT = 0;
	*ADDRESS = 0;

	while(1) {
		int i;
		for (i = 0; i < 128; i++ ) {
			*READNWRITE = 0;
			*ADDRESS = i;
			*DATA = (127 - i);
			//alt_putstr("%x\n" , *DATA);
			udelay(100);
			*READNWRITE = 1;
			udelay(100);
		}
		alt_putstr("finished");
		*ENABLE = 1;
		udelay(100);
		for(i = 0; i < 128; i++) {
			*LEDS = *DATA;
			udelay(1000);
		}
	}

    return 0;
}

void udelay(int n) {
	int i , j;
	for (i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {

		}
	}
}
