/*******************************************************************
 * SysTick.h
 * Author: Rajan Sah
 * Brief description of the program
 *  Defines systick and implement delay using systick
 *******************************************************************/

#ifndef SYS_TICK_H
#define SYS_TICK_H

#include <stdint.h>
#include "DefaultMask.h"

#define NVIC_ST_CTRL_R    (*((volatile uint32_t *)0xE000E010))
#define NVIC_ST_RELOAD_R  (*((volatile uint32_t *)0xE000E014))
#define NVIC_ST_CURRENT_R (*((volatile uint32_t *)0xE000E018))

#define SYS_TICK_COUNT_MASK     UNIT_MASK << 16 // systick counter mask (bit 16) 
#define SYS_TICK_CLOCK_SRC_MASK UNIT_MASK << 2  // Clock Source     (bit 2)
#define SYS_TICK_INTEN_MASK     UNIT_MASK << 1  // Interrupt enable (bit 1)
#define SYS_TICK_ENABLE_MASK    UNIT_MASK << 0  // Counter mode     (bit 0)
#define SYS_TICK_MAX_RELOAD_VAL 0x00FFFFFF      // Counter load max value

/**
 * Initialize SysTick with clock source set to system bus 
 * without enabling interrupts and the reload value set to max
 * 24-bit value (0x00FFFFFF)
 * 
 */
void initSysTick(void);

/**
 * Elapsed delay by given delay second value
 * assuming clock is set at 80 MHz
 *
 * @param delay a delay value in seconds
 */
void waitElapsedDelay(uint32_t delay);

/**
 * Using reload counter delays by given delay second value
 * assuming clock is set at 80 MHz
 *
 * @param delay a delay value in seconds
 */
void waitReloadCounterDelay(uint32_t delay);

/**
 * Elapsed delay by given 12.5 ns timer loop delay value
 * assuming clock is set at 80 MHz
 *
 * @param delay a 12.5 ns time loop value
 */
void elapsedDelay(uint32_t delay);

/**
 * Elapsed delay by 62ms exact
 */
void elapsedDelay10MS(void);

/**
 * Calculate the elapsed time from given reload value/ number of
 * counts defined from delay assuming clock is set at 80 MHz
 *
 * @param delay a reload value (n + 1) 
 */
void reloadCounterDelay(uint32_t);

/**
* Delay exactly by 62ms assuming clock is set at 80 MHz
*/
void reloadCounterDelay10MS(void);

#endif /* SYS_TICK_H */
