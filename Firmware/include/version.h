//-------------------------------------------------------------------------
// AP1ication APbeacon Firmware
// version.h - file contraining the version information
// Started: May 5 2014
// Author: Sam MacKenzie 
// Email: sam.mackenzie@apbeacon.com
//-------------------------------------------------------------------------


//This is the version information file for the APbeacon
//Whenever a change is made  to the funtionality to the APbeacon
//or a bug is fixed, please increment the version.

#ifndef VERSION_H
#define VERSION_H
#include <stdint.h>

#define VERSION_MAJOR  1
#define VERSION_MINOR  1
#define VERSION_BUILD  1

typedef struct 
{
  uint8_t ver_major;
  uint8_t ver_minor;
  uint8_t ver_build;
}VersionInfo;


typedef struct 
{
  VersionInfo ver_motor_driver;
  VersionInfo ver_flight_controller;
  VersionInfo ver_main_micro;
}AllVersionInfo;

#endif