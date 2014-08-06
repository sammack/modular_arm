//-------------------------------------------------------------------------
// AP1ication APbeacon Firmware
// GlobalDefinitions.h - header file containing global constants
// Started: May 5 2014
// Author: Sam MacKenzie 
// Email: sam.mackenzie@apbeacon.com
//-------------------------------------------------------------------------



//Main clock frequency
#define F_CLK          32000000


// Error codes
#define OK              0x02
#define NOK             0x03
#define MAX_LIMIT       0x04
#define MIN_LIMIT       0x05
#define BAD_COMMAND     0x06
#define NO_COMMAND     0x06

// Bit definitions 

#define BIT0      0x01             // b.00000001
#define BIT1      0x02             // b.00000010
#define BIT2      0x04             // b.00000100
#define BIT3      0x08             // b.00001000
#define BIT4      0x10             // b.00010000
#define BIT5      0x20             // b.00100000
#define BIT6      0x40             // b.01000000
#define BIT7      0x80             // b.10000000
#define BIT8      0x0100           // b.0000000100000000
#define BIT9      0x0200           // b.0000001000000000
#define BIT10     0x0400           // b.0000010000000000
#define BIT11     0x0800           // b.0000100000000000
#define BIT12     0x1000           // b.0001000000000000
#define BIT13     0x2000           // b.0010000000000000
#define BIT14     0x4000           // b.0100000000000000
#define BIT15     0x8000           // b.1000000000000000
#define BIT16     0x010000         // b.00000000000000010000000000000000
#define BIT17     0x020000         // b.00000000000000100000000000000000
#define BIT18     0x040000         // b.00000000000001000000000000000000
#define BIT19     0x080000         // b.00000000000010000000000000000000
#define BIT20     0x100000         // b.00000000000100000000000000000000
#define BIT21     0x200000         // b.00000000001000000000000000000000
#define BIT22     0x400000         // b.00000000010000000000000000000000
#define BIT23     0x800000         // b.00000000100000000000000000000000
#define BIT24     0x01000000       // b.00000001000000000000000000000000
#define BIT25     0x02000000       // b.00000010000000000000000000000000
#define BIT26     0x04000000       // b.00000100000000000000000000000000
#define BIT27     0x08000000       // b.00001000000000000000000000000000
#define BIT28     0x10000000       // b.00010000000000000000000000000000
#define BIT29     0x20000000       // b.00100000000000000000000000000000
#define BIT30     0x40000000       // b.01000000000000000000000000000000
#define BIT31     0x80000000       // b.10000000000000000000000000000000

/* Port Configuration constants */

#define GPIO_Pin_0_mul         0x00000001
#define GPIO_Pin_1_mul         0x00000004
#define GPIO_Pin_2_mul         0x00000010
#define GPIO_Pin_3_mul         0x00000040
#define GPIO_Pin_4_mul         0x00000100
#define GPIO_Pin_5_mul         0x00000400
#define GPIO_Pin_6_mul         0x00001000
#define GPIO_Pin_7_mul         0x00004000
#define GPIO_Pin_8_mul         0x00010000
#define GPIO_Pin_9_mul         0x00040000
#define GPIO_Pin_10_mul         0x00100000
#define GPIO_Pin_11_mul         0x00400000
#define GPIO_Pin_12_mul         0x01000000
#define GPIO_Pin_13_mul         0x04000000
#define GPIO_Pin_14_mul         0x10000000
#define GPIO_Pin_15_mul         0x40000000


  #define USARTx                           USART1
  #define USARTx_CLK                       RCC_APB2Periph_USART1
  #define USARTx_APBPERIPHCLOCK            RCC_APB2PeriphClockCmd
  #define USARTx_IRQn                      USART1_IRQn
  #define USARTx_IRQHandler                USART1_IRQHandler