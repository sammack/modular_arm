/* (The MIT License)

Copyright (c) 2014 Sam MacKenzie

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the 'Software'), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE. */

/*-------------------------------------------------------------------------
Modular Arm firmware - coordinator
main.cpp
Started: Aug 6 2014
Author: Sam MacKenzie 
Email: samtmackenzie@gmail.com
---------------------------------------------------------------------------*/   

#ifndef __LEDS_H
#define __LEDS_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* constants --------------------------------------------------------*/


#define LED_RED         GPIO_PIN_14
#define LED_ORANGE      GPIO_PIN_13
#define LED_BLUE        GPIO_PIN_14
#define LED_PORT        GPIOD


/* Exported functions ------------------------------------------------------- */
/* Set up the GPIO ports for the 3 LEDs */
void LEDS_InitializeLeds(void);
/* turn on the LED, argument is LED_RED, LED_BLUE, or LED_ORANGE */
void LEDS_TurnOnLed(uint16_t ledToTurnOn);
void LEDS_TurnOffLed(uint16_t ledToTurnOff);

#endif /* __LEDS_H */
