/*
 * Gpt.c
 *
 *  Created on: Jun 19, 2023
 *      Author: hp
 */
#include "Gpt.h"
#include "Gpt_private.h"
#include "Rcc.h"
#include "Rcc_Private.h"
#include "Bit_Operations.h"

TimType *TIM2 = 0x40000000;

uint8 gpt_StartTimer_flag = 0 ;

void GPT_init(){
    Rcc_Enable(RCC_TIM2);
    // Set TIM_PSC to CK_CNT = fck/(PSC+1)
    TIM2->PSC = 15;
    TIM2->ARR = 2000000;
    TIM2->CNT =0;
    SET_BIT(TIM2->CR1,0);
    // Note on Teams
    // TIM2->EGR |= 1<< 0;
}

void GPT_StartTimer(uint32 OverflowTicks){
    gpt_StartTimer_flag = 1 ;

    unsigned int counter = 0;
	unsigned int goalcount = OverflowTicks;
	unsigned int currentCNTval = 0;
	unsigned int prevCNTval = 0;
	unsigned int countToAdd = 0;
	prevCNTval = TIM2->CNT;

	while (counter < goalcount){
		currentCNTval = TIM2->CNT;

		if(currentCNTval < prevCNTval ){
			countToAdd = (OverflowTicks - prevCNTval)+ currentCNTval;
		}
		else {
			countToAdd = currentCNTval - prevCNTval;
		}
		counter += countToAdd;

		prevCNTval = currentCNTval;
	}
}


uint8 GPT_CheckTimeElapsed(){
    if(TIM2->SR & TIM_SR_UIF){
        CLEAR_BIT(TIM2->SR,0);
        // TIM2->SR &= ~TIM_SR_UIF;
        return 1;
    }
    else{
        return 0;
    }
}

uint32 GPT_GetTimeElapsed(){
    // should call check
    uint8 check = GPT_CheckTimeElapsed();
    // if 0 no call of starttimer and oxffffffff if overflow, if 1 no overflow return number of elapsed ticks
    if(gpt_StartTimer_flag==0){
        return 0;
    }
    else if(check==0 && gpt_StartTimer_flag !=0)
        //  return elapsed ticks
        return TIM2->CNT;
    else if (check==1 && gpt_StartTimer_flag !=0){
        // overflow occured
        return 0xffffffff;
    }
}


uint32 GPT_GetTimeRemaining(){
    // should call check
    uint8 check = GPT_CheckTimeElapsed();
    // switch if 0 no overflow if 1 there is overflow return number of remaining ticks
    if(gpt_StartTimer_flag==0){
        return 0xffffffff;
    }
    else if(check==0 && gpt_StartTimer_flag !=0)
        //  return elapsed ticks
        return (TIM2->ARR - TIM2->CNT) ;
    else if (check==1 && gpt_StartTimer_flag !=0){
        // overflow occured
        return 0 ;
    }
}
