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
#include QMK_KEYBOARD_H
#include "keymap_italian.h"
#include <print.h>

// Layer Names
enum layers {
    _QWERTY = 0,
    _RETPIE,
    _PROGRAM,
    _LOWER,
    _RAISE,
    _ADJUST
};

// Custom keycodes
enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    RETPIE,
    PROGRAM,
    LOWER,
    RAISE,
    ADJUST,
    EURO,
    SPAIN1,
    SPAIN2,
    GRAVEA,
    GRAVEE,
    GRAVEI,
    GRAVEO,
    GRAVEU,
    MAIL
};

// Tap Dance
enum tapdance {
    OPNBR = 0,
    CLSBR,
    CPSLK
};

// LAYOUT SECTION     **************************************************************
//
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_ortho_5x12( \
/*-----------------------------------------------------------------------------------.
 | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   \  |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 | CAPS |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |Enter |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 | PROG | Ctrl | Alt  | GUI  |LOWER |    Space    | RAISE|   /  | Left | Down |Right |
 `-----------------------------------------------------------------------------------*/
 	KC_ESC,     KC_1,     KC_2,     KC_3,     KC_4,   KC_5,    KC_6,    KC_7,   KC_8,     KC_9,     KC_0,     KC_BSPC, \
    KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,   KC_T,    KC_Y,    KC_U,   KC_I,     KC_O,     KC_P,     KC_BSLS, \
    KC_CAPS,    KC_A,     KC_S,     KC_D,     KC_F,   KC_G,    KC_H,    KC_J,   KC_K,     KC_L,     KC_SCLN,  KC_QUOT, \
    KC_LSFT,    KC_Z,     KC_X,     KC_C,     KC_V,   KC_B,    KC_N,    KC_M,   KC_COMM,  KC_DOT,   KC_UP,    KC_ENT, \
    PROGRAM,    KC_LCTL,  KC_LALT,  KC_LGUI,  LOWER,  KC_SPC,  KC_SPC,  RAISE,  KC_SLSH,  KC_LEFT,  KC_DOWN,  KC_RGHT \
),
[_RETPIE] = LAYOUT_ortho_5x12( \
/*-----------------------------------------------------------------------------------.
 | CANC |      |      |      |      |      |      |      |      |      |   Y  |   X  |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 | MENU |      |      |      |      |      |      |      |      |      |   B  |   A  |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |      |      |      |      |      |      |      |      |      |      |      |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 | SLCT |      | LSld | LTrg | LTmb |      |      | RTmb | RTrg | RSld |  UP  | STRT |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      | FIRE | JUMP | COIN |LOWER | PLAYER  ONE | RAISE|      | LEFT | DOWN | RGHT |
 '-----------------------------------------------------------------------------------*/
    KC_ESC,   KC_NO,    KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_LBRC,  KC_RBRC, \
    KC_TAB,   KC_NO,    KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_QUOT,  KC_ENT, \
    KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO, \
    KC_LSFT,  KC_NO,    KC_X,     KC_C,   KC_V,   KC_NO,  KC_NO,  KC_M,   KC_COMM,  KC_DOT,   KC_UP,    KC_RSFT, \
    KC_NO,    KC_LCTL,  KC_LALT,  KC_5,   LOWER,  KC_1,   KC_1,   RAISE,  KC_NO,    KC_LEFT,  KC_DOWN,  KC_RGHT \
),
[_PROGRAM] = LAYOUT_ortho_5x12( \
/*-----------------------------------------------------------------------------------.
 |      |      |      |      |      |      |      |      |      |      |      | Del  |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |      |      |  è   |      | MAIL |   €  |  ù   |  ì   |  ò   |      |NKROTG|
 |------+------+------+------+------+------+------+------+------+------+------+------|
 | ALT` |  à   |      |      |      |      | HOME | PGDN | PGUP |  END |      |      |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 | ALTe |      |      |      |      |      |   ñ  |   ¿  |MSW UP| MSBL | MS U | MSBR |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |      |      |      |LOWER |             | RAISE|MSW DN| MS L | MS D | MS R |
 `-----------------------------------------------------------------------------------*/
    KC_NO,         KC_NO,   KC_NO,  KC_NO,   KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_DEL, \
    KC_NO,         KC_NO,   KC_NO,  GRAVEE,  KC_NO,  MAIL,   EURO,     GRAVEU,   GRAVEI,   GRAVEO,   KC_NO,    NK_TOGG, \
    LALT(KC_GRV),  GRAVEA,  KC_NO,  KC_NO,   KC_NO,  KC_NO,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_NO,    KC_NO, \
    LALT(KC_E),    KC_NO,   KC_NO,  KC_NO,   KC_NO,  KC_NO,  SPAIN1,   SPAIN2,   KC_WH_U,  KC_BTN1,  KC_MS_U,  KC_BTN2, \
    KC_NO,         KC_NO,   KC_NO,  KC_NO,   LOWER,  KC_NO,  KC_NO,    RAISE,    KC_WH_D,  KC_MS_L,  KC_MS_D,  KC_MS_R \
),
[_LOWER] = LAYOUT_ortho_5x12( \
/*-----------------------------------------------------------------------------------.
 |      | BRID | BRIU |PRNSCR|PRNSEL| PREV | PLAY | NEXT | MUTE | VOL- | VOL+ |      |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |      |      |      |      |      |      |      |      |      |      |      |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 | MOD+ |RGB_K |BLBRTG|      |      |      |      |      |      |      |RGB_P | MOD- |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 | BRI+ | SAT+ | BL + |      |      |      |      |      |      |RGBTOG| HUE+ |BLTOGG|
 |------+------+------+------+------+------+------+------+------+------+------+------|
 | BRI- | SAT- | BL - |      |LOWER |             | RAISE|      | SPD- | HUE- | SPD+ |
 `-----------------------------------------------------------------------------------*/
    KC_NO,    KC_BRID,  KC_BRIU,  SGUI(KC_3),  SGUI(KC_4),  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_NO, \
    KC_NO,    KC_NO,    KC_NO,    KC_NO,       KC_NO,       KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO, \
    RGB_MOD,  RGB_M_K,  BL_BRTG,  KC_NO,       KC_NO,       KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    RGB_M_P,  RGB_RMOD, \
    RGB_VAI,  RGB_SAI,  BL_INC,   KC_NO,       KC_NO,       KC_NO,    KC_NO,    KC_NO,    KC_NO,    RGB_TOG,  RGB_HUI,  BL_TOGG, \
    RGB_VAD,  RGB_SAD,  BL_DEC,   KC_NO,       LOWER,       KC_NO,    KC_NO,    RAISE,    KC_NO,    RGB_SPD,  RGB_HUD,  RGB_SPI \
),
[_RAISE] = LAYOUT_ortho_5x12( \
/*-----------------------------------------------------------------------------------.
 |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |      |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |   `  |   %  |   &  |   ?  |   +  |   @  |   $  |   _  |   [  |   ]  |   !  |   #  |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |   ~  |   /  | ([{  |   =  |   0  |   {  |   }  |   1  |   *  |  }]) |   \  |   ^  |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |   6  |   7  |   8  |   9  |   |  |   -  |   2  |   3  |   4  |   5  |      |
 |------+------+------+------+------+-------------+------+------+------+------+------|
 |      |      |      |      |LOWER |             | RAISE|      |      |      |      |
 `-----------------------------------------------------------------------------------*/
    KC_NO,    KC_F1,    KC_F2,      KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,      KC_F10,   KC_NO, \
    KC_GRV,   KC_PERC,  KC_AMPR,    KC_QUES,  KC_PPLS,  KC_AT,    KC_DLR,   KC_UNDS,  KC_LBRC,  KC_RBRC,    KC_EXLM,  KC_DEL, \
    KC_TILD,  KC_PSLS,  TD(OPNBR),  KC_PEQL,  KC_0,     KC_LCBR,  KC_RCBR,  KC_1,     KC_PAST,  TD(CLSBR),  KC_BSLS,  KC_HASH, \
    KC_NO,    KC_6,     KC_7,       KC_8,     KC_9,     KC_PIPE,  KC_PMNS,  KC_2,     KC_3,     KC_4,       KC_5,     KC_CIRC, \
    KC_NO,    KC_NO,    KC_NO,      KC_NO,    LOWER,    KC_NO,    KC_NO,    RAISE,    KC_NO,    KC_NO,      KC_NO,    KC_NO \
),
[_ADJUST] = LAYOUT_ortho_5x12( \
/*-----------------------------------------------------------------------------------.
 | RSET |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |QWERTY|
 |------+------+------+------+------+-------------+------+------+------+------+------|
 | DBUG |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |RETPIE|
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |  F11 |  F12 |  F13 |  F14 |  F15 |  F16 |  F17 |  F18 |  F19 |  F20 |      |
 |------+------+------+------+------+-------------+------+------+------+------+------|
 |      |      |      |      |      |      |      |      |      |      |      |      |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |      |      |      |LOWER |             | RAISE|      |      |      |      |
 `-----------------------------------------------------------------------------------*/
    RESET,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    QWERTY, \
    DEBUG,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  RETPIE, \
    KC_NO,  KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_NO, \
    KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
    KC_NO,  KC_NO,   KC_NO,   KC_NO,   LOWER,   KC_NO,   KC_NO,   RAISE,   KC_NO,   KC_NO,   KC_NO,   KC_NO \
)
};

// MACRO SECTION       **************************************************************
//
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    #ifdef CONSOLE_ENABLE
       uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
    #endif

    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_ADJUST);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case RETPIE:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_RETPIE);
            }
            return false;
            break;
        case PROGRAM:
            if (record->event.pressed) {
                layer_on(_PROGRAM);
            } else {
                layer_off(_PROGRAM);
            }
            return false;
            break;
        case EURO: // EURO Symbol €
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LSFT));
                SEND_STRING(SS_DOWN(X_LALT));
                SEND_STRING(SS_TAP(X_2));
                SEND_STRING(SS_UP(X_LSFT));
                SEND_STRING(SS_UP(X_LALT));
            }
            return false;
            break;
        case SPAIN1: // Spanish ñ
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT));
                SEND_STRING(SS_TAP(X_N));
                SEND_STRING(SS_UP(X_LALT));
                SEND_STRING(SS_TAP(X_N));
            }
            return false;
            break;
        case SPAIN2: // Spanish ¿
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LSFT));
                SEND_STRING(SS_DOWN(X_LALT));
                SEND_STRING(SS_TAP(X_SLSH));
                SEND_STRING(SS_UP(X_LSFT));
                SEND_STRING(SS_UP(X_LALT));
            }
            return false;
            break;
        case GRAVEA: // Italian à
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT));
                SEND_STRING(SS_TAP(X_GRV));
                SEND_STRING(SS_UP(X_LALT));
                SEND_STRING(SS_TAP(X_A));
            }
            return false;
            break;
        case GRAVEE: // Italian è
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT));
                SEND_STRING(SS_TAP(X_GRV));
                SEND_STRING(SS_UP(X_LALT));
                SEND_STRING(SS_TAP(X_E));
            }
            return false;
            break;
        case GRAVEI: // Italian ì
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT));
                SEND_STRING(SS_TAP(X_GRV));
                SEND_STRING(SS_UP(X_LALT));
                SEND_STRING(SS_TAP(X_I));
            }
            return false;
            break;
        case GRAVEO: // Italian ò
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT));
                SEND_STRING(SS_TAP(X_GRV));
                SEND_STRING(SS_UP(X_LALT));
                SEND_STRING(SS_TAP(X_O));
            }
            return false;
            break;
        case GRAVEU: // Italian ù
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT));
                SEND_STRING(SS_TAP(X_GRV));
                SEND_STRING(SS_UP(X_LALT));
                SEND_STRING(SS_TAP(X_U));
            }
            return false;
            break;
        case MAIL:  // Write your email address
            if (record->event.pressed) {
                SEND_STRING("email.address@gmail.com");
            }
            return false;
            break;
    }
    return true;
};

// TAP DANCE SECTION   **************************************************************
//
// 1 TAP Round Parenthesis, 2 TAPs Square Brackets, 3 TAPs Curly Brackets
// OPENING Brackets
void opn_bracket (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code16(KC_LPRN);
    } else if (state->count == 2) {
        tap_code16(KC_LBRC);
    } else if (state->count == 3) {
        tap_code16(KC_LCBR);
    } else {
        reset_tap_dance (state);
    }
}
// CLOSING Brackets
void cls_bracket (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code16(KC_RPRN);
    } else if (state->count == 2) {
        tap_code16(KC_RBRC);
    } else if (state->count == 3) {
        tap_code16(KC_RCBR);
    } else {
        reset_tap_dance (state);
    }
}
qk_tap_dance_action_t tap_dance_actions[] = {
 [OPNBR] = ACTION_TAP_DANCE_FN (opn_bracket), // OPENING Brackets
 [CLSBR] = ACTION_TAP_DANCE_FN (cls_bracket), // CLOSING Brackets
 [CPSLK] = ACTION_TAP_DANCE_DOUBLE (KC_LSFT, KC_CAPS) // 1 TAP Left Shift, 2 TAPs Caps Lock
};
