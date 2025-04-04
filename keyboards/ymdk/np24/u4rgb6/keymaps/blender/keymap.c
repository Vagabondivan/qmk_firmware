/* Blender - Copyright 2025 Vagabondivan
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
#include QMK_KEYBOARD_H

/* Layer Names */
enum custom_layers {
    _NUMPAD,
    _BLEND,
    _LITE,
    _RESET
};

/* Custom keycodes */
enum custom_keycodes {
    NUMPAD = SAFE_RANGE,
    BLEND,
    RESET,
    CTRL_XX,
    DOUBLEO
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_NUMPAD] = LAYOUT_ortho_6x4 (
  KC_NUM,         KC_HOME,  KC_END,   KC_BSPC,
  LALT(KC_SLSH),  KC_C,     KC_PERC,  KC_PSLS,
  KC_P7,          KC_P8,    KC_P9,    KC_PAST,
  KC_P4,          KC_P5,    KC_P6,    KC_PMNS,
  KC_P1,          KC_P2,    KC_P3,    KC_PPLS,
  TG(_LITE),      KC_P0,    KC_PDOT,  KC_PENT
),

[_BLEND] = LAYOUT_ortho_6x4 (
  KC_1,        KC_2,     KC_3,    LCTL(KC_R),
  LCTL(KC_B),  KC_PSLS,  KC_E,    KC_I,
  KC_P7,       KC_P8,    KC_P9,   KC_O,
  KC_P4,       KC_P5,    KC_P6,   KC_G,
  KC_P1,       KC_P2,    KC_P3,   KC_R,
  KC_TRNS,     KC_P0,    KC_DOT,  KC_S
),

[_LITE] = LAYOUT_ortho_6x4 (
  NUMPAD,      BLEND,       KC_NO,       KC_DEL,
  LCTL(KC_Y),  LCTL(KC_K),  CTRL_XX,     LCTL(KC_U),  
  RGB_TOG,     BL_DOWN,     BL_UP,       BL_TOGG,
  RGB_VAD,     RGB_VAI,     RGB_SAD,     RGB_SAI,
  RGB_HUD,     RGB_HUI,     RGB_RMOD,    RGB_MOD,
  KC_TRNS,     DOUBLEO,     LCTL(KC_L),  MO(_RESET)
),

[_RESET] = LAYOUT_ortho_6x4 (
  QK_BOOT,  KC_NO,  KC_NO,  KC_NO,
  KC_NO,    KC_NO,  KC_NO,  KC_NO,
  KC_NO,    KC_NO,  KC_NO,  KC_NO,
  KC_NO,    KC_NO,  KC_NO,  KC_NO,
  KC_NO,    KC_NO,  KC_NO,  KC_NO,
  KC_NO,    KC_NO,  KC_NO,  KC_NO
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {

        case NUMPAD:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_NUMPAD);
            }
            return false;

        case BLEND:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_BLEND);
            }
            return false;

        case CTRL_XX:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_X) SS_TAP(X_X) SS_UP(X_LCTL));
            }
            return false;

        case DOUBLEO:
            if (record->event.pressed) {
                SEND_STRING("00");
            }
            return false;
    }

    return true;

}
