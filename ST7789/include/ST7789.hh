//
// Created by abav on 04.11.2025.
//

#ifndef ST7789_HH
#define ST7789_HH
#include "stm32f1xx_hal.h"
#include "ST7789_SPI.hh"

namespace ST7789 {
    class ST7789 {
        static constexpr uint32_t width = 240;
        static constexpr uint32_t height = 320;
        uint8_t buffer[width][height][3];

        SPI spi;

        GPIO_TypeDef* reset_port;
        uint16_t reset_pin;

        GPIO_TypeDef* dc_port;
        uint16_t dc_pin;

        GPIO_TypeDef* cs_port;
        uint16_t cs_pin;

        auto init_pins() -> void;
        auto reset() -> void;
        auto sleep_out() -> void;
        auto set_pixel_format() -> void;
        auto set_memory_access_control() -> void;
        auto turn_on_display() -> void;
    public:
        explicit ST7789(
            SPI_HandleTypeDef* spi_handle, 
        
            GPIO_TypeDef* reset_port, 
            uint16_t reset_pin,
        
            GPIO_TypeDef* dc_port, 
            uint16_t dc_pin,

            GPIO_TypeDef* cs_port,
            uint16_t cs_pin
        )
          : spi(spi_handle),
          reset_port(reset_port),
          reset_pin(reset_pin),
          dc_port(dc_port),
          dc_pin(dc_pin),
          cs_port(cs_port),
          cs_pin(cs_pin) {}
        auto init() -> void;
        auto display_image() -> void;
    };
}
#endif //ST7789_HH
