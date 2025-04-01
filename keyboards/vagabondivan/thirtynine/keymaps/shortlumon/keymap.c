/* ShortLumon - Copyright 2025 Vagabondivan
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

#include QMK_KEYBOARD_H

/* Layer Names */
enum custom_layers {
    _QWERTY = 0,
    _FN,
	_LOWER,
	_RAISE,
	_ADJUST
};

/* Custom keycodes */
enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    FN,
	LOWER,
	RAISE,
	ADJUST,
    CTRL_XX,
    MAIL_1,
    MAIL_2,
    TXT_00,
    TXT_01,
    TXT_02,
    TXT_03,
    TXT_04,
    TXT_05,
    TXT_06,
    TXT_07,
    TXT_08
};

/* Tap Dance */
enum tapdance {
    OPNBR = 0,
    CLSBR,
    CPSLK
};

/*********************     LAYOUTS SECTION     ********************/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_ortho_4x10uC(

 /*--------------------------------------------------------------------.
 |   q  |   w  |   e  |   r  |   t  |   y  |   u  |   i  |   o  |   p  |
 |------+------+------+------+------+------+------+------+------+------|
 |   a  |   s  |   d  |   f  |   g  |   h  |   j  |   k  |   l  | ;  : |
 |------+------+------+------+------+------+------+------+------+------|
 |   z  |   x  |   c  |   v  |   b  |   n  |   m  | , <  |  . > | Entr |
 |------+------+------+------+------+------+------+------+------+------|
 |  FN  | LCTL | LALT | LGUI |   SPC/SFT   | Left | Down |  Up  | Rght |
 `--------------------------------------------------------------------*/

  KC_Q,  KC_W,     KC_E,     KC_R,       KC_T,     KC_Y,  KC_U,     KC_I,     KC_O,     KC_P,   
  KC_A,  KC_S,     KC_D,     KC_F,       KC_G,     KC_H,  KC_J,     KC_K,     KC_L,     KC_SCLN,
  KC_Z,  KC_X,     KC_C,     KC_V,       KC_B,     KC_N,  KC_M,     KC_COMM,  KC_DOT,   KC_ENT,
  FN,    KC_LCTL,  KC_LALT,  KC_LGUI,    RSFT_T(KC_SPC),  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT
),

[_FN] = LAYOUT_ortho_4x10uC(

 /*--------------------------------------------------------------------.
 |  !   |  @   |  #   |  $   |  %   |   ^  |   &  |   *  | ([{  |  }]) |
 |------+------+------+------+------+------+------+------+------+------|
 |  TAB |  2   |  3   |  4   |  5   |   6  |   7  |   8  |   9  | '  " |
 |------+------+------+------+------+------+------+------+------+------|
 | LSFT |  =   | \  | |MAIL_1|  1   |   0  |MAIL_2|   -  |   +  | /  ? |
 |------+------+------+------+------+------+------+------+------+------|
 |      | LWR  | RSE  |NMLOCK|      _      | HOME | PGDN | PGUP | END  |
 `--------------------------------------------------------------------*/

  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,  KC_PERC,  KC_CIRC,  KC_AMPR,  KC_ASTR,  TD(OPNBR),  TD(CLSBR),
  KC_TAB,   KC_2,     KC_3,     KC_4,    KC_5,     KC_6,     KC_7,     KC_8,     KC_9,       KC_QUOT,
  KC_LSFT,  KC_EQL,   KC_BSLS,  MAIL_1,  KC_1,     KC_0,     MAIL_2,   KC_MINS,  KC_PLUS,    KC_SLSH,
  KC_NO,    LOWER,    RAISE,    KC_NUM,     KC_UNDS,         KC_HOME,  KC_PGDN,  KC_PGUP,    KC_END,
),

[_LOWER] = LAYOUT_ortho_4x10uC(

 /*--------------------------------------------------------------------.
 | ESC  |      |      |      |      |      |      |      |      |  DEL |
 |------+------+------+------+------+------+------+------+------+------|
 |      |CTRL+L|CTRL+W|CTRL+Y|      |      |      | MSBL | MSBR |      |
 |------+------+------+------+------+------+------+------+------+------|
 |      |CTRL+K|CTRLXX|CTRL+U|      |      |MSW L |MSW DN|MSW UP|MSW R |
 |------+------+------+------+------+------+------+------+------+------|
 |      |      |  ADJ |      |      ~      | MS L | MS D | MS U | MS R |
 `--------------------------------------------------------------------*/

  KC_ESC,  KC_NO,       KC_NO,       KC_NO,       KC_NO,   KC_NO,  KC_NO,       KC_NO,       KC_NO,       KC_DEL,
  KC_NO,   LCTL(KC_L),  LCTL(KC_W),  LCTL(KC_Y),  KC_NO,   KC_NO,  KC_NO,       KC_MS_BTN1,  KC_MS_BTN2,  KC_NO,
  KC_NO,   LCTL(KC_K),  CTRL_XX,     LCTL(KC_U),  KC_NO ,  KC_NO,  KC_WH_L,     KC_WH_D,     KC_WH_UP,    KC_WH_R,
  KC_NO,   KC_NO,       KC_TRNS,     KC_NO,           KC_TILD,     KC_MS_LEFT,  KC_MS_DOWN,  KC_MS_UP,    KC_MS_RIGHT
),

[_RAISE] = LAYOUT_ortho_4x10uC(

 /*--------------------------------------------------------------------.
 | BRID | BRIU |PRNSCR|PRNSEL| PREV | PLAY | NEXT | MUTE | VOL- | VOL+ |
 |------+------+------+------+------+------+------+------+------+------+
 |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F 10 |
 |------+------+------+------+------+------+------+------+------+------+
 | F 11 |      |      |      |S_SHOT| CALC |      |      |      | F 12 |
 |------+------+------+------+-------------+------+------+------+------+
 |      |  ADJ |      |      |             |      |      |      |      |
 `--------------------------------------------------------------------*/

  KC_BRID,  KC_BRIU,  SGUI(KC_3),  SGUI(KC_4),  KC_MPRV,     KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,
  KC_F1,    KC_F2,    KC_F3,       KC_F4,       KC_F5,       KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,
  KC_F11,   KC_NO,    KC_NO,       KC_NO,       SGUI(KC_S),  KC_CALC,  KC_NO,    KC_NO,    KC_NO,    KC_F12,
  KC_NO,    KC_TRNS,  KC_NO,       KC_NO,               KC_NO,         KC_NO,    KC_NO,    KC_NO,    KC_NO
),

[_ADJUST] = LAYOUT_ortho_4x10uC(

 /*--------------------------------------------------------------------.
 | RSET |      |      |      |      |      |TXT_08|      |TXT_04|TXT_00|
 |------+------+------+------+------+------+------+------+------+------+
 |      |      |      |      |      |      |      |      |TXT_05|TXT_01|
 |------+------+------+------+------+------+------+------+------+------+
 |      |      |      |      |      |      |      |      |TXT_06|TXT_02|
 |------+------+------+------+------+------+------+------+------+------+
 |      |      |      |      |             |      |      |TXT_07|TXT_03|
 `--------------------------------------------------------------------*/

    QK_BOOT,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  TXT_08,  KC_NO,  TXT_04,  TXT_00,
    KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,  TXT_05,  TXT_01,
    KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,  TXT_06,  TXT_02,
    KC_NO,    KC_NO,  KC_NO,  KC_NO,      KC_NO,      KC_NO,   KC_NO,  TXT_07,  TXT_03
)

};

/*********************     MACRO SECTION     ********************/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
             return false;

        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
             return false;

        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
             return false;

        case FN:
            if (record->event.pressed) {
                layer_on(_FN);
            } else {
                layer_off(_FN);
            }
             return false;

        case CTRL_XX: // CTRL+XX
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_X) SS_TAP(X_X) SS_UP(X_LCTL));
            }
             return false;

        case MAIL_1:  // Write your email address 1
            if (record->event.pressed) {
                SEND_STRING("");
            }
             return false;

        case MAIL_2:  // Write your email address 2
            if (record->event.pressed) {
                SEND_STRING("");
            }
             return false;

        case TXT_00:  // Write a text 0
            if (record->event.pressed) {
                SEND_STRING("");
            }
             return false;

        case TXT_01:  // Write a text 1
            if (record->event.pressed) {
                SEND_STRING("");
            }
             return false;

        case TXT_02:  // Write a text 2
            if (record->event.pressed) {
                SEND_STRING("");
            }
             return false;

        case TXT_03:  // Write a text 3
            if (record->event.pressed) {
                SEND_STRING("");
            }
             return false;

        case TXT_04:  // Write a text 4
            if (record->event.pressed) {
                SEND_STRING("#Blue72Shark#");
            }
             return false;

        case TXT_05:  // Write a text 5
            if (record->event.pressed) {
                SEND_STRING("");
            }
             return false;


        case TXT_06:  // Write a text 6
            if (record->event.pressed) {
                SEND_STRING("");
            }
             return false;

        case TXT_07:  // Write a text 7
            if (record->event.pressed) {
                SEND_STRING("");
            }
             return false;

        case TXT_08:  // Write a text 8
            if (record->event.pressed) {
                SEND_STRING("");
            }
             return false;

    }
    return true;
};

/*********************     TAP DANCE SECTION     ********************/

// 1 TAP Round Parenthesis, 2 TAPs Square Brackets, 3 TAPs Curly Brackets

// OPENING Brackets
void opn_bracket (tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code16(KC_LPRN);
    } else if (state->count == 2) {
        tap_code16(KC_LBRC);
    } else if (state->count == 3) {
        tap_code16(KC_LCBR);
    } else {
        reset_tap_dance (state);
    }
};

// CLOSING Brackets
void cls_bracket (tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code16(KC_RPRN);
    } else if (state->count == 2) {
        tap_code16(KC_RBRC);
    } else if (state->count == 3) {
        tap_code16(KC_RCBR);
    } else {
        reset_tap_dance (state);
    }
};

tap_dance_action_t tap_dance_actions[] = {
 [OPNBR] = ACTION_TAP_DANCE_FN (opn_bracket), // OPENING Brackets
 [CLSBR] = ACTION_TAP_DANCE_FN (cls_bracket), // CLOSING Brackets
 [CPSLK] = ACTION_TAP_DANCE_DOUBLE (KC_LSFT, KC_CAPS) // 1 TAP Left Shift, 2 TAPs Caps Lock
};
