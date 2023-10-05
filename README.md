### Assignment:
You are required to implement a GPIO driver that supports the following functions:<br />
1- void GPIO_Init(void)<br />
- A function to initialize the GPIO registers with the needed initial values to support the 
connected hardware actions.<br />
2- void GPIO_WritePinValue(unsigned char PinId, unsigned char PinData)<br />
- A function to set a value (1 or 0) to a specific pin.<br />
3- unsigned char GPIO_ReadPinState(unsigned char PinId)<br />
- A function to return (1) if a falling edge is detected on the pin and (0) otherwise.<br />
The GPIO driver shall be used to read the buttons’ state and drive the LEDs’ outputs.<br />
You are required to implement a GPT driver that supports the following functions:<br />
1- void GPT_Init(void)<br />
- A function to initialize the GPT registers with the needed initial values to support the 
needed timing actions.<br />
2- void GPT_StartTimer(unsigned long int OverFlowTicks)<br />
- A function to request the GPT to start and send its number of tickets before timer 
overflow and stop.<br />
3- unsigned char GPT_CheckTimeIsElapsed(void)<br />
- A function to return (1) if an overflow occurred after the last call of GPT_StartTimer and 
(0) if no overflow occurred or GPT_StartTimer is not called from the last read.<br />
4- unsigned long int GPT_GetElapsedTime(void)<br />
- A function to return number of elapsed ticks from the last call of the GPT_StartTimer, 0 if 
it is not called and 0xffffffff if an overflow occurred.<br />
5- unsigned long int GPT_GetRemainingTime(void)<br />
- A function to return number of remaining ticks till the overflow ticks passed to 
GPT_StartTimer, 0xffffffff if GPT_startTime is not called, 0 if an overflow occurred.<br />
The GPT driver shall be used to handle all the time actions in the project. (No delay functions 
will be used, and no hardware wait loops).<br /><br />
Video Link: <br />
https://drive.google.com/file/d/1paMUUfKvckOuYg1IU5WNNpm9orWvy8r8/view?usp=sharing
