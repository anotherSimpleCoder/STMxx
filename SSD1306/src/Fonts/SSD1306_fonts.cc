/**
* original author:  Tilen Majerle<tilen@majerle.eu>
 * modification for STM32f10x: Alexander Lutsai<s.lyra@ya.ru>
   ----------------------------------------------------------------------
       Copyright (C) Alexander Lutsai, 2016
    Copyright (C) Tilen Majerle, 2015
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
   ----------------------------------------------------------------------
 */
#include "Fonts/SSD1306_Fonts.hh"
#include "Fonts/7x10.hh"
#include "Fonts/11x18.hh"
#include "Fonts/16x26.hh"


Fonts::FontDef_t Font_7x10 = {
    7,
    10,
    Font7x10
};

Fonts::FontDef_t Font_11x18 = {
    11,
    18,
    Font11x18
};

Fonts::FontDef_t Font_16x26 = {
    16,
    26,
    Font16x26
};

char* Fonts::get_string_size(char* str, FONTS_SIZE_t* SizeStruct, FontDef_t* Font) {
    /* Fill settings */
    SizeStruct->Height = Font->FontHeight;
    SizeStruct->Length = Font->FontWidth * strlen(str);

    /* Return pointer */
    return str;
}
