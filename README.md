# SSD1306 display STM32 HAL library
## - A full-fledged C++ library for comfortable work with the SSD1306 display on the STM32F1 using the HAL framework!

1) To set-up I2C connection for display choose Connectivity -> I2C1 / I2C2
2) In the dropdown menu select I2C - I2C
3) On the Parameter Settings tab set:
    - I2C Speed Mode - FastMode
    - I2C Clock Speed (Hz) - 400000
4) On the NVIC Settings tab set:
    - I2C1 event interrupt - Enabled
5) Configure the project and include any example file in main.cpp
6) In main.h write: "extern I2C_HandleTypeDef hi2c1;" for use this variable in other files
7) Don't forget past self code in USER CODE BEGIN region blocks to avoid deleting the code during the next project configuration in CubeMX!
8) Copy example cpp file in Src directory
9) In main.cpp in main(void) run another function in example with "test();"
10) I hope everything worked, good luck in project!
