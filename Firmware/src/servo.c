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
#include  "servo.h"
#include "GlobalDefinitions.h"
#include "utility.h"


//-----------------------------------------------------------------------------
// PRIVATE VARIABLES
//------------------------------------------------------------------------------

uint16_t servo_timer = 0;

//------------------------------------------------------------------------------
// PUBLIC FUNCTION DEFINITIONS
//------------------------------------------------------------------------------

void ConfigServo(){
  GPIO_InitTypeDef GPIO_InitStructure;
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
  TIM_OCInitTypeDef  TIM_OCInitStructure;
  
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);

  
  GPIO_InitStructure.GPIO_Pin = servo_PWM_pin;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(servo_PORT, &GPIO_InitStructure);
  
  GPIO_PinAFConfig(servo_PORT, GPIO_PinSource8, GPIO_AF_2);
  
    /* Time Base configuration */
  TIM_TimeBaseStructure.TIM_Prescaler = 47;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseStructure.TIM_Period = 20000;
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;

  TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);

  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;
  TIM_OCInitStructure.TIM_Pulse = 1500;
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
  TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
  TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
  TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCIdleState_Reset;

  TIM_OC1Init(TIM1, &TIM_OCInitStructure);

  /* TIM1 counter enable */
  TIM_Cmd(TIM1, ENABLE);

  /* TIM1 Main Output Enable */
  TIM_CtrlPWMOutputs(TIM1, ENABLE);
  
}


extern void MoveClockwise(uint8_t time, uint8_t speed)
{
  servo_timer = time;
  TIM_SetCompare1(TIM1, 1500 - speed);
}

extern void MoveCounterClockwise(uint8_t time, uint8_t speed)
{
  servo_timer = time;
  TIM_SetCompare1(TIM1, 1500 + speed);
}

extern void ServoStop(void)
{
  TIM_SetCompare1(TIM1, 1500);
}

extern void DecrementServoTimer(void)
{
  servo_timer--; 
  if (servo_timer == 0)
    ServoStop();
}
    
