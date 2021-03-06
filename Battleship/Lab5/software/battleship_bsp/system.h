/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'nios2_processor' in SOPC Builder design 'nios_system'
 * SOPC Builder design path: ../../nios_system.sopcinfo
 *
 * Generated: Mon Mar 07 16:19:44 PST 2016
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_qsys"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x00020820
#define ALT_CPU_CPU_FREQ 50000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "tiny"
#define ALT_CPU_DATA_ADDR_WIDTH 0x12
#define ALT_CPU_DCACHE_LINE_SIZE 0
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_DCACHE_SIZE 0
#define ALT_CPU_EXCEPTION_ADDR 0x00010020
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 50000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 0
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 0
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_ICACHE_SIZE 0
#define ALT_CPU_INST_ADDR_WIDTH 0x12
#define ALT_CPU_NAME "nios2_processor"
#define ALT_CPU_RESET_ADDR 0x00010000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x00020820
#define NIOS2_CPU_FREQ 50000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "tiny"
#define NIOS2_DATA_ADDR_WIDTH 0x12
#define NIOS2_DCACHE_LINE_SIZE 0
#define NIOS2_DCACHE_LINE_SIZE_LOG2 0
#define NIOS2_DCACHE_SIZE 0
#define NIOS2_EXCEPTION_ADDR 0x00010020
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 0
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 0
#define NIOS2_ICACHE_LINE_SIZE_LOG2 0
#define NIOS2_ICACHE_SIZE 0
#define NIOS2_INST_ADDR_WIDTH 0x12
#define NIOS2_RESET_ADDR 0x00010000


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_PIO
#define __ALTERA_NIOS2_QSYS


/*
 * LEDs configuration
 *
 */

#define ALT_MODULE_CLASS_LEDs altera_avalon_pio
#define LEDS_BASE 0x211c0
#define LEDS_BIT_CLEARING_EDGE_REGISTER 0
#define LEDS_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LEDS_CAPTURE 0
#define LEDS_DATA_WIDTH 8
#define LEDS_DO_TEST_BENCH_WIRING 0
#define LEDS_DRIVEN_SIM_VALUE 0
#define LEDS_EDGE_TYPE "NONE"
#define LEDS_FREQ 50000000
#define LEDS_HAS_IN 0
#define LEDS_HAS_OUT 1
#define LEDS_HAS_TRI 0
#define LEDS_IRQ -1
#define LEDS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LEDS_IRQ_TYPE "NONE"
#define LEDS_NAME "/dev/LEDs"
#define LEDS_RESET_VALUE 0
#define LEDS_SPAN 16
#define LEDS_TYPE "altera_avalon_pio"


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone V"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/jtag_uart"
#define ALT_STDERR_BASE 0x211d0
#define ALT_STDERR_DEV jtag_uart
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag_uart"
#define ALT_STDIN_BASE 0x211d0
#define ALT_STDIN_DEV jtag_uart
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag_uart"
#define ALT_STDOUT_BASE 0x211d0
#define ALT_STDOUT_DEV jtag_uart
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "nios_system"


/*
 * address configuration
 *
 */

#define ADDRESS_BASE 0x21110
#define ADDRESS_BIT_CLEARING_EDGE_REGISTER 0
#define ADDRESS_BIT_MODIFYING_OUTPUT_REGISTER 0
#define ADDRESS_CAPTURE 0
#define ADDRESS_DATA_WIDTH 11
#define ADDRESS_DO_TEST_BENCH_WIRING 0
#define ADDRESS_DRIVEN_SIM_VALUE 0
#define ADDRESS_EDGE_TYPE "NONE"
#define ADDRESS_FREQ 50000000
#define ADDRESS_HAS_IN 0
#define ADDRESS_HAS_OUT 1
#define ADDRESS_HAS_TRI 0
#define ADDRESS_IRQ -1
#define ADDRESS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ADDRESS_IRQ_TYPE "NONE"
#define ADDRESS_NAME "/dev/address"
#define ADDRESS_RESET_VALUE 0
#define ADDRESS_SPAN 16
#define ADDRESS_TYPE "altera_avalon_pio"
#define ALT_MODULE_CLASS_address altera_avalon_pio


/*
 * char_read configuration
 *
 */

#define ALT_MODULE_CLASS_char_read altera_avalon_pio
#define CHAR_READ_BASE 0x21150
#define CHAR_READ_BIT_CLEARING_EDGE_REGISTER 0
#define CHAR_READ_BIT_MODIFYING_OUTPUT_REGISTER 0
#define CHAR_READ_CAPTURE 0
#define CHAR_READ_DATA_WIDTH 1
#define CHAR_READ_DO_TEST_BENCH_WIRING 0
#define CHAR_READ_DRIVEN_SIM_VALUE 0
#define CHAR_READ_EDGE_TYPE "NONE"
#define CHAR_READ_FREQ 50000000
#define CHAR_READ_HAS_IN 0
#define CHAR_READ_HAS_OUT 1
#define CHAR_READ_HAS_TRI 0
#define CHAR_READ_IRQ -1
#define CHAR_READ_IRQ_INTERRUPT_CONTROLLER_ID -1
#define CHAR_READ_IRQ_TYPE "NONE"
#define CHAR_READ_NAME "/dev/char_read"
#define CHAR_READ_RESET_VALUE 0
#define CHAR_READ_SPAN 16
#define CHAR_READ_TYPE "altera_avalon_pio"


/*
 * char_recv configuration
 *
 */

#define ALT_MODULE_CLASS_char_recv altera_avalon_pio
#define CHAR_RECV_BASE 0x21160
#define CHAR_RECV_BIT_CLEARING_EDGE_REGISTER 0
#define CHAR_RECV_BIT_MODIFYING_OUTPUT_REGISTER 0
#define CHAR_RECV_CAPTURE 0
#define CHAR_RECV_DATA_WIDTH 1
#define CHAR_RECV_DO_TEST_BENCH_WIRING 0
#define CHAR_RECV_DRIVEN_SIM_VALUE 0
#define CHAR_RECV_EDGE_TYPE "NONE"
#define CHAR_RECV_FREQ 50000000
#define CHAR_RECV_HAS_IN 1
#define CHAR_RECV_HAS_OUT 0
#define CHAR_RECV_HAS_TRI 0
#define CHAR_RECV_IRQ -1
#define CHAR_RECV_IRQ_INTERRUPT_CONTROLLER_ID -1
#define CHAR_RECV_IRQ_TYPE "NONE"
#define CHAR_RECV_NAME "/dev/char_recv"
#define CHAR_RECV_RESET_VALUE 0
#define CHAR_RECV_SPAN 16
#define CHAR_RECV_TYPE "altera_avalon_pio"


/*
 * char_sent configuration
 *
 */

#define ALT_MODULE_CLASS_char_sent altera_avalon_pio
#define CHAR_SENT_BASE 0x21190
#define CHAR_SENT_BIT_CLEARING_EDGE_REGISTER 0
#define CHAR_SENT_BIT_MODIFYING_OUTPUT_REGISTER 0
#define CHAR_SENT_CAPTURE 0
#define CHAR_SENT_DATA_WIDTH 1
#define CHAR_SENT_DO_TEST_BENCH_WIRING 0
#define CHAR_SENT_DRIVEN_SIM_VALUE 0
#define CHAR_SENT_EDGE_TYPE "NONE"
#define CHAR_SENT_FREQ 50000000
#define CHAR_SENT_HAS_IN 1
#define CHAR_SENT_HAS_OUT 0
#define CHAR_SENT_HAS_TRI 0
#define CHAR_SENT_IRQ -1
#define CHAR_SENT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define CHAR_SENT_IRQ_TYPE "NONE"
#define CHAR_SENT_NAME "/dev/char_sent"
#define CHAR_SENT_RESET_VALUE 0
#define CHAR_SENT_SPAN 16
#define CHAR_SENT_TYPE "altera_avalon_pio"


/*
 * chipReset configuration
 *
 */

#define ALT_MODULE_CLASS_chipReset altera_avalon_pio
#define CHIPRESET_BASE 0x21120
#define CHIPRESET_BIT_CLEARING_EDGE_REGISTER 0
#define CHIPRESET_BIT_MODIFYING_OUTPUT_REGISTER 0
#define CHIPRESET_CAPTURE 0
#define CHIPRESET_DATA_WIDTH 1
#define CHIPRESET_DO_TEST_BENCH_WIRING 0
#define CHIPRESET_DRIVEN_SIM_VALUE 0
#define CHIPRESET_EDGE_TYPE "NONE"
#define CHIPRESET_FREQ 50000000
#define CHIPRESET_HAS_IN 0
#define CHIPRESET_HAS_OUT 1
#define CHIPRESET_HAS_TRI 0
#define CHIPRESET_IRQ -1
#define CHIPRESET_IRQ_INTERRUPT_CONTROLLER_ID -1
#define CHIPRESET_IRQ_TYPE "NONE"
#define CHIPRESET_NAME "/dev/chipReset"
#define CHIPRESET_RESET_VALUE 0
#define CHIPRESET_SPAN 16
#define CHIPRESET_TYPE "altera_avalon_pio"


/*
 * data configuration
 *
 */

#define ALT_MODULE_CLASS_data altera_avalon_pio
#define DATA_BASE 0x21100
#define DATA_BIT_CLEARING_EDGE_REGISTER 0
#define DATA_BIT_MODIFYING_OUTPUT_REGISTER 0
#define DATA_CAPTURE 0
#define DATA_DATA_WIDTH 8
#define DATA_DO_TEST_BENCH_WIRING 0
#define DATA_DRIVEN_SIM_VALUE 0
#define DATA_EDGE_TYPE "NONE"
#define DATA_FREQ 50000000
#define DATA_HAS_IN 0
#define DATA_HAS_OUT 0
#define DATA_HAS_TRI 1
#define DATA_IRQ -1
#define DATA_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DATA_IRQ_TYPE "NONE"
#define DATA_NAME "/dev/data"
#define DATA_RESET_VALUE 0
#define DATA_SPAN 16
#define DATA_TYPE "altera_avalon_pio"


/*
 * data_in configuration
 *
 */

#define ALT_MODULE_CLASS_data_in altera_avalon_pio
#define DATA_IN_BASE 0x21170
#define DATA_IN_BIT_CLEARING_EDGE_REGISTER 0
#define DATA_IN_BIT_MODIFYING_OUTPUT_REGISTER 0
#define DATA_IN_CAPTURE 0
#define DATA_IN_DATA_WIDTH 8
#define DATA_IN_DO_TEST_BENCH_WIRING 0
#define DATA_IN_DRIVEN_SIM_VALUE 0
#define DATA_IN_EDGE_TYPE "NONE"
#define DATA_IN_FREQ 50000000
#define DATA_IN_HAS_IN 1
#define DATA_IN_HAS_OUT 0
#define DATA_IN_HAS_TRI 0
#define DATA_IN_IRQ -1
#define DATA_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DATA_IN_IRQ_TYPE "NONE"
#define DATA_IN_NAME "/dev/data_in"
#define DATA_IN_RESET_VALUE 0
#define DATA_IN_SPAN 16
#define DATA_IN_TYPE "altera_avalon_pio"


/*
 * data_out configuration
 *
 */

#define ALT_MODULE_CLASS_data_out altera_avalon_pio
#define DATA_OUT_BASE 0x211b0
#define DATA_OUT_BIT_CLEARING_EDGE_REGISTER 0
#define DATA_OUT_BIT_MODIFYING_OUTPUT_REGISTER 0
#define DATA_OUT_CAPTURE 0
#define DATA_OUT_DATA_WIDTH 8
#define DATA_OUT_DO_TEST_BENCH_WIRING 0
#define DATA_OUT_DRIVEN_SIM_VALUE 0
#define DATA_OUT_EDGE_TYPE "NONE"
#define DATA_OUT_FREQ 50000000
#define DATA_OUT_HAS_IN 0
#define DATA_OUT_HAS_OUT 1
#define DATA_OUT_HAS_TRI 0
#define DATA_OUT_IRQ -1
#define DATA_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DATA_OUT_IRQ_TYPE "NONE"
#define DATA_OUT_NAME "/dev/data_out"
#define DATA_OUT_RESET_VALUE 0
#define DATA_OUT_SPAN 16
#define DATA_OUT_TYPE "altera_avalon_pio"


/*
 * hal configuration
 *
 */

#define ALT_MAX_FD 4
#define ALT_SYS_CLK none
#define ALT_TIMESTAMP_CLK none


/*
 * jtag_uart configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart altera_avalon_jtag_uart
#define JTAG_UART_BASE 0x211d0
#define JTAG_UART_IRQ 5
#define JTAG_UART_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_NAME "/dev/jtag_uart"
#define JTAG_UART_READ_DEPTH 64
#define JTAG_UART_READ_THRESHOLD 8
#define JTAG_UART_SPAN 8
#define JTAG_UART_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_WRITE_DEPTH 64
#define JTAG_UART_WRITE_THRESHOLD 8


/*
 * load configuration
 *
 */

#define ALT_MODULE_CLASS_load altera_avalon_pio
#define LOAD_BASE 0x21180
#define LOAD_BIT_CLEARING_EDGE_REGISTER 0
#define LOAD_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LOAD_CAPTURE 0
#define LOAD_DATA_WIDTH 1
#define LOAD_DO_TEST_BENCH_WIRING 0
#define LOAD_DRIVEN_SIM_VALUE 0
#define LOAD_EDGE_TYPE "NONE"
#define LOAD_FREQ 50000000
#define LOAD_HAS_IN 0
#define LOAD_HAS_OUT 1
#define LOAD_HAS_TRI 0
#define LOAD_IRQ -1
#define LOAD_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LOAD_IRQ_TYPE "NONE"
#define LOAD_NAME "/dev/load"
#define LOAD_RESET_VALUE 0
#define LOAD_SPAN 16
#define LOAD_TYPE "altera_avalon_pio"


/*
 * notOutEn configuration
 *
 */

#define ALT_MODULE_CLASS_notOutEn altera_avalon_pio
#define NOTOUTEN_BASE 0x21140
#define NOTOUTEN_BIT_CLEARING_EDGE_REGISTER 0
#define NOTOUTEN_BIT_MODIFYING_OUTPUT_REGISTER 0
#define NOTOUTEN_CAPTURE 0
#define NOTOUTEN_DATA_WIDTH 1
#define NOTOUTEN_DO_TEST_BENCH_WIRING 0
#define NOTOUTEN_DRIVEN_SIM_VALUE 0
#define NOTOUTEN_EDGE_TYPE "NONE"
#define NOTOUTEN_FREQ 50000000
#define NOTOUTEN_HAS_IN 0
#define NOTOUTEN_HAS_OUT 1
#define NOTOUTEN_HAS_TRI 0
#define NOTOUTEN_IRQ -1
#define NOTOUTEN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define NOTOUTEN_IRQ_TYPE "NONE"
#define NOTOUTEN_NAME "/dev/notOutEn"
#define NOTOUTEN_RESET_VALUE 0
#define NOTOUTEN_SPAN 16
#define NOTOUTEN_TYPE "altera_avalon_pio"


/*
 * onchip_memory configuration
 *
 */

#define ALT_MODULE_CLASS_onchip_memory altera_avalon_onchip_memory2
#define ONCHIP_MEMORY_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ONCHIP_MEMORY_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ONCHIP_MEMORY_BASE 0x10000
#define ONCHIP_MEMORY_CONTENTS_INFO ""
#define ONCHIP_MEMORY_DUAL_PORT 0
#define ONCHIP_MEMORY_GUI_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY_INIT_CONTENTS_FILE "nios_system_onchip_memory"
#define ONCHIP_MEMORY_INIT_MEM_CONTENT 1
#define ONCHIP_MEMORY_INSTANCE_ID "NONE"
#define ONCHIP_MEMORY_IRQ -1
#define ONCHIP_MEMORY_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ONCHIP_MEMORY_NAME "/dev/onchip_memory"
#define ONCHIP_MEMORY_NON_DEFAULT_INIT_FILE_ENABLED 0
#define ONCHIP_MEMORY_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY_READ_DURING_WRITE_MODE "DONT_CARE"
#define ONCHIP_MEMORY_SINGLE_CLOCK_OP 0
#define ONCHIP_MEMORY_SIZE_MULTIPLE 1
#define ONCHIP_MEMORY_SIZE_VALUE 65536
#define ONCHIP_MEMORY_SPAN 65536
#define ONCHIP_MEMORY_TYPE "altera_avalon_onchip_memory2"
#define ONCHIP_MEMORY_WRITABLE 1


/*
 * readnWrite configuration
 *
 */

#define ALT_MODULE_CLASS_readnWrite altera_avalon_pio
#define READNWRITE_BASE 0x21130
#define READNWRITE_BIT_CLEARING_EDGE_REGISTER 0
#define READNWRITE_BIT_MODIFYING_OUTPUT_REGISTER 0
#define READNWRITE_CAPTURE 0
#define READNWRITE_DATA_WIDTH 1
#define READNWRITE_DO_TEST_BENCH_WIRING 0
#define READNWRITE_DRIVEN_SIM_VALUE 0
#define READNWRITE_EDGE_TYPE "NONE"
#define READNWRITE_FREQ 50000000
#define READNWRITE_HAS_IN 0
#define READNWRITE_HAS_OUT 1
#define READNWRITE_HAS_TRI 0
#define READNWRITE_IRQ -1
#define READNWRITE_IRQ_INTERRUPT_CONTROLLER_ID -1
#define READNWRITE_IRQ_TYPE "NONE"
#define READNWRITE_NAME "/dev/readnWrite"
#define READNWRITE_RESET_VALUE 0
#define READNWRITE_SPAN 16
#define READNWRITE_TYPE "altera_avalon_pio"


/*
 * trans_en configuration
 *
 */

#define ALT_MODULE_CLASS_trans_en altera_avalon_pio
#define TRANS_EN_BASE 0x211a0
#define TRANS_EN_BIT_CLEARING_EDGE_REGISTER 0
#define TRANS_EN_BIT_MODIFYING_OUTPUT_REGISTER 0
#define TRANS_EN_CAPTURE 0
#define TRANS_EN_DATA_WIDTH 1
#define TRANS_EN_DO_TEST_BENCH_WIRING 0
#define TRANS_EN_DRIVEN_SIM_VALUE 0
#define TRANS_EN_EDGE_TYPE "NONE"
#define TRANS_EN_FREQ 50000000
#define TRANS_EN_HAS_IN 0
#define TRANS_EN_HAS_OUT 1
#define TRANS_EN_HAS_TRI 0
#define TRANS_EN_IRQ -1
#define TRANS_EN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define TRANS_EN_IRQ_TYPE "NONE"
#define TRANS_EN_NAME "/dev/trans_en"
#define TRANS_EN_RESET_VALUE 0
#define TRANS_EN_SPAN 16
#define TRANS_EN_TYPE "altera_avalon_pio"


/*
 * yourboard0 configuration
 *
 */

#define ALT_MODULE_CLASS_yourboard0 altera_avalon_pio
#define YOURBOARD0_BASE 0x21090
#define YOURBOARD0_BIT_CLEARING_EDGE_REGISTER 0
#define YOURBOARD0_BIT_MODIFYING_OUTPUT_REGISTER 0
#define YOURBOARD0_CAPTURE 0
#define YOURBOARD0_DATA_WIDTH 8
#define YOURBOARD0_DO_TEST_BENCH_WIRING 0
#define YOURBOARD0_DRIVEN_SIM_VALUE 0
#define YOURBOARD0_EDGE_TYPE "NONE"
#define YOURBOARD0_FREQ 50000000
#define YOURBOARD0_HAS_IN 0
#define YOURBOARD0_HAS_OUT 1
#define YOURBOARD0_HAS_TRI 0
#define YOURBOARD0_IRQ -1
#define YOURBOARD0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define YOURBOARD0_IRQ_TYPE "NONE"
#define YOURBOARD0_NAME "/dev/yourboard0"
#define YOURBOARD0_RESET_VALUE 0
#define YOURBOARD0_SPAN 16
#define YOURBOARD0_TYPE "altera_avalon_pio"


/*
 * yourboard1 configuration
 *
 */

#define ALT_MODULE_CLASS_yourboard1 altera_avalon_pio
#define YOURBOARD1_BASE 0x210f0
#define YOURBOARD1_BIT_CLEARING_EDGE_REGISTER 0
#define YOURBOARD1_BIT_MODIFYING_OUTPUT_REGISTER 0
#define YOURBOARD1_CAPTURE 0
#define YOURBOARD1_DATA_WIDTH 8
#define YOURBOARD1_DO_TEST_BENCH_WIRING 0
#define YOURBOARD1_DRIVEN_SIM_VALUE 0
#define YOURBOARD1_EDGE_TYPE "NONE"
#define YOURBOARD1_FREQ 50000000
#define YOURBOARD1_HAS_IN 0
#define YOURBOARD1_HAS_OUT 1
#define YOURBOARD1_HAS_TRI 0
#define YOURBOARD1_IRQ -1
#define YOURBOARD1_IRQ_INTERRUPT_CONTROLLER_ID -1
#define YOURBOARD1_IRQ_TYPE "NONE"
#define YOURBOARD1_NAME "/dev/yourboard1"
#define YOURBOARD1_RESET_VALUE 0
#define YOURBOARD1_SPAN 16
#define YOURBOARD1_TYPE "altera_avalon_pio"


/*
 * yourboard2 configuration
 *
 */

#define ALT_MODULE_CLASS_yourboard2 altera_avalon_pio
#define YOURBOARD2_BASE 0x210e0
#define YOURBOARD2_BIT_CLEARING_EDGE_REGISTER 0
#define YOURBOARD2_BIT_MODIFYING_OUTPUT_REGISTER 0
#define YOURBOARD2_CAPTURE 0
#define YOURBOARD2_DATA_WIDTH 8
#define YOURBOARD2_DO_TEST_BENCH_WIRING 0
#define YOURBOARD2_DRIVEN_SIM_VALUE 0
#define YOURBOARD2_EDGE_TYPE "NONE"
#define YOURBOARD2_FREQ 50000000
#define YOURBOARD2_HAS_IN 0
#define YOURBOARD2_HAS_OUT 1
#define YOURBOARD2_HAS_TRI 0
#define YOURBOARD2_IRQ -1
#define YOURBOARD2_IRQ_INTERRUPT_CONTROLLER_ID -1
#define YOURBOARD2_IRQ_TYPE "NONE"
#define YOURBOARD2_NAME "/dev/yourboard2"
#define YOURBOARD2_RESET_VALUE 0
#define YOURBOARD2_SPAN 16
#define YOURBOARD2_TYPE "altera_avalon_pio"


/*
 * yourboard3 configuration
 *
 */

#define ALT_MODULE_CLASS_yourboard3 altera_avalon_pio
#define YOURBOARD3_BASE 0x210d0
#define YOURBOARD3_BIT_CLEARING_EDGE_REGISTER 0
#define YOURBOARD3_BIT_MODIFYING_OUTPUT_REGISTER 0
#define YOURBOARD3_CAPTURE 0
#define YOURBOARD3_DATA_WIDTH 8
#define YOURBOARD3_DO_TEST_BENCH_WIRING 0
#define YOURBOARD3_DRIVEN_SIM_VALUE 0
#define YOURBOARD3_EDGE_TYPE "NONE"
#define YOURBOARD3_FREQ 50000000
#define YOURBOARD3_HAS_IN 0
#define YOURBOARD3_HAS_OUT 1
#define YOURBOARD3_HAS_TRI 0
#define YOURBOARD3_IRQ -1
#define YOURBOARD3_IRQ_INTERRUPT_CONTROLLER_ID -1
#define YOURBOARD3_IRQ_TYPE "NONE"
#define YOURBOARD3_NAME "/dev/yourboard3"
#define YOURBOARD3_RESET_VALUE 0
#define YOURBOARD3_SPAN 16
#define YOURBOARD3_TYPE "altera_avalon_pio"


/*
 * yourboard4 configuration
 *
 */

#define ALT_MODULE_CLASS_yourboard4 altera_avalon_pio
#define YOURBOARD4_BASE 0x210c0
#define YOURBOARD4_BIT_CLEARING_EDGE_REGISTER 0
#define YOURBOARD4_BIT_MODIFYING_OUTPUT_REGISTER 0
#define YOURBOARD4_CAPTURE 0
#define YOURBOARD4_DATA_WIDTH 8
#define YOURBOARD4_DO_TEST_BENCH_WIRING 0
#define YOURBOARD4_DRIVEN_SIM_VALUE 0
#define YOURBOARD4_EDGE_TYPE "NONE"
#define YOURBOARD4_FREQ 50000000
#define YOURBOARD4_HAS_IN 0
#define YOURBOARD4_HAS_OUT 1
#define YOURBOARD4_HAS_TRI 0
#define YOURBOARD4_IRQ -1
#define YOURBOARD4_IRQ_INTERRUPT_CONTROLLER_ID -1
#define YOURBOARD4_IRQ_TYPE "NONE"
#define YOURBOARD4_NAME "/dev/yourboard4"
#define YOURBOARD4_RESET_VALUE 0
#define YOURBOARD4_SPAN 16
#define YOURBOARD4_TYPE "altera_avalon_pio"


/*
 * yourboard5 configuration
 *
 */

#define ALT_MODULE_CLASS_yourboard5 altera_avalon_pio
#define YOURBOARD5_BASE 0x21080
#define YOURBOARD5_BIT_CLEARING_EDGE_REGISTER 0
#define YOURBOARD5_BIT_MODIFYING_OUTPUT_REGISTER 0
#define YOURBOARD5_CAPTURE 0
#define YOURBOARD5_DATA_WIDTH 8
#define YOURBOARD5_DO_TEST_BENCH_WIRING 0
#define YOURBOARD5_DRIVEN_SIM_VALUE 0
#define YOURBOARD5_EDGE_TYPE "NONE"
#define YOURBOARD5_FREQ 50000000
#define YOURBOARD5_HAS_IN 0
#define YOURBOARD5_HAS_OUT 1
#define YOURBOARD5_HAS_TRI 0
#define YOURBOARD5_IRQ -1
#define YOURBOARD5_IRQ_INTERRUPT_CONTROLLER_ID -1
#define YOURBOARD5_IRQ_TYPE "NONE"
#define YOURBOARD5_NAME "/dev/yourboard5"
#define YOURBOARD5_RESET_VALUE 0
#define YOURBOARD5_SPAN 16
#define YOURBOARD5_TYPE "altera_avalon_pio"


/*
 * yourboard6 configuration
 *
 */

#define ALT_MODULE_CLASS_yourboard6 altera_avalon_pio
#define YOURBOARD6_BASE 0x210b0
#define YOURBOARD6_BIT_CLEARING_EDGE_REGISTER 0
#define YOURBOARD6_BIT_MODIFYING_OUTPUT_REGISTER 0
#define YOURBOARD6_CAPTURE 0
#define YOURBOARD6_DATA_WIDTH 8
#define YOURBOARD6_DO_TEST_BENCH_WIRING 0
#define YOURBOARD6_DRIVEN_SIM_VALUE 0
#define YOURBOARD6_EDGE_TYPE "NONE"
#define YOURBOARD6_FREQ 50000000
#define YOURBOARD6_HAS_IN 0
#define YOURBOARD6_HAS_OUT 1
#define YOURBOARD6_HAS_TRI 0
#define YOURBOARD6_IRQ -1
#define YOURBOARD6_IRQ_INTERRUPT_CONTROLLER_ID -1
#define YOURBOARD6_IRQ_TYPE "NONE"
#define YOURBOARD6_NAME "/dev/yourboard6"
#define YOURBOARD6_RESET_VALUE 0
#define YOURBOARD6_SPAN 16
#define YOURBOARD6_TYPE "altera_avalon_pio"


/*
 * yourboard7 configuration
 *
 */

#define ALT_MODULE_CLASS_yourboard7 altera_avalon_pio
#define YOURBOARD7_BASE 0x210a0
#define YOURBOARD7_BIT_CLEARING_EDGE_REGISTER 0
#define YOURBOARD7_BIT_MODIFYING_OUTPUT_REGISTER 0
#define YOURBOARD7_CAPTURE 0
#define YOURBOARD7_DATA_WIDTH 8
#define YOURBOARD7_DO_TEST_BENCH_WIRING 0
#define YOURBOARD7_DRIVEN_SIM_VALUE 0
#define YOURBOARD7_EDGE_TYPE "NONE"
#define YOURBOARD7_FREQ 50000000
#define YOURBOARD7_HAS_IN 0
#define YOURBOARD7_HAS_OUT 1
#define YOURBOARD7_HAS_TRI 0
#define YOURBOARD7_IRQ -1
#define YOURBOARD7_IRQ_INTERRUPT_CONTROLLER_ID -1
#define YOURBOARD7_IRQ_TYPE "NONE"
#define YOURBOARD7_NAME "/dev/yourboard7"
#define YOURBOARD7_RESET_VALUE 0
#define YOURBOARD7_SPAN 16
#define YOURBOARD7_TYPE "altera_avalon_pio"


/*
 * yourshots0 configuration
 *
 */

#define ALT_MODULE_CLASS_yourshots0 altera_avalon_pio
#define YOURSHOTS0_BASE 0x21070
#define YOURSHOTS0_BIT_CLEARING_EDGE_REGISTER 0
#define YOURSHOTS0_BIT_MODIFYING_OUTPUT_REGISTER 0
#define YOURSHOTS0_CAPTURE 0
#define YOURSHOTS0_DATA_WIDTH 8
#define YOURSHOTS0_DO_TEST_BENCH_WIRING 0
#define YOURSHOTS0_DRIVEN_SIM_VALUE 0
#define YOURSHOTS0_EDGE_TYPE "NONE"
#define YOURSHOTS0_FREQ 50000000
#define YOURSHOTS0_HAS_IN 0
#define YOURSHOTS0_HAS_OUT 1
#define YOURSHOTS0_HAS_TRI 0
#define YOURSHOTS0_IRQ -1
#define YOURSHOTS0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define YOURSHOTS0_IRQ_TYPE "NONE"
#define YOURSHOTS0_NAME "/dev/yourshots0"
#define YOURSHOTS0_RESET_VALUE 0
#define YOURSHOTS0_SPAN 16
#define YOURSHOTS0_TYPE "altera_avalon_pio"


/*
 * yourshots1 configuration
 *
 */

#define ALT_MODULE_CLASS_yourshots1 altera_avalon_pio
#define YOURSHOTS1_BASE 0x21060
#define YOURSHOTS1_BIT_CLEARING_EDGE_REGISTER 0
#define YOURSHOTS1_BIT_MODIFYING_OUTPUT_REGISTER 0
#define YOURSHOTS1_CAPTURE 0
#define YOURSHOTS1_DATA_WIDTH 8
#define YOURSHOTS1_DO_TEST_BENCH_WIRING 0
#define YOURSHOTS1_DRIVEN_SIM_VALUE 0
#define YOURSHOTS1_EDGE_TYPE "NONE"
#define YOURSHOTS1_FREQ 50000000
#define YOURSHOTS1_HAS_IN 0
#define YOURSHOTS1_HAS_OUT 1
#define YOURSHOTS1_HAS_TRI 0
#define YOURSHOTS1_IRQ -1
#define YOURSHOTS1_IRQ_INTERRUPT_CONTROLLER_ID -1
#define YOURSHOTS1_IRQ_TYPE "NONE"
#define YOURSHOTS1_NAME "/dev/yourshots1"
#define YOURSHOTS1_RESET_VALUE 0
#define YOURSHOTS1_SPAN 16
#define YOURSHOTS1_TYPE "altera_avalon_pio"


/*
 * yourshots2 configuration
 *
 */

#define ALT_MODULE_CLASS_yourshots2 altera_avalon_pio
#define YOURSHOTS2_BASE 0x21050
#define YOURSHOTS2_BIT_CLEARING_EDGE_REGISTER 0
#define YOURSHOTS2_BIT_MODIFYING_OUTPUT_REGISTER 0
#define YOURSHOTS2_CAPTURE 0
#define YOURSHOTS2_DATA_WIDTH 8
#define YOURSHOTS2_DO_TEST_BENCH_WIRING 0
#define YOURSHOTS2_DRIVEN_SIM_VALUE 0
#define YOURSHOTS2_EDGE_TYPE "NONE"
#define YOURSHOTS2_FREQ 50000000
#define YOURSHOTS2_HAS_IN 0
#define YOURSHOTS2_HAS_OUT 1
#define YOURSHOTS2_HAS_TRI 0
#define YOURSHOTS2_IRQ -1
#define YOURSHOTS2_IRQ_INTERRUPT_CONTROLLER_ID -1
#define YOURSHOTS2_IRQ_TYPE "NONE"
#define YOURSHOTS2_NAME "/dev/yourshots2"
#define YOURSHOTS2_RESET_VALUE 0
#define YOURSHOTS2_SPAN 16
#define YOURSHOTS2_TYPE "altera_avalon_pio"


/*
 * yourshots3 configuration
 *
 */

#define ALT_MODULE_CLASS_yourshots3 altera_avalon_pio
#define YOURSHOTS3_BASE 0x21040
#define YOURSHOTS3_BIT_CLEARING_EDGE_REGISTER 0
#define YOURSHOTS3_BIT_MODIFYING_OUTPUT_REGISTER 0
#define YOURSHOTS3_CAPTURE 0
#define YOURSHOTS3_DATA_WIDTH 8
#define YOURSHOTS3_DO_TEST_BENCH_WIRING 0
#define YOURSHOTS3_DRIVEN_SIM_VALUE 0
#define YOURSHOTS3_EDGE_TYPE "NONE"
#define YOURSHOTS3_FREQ 50000000
#define YOURSHOTS3_HAS_IN 0
#define YOURSHOTS3_HAS_OUT 1
#define YOURSHOTS3_HAS_TRI 0
#define YOURSHOTS3_IRQ -1
#define YOURSHOTS3_IRQ_INTERRUPT_CONTROLLER_ID -1
#define YOURSHOTS3_IRQ_TYPE "NONE"
#define YOURSHOTS3_NAME "/dev/yourshots3"
#define YOURSHOTS3_RESET_VALUE 0
#define YOURSHOTS3_SPAN 16
#define YOURSHOTS3_TYPE "altera_avalon_pio"


/*
 * yourshots4 configuration
 *
 */

#define ALT_MODULE_CLASS_yourshots4 altera_avalon_pio
#define YOURSHOTS4_BASE 0x21030
#define YOURSHOTS4_BIT_CLEARING_EDGE_REGISTER 0
#define YOURSHOTS4_BIT_MODIFYING_OUTPUT_REGISTER 0
#define YOURSHOTS4_CAPTURE 0
#define YOURSHOTS4_DATA_WIDTH 8
#define YOURSHOTS4_DO_TEST_BENCH_WIRING 0
#define YOURSHOTS4_DRIVEN_SIM_VALUE 0
#define YOURSHOTS4_EDGE_TYPE "NONE"
#define YOURSHOTS4_FREQ 50000000
#define YOURSHOTS4_HAS_IN 0
#define YOURSHOTS4_HAS_OUT 1
#define YOURSHOTS4_HAS_TRI 0
#define YOURSHOTS4_IRQ -1
#define YOURSHOTS4_IRQ_INTERRUPT_CONTROLLER_ID -1
#define YOURSHOTS4_IRQ_TYPE "NONE"
#define YOURSHOTS4_NAME "/dev/yourshots4"
#define YOURSHOTS4_RESET_VALUE 0
#define YOURSHOTS4_SPAN 16
#define YOURSHOTS4_TYPE "altera_avalon_pio"


/*
 * yourshots5 configuration
 *
 */

#define ALT_MODULE_CLASS_yourshots5 altera_avalon_pio
#define YOURSHOTS5_BASE 0x21020
#define YOURSHOTS5_BIT_CLEARING_EDGE_REGISTER 0
#define YOURSHOTS5_BIT_MODIFYING_OUTPUT_REGISTER 0
#define YOURSHOTS5_CAPTURE 0
#define YOURSHOTS5_DATA_WIDTH 8
#define YOURSHOTS5_DO_TEST_BENCH_WIRING 0
#define YOURSHOTS5_DRIVEN_SIM_VALUE 0
#define YOURSHOTS5_EDGE_TYPE "NONE"
#define YOURSHOTS5_FREQ 50000000
#define YOURSHOTS5_HAS_IN 0
#define YOURSHOTS5_HAS_OUT 1
#define YOURSHOTS5_HAS_TRI 0
#define YOURSHOTS5_IRQ -1
#define YOURSHOTS5_IRQ_INTERRUPT_CONTROLLER_ID -1
#define YOURSHOTS5_IRQ_TYPE "NONE"
#define YOURSHOTS5_NAME "/dev/yourshots5"
#define YOURSHOTS5_RESET_VALUE 0
#define YOURSHOTS5_SPAN 16
#define YOURSHOTS5_TYPE "altera_avalon_pio"


/*
 * yourshots6 configuration
 *
 */

#define ALT_MODULE_CLASS_yourshots6 altera_avalon_pio
#define YOURSHOTS6_BASE 0x21010
#define YOURSHOTS6_BIT_CLEARING_EDGE_REGISTER 0
#define YOURSHOTS6_BIT_MODIFYING_OUTPUT_REGISTER 0
#define YOURSHOTS6_CAPTURE 0
#define YOURSHOTS6_DATA_WIDTH 8
#define YOURSHOTS6_DO_TEST_BENCH_WIRING 0
#define YOURSHOTS6_DRIVEN_SIM_VALUE 0
#define YOURSHOTS6_EDGE_TYPE "NONE"
#define YOURSHOTS6_FREQ 50000000
#define YOURSHOTS6_HAS_IN 0
#define YOURSHOTS6_HAS_OUT 1
#define YOURSHOTS6_HAS_TRI 0
#define YOURSHOTS6_IRQ -1
#define YOURSHOTS6_IRQ_INTERRUPT_CONTROLLER_ID -1
#define YOURSHOTS6_IRQ_TYPE "NONE"
#define YOURSHOTS6_NAME "/dev/yourshots6"
#define YOURSHOTS6_RESET_VALUE 0
#define YOURSHOTS6_SPAN 16
#define YOURSHOTS6_TYPE "altera_avalon_pio"


/*
 * yourshots7 configuration
 *
 */

#define ALT_MODULE_CLASS_yourshots7 altera_avalon_pio
#define YOURSHOTS7_BASE 0x21000
#define YOURSHOTS7_BIT_CLEARING_EDGE_REGISTER 0
#define YOURSHOTS7_BIT_MODIFYING_OUTPUT_REGISTER 0
#define YOURSHOTS7_CAPTURE 0
#define YOURSHOTS7_DATA_WIDTH 8
#define YOURSHOTS7_DO_TEST_BENCH_WIRING 0
#define YOURSHOTS7_DRIVEN_SIM_VALUE 0
#define YOURSHOTS7_EDGE_TYPE "NONE"
#define YOURSHOTS7_FREQ 50000000
#define YOURSHOTS7_HAS_IN 0
#define YOURSHOTS7_HAS_OUT 1
#define YOURSHOTS7_HAS_TRI 0
#define YOURSHOTS7_IRQ -1
#define YOURSHOTS7_IRQ_INTERRUPT_CONTROLLER_ID -1
#define YOURSHOTS7_IRQ_TYPE "NONE"
#define YOURSHOTS7_NAME "/dev/yourshots7"
#define YOURSHOTS7_RESET_VALUE 0
#define YOURSHOTS7_SPAN 16
#define YOURSHOTS7_TYPE "altera_avalon_pio"

#endif /* __SYSTEM_H_ */
