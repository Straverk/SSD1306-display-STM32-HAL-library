#ifndef DISPLAY1306_H // Include guard start.
#define DISPLAY1306_H

#include <stdint.h>
#include "stm32f1xx_hal.h"
#include "font_5x8.h"
#include <string>

using std::string;


#define SSD1306_I2C_TIMEOUT                 100
#define SSD1306_I2C_ADDRESS                 0x78
#define SSD1306_I2C_CONTROL_BYTE_COMMAND    0x00
#define SSD1306_I2C_CONTROL_BYTE_DATA       0x40


class Display1306
{
public:
  static const uint8_t WIDTH = 128;
  static const uint8_t HEIGHT = 64;

  //Display1306(I2C_HandleTypeDef i2c, uint8_t address);
  Display1306(I2C_HandleTypeDef *i2c);

  //  Core functions
  void init();

  void drawPixel(uint8_t x, uint8_t y);
  void clearPixel(uint8_t x, uint8_t y);

  void drawRect(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);
  void clearRect(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);

  void writeChar(unsigned char ch, uint8_t start_x, uint8_t row, const fontData font[][5]);
  void writeString(string s, uint8_t start_x, uint8_t row, const fontData font[][5]);

  void clear();
  void update();


private:
  static const uint16_t BUFFER_SIZE = (WIDTH * HEIGHT) / 8;
  uint8_t _displayBuffer[BUFFER_SIZE]{};

  uint8_t _address = 0x78;

  I2C_HandleTypeDef *_i2c;

  uint8_t _writeCommand(uint8_t* command, uint8_t size);
  uint8_t _writeData(uint8_t* data, uint16_t size);

  void _drawBytePixel(uint8_t x, uint8_t y);
  void _clearBytePixel(uint8_t x, uint8_t y);
};

#endif