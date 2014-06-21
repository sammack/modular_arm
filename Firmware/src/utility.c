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

//-------------------------------------------------------------------------
// Modular Arm firmware
// utility.c - utilities used throughout the firmware
// Started: June 17 2014
// Author: Sam MacKenzie 
// Email: samtmackenzie@gmail.com
//-------------------------------------------------------------------------
#include <stdbool.h>
#include "stm32f0xx.h"
#include "utility.h"
#include "GlobalDefinitions.h"

//Warning : Delay functions are dependant on SystemCoreClock being correct
extern uint32_t SystemCoreClock = F_CLK; 


//------------------------------------------------------------------------------
// PUBLIC FUNCTION DEFINITIONS
//------------------------------------------------------------------------------

// function that waits some number of ms
// TODO: this should be rewritten to use a timer as this function is not acurate
// when it's interrupted

#pragma optimize=none
void wait_ms(uint16_t delay_ms)
{
  uint32_t count = (SystemCoreClock/5000)*delay_ms;
  for(uint32_t i=0;i<count;i++)
  {
  }
}

#pragma optimize=none
void  wait_us(uint16_t delay_us)
{
  uint32_t count = (SystemCoreClock/5000000)*delay_us;
  for(uint32_t i=0;i<count;i++)
  {
  }
}


//Pin B5 is the 'heartbeat' pin
void Heartbeat(void)
{
  GPIO_InitTypeDef         GPIO_InitStructure;  
  
  static bool out_high = false;
  if(out_high == true)
  {
    //GPIO_ResetBits(GPIOB, GPIO_Pin_5);    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
    GPIO_Init(GPIOB, &GPIO_InitStructure);         
    out_high = false;
  }
  else
  {
    //GPIO_SetBits(GPIOB, GPIO_Pin_5);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GPIOB, &GPIO_InitStructure);     
    out_high = true;
  }
}
