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

#include QMK_KEYBOARD_H

/* Layer Names */
enum custom_layers {
    _QWERTY = 0,
    _FN,
    _LOWER,
    _RAISE,
    _ADJUST,
    _RESET
};

/* Custom keycodes */
enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    FN,
    LOWER,
    RAISE,
    MNXS,
    HMAP,
    AMOD,
    UPDN,
    EURO,
    SPAIN_1,
    CTRL_XX,
    MAIL_1,
    MAIL_2,
    MAIL_3,
    MAIL_4,
    TEXT_0,
    TEXT_1,
    TEXT_2,
    TEXT_3,
    TEXT_4,
    TEXT_5,
    TEXT_6,
    TEXT_7,
    TEXT_8
};

/* Tap Dance */
enum tapdance {
    OPNBR = 0,
    CLSBR,
    CPSLK
};

/*********************     LAYOUTS SECTION     ********************/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_mit(

 /*----------------------------------------------------------------------------------.
 | Tab  |   q  |   w  |   e  |   r  |   t  |   y  |   u  |   i  |   o  |   p  | Bksp |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 | Esc  |   a  |   s  |   d  |   f  |   g  |   h  |   j  |   k  |   l  | ;  : | '  " |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 | LSFT |   z  |   x  |   c  |   v  |   b  |   n  |   m  | , <  |  . > | /  ? | Entr |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |MO (1)| LCTL | LALT | LGUI |MO (2)|    Space    |MO (3)| Left | Down |  Up  | Rght |
 `----------------------------------------------------------------------------------*/

    KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,   KC_T,  KC_Y,  KC_U,   KC_I,     KC_O,     KC_P,     KC_BSPC,
    KC_ESC,     KC_A,     KC_S,     KC_D,     KC_F,   KC_G,  KC_H,  KC_J,   KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    TD(CPSLK),  KC_Z,     KC_X,     KC_C,     KC_V,   KC_B,  KC_N,  KC_M,   KC_COMM,  KC_DOT,   KC_SLSH,  KC_ENT,
    FN,         KC_LCTL,  KC_LALT,  KC_LGUI,  LOWER,     KC_SPC,    RAISE,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT
),

[_FN] = LAYOUT_planck_mit(

 /*----------------------------------------------------------------------------------.
 |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  | ([{  |  }]) |  Del |
 |------|------+------+------+------+------+------+------+------+------+------+------|
 |   -  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   +  |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 | RSFT |NMLOCK|S_SHOT| CALC |MAIL_1|MAIL_2|MAIL_3|MAIL_4|   €  |   ñ  | \  | |   =  |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      | RCTL | RALT | RGUI |MO (2)|      _      |MO (3)| HOME | PGDN | PGUP | END  |
 `----------------------------------------------------------------------------------*/

   KC_TILD,  KC_EXLM,  KC_AT,       KC_HASH,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR,  KC_ASTR,  TD(OPNBR),  TD(CLSBR),  KC_DEL,
   KC_MINS,  KC_P1,    KC_P2,       KC_P3,    KC_P4,    KC_P5,    KC_P6,    KC_P7,    KC_P8,    KC_P9,      KC_P0,      KC_PLUS,
   KC_RSFT,  KC_NUM,   SGUI(KC_S),  KC_CALC,  MAIL_1,   MAIL_2,   MAIL_3,   MAIL_4,   EURO,     SPAIN_1,    KC_BSLS,    KC_EQL,
   KC_NO,    KC_RCTL,  KC_RALT,     KC_RGUI,  KC_TRNS,      KC_UNDS,        KC_TRNS,  KC_HOME,  KC_PGDN,    KC_PGUP,    KC_END

),

[_LOWER] = LAYOUT_planck_mit(

 /*----------------------------------------------------------------------------------.
 |      |      |      |      |      |      |      |      |      |      |MSW UP|      |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |      |      |      |      |      |      |      |      |MSW L |MSW DN|MSW R |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |CTRL+L|CTRL+W|CTRL+Y|      |      |      |      |      | MSBL | MS U | MSBR |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |CTRL+K|CTRLXX|CTRL+U| TRNS |      _      |MO (4)|      | MS L | MS D | MS R |
 `----------------------------------------------------------------------------------*/

    KC_NO,  KC_NO,       KC_NO,       KC_NO,       KC_NO,    KC_NO,   KC_NO,  KC_NO,    KC_NO,  KC_NO,       KC_WH_U,     KC_NO,
    KC_NO,  KC_NO,       KC_NO,       KC_NO,       KC_NO,    KC_NO,   KC_NO,  KC_NO,    KC_NO,  KC_WH_L,     KC_WH_D,     KC_WH_R,
    KC_NO,  LCTL(KC_L),  LCTL(KC_W),  LCTL(KC_Y),  KC_NO,    KC_NO ,  KC_NO,  KC_NO,    KC_NO,  KC_MS_BTN1,  KC_MS_UP,    KC_MS_BTN2,
    KC_NO,  LCTL(KC_K),  CTRL_XX,     LCTL(KC_U),  KC_TRNS,      KC_UNDS,     KC_TRNS,  KC_NO,  KC_MS_LEFT,  KC_MS_DOWN,  KC_MS_RIGHT
),

[_RAISE] = LAYOUT_planck_mit(

 /*----------------------------------------------------------------------------------.
 |      | BRID | BRIU |PRNSCR|PRNSEL| PREV | PLAY | NEXT | MUTE | VOL- | VOL+ |      |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F 10 |      |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      | F 11 |      |      |      |      |      |      |      |      | F 12 |      |
 |------+------+------+------+------+-------------+------+------+------+------+------|
 |      |      |      |      |MO (4)|      _      |      |      |      |      |      |
 `----------------------------------------------------------------------------------*/

   KC_NO,  KC_BRID,  KC_BRIU,  SGUI(KC_3),  SGUI(KC_4),  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_NO,
   KC_NO,  KC_F1,    KC_F2,    KC_F3,       KC_F4,       KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_NO,
   KC_NO,  KC_F11,   KC_NO,    KC_NO,       KC_NO,       KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_F12,   KC_NO,
   KC_NO,  KC_NO,    KC_NO,    KC_NO,       KC_TRNS,        KC_UNDS,         KC_TRNS,  KC_NO,    KC_NO,    KC_NO,    KC_NO
),

[_ADJUST] = LAYOUT_planck_mit(

 /*----------------------------------------------------------------------------------.
 |      |      |      |      |      |      |      |      |      |      |      |      |
 |------+------+------+------+------+-------------+------+------+------+------+------|
 |      |      | SAT- | SAT+ |      | AMOD | HMAP |      | MOD- | MOD+ |      |      |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |RGBTOG| BRI- | BRI+ |      | UPDN | MNXS |      | SPD- | SPD+ |RGBTOG|      |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |      | HUE- | HUE+ | TRNS |    OSL(5)   | TRNS | MOD- | MOD+ |      |      |
 `----------------------------------------------------------------------------------*/

    KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_NO,  KC_NO,    KC_NO,     KC_NO,    KC_NO,    KC_NO,
    KC_NO,  KC_NO,    RGB_SAD,  RGB_SAI,  KC_NO,    AMOD,   HMAP,   KC_NO,    RGB_RMOD,  RGB_MOD,  KC_NO,    KC_NO,
    KC_NO,  RGB_TOG,  RGB_VAD,  RGB_VAI,  KC_NO,    UPDN,   MNXS,   KC_NO,    RGB_SPD,   RGB_SPI,  RGB_TOG,  KC_NO,
    KC_NO,  KC_NO,    RGB_HUD,  RGB_HUI,  KC_TRNS,     OSL(5),      KC_TRNS,  RGB_RMOD,  RGB_MOD,  KC_NO,    KC_NO
),

[_RESET] = LAYOUT_planck_mit(

 /*----------------------------------------------------------------------------------.
 | RSET |      |      |      |      |      |      |      |TEXT_8|      |TEXT_4|TEXT_0|
 |------+------+------+------+------+------+------+------+------+------+------+------+
 |      |      |      |      |      |      |      |      |      |      |TEXT_5|TEXT_1|
 |------+------+------+------+------+------+------+------+------+------+------+------+
 |      |      |      |      |      |      |      |      |      |      |TEXT_6|TEXT_2|
 |------+------+------+------+------+------+------+------+------+------+------+------+
 |      |      |      |      |      | Q W E R T Y |      |      |      |TEXT_7|TEXT_3|
 `----------------------------------------------------------------------------------*/

    QK_BOOT,KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  TEXT_8,  KC_NO,  TEXT_4,  TEXT_0,
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,  TEXT_5,  TEXT_1,
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,  TEXT_6,  TEXT_2,
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,      QWERTY,     KC_NO,  KC_NO,   KC_NO,  TEXT_7,  TEXT_3
)

};

/*********************     MACRO SECTION     ********************/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
				rgb_matrix_sethsv(160,160,255);
                rgb_matrix_set_speed(150);
                rgb_matrix_mode(2);
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

        case EURO: // EURO Symbol €
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LSFT) SS_DOWN(X_LALT) SS_TAP(X_2) SS_UP(X_LSFT) SS_UP(X_LALT));
            }
            return false;

        case SPAIN_1: // Spanish ñ
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_N) SS_UP(X_LALT) SS_TAP(X_N));
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

        case MAIL_3:  // Write your email address 3
            if (record->event.pressed) {
                SEND_STRING("");
            }
             return false;

        case MAIL_4:  // Write your email address 4
            if (record->event.pressed) {
                SEND_STRING("");
            }
             return false;

        case TEXT_0:  // Write a text 0
            if (record->event.pressed) {
                SEND_STRING("");
            }
             return false;

        case TEXT_1:  // Write a text 1
            if (record->event.pressed) {
                SEND_STRING("");
            }
             return false;

        case TEXT_2:  // Write a text 2
            if (record->event.pressed) {
                SEND_STRING("");
            }
             return false;

        case TEXT_3:  // Write a text 3
            if (record->event.pressed) {
                SEND_STRING("");
            }
             return false;

        case TEXT_4:  // Write a text 4
            if (record->event.pressed) {
                SEND_STRING("");
            }
             return false;

        case TEXT_5:  // Write a text 5
            if (record->event.pressed) {
                SEND_STRING("");
            }
             return false;

        case TEXT_6:  // Write a text 6
            if (record->event.pressed) {
                SEND_STRING("");
            }
             return false;

        case TEXT_7:  // Write a text 7
            if (record->event.pressed) {
                SEND_STRING("");
            }
             return false;

        case TEXT_8:  // Write a text 8
            if (record->event.pressed) {
                SEND_STRING("");
            }
             return false;

        case AMOD:
            if (record->event.pressed) {
				rgb_matrix_sethsv(160,160,255);
                rgb_matrix_set_speed(150);
                rgb_matrix_mode(2);
            }
            return false;

        case UPDN:
            if (record->event.pressed) {
                rgb_matrix_sethsv(170,170,255);
                rgb_matrix_set_speed(20);
                rgb_matrix_mode(3);
            }
            return false;

        case HMAP:
            if (record->event.pressed) {
                rgb_matrix_sethsv(255,255,255);
                rgb_matrix_set_speed(255);
                rgb_matrix_mode(4);
            }
            return false;

        case MNXS:
            if (record->event.pressed) {
                rgb_matrix_sethsv(255,255,255);
                rgb_matrix_set_speed(150);
                rgb_matrix_mode(5);
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

/*********************     RGB MATRIX SECTION     ********************/

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
	rgb_matrix_sethsv(160,160,255);
	rgb_matrix_set_speed(150);
	rgb_matrix_mode(4);
};

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {

[0] = {\
    {0,0,255},     {170,255,255}, {170,255,255}, {170,255,255}, {170,255,255}, {170,255,255}, {170,255,255}, {170,255,255}, {170,255,255}, {170,255,255}, {170,255,255}, {0,0,255},
    {0,0,255},     {170,255,255}, {170,255,255}, {170,255,255}, {170,255,255}, {170,255,255}, {170,255,255}, {170,255,255}, {170,255,255}, {170,255,255}, {170,255,255}, {0,0,255},
    {0,0,255},     {170,255,255}, {170,255,255}, {170,255,255}, {170,255,255}, {170,255,255}, {170,255,255}, {170,255,255}, {170,255,255}, {170,255,255}, {170,255,255}, {0,0,255},
    {0,0,255},     {0,0,255},     {0,0,255},     {0,0,255},     {0,0,255},     {0,0,255},                    {0,0,255},     {0,0,255},     {0,0,255},     {0,0,255},     {0,0,255},
    {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0}
},

[1] = {\
    {0,0,0},       {0,0,255},     {0,0,255},     {0,0,255},     {0,0,255},     {0,0,255},     {0,0,255},     {0,0,255},     {0,0,255},     {0,0,255},     {0,0,255},     {0,0,0},
    {0,0,0},       {150,255,255}, {150,255,255}, {150,255,255}, {150,255,255}, {150,255,255}, {150,255,255}, {150,255,255}, {150,255,255}, {150,255,255}, {150,255,255}, {0,0,0},
    {0,0,0},       {50,255,255},  {50,255,255},  {50,255,255},  {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
    {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},                      {0,0,0},       {150,255,255}, {150,255,255}, {150,255,255}, {150,255,255},
    {90,255,255},  {90,255,255},  {90,255,255},  {90,255,255},  {90,255,255},  {90,255,255}
},

[2] = {\
    {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {170,255,255}, {0,0,0},
    {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {170,255,255}, {0,0,0},
    {0,0,0},       {50,255,120},  {50,255,120},  {50,255,120},  {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,255},     {150,255,255}, {0,0,255},
    {0,0,0},       {50,255,120},  {50,255,120},  {50,255,120},  {0,0,0},       {0,0,0},                      {0,0,0},       {0,0,0},       {150,255,255}, {150,255,255}, {150,255,255},
    {120,255,255}, {120,255,255}, {120,255,255}, {120,255,255}, {120,255,255}, {120,255,255}
},

[3] = {\
    {0,0,0},       {0,0,255},     {0,0,255},     {170,255,255}, {170,255,255}, {0,0,255},     {0,0,255},     {0,0,255},     {170,255,255}, {170,255,255}, {170,255,255}, {0,0,0},
    {0,0,0},       {150,255,255}, {150,255,255}, {150,255,255}, {150,255,255}, {150,255,255}, {150,255,255}, {150,255,255}, {150,255,255}, {150,255,255}, {150,255,255}, {0,0,0},
    {0,0,0},       {150,255,255}, {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {150,255,255}, {0,0,0},
    {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},                      {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
    {150,255,255}, {150,255,255}, {150,255,255}, {150,255,255}, {150,255,255}, {150,255,255}
},

[4] = {\
    {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
    {0,0,0},       {0,0,0},       {0,0,255},     {170,255,255}, {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {170,255,255}, {0,0,255},     {0,0,0},       {0,0,0},
    {0,0,0},       {0,0,255},     {0,0,255},     {170,255,255}, {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {170,255,255}, {0,0,255},     {0,0,255},     {0,0,0},
    {0,0,0},       {0,0,0},       {0,0,255},     {170,255,255}, {0,0,0},       {255,255,255},                {0,0,0},       {170,255,255}, {0,0,255},     {0,0,0},       {0,0,0},
    {185,255,255}, {185,255,255}, {185,255,255}, {185,255,255}, {185,255,255}, {185,255,255}
},

[5] = {\
    {255,255,255}, {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
    {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
    {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
    {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},                      {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
    {255,255,255}, {255,255,255}, {255,255,255}, {255,255,255}, {255,255,255}, {255,255,255}
}

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
};

void set_underglow_color(int layer) {
  for (int i = 47; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
};

bool rgb_matrix_indicators_user(void) {

	// Check the Caps Lock state
	if (host_keyboard_led_state().caps_lock) {
	    rgb_matrix_set_color(24, 0x00, 0xFF, 0x00); // Green for Caps Lock ON
	}

	// Check the Num Lock state
	if (host_keyboard_led_state().num_lock) {
	    rgb_matrix_set_color(11, 0x00, 0xFF, 0x00); // Green for Num Lock ON
	}

	switch (biton32(layer_state)) {

		case 1:
			set_layer_color(1);
      set_underglow_color(0);
		break;

		case 2:
			set_layer_color(2);
      set_underglow_color(0);
		break;

		case 3:
			set_layer_color(3);
      set_underglow_color(0);
		break;

		case 4:
			set_layer_color(4);
      set_underglow_color(0);
		break;

		case 5:
      set_layer_color(5);
      set_underglow_color(0);
		break;

		default:

			switch (biton32(default_layer_state)) {

				case _QWERTY:
					set_underglow_color(0);
				break;

			}
        break;
	}
	return false; // Allow other effects
}
