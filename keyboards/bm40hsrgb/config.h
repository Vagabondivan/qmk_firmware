/* Copyright 2020 vagabondivan
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

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x4B50 // "KP"
#define PRODUCT_ID      0x3430 // "40"
#define DEVICE_VER      0x0001
#define MANUFACTURER    KPRepublic
#define PRODUCT         BM40 Hotswap RGB
#define DESCRIPTION     A really compact 40% (1x2Uc) ortholinear keyboard

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12

/* key matrix pins */
#define MATRIX_ROW_PINS { B3, B2, E6, B5 }
#define MATRIX_COL_PINS { B6, C6, B4, D7, D4, D6, C7, F6, F5, F4, F1, F0 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* Lights of when computer sleeps */
#define RGB_DISABLE_WHEN_USB_SUSPENDED true

// toggle one-shot layer keys after this many presses
#define ONESHOT_TAP_TOGGLE 3

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* Maximum time (milliseconds) allowed for TAP-DANCE keys*/
#define TAPPING_TERM 200

/* Set Autoshift hold time to activate */
#define AUTO_SHIFT_TIMEOUT 230

#define RGB_DI_PIN E2
#define RGBLED_NUM 53
#define DRIVER_LED_TOTAL RGBLED_NUM
// #define DISABLE_RGB_MATRIX_ALPHAS_MODS                          // Disables RGB_MATRIX_ALPHAS_MODS
#define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN                     // Disables  RGB_MATRIX_GRADIENT_UP_DOWN
#define DISABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT                     // Disables  RGB_MATRIX_GRADIENT_LEFT_RIGHT
// #define DISABLE_RGB_MATRIX_BREATHING                            // Disables  RGB_MATRIX_BREATHING
#define DISABLE_RGB_MATRIX_BAND_SAT                             // Disables  RGB_MATRIX_BAND_SAT
// #define DISABLE_RGB_MATRIX_BAND_VAL                          // Disables  RGB_MATRIX_BAND_VAL
#define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT                    // Disables  RGB_MATRIX_BAND_PINWHEEL_SAT
#define DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL                    // Disables  RGB_MATRIX_BAND_PINWHEEL_VAL
#define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT                      // Disables  RGB_MATRIX_BAND_SPIRAL_SAT
#define DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL                      // Disables  RGB_MATRIX_BAND_SPIRAL_VAL
#define DISABLE_RGB_MATRIX_CYCLE_ALL                            // Disables  RGB_MATRIX_CYCLE_ALL
#define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT                     // Disables  RGB_MATRIX_CYCLE_LEFT_RIGHT
#define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN                        // Disables  RGB_MATRIX_CYCLE_UP_DOWN
#define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON               // Disables  RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#define DISABLE_RGB_MATRIX_CYCLE_OUT_IN                         // Disables  RGB_MATRIX_CYCLE_OUT_IN
#define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL                    // Disables  RGB_MATRIX_CYCLE_OUT_IN_DUAL
#define DISABLE_RGB_MATRIX_CYCLE_PINWHEEL                       // Disables  RGB_MATRIX_CYCLE_PINWHEEL
#define DISABLE_RGB_MATRIX_CYCLE_SPIRAL                         // Disables  RGB_MATRIX_CYCLE_SPIRAL
#define DISABLE_RGB_MATRIX_DUAL_BEACON                          // Disables  RGB_MATRIX_DUAL_BEACON
#define DISABLE_RGB_MATRIX_RAINBOW_BEACON                       // Disables  RGB_MATRIX_RAINBOW_BEACON
#define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS                    // Disables  RGB_MATRIX_RAINBOW_PINWHEELS
#define DISABLE_RGB_MATRIX_RAINDROPS                            // Disables  RGB_MATRIX_RAINDROPS
#define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS                  // Disables  RGB_MATRIX_JELLYBEAN_RAINDROPS
// #define DISABLE_RGB_MATRIX_TYPING_HEATMAP                    // Disables  RGB_MATRIX_TYPING_HEATMAP
// #define DISABLE_RGB_MATRIX_DIGITAL_RAIN                      // Disables  RGB_MATRIX_DIGITAL_RAIN
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE                // Disables  RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE                       // Disables  RGB_MATRIX_SOLID_REACTIVE
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE                  // Disables  RGB_MATRIX_SOLID_REACTIVE_WIDE
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE             // Disables  RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS                 // Disables  RGB_MATRIX_SOLID_REACTIVE_CROSS
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS            // Disables  RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS                 // Disables  RGB_MATRIX_SOLID_REACTIVE_NEXUS
//#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS          // Disables  RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#define DISABLE_RGB_MATRIX_SPLASH                               // Disables  RGB_MATRIX_SPLASH
#define DISABLE_RGB_MATRIX_MULTISPLASH                          // Disables  RGB_MATRIX_MULTISPLASH
#define DISABLE_RGB_MATRIX_SOLID_SPLASH                         // Disables  RGB_MATRIX_SOLID_SPLASH
// #define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH                 // Disables  RGB_MATRIX_SOLID_MULTISPLASH

#ifdef RGB_DI_PIN
    #define RGBLIGHT_LAYERS
    #define RGB_MATRIX_KEYPRESSES                               // reacts to keypresses
    #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
    #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_KNIGHT_LENGTH 4
    #define RGBLIGHT_EFFECT_KNIGHT_OFFSET 14
    #define RGBLIGHT_EFFECT_KNIGHT_LED_NUM 8
    #define RGB_DIGITAL_RAIN_DROPS    24
    #define USB_MAX_POWER_CONSUMPTION 100
    #define ONESHOT_TIMEOUT           2000
#   endif

