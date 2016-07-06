#define LEDS ((volatile char *) 0x00011080)
#define DATAIN ((volatile char *) 0x00011020)
#define DATAOUT ((volatile char *) 0x00011070)
#define ENABLE ((volatile char *) 0x00011060)
#define CHIPSELECT ((volatile char *) 0x00011050)
#define ADDRESS ((volatile char* ) 0x00011040)
#define READNWRITE ((volatile char *) 0x00011030)

void write(int addr, int data);
void udelay(int n);


int main(void)
{
	*ENABLE = 0;
	*CHIPSELECT = 0;
	*ADDRESS = 0;
	printf("here");

	while(1) {
		alt_putstr("Enter 'w' for write, 'r' for read, 'c' to clear\n");
		char c;
		read(0,&c,1);
		alt_putchar(c);
		if (c == 'w') {
			*ENABLE = 1;
			*CHIPSELECT = 0;
			int i;
			for (i = 0; i < 128; i++ ) {
				int tmp = 127 - i;
				write(i, tmp);
			}
			alt_putstr("Write finished\n");
		} else if (c == 'r') {
			*READNWRITE = 1;
			*CHIPSELECT = 0;
			udelay(100);
			int i;
			for(i = 0; i < 128; i++) {
				*ENABLE = 1;
				udelay(100);
				*ADDRESS = i;
				*LEDS = *DATAIN;
				udelay(100);
				printf("%x\n", *DATAIN);
				*ENABLE = 0;
				udelay(100);
			}
			alt_putstr("Read finished\n");
		} else if (c == 'c') {
			int i;
			for (i = 0; i < 128; i++ ) {
				write(i, 0);
			}
			alt_putstr("Data cleared \n");
		}
	}

    return 0;
}

void write(int addr, int data) {
	*READNWRITE = 0;
	udelay(100);
	*ADDRESS = addr;
	*DATAOUT = data;
	udelay(100);
	printf("%x\n" , *DATAOUT);
	*READNWRITE = 1;
	udelay(100);
}

void udelay(int n) {
	int i , j;
	for (i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {

		}
	}


}

