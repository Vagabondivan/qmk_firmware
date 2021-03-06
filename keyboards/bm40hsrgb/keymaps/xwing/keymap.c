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

// Layer Names
enum custom_layers {
    _QWERTY,
    _RETROPIE,
    _PROGRAM,
    _LOWER,
    _RAISE,
    _ADJUST,
    _RESET
};

// Custom keycodes
enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    QWERTY2,
    RETROPIE,
    PROGRAM,
    LOWER,
    RAISE,
    RGB_SLD1,
    RGB_SLD2,
    MNXS,
    HMAP,
    MKNIGHT,
    EURO,
    SPAIN1,
    SPAIN2,
    GRAVEA,
    GRAVEE,
    GRAVEI,
    GRAVEO,
    GRAVEU,
    FISH,
    SIG,
    MAIL
};

// Tap Dance
enum tapdance {
    OPNBR = 0,
    CLSBR,
    CPSLK
};

// LAYOUTS SECTION     **************************************************************
//
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_planck_mit(
/*-----------------------------------------------------------------------------------.
 | ESC  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 | TAB  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 | LSFT |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  UP  | ENTER|
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |PROGRM| LCTL | LALT | GUI\ |LOWER |    Space    | RAISE|   /  | LEFT | DOWN | RGHT |
 `-----------------------------------------------------------------------------------*/
    KC_ESC,     KC_Q,     KC_W,     KC_E,             KC_R,   KC_T,    KC_Y,   KC_U,   KC_I,     KC_O,     KC_P,     KC_BSPC,
    KC_TAB,     KC_A,     KC_S,     KC_D,             KC_F,   KC_G,    KC_H,   KC_J,   KC_K,     KC_L,     KC_SCLN,  KC_QUOTE,
    TD(CPSLK),  KC_Z,     KC_X,     KC_C,             KC_V,   KC_B,    KC_N,   KC_M,   KC_COMM,  KC_DOT,   KC_UP,    KC_ENT,
    PROGRAM,    KC_LCTL,  KC_LALT,  LGUI_T(KC_BSLS),  LOWER,      KC_SPC,      RAISE,  KC_SLSH,  KC_LEFT,  KC_DOWN,  KC_RGHT
),

[_RETROPIE] = LAYOUT_planck_mit(
/*-----------------------------------------------------------------------------------.
 | CANC |      |      |      |      |      |      |      |      |      |   X  |   A  |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 | MENU |      |      |      |      |      |      |      |      |      |   Y  |   B  |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 | SLCT |      | LSld | LTrg | LTmb |      |      | RTmb | RTrg | RSld |  UP  | STRT |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      | FIRE | JUMP | COIN |LOWER |    Space    | RAISE| PLY1 | LEFT | DOWN | RGHT |
 '-----------------------------------------------------------------------------------*/
    KC_ESC,   KC_NO,    KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_RBRC,  KC_ENT,
    KC_TAB,   KC_NO,    KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_LBRC,  KC_QUOT,
    KC_LSFT,  KC_NO,    KC_X,     KC_C,   KC_V,   KC_NO,  KC_NO,  KC_M,   KC_COMM,  KC_DOT,   KC_UP,    KC_RSFT,
    KC_NO,    KC_LCTL,  KC_LALT,  KC_5,   LOWER,      KC_SPC,     RAISE,  KC_1,     KC_LEFT,  KC_DOWN,  KC_RGHT
),

[_PROGRAM] = LAYOUT_planck_mit(
/*-----------------------------------------------------------------------------------.
 |      |PRNSCR|PRNSEL|  è   |      | MAIL |   €  |  ù   |  ì   |  ò   |MSW UP|  DEL |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 | ALT` |  à   | SIG  |      | FISH |      | HOME | PGDN | PGUP | END  |MSW DN|OSL(6)|
 |------+------+------+------+------+------+------+------+------+------+------+------|
 | ALTe |      |      |      |      |      |   ñ  |      |      | MSBL | MS U | MSBR |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |      |      |      |      |             |      |   ¿  | MS L | MS D | MS R |
 `-----------------------------------------------------------------------------------*/
    KC_NO,         SGUI(KC_3),  SGUI(KC_4),  GRAVEE,  KC_NO,    MAIL,   EURO,     GRAVEU,   GRAVEI,   GRAVEO,      KC_WH_U,     KC_DEL,
    LALT(KC_GRV),  GRAVEA,      SIG,         KC_NO,   FISH,     KC_NO,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,      KC_WH_D,     OSL(6),
    LALT(KC_E),    KC_NO,       KC_NO,       KC_NO,   KC_NO,    KC_NO,  SPAIN1,   KC_NO,    KC_WH_D,  KC_MS_BTN1,  KC_MS_UP,    KC_MS_BTN2,
    KC_NO,         KC_NO,       KC_NO,       KC_NO,   KC_TRNS,      KC_TRNS,      KC_TRNS,  SPAIN2,   KC_MS_LEFT,  KC_MS_DOWN,  KC_MS_RIGHT
),

[_LOWER] = LAYOUT_planck_mit(
/*-----------------------------------------------------------------------------------.
 |      |BW-RGB| PREV | PLAY | NEXT | BRID | BRIU | VOL- | MUTE | VOL+ |RGBTOG|      |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |      |      |      |      |      |      |      |      |      |      |      |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 | BRI+ | SAT+ | HUE+ |      |      |      |      |      |      | MNXS | MOD+ | HMAP |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 | BRI- | SAT- | HUE- |      |      | KNIGHTRIDER |      |      | SPD- | MOD- | SPD+ |
 `-----------------------------------------------------------------------------------*/
    KC_NO,    RGB_SLD1,  KC_MPRV,  KC_MPLY,  KC_MNXT,   KC_BRID,  KC_BRIU,  KC_VOLD,  KC_MUTE,  KC_VOLU,  RGB_SLD2,  KC_NO,
    KC_NO,    KC_NO,     KC_NO,    KC_NO,    KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO,
    RGB_VAI,  RGB_SAI,   RGB_HUI,  KC_NO,    KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    MNXS,     RGB_MOD,   HMAP,
    RGB_VAD,  RGB_SAD,   RGB_HUD,  KC_NO,    KC_TRNS,       MKNIGHT,        KC_TRNS,  KC_NO,    RGB_SPD,  RGB_RMOD,  RGB_SPI
),

[_RAISE] = LAYOUT_planck_mit(
/*-----------------------------------------------------------------------------------.
 |   ~  |   %  |   &  |   ?  |   =  |   @  |   $  |   _  |   [  |   ]  |   !  |  DEL |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |   `  |   /  | ([{  |   |  |   0  |   {  |   }  |   1  |   *  |  }]) |   \  |   #  |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |   .  |   6  |   7  |   8  |   9  |   +  |   -  |   2  |   3  |   4  |   5  |   ^  |
 |------+------+------+------+------+-------------+------+------+------+------+------|
 |      |      |      |      |      |             |      |      |      |      |      |
 `-----------------------------------------------------------------------------------*/
    KC_TILD,  KC_PERC,  KC_AMPR,    KC_QUES,  KC_EQL,   KC_AT,    KC_DLR,   KC_UNDS,  KC_LBRC,  KC_RBRC,    KC_EXLM,  KC_DEL,
    KC_GRV,   KC_PSLS,  TD(OPNBR),  KC_PIPE,  KC_0,     KC_LCBR,  KC_RCBR,  KC_1,     KC_PAST,  TD(CLSBR),  KC_BSLS,  KC_HASH,
    KC_PDOT,  KC_6,     KC_7,       KC_8,     KC_9,     KC_PPLS,  KC_PMNS,  KC_2,     KC_3,     KC_4,       KC_5,     KC_CIRC,
    KC_NO,    KC_NO,    KC_NO,      KC_NO,    KC_TRNS,        KC_TRNS,      KC_TRNS,  KC_NO,    KC_NO,      KC_NO,    KC_NO
),

[_ADJUST] = LAYOUT_planck_mit(
/*-----------------------------------------------------------------------------------.
 |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |QWERTY|
 |------+------+------+------+------+-------------+------+------+------+------+------|
 |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |RETPIE|
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |  F11 |  F12 |  F13 |  F14 |  F15 |  F16 |  F17 |  F18 |  F19 |  F20 | NKRO |
 |------+------+------+------+------+-------------+------+------+------+------+------|
 |      |      |      |      |      |             |      |      |      |      |      |
 `-----------------------------------------------------------------------------------*/
    KC_NO,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    QWERTY,
    KC_NO,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  RETROPIE,
    KC_NO,  KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  NK_TOGG,
    KC_NO,  KC_NO,   KC_NO,   KC_NO,   LOWER,   KC_TRNS,      KC_TRNS,     KC_TRNS,  KC_NO,   KC_NO,  KC_NO
),

[_RESET] = LAYOUT_planck_mit(
/*-----------------------------------------------------------------------------------.
 | RSET |      |      |      |      |      |      |      |      |      |      |      |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |      |      |      |      |      |      |      |      |      |      |      |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |      |      |      |      |      |      |      |      |      |      |      |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |      |      |      |      |             |      |      |      |      |      |
 `-----------------------------------------------------------------------------------*/
    RESET,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,
    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_NO,  KC_NO,  KC_NO,  KC_NO
),

};

// MACRO SECTION       **************************************************************
//
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
                rgblight_disable();
                rgb_matrix_enable();
            }
            return false;
            break;
        case RETROPIE:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_RETROPIE);
                rgblight_disable();
                rgb_matrix_enable();
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
        case FISH:  // Write your ASCII Signature
            if (record->event.pressed) {
                SEND_STRING("><))):>");
            }
            return false;
            break;
        case SIG:  // Write Disclaimer
            if (record->event.pressed) {
                SEND_STRING("Your Disclaimer");
            }
            return false;
            break;
        case RGB_SLD1:
            if (record->event.pressed) {
                if (rgblight_is_enabled() == true) {
                    rgblight_disable();
                    rgb_matrix_enable();
                    rgb_matrix_sethsv(0,0,127);
                    rgb_matrix_mode(1);
                } else if (rgb_matrix_get_sat() != 0) {
                    rgblight_disable();
                    rgb_matrix_enable();
                    rgb_matrix_sethsv(0,0,127);
                    rgb_matrix_mode(1);
                } else if (rgb_matrix_get_sat() == 0) {
                    rgblight_disable();
                    rgb_matrix_enable();
                    rgb_matrix_sethsv(86,255,127);
                    rgb_matrix_mode(1);
                }
            }
            return false;
            break;
        case RGB_SLD2:
            if (record->event.pressed) {
                if (rgblight_is_enabled() == true) {
                    rgblight_disable();
                    rgb_matrix_enable();
                    rgb_matrix_sethsv(255,255,255);
                    rgb_matrix_mode(7);
                } else if (rgb_matrix_get_val() != 0) {
                    rgblight_disable();
                    rgb_matrix_enable();
                    rgb_matrix_sethsv(0,0,0);
                } else if (rgb_matrix_get_val() == 0) {
                    rgblight_disable();
                    rgb_matrix_enable();
                    rgb_matrix_sethsv(255,255,255);
                    rgb_matrix_mode(7);
                }
            }
            return false;
            break;
        case HMAP:
            if (record->event.pressed) {
                rgblight_disable();
                rgb_matrix_enable();
                rgb_matrix_sethsv(255,255,255);
                rgb_matrix_mode(5);
            }
            return false;
            break;
        case MNXS:
            if (record->event.pressed) {
                rgb_matrix_sethsv(255,255,255);
                rgb_matrix_mode(7);
            }
            return false;
            break;
        case MKNIGHT:
            if (record->event.pressed) {
                rgb_matrix_disable();
                rgblight_enable();
                rgblight_sethsv(255,255,255);
                rgblight_mode(2);
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

// RGB_MATRIX SECTION  **************************************************************
//

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
    rgb_matrix_disable();
	rgblight_enable();
	rgblight_sethsv(0,255,255);
	rgblight_mode(2);
}

// RGBLIGHT SECTION  ****************************************************************
//
// How long (in milliseconds) to wait between animation steps for each of the "Knight Rider" animations
const uint8_t RGBLED_KNIGHT_INTERVALS[] PROGMEM = {140, 63, 31};

void suspend_power_down_user(void) {
//  rgb_matrix_set_suspend_state(true);
    rgb_matrix_disable();
    rgblight_disable();
}

void suspend_wakeup_init_user(void) {
//  rgb_matrix_set_suspend_state(false);
	rgblight_enable();
	rgblight_sethsv(0,255,255);
	rgblight_mode(2);
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
[0] = {\
    {40,255,120},  {0,0,120},     {0,0,120},     {0,0,120},     {0,0,120},     {0,0,120},     {0,0,120},     {0,0,120},     {0,0,120},     {0,0,120},     {0,0,120},     {150,200,120}, \
    {150,200,120}, {0,0,120},     {0,0,120},     {0,0,120},     {0,0,120},     {0,0,120},     {0,0,120},     {0,0,120},     {0,0,120},     {0,0,120},     {0,0,120},     {150,200,120}, \
    {150,200,120}, {0,0,120},     {0,0,120},     {0,0,120},     {0,0,120},     {0,0,120},     {0,0,120},     {0,0,120},     {0,0,120},     {0,0,120},     {255,255,120}, {40,255,120},\
    {150,200,120}, {150,200,120}, {150,200,120}, {150,200,120}, {150,200,120}, {150,200,120},                {150,200,120}, {150,200,120}, {255,255,120}, {255,255,120}, {255,255,120},\
    {86,255,255},  {86,255,255},  {86,255,255},  {86,255,255},  {86,255,255},  {86,255,255} \
},

[1] = {\
    {200,255,120}, {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {86,240,120},  {255,255,120},\
    {200,255,120}, {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {170,255,233}, {40,255,120},\
    {200,255,120}, {0,0,0},       {86,240,120},  {86,240,120},  {86,240,120},  {0,0,0},       {0,0,0},       {86,240,120},  {86,240,120},  {86,240,120},  {0,0,120},     {200,255,120},\
    {0,0,0},       {0,0,120},     {0,0,120},     {170,255,120}, {0,0,0},       {0,0,0},                      {0,0,0},       {170,255,120}, {0,0,120},     {0,0,120},     {0,0,120},\
    {255,255,255}, {255,255,255}, {255,255,255}, {255,255,255}, {255,255,255}, {255,255,255} \
},

[2] = {\
    {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},\
    {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {200,255,120}, {200,255,120}, {200,255,120}, {200,255,120}, {0,0,0},       {0,0,0},\
    {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {86,240,120},  {170,255,120}, {86,240,120},\
    {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},                      {0,0,0},       {0,0,0},       {170,255,120}, {170,255,120}, {170,255,120},  \
    {170,255,120}, {170,255,120}, {170,255,120}, {170,255,120}, {170,255,120}, {170,255,120} \
},

[3] = {\
    {0,0,0},       {0,0,120},     {200,255,120}, {200,255,120}, {200,255,120}, {0,0,120},     {0,0,120},     {200,255,120}, {200,255,120}, {200,255,120}, {0,0,120},     {0,0,0},\
    {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},\
    {86,240,120},  {86,240,120},  {86,240,120},  {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {86,240,120},  {86,240,120},  {86,240,120},\
    {86,240,120},  {86,240,120},  {86,240,120},  {0,0,0},       {0,0,0},       {0,0,0},                      {0,0,0},       {0,0,0},       {86,240,120},  {86,240,120},  {86,240,120},\
    {0,0,120},     {0,0,120},     {0,0,120},     {0,0,120},     {0,0,120},     {0,0,120} \
},

[4] = {\
    {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},      {0,0,0},        {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},\
    {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {200,55,120},  {0,0,0},       {0,0,0},      {200,55,120},   {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},\
    {0,0,0},       {200,255,120}, {200,205,120}, {200,155,120}, {200,105,120}, {0,0,0},       {0,0,0},      {200,105,120},  {200,155,120}, {200,205,120}, {200,255,120}, {0,0,0},\
    {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},                     {0,0,0},        {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},\
    {200,55,120},  {200,55,120},  {200,55,120},  {200,55,120},  {200,55,120},  {200,55,120} \
},

[5] = {\
    {0,0,0},       {200,255,120}, {200,255,120}, {200,255,120}, {200,255,120}, {200,255,120}, {200,255,120}, {200,255,120}, {200,255,120}, {200,255,120}, {200,255,120}, {0,0,0},\
    {0,0,0},       {200,180,120}, {200,180,120}, {200,180,120}, {200,180,120}, {200,180,120}, {200,180,120}, {200,180,120}, {200,180,120}, {200,180,120}, {200,180,120}, {0,0,0},\
    {0,0,0},       {200,64,120},  {200,64,120},  {200,64,120},  {200,64,120},  {200,64,120},  {200,64,120},  {200,64,120},  {200,64,120},  {200,64,120},  {200,64,120},  {0,0,0},\
    {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},                      {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},\
    {0,0,120},     {0,0,120},     {0,0,120},     {0,0,120},     {0,0,120},     {0,0,120} \
},

[6] = {\
    {255,255,255}, {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},\
    {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},\
    {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},\
    {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},                      {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},\
    {255,255,255}, {255,255,255}, {255,255,255}, {255,255,255}, {255,255,255}, {255,255,255}, \
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
}

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
}

void rgb_matrix_indicators_user(void) {

uint8_t this_led = host_keyboard_leds();
    if (this_led & (1 << USB_LED_CAPS_LOCK)) {
        rgb_matrix_set_color(0, 0x00, 0xFF, 0x00);
    }

  switch (biton32(layer_state)) {
    case 2:
        set_layer_color(2);
    break;
    case 3:
        set_layer_color(3);
    break;
    case 4:
        set_layer_color(4);
    break;
    case 5:
        set_layer_color(5);
    break;
    case 6:
        set_layer_color(6);
    break;

    default:
        switch (biton32(default_layer_state)) {
            case _QWERTY:
                set_underglow_color(0);
            break;
            case _RETROPIE:
                set_layer_color(1);
            break;
        }
    break;
  }
}
