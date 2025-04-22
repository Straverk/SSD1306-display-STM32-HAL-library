#include "display1306.h"


#ifndef DISPLAY_CUT_ALL_GRAPHICS
#ifndef DISPLAY_CUT_NOT_TEXT_GRAPHICS

void Display1306::drawLineH(uint8_t x1, uint8_t x2, uint8_t y)
{
  for (uint8_t x = x1; x < x2; x++)
  {
    drawPixel(x, y);
  }
}
void Display1306::drawLineV(uint8_t x, uint8_t y1, uint8_t y2)
{
  for (uint8_t y = y1; y < y2; y++)
  {
    drawPixel(x, y);
  }
}

void Display1306::clearLineH(uint8_t x1, uint8_t x2, uint8_t y)
{
  for (uint8_t x = x1; x < x2; x++)
  {
    clearPixel(x, y);
  }
}
void Display1306::clearLineV(uint8_t x, uint8_t y1, uint8_t y2)
{
  for (uint8_t y = y1; y < y2; y++)
  {
    clearPixel(x, y);
  }
}

void Display1306::drawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2) {
  int dx = abs(x2 - x1);
  int dy = -abs(y2 - y1);
  int sx = x1 < x2 ? 1 : -1;
  int sy = y1 < y2 ? 1 : -1;
  int err = dx + dy;
  
  while (true) {
      drawPixel(x1, y1);
      if (x1 == x2 && y1 == y2) break;
      int e2 = 2 * err;
      if (e2 >= dy) { // Horizontal step
          err += dy;
          x1 += sx;
      }
      if (e2 <= dx) { // Vertical step
          err += dx;
          y1 += sy;
      }
  }
}
void Display1306::clearLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2) {
  int dx = abs(x2 - x1);
  int dy = -abs(y2 - y1);
  int sx = x1 < x2 ? 1 : -1;
  int sy = y1 < y2 ? 1 : -1;
  int err = dx + dy;
  
  while (true) {
      clearPixel(x1, y1);
      if (x1 == x2 && y1 == y2) break;
      int e2 = 2 * err;
      if (e2 >= dy) { // Horizontal step
          err += dy;
          x1 += sx;
      }
      if (e2 <= dx) { // Vertical step
          err += dx;
          y1 += sy;
      }
  }
}

#ifndef DISPLAY_CUT_RECT_GRAPHICS

void Display1306::drawRectFrame(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2)
{
  drawLineH(x1, x2, y1);
  drawLineH(x1, x2, y2);

  drawLineV(x1, y1, y2);
  drawLineV(x2, y1, y2);
}

void Display1306::drawRectFrameBorder(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t borderSize)
{
  for (int i = 0; i < borderSize; i++)
    drawRectFrame(x1-i, y1-i, x2+i, y2+i);
}

void Display1306::drawRectFill(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2)
{
  for (uint8_t x = x1; x < x2; x++)
  {
    for (uint8_t y = y1; y < y2; y++)
    {
      drawPixel(x, y);
    }
  }
}

void Display1306::clearRect(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2)
{
  for (uint8_t x = x1; x < x2; x++)
  {
    for (uint8_t y = y1; y < y2; y++)
    {
      clearPixel(x, y);
    }
  }
}
#endif

#endif
#endif