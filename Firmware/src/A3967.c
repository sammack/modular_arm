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


//-----------------------------------------------------------------------------
// PRIVATE VARIABLES
//------------------------------------------------------------------------------

uint16_t stepper_position = 0x0FFF

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
// This is then set as the zero position in the StepperLocation


// Enable the Stepper motor by reseting the stepper_nENABLE_pin
inline void EnableStepper(){
  GPIO_ResetBits(stepper_PORT, stepper_nENABLE_pin);
}

// Disable the Stepper motor by seting the stepper_nENABLE_pin
inline void enable_stepper(){
  GPIO_SetBits(stepper_PORT, stepper_nENABLE_pin);
}

//------------------------------------------------------------------------------
// PRIVATE FUNCTION DEFINITIONS
//------------------------------------------------------------------------------

// step the motor the numebr of steps passed to it
// if the stepper motor reaches a position of 1 it should stop and return an
// MIN_LIMIT error, it should stop and return a MAX_LIMIT error if it reaches
// kStepperMax
void step(uint16_t number_of_steps){
  


}