#ifndef DISPLAY1306_H // Include guard start.
#define DISPLAY1306_H

#include <string>
#include <stdint.h>
#include "stm32f1xx_hal.h"
#include "font_5x8.h"

using std::string;
using font_ssd1306::Font;

#define SSD1306_I2C_TIMEOUT                 100
#define SSD1306_I2C_ADDRESS                 0x78
#define SSD1306_I2C_CONTROL_BYTE_COMMAND    0x00
#define SSD1306_I2C_CONTROL_BYTE_DATA       0x40


class Display1306
{
public:
  static const uint8_t width = 128;
  static const uint8_t height = 64;

  //Display1306(I2C_HandleTypeDef i2c, uint8_t address);
  Display1306(I2C_HandleTypeDef *i2c);
  Display1306(I2C_HandleTypeDef *i2c, uint8_t address);

  //  Core functions
  void init();

  void drawPixel(uint8_t x, uint8_t y);
  void clearPixel(uint8_t x, uint8_t y);

  void drawLineH(uint8_t x1, uint8_t x2, uint8_t y);
  void drawLineV(uint8_t x, uint8_t y1, uint8_t y2);
  void drawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);

  void drawRectFrame(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);
  void drawRectFrameBorder(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t borderSize);
  void drawRectFill(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);
  void clearRect(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);

  void drawCircleFrame(uint8_t x1, uint8_t y1, uint8_t r);
  void drawCircleFilled(uint8_t x1, uint8_t y1, uint8_t r);
  void drawOutlinedCircle(uint8_t x1, uint8_t y1, uint8_t r, uint8_t outline_width);
  void drawArc(uint8_t x1, uint8_t y1, uint8_t r, float start_angle, float end_angle);
  void drawArcFilled(uint8_t x1, uint8_t y1, uint8_t r, float start_angle, float end_angle);

  void drawCharRow(const unsigned char &ch, uint8_t start_x, uint8_t row, Font *font);
  void drawStringRow(const unsigned char str[], uint8_t start_x, uint8_t row, Font *font);
  void drawStringRow(const char str[], uint8_t start_x, uint8_t row, Font *font);
  void drawStringRow(string str, uint8_t start_x, uint8_t row, Font *font);
  
  void drawChar(const unsigned char &ch, uint8_t start_x, uint8_t start_y, Font *font);
  void drawString(const unsigned char str[], uint8_t start_x, uint8_t start_y, Font *font);
  void drawString(const char str[], uint8_t start_x, uint8_t start_y, Font *font);
  void drawString(string str, uint8_t start_x, uint8_t start_y, Font *font);

  void clear();
  void update();


private:
  static const uint16_t BUFFER_SIZE = (width * height) / 8;
  uint8_t _displayBuffer[BUFFER_SIZE]{};

  uint8_t _address = 0x78;

  I2C_HandleTypeDef *_i2c;

  uint8_t _writeCommand(uint8_t* command, uint8_t size);
  uint8_t _writeData(uint8_t* data, uint16_t size);
};

#endif