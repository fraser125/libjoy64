//
// libn64/include/si.h: SI helper functions.
//
// n64chain: A (free) open-source N64 development toolchain.
// Copyright 2017 Fraser
//			https://sites.google.com/site/consoleprotocols/
// This file is subject to the terms and conditions defined in
// 'LICENSE', which is part of this source code package.
//

#ifndef LIBN64_INCLUDE_RCP_SI_H
#define LIBN64_INCLUDE_RCP_SI_H

#include <stdint.h>

// typedef unsigned char uint8_t;
// typedef unsigned short int uint16_t;
// typedef unsigned int uint32_t;
//#define true 1
//#define false 0
// TODO bool?

#define RDRAM_DIRECT_MASK	0x1FFFFF
#define PIF_RAM_ADDR			0x1FC007C0

#define MAX_CONTROLLERS 4
#define INVALID_CONTROLLER_COUNT 1
#define INVALID_ENTRY_ID 2
#define INVALID_LENGTH 3
#define INVALID_DATA 4
#define NO_ERROR 0

#define BUTTON_A		0x8000
#define BUTTON_B		0x4000
#define BUTTON_Z		0x2000
#define BUTTON_START	0x1000

#define BUTTON_DUP		0x0800
#define BUTTON_DDOWN	0x0400
#define BUTTON_DLEFT	0x0200
#define BUTTON_DRIGHT	0x0100

#define BUTTON_RESET	0x0080
//#define BUTTON_UNUSED	0x0040
#define BUTTON_TLEFT	0x0020
#define BUTTON_TRIGHT	0x0010

#define BUTTON_CUP		0x0008
#define BUTTON_CDOWN	0x0004
#define BUTTON_CLEFT 	0x0002
#define BUTTON_CRIGHT 	0x0001

#define MOUSE_LEFT		BUTTON_A
#define MOUSE_RIGHT		BUTTON_B

#define STANDARD_TYPE_TEST (BUTTON_START | BUTTON_A)

// https://assemblergames.com/threads/densha-de-go-64-train-controller-info.56965/
#define DENSHA_MASK_BRK	0x000F
#define DENSHA_MASK_MST 0x2900

#define DENSHA_MASTER_0	0x2800	// 0010 1000 0000 0000
#define DENSHA_MASTER_1	0x2100	// 0010 0001 0000 0000
#define DENSHA_MASTER_2	0x2000	// 0010 0000 0000 0000
#define DENSHA_MASTER_3	0x0900	// 0000 1001 0000 0000
#define DENSHA_MASTER_4	0x0800	// 0000 1000 0000 0000
#define DENSHA_MASTER_5	0x0100	// 0000 0001 0000 0000								

#define DENSHA_BRK_INVAL	0x000F
#define DENSHA_BRK_14	0x000E
#define DENSHA_BRK_13	0x000D
#define DENSHA_BRK_12	0x000C
#define DENSHA_BRK_11	0x000B
#define DENSHA_BRK_10	0x000A
#define DENSHA_BRK_09	0x0009
#define DENSHA_BRK_08	0x0008
#define DENSHA_BRK_07	0x0007
#define DENSHA_BRK_06	0x0006
#define DENSHA_BRK_05	0x0005
#define DENSHA_BRK_04	0x0004
#define DENSHA_BRK_03	0x0003
#define DENSHA_BRK_02	0x0002
#define DENSHA_BRK_01	0x0001
#define DENSHA_BRK_OFF	0x0000

#define DENSHA_B_SELECT	0x0010
#define DENSHA_B_START	0x1000

#define DENSHA_BUTTON_A	0x4000
#define DENSHA_BUTTON_B	0x8000
#define DENSHA_BUTTON_C	0x0020

#define DENSHA_TYPE_TEST (DENSHA_B_START | DENSHA_BUTTON_A)

#define SI_STATUS_DMA_BUSY		(1 << 0)
#define SI_STATUS_IO_BUSY		(1 << 1)
#define SI_STATUS_DMA_ERROR		(1 << 3)
#define SI_STATUS_BUSY_ERROR_6	(1 << 6) // Not sure but they would flip high while waiting for PIF
#define SI_STATUS_BUSY_ERROR_8	(1 << 8) // Not sure but they would flip high while waiting for PIF
#define SI_STATUS_INTERRUPT		(1 << 12)

#define N64_UNPLUGGED	0xFFFF
#define N64_UNKNOWN		0x0000
#define N64_CONTROLLER	0x0500
#define N64_DANCEPAD	0x0500
#define N64_VRU			0x0001
#define N64_MOUSE		0x0200
#define N64_KEYBOARD	0x0002
#define N64_DENSHA		0x2004
#define GBA_HANDHELD	0x0004

#define KEYBOARD_NUMLCK	0x01000000
#define KEYBOARD_CAPLCK	0x02000000
#define KEYBOARD_POWER	0x04000000

#define SI_REQ_FILL_FF 	0xFFFFFFFF
#define SI_REQ_CONT_QY	0xFF010300
#define SI_REQ_CONT_ST	0xFF010401
#define SI_REQ_KYBD_ST	0x02071304
#define SI_REQ_ACC_READ 0x03210200
#define SI_REQ_ACC_WRIT 0x23010300


#define SI_REQ_FINL_CH	0xFE000000

#define SI_REQ_SKP_PORT_NO 	0xFFFFFF03
#define SI_REQ_SKP_PORT_0 	0x00FFFF03
#define SI_REQ_SKP_PORT_01 	0x0000FF03
#define SI_REQ_SKP_PORT_012	0x00000003
#define SI_REQ_CPAK_R1		0x21020000
#define SI_REQ_CPAK_AD		0xFF032102
#define SI_REQ_CPAK_END		0xFFFE0000

#define SI_PSTAT_ZERO	0x00
#define SI_PSTAT_ERROR	0x01
#define SI_PSTAT_CHANG	0x02
#define SI_PSTAT_IGNOR	0x04
#define SI_PSTAT_ERR_1	0x08
#define SI_PSTAT_READY	0x10
#define SI_PSTAT_GSTAT	0x20
#define SI_PSTAT_PERR4	0x40 // Port Overrun?
#define SI_PSTAT_NORES	0x80 // No response

#define SI_GSTAT_INIT	0x00
#define SI_GSTAT_BACKGR	0x01
#define SI_GSTAT_ACC_CHANGED	0x08
#define SI_GSTAT_ACC_ON	0x80 // Rumble / Pulse

#define SI_ACC_UNKNOWN  0x01
#define SI_ACC_CONT_PAK 0x02
#define SI_ACC_RUMB_PAK 0x04
#define SI_ACC_TXFR_PAK 0x08
#define SI_ACC_PULS_PAK 0x10
#define SI_ACC_KNOWN	0x1E
#define SI_ACC_REQUESTW 0x21
#define SI_ACC_REQUESTR 0x21


typedef struct si_request_t {
	union
	{
		uint8_t bytes[64];
		uint16_t shorts[32];
		uint32_t uints[16];
	} raw;
} _si_request_t __attribute__ ((aligned (16)));

typedef struct si_port_t {
	union
	{
		struct si_device_type_t {
			uint16_t id;
			uint8_t acc;
			uint8_t state;		
		} dev_type;
		uint32_t raw;
	} device;
	union // 64 bit, 8 bytes
	{
		struct si_controller_state_t {
			uint16_t pressed; // Raw?
			uint8_t joyx;
			uint8_t joyy;
			uint16_t held;
			uint16_t released;
		} controller;
		
		struct si_mouse_state_t {
			uint16_t buttons;
			uint8_t movex;
			uint8_t movey;
			uint8_t filler[4];
		} mouse;
		
		struct si_keyboard_state_t {
			uint16_t raw[3];
			uint8_t bits;
			uint8_t filler;
		} keyboard;
		
		struct si_densha_de_go_t {
			uint16_t buttons;
			uint8_t filler[6];
		} densha_de_go;
		
		struct si_dancepad_t {
			uint32_t raw;
			uint8_t filler[4];
		} dancepad;
		
		struct si_fishing_rod_t {
			uint32_t raw;
			uint8_t filler[4];
		} fishing_rod;
		uint32_t raw[2];
	} data;
} _si_port_t;

typedef struct si_console_t {
	uint16_t state;
	uint8_t eeprom;
	uint8_t portcount;
	struct si_port_t port[MAX_CONTROLLERS];
} _si_console;

typedef struct si_io_port_t {
	struct si_io_device_type_t {
		uint16_t identifier;
		uint8_t acc_state;
		uint8_t errors;
	} _si_io_device_type_t;
	union
	{
		struct controller_pak_t {
			uint8_t raw[32];
		} _controller_pak_t;
		
		struct si_voice_recognition_t {
			uint32_t raw;
		} _si_voice_recognition_t;
		
	} _data_t;
} _si_io_port_t;

typedef struct page_t {	
	uint8_t raw[256];
} page;

typedef struct request_t {
	uint32_t raw[8];
} request;	

typedef struct entry_t {
	uint32_t vendor; // 4
	uint16_t game_id; // 2
	uint16_t inode; // 2
	uint8_t region; // 1 
	uint8_t blocks; // 1
	uint8_t valid; // 1
	uint8_t entry_id; // 1
	uint8_t raw[19]; // 19
	// 31 ? 
} entry;

typedef struct si_controllerpak_toc_t {
	struct status_t {
		uint16_t start;
		uint16_t end;
		uint16_t current;
		uint16_t status;		
	} status;
	union
	{
		struct page_t pages[5]; // toc only has 5 pages
		struct request_t requests[40]; // Takes 40 requests for the table of contents
		uint32_t raw[320]; // 1280 Bytes
	} data;
} si_controllerpak_toc;

struct 		si_console_t si_console;
//struct 		si_controllerpak_toc_t si_toc[MAX_CONTROLLERS];

struct 		si_request_t si_buffer_tx __attribute__((aligned (16)));
struct 		si_request_t si_buffer_rx __attribute__((aligned (16)));	
 
uint32_t 	si_buffer_tx_ram_addr; 
uint32_t 	si_buffer_rx_ram_addr;
uint32_t 	si_controller_background_index;

uint32_t si_state;

// From si.c
void 		si_init(uint32_t port_enable_count, uint32_t enableBackground);
void 		si_init_tx_buffer();
void 		si_init_devices();
void 		si_status_zero_wait();
void 		si_status_dma_io_wait();
void 		si_send_request(uint32_t buffer_addr);
void 		si_recv_response(uint32_t buffer_addr);

// From si_auto.c
uint32_t 	si_auto_before_vi();
uint32_t 	si_auto_after_vi();

// From si_port.c
void 		si_prepare_port();
uint32_t 	si_process_port();
uint32_t	si_prepare_background();
uint32_t 	si_process_background();
void 		si_controller_manual_identify();

__attribute__((always_inline))
static inline uint32_t si_status(void) {
	return *(volatile const uint32_t *) 0xA4800018;
}

__attribute__((always_inline))
static inline void si_set_dram_addr(uint32_t buffer_addr) {		
	*(volatile uint32_t *) 0xA4800000 = buffer_addr;
}

__attribute__((always_inline))
static inline void si_dma_read(uint32_t addr) {
	*(volatile uint32_t *) 0xA4800004 = addr;
}

__attribute__((always_inline))
static inline void si_dma_write(uint32_t addr) {
	*(volatile uint32_t *) 0xA4800010 = addr;
}

#endif