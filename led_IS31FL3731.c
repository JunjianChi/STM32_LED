/*
 * led_IS31FL3731.c
 *
 *  Created on: Mar 15, 2024
 *      Author: Junjian Chi
 */

#include "led_IS31FL3731.h"

#include "main.h"

static const uint8_t LEDMAT_ADD = 0x75 << 1;
static const uint8_t PAGE_1 = 0x00;
//static const uint8_t PAGE_2 = 0x01;
//static const uint8_t PAGE_3 = 0x02;
//static const uint8_t PAGE_4 = 0x03;
//static const uint8_t PAGE_5 = 0x04;
//static const uint8_t PAGE_6 = 0x05;
//static const uint8_t PAGE_7 = 0x06;
//static const uint8_t PAGE_8 = 0x07;
static const uint8_t FUN_REG = 0x0B;
static const uint8_t COM_REG = 0xFD;
static const uint8_t MAT_ROW[11] = {0x00, 0x02, 0x04, 0x06, 0x08, 0x0A, 0x01, 0x03, 0x05, 0x07, 0x09};
static const uint8_t MAT_COL[7] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40};

// Assuming data array is declared globally
uint8_t data[2]; // Modify the size if necessary

void clearscreen() {
    for(uint8_t r = 0; r < 11; r++) {
        data[0] = COM_REG;
        data[1] = PAGE_1;
        HAL_I2C_Master_Transmit(&hi2c1, LEDMAT_ADD, data, 2, HAL_MAX_DELAY);
        //HAL_Delay(10);
        data[0] = MAT_ROW[r];
        data[1] = 0x00;
        HAL_I2C_Master_Transmit(&hi2c1, LEDMAT_ADD, data, 2, HAL_MAX_DELAY);
        //HAL_Delay(10);
    }
}

void turnoffscreen() {
    data[0] = COM_REG;
    data[1] = FUN_REG;
    HAL_I2C_Master_Transmit(&hi2c1, LEDMAT_ADD, data, 2, HAL_MAX_DELAY);
    //HAL_Delay(10);
    data[0] = 0x0A; //shutdown on/off
    data[1] = 0x00; //off
    HAL_I2C_Master_Transmit(&hi2c1, LEDMAT_ADD, data, 2, HAL_MAX_DELAY);
}

void turnonscreen() {
    data[0] = COM_REG;
    data[1] = FUN_REG;
    HAL_I2C_Master_Transmit(&hi2c1, LEDMAT_ADD, data, 2, HAL_MAX_DELAY);
    //HAL_Delay(10);
    data[0] = 0x0A; //shutdown on/off
    data[1] = 0x01; //on
    HAL_I2C_Master_Transmit(&hi2c1, LEDMAT_ADD, data, 2, HAL_MAX_DELAY);
}

void setpixel(uint8_t r, uint8_t c) {
    data[0] = COM_REG;
    data[1] = PAGE_1;
    HAL_I2C_Master_Transmit(&hi2c1, LEDMAT_ADD, data, 2, HAL_MAX_DELAY);
    //HAL_Delay(10);
    data[0] = MAT_ROW[r];
    data[1] = MAT_COL[c];
    HAL_I2C_Master_Transmit(&hi2c1, LEDMAT_ADD, data, 2, HAL_MAX_DELAY);
}
