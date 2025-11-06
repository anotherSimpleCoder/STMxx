//
// Created by abav on 04.11.2025.
//
#include "ST7789.hh"
#include "ST7789_Commands.hh"

namespace ST7789 {
    auto ST7789::init() -> void {
        init_pins();
        reset();
        sleep_out();
        set_pixel_format();
        set_memory_access_control();
        turn_on_display();
    }

    auto ST7789::display_image(uint8_t buffer[width][height][3]) -> void {
        uint8_t column_addresses[4] = {0, 0, (((width -1) >> 8) & 0xff), ((width-1) & 0xff)};
        uint8_t row_addresses[4] = {0, 0, (((height -1) >> 8) & 0xff), ((height-1) & 0xff)};

        HAL_GPIO_WritePin(cs_port, cs_pin, GPIO_PIN_RESET);

        HAL_GPIO_WritePin(dc_port, dc_pin, GPIO_PIN_RESET);
        spi.write(Commands::COL_ADR_SET);
        HAL_GPIO_WritePin(dc_port, dc_pin, GPIO_PIN_SET);
        spi.write_multi(column_addresses, 4);

        HAL_GPIO_WritePin(dc_port, dc_pin, GPIO_PIN_RESET);
        spi.write(Commands::ROW_ADR_SET);
        HAL_GPIO_WritePin(dc_port, dc_pin, GPIO_PIN_SET);
        spi.write_multi(row_addresses, 4);

        HAL_GPIO_WritePin(dc_port, dc_pin, GPIO_PIN_RESET);
        spi.write(Commands::MEM_WRT);
        HAL_GPIO_WritePin(dc_port, dc_pin, GPIO_PIN_SET);

        for(int y = 0; y < height; y++) {
          for(int x = 0; x < width; x++) {
            spi.write_multi(buffer[y][x], 3);
          }
        }

        HAL_GPIO_WritePin(cs_port, cs_pin, GPIO_PIN_SET);
    }

    auto ST7789::init_pins() -> void {
      HAL_GPIO_WritePin(cs_port, cs_pin, GPIO_PIN_SET);
    }

    auto ST7789::reset() -> void {
        HAL_GPIO_WritePin(reset_port, reset_pin, GPIO_PIN_RESET);
        //delay_us(10);
        HAL_GPIO_WritePin(reset_port, reset_pin, GPIO_PIN_SET);
        HAL_Delay(120);

        HAL_GPIO_WritePin(cs_port, cs_pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(dc_port, dc_pin, GPIO_PIN_RESET);
        spi.write(Commands::SOFTWARE_RESET);
        HAL_GPIO_WritePin(cs_port, cs_pin, GPIO_PIN_SET);
        HAL_Delay(120);
    }

    auto ST7789::sleep_out() -> void {
        HAL_GPIO_WritePin(cs_port, cs_pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(dc_port, dc_pin, GPIO_PIN_RESET);
        spi.write(Commands::SLEEP_OUT);
        HAL_GPIO_WritePin(cs_port, cs_pin, GPIO_PIN_SET);
        HAL_Delay(120);
    }

    auto ST7789::set_pixel_format() -> void {
        constexpr uint8_t color_mod = 0x56;
        HAL_GPIO_WritePin(cs_port, cs_pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(dc_port, dc_pin, GPIO_PIN_RESET);

        spi.write(PIXEL_FORMAT);

        HAL_GPIO_WritePin(dc_port, dc_pin, GPIO_PIN_SET);
        spi.write(color_mod);

        constexpr uint8_t INVOFF = 0x21;
        HAL_GPIO_WritePin(dc_port, dc_pin, GPIO_PIN_RESET);
        spi.write(INVOFF);

        HAL_GPIO_WritePin(cs_port, cs_pin, GPIO_PIN_SET);
    }

    auto ST7789::set_memory_access_control() -> void {
        uint8_t color_order = 0x00;
        HAL_GPIO_WritePin(cs_port, cs_pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(dc_port, dc_pin, GPIO_PIN_RESET);

        spi.write(Commands::MEM_ACC_CTL);

        HAL_GPIO_WritePin(dc_port, dc_pin, GPIO_PIN_SET);
        spi.write(color_order);
        HAL_GPIO_WritePin(cs_port, cs_pin, GPIO_PIN_SET);
    }

    auto ST7789::turn_on_display() -> void {
        HAL_GPIO_WritePin(cs_port, cs_pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(dc_port, dc_pin, GPIO_PIN_RESET);

        spi.write(Commands::DISPLAY_ON);

        HAL_GPIO_WritePin(dc_port, dc_pin, GPIO_PIN_SET);
    }
};
