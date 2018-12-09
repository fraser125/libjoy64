//
// libn64/include/os/si.h: SI helper functions.
//
// n64chain: A (free) open-source N64 development toolchain.
// Copyright 2017 Fraser
//			https://sites.google.com/site/consoleprotocols/
// This file is subject to the terms and conditions defined in
// 'LICENSE', which is part of this source code package.
//
#include "si.h"

uint32_t si_auto_before_vi() // 0x76 CPU Cycles aka 118 (Excluding background)
{
	if (si_console.state & SI_GSTAT_BACKGR)
	{
		// Parse Background SI Request
		si_status_zero_wait(); // Should be ZERO delay, but make sure

		si_process_background();
	}
	si_prepare_port();

	si_status_dma_io_wait();
	
	si_send_request(si_buffer_tx_ram_addr);  // Time 0x06			
	
	si_status_dma_io_wait();
	
	si_recv_response(si_buffer_rx_ram_addr); // Time 0x06		
	return 0;
}

uint32_t si_auto_after_vi() // 0x0A CPU Cycles aka 10 (Excluding background)
{
	uint32_t result = 0;
	si_status_zero_wait(); // Longest delay is potentially right here.
	
	result = si_process_port(); // Process Player Input
	
	if (si_console.state & SI_GSTAT_BACKGR)
	{
		// Create Background SI Request
		if (si_prepare_background())
		{
			si_status_dma_io_wait();		
			si_send_request(si_buffer_tx_ram_addr);
		}
	}

	return result;
}
/*
while(1) {
	
	if (requested)
	{
		recv_io();
	}
	prepare_port();
	prepare_io();
	
	send_port();
	video_interrupt();
	recv_port();
	send_io();

}
	dma wait (minimal)
controller dma tx
	dma wait (0x76)
controller dma rx
	dma wait
io dma tx
	dma wait
io dma rx

ms:us
6:60
7:210
940+210=

1150us ON
 546us OFF
 
Max bitrate 31,250 bytes / second
"Easy" 19,200 bytes / second
*/