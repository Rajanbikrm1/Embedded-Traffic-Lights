/*******************************************************************
 * SysTick.c
 * Author: Rajan Sah
 * Brief description of the program
 *  Implement systick and implement delay using systick
 *******************************************************************/
#include "SysTick.h"

void initSysTick(void){
	NVIC_ST_CTRL_R = CLEAR_MASK;
	NVIC_ST_RELOAD_R = SYS_TICK_MAX_RELOAD_VAL;
	NVIC_ST_CURRENT_R = CLEAR_MASK;
	NVIC_ST_CTRL_R = SYS_TICK_ENABLE_MASK | SYS_TICK_CLOCK_SRC_MASK;
}

void waitElapsedDelay(uint32_t delay){
	while(delay--){
		elapsedDelay10MS();
	}
}

void waitReloadCounterDelay(uint32_t delay){
	while(delay--){
		reloadCounterDelay10MS();
	}
}

void elapsedDelay(uint32_t delay){
	volatile uint32_t startTime; 
	delay &= SYS_TICK_MAX_RELOAD_VAL;  // Set delay to 24 bit max reloadable value if greater
	startTime = NVIC_ST_CURRENT_R;     // Set current time to current tick 
	while(((startTime - NVIC_ST_CURRENT_R) & SYS_TICK_MAX_RELOAD_VAL) < delay);
}

void elapsedDelay10MS(void){
	elapsedDelay(800000);
}

void reloadCounterDelay(uint32_t delay){
	delay = delay - 1;
	NVIC_ST_RELOAD_R = delay;
	NVIC_ST_CURRENT_R = delay;
	while(!(NVIC_ST_CTRL_R & SYS_TICK_COUNT_MASK));
}

void reloadCounterDelay10MS(void){
	reloadCounterDelay(800000);
}
