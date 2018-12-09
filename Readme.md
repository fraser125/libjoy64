# The N64 Serial/Controller Interface
## About
This has been a long project with lots of research. The following are the project goals.
1. Support all N64 controller port devices
2. Allow hot-swapping of all devices.
3. Support all N64 accessories
4. Allow hot-swapping of all accessories
5. Ease of Use
6. Performance
### Devices
* Standard Tri-Wing Controller (Official and 3rd Party)
** Includes non-standard appearing controllers like N64 Glove, Ultraracer, ASCII Controller
* N64 Mouse
* Densha de Go! Train Simulation Controller
* RandNET Keyboard (Detected, Full support is Planned)
* VRU (Detected, Full support is Planned)
### Accessories
* Rumble PAK (Planned)
* Controller PAK aka game save memory (Planned)
* Transfer PAK (Planned)
* Pulse Sensor (Planned)
### Ease of Use
Easy to use in this case means a minimum of API's and many "just work", once setup.
### Performance
A lot of thought and research went into making this api simple, flexible and perform well.

With all of the effort put in to the other features, it seems like performance might suffer. 
The goal is for all standard controller input, excluding Save Files and Gameboy game loading will take less than 0.00002 of each frame @ 60 FPS or 312 or fewer instructions. Features that would require more than this will have dedicated API's for their functionality.

If the game/program only needs 1 controller port only poll 1 controller. The API will be much faster if only 1 controllers input is needed. 

The 4 controller input (excluding accessories): 160
The 4 controller input w/ accessories: ###

The Math: 93.75 MHz processor. 93,750,000 Instructions/Second.
60 Frames per Second = 1,562,500 Instructions/Second.
1/10,000 of a frame = 156.25 Instructions
2/10,000 of a frame = 312.5 Instructions.

## Library or standalone code Usage
NOTE: If your N64 Homebrew library has different recommendations use them, see usage for all homebrew libraries below.
The following tips apply to most scenarios.

For standard controller input:
There are just a few api calls that do most of the work managing the button and analog input for all of the standard controller types.

```C
#define num_controller_ports 4;
	si_init(num_controller_ports, false);
```
	
	This initializes the serial interface and sets the maximum number of controllers that will be polled on each cycle. Fewer controllers being polled will reduce the processing time and the "delay time". The boolean parameter allows for background processing of accessories, like Rumble. 

	It's important even if your framerate is low to always process player input consistently. The best way to do this is to trigger off the VI interrupt which is always 60 FPS. The other game feature that needs to be consistent even more than input is audio. I suggest the following sequence of events once VI fires.
	
```C
	si_prepare_request(num_controller_ports); // SI 
	// Swap Frame Buffer if it's ready
	// Queue up one frame of audio
	si_status_dma_io_wait(); // Optional if the above tasks don't take long enough.
	si_process_response(); // SI
```
	There may be other small tasks that can be done between these 2 primary calls, that is fine. There are up to 3400 CPU Instructions available before the results are ready. It's OK to do other tasks and wait longer before processing the response.
	
	Those 2 api's manage the different states of a controller from first plugged in, idenfying and querying them for their button or analog status.
	
	The controller type, status and data are all stored in global structs, so test the controller input types use the following code:
	
## Usage for all Homebrew Libraries
	
```C
	if (si_port[controller_idx].device.dev_type.id == N64_CONTROLLER)
```
	Other constants that can be tested for include: N64_DANCEPAD, N64_MOUSE, N64_DENSHA, N64_DANCEPAD. It's a good idea to ignore the following types for standard game input: N64_VRU, N64_KEYBOARD they are handled by other api calls.
	
	To test the buttons of a controller use the following code:
```C
	if (si_port[controller_idx].status.controller.buttons & BUTTON_A)
	{
		// Do Something
	}
	if (si_port[controller_idx].status.controller.joyx != 0)
	{
		// Do Something
	}
	if (si_port[controller_idx].status.controller.joyy != 0)
	{
		// Do Something
	}
```
	The struct holding the controller input data is 'si_port', it's a 4 element array of device and status information. The supported devices each have their own nested struct. 
	
	The device id (i.e. si_port[0].device.dev_type.id) may have the following values:
		N64_CONTROLLER the standard "Tri-wing" controller.
			si_port[0].status.controller.buttons
			si_port[0].status.controller.joyx
			si_port[0].status.controller.joyy
		N64_DANCEPAD the Disney Dancepad (Id's the same as a controller)
		N64_MOUSE The mouse that is included with the 64DD Mario Artist game.
			si_port[0].status.mouse.buttons
			si_port[0].status.mouse.movex
			si_port[0].status.mouse.movey
		N64_DENSHA The Train Controller
			si_port[controller_idx].status.densha_de_go.buttons
		N64_VRU Voice Recognition Unit
			Handled seperately only identified by this api.
		N64_KEYBOARD The RandNET keyboard
			Handled seperately only identified by this api.
			
The controller button constants are:
	BUTTON_A, BUTTON_B, BUTTON_Z, BUTTON_START,
	BUTTON_DUP, BUTTON_DDOWN, BUTTON_DLEFT, BUTTON_DRIGHT,
	BUTTON_RESET, BUTTON_TLEFT, BUTTON_TRIGHT
	BUTTON_CUP, BUTTON_CDOWN, BUTTON_CLEFT, BUTTON_CRIGHT
The mouse button constants are:
	MOUSE_LEFT, MOUSE_RIGHT
The train controller constants are:
	DENSHA_B_START, DENSHA_B_SELECT
	DENSHA_BUTTON_A, DENSHA_BUTTON_B, DENSHA_BUTTON_C, 
	DENSHA_BRK_OFF, DENSHA_BRK_01, DENSHA_BRK_02, DENSHA_BRK_03, DENSHA_BRK_04, DENSHA_BRK_05,
	DENSHA_BRK_06, DENSHA_BRK_07, DENSHA_BRK_08, DENSHA_BRK_09, DENSHA_BRK_10, DENSHA_BRK_11,
	DENSHA_BRK_12, DENSHA_BRK_13, DENSHA_BRK_14, DENSHA_BRK_INVAL,
	DENSHA_MASTER_0, DENSHA_MASTER_1, DENSHA_MASTER_2, DENSHA_MASTER_3, DENSHA_MASTER_4, DENSHA_MASTER_5, 

## Train Controller i.e. Densha de Go! custom Controller

The Train controller identifies itself as a standard controller, the best way to tell the game that it's a Train controller is asking the user to press Start + A at the same time. 

The A button has a different value between the Train and standard controllers. Using the Start button makes it a very concious action on the part of the user. Present a (Controller Selection) screen that prompts all users to press "Start + A". while calling this api.

```C
	si_controller_manual_identify()
```

FYI: Pressing "Start + B" while calling the API will restore the Standard Controller setting. Effectively toggling modes by pressing "Start + A" then "Start + B". 
