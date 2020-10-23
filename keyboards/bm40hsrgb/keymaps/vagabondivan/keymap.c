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
    COL1,
    COL2,
    COL3,
    MNXS,
    HMAP,
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

// LAYOUTS SECTION     **************************************************************
//
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_planck_mit(
/*-----------------------------------------------------------------------------------.
 | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |Enter |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 | PROG | Ctrl | Alt  | GUI  |LOWER |    Space    | RAISE|   /  | Left | Down |Right |
 `-----------------------------------------------------------------------------------*/
    KC_ESC,     KC_Q,     KC_W,     KC_E,     KC_R,   KC_T,    KC_Y,  KC_U,   KC_I,     KC_O,     KC_P,     KC_BSPC,
    KC_TAB,     KC_A,     KC_S,     KC_D,     KC_F,   KC_G,    KC_H,  KC_J,   KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    TD(CPSLK),  KC_Z,     KC_X,     KC_C,     KC_V,   KC_B,    KC_N,  KC_M,   KC_COMM,  KC_DOT,   KC_UP,    KC_ENT,
    PROGRAM,    KC_LCTL,  KC_LALT,  KC_LGUI,  LOWER,  KC_SPC,         RAISE,  KC_SLSH,  KC_LEFT,  KC_DOWN,  KC_RGHT
),
[_RETPIE] = LAYOUT_planck_mit(
/*-----------------------------------------------------------------------------------.
 | CANC |      |      |      |      |      |      |      |      |      |   Y  |   X  |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 | MENU |      |      |      |      |      |      |      |      |      |   B  |   A  |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 | SLCT |      | LSld | LTrg | LTmb |      |      | RTmb | RTrg | RSld |  UP  | STRT |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      | FIRE | JUMP | COIN |LOWER | PLAYER  ONE | RAISE|      | LEFT | DOWN | RGHT |
 '-----------------------------------------------------------------------------------*/
    KC_ESC,   KC_NO,    KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_LBRC,  KC_RBRC,
    KC_TAB,   KC_NO,    KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_QUOT,  KC_ENT,
    KC_LSFT,  KC_NO,    KC_X,     KC_C,   KC_V,   KC_NO,  KC_NO,  KC_M,   KC_COMM,  KC_DOT,   KC_UP,    KC_RSFT,
    KC_NO,    KC_LCTL,  KC_LALT,  KC_5,   LOWER,  KC_1,           RAISE,  KC_NO,    KC_LEFT,  KC_DOWN,  KC_RGHT
),
[_PROGRAM] = LAYOUT_planck_mit(
/*-----------------------------------------------------------------------------------.
 |      |      |      |  è   |      | MAIL |   €  |  ù   |  ì   |  ò   |      | Del  |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 | ALT` |  à   |      |      |      |      | HOME | PGDN | PGUP |  END |      |NKROTG|
 |------+------+------+------+------+------+------+------+------+------+------+------|
 | ALTe |      |      |      |      |      |   ñ  |   ¿  |MSW UP| MSBL | MS U | MSBR |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |      |      |      |LOWER |             | RAISE|MSW DN| MS L | MS D | MS R |
 `-----------------------------------------------------------------------------------*/
    KC_NO,         KC_NO,   KC_NO,  GRAVEE,  KC_NO,  MAIL,   EURO,     GRAVEU,   GRAVEI,   GRAVEO,   KC_NO,    KC_DEL,
    LALT(KC_GRV),  GRAVEA,  KC_NO,  KC_NO,   KC_NO,  KC_NO,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_NO,    NK_TOGG,
    LALT(KC_E),    KC_NO,   KC_NO,  KC_NO,   KC_NO,  KC_NO,  SPAIN1,   SPAIN2,   KC_WH_U,  KC_BTN1,  KC_MS_U,  KC_BTN2,
    KC_NO,         KC_NO,   KC_NO,  KC_NO,   LOWER,  KC_NO,            RAISE,    KC_WH_D,  KC_MS_L,  KC_MS_D,  KC_MS_R
),
[_LOWER] = LAYOUT_planck_mit(
/*-----------------------------------------------------------------------------------.
 |      | BRID | BRIU |PRNSCR|PRNSEL| PREV | PLAY | NEXT | MUTE | VOL- | VOL+ |      |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 | MOD+ | MNXS |      |      |      |      |      |      |      |      | HMAP | MOD- |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 | BRI+ | SAT+ |      |      |      |      |      |      |      | MTRX | HUE+ | RGBL |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 | BRI- | SAT- |      |      |LOWER |             | RAISE|      | SPD- | HUE- | SPD+ |
 `-----------------------------------------------------------------------------------*/
    KC_NO,    KC_BRID,  KC_BRIU,  SGUI(KC_3),  SGUI(KC_4),  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_NO,
    RGB_MOD,  MNXS,     KC_NO,    KC_NO,       KC_NO,       KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    HMAP,     RGB_RMOD,
    RGB_VAI,  RGB_SAI,  KC_NO,    KC_NO,       KC_NO,       KC_NO,    KC_NO,    KC_NO,    KC_NO,    COL1,     RGB_HUI,  COL2,
    RGB_VAD,  RGB_SAD,  KC_NO,    KC_NO,       LOWER,       KC_NO,              RAISE,    KC_NO,    RGB_SPD,  RGB_HUD,  RGB_SPI
),
[_RAISE] = LAYOUT_planck_mit(
/*-----------------------------------------------------------------------------------.
 |   `  |   %  |   &  |   ?  |   +  |   @  |   $  |   _  |   [  |   ]  |   !  |  DEL |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |   ~  |   /  | ([{  |   =  |   0  |   {  |   }  |   1  |   *  |  }]) |   \  |   #  |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |   6  |   7  |   8  |   9  |   |  |   -  |   2  |   3  |   4  |   5  |   ^  |
 |------+------+------+------+------+-------------+------+------+------+------+------|
 |      |      |      |      |LOWER |             | RAISE|      |      |      |      |
 `-----------------------------------------------------------------------------------*/
    KC_GRV,   KC_PERC,  KC_AMPR,    KC_QUES,  KC_PPLS,  KC_AT,    KC_DLR,   KC_UNDS,  KC_LBRC,  KC_RBRC,    KC_EXLM,  KC_DEL,
    KC_TILD,  KC_PSLS,  TD(OPNBR),  KC_PEQL,  KC_0,     KC_LCBR,  KC_RCBR,  KC_1,     KC_PAST,  TD(CLSBR),  KC_BSLS,  KC_HASH,
    KC_NO,    KC_6,     KC_7,       KC_8,     KC_9,     KC_PIPE,  KC_PMNS,  KC_2,     KC_3,     KC_4,       KC_5,     KC_CIRC,
    KC_NO,    KC_NO,    KC_NO,      KC_NO,    LOWER,    KC_NO,              RAISE,    KC_NO,    KC_NO,      KC_NO,    KC_NO
),
[_ADJUST] = LAYOUT_planck_mit(
/*-----------------------------------------------------------------------------------.
 | RSET |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |QWERTY|
 |------+------+------+------+------+-------------+------+------+------+------+------|
 | DBUG |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |RETPIE|
 |------+------+------+------+------+------+------+------+------+------+------+------|
 | BLON |  F11 |  F12 |  F13 |  F14 |  F15 |  F16 |  F17 |  F18 |  F19 |  F20 |RGBOFF|
 |------+------+------+------+------+-------------+------+------+------+------+------|
 |      |      |      |      |LOWER |             | RAISE|      |      |      |      |
 `-----------------------------------------------------------------------------------*/
    RESET,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    QWERTY,
    DEBUG,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  RETPIE,
    KC_NO,  KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  COL3,
    KC_NO,  KC_NO,   KC_NO,   KC_NO,   LOWER,   KC_NO,            RAISE,   KC_NO,   KC_NO,   KC_NO,   KC_NO
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
                rgblight_disable();
                rgb_matrix_enable();
                rgb_matrix_sethsv(0,0,0);
                rgb_matrix_mode(1);
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
                    rgb_matrix_disable();
                    rgblight_enable();
            } else {
                layer_off(_ADJUST);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case RETPIE:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_RETPIE);
                rgb_matrix_disable();
                rgblight_enable();
                rgblight_sethsv(255,255,255);
                rgblight_mode(2);
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
        case COL1:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
                rgblight_disable();
                rgb_matrix_enable();
                rgb_matrix_sethsv(0,0,127);
                rgb_matrix_mode(1);
            }
            return false;
            break;
        case COL2:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
                rgb_matrix_disable();
                rgblight_enable();
                rgblight_sethsv(255,255,255);
                rgblight_mode(2);
            }
            return false;
            break;
        case COL3:
            if (record->event.pressed) {
                rgblight_disable();
                rgb_matrix_sethsv(0,0,0);
                rgb_matrix_disable();
            }
            return false;
            break;
        case MNXS:
            if (record->event.pressed) {
                rgblight_disable();
                rgb_matrix_enable();
                rgb_matrix_sethsv(255,255,255);
                rgb_matrix_mode(7);
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

// RGB_MATRIX SECTION  **************************************************************
//

// Light Up LEDs when connecting to USB
void matrix_init_user(void) {
    rgb_matrix_disable();
	rgblight_enable();
	rgblight_sethsv(0,255,255);
	rgblight_mode(2);
};

void rgb_matrix_indicators_kb(void) {

    #ifdef RGB_MATRIX_ENABLE

    uint8_t this_led = host_keyboard_leds();
        if (this_led & (1 << USB_LED_CAPS_LOCK)) {
            rgb_matrix_set_color(0, 0x00, 0xFF, 0x00);
        }

    switch (biton32(layer_state)) {
        case _LOWER:
            rgb_matrix_set_color(1, RGB_PINK);
            rgb_matrix_set_color(2, RGB_PINK);
            rgb_matrix_set_color(3, RGB_TEAL);
            rgb_matrix_set_color(4, RGB_TEAL);
            rgb_matrix_set_color(5, RGB_PINK);
            rgb_matrix_set_color(6, RGB_PINK);
            rgb_matrix_set_color(7, RGB_PINK);
            rgb_matrix_set_color(8, RGB_TEAL);
            rgb_matrix_set_color(9, RGB_TEAL);
            rgb_matrix_set_color(10, RGB_TEAL);
            rgb_matrix_set_color(12, RGB_PURPLE);
            rgb_matrix_set_color(23, RGB_PURPLE);
            rgb_matrix_set_color(24, RGB_GREEN);
            rgb_matrix_set_color(25, RGB_GREEN);
            rgb_matrix_set_color(33, RGB_BLUE);
            rgb_matrix_set_color(34, RGB_GREEN);
            rgb_matrix_set_color(35, RGB_BLUE);
            rgb_matrix_set_color(36, RGB_GREEN);
            rgb_matrix_set_color(37, RGB_GREEN);
            rgb_matrix_set_color(44, RGB_GREEN);
            rgb_matrix_set_color(45, RGB_GREEN);
            rgb_matrix_set_color(46, RGB_GREEN);
            rgb_matrix_set_color(47, RGB_RED);
            rgb_matrix_set_color(48, RGB_RED);
            rgb_matrix_set_color(49, RGB_RED);
            rgb_matrix_set_color(50, RGB_RED);
            rgb_matrix_set_color(51, RGB_RED);
            rgb_matrix_set_color(52, RGB_RED);
        break;
        case _RAISE:
            rgb_matrix_set_color(16, RGB_PURPLE);
            rgb_matrix_set_color(19, RGB_PURPLE);
            rgb_matrix_set_color(25, RGB_PURPLE);
            rgb_matrix_set_color(26, RGB_PURPLE);
            rgb_matrix_set_color(27, RGB_PURPLE);
            rgb_matrix_set_color(28, RGB_PURPLE);
            rgb_matrix_set_color(31, RGB_PURPLE);
            rgb_matrix_set_color(32, RGB_PURPLE);
            rgb_matrix_set_color(33, RGB_PURPLE);
            rgb_matrix_set_color(34, RGB_PURPLE);
            rgb_matrix_set_color(47, RGB_RED);
            rgb_matrix_set_color(48, RGB_RED);
            rgb_matrix_set_color(49, RGB_RED);
            rgb_matrix_set_color(50, RGB_RED);
            rgb_matrix_set_color(51, RGB_RED);
            rgb_matrix_set_color(52, RGB_RED);
        break;
        case _ADJUST:
            rgb_matrix_set_color(0, RGB_RED);
            rgb_matrix_set_color(11, RGB_PURPLE);
            rgb_matrix_set_color(23, RGB_PINK);
            rgb_matrix_set_color(47, RGB_RED);
            rgb_matrix_set_color(48, RGB_RED);
            rgb_matrix_set_color(49, RGB_RED);
            rgb_matrix_set_color(50, RGB_RED);
            rgb_matrix_set_color(51, RGB_RED);
            rgb_matrix_set_color(52, RGB_RED);
        break;
        case _PROGRAM:
            rgb_matrix_set_color(18, RGB_PURPLE);
            rgb_matrix_set_color(19, RGB_PURPLE);
            rgb_matrix_set_color(20, RGB_PURPLE);
            rgb_matrix_set_color(21, RGB_PURPLE);
            rgb_matrix_set_color(32, RGB_BLUE);
            rgb_matrix_set_color(33, RGB_YELLOW);
            rgb_matrix_set_color(34, RGB_WHITE);
            rgb_matrix_set_color(35, RGB_YELLOW);
            rgb_matrix_set_color(43, RGB_BLUE);
            rgb_matrix_set_color(44, RGB_WHITE);
            rgb_matrix_set_color(45, RGB_WHITE);
            rgb_matrix_set_color(46, RGB_WHITE);
            rgb_matrix_set_color(47, RGB_RED);
            rgb_matrix_set_color(48, RGB_RED);
            rgb_matrix_set_color(49, RGB_RED);
            rgb_matrix_set_color(50, RGB_RED);
            rgb_matrix_set_color(51, RGB_RED);
            rgb_matrix_set_color(52, RGB_RED);
        break;

        default:
        break;
    }

    #endif // RGB_MATRIX_ENABLE
}

// RGBLIGHT SECTION  ****************************************************************
//
// How long (in milliseconds) to wait between animation steps for each of the "Knight Rider" animations
const uint8_t RGBLED_KNIGHT_INTERVALS[] PROGMEM = {140, 63, 31};
// Light with CYLON effect when QWERTY is active
const rgblight_segment_t PROGMEM qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, 0,0,127}, {1, 10, 0,0,127},   {11, 2, 0,0,127},
    {13, 1, 0,0,127}, {22, 1, 0,0,127},   {23, 2, 0,0,127},
    {25, 9, 0,0,127}, {34, 1, 0,0,127}, {35, 13, 0,0,127}, {47, 6, HSV_RED}
);
// Light LEDs when RETPIE is active
const rgblight_segment_t PROGMEM retpie_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_GREEN},   {10, 1, HSV_GREEN},  {11, 1, HSV_BLUE},
    {12, 1, HSV_PURPLE}, {22, 1, HSV_YELLOW}, {23, 1, HSV_RED},
    {24, 1, HSV_PURPLE}, {34, 1, HSV_WHITE},  {35, 1, HSV_PURPLE},
    {37, 2, HSV_WHITE},  {39, 1, HSV_ORANGE}, {41, 1, HSV_ORANGE}, {44, 3, HSV_WHITE}
);
// Light LEDs when PROGRAM is active
const rgblight_segment_t PROGMEM program_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 18, 0}, {18, 4, HSV_PURPLE}, {22, 10, 0}, {32, 1, HSV_BLUE}, {33, 1, HSV_YELLOW}, {34, 1, HSV_WHITE}, {35, 1, HSV_YELLOW},
    {36, 7, 0}, {43, 1, HSV_BLUE}, {44, 3, HSV_WHITE}
);
// Light LEDs when LOWER is active
const rgblight_segment_t PROGMEM lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, 0}, {1, 2, HSV_PINK}, {3, 2, HSV_TEAL}, {5, 3, HSV_PINK}, {8, 3, HSV_TEAL}, {11, 1, 0},
    {12, 1, HSV_PURPLE}, {13, 1, 0}, {22, 1, 0},  {23, 1, HSV_PURPLE},
    {24, 2, HSV_GREEN}, {26, 8, 0}, {33, 1, HSV_BLUE}, {34, 1, HSV_GREEN}, {35, 1, HSV_BLUE},
    {36, 2, HSV_GREEN}, {38, 6, 0}, {44, 3, HSV_GREEN}
);
// Light LEDs when RAISE is active
const rgblight_segment_t PROGMEM raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 16, 0},
    {16, 1, HSV_PURPLE}, {17, 2, 0}, {19, 1, HSV_PURPLE}, {20, 5, 0},
    {25, 4, HSV_PURPLE}, {29, 2, 0}, {31, 4, HSV_PURPLE},
    {35, 13, 0}
);
// Light LEDs when ADJUST is active
const rgblight_segment_t PROGMEM adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_RED}, {11, 1, HSV_PURPLE}, {12, 9, 0}, {23, 1, HSV_PINK}, {24, 24, 0}, {47, 6, HSV_RED}
);
// Light STORMTROOPER when CAPS LOCK is active.
const rgblight_segment_t PROGMEM capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_GREEN}
);
// Define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    qwerty_layer,
    retpie_layer,    // Overrides other layers
    program_layer,   // Overrides other layers
    lower_layer,     // Overrides other layers
    raise_layer,     // Overrides other layers
    adjust_layer,    // Overrides other layers
    capslock_layer   // Overrides other layers
);
// Both layers will light up if both kb layers are active
layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state|default_layer_state, _QWERTY));
    rgblight_set_layer_state(1, layer_state_cmp(state|default_layer_state, _RETPIE));
    rgblight_set_layer_state(2, layer_state_cmp(state, _PROGRAM));
    rgblight_set_layer_state(3, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(4, layer_state_cmp(state, _RAISE));
    rgblight_set_layer_state(5, layer_state_cmp(state, _ADJUST));
    return state;
}
// Update layer state
bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(6, led_state.caps_lock);
    return true;
}

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;    // Enable the LED layers
//  debug_enable=true;                  // Debug enable
//  debug_matrix=true;                  // Debug Matrix
//  debug_keyboard=true;                // Debug Keyboard
//  debug_mouse=true;                   // Debug Mouse
};
