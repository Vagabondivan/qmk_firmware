/* CBM64 - Copyright 2020 Ivano Piacenza
 *
 * This FN is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This FN is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this FN.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

// Layer Names declarations
enum layers {
    _QWERTY,
    _CBM64,
    _GAMING,
    _LOWER,
    _RAISE,
    _ADJUST,
    _FN
};

// Custom keycodes declarations
enum keycodes {
    QWERTY = SAFE_RANGE,
	CBM64,
	GAMING,
    LOWER,
    RAISE,
    ADJUST,
    FN,
    DBLOO,
    MAIL,
    EURO,
    SPAIN1,
    SPAIN2,
    ACCENTA,
    ACCENTE,
    ACCENTI,
    ACCENTO,
    ACCENTU,
    CBM
};

// Tap Dance Declarations
enum {
    OPNBR = 0,
    CLSBR,
    CPSLK
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   q  |   w  |   e  |   r  |   t  |   y  |   u  |   i  |   o  |   p  |   @  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  =   |   a  |   s  |   d  |   f  |   g  |   h  |   j  |   k  |   l  |   :  |   ;  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shft |   z  |   x  |   c  |   v  |   b  |   n  |   m  |   ,  |   .  |   /  |  Ent |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  Fn  | Ctrl | Alt  |  Os  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_1x2uC (	\
	KC_ESC,     KC_P1,    KC_P2,    KC_P3,    KC_P4,  KC_P5,  KC_P6,  KC_P7,  KC_P8,    KC_P9,    KC_P0,    KC_BSPC,\
	KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,     KC_O,     KC_P,     KC_AT,\
	KC_PEQL,    KC_A,     KC_S,     KC_D,     KC_F,   KC_G,   KC_H,   KC_J,   KC_K,     KC_L,     KC_COLN,  KC_SCLN,\
	TD(CPSLK),  KC_Z,     KC_X,     KC_C,     KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,  KC_DOT,   KC_SLSH,  KC_ENT,\
	FN,         KC_LCTL,  KC_LGUI,  KC_LALT,  LOWER,      KC_SPC,     RAISE,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT\
),

/* Gaming
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |      |      |      |      |      |      |      |      |      |      | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |      |      |      |      |      |      |      |      |      |      |   @  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  =   |      |      |      |      |      |      |      |      |      |      |   ;  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shft |      |      |      |      |      |      |      |      |      |      |  Ent |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  Fn  | Ctrl | Alt  |  Os  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_GAMING] = LAYOUT_preonic_1x2uC (	\
    KC_ESC,     KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_NO,  KC_BSPC,\
    KC_TAB,     KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_NO,  KC_AT,\
    KC_PEQL,    KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_NO,  KC_SCLN,\
    TD(CPSLK),  KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_NO,  KC_ENT,\
	FN,         KC_LCTL,  KC_LGUI,  KC_LALT,  LOWER,     KC_SPC,      RAISE,  KC_LEFT,  KC_DOWN,  KC_UP,  KC_RGHT\
),

/* CBM64
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  *   |   q  |   w  |   e  |   r  |   t  |   y  |   u  |   i  |   o  |   p  |   @  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  =   |   a  |   s  |   d  |   f  |   g  |   h  |   j  |   k  |   l  |   :  |   ;  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shft |   z  |   x  |   c  |   v  |   b  |   n  |   m  |   ,  |   .  |   /  |  Ent |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |INS/DL|CLR/HM|   -  |   +  |SH/LCK|    Space    |RUN/ST| Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_CBM64] LAYOUT_preonic_1x2uC (	\
	ADJUST,   KC_P1,    KC_P2,    KC_P3,    KC_P4,    KC_P5,  KC_P6,  KC_P7,   KC_P8,    KC_P9,    KC_P0,    KC_BSPC,\
	KC_ASTR,  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,   KC_Y,   KC_U,    KC_I,     KC_O,     KC_P,     KC_AT,\
	KC_PEQL,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,   KC_H,   KC_J,    KC_K,     KC_L,     KC_COLN,  KC_SCLN,\
	KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,   KC_N,   KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_ENT,\
	FN,       KC_HOME,  KC_PLUS,  KC_MINS,  KC_CAPS,      KC_SPC,     KC_ESC,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT\
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |Lower |             |Raise |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_1x2uC (	\
    KC_NO,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10,  KC_NO,\
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,\
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,\
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,\
    KC_NO,	KC_NO,	KC_NO,  KC_NO,  LOWER,      KC_NO,      RAISE,  KC_NO,  KC_NO,  KC_NO,   KC_NO,\
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      | BR - | BR + | WBAK | WFWD | Prev | Play | Next | Mute | Vol- | Vol+ |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | WSTP | WREF | WSCH | PAU  |  +   |  -   |   _  |   =  |PRNSCR| Mute | Vol+ | Play |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | WBAK | WHOM | WFWD | SLCK |Lower |             |Raise |PRNSEL| Prev | Vol- | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_1x2uC (	    \
	KC_NO,    KC_BRID,  KC_BRIU,  KC_WBAK,  KC_WFWD,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,     KC_VOLD,  KC_VOLU,  KC_NO,\
    KC_BSLS,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,       KC_NO,    KC_NO,    KC_PIPE,\
    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,       KC_NO,    KC_NO,    KC_NO,\
    KC_WSTP,  KC_WREF,	KC_WSCH,  KC_PAUS,  KC_PPLS,  KC_PMNS,  KC_UNDS,  KC_PEQL,  SGUI(KC_4),  KC_MUTE,  KC_VOLU,  KC_MPLY,\
    KC_WBAK,  KC_WHOM,	KC_WFWD,  KC_SLCK,  LOWER,         KC_NO,         RAISE,    SGUI(KC_3),  KC_MPRV,  KC_VOLD,  KC_MNXT\
),

/* Fn
 * ,-----------------------------------------------------------------------------------.
 * |CKTOGG|  !   |  "   |  #   |  $   |  %   |  &   |   '  |  (   |   )  |   |  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   *  |      |      |  è   |      |      |      |  ù   |  ì   |  ò   |      | MAIL |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   ~  |   à  |      |      |      |      |      |      |      |      |   [  |   ]  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |   ñ  |   ¿  |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |CTRL+L|   -  |   +  |Lower |   MENDL'S   |Raise | HOME | PGDN | PGUP | END  |
 * `-----------------------------------------------------------------------------------'
 */
[_FN] = LAYOUT_preonic_1x2uC (	    \
	CK_TOGG,  KC_EXLM,     KC_DQUO,  KC_HASH,  KC_DLR,  KC_PERC,  KC_AMPR,  KC_GRV,   KC_LPRN,  KC_RPRN,  KC_PIPE,  KC_DEL,\
    KC_ASTR,  KC_NO,       KC_NO,    ACCENTE,  KC_NO,   KC_NO,    KC_NO,    ACCENTU,  ACCENTI,  ACCENTO,  KC_NO,    MAIL,\
    KC_TILD,  ACCENTA,     KC_NO,    KC_NO,    KC_NO,   KC_NO,    KC_NO,	KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,\
    KC_NO,    KC_NO,  	   KC_NO,    KC_NO,    KC_NO,   KC_NO,    SPAIN1,   SPAIN2,   KC_NO,    KC_NO,    KC_NO,    KC_NO,\
    KC_NO,    LCTL(KC_L),  KC_MINS,  KC_PLUS,  LOWER,         CBM,          RAISE,    KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END\
),

/* Adjust
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Qwerty|Gaming|CBM64|      |      |      |      |WipeEP|Debug |Reset |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |Lower |             |Raise |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_1x2uC (	\
    KC_NO,    KC_NO,    KC_NO,      KC_NO,      KC_NO,    KC_NO,        KC_NO,      KC_NO,    KC_NO,    KC_NO,      KC_NO,      KC_NO,\
    KC_NO,    KC_NO,    KC_NO,      KC_NO,      KC_NO,    KC_NO,        KC_NO,      KC_NO,    KC_NO,    KC_NO,      KC_NO,      KC_NO,\
    KC_NO,    KC_NO,    KC_NO,      KC_NO,      KC_NO,    KC_NO,        KC_NO,      KC_NO,    KC_NO,    KC_NO,      KC_NO,      KC_NO,\
    KC_NO,    QWERTY,   GAMING,     CBM64,     KC_NO,    KC_NO,        KC_NO,      KC_NO,    EEP_RST,	DEBUG,      RESET,      KC_NO,\
    KC_NO,    KC_NO,    KC_NO,      KC_NO,      LOWER,    KC_NO,                    RAISE,    KC_NO,    KC_NO,      KC_NO,      KC_NO\
)

};

// MACRO SECTION ***************************************************************

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case GAMING:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_GAMING);
            }
            return false;
            break;
        case CBM64:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_CBM64);
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
        case FN:
            if (record->event.pressed) {
                layer_on(_FN);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_FN);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case DBLOO:  // Double Zero for CBM64
            if (record->event.pressed) {
                SEND_STRING("00");
            }
            return false;
            break;
        case MAIL:  // Write your email address
            if (record->event.pressed) {
                SEND_STRING("mail.ivanp@gmail.com");
            }
            return false;
            break;
        case CBM: // The Grand Brudapest Hotel
            if (record->event.pressed) {
                SEND_STRING("LOAD");
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
        case ACCENTA: // Italian à
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT));
                SEND_STRING(SS_TAP(X_GRV));
                SEND_STRING(SS_UP(X_LALT));
                SEND_STRING(SS_TAP(X_A));
            }
            return false;
            break;
        case ACCENTE: // Italian è
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT));
                SEND_STRING(SS_TAP(X_GRV));
                SEND_STRING(SS_UP(X_LALT));
                SEND_STRING(SS_TAP(X_E));
            }
            return false;
            break;
        case ACCENTI: // Italian ì
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT));
                SEND_STRING(SS_TAP(X_GRV));
                SEND_STRING(SS_UP(X_LALT));
                SEND_STRING(SS_TAP(X_I));
            }
            return false;
            break;
        case ACCENTO: // Italian ò
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT));
                SEND_STRING(SS_TAP(X_GRV));
                SEND_STRING(SS_UP(X_LALT));
                SEND_STRING(SS_TAP(X_O));
            }
            return false;
            break;
        case ACCENTU: // Italian ù
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT));
                SEND_STRING(SS_TAP(X_GRV));
                SEND_STRING(SS_UP(X_LALT));
                SEND_STRING(SS_TAP(X_U));
            }
            return false;
            break;
    }
    return true;
};


// ENCODER SECTION ***************************************************************

void knob_code(uint16_t keycode) {
  uint16_t held_keycode_timer = timer_read();
  register_code(keycode);
  while (timer_elapsed(held_keycode_timer) < MEDIA_KEY_DELAY) {
      // no-op
  }
  unregister_code(keycode);
}

void encoder_update_user(uint8_t index, bool clockwise) {

    switch (biton32(layer_state)) {

    case _QWERTY:
        if (clockwise) {
          tap_code(KC_MS_WH_UP);
          break;
        } else {
          tap_code(KC_MS_WH_DOWN);
          break;
        }
    case _LOWER:
        if (clockwise) {
          tap_code(KC_DOWN);
          break;
        } else {
          tap_code(KC_UP);
          break;
        }
    case _RAISE:
        if (clockwise) {
          knob_code(KC_VOLU);
          break;
        } else {
          knob_code(KC_VOLD);
          break;
        }
    case _FN:
        if (clockwise) {
          tap_code(KC_RIGHT);
          break;
        } else {
          tap_code(KC_LEFT);
          break;
        }
    case _ADJUST:
        if (clockwise) {
          tap_code(KC_PGUP);
          break;
        } else {
          tap_code(KC_PGDN);
          break;
        }
    }
}
// TAP DANCE SECTION ***************************************************************

// OPENING Brackets
// 1 TAP Round Parenthesis, 2 TAPs Square Brackets, 3 TAPs Curly Brackets
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
// 1 TAP Round Parenthesis, 2 TAPs Square Brackets, 3 TAPs Curly Brackets
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
 [CPSLK] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS) // 1 TAP Left Shift, 2 TAPs Caps Lock
};
