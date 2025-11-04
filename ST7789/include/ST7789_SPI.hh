//
// Created by abav on 04.11.2025.
//

#ifndef ST7789_SPI_HH
#define ST7789_SPI_HH
#include "stm32f1xx_hal.h"

namespace ST7789 {
    class SPI {
        SPI_HandleTypeDef* spi_handle;
    public:
      explicit SPI(SPI_HandleTypeDef* spi_handle)
          : spi_handle(spi_handle) {}

      auto init() -> void;
      auto write(uint8_t data) -> void;
      auto write_multi(uint8_t *data, uint16_t count) -> void;
      auto get_spi_handle() -> SPI_HandleTypeDef*;

    };
};
#endif //ST7789_SPI_HH
