/*******************************************************************
 * TexasPortA.h
 * Author: Rajan Sah
 * Brief description of the program
 * 	Defines GPIO port A initialization and operation
 *******************************************************************/
#ifndef TEXAS_PORT_A_H
#define TEXAS_PORT_A_H

#include <stdint.h>
#include "inc\tm4c123gh6pm.h"
#include "TexasInterface.h"

/**
 * Initialize port A for given pins
 *
 * @param clearPins a port A pins to be cleared in CR register
 * @param digitalPins a port A pins to use as digital pins using DEN register
 * @param inputPins a port A pins to use as input using DIR register
 * @param outputPins a port A pins to use as output using DIR register
 */
void initPortA(uint32_t clearPins, uint32_t digitalPins, uint32_t inputPins, uint32_t outputPins);

/**
 * Gets the input from port A using given input pins
 *
 * @param inputPins an input pins to read input from
 * @param shift a value to right shift the resulting output
 * 
 * @return a right shifted input result from given input pins
 */
uint32_t portAInput(uint32_t inputPins, uint32_t shift);

#endif /* TEXAS_PORT_A_H */
