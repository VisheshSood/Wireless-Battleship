char inputBuffer[]
char outputBuffer[]
int validMove
int yourShotX
int yourShotY
int theirShotX
int theirShotY
int enemyHits = 0;
int yourHits = 0;

#define shotsBase 0
#define hitsBase 8
#define boardBase 16
#define BOARD_WIDTH 8
#define BOARD_HEIGHT 8

// shots board, hits board (-, X, 0)
// your boats board (-, B)

void main {
    // Create array to store previous moves
    int prevMoves[BOARD_WIDTH*BOARD_HEIGHT];
    int validMove = 0;

    setUpBoats()
    ask if going first, set yourTurn 1 or 0
    while(!gameOver) {
         if (yourTurn) {
            while (!validMove) {
                enterString()
                int *shotX, *shotY;
                translateOutputBuffer(*shotX, *shotY);
                validMove = checkMove(shotX, shotY);
            }
            sendString()
            readString()    
            updateShots(indices)
            if (hit) 
                updateHits(index)
            printEnemyBoard()
            yourTurn = 0
        } else {
            readString()
            translateInputBuffer()
            updateYourBoard()
            sendString()
            yourTurn = 1
        }
    }
}

void setUpBoats() {
    for (i from 3 to 1) {
        (while check conditions not met)
            print "please choose coords for length i ship"
            enterString()
            translateOutputBuffer()
            print "please choose orientation (v or h)"
            for (each bit in ship)
                check if bit is not off the board space and does not already have a ship at it
                addShipBit(x, y)
    }
}

void addShipBit(int x, int y) {
    c = readSRAM(y + boardBase)
    writeSRAM(y + boardBase, c + createByte(x))
}

void translateInputBuffer() {
    assign theirShotX and theirShotY according to input buffer
}

void translateOutputBuffer(int *shotX, int *shotY) {
    // assign yourShotX and yourShotY according to output buffer
    *shotX = outputBuffer[0];
    *shotY = outputBuffer[1];
}

updateYourBoard() {
    char c = readSRAM(address)
    if index they are attempting to hit has a ship {
        print "enemy got a hit"
        writeSRAM(address, new byte with zero where there was a one)
        increment enemyHits++
        set outputBuffer to 1 followed by null terminator // returning this to other player
    } else {
        print "enemy has missed"
        set outputBuffer to 0 followed by null terminator // going to return this to other player
    }
}

/**
 * 
 */
void updateHits(alt_u8 address) {
    writeSRAM(address, (alt_u8) 1); // new byte indicating hit
    hits++;
}

void printEnemyBoard() {
    sequentially go through SRAM indices for hits and shots
    assign temporary chars (1 byte) to SRAM bytes
    if index has both shot and hit, print "X"
    if index has only shot, "O"
    else print "-"
}

void readString() {
    char received;
    while (received != '\0')
        if (char received)
            read input
            check parity of input
            add input to inputBuffer
}

void enterString() {
    char c = alt_getchar()
    while (c not newline)
        put c in outputBuffer
        c = alt_getchar()
    put null terminator at end of string in outputBuffer
}

void sendString() {
    for (i < length of output buffer) {
        if (outputBuffer[i] == '\0') {
            sendChar(outputBuffer[i])
            break
        } else {
            sendChar(outputBuffer[i])
        }
    }
}

void sendChar(char c) {
    (normal sending procedure for one character)
    usleep(100);
}

/**
 * Computes the even parity of character c and appends
 * it as the LSB of c, returning the result
 */
char computeParity(char c) {
    int ones = 0;
    int i;
    for (i = 7; i >= 0; i--) {
        if (((byte >> i) & 0x01) == 1) {
            ones++;
        }
    }
    alt_u8 parity = ones % 2;
    return (c << 1) | parity;
}

int checkMove(int shotX, int shotY) {
    if (checkIndex(shotX, shotY) == 0) {
        // check that move has not been previously made
        int index = shotX*BOARD_WIDTH + shotY;
        if (prevMoves[index] == 1) {
            return 1;
        } else {
            return 0;
        }
    }
}

char createByte(int column) {
    char c = 1
    c = c << column
    return c
}

/**
 *  Return 0 if index is within board range, otherwise return 1
 */
int checkIndex(int x, int y) {
    if (x >= 0 && x < (BOARD_WIDTH-1) && 
        y >= 0 && y < (BOARD_HEIGHT-1)) {
        return 0;
    }
    return 1;
}

/**
 * Read the byte stored at the given address
 */
alt_u8 readSRAM(alt_u8 address) {
    return (alt_u8) IORD_ALTERA_AVALON_PIO_DATA(address);
}

/**
 * Write the character byte to the given SRAM address
 */
void writeSRAM(alt_u8 address, char byte) {
    IOWR_ALTERA_AVALON_PIO_DATA(address, (alt_u8) byte);
    usleep(10);
}
