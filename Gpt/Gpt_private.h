/*
 * Gpt_private.h
 *
 *  Created on: Jun 19, 2023
 *      Author: hp
 */

#ifndef GPT_PRIVATE_H_
#define GPT_PRIVATE_H_

#include "Std_Types.h"

// #define GPT_BASE_ADDR
// #define GPT_BASE_ADDR

//#define GPT_BASE_ADDR 0x
#define TIM2_BASE_ADDR 0x40000000

typedef struct {
	uint32 CR1;
	uint32 CR2;
	uint32 SMCR;
	uint32 DIER;
	uint32 SR;
	uint32 EGR;
	uint32 CCMR1;
	uint32 CCMR2;
	uint32 CCER;
	uint32 CNT;
	uint32 PSC;
	uint32 ARR;
	uint32 CCR1;
	uint32 CCR2;
	uint32 CCR3;
	uint32 CCR4;
	uint32 DCR;
	uint32 DMAR;
	uint32 OR;
} TimType;



#endif /* GPT_PRIVATE_H_ */
