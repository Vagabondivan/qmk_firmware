/* Copyright 2020 K-rnivoro
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef KEYMMODORE64_H
#define KEYMMODORE64_H

#include "quantum.h"
#include "led.h"


/* 
Option RGB LED (Replacement of original C-64 Power LED):
  Option for Teensy2.0, Arduino Leonardo, Arduino Micro, etc.
  Use a common anode RGB LED, so is ACTIVE LOW (inverted logic)
  - PC Mode: LED Green
  - Any SHIFT pressed (in PC Mode):  LED Cyan (Green+Blue)
  - Commodore Key (C=) pressed (in PC Mode): LED Yellow (Green+Red)
  - Commodore-64 Emulator Mode: LED Red
  - Commodore-16 and Plus/4  Emulator Mode: LED Blue
  - Commodore PET Emulator Mode: LED Purple (Blue+Red) 
*/

//Enable this for RGB LED on Arduino Leonardo, Micro and Teensy 2.00
#define green_led B2
#define red_led B1
#define blue_led B3


/*
Option TX and RX built-in LEDs for ProMicro boards:
  (RGB LED not available in ProMicro due to not having enough pins) 
  Catode connected to chip, so is ACTIVE LOW (inverted logic)
  - PC Mode: Rx Off, Tx Off.
  - Any SHIFT pressed (in PC Mode): Rx On, Tx Off.
  - Commodore Key (C=) pressed (in PC Mode): Rx Off, Tx On.
  - C-64 Mode:  Rx On, Tx On.
  - C-16 Mode:  Rx On, Tx Off.
  - C-128 Mode: Rx Off, Tx On.
  - PET Mode:   Rx Off, Tx Off.
 */

// Enable this for ProMicro built-in LEDS
//#define tx_led B0
//#define rx_led D5
 

#define KEYMAP( \
    K00, K01, K02, K03, K04, K05, K06, K07,                                                                 \
    K10, K11, K12, K13, K14, K15, K16, K17,                                                                 \
    K20, K21, K22, K23, K24, K25, K26, K27,                                                                 \
    K30, K31, K32, K33, K34, K35, K36, K37, K38,                                                            \
    K40, K41, K42, K43, K44, K45, K46, K47, K48,                                                            \
    K50, K51, K52, K53, K54, K55, K56, K57, K58,                                                            \
    K60, K61, K62, K63, K64, K65, K66, K67, K68,                                                            \
    K70, K71, K72, K73, K74, K75, K76, K77, K78,                                                            \
    K80, K81, K82, K83, K84,                K88                                                             \
) { \
    { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   KC_NO         },   \
    { K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   KC_NO         },   \
    { K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   KC_NO         },   \
    { K30,   K31,   K32,   K33,   K34,   K35,   K36,   K37,   K38           },   \
    { K40,   K41,   K42,   K43,   K44,   K45,   K46,   K47,   K48           },   \
    { K50,   K51,   K52,   K53,   K54,   K55,   K56,   K57,   K58           },   \
    { K60,   K61,   K62,   K63,   K64,   K65,   K66,   K67,   K68           },   \
    { K70,   K71,   K72,   K73,   K74,   K75,   K76,   K77,   K78           },   \
    { K80,   K81,   K82,   K83,   K84,   KC_NO, KC_NO, KC_NO, K88           }    \
}
#endif
