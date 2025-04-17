#ifndef FONT_SSD1306_H
#define FONT_SSD1306_H

#include <stdint.h>

namespace font_ssd1306
{
  typedef uint8_t fontStroke;

  class Font
  {
  public:
    uint8_t fontWidth;
    const uint8_t fontHeight;

    const fontStroke *charData;

    const uint8_t charWidth;

    const uint8_t charCount;

    fontStroke stroke(unsigned char ch, uint8_t stroke)
    {
      return charData[(ch * charWidth) + stroke];
    }

    fontStroke pixel(unsigned char ch, uint8_t stroke, uint8_t y)
    {
      return Font::stroke(ch, stroke) & (1 << y);
    }

    Font(const uint8_t _fontWidth, const uint8_t _fontHeight,
      const fontStroke(*_charData), const uint8_t _charWidth, uint8_t _charCount)
        : fontWidth{_fontWidth}, fontHeight{_fontHeight}, charData{_charData}, charWidth{_charWidth}, charCount{_charCount} {}
  };
}

#endif // FONT_5x8_H