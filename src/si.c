//
// libjoy64/include/os/si.h: SI helper functions.
//
// Copyright 2017 Fraser
//			https://sites.google.com/site/consoleprotocols/
// This file is subject to the terms and conditions defined in
// 'LICENSE', which is part of this source code package.
//
#include "si.h"

// enableBackground will enable the easy use of si accessories
// Example:
//		Identify Controller Accessories
//		Enable/Disable Rumble
//		Get Pulse Sensor Readings
//		Read the Table of Contents for Memory PAK's
//		Read the Header of Gameboy Carts
//		Initialize the VRU/VRS, except Word List
// If you are using any of these features this will make your work easier.
// The processing time taken for these actions is very minimal
void si_init(uint32_t port_enable_count, uint32_t enableBackground)
{
	if (port_enable_count > MAX_CONTROLLERS)
		port_enable_count = 1;	

	si_console.portcount = port_enable_count;
	
	if (enableBackground)
		si_console.state = SI_GSTAT_BACKGR;
	else
		si_console.state = SI_GSTAT_INIT;
	
	si_buffer_tx_ram_addr = (((uint32_t)&si_buffer_tx) & RDRAM_DIRECT_MASK);
	si_buffer_rx_ram_addr = (((uint32_t)&si_buffer_rx) & RDRAM_DIRECT_MASK);
	si_controller_background_index = 0;
	si_init_tx_buffer();
	si_init_devices();
}

void si_init_tx_buffer()
{
	for(uint32_t idx = 0; idx < 16; idx++)
		si_buffer_tx.raw.uints[idx] = 0x0;
}

void si_init_devices()
{
	for(uint32_t idx = 0;idx < MAX_CONTROLLERS; idx++)
	{
		si_console.port[idx].device.raw = 0x0;
		si_console.port[idx].data.raw[0] = 0x0;
		si_console.port[idx].data.raw[1] = 0x0;
	}
}

void si_status_zero_wait()
{
	uint32_t status = 0;
	do
	{
		status = si_status();
	}
	while (status > 0);
}

void si_status_dma_io_wait()
{
	uint32_t status = 0;
	do
	{
		status = (si_status() & (SI_STATUS_IO_BUSY | SI_STATUS_DMA_BUSY));		
	}
	while (status > 0);
}

void si_send_request(uint32_t buffer_addr)
{
	si_set_dram_addr(buffer_addr);
	si_dma_write(PIF_RAM_ADDR);
}


void si_recv_response(uint32_t buffer_addr)
{  		
	si_set_dram_addr(buffer_addr);
	si_dma_read(PIF_RAM_ADDR);	
}