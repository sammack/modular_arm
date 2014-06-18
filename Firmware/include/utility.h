//-------------------------------------------------------------------------
// AP1ication APbeacon Firmware
// utility.h - extra functions used by many files
// Started: May 5 2014
// Author: Sam MacKenzie 
// Email: sam.mackenzie@apbeacon.com
//-------------------------------------------------------------------------

#ifndef UTILITY_H
#define UTILITY_H
#include <stdint.h>

// wait the number of ms passed to the function
void wait_ms(uint16_t delay_ms);
// wait the number of us massed to the function
void wait_us(uint16_t delay_us);

#endif