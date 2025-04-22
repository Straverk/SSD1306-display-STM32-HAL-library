#include "display1306.h"
#include "math.h"


#ifndef DISPLAY_CUT_ALL_GRAPHICS

#ifndef DISPLAY_CUT_NOT_TEXT_GRAPHICS

#ifndef DISPLAY_NUM_PI
// #define DISPLAY_NUM_PI 3.14159
#define DISPLAY_NUM_PI 3.1415
#endif


#ifndef DISPLAY_CUT_CIRCLE_GRAPHICS

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
    // Horizontal lines between symmetrical points
    drawLineH(x1 - x, x1 + x, y1 + y); // Upper half
    drawLineH(x1 - x, x1 + x, y1 - y); // Lower half
    drawLineH(x1 - y, x1 + y, y1 + x); // Additional lines
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

void Display1306::drawOutlinedCircle(uint8_t x1, uint8_t y1, uint8_t r,
                                     uint8_t outline_width) {
  // Draw filled circle
  drawCircleFilled(x1, y1, r);

  // Draw frame
  for (uint8_t w = 0; w < outline_width; w++) {
    drawCircleFrame(x1, y1, r - w);
  }
}

#ifndef DISPLAY_CUT_CIRCLE_ARC_GRAPHICS

void Display1306::clearCircle(uint8_t x1, uint8_t y1, uint8_t r) {
  int x = 0;
  int y = r;
  int d = 3 - 2 * r;

  while (x <= y) {
    // Horizontal lines between symmetrical points
    clearLineH(x1 - x, x1 + x, y1 + y); // Upper half
    clearLineH(x1 - x, x1 + x, y1 - y); // Lower half
    clearLineH(x1 - y, x1 + y, y1 + x); // Additional lines
    clearLineH(x1 - y, x1 + y, y1 - x);

    if (d < 0) {
      d = d + 4 * x + 6;
    } else {
      d = d + 4 * (x - y) + 10;
      y--;
    }
    x++;
  }
}

void Display1306::drawArc(uint8_t x1, uint8_t y1, uint8_t r, float start_angle,
                          float end_angle) {
  int x = 0;
  int y = r;
  int d = 3 - 2 * r;

  // Degress to radian
  start_angle = start_angle * DISPLAY_NUM_PI / 180.0;
  end_angle = end_angle * DISPLAY_NUM_PI / 180.0;

  while (x <= y) {
    for (int i = 0; i < 8; i++) {
      int px, py;
      switch (i) {
      case 0:
        px = x;
        py = y;
        break;
      case 1:
        px = -x;
        py = y;
        break;
      case 2:
        px = x;
        py = -y;
        break;
      case 3:
        px = -x;
        py = -y;
        break;
      case 4:
        px = y;
        py = x;
        break;
      case 5:
        px = -y;
        py = x;
        break;
      case 6:
        px = y;
        py = -x;
        break;
      case 7:
        px = -y;
        py = -x;
        break;
      }

      float angle = atan2(py, px);
      if (angle < 0)
        angle += 2 * DISPLAY_NUM_PI;

      // Draw is angle in
      if (angle >= start_angle && angle <= end_angle) {
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

void Display1306::drawArcFilled(uint8_t x1, uint8_t y1, uint8_t r,
                                float start_angle, float end_angle) {
  // Draw arc
  drawArc(x1, y1, r, start_angle, end_angle);

  // Draw radius
  start_angle = start_angle * DISPLAY_NUM_PI / 180.0;
  end_angle = end_angle * DISPLAY_NUM_PI / 180.0;

  drawLine(x1, y1, x1 + r * cos(start_angle), y1 + r * sin(start_angle));
  drawLine(x1, y1, x1 + r * cos(end_angle), y1 + r * sin(end_angle));

  // Filled
  for (uint8_t rad = 1; rad < r; rad++) {
    drawArc(x1, y1, rad, start_angle, end_angle);
  }
}

#endif
#endif

#endif
#endif