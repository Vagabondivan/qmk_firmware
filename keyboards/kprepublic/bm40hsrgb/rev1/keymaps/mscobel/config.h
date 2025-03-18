/* MsCobel - Copyright 2025 Vagabondivan
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

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12

/* key matrix pins */
#define MATRIX_ROW_PINS { B3, B2, E6, B5 }
#define MATRIX_COL_PINS { B6, C6, B4, D7, D4, D6, C7, F6, F5, F4, F1, F0 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* Maximum time (milliseconds) allowed for TAP-DANCE keys*/
#define TAPPING_TERM 200

// RGB Matrix Animation modes. Explicitly enabled
// For full list of effects, see: https://docs.qmk.fm/#/feature_rgb_matrix?id=rgb-matrix-effects
#define RGB_DI_PIN E2

#ifdef RGB_MATRIX_ENABLE

	#define USB_MAX_POWER_CONSUMPTION 500						// Max power consumption via USB port
	#define DRIVER_LED_TOTAL 47									// Number of active LEDs
	#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 180					// Limit to vendor-recommended value

	// enabled only if RGB_MATRIX_FRAMEBUFFER_EFFECTS is defined
	#define RGB_MATRIX_FRAMEBUFFER_EFFECTS

	// enabled only of RGB_MATRIX_KEYPRESSES or RGB_MATRIX_KEYRELEASES is defined
	#define RGB_MATRIX_KEYPRESSES								// reacts to key press
	#define RGB_MATRIX_KEYRELEASES								// reacts to key release

#endif
