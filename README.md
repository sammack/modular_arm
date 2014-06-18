modular_arm
===========

Firmware and software for a modular arm project


Frimware is written in C for the STM32F051 microcontroller, tested only in IAR EWB (because it has a good debugger).

The controller is sent a command over the UART, it looks at the command and if it's for it, it moves it's motor 
to whatever point it is asked to, if not, it passes the message on to the next module over it's 2nd UART.
