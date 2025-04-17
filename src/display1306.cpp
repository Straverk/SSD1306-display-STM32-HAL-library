#include "display1306.h"


Display1306::Display1306(I2C_HandleTypeDef *i2c)
{
  _i2c = i2c;
  
  init();
}
Display1306::Display1306(I2C_HandleTypeDef *i2c, uint8_t address) : Display1306(i2c)
{
  _address = address;
}


void Display1306::init()
{
  uint8_t data[3];

  // Set display off
  data[0] = 0xAE;
  _writeCommand(data, 1);

  // Set oscillator frequency
  data[0] = 0xD5;
  data[1] = 0x80;
  _writeCommand(data, 2);

  // Enable charge pump regulator
  data[0] = 0x8D;
  data[1] = 0x14;
  _writeCommand(data, 2);

  // Set display start line
  data[0] = 0x40;
  _writeCommand(data, 1);

  // Set segment remap
  data[0] = 0xA1;
  _writeCommand(data, 1);

  // Set COM output scan direction
  data[0] = 0xC8;
  _writeCommand(data, 1);

  // Set COM pins hardware configuration
  data[0] = 0xDA;
  data[1] = 0x12;
  _writeCommand(data, 2);

  // Set MUX ratio
  data[0] = 0xA8;
  data[1] = 63;
  _writeCommand(data, 2);

  // Set display offset
  data[0] = 0xD3;
  data[1] = 0;
  _writeCommand(data, 2);

  // Set horizontal addressing mode
  data[0] = 0x20;
  data[1] = 0x00;
  _writeCommand(data, 2);

  // Set column address
  data[0] = 0x21;
  data[1] = 0;
  data[2] = 127;
  _writeCommand(data, 3);

  // Set page address
  data[0] = 0x22;
  data[1] = 0;
  data[2] = 7;
  _writeCommand(data, 3);

  // Set contrast
  data[0] = 0x81;
  data[1] = 0x7F;
  _writeCommand(data, 2);

  // Entire display on
  data[0] = 0xA4;
  _writeCommand(data, 1);

  // Set normal display
  data[0] = 0xA6;
  _writeCommand(data, 1);

  // Set display on
  data[0] = 0xAF;
  _writeCommand(data, 1);

  update();
}



void Display1306::clear()
{
  for (uint16_t i = 0; i < BUFFER_SIZE; i++)
  {
    _displayBuffer[i] = 0x00;
  }
}

void Display1306::update()
{
  _writeData(_displayBuffer, BUFFER_SIZE);
}



uint8_t Display1306::_writeCommand(uint8_t* data, uint8_t size)
{
  return HAL_I2C_Mem_Write(_i2c, _address, SSD1306_I2C_CONTROL_BYTE_COMMAND,
                            1, data, size, SSD1306_I2C_TIMEOUT);
}

uint8_t Display1306::_writeData(uint8_t* data, uint16_t size)
{
  return HAL_I2C_Mem_Write(_i2c, _address, SSD1306_I2C_CONTROL_BYTE_DATA,
                            1, data, size, SSD1306_I2C_TIMEOUT);
}