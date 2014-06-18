//-------------------------------------------------------------------------
// AP1ication APbeacon Firmware
// utility.c - extra functions used by many files
// Started: May 5 2014
// Author: Sam MacKenzie 
// Email: sam.mackenzie@apbeacon.com
//-------------------------------------------------------------------------

#include <stdbool.h>
#include "stm32f0xx.h"
#include "utility.h"
#include "GlobalDefinitions.h"

//Warning : Delay functions are dependant on SystemCoreClock being correct
extern uint32_t SystemCoreClock; 


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
