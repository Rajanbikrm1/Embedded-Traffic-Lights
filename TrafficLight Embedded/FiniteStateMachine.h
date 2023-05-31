/*******************************************************************
 * FiniteStateMachine.h
 * Author: Rajan Sah
 * Brief description of the program
 * 	Defines Moore's finite state machine for traffic light of 3 inputs
 *  9 outputs and 20 states
 *******************************************************************/
#ifndef FINITE_STATE_MACHINE_H
#define FINITE_STATE_MACHINE_H

#include <stdint.h>

/**
 * Next state index for Moore Finite State
 */
typedef enum {
	WALK_SOUTH = 0,							// Pedestrian using south(north) walk
	DONT_WALK_WEST_0, 					// Do not walk flash led to west(east) 0
    DONT_WALK_WEST_1,  					// Do not walk flash led to west(east) 1
	DONT_WALK_WEST_2,  					// Do not walk flash led to west(east) 2
	DONT_WALK_WEST_3,  					// Do not walk flash led to west(east) 3
	DONT_WALK_WEST_4,  					// Do not walk flash led to west(east) 4
	DONT_WALK_SOUTH_0,  				// Do not walk flash led to south(north) 0
	DONT_WALK_SOUTH_1,  				// Do not walk flash led to south(north) 1
	DONT_WALK_SOUTH_2,  				// Do not walk flash led to south(north) 2
	DONT_WALK_SOUTH_3,  				// Do not walk flash led to south(north) 3
	DONT_WALK_SOUTH_4,  				// Do not walk flash led to south(north) 4
	GREEN_WEST,  								// Green light proceeding traffic from/to west(east)
	YELLOW_WEST, 								// Yellow light proceeding traffic from/to west(east)
	WALK_PRESSED_GREEN_WEST_0, 	// Green light to west(east) with walk light pressed for 1 second
	WALK_PRESSED_GREEN_WEST_1, 	// Green light to West(east) with walk light pressed for 2 second
	GREEN_SOUTH,								// Green light proceeding traffic from/to south(north)
	YELLOW_SOUTH, 							// Yellow light proceeding traffic from/to south(north)
	WALK_PRESSED_GREEN_SOUTH_0,	// Green light to south(north) with walk light pressed for 1 second
	WALK_PRESSED_GREEN_SOUTH_1, // Green light to south(north) with walk light pressed for 2 second
	WALK_WEST, 									// Pedestrian using east(west) walk
}	FiniteStateIndex;

/**
 * Moore Finite State
 */
typedef const struct {
	uint32_t trafficLightOutput;     // Traffic light sensor output
	uint32_t walkLightOutput;        // Walk light sensor output
	uint32_t waitTime;               // Delay wait time in seconds
	FiniteStateIndex nextStates[8];
} FiniteState;

/**
 * Moore's finite state machine
 */
const FiniteState FINITE_STATE_MACHINE[20] = {
								        // 000,        001               010                011                100            101              110               111             
/*WS*/  {0x24, 0x08, 50, {WALK_SOUTH, DONT_WALK_WEST_0, DONT_WALK_SOUTH_0, DONT_WALK_SOUTH_0, WALK_SOUTH, DONT_WALK_WEST_0, DONT_WALK_SOUTH_0, DONT_WALK_SOUTH_0}},
/*DWW0*/{0x24, 0x02, 10, {DONT_WALK_WEST_1, DONT_WALK_WEST_1, DONT_WALK_WEST_1, DONT_WALK_WEST_1, DONT_WALK_WEST_1, DONT_WALK_WEST_1, DONT_WALK_WEST_1, DONT_WALK_WEST_1}},
/*DWW1*/{0x24, 0x00, 10, {DONT_WALK_WEST_2, DONT_WALK_WEST_2, DONT_WALK_WEST_2, DONT_WALK_WEST_2, DONT_WALK_WEST_2, DONT_WALK_WEST_2, DONT_WALK_WEST_2, DONT_WALK_WEST_2}},
/*DWW2*/{0x24, 0x02, 10, {DONT_WALK_WEST_3, DONT_WALK_WEST_3, DONT_WALK_WEST_3, DONT_WALK_WEST_3, DONT_WALK_WEST_3,DONT_WALK_WEST_3, DONT_WALK_WEST_3, DONT_WALK_WEST_3}},
/*DWW3*/{0x24, 0x00, 10, {DONT_WALK_WEST_4, DONT_WALK_WEST_4, DONT_WALK_WEST_4, DONT_WALK_WEST_4, DONT_WALK_WEST_4, DONT_WALK_WEST_4, DONT_WALK_WEST_4, DONT_WALK_WEST_4}},
/*DWW4*/{0x24, 0x02, 10, {GREEN_WEST, GREEN_WEST, GREEN_WEST, GREEN_WEST, GREEN_WEST, GREEN_WEST, GREEN_WEST, GREEN_WEST}},
/*DWS0*/{0x24, 0x02, 10, {DONT_WALK_SOUTH_1, DONT_WALK_SOUTH_1, DONT_WALK_SOUTH_1, DONT_WALK_SOUTH_1, DONT_WALK_SOUTH_1, DONT_WALK_SOUTH_1, DONT_WALK_SOUTH_1, DONT_WALK_SOUTH_1}},
/*DWS1*/{0x24, 0x00, 10, {DONT_WALK_SOUTH_2, DONT_WALK_SOUTH_2, DONT_WALK_SOUTH_2, DONT_WALK_SOUTH_2, DONT_WALK_SOUTH_2, DONT_WALK_SOUTH_2, DONT_WALK_SOUTH_2, DONT_WALK_SOUTH_2}},
/*DWS2*/{0x24, 0x02, 10, {DONT_WALK_SOUTH_3, DONT_WALK_SOUTH_3, DONT_WALK_SOUTH_3, DONT_WALK_SOUTH_3, DONT_WALK_SOUTH_3, DONT_WALK_SOUTH_3, DONT_WALK_SOUTH_3, DONT_WALK_SOUTH_3}},
/*DWS3*/{0x24, 0x00, 10, {DONT_WALK_SOUTH_4, DONT_WALK_SOUTH_4, DONT_WALK_SOUTH_4, DONT_WALK_SOUTH_4, DONT_WALK_SOUTH_4,DONT_WALK_SOUTH_4, DONT_WALK_SOUTH_4, DONT_WALK_SOUTH_4}},
/*DWS4*/{0x24, 0x02, 10, {GREEN_SOUTH, GREEN_SOUTH, GREEN_SOUTH, GREEN_SOUTH, GREEN_SOUTH, GREEN_SOUTH, GREEN_SOUTH,GREEN_SOUTH}},
/*GW*/	{0x0C, 0x02, 30, {GREEN_WEST, GREEN_WEST, YELLOW_WEST, YELLOW_WEST, WALK_PRESSED_GREEN_WEST_0, WALK_PRESSED_GREEN_WEST_0, WALK_PRESSED_GREEN_WEST_0, WALK_PRESSED_GREEN_WEST_0}},
/*YW*/	{0x14, 0x02, 20, {WALK_SOUTH, DONT_WALK_WEST_4, DONT_WALK_SOUTH_4, DONT_WALK_SOUTH_4, WALK_SOUTH, WALK_SOUTH, WALK_SOUTH, WALK_SOUTH}},
/*WPGW0*/{0x0C, 0x02, 10, {GREEN_WEST, GREEN_WEST, GREEN_WEST, GREEN_WEST, WALK_PRESSED_GREEN_WEST_1, WALK_PRESSED_GREEN_WEST_1, WALK_PRESSED_GREEN_WEST_1, WALK_PRESSED_GREEN_WEST_1}},
/*WPGW1*/{0x0C, 0x02, 10, {WALK_PRESSED_GREEN_WEST_0, WALK_PRESSED_GREEN_WEST_0, WALK_PRESSED_GREEN_WEST_0, WALK_PRESSED_GREEN_WEST_0, YELLOW_WEST, YELLOW_WEST, YELLOW_WEST, YELLOW_WEST}},
/*GS*/	{0x21, 0x02, 30, {GREEN_SOUTH, YELLOW_SOUTH, GREEN_SOUTH, YELLOW_SOUTH, WALK_PRESSED_GREEN_SOUTH_0, WALK_PRESSED_GREEN_SOUTH_0, WALK_PRESSED_GREEN_SOUTH_0, WALK_PRESSED_GREEN_SOUTH_0}},
/*YS*/	{0x22, 0x02, 20, {WALK_WEST, DONT_WALK_WEST_4, DONT_WALK_SOUTH_4, DONT_WALK_WEST_4, WALK_WEST, WALK_WEST, WALK_WEST, WALK_WEST}},
/*WPGS0*/{0x21, 0x02, 10, {GREEN_SOUTH, GREEN_SOUTH, GREEN_SOUTH, GREEN_SOUTH, WALK_PRESSED_GREEN_SOUTH_1, WALK_PRESSED_GREEN_SOUTH_1, WALK_PRESSED_GREEN_SOUTH_1, WALK_PRESSED_GREEN_SOUTH_1}},
/*WPGS1*/{0x21, 0x02, 10, {WALK_PRESSED_GREEN_SOUTH_0, WALK_PRESSED_GREEN_SOUTH_0, WALK_PRESSED_GREEN_SOUTH_0, WALK_PRESSED_GREEN_SOUTH_0, YELLOW_SOUTH, YELLOW_SOUTH, YELLOW_SOUTH, YELLOW_SOUTH}},
/*WW*/  {0x24, 0x08, 50, {WALK_WEST, DONT_WALK_WEST_0, DONT_WALK_SOUTH_0, DONT_WALK_WEST_0, WALK_WEST, DONT_WALK_WEST_0,DONT_WALK_SOUTH_0, DONT_WALK_WEST_0}}
};

#endif /* FINITE_STATE_MACHINE_H */
