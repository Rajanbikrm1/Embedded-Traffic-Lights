/*******************************************************************
 * TexasPortE.c
 * Author: Rajan Sah
 * Brief description of the program
 * 	Implements GPIO port E initialization and operation
 *******************************************************************/
#include "TexasPortE.h"

void initPortE(uint32_t clearPins, uint32_t digitalPins, uint32_t inputPins, uint32_t outputPins){
	volatile uint32_t delay;
	SYSCTL_RCGC2_R |= PORT_E;           // Unlock clock for port E
	delay = SYSCTL_RCGC2_R;             // Allow clock to set by delaying
	
	GPIO_PORTE_LOCK_R = GPIO_LOCK_KEY;  // Unlock port E
	GPIO_PORTE_CR_R |= clearPins;       // Enable changes for port E clear pins
	GPIO_PORTE_AMSEL_R &= CLEAR_MASK; 
	GPIO_PORTE_PCTL_R &= CLEAR_MASK;
	GPIO_PORTE_DIR_R |= outputPins;     // Set port E pins for output
	GPIO_PORTE_DIR_R &= ~inputPins;     // Clear port E pins for input
	GPIO_PORTE_AFSEL_R &= CLEAR_MASK;
	GPIO_PORTE_DEN_R |= digitalPins;    // Enable digital pins
}

void portEOutput(uint32_t outputPins){
	GPIO_PORTE_DATA_R = outputPins;
}
