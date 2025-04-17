#include "display1306.h"
#include "main.h"
#include "math.h"


#define NUM_PI 3.1415
#define SIN_STEP 0.05
#define WAIT_BETWEEN_STEP 50


using namespace font_ssd1306;

float sin_step = 0;
uint32_t last_sin_tick = 0;


Display1306 display(&hi2c1);
Font *font = new Font_5x8();


void updateScreen() {
  display.clear();

  display.drawString("Hello world! 123", 16, 20, font);
  display.drawRectFrame(0, 0, 32, 16);
  display.drawRectFrame(32, 0, 40, 16);

  display.drawArc(8, 24, 5, 50, 130);
  display.drawArcFilled(8, 24, 5, 130, 210);
  display.drawCircleFrame(8, 24, 3);
}

void start() {
  display.init();

  updateScreen();

  last_sin_tick = HAL_GetTick();

  while (1) {
    if (HAL_GetTick() > last_sin_tick + WAIT_BETWEEN_STEP) {
      last_sin_tick += WAIT_BETWEEN_STEP;

      sin_step += SIN_STEP;
      if (sin_step > 2 * NUM_PI) {
        sin_step = 0;

        updateScreen();
      }

      int y = 16 - ((sin(sin_step) + 1) * 8);
      int x = sin_step * 8;

      display.drawPixel(x, y);

      display.update();
    }
  }
}