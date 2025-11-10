#ifndef SSD1306_I2C_HH
#define SSD1306_I2C_HH

#include "stm32f1xx_hal.h"

namespace SSD1306 {
    class I2C {
        I2C_HandleTypeDef* i2c_handle;
    public:
        const uint8_t address = 0x78;
        const unsigned int timeout = 20000;

        explicit I2C(I2C_HandleTypeDef* i2c_handle)
            :i2c_handle(i2c_handle) {}

        void init();
        void write(uint8_t address, uint8_t  reg, uint8_t  data) const;
        void write_multi(uint8_t address, uint8_t reg, uint8_t *data, uint16_t count) const;
        I2C_HandleTypeDef* get_i2c_handle() const;
    };
};

#endif
