//
// Created by amsakan on 03.11.25.
//

#ifndef SSD1306_SSD1306_FONTS_HH
#define SSD1306_SSD1306_FONTS_HH


#include "stm32f1xx_hal.h"
#include "string.h"

namespace Fonts {
    struct FontDef_t {
        uint8_t FontWidth;
        uint8_t FontHeight;
        const uint16_t *data;
    };

    struct FONTS_SIZE_t {
        uint16_t Length;
        uint16_t Height;
    };


    extern FontDef_t Font_7x10;

    extern FontDef_t Font_11x18;

    extern FontDef_t Font_16x26;

    char* get_string_size(char* str, FONTS_SIZE_t* SizeStruct, FontDef_t* Font);
};
#endif //SSD1306_SSD1306_FONTS_HH
