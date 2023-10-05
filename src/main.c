/*
 * main.c
 *
 *  Created on: Jun 19, 2023
 *      Author: hp
 */
#include "Rcc.h"
#include "Gpio.h"
#include "Gpt.h"


int main() {
	Rcc_Init();
	Rcc_Enable(GPIO_A);

	GPT_init();

	// LED pins
	Gpio_ConfigPin(GPIO_A,1,GPIO_OUTPUT,GPIO_PUSH_PULL);
//	Gpio_ConfigPin(GPIO_A,2,GPIO_OUTPUT,GPIO_PUSH_PULL);
//	Gpio_ConfigPin(GPIO_A,3,GPIO_OUTPUT,GPIO_PUSH_PULL);
//
//	// Config two pins for door and handle btns
//	Gpio_ConfigPin(GPIO_A,6,GPIO_INPUT,GPIO_PULL_UP);
//	Gpio_ConfigPin(GPIO_A,7,GPIO_INPUT,GPIO_PULL_UP);
	uint8 doorlocked,doorclosed;
	while (1){
		Gpio_WritePin(GPIO_A,1,HIGH);
		GPT_StartTimer(2000000);
		Gpio_WritePin(GPIO_A,1,LOW);

		// GPT_GetTimeElapsed



		// if(doorlocked != 0){
		// 	// Init State: if door is locked  --->  will be unlocked (btn handle pressed)
		// 	// Result    : Door Unlocked, LED 2 sec $ LED 0.5 sec
		// 	// DO        : count 2 sec to do an action and after 0.5 sec or 500ms do another action
		// }
		// else if(doorclosed != 0){
		// }
		// else if(doorclosed == 0)

	}

	return 0;
}
