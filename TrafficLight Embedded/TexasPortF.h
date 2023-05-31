/*******************************************************************
 * TexasPortF.h
 * Author: Rajan Sah
 * Brief description of the program
 * 	Defines GPIO port F initialization and operation
 *******************************************************************/
#ifndef TEXAS_PORT_F_H
#define TEXAS_PORT_F_H

#include <stdint.h>
#include "inc\tm4c123gh6pm.h"
#include "TexasInterface.h"

/**
 * Initialize port F for given pins
 *
 * @param clearPins a port F pins to be cleared in CR register
 * @param digitalPins a port F pins to use as digital pins using DEN register
 * @param inputPins a port F pins to use as input using DIR register
 * @param outputPins a port F pins to use as output using DIR register
 */
void initPortF(uint32_t clearPins, uint32_t digitalPins, uint32_t inputPins, uint32_t outputPins);

/**
 * Set the output data register for port F to given outputPins result
 * 
 * @param outputPins an output pins mask to write to data register 
 */
void portFOutput(uint32_t outputPins);

#endif /* TEXAS_PORT_F_H */
