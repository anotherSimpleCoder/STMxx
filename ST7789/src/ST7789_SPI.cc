//
// Created by abav on 04.11.2025.
//
#include "ST7789_SPI.hh"

namespace ST7789 {
    auto SPI::write(uint8_t data) -> void {
        HAL_SPI_Transmit(spi_handle, &data, 1, HAL_MAX_DELAY);
    }

    auto SPI::write_multi(uint8_t *data, uint16_t count) -> void {
      HAL_SPI_Transmit(spi_handle, data, count, HAL_MAX_DELAY);
    }

    auto SPI::get_spi_handle() -> SPI_HandleTypeDef* {
        return spi_handle;
    }
}