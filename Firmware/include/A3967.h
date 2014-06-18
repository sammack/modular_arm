//-------------------------------------------------------------------------
// Modular Arm Firmware
// A3967.h - header file for stepper control
// Started: June 17 2014
// Author: Sam MacKenzie 
// Email: samtmackenzie@gmail.com
//-------------------------------------------------------------------------

// ******     Pin assignments      *********

#define stepper_MS1_pin          GPIO_Pin_8
#define stepper_MS1_pin          GPIO_Pin_8
#define stepper_STEP_pin         GPIO_Pin_8  
#define stepper_nENABLE_pin      GPIO_Pin_8  
#define stepper_DIR_pin          GPIO_Pin_8  
#define stepper_nLIMIT_pin       GPIO_Pin_8  

#define stepper_PORT            GPIOA

// *********** constants ***********

#define kStepperMax     256