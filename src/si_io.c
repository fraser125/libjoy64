//
// libjoy64/src/si_io.c
//
// Copyright 2017 Fraser
//			https://sites.google.com/site/consoleprotocols/
// This file is subject to the terms and conditions defined in
// 'LICENSE', which is part of this source code package.
//
#include <libn64.h>
#include <stdint.h>
#include <stddef.h>
#include <syscall.h>
#include "si.h"

// Support Serial Accessories that transfer data on an as needed basis instead of every frame.
// ex. Controller Pak (Game Saves), Transfer Pak (GB/GBC), EEPROM, Pulse, Rumble, GBA?, Animal Forest RTC

// Memory MAP
//	0x8000 Rumble
//	0xC000 Pulse Sensor
// Identify Accessories
// 		Controller PAK
//		Transfer PAK
//		Pulse
//	http://www.raphnet.net/divers/n64_bio_sensor/index_en.php
//			The game simply reads 32-byte blocks from address 0xC000 at a constant interval. The bytes 
//		returned are either 0x00 or 0x03. Between heart beats, a value of 0x03 is read. During a pulse, 
//		a value of 0x00 is read.
//		Rumble
//		GBA?


// 		AF RTC
//	https://github.com/mupen64plus/mupen64plus-core/blob/6b53176d6f8f86ae0e029a85814ef7a124b1e37e/src/device/cart/cart.c
//			Status 	tx 1, rx 3		JCMD_AF_RTC_STATUS
//			Read	tx 2, rx 9		JCMD_AF_RTC_READ
//			Write	tx 10, rx 1		JCMD_AF_RTC_WRITE
// Controller Pak
// 		Note 16 Qty

// 		Sector / Page
// 			256 Bytes
// 			128 Qty
// 			5 Are the Table of Contents
// 		0x21 becomes 0xA1 when there isn't a controller attached and the I/O request is sent

// Transfer PAK (GB/GBC)
//		http://gbdev.gg8.se/wiki/articles/The_Cartridge_Header
//		Header at 0x0100 to 0x014F (Interrupt table is 0x0000 to 0x00FF
//		80 bytes = 3 requests (3 * 32 = 96)
//		Cartridge Type 0x0147
//			Officially only MBC1, MBC2 & MBC3 are supported. 
// http://ultra64.ca/files/documentation/online-manuals/man-v5-1/n64man/os/osGbpakCheckConnector.htm
//			00h  ROM ONLY                 13h  MBC3+RAM+BATTERY
// 			01h  MBC1                     15h  MBC4
//			02h  MBC1+RAM                 16h  MBC4+RAM
//			03h  MBC1+RAM+BATTERY         17h  MBC4+RAM+BATTERY
//			05h  MBC2                     19h  MBC5
//			06h  MBC2+BATTERY             1Ah  MBC5+RAM
//			08h  ROM+RAM                  1Bh  MBC5+RAM+BATTERY
//			09h  ROM+RAM+BATTERY          1Ch  MBC5+RUMBLE
//			0Bh  MMM01                    1Dh  MBC5+RUMBLE+RAM
//			0Ch  MMM01+RAM                1Eh  MBC5+RUMBLE+RAM+BATTERY
//			0Dh  MMM01+RAM+BATTERY        FCh  POCKET CAMERA
//			0Fh  MBC3+TIMER+BATTERY       FDh  BANDAI TAMA5
//			10h  MBC3+TIMER+RAM+BATTERY   FEh  HuC3
//			11h  MBC3                     FFh  HuC1+RAM+BATTERY
//			12h  MBC3+RAM
//		ROM Size 0x0148
//			00h -  32KByte (no ROM banking)
//			01h -  64KByte (4 banks)
//			02h - 128KByte (8 banks)
//			03h - 256KByte (16 banks)
//			04h - 512KByte (32 banks)
//			05h -   1MByte (64 banks)  - only 63 banks used by MBC1
//			06h -   2MByte (128 banks) - only 125 banks used by MBC1
//			07h -   4MByte (256 banks)
//			52h - 1.1MByte (72 banks)
//			53h - 1.2MByte (80 banks)
//			54h - 1.5MByte (96 banks)
//		RAM Size 0x0149
// 			00h - None
// 			01h - 2 KBytes
// 			02h - 8 Kbytes
// 			03h - 32 KBytes (4 banks of 8KBytes each)


// SI Request
// 32 Bytes
// 8 Requests / Sector
//19,200
void si_init_io()
{
}

void _si_prepare_io(uint32_t controller_index, uint32_t request_index)
{
	
	uint32_t uints_idx = 0;	// uints so 4 bytes / offset
	// Fill the Data portion to be 4 byte aligned means we can pull data out more efficiently
	// Not sure what is faster for now because the CRC is still going to require byte by byte processing
	// 0x######FF
	switch(controller_index)
	{
		case 0: 
			si_buffer_tx.raw.uints[uints_idx++] = SI_REQ_SKP_PORT_NO;
		break;
		case 1:
			si_buffer_tx.raw.uints[uints_idx++] = SI_REQ_SKP_PORT_0;
		break;
		case 2:
			si_buffer_tx.raw.uints[uints_idx++] = SI_REQ_SKP_PORT_01;
		break;
		case 3:
			si_buffer_tx.raw.uints[uints_idx++] = SI_REQ_SKP_PORT_012;
		break;
	}
	uint32_t command = SI_REQ_CPAK_R1;
	// TODO: Set Address & CRC of address	
	// request_index
	if (request_index > 0)
	{
	}
	si_buffer_tx.raw.uints[uints_idx++] = command;
	
	uint32_t last_idx = uints_idx + 8;
	
	for(uint32_t idx = uints_idx; idx < last_idx; idx++)
		si_buffer_tx.raw.uints[idx] = SI_REQ_FILL_FF;
		
	si_buffer_tx.raw.uints[last_idx] = SI_REQ_CPAK_END;
	si_buffer_tx.raw.bytes[63] = 0x01;
}

uint32_t si_io_read(uint32_t controller_index)
{
	if (controller_index > (MAX_CONTROLLERS - 1))
		return INVALID_CONTROLLER_COUNT;	
		
  	struct timeval startTime;
	struct timeval endTime;

	_si_prepare_io(controller_index, 0);

	si_status_dma_io_wait();
	si_send_request(si_buffer_tx_ram_addr);  // Time 0x06			
	
	startTime = libn64_time();	
	si_status_dma_io_wait();
	endTime = libn64_time();

	si_recv_response(si_buffer_rx_ram_addr); // Time 0x06	
	
	return (endTime.tv_usec - startTime.tv_usec) << 1;	
}


uint32_t si_toc_prepare(uint32_t controller_index)
{
	if (controller_index > (MAX_CONTROLLERS - 1))
		return INVALID_CONTROLLER_COUNT;	

	uint32_t result = NO_ERROR;
	si_status_dma_io_wait();
	// Do work here
	return result;
}

uint32_t si_toc_process()
{
	uint32_t result = NO_ERROR;
	si_status_dma_io_wait();
	// Do work here
	return result;
}

uint32_t si_pak_read(uint32_t controller_index, uint32_t entry_id, uint32_t length, void * dest)
{
	uint32_t result = NO_ERROR;
	if (controller_index > (MAX_CONTROLLERS - 1))
		return INVALID_CONTROLLER_COUNT;	
	if (entry_id > 15)
		return INVALID_ENTRY_ID;
	if (length == 0)
		return INVALID_LENGTH;
	if (dest == NULL)
		return INVALID_DATA;
	// TODO: The work
	return result;
}

uint32_t si_pak_write(uint32_t controller_index, uint32_t entry_id, uint32_t length, void * source)
{
	uint32_t result = NO_ERROR;
	if (controller_index > (MAX_CONTROLLERS - 1))
		return INVALID_CONTROLLER_COUNT;	
	if (entry_id > 15)
		return INVALID_ENTRY_ID;
	if (length == 0)
		return INVALID_LENGTH;
	if (source == NULL)
		return INVALID_DATA;
	// TODO: The work
	return result;
}

uint32_t si_pak_delete(uint32_t controller_index, uint32_t entry_id)
{
	uint32_t result = NO_ERROR;
	if (controller_index > (MAX_CONTROLLERS - 1))
		return INVALID_CONTROLLER_COUNT;	
	if (entry_id > 15)
		return INVALID_ENTRY_ID;
	// TODO: The work
	return result;
}