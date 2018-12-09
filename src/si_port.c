//
// libn64/os/si_port.c: controller input functions.
//
// n64chain: A (free) open-source N64 development toolchain.
// Copyright 2017 Fraser
//			https://sites.google.com/site/consoleprotocols/
// This file is subject to the terms and conditions defined in
// 'LICENSE', which is part of this source code package.
//
#include "si.h"
uint32_t si_prepare_background()
{
	// The trick here is that each of these are 32 byte reads/writes.
	// Each must be done one at a time
	//	The programmer initializing with an appropriate controller count will really help.
	
	// We kind of have to assume if the gamer is "hot swapping" they are ok with 
	//	several frames (to several seconds) of lag before something works.
	//	The number of controllers will also affect when the controller data is ready.
	// Examples if Single Controller initialized:
	//		Controllers (1 frame identify, next frame data) Main thread.
	// 		Rumble (2 frame Identify, next frame enable)
	// 		Pulse Sensor (2 frame Identify, next frame enable)
	//		Transfer PAK (6 frame Identify, 3 frame load header)
	//		Controller PAK (2 frame Identify, 40 frame load Table of Contents)	
	//  The max lag would be 4 controllers with 4 controller pak's (168 frames or 2.8 seconds)
	//	
	//		This might not seem "fast enough" to some, I'd ask how long does it take a player
	// 	to insert any of these accessories and look at the screen. The accessory will be identified 
	//  before they look and the background data will already be loaded by the time they are ready
	//  to take their next action.
	//		Loading an entire controller PAK or Transfer PAK will have their own api's.
	
	// 1. identify the accessories
	//		If an accessory is removed or swapped in always do identify
	// 2. Identify EEPROM
	// 3. Load/Manage devices
	// 		1. Read GB/GBC Header (2 reads)
	// 		2. retrieve input data (i.e. Pulse Sensor)
	// 		3. manage rumble pak
	// 		4. Controller PAK ToC
	uint32_t buffer_offset = 0;	// uints so 4 bytes / offset	
	uint32_t controllers_checked = 0;
	uint32_t work_queued = 0;
	do
	{
		if (si_console.port[si_controller_background_index].device.dev_type.id == N64_CONTROLLER)
		{		
			if (si_console.port[si_controller_background_index].device.dev_type.acc == SI_ACC_UNKNOWN)
			{
				// Send Write 0xFE to 0x8000
				si_buffer_tx.raw.uints[buffer_offset++] = 0x0;
				si_console.port[si_controller_background_index].device.dev_type.acc = SI_ACC_REQUESTW;
				work_queued++;
			}
			else if (si_console.port[si_controller_background_index].device.dev_type.acc == SI_ACC_REQUESTW)
			{
				// Send Read to 0x8000
				si_buffer_tx.raw.uints[buffer_offset++] = 0x0;
				// Response: 0xE1 with memory pak, 0x1E without.
				si_console.port[si_controller_background_index].device.dev_type.acc = SI_ACC_REQUESTR;
				work_queued++;
			}
			else
			{
				switch(si_console.port[si_controller_background_index].device.dev_type.acc)
				{				
					case SI_ACC_RUMB_PAK:
					{
						if (si_console.port[si_controller_background_index].device.dev_type.state & SI_GSTAT_ACC_ON)
						{
							// Send Command to Turn ON Rumble
							// Send Write 0x01 to 0xC000
						}
						else
						{
							// Send Command to Turn OFF Rumble
							// Send Write 0x00 to 0xC000
						}
					}
					break;
					case SI_ACC_PULS_PAK:
					{
						// Send command to take pulse reading
					}
					break;
					case SI_ACC_CONT_PAK:
					{
						// Load Table of Contents.
					}
					break;
					case SI_ACC_TXFR_PAK:
					{
						// Load GB/GBC Header
					}
					break;
				}
			}
		}
		if (!work_queued)
		{
			// si_controller_background_index Increment
		}
	}
	while (work_queued == 0 && controllers_checked < si_console.portcount);
	if (work_queued)
	{
		si_buffer_tx.raw.uints[buffer_offset] = SI_REQ_FINL_CH;
		si_buffer_tx.raw.bytes[63] = 0x01;
	}
	return work_queued;
}

void si_prepare_port()
{
	uint32_t buffer_offset = 0;	// uints so 4 bytes / offset
	uint32_t controller_count = si_console.portcount;
	for( uint32_t idx = 0; idx < controller_count; idx++)
	{						
		switch(si_console.port[idx].device.dev_type.id)
		{
			case N64_CONTROLLER:
			case N64_MOUSE:
			case N64_DENSHA: // Query Controller Data			
			{		
				si_buffer_tx.raw.uints[buffer_offset++] = SI_REQ_CONT_ST;															
				si_buffer_tx.raw.uints[buffer_offset++] = SI_REQ_FILL_FF;												
			}
			break;	
			case N64_KEYBOARD:
			{
				//buffer_offset+=4;
				si_buffer_tx.raw.uints[buffer_offset++] = SI_REQ_KYBD_ST;
				si_buffer_tx.raw.uints[buffer_offset++] = SI_REQ_FILL_FF;
				si_buffer_tx.raw.uints[buffer_offset++] = SI_REQ_FILL_FF;
			}
			break;
			default: // Type Query or Reset
			{				
				si_buffer_tx.raw.uints[buffer_offset++] = SI_REQ_CONT_QY;				
				si_buffer_tx.raw.uints[buffer_offset++] = SI_REQ_FILL_FF;								
			}
			break;
		}
	}
	si_buffer_tx.raw.uints[buffer_offset] = SI_REQ_FINL_CH;
	si_buffer_tx.raw.bytes[63] = 0x01;
}

uint32_t si_process_background()
{
	return 0;
}

uint32_t si_process_port()
{
	uint32_t port_idx = 0;
	
	uint32_t result = NO_ERROR;
	for(uint32_t rx_uint_idx = 0;rx_uint_idx < 16; rx_uint_idx++)
	{		
		uint32_t requestCommand = si_buffer_rx.raw.uints[rx_uint_idx];
		uint32_t error = (requestCommand & 0xC000) >> 8;
		rx_uint_idx++;
		if (error > 0)
		{
			si_console.port[port_idx].device.raw = 0xFFFFFF00 | error | SI_PSTAT_CHANG;
			si_console.port[port_idx].data.raw[0] = 0x0;
			si_console.port[port_idx].data.raw[1] = 0x0;
		}
		else if (requestCommand == SI_REQ_CONT_QY)
		{
			uint32_t responseValue = si_buffer_rx.raw.uints[rx_uint_idx];
			// TODO: Process Held & Released Properties
			si_console.port[port_idx].device.raw = (responseValue & 0xFFFFFF00) | SI_PSTAT_CHANG;
		}
		else if (requestCommand == SI_REQ_CONT_ST)
		{			
			si_console.port[port_idx].data.raw[0] = si_buffer_rx.raw.uints[rx_uint_idx];			
			result = SI_REQ_CONT_ST;
		}		
		else if (requestCommand == SI_REQ_KYBD_ST)
		{
			// TODO: Convert Keys
			si_console.port[port_idx].data.raw[0] = si_buffer_rx.raw.uints[rx_uint_idx++];			
			si_console.port[port_idx].data.raw[1] = si_buffer_rx.raw.uints[rx_uint_idx++];
			result = SI_REQ_KYBD_ST;
		}
		else if (requestCommand == SI_REQ_FINL_CH)
		{
			break; // exit for loop when 0xFE000000 is found. 
		}	
		else if (requestCommand == 0x0)
		{
			// Ignored
		}
		else
		{
			result = requestCommand;
		}
		port_idx++;
		if (port_idx > (MAX_CONTROLLERS - 1))
			break;
	}
	return result;
}

// If you want to offer the use of Non-Standard controllers
// 1. Prompt user to Hold "Start + A" buttons
// 2. Call in a loop for 5-10 seconds or whatever you think your user needs.
void si_controller_manual_identify()
{
	for(uint32_t idx = 0; idx < MAX_CONTROLLERS; idx++)
	{
		uint32_t buttons = (si_console.port[idx].data.controller.pressed);
		if ((buttons & DENSHA_TYPE_TEST) == DENSHA_TYPE_TEST)
			si_console.port[idx].device.raw = ((N64_DENSHA << 16) & 0x0200);
		else if ((buttons & STANDARD_TYPE_TEST) == STANDARD_TYPE_TEST)
			si_console.port[idx].device.raw = ((N64_CONTROLLER << 16) & 0x0200);
	}
}