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
// UART.c - configuration and communications for the UARTs
// Started: June 17 2014
// Author: Sam MacKenzie 
// Email: samtmackenzie@gmail.com
//-------------------------------------------------------------------------     
// Includes  
#include "stm32f0xx.h"
#include "UART.hpp"
#include "GlobalDefinitions.h"
#include "stm32f0xx_it.hpp"

//------------------------------------------------------------------------------
// PUBLIC VARIABLES
//------------------------------------------------------------------------------

 UartBuffers uart_buffer;// = {.TX_index = 0, .RX_index = 0};


//------------------------------------------------------------------------------
// PUBLIC FUNCTION DEFINITIONS
//------------------------------------------------------------------------------

//Configure the  uart, UART1
uint8_t ConfigUart(void)
{
  USART_InitTypeDef USART_InitStructure;  
  NVIC_InitTypeDef NVIC_InitStructure;
  GPIO_InitTypeDef GPIO_InitStructure;
  
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
  USART_Cmd(USART1, DISABLE);  
  
  GPIO_InitStructure.GPIO_Pin = UART1_TX_Pin | UART1_RX_Pin;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIO_UART1, &GPIO_InitStructure);
  GPIO_PinAFConfig(GPIO_UART1, UART1_TX_PinSource, GPIO_AF_1);
  GPIO_PinAFConfig(GPIO_UART1, UART1_RX_PinSource, GPIO_AF_1);
  
  USART_InitStructure.USART_BaudRate = 9600;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b; 
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
  USART_Init(USART1, &USART_InitStructure);
  USART_Cmd(USART1, ENABLE);
  
  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
  
  USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
  return OK;
}

uint8_t PutOnTxBuffer(uint8_t* command, uint8_t length)
{
  
  for(uint8_t i = 0; i < length; i++)
  {
    uart_buffer.TX[uart_buffer.RX_index + i] = command[i];
  }
  
  return OK;
}
  
  
// Check the UART RX buffer and see if you need to do anything
uint8_t CheckUartBuffer(void)
{
  uint8_t return_value = NO_COMMAND;
  // check for the stop character 
  if (uart_buffer.RX[uart_buffer.RX_index] == 0x0D){
    
    
  }
  return return_value;
}
        
// Called by the interrup handler in stm32f0xx_it.c
// 
void RxInterrupt(void)
{
  uart_buffer.RX_index++;
  uart_buffer.RX[uart_buffer.RX_index] = USART_ReceiveData(USART1);
}

void TxInterrupt(void)
{
  uart_buffer.TX_index++;
  USART_SendData(USART1, uart_buffer.TX[uart_buffer.TX_index]);
}