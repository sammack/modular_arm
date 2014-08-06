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
base_module.hpp
Started: Aug 6 2014
Author: Sam MacKenzie 
Email: samtmackenzie@gmail.com
------------------------------------------------------------------------------*/

#ifndef __ELBO_MODULE_H
#define __ELBO_MODULE_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx.h"
#include "base_module.hpp"

/* Constants -----------------------------------------------------------------*/

#define ELBO_MODULE     0x01

/* Class interface ------------------------------------------------------- */

class ElboModule : public BaseModule {
  uint8_t module_position;  // the position in the line of modules
  uint16_t max_speed;
  int16_t min_angle;    // max and min angle, can be set or found automatically
  int16_t max_angle;    // with FindLimits() 
  int16_t current_angle;
  bool limits_found;    // have the limits been found by the module
public:
  ElboModule(uint8_t position);
  uint8_t GetModuleType();
  int16_t GetMaxSpeed();
  int16_t GetMinAngle();
  int16_t GetMaxAngle();
  int16_t GetCurrentAngle();
  bool GetLimitsFound();
  void SetMaxAngle(int16_t);
  void SetMinAngle(int16_t);
  bool GetLimitFound();
  void ReadParameters();
  void MoveElbo(uint16_t, int16_t);
  void FindLimits();
};

#endif /* __ELBO_MODULE_H */