#ifndef MAIN_H_
#define MAIN_H_

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <avr/pgmspace.h>

#include "uart.h"
#include "ws2812.h"
#include "ir_read.h"
#include "eeprom.h"
#include "lighting.h"

#endif /* MAIN_H_ */
