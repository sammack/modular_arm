//-------------------------------------------------------------------------
// AP1ication APbeacon Firmware
// UART.h - configuration and communications for the UARTs
// Started: May 5 2014
// Author: Sam MacKenzie 
// Email: sam.mackenzie@apbeacon.com
//-------------------------------------------------------------------------

#ifndef UART_H
#define UART_H

#include <stdint.h>
#include "stm32f0xx.h"

// UART Data structures
typedef struct
{
  int8_t RX[256];
  int8_t TX[256];
  uint8_t RX_index;
  uint8_t TX_index;
  uint8_t RX_length;
  uint8_t TX_length;
}UartBuffers;

#define GPIO_UART1                   GPIOA
#define UART1_TX_Pin                 GPIO_Pin_8
#define UART1_TX_PinSource           GPIO_PinSource8
#define UART1_RX_Pin                 GPIO_Pin_9
#define UART1_RX_PinSource           GPIO_PinSource9


extern uint8_t Config_UART1(void);
extern void USART1_IRQHandler(void);
uint8_t UART_write(USART_TypeDef* UARTx, uint8_t message_array[], uint16_t message_length);

#endif