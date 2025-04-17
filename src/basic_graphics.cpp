#include "display1306.h"
#include "easy_math.h"
#include "math.h"


//#define NUM_PI 3.14159
#define NUM_PI 3.141


void Display1306::drawPixel(uint8_t x, uint8_t y)
{
  _displayBuffer[x + (y / 8) * width] |= (1 << (y % 8));
}
void Display1306::clearPixel(uint8_t x, uint8_t y)
{
  _displayBuffer[x + (y / 8) * width] &= ~(1 << (y % 8));
}


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
      if (e2 >= dy) { // Горизонтальный шаг
          err += dy;
          x1 += sx;
      }
      if (e2 <= dx) { // Вертикальный шаг
          err += dx;
          y1 += sy;
      }
  }
}


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



void Display1306::drawCircleFrame(uint8_t x1, uint8_t y1, uint8_t r) {
  int x = 0;
  int y = r;
  int d = 3 - 2 * r;

  while (x <= y) {
      drawPixel(x1 + x, y1 + y);
      drawPixel(x1 - x, y1 + y);
      drawPixel(x1 + x, y1 - y);
      drawPixel(x1 - x, y1 - y);
      drawPixel(x1 + y, y1 + x);
      drawPixel(x1 - y, y1 + x);
      drawPixel(x1 + y, y1 - x);
      drawPixel(x1 - y, y1 - x);

      if (d < 0) {
          d = d + 4 * x + 6;
      } else {
          d = d + 4 * (x - y) + 10;
          y--;
      }
      x++;
  }
}

void Display1306::drawCircleFilled(uint8_t x1, uint8_t y1, uint8_t r) {
  int x = 0;
  int y = r;
  int d = 3 - 2 * r;

  while (x <= y) {
      // Горизонтальные линии между симметричными точками
      drawLineH(x1 - x, x1 + x, y1 + y); // Верхняя половина
      drawLineH(x1 - x, x1 + x, y1 - y); // Нижняя половина
      drawLineH(x1 - y, x1 + y, y1 + x); // Дополнительные линии
      drawLineH(x1 - y, x1 + y, y1 - x);

      if (d < 0) {
          d = d + 4 * x + 6;
      } else {
          d = d + 4 * (x - y) + 10;
          y--;
      }
      x++;
  }
}

void Display1306::drawOutlinedCircle(uint8_t x1, uint8_t y1, uint8_t r, uint8_t outline_width) {
  // Рисуем закрашенный круг
  drawCircleFilled(x1, y1, r);
  
  // Рисуем контур (можно другим цветом)
  for(uint8_t w = 0; w < outline_width; w++) {
      drawCircleFrame(x1, y1, r - w);
  }
}

void Display1306::drawArc(uint8_t x1, uint8_t y1, uint8_t r, float start_angle, float end_angle) {
  int x = 0;
  int y = r;
  int d = 3 - 2 * r;
  
  // Degress to radian
  start_angle = start_angle * NUM_PI / 180.0;
  end_angle = end_angle * NUM_PI / 180.0;

  while (x <= y) {
      for(int i = 0; i < 8; i++) {
          int px, py;
          switch(i) {
              case 0: px = x; py = y; break;
              case 1: px = -x; py = y; break;
              case 2: px = x; py = -y; break;
              case 3: px = -x; py = -y; break;
              case 4: px = y; py = x; break;
              case 5: px = -y; py = x; break;
              case 6: px = y; py = -x; break;
              case 7: px = -y; py = -x; break;
          }
          
          float angle = atan2(py, px);
          if(angle < 0) angle += 2*NUM_PI;
          
          // Draw is angle in 
          if(angle >= start_angle && angle <= end_angle) {
              drawPixel(x1 + px, y1 + py);
          }
      }

      if (d < 0) {
          d = d + 4 * x + 6;
      } else {
          d = d + 4 * (x - y) + 10;
          y--;
      }
      x++;
  }
}

void Display1306::drawArcFilled(uint8_t x1, uint8_t y1, uint8_t r, float start_angle, float end_angle) {
  // Draw arc
  drawArc(x1, y1, r, start_angle, end_angle);
  
  // Draw radius
  float start_angle = start_angle * NUM_PI / 180.0;
  float end_angle = end_angle * NUM_PI / 180.0;
  
  drawLine(x1, y1, x1 + r * cos(start_angle), y1 + r * sin(start_angle));
  drawLine(x1, y1, x1 + r * cos(end_angle), y1 + r * sin(end_angle));
  
  // Filled
  for(uint8_t rad = 1; rad < r; rad++) {
      drawArc(x1, y1, rad, start_angle, end_angle);
  }
}