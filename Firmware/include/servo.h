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

#ifndef SERVO_H
#define SERVO_H

#define servo_PWM_pin           GPIO_Pin_8
#define servo_PORT              GPIOA
#define servo_MOVE_CW           'F'
#define servo_MOVE_CCW          'B'
#define servo_STOP              'S'

extern void ConfigServo();
extern void MoveClockwise(uint8_t time, uint8_t speed);
extern void MoveCounterClockwise(uint8_t time, uint8_t speed);
extern void DecrementServoTimer(void);
extern void ServoStop(void);

#endif // SERVO_H