/*******************************************************************
 * TexasPortA.c
 * Author: Rajan Sah
 * Brief description of the program
 * 	Implements GPIO port A initialization and operation
 *******************************************************************/
#include "TexasPortA.h"

void initPortA(uint32_t clearPins, uint32_t digitalPins, uint32_t inputPins, uint32_t outputPins){
	volatile uint32_t delay;
	SYSCTL_RCGC2_R |= PORT_A;           // Unlock clock for port A
	delay = SYSCTL_RCGC2_R;             // Allow clock to set by delaying
	
	GPIO_PORTA_LOCK_R = GPIO_LOCK_KEY;  // Unlock port A
	GPIO_PORTA_CR_R |= clearPins;       // Enable changes for port A clear pins
	GPIO_PORTA_AMSEL_R &= CLEAR_MASK; 
	GPIO_PORTA_PCTL_R &= CLEAR_MASK;
	GPIO_PORTA_DIR_R |= outputPins;     // Set port A pins for output
	GPIO_PORTA_DIR_R &= ~inputPins;     // Clear port A pins for input
	GPIO_PORTA_AFSEL_R &= CLEAR_MASK;
	GPIO_PORTA_DEN_R |= digitalPins;    // Enable digital pins
}

uint32_t portAInput(uint32_t inputPins, uint32_t shift){
	return (GPIO_PORTA_DATA_R & inputPins) >> shift;
}
