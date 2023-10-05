/*
 * Tim_private.h
 *
 *  Created on: Jun 19, 2023
 *      Author: hp
 */

#ifndef GPT_H_
#define GPT_H_

#include "Std_Types.h"

#define TIM_SR_UIF 1

void GPT_init();

void GPT_StartTimer(uint32 OverflowTicks);

uint8 GPT_CheckTimeElapsed();

uint32 GPT_GetTimeElapsed();

uint32 GPT_GetTimeRemaining();


#endif /* GPT_H_ */
