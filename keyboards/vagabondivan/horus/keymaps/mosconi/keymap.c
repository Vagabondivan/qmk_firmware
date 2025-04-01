/* Mosconi - Copyright 2025 Vagabondivan
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

#include "horus.h"

/* Layer Names */
enum custom_layers {
    _HORUS = 0,
};

/* Tap Dance */
enum tapdance {
    ROUND = 0
};

/*********************     LAYOUTS SECTION     ********************/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_HORUS] = LAYOUT_grid_1x2(

 /*------+-------.
 |   `   |  TAP  |
 |       | DANCE |
 '-------+------*/

    KC_GRV, TD(ROUND)
)

};


/*********************     ENCODER SECTION     ********************/

void knob_code(uint16_t keycode) {

  uint16_t held_keycode_timer = timer_read();
  register_code(keycode);
  while (timer_elapsed(held_keycode_timer) < MEDIA_KEY_DELAY) {
      // no-op
  }
  unregister_code(keycode);
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (biton32(layer_state)) {
    case _HORUS:
        if (clockwise) {
          tap_code(KC_UP);
          break;
        } else {
          tap_code(KC_DOWN);
          break;
        }
    }
    return false;
};

/*********************     TAP DANCE SECTION     ********************/

void dance_egg(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code16(RCS(KC_C));                          // send COPY
    } else if (state->count == 2) {
        tap_code16(RCS(KC_V));                          // send PASTE
    } else if (state->count == 5) {
        reset_keyboard();                               // dfu-mode
    } else {
        reset_tap_dance (state);
    }
};

tap_dance_action_t tap_dance_actions[] = {
    [ROUND] = ACTION_TAP_DANCE_FN(dance_egg),
};
