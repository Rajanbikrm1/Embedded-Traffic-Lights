/*******************************************************************
 * TableTrafficLight.c
 * Runs on LM4F120/TM4C123
 * Index implementation of a Moore finite state machine to operate a traffic light.  
 * Author: Rajan Sah
 * Date:    07/18/2021
 *
 * east/west red light connected to PB5
 * east/west yellow light connected to PB4
 * east/west green light connected to PB3
 * north/south facing red light connected to PB2
 * north/south facing yellow light connected to PB1
 * north/south facing green light connected to PB0
 * pedestrian detector connected to PE2 (1=pedestrian present)
 * north/south car detector connected to PE1 (1=car present)
 * east/west car detector connected to PE0 (1=car present)
 * "walk" light connected to PF3 (built-in green LED)
 * "don't walk" light connected to PF1 (built-in red LED)
 *******************************************************************/
 
#include "TExaS.h"
#include "inc\tm4c123gh6pm.h"
#include "SysTick.h"
#include "FiniteStateMachine.h"
#include "TexasPortA.h"
#include "TexasPortE.h"
#include "TexasPortF.h"

extern void DisableInterrupts(void); // Disable interrupts
extern void EnableInterrupts(void);  // Enable interrupts

void init(void);                     // Initialize all ports/SysTick/interrupts

uint32_t currentState;
volatile uint32_t input;

int main(void){
	init();
	currentState = WALK_SOUTH;
	
	while(UNIT_MASK){
		portEOutput(FINITE_STATE_MACHINE[currentState].trafficLightOutput);    // set traffic lights
		portFOutput(FINITE_STATE_MACHINE[currentState].walkLightOutput);       // set walking lights
		
		waitReloadCounterDelay(FINITE_STATE_MACHINE[currentState].waitTime);
		input = portAInput(PIN_2 | PIN_3 | PIN_4, 2);
		
		currentState = FINITE_STATE_MACHINE[currentState].nextStates[input];
	}
}

void init(void){
	// Activate grader and set system clock to 80 MHz
	TExaS_Init(SW_PIN_PE210, LED_PIN_PB543210, ScopeOff);
	
	initSysTick();
	
	uint32_t pins = PIN_2 | PIN_3 | PIN_4;
	initPortA(pins, pins, pins, CLEAR_MASK);

	pins = PIN_0 | PIN_1 | PIN_2 | PIN_3 | PIN_4 | PIN_5;
	initPortE(pins, pins, CLEAR_MASK, pins);
	
	pins = PIN_1 | PIN_3;
	initPortF(pins, pins, CLEAR_MASK, pins);
	
	EnableInterrupts();
}
