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
// A3967.h - header file for stepper control
// Started: June 17 2014
// Author: Sam MacKenzie 
// Email: samtmackenzie@gmail.com
//-------------------------------------------------------------------------


#ifndef A3967_H
#define A3967_H


// ******     Pin assignments      *********

#define stepper_MS1_pin          GPIO_Pin_8
#define stepper_MS1_pin          GPIO_Pin_8
#define stepper_STEP_pin         GPIO_Pin_8  
#define stepper_nENABLE_pin      GPIO_Pin_8  
#define stepper_DIR_pin          GPIO_Pin_8  
#define stepper_nLIMIT_pin       GPIO_Pin_8  

#define stepper_PORT            GPIOA

// *********** constants ***********

#define kStepperMax     256
#define kStepDelay      5

// ****** Function Prototypes **** 

// configure the stepper motor GPIO pins
void ConfigStepper();
// home the stepper motor against the limit switch
void HomeStepper();
// Enable the Stepper motor so it can be moved
void EnableStepper();
// Disable the Stepper motor so that it cannot be moved
void DisableStepper();
// return the position of the stepper motor
uint16_t GetStepperPosition();
// Move the Stepper motor to a position
void MoveStepperToPosition(uint16_t stepper_position_target);


#endif

