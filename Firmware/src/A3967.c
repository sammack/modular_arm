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
// A3967.h - file for stepper control
// Started: June 17 2014
// Author: Sam MacKenzie 
// Email: samtmackenzie@gmail.com
//-------------------------------------------------------------------------

// Includes  
#include "stm32f0xx.h"
#include  "A3967.h"
#include "GlobalDefinitions.h"
#include "utility.h"


//-----------------------------------------------------------------------------
// PRIVATE VARIABLES
//------------------------------------------------------------------------------

uint16_t stepper_position = 0xFFFF;

//------------------------------------------------------------------------------
// PUBLIC FUNCTION DEFINITIONS
//------------------------------------------------------------------------------


// Configures the Pins for the A3967 stepper motor driver and the limit switch
// All A3967 pins are output Push Pull no pull up
// Limit switch is Input with pullup 
void ConfigStepper(){
  GPIO_InitTypeDef GPIO_InitStructure;
  
  GPIO_InitStructure.GPIO_Pin = stepper_MS1_pin | 
                                stepper_MS1_pin | 
                                stepper_STEP_pin | 
                                stepper_nENABLE_pin | 
                                stepper_DIR_pin;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(stepper_PORT, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = stepper_nLIMIT_pin;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(stepper_PORT, &GPIO_InitStructure);
  
} 
  
// Home the Stepper motor
// Stepps the motor in reverse until it reaches the limit switch,
// This is then set as the zero position in the stepper_position
void HomeStepper(){
  while(GPIO_ReadInputDataBit(stepper_PORT, stepper_nLIMIT_pin)){
    GPIO_SetBits(stepper_PORT, stepper_STEP_pin);
    wait_us(kStepDelay);
    GPIO_ResetBits(stepper_PORT, stepper_STEP_pin);
    wait_us(kStepDelay); 
  }
    stepper_position = 0;
}

// Enable the Stepper motor by reseting the stepper_nENABLE_pin 
void EnableStepper(){
  GPIO_ResetBits(stepper_PORT, stepper_nENABLE_pin);
}

// Disable the Stepper motor by seting the stepper_nENABLE_pin
void DisableStepper(){
  GPIO_SetBits(stepper_PORT, stepper_nENABLE_pin);
}

// return the position of the stepper motor
uint16_t GetStepperPosition() 
{
  return stepper_position;
}

// Move the stepper to a perticular position. 
// This is done but comparing the position with the position target and 
// calling the appropriate step routine.
void MoveStepperToPosition(uint16_t stepper_position_target){
}

//------------------------------------------------------------------------------
// PRIVATE FUNCTION DEFINITIONS
//------------------------------------------------------------------------------

// step the motor forward the number of steps in the argument
// if the stepper motor reaches a position of kStepperMax, it should stop and 
// return a MAX_LIMIT error 
uint8_t StepForward(uint16_t number_of_steps){
  GPIO_SetBits(stepper_PORT, stepper_DIR_pin);
  if(stepper_position == kStepperMax) return MAX_LIMIT;
  for (uint16_t i = 0; i < number_of_steps; i++){
    GPIO_SetBits(stepper_PORT, stepper_STEP_pin);
    wait_us(kStepDelay);
    GPIO_ResetBits(stepper_PORT, stepper_STEP_pin);
    wait_us(kStepDelay);        
    stepper_position++;
    if(stepper_position == kStepperMax) return MAX_LIMIT;
  }
  return OK;
}

// step the motor backwards the number of steps in the argument
// if the stepper motor reaches a position of kStepperMax, it should stop and 
// return a MAX_LIMIT error 
uint8_t StepBackward(uint16_t number_of_steps){
  GPIO_ResetBits(stepper_PORT, stepper_DIR_pin);
  if(stepper_position == 2) return MIN_LIMIT;
  for (uint16_t i = 0; i < number_of_steps; i++){
    GPIO_SetBits(stepper_PORT, stepper_STEP_pin);
    wait_us(kStepDelay);
    GPIO_ResetBits(stepper_PORT, stepper_STEP_pin);
    wait_us(kStepDelay);        
    stepper_position--;
    if(stepper_position == 2) return MIN_LIMIT;
  }
  return OK;
}