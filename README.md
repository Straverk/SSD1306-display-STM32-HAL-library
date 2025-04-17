# SSD1306 display STM32 HAL library
## - A full-fledged C++ library for comfortable work with the SSD1306 display on the STM32F1 using the HAL framework!

# CubeMX Settings
1) To set-up I2C connection for display choose Connectivity -> I2C1 / I2C2
2) In the dropdown menu select I2C - I2C
3) On the Parameter Settings tab set:
    - I2C Speed Mode - FastMode
    - I2C Clock Speed (Hz) - 400000
4) On the NVIC Settings tab set:
    - I2C1 event interrupt - Enabled