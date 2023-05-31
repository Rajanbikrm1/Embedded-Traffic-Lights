/*******************************************************************
 * TexasPortF.c
 * Author: Rajan Sah
 * Brief description of the program
 * 	Implements GPIO port F initialization and operation
 *******************************************************************/
#include "TexasPortF.h"

void initPortF(uint32_t clearPins, uint32_t digitalPins, uint32_t inputPins, uint32_t outputPins){
	volatile uint32_t delay;
	SYSCTL_RCGC2_R |= PORT_F;           // Unlock clock for port F
	delay = SYSCTL_RCGC2_R;             // Allow clock to set by delaying
	
	GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;  // Unlock port F
	GPIO_PORTF_CR_R |= clearPins;       // Enable changes for port F clear pins
	GPIO_PORTF_AMSEL_R &= CLEAR_MASK; 
	GPIO_PORTF_PCTL_R &= CLEAR_MASK;
	GPIO_PORTF_DIR_R |= outputPins;     // Set port F pins for output
	GPIO_PORTF_DIR_R &= ~inputPins;     // Clear port F pins for input
	GPIO_PORTF_AFSEL_R &= CLEAR_MASK;
	GPIO_PORTF_DEN_R |= digitalPins;    // Enable digital pins
}

void portFOutput(uint32_t outputPins){
	GPIO_PORTF_DATA_R = outputPins;
}
