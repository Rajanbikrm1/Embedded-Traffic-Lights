/*******************************************************************
 * DefaultMash.h
 * Author: Rajan Sah
 * Brief description of the program
 * 	Defines default unit and clear mask value
 *******************************************************************/
#ifndef DEFAULT_MASK_H
#define DEFAULT_MASK_H

/**
 * Default unit and clear flag mask
 */
typedef enum {
	CLEAR_MASK = 0x00000000,
	UNIT_MASK  = 0x00000001
} DefaultMask;
 
#endif /* DEFAULT_MASK_H */
