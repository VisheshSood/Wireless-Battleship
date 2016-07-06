#include "sys/alt_stdio.h"
#include "alt_types.h"
#include "altera_avalon_pios_regs.h"

#define switches (volatile char*) 0x3010
#define leds (char*) 0x3000

void main() {
	volatile int i;
	while (1) {
		*leds = *switches;
		for (i = 10000; i > 0; i--) {}
	}
}
