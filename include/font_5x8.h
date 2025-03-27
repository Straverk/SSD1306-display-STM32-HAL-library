#ifndef FONT_5x8_H
#define FONT_5x8_H


#include <stdint.h>
typedef uint8_t fontData;

namespace SSD1306_Font
{
  const uint8_t fontWidth = 5;                  // Font width, padding excluded.
  const uint8_t fontHeight = 5;                 // Font height, padding included.
  const fontData CharData[128][5] = {
  // 0 NUL
 {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
  // 1 SOH
 {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
  // 2 STX
 {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
  // 3 ETX
 {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
  // 4 QOT
 {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
  // 5 ENQ
 {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
  // 6 ACK
 {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
  // 7 BEL
 {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
  // 8 BS
 {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
  // 9 HT
 {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
  // 10 LF
 {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
  // 11 VT
 {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
  // 12 FF
 {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
  // 13 CR
 {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
  // 14 SO
 {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
  // 15 SI
 {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
  // 16 DLE
 {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
  // 17 DC1
 {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
  // 18 DC2
 {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
  // 19 DC3
 {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
  // 20 DC4
 {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
  // 21 NAK
 {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
  // 22 SYN
 {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
  // 23 ETB
 {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
  // 24 CAN
 {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
  // 25 EM
 {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
  // 26 SUB
 {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
  // 27 ESC
 {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
  // 28 FS
 {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
  // 29 GS
 {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
  // 30 RS
 {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
  // 31 US
 {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
  // 32 Space
 {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000},
  // 33 !
 {0b00000000,
  0b00000000,
  0b01011111,
  0b00000000,
  0b00000000},
  // 34 "
 {0b00000000,
  0b00000111,
  0b00000000,
  0b00000111,
  0b00000000},
  // 35 #
 {0b00010100,
  0b01111111,
  0b00010100,
  0b01111111,
  0b00010100},
  // 36 $
 {0b00100100,
  0b00101010,
  0b01111111,
  0b00101010,
  0b00010010},
  // 37 %
 {0b00100011,
  0b00010011,
  0b00001000,
  0b01100100,
  0b01100010},
  // 38 &
 {0b00110110,
  0b01001001,
  0b01010110,
  0b00100000,
  0b01010000},
  // 39 '
 {0b00000000,
  0b00000111,
  0b00000000,
  0b00000000,
  0b00000000},
  // 40 (
 {0b00000000,
  0b00011100,
  0b01100011,
  0b00000000,
  0b00000000},
  // 41 )
 {0b00000000,
  0b00000000,
  0b01100011,
  0b00011100,
  0b00000000},
  // 42 *
 {0b00001010,
  0b00000100,
  0b00011111,
  0b00000100,
  0b00001010},
  // 43 +
 {0b00001000,
  0b00001000,
  0b00111110,
  0b00001000,
  0b00001000},
  // 44 ,
 {0b00000000,
  0b11100000,
  0b00000000,
  0b00000000,
  0b00000000},
  // 45 -
 {0b00001000,
  0b00001000,
  0b00001000,
  0b00001000,
  0b00001000},
  // 46 .
 {0b00000000,
  0b01100000,
  0b01100000,
  0b00000000,
  0b00000000},
  // 47 /
 {0b00000000,
  0b01100000,
  0b00011100,
  0b00000011,
  0b00000000},
  // 48 0
 {0b00111110,
  0b01010001,
  0b01001001,
  0b01000101,
  0b00111110},
  // 49 1
 {0b01000100,
  0b01000010,
  0b01111111,
  0b01000000,
  0b01000000},
  // 50 2
 {0b01100010,
  0b01010001,
  0b01001001,
  0b01001001,
  0b01000110},
  // 51 3
 {0b00100010,
  0b01000001,
  0b01001001,
  0b01001001,
  0b00110110},
  // 52 4
 {0b00011000,
  0b00010100,
  0b00010010,
  0b01111111,
  0b00010000},
  // 53 5
 {0b00100111,
  0b01000101,
  0b01000101,
  0b01000101,
  0b00111001},
  // 54 6
 {0b00111110,
  0b01001001,
  0b01001001,
  0b01001001,
  0b00110010},
  // 55 7
 {0b00000001,
  0b01110001,
  0b00001001,
  0b00000101,
  0b00000011},
  // 56 8
 {0b00110110,
  0b01001001,
  0b01001001,
  0b01001001,
  0b00110110},
  // 57 9
 {0b00100110,
  0b01001001,
  0b01001001,
  0b01001001,
  0b00111110},
  // 58 :
 {0b00000000,
  0b01100110,
  0b01100110,
  0b00000000,
  0b00000000},
  // 59 ;
 {0b00000000,
  0b00010110,
  0b01110110,
  0b00000000,
  0b00000000},
  // 60 <
 {0b00001000,
  0b00010100,
  0b00100010,
  0b01000001,
  0b00000000},
  // 61 =
 {0b00100100,
  0b00100100,
  0b00100100,
  0b00100100,
  0b00100100},
  // 62 >
 {0b00000000,
  0b01000001,
  0b00100010,
  0b00010100,
  0b00001000},
  // 63 ?
 {0b00000010,
  0b00000001,
  0b01010001,
  0b00001001,
  0b00000110},
  // 64 @
 {0b00111110,
  0b01001001,
  0b01110001,
  0b01000001,
  0b00011110},
  // 65 A
 {0b01111110,
  0b00010001,
  0b00010001,
  0b00010001,
  0b01111110},
  // 66 B
 {0b01111111,
  0b01001001,
  0b01001001,
  0b01001001,
  0b00110110},
  // 67 C
 {0b00111110,
  0b01000001,
  0b01000001,
  0b01000001,
  0b00100010},
  // 68 D
 {0b01111111,
  0b01000001,
  0b01000001,
  0b00100010,
  0b00011100},
  // 69 E
 {0b01111111,
  0b01001001,
  0b01001001,
  0b01001001,
  0b01000001},
  // 70 F
 {0b01111111,
  0b00001001,
  0b00001001,
  0b00001001,
  0b00000001},
  // 71 G
 {0b00111110,
  0b01000001,
  0b01000001,
  0b01001001,
  0b00111000},
  // 72 H
 {0b01111111,
  0b00001000,
  0b00001000,
  0b00001000,
  0b01111111},
  // 73 I
 {0b00000000,
  0b01000001,
  0b01111111,
  0b01000001,
  0b00000000},
  // 74 J
 {0b00100000,
  0b01000000,
  0b01000001,
  0b00111111,
  0b00000001},
  // 75 K
 {0b01111111,
  0b00001000,
  0b00010100,
  0b00100010,
  0b01000001},
  // 76 L
 {0b01111111,
  0b01000000,
  0b01000000,
  0b01000000,
  0b01000000},
  // 77 M
 {0b01111111,
  0b00000010,
  0b00000100,
  0b00000010,
  0b01111111},
  // 78 N
 {0b01111111,
  0b00000100,
  0b00001000,
  0b00010000,
  0b01111111},
  // 79 O
 {0b00111110,
  0b01000001,
  0b01000001,
  0b01000001,
  0b00111110},
  // 80 P
 {0b01111111,
  0b00001001,
  0b00001001,
  0b00001001,
  0b00000110},
  // 81 Q
 {0b00111110,
  0b01000001,
  0b00100001,
  0b01000001,
  0b10111110},
  // 82 R
 {0b01111111,
  0b00001001,
  0b00011001,
  0b00101001,
  0b01000110},
  // 83 S
 {0b00100110,
  0b01001001,
  0b01001001,
  0b01001001,
  0b00110010},
  // 84 T
 {0b00000001,
  0b00000001,
  0b01111111,
  0b00000001,
  0b00000001},
  // 85 U
 {0b00111111,
  0b01000000,
  0b01000000,
  0b01000000,
  0b00111111},
  // 86 V
 {0b00000111,
  0b00011000,
  0b01100000,
  0b00011000,
  0b00000111},
  // 87 W
 {0b01111111,
  0b00100000,
  0b00010000,
  0b00100000,
  0b01111111},
  // 88 X
 {0b01100011,
  0b00010100,
  0b00001000,
  0b00010100,
  0b01100011},
  // 89 Y
 {0b00000011,
  0b00001100,
  0b01110000,
  0b00001100,
  0b00000011},
  // 90 Z
 {0b01100001,
  0b01010001,
  0b01001001,
  0b01000101,
  0b01000011},
  // 91 [
 {0b00000000,
  0b01111111,
  0b01000001,
  0b00000000,
  0b00000000},
  // 92 \'\'
 {0b00000000,
  0b00000011,
  0b00011100,
  0b01100000,
  0b00000000},
  // 93 ]
 {0b00000000,
  0b00000000,
  0b01000001,
  0b01111111,
  0b00000000},
  // 94 ^
 {0b00000100,
  0b00000010,
  0b00000001,
  0b00000010,
  0b00000100},
  // 95 _
 {0b01000000,
  0b01000000,
  0b01000000,
  0b01000000,
  0b01000000},
  // 96 '
 {0b00000000,
  0b00000111,
  0b00000000,
  0b00000000,
  0b00000000},
  // 97 a
 {0b00100000,
  0b01010100,
  0b01010100,
  0b01010100,
  0b01111000},
  // 98 b
 {0b01111111,
  0b01000100,
  0b01000100,
  0b01000100,
  0b00111000},
  // 99 c
 {0b00111000,
  0b01000100,
  0b01000100,
  0b01000100,
  0b00101000},
  // 100 d
 {0b00111000,
  0b01000100,
  0b01000100,
  0b01000100,
  0b01111111},
  // 101 e
 {0b00111000,
  0b01010100,
  0b01010100,
  0b01010100,
  0b00011000},
  // 102 f
 {0b00001000,
  0b01111110,
  0b00001001,
  0b00000001,
  0b00000010},
  // 103 g
 {0b00011000,
  0b00100100,
  0b10100100,
  0b10100100,
  0b01111000},
  // 104 h
 {0b01111111,
  0b00000100,
  0b00000100,
  0b00000100,
  0b01111000},
  // 105 i
 {0b00000000,
  0b01000100,
  0b01111101,
  0b01000000,
  0b00000000},
  // 106 j
 {0b00000000,
  0b01000000,
  0b10000000,
  0b10000000,
  0b01111101},
  // 107 k
 {0b01111111,
  0b00010000,
  0b00011000,
  0b00100100,
  0b01000000},
  // 108 l
 {0b00000000,
  0b01000001,
  0b01111111,
  0b01000000,
  0b00000000},
  // 109 m
 {0b01111100,
  0b00000100,
  0b00001000,
  0b00000100,
  0b01111000},
  // 110 n
 {0b01111100,
  0b00001000,
  0b00000100,
  0b00000100,
  0b01111000},
  // 111 o
 {0b00111000,
  0b01000100,
  0b01000100,
  0b01000100,
  0b00111000},
  // 112 p
 {0b11111100,
  0b00100100,
  0b00100100,
  0b00100100,
  0b00011000},
  // 113 q
 {0b00011000,
  0b00100100,
  0b00100100,
  0b00100100,
  0b11111100},
  // 114 r
 {0b01111100,
  0b00001000,
  0b00000100,
  0b00000100,
  0b00000000},
  // 115 s
 {0b01001000,
  0b01010100,
  0b01010100,
  0b01010100,
  0b00100000},
  // 116 t
 {0b00000100,
  0b00111111,
  0b01000100,
  0b01000000,
  0b00100000},
  // 117 u
 {0b00111100,
  0b01000000,
  0b01000000,
  0b00100000,
  0b01111100},
  // 118 v
 {0b00011100,
  0b00100000,
  0b01000000,
  0b00100000,
  0b00011100},
  // 119 w
 {0b00111100,
  0b01000000,
  0b00100000,
  0b01000000,
  0b00111100},
  // 120 x
 {0b01000100,
  0b00101000,
  0b00010000,
  0b00101000,
  0b01000100},
  // 121 y
 {0b00011100,
  0b00100000,
  0b10100000,
  0b10100000,
  0b01111100},
  // 122 z
 {0b01000100,
  0b01100100,
  0b01010100,
  0b01001100,
  0b01000100},
  // 123 {
 {0b00000000,
  0b00001000,
  0b00110110,
  0b01000001,
  0b00000000},
  // 124 |
 {0b00000000,
  0b00000000,
  0b01111111,
  0b00000000,
  0b00000000},
  // 125 }
 {0b00000000,
  0b01000001,
  0b00110110,
  0b00001000,
  0b00000000},
  // 126 ~
 {0b00010000,
  0b00001000,
  0b00010000,
  0b00100000,
  0b00010000},
  // 127 DEL
 {0b11111111,
  0b11111111,
  0b11111111,
  0b11111111,
  0b11111111}
};
};

#endif  // FONT_5x8_H