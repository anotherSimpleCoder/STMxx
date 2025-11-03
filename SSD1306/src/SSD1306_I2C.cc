//
// Created by amsakan on 03.11.25.
//
#include "stm32f1xx_hal.h"
#include "SSD1306_I2C.hh"

void SSD1306::I2C::init() {
    uint32_t p = 250000;
    while(p>0)
        p--;
}


void SSD1306::I2C::write(uint8_t address, uint8_t reg, uint8_t data) const {
    uint8_t dt[2];
    dt[0] = reg;
    dt[1] = data;
    HAL_I2C_Master_Transmit(i2c_handle, address, dt, 2, 10);
}

void SSD1306::I2C::write_multi(uint8_t address, uint8_t reg, uint8_t *data, uint16_t count) const {
    uint8_t dt[256];
    dt[0] = reg;
    uint8_t i;
    for(i = 0; i < count; i++)
        dt[i+1] = data[i];
    HAL_I2C_Master_Transmit(i2c_handle, address, dt, count+1, 10);
}

I2C_HandleTypeDef* SSD1306::I2C::get_i2c_handle() const {
    return this->i2c_handle;
}
