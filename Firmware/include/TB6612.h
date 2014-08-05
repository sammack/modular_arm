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
// servo.h - file for server control
// Started: June 17 2014
// Author: Sam MacKenzie 
// Email: samtmackenzie@gmail.com
//-------------------------------------------------------------------------

#ifndef TB6612_H
#define TB6612_H

#define tb_PWM_pin           GPIO_Pin_0
#define tb_IN1_pin           GPIO_Pin_1
#define tb_IN2_pin           GPIO_Pin_2
#define tb_PORT              GPIOA

extern void ConfigTb();
extern void TbMoveClockwise(uint8_t time, uint16_t speed);
extern void TbMoveCounterClockwise(uint8_t time, uint16_t speed);
extern void DecrementTbTimer(void);
extern void TbStop(void);

#endif // TB6612_H