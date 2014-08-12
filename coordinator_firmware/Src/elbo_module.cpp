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
elbo_module.cpp
Started: Aug 6 2014
Author: Sam MacKenzie 
Email: samtmackenzie@gmail.com
---------------------------------------------------------------------------*/   

/* Includes ------------------------------------------------------------------*/
#include "elbo_module.hpp"
#include "crc.hpp"
#include "stm32f0xx.h"
#include "GlobalDefinitions.h"
#include "UART.hpp"


ElboModule::ElboModule(uint8_t position){
  module_position = position;
  max_speed = 0;
  min_angle = 0;
  max_angle = 0;
  current_angle = 0;
  limits_found = false;
}

uint8_t ElboModule::GetModuleType() { return ELBO_MODULE; }
int16_t ElboModule::GetMaxSpeed() { return max_speed; }
int16_t ElboModule::GetMinAngle() { return min_angle; }
int16_t ElboModule::GetMaxAngle() { return max_angle; }
int16_t ElboModule::GetCurrentAngle() { return current_angle; }
bool ElboModule::GetLimitsFound() { return limits_found; }
void ElboModule::SetMaxAngle(int16_t angle){ max_angle = angle; }
void ElboModule::SetMinAngle(int16_t angle){ min_angle = angle; }


void ElboModule::ReadParameters(){
  // read the parameters over the UART
}
  
void ElboModule::MoveElbo(int16_t angle, uint16_t speed){
  int8_t command[5]; 
  command[0] = ELBO_MOVE_MESSAGE;
  command[1] = angle >> 8;
  command[2] = angle;
  command[3] = speed >> 8;
  command[4] = speed;
  ConstructMessage(module_position, 5, (uint8_t*)command);
}

void ElboModule::FindLimits(){
}

uint8_t ElboModule::ParseMessage(int8_t* message, uint8_t message_length){
  uint16_t transmitted_crc = (int16_t)message[message_length - 2];
  uint16_t calculated_crc = crcFast((uint8_t*)message, message_length - 2);
  if(transmitted_crc != calculated_crc)
    return BAD_CRC;
  int8_t command = message[1];
  switch(command)
  {
  case LIMITS_RETURNED:
    min_angle = message[2] + (message[3] << 8);
    max_angle = message[4] + (message[5] << 8);
    limits_found = true;
    break;
  case POSITION_RETURNED:
    current_angle = message[2] + (message[3] << 8);
    limits_found = true;
    break;
  }
  return OK;
}