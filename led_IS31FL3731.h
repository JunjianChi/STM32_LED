/*
 * led_IS31FL3731.h
 *
 *  Created on: Mar 15, 2024
 *      Author: Junjian Chi
 */

#ifndef INC_LED_IS31FL3731_H_
#define INC_LED_IS31FL3731_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
//Functions

extern void clearscreen(void);
extern void turnoffscreen(void);
extern void turnonscreen(void);
extern void setpixel(uint8_t r, uint8_t c);


#endif /* INC_LED_IS31FL3731_H_ */
