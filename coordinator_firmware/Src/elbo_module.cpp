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
  
void ElboModule::MoveElbo(uint16_t angle, int16_t speed){
  // write the angle position and speed over the UART
}

void ElboModule::FindLimits(){
  // ask the elbo to find it's limits
  limits_found = true;
}