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
// UART.h - configuration and communications for the UARTs
// Started: June 17 2014
// Author: Sam MacKenzie 
// Email: samtmackenzie@gmail.com
//-------------------------------------------------------------------------

#ifndef UART_H
#define UART_H

#include <stdint.h>
#include "stm32f0xx.h"

// UART Data structures
typedef struct
{
  uint8_t RX[256];
  uint8_t TX[256];
  uint8_t RX_index;
  uint8_t TX_index;
  uint8_t RX_length;
  uint8_t TX_length;
}UartBuffers;

#define GPIO_UART1                   GPIOA
#define UART1_TX_Pin                 GPIO_Pin_9
#define UART1_TX_PinSource           GPIO_PinSource9
#define UART1_RX_Pin                 GPIO_Pin_10
#define UART1_RX_PinSource           GPIO_PinSource10


uint8_t ConfigUart(void);
uint8_t UartWrite(USART_TypeDef* UARTx, uint8_t message_array[], uint16_t message_length);
void RxInterrupt(void);
void TxInterrupt(void);
uint8_t CheckUartBuffer(void);
uint8_t PutOnTxBuffer(uint8_t* command, uint8_t length);

#endif // UART_H