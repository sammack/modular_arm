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
// Modular Arm Firmware
// servo.h - file for servo control
// Started: June 17 2014
// Author: Sam MacKenzie 
// Email: samtmackenzie@gmail.com
//-------------------------------------------------------------------------

// Includes  
#include "stm32f0xx.h"
#include "TB6612.h"
#include "GlobalDefinitions.h"
#include "utility.h"


//-----------------------------------------------------------------------------
// PRIVATE VARIABLES
//------------------------------------------------------------------------------

uint16_t tb_timer = 0;

//------------------------------------------------------------------------------
// PUBLIC FUNCTION DEFINITIONS
//------------------------------------------------------------------------------

void ConfigTb(){
  GPIO_InitTypeDef GPIO_InitStructure;
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
  TIM_OCInitTypeDef  TIM_OCInitStructure;
  
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

  
  GPIO_InitStructure.GPIO_Pin = tb_PWM_pin;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
  GPIO_Init(tb_PORT, &GPIO_InitStructure);
  
  GPIO_PinAFConfig(tb_PORT, GPIO_PinSource0, GPIO_AF_2);
  
  GPIO_InitStructure.GPIO_Pin = tb_IN1_pin | tb_IN2_pin;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(tb_PORT, &GPIO_InitStructure);
  
    /* Time Base configuration */
  TIM_TimeBaseStructure.TIM_Prescaler = 40;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseStructure.TIM_Period = 20000;
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;

  TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;
  TIM_OCInitStructure.TIM_Pulse = 10;
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
  TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
  TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
  TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCIdleState_Reset;

  TIM_OC1Init(TIM2, &TIM_OCInitStructure);

  /* TIM1 counter enable */
  TIM_Cmd(TIM2, ENABLE);

  /* TIM1 Main Output Enable */
  TIM_CtrlPWMOutputs(TIM2, ENABLE);
  
}


extern void TbMoveClockwise(uint8_t time, uint16_t speed)
{
  GPIO_ResetBits(tb_PORT, tb_IN2_pin);
  GPIO_SetBits(tb_PORT, tb_IN1_pin);
  tb_timer = time;
  TIM_SetCompare1(TIM2, speed);
}

extern void TbMoveCounterClockwise(uint8_t time, uint16_t speed)
{
  GPIO_ResetBits(tb_PORT, tb_IN1_pin);
  GPIO_SetBits(tb_PORT, tb_IN2_pin);
  tb_timer = time;
  TIM_SetCompare1(TIM2, speed);
}

extern void TbStop(void)
{
  tb_timer = 0;
  TIM_SetCompare1(TIM2, 2);
}

extern void DecrementTbTimer(void)
{
  tb_timer--; 
  if (tb_timer == 0)
    TbStop();
}
