/* CBM64 - Copyright 2020 Ivano Piacenza
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

// Layer Names declarations
enum layers {
    _QWERTY,
    _GAMING,
    _NUMPAD,
    _LOWER,
    _RAISE,
    _ADJUST,
    _PROGRAM
};

// Custom keycodes declarations
enum keycodes {
    QWERTY = SAFE_RANGE,
    GAMING,
    NUMPAD,
    LOWER,
    RAISE,
    PROGRAM,
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
 * | TAB  |   q  |   w  |   e  |   r  |   t  |   y  |   u  |   i  |   o  |   p  |   @  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  =   |   a  |   s  |   d  |   f  |   g  |   h  |   j  |   k  |   l  |   :  |   ;  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | SHFT |   z  |   x  |   c  |   v  |   b  |   n  |   m  |   ,  |   .  |   /  |  Ent |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | PROG | Ctrl | Alt  |  OS  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_1x2uC (	\
	KC_ESC,     KC_1,     KC_2,     KC_3,     KC_4,   KC_5,  KC_6,  KC_7,   KC_8,     KC_9,     KC_0,     KC_BSPC,\
	KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,   KC_T,  KC_Y,  KC_U,   KC_I,     KC_O,     KC_P,     KC_AT,\
	KC_EQL,     KC_A,     KC_S,     KC_D,     KC_F,   KC_G,  KC_H,  KC_J,   KC_K,     KC_L,     KC_COLN,  KC_SCLN,\
	TD(CPSLK),  KC_Z,     KC_X,     KC_C,     KC_V,   KC_B,  KC_N,  KC_M,   KC_COMM,  KC_DOT,   KC_SLSH,  KC_ENT,\
	PROGRAM,    KC_LCTL,  KC_LGUI,  KC_LALT,  LOWER,    KC_SPC,     RAISE,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT\
),

/* Gaming
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |      |   5  |  F1  |  F3  |  F5  |  F7  |  F9  |  F11 |   [  |   ]  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |      |   W  |      |  F2  |  F4  |  F6  |  F8  |  F10 |  F12 |   '  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   A  |   S  |   D  |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LSft |      |   X  |   C  |   V  |      |      |   M  |   ,  |   .  |  Up  | RSft |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | PROG | LCtl | LAlt | RCtl |Lower |    Space    |Raise | RAlt | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 *///
[_GAMING] = LAYOUT_preonic_1x2uC (	\
	KC_ESC,			KC_1,		KC_NO,      KC_5,		KC_F1,		KC_F3,		KC_F5,		KC_F7,		KC_F9,		KC_F11,     KC_LBRC,	KC_RBRC,\
	KC_TAB,			KC_NO,      KC_W,		KC_NO,      KC_F2,		KC_F4,		KC_F6,		KC_F8,		KC_F10,		KC_F12,     KC_QUOT,  	KC_ENT,\
	KC_NO,  		KC_A,		KC_S,		KC_D,		KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,\
	KC_LSFT,        KC_NO,      KC_X,		KC_C,		KC_V,		KC_NO,      KC_NO,      KC_M,		KC_COMM,	KC_DOT,     KC_UP,		KC_RSFT,\
	PROGRAM,        KC_LCTL,	KC_LALT,	KC_RCTL,    LOWER,      KC_SPC,                 RAISE,      KC_RALT,	KC_LEFT,    KC_DOWN,    KC_RGHT\
),

/* Numpad
 * ,-----------------------------------------------------------------------------------.
 * |  |   |  !   |  "   |  #   |  $   |  %   |  &   |   '  |  (   |   )  |      | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  *   |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   @  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  ~   |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   [  |   ]  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   <  |   >  |   ?  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | PROG | Ctrl | Alt  | Ctrl |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_preonic_1x2uC (	\
    KC_PIPE,   KC_EXLM,  KC_DQUO,  KC_HASH,  KC_DLR,  KC_PERC,  KC_AMPR,  KC_GRV,  KC_LPRN,  KC_RPRN,  KC_NO,    KC_BSPC,\
	KC_ASTR,   KC_Q,     KC_W,     KC_E,     KC_R,    KC_T,     KC_Y,     KC_U,    KC_I,     KC_O,     KC_P,     KC_AT,\
	KC_TILDE,  KC_A,     KC_S,     KC_D,     KC_F,    KC_G,     KC_H,     KC_J,    KC_K,     KC_L,     KC_LBRC,  KC_RBRC,\
	KC_TRNS,   KC_Z,     KC_X,     KC_C,     KC_V,    KC_B,     KC_N,     KC_M,    KC_LT,    KC_GT,    KC_QUES,  KC_TRNS,\
	PROGRAM,   KC_LCTL,  KC_LALT,  KC_LGUI,  LOWER,        KC_SPC,        RAISE,   KC_LEFT,	 KC_DOWN,  KC_UP,    KC_RGHT\
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
 * |      |      |      |      |Lower |             |Raise | HOME | PGDN | PGUP | END  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_1x2uC (	\
    KC_NO,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,    KC_F9,    KC_F10,   KC_NO,\
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,\
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,\
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,\
    KC_NO,	KC_NO,	KC_NO,  KC_NO,  LOWER,      KC_NO,      RAISE,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END\
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | BR - | BR + | WBAK | WFWD | BL - | BL + | Prev | Play | Next | Mute | Vol- | Vol+ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   \  |      |      |      |      |      |      |      |      |      |      |   |  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | WSTP | WREF | WSCH | PAU  |  +   |  -   |   _  |   =  |PRNSCR| Mute | Vol+ | Play |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | WBAK | WHOM | WFWD | SLCK |Lower |             |Raise |PRNSEL| Prev | Vol- | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_1x2uC (	    \
	KC_BRID,	KC_BRIU,	KC_WBAK,	KC_WFWD,	BL_DEC,		BL_INC,		KC_MPRV,	KC_MPLY,	KC_MNXT,        KC_MUTE,	KC_VOLD,	KC_VOLU,\
    KC_BSLS,  	KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,          KC_NO,      KC_NO,      KC_PIPE,\
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,          KC_NO,      KC_NO,      KC_NO,\
    KC_WSTP,    KC_WREF,	KC_WSCH,	KC_PAUS,    KC_PPLS,	KC_PMNS,	KC_UNDS,	KC_PEQL,	SGUI(KC_4),     KC_MUTE,    KC_VOLU,    KC_MPLY,\
    KC_WBAK,    KC_WHOM,	KC_WFWD,	KC_SLCK,    LOWER,      KC_NO,                  RAISE,      SGUI(KC_3),     KC_MPRV,    KC_VOLD,    KC_MNXT\
),

/* Program
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |      | MAIL |      |   €  |      |      |      |      |      |      | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   *  |      |      |  è   |      |      |      |  ù   |  ì   |  ò   |      |ALT ` |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   à  |      |      |      |      |      |      |      |      |      |NKROTG|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |   ñ  |   ¿  |      | MSBL | MS U | MSBR |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |CTRL+L|   -  |   +  |Lower |   MENDL'S   |Raise |      | MS L | MS D | MS R |
 * `-----------------------------------------------------------------------------------'
 */
[_PROGRAM] = LAYOUT_preonic_1x2uC (	    \
	KC_TILD,  KC_NO,       MAIL,     KC_NO,    EURO,   KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_DEL,\
    KC_ASTR,  KC_NO,       KC_NO,    ACCENTE,  KC_NO,  KC_NO,  KC_NO,    ACCENTU,  ACCENTI,  ACCENTO,  KC_NO,    LALT(KC_GRV),\
    CK_TOGG,  ACCENTA,     KC_NO,    KC_NO,    KC_NO,  KC_NO,  KC_NO,	 KC_NO,    KC_NO,    KC_NO,    KC_NO,    NK_TOGG,\
    KC_NO,    KC_NO,  	   KC_NO,    KC_NO,    KC_NO,  KC_NO,  SPAIN1,   SPAIN2,   KC_NO,    KC_BTN1,  KC_MS_U,  KC_BTN2,\
    KC_NO,    LCTL(KC_L),  KC_MINS,  KC_PLUS,  LOWER,       CBM,         RAISE,    KC_NO,    KC_MS_L,  KC_MS_D,  KC_MS_R\
),

/* Adjust
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Qwerty|Gaming|Numpad|      |      |      |      |WipeEP|Debug |Reset |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |Lower |             |Raise |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_1x2uC (	\
    KC_NO,    KC_NO,    KC_NO,      KC_NO,      KC_NO,    KC_NO,        KC_NO,      KC_NO,    KC_NO,    KC_NO,      KC_NO,      KC_NO,\
    KC_NO,    KC_NO,    KC_NO,      KC_NO,      KC_NO,    KC_NO,        KC_NO,      KC_NO,    KC_NO,    KC_NO,      KC_NO,      KC_NO,\
    KC_NO,    KC_NO,    KC_NO,      KC_NO,      KC_NO,    KC_NO,        KC_NO,      KC_NO,    KC_NO,    KC_NO,      KC_NO,      KC_NO,\
    KC_NO,    QWERTY,   GAMING,     NUMPAD,     KC_NO,    KC_NO,        KC_NO,      KC_NO,    EEP_RST,	DEBUG,      RESET,      KC_NO,\
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
        case NUMPAD:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_NUMPAD);
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
        case PROGRAM:
            if (record->event.pressed) {
                layer_on(_PROGRAM);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_PROGRAM);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case DBLOO:  // Double Zero for NUMPAD
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
    case _PROGRAM:
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
