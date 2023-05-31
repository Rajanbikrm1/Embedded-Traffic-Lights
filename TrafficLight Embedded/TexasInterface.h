/*******************************************************************
 * TexasInterface.h
 * Author: Rajan Sah
 * Brief description of the program
 * 	Defines TIVA LaunchPad ports and pins
 *******************************************************************/
#ifndef TEXAS_INTERFACE_H
#define TEXAS_INTERFACE_H

#include <stdint.h>
#include "DefaultMask.h"

/**
 * TIVA LaunchPad available ports
 */
typedef enum {
	PORT_A = UNIT_MASK << 0,
	PORT_B = UNIT_MASK << 1,
	PORT_C = UNIT_MASK << 2,
	PORT_D = UNIT_MASK << 3,
	PORT_E = UNIT_MASK << 4,
	PORT_F = UNIT_MASK << 5,
}	TexasPort;

/**
 * TIVA LaunchPad available pins
 */
typedef enum {
	PIN_0 = UNIT_MASK << 0,
	PIN_1 = UNIT_MASK << 1,
	PIN_2 = UNIT_MASK << 2,
	PIN_3 = UNIT_MASK << 3,
	PIN_4 = UNIT_MASK << 4,
	PIN_5 = UNIT_MASK << 5,
	PIN_6 = UNIT_MASK << 6,
	PIN_7 = UNIT_MASK << 7
} TexasPin;

#endif  /* TEXAS_INTERFACE_H */
