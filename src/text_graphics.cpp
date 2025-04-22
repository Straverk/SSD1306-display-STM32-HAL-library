#include "display1306.h"

#ifndef DISPLAY_CUT_ALL_GRAPHICS
#ifndef DISPLAY_CUT_TEXT_GRAPHICS

#ifndef DISPLAY_CUT_TEXT_ROW_GRAPHICS

void Display1306::drawCharRow(const unsigned char &ch, uint8_t start_x, uint8_t row, Font *font)
{
  for (uint8_t i = 0; i < font->charWidth; i++)
  {
    _displayBuffer[start_x + row * width + i] = font->stroke(ch, i);
  }
}

#ifndef DISPLAY_CUT_STRINGS_GRAPHICS

void Display1306::drawStringRow(const unsigned char str[], uint8_t start_x, uint8_t row, Font *font)
{
  uint8_t chars_printed{0};
  while (*str)
  {
    if (start_x + chars_printed * font->fontWidth < width)
    {
      drawCharRow((*str), start_x + chars_printed * font->fontWidth, row, font);
      chars_printed++;
    }
    str++;
  }
}

void Display1306::drawStringRow(const char str[], uint8_t start_x, uint8_t row, Font *font)
{
  drawStringRow((const unsigned char *)str, start_x, row, font);
}

void Display1306::drawStringRow(string str, uint8_t start_x, uint8_t row, Font *font)
{
  drawStringRow(str.c_str(), start_x, row, font);
}
#endif

#endif


#ifndef DISPLAY_CUT_TEXT_NOT_ROW_GRAPHICS

void Display1306::drawChar(const unsigned char &ch, uint8_t start_x, uint8_t start_y, Font *font)
{
  for (int x = 0; x < font->charWidth; x++)
  {
    const fontStroke stroke = font->stroke(ch, x);
    const uint8_t start_y_bit = start_y % 8;
    for (int y = 0; y < font->fontHeight; y++)
      _displayBuffer[start_x + x + (((start_y + y) / 8) * width)] |= (stroke & (1 << y)) << start_y_bit >> (((start_y_bit + y) / 8) * 8);
  }
}

#ifndef DISPLAY_CUT_STRINGS_GRAPHICS

void Display1306::drawString(const unsigned char str[], uint8_t start_x, uint8_t start_y, Font *font)
{
  uint8_t chars_printed{0};
  while (*str)
  {
    if (start_x + chars_printed * font->fontWidth < width)
    {
      drawChar((*str), start_x + chars_printed * font->fontWidth, start_y, font);
      chars_printed++;
    }
    str++;
  }
}

void Display1306::drawString(const char str[], uint8_t start_x, uint8_t start_y, Font *font)
{
  drawString((const unsigned char *)str, start_x, start_y, font);
}

void Display1306::drawString(string str, uint8_t start_x, uint8_t start_y, Font *font)
{
  drawString(str.c_str(), start_x, start_y, font);
}

#endif

#endif

#endif
#endif