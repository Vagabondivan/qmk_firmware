/*
 * Copyright 2022 Vagabondivan
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
 * You should have received a copy of the GNU General Public LicensezZZ
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

//#include "config_common.h"

/* USB Device descriptor parameter */
//#define VENDOR_ID       0xFEED
//#define PRODUCT_ID      0x6060
//#define DEVICE_VER      0x0001
//#define MANUFACTURER    Vagabondivan
//#define PRODUCT         Horus

/* key matrix size */
#define MATRIX_ROWS 1
#define MATRIX_COLS 2

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
*/
#define DIODE_DIRECTION COL2ROW

// Default pin-out for ProMicro
#define MATRIX_ROW_PINS { F7 }
#define MATRIX_COL_PINS { B6, B5 }

/* Encoder section */
#define ENCODER_RESOLUTION 4
#define ENCODERS_PAD_A { D1 }
#define ENCODERS_PAD_B { E6 }
#define ENCODER_DIRECTION_FLIP

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* Tap Dance */
#define TAPPING_TERM 250

/* Media Keys */
#define MEDIA_KEY_DELAY 10

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)
