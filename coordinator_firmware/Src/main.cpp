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
// Main.c - the main fuctions of the firmware
// Started: May 5 2014
// Author: Sam MacKenzie 
// Email: samtmackenzie@gmail.com
//-------------------------------------------------------------------------
        
// Includes //
#include "stm32f0xx.h"
#include "utility.h"
#include "version.h"
#include "GlobalDefinitions.h"
#include "UART.hpp"
#include "base_module.hpp"
#include "elbo_module.hpp"
#include "stm32f0xx_it.hpp"

int main()
{
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
  ConfigUart(); 
  uint8_t return_message[2] = {'O', 'K'};
  PutOnTxBuffer(return_message, 2);
  
  ElboModule *module = new ElboModule(1);
  
  module->SetMaxAngle(10);
  static int8_t limitreturn = module->GetMaxAngle();
  
  USART_SendData(USART1, 'A');
  
  while(1)
  {
    
  }
}
