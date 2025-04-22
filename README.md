# SSD1306 display STM32 HAL library
## - A full-fledged C++ library for comfortable work with the SSD1306 display on the STM32F1 using the HAL framework!

# CubeMX Set-up Settings
1) To set-up I2C connection for display choose Connectivity -> I2C1 / I2C2
2) In the dropdown menu select I2C - I2C
3) On the Parameter Settings tab set:
    - I2C Speed Mode - FastMode
    - I2C Clock Speed (Hz) - 400000
4) On the NVIC Settings tab set:
    - I2C1 event interrupt - Enabled


## Display function
# Сreating an instance of an object
- Display1306(I2C_HandleTypeDef *i2c);
- Display1306(I2C_HandleTypeDef *i2c, uint8_t address);

# Basic function
- void init();
- void clear();
- void update();

- void drawPixel(uint8_t x, uint8_t y);
- void clearPixel(uint8_t x, uint8_t y);

# Basic graphics functions
- void drawLineH(uint8_t x1, uint8_t x2, uint8_t y);
- void drawLineV(uint8_t x, uint8_t y1, uint8_t y2);
- void drawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);
- void clearLineH(uint8_t x1, uint8_t x2, uint8_t y);
- void clearLineV(uint8_t x, uint8_t y1, uint8_t y2);
- void clearLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);

- void drawRectFrame(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);
- void drawRectFrameBorder(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t borderSize);
- void drawRectFill(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);
- void clearRect(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);

# Circle graphics functions
- void drawCircleFrame(uint8_t x1, uint8_t y1, uint8_t r);
- void drawCircleFilled(uint8_t x1, uint8_t y1, uint8_t r);
- void drawOutlinedCircle(uint8_t x1, uint8_t y1, uint8_t r, uint8_t outline_width);
- void clearCircle(uint8_t x1, uint8_t y1, uint8_t r);

- void drawArc(uint8_t x1, uint8_t y1, uint8_t r, float start_angle, float end_angle);
- void drawArcFilled(uint8_t x1, uint8_t y1, uint8_t r, float start_angle, float end_angle);

# Text graphics functions
- void drawCharRow(const unsigned char &ch, uint8_t start_x, uint8_t row, Font *font);
- void drawStringRow(const unsigned char str[], uint8_t start_x, uint8_t row, Font *font);
- void drawStringRow(const char str[], uint8_t start_x, uint8_t row, Font *font);
- void drawStringRow(string str, uint8_t start_x, uint8_t row, Font *font);
  
- void drawChar(const unsigned char &ch, uint8_t start_x, uint8_t start_y, Font *font);
- void drawString(const unsigned char str[], uint8_t start_x, uint8_t start_y, Font *font);
- void drawString(const char str[], uint8_t start_x, uint8_t start_y, Font *font);
- void drawString(string str, uint8_t start_x, uint8_t start_y, Font *font);

## Exclusion of functions from compilation
This allows you to save a bit of memory and remove unused functions.
Use #define directives to exclude unnecessary functions
| |draw/clear Pixel|drawLine and etc.|drawRect and etc.|drawCircle and etc.|drawArc and etc.|
|-|-|-|-|-|-|
|DISPLAY_CUT_ALL_GRAPHICS|✓|❌|❌|❌|❌|
|DISPLAY_CUT_NOT_TEXT_GRAPHICS|✓|❌|❌|❌|❌|
|DISPLAY_CUT_RECT_GRAPHICS|✓| |❌| | |
|DISPLAY_CUT_CIRCLE_GRAPHICS|✓| | |❌|❌|
|DISPLAY_CUT_CIRCLE_ARC_GRAPHICS|✓| | |✓|❌|


| |drawCharRow|drawStringRow|drawChar|drawString|
|-|-|-|-|-|-|
|DISPLAY_CUT_NOT_TEXT_GRAPHICS|✓|✓|✓|✓|
|DISPLAY_CUT_TEXT_NOT_ROW_GRAPHICS|✓|✓|❌|❌|
|DISPLAY_CUT_TEXT_ROW_GRAPHICS|❌|❌|✓|✓|
|DISPLAY_CUT_ALL_GRAPHICS|❌|❌|❌|❌|
|DISPLAY_CUT_TEXT_GRAPHICS|❌|❌|❌|❌|