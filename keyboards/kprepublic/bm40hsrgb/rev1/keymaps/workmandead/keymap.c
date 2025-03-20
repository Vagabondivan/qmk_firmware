/* Workmandead - Copyright 2025 Vagabondivan
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
  _WORKMAN,
  _FN,
  _LOWER,
  _RAISE,
  _ADJUST,
  _RESET
};

/* Custom keycodes */
enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    WORKMAN,
    FN,
    LOWER,
    RAISE,
    ADJUST
};

/*********************     LAYOUTS SECTION     ********************/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_mit(

 /*----------------------------------------------------------------------------------.
 |HYPESC|   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 | LSFT |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |  FN  | LCTL | LALT | GUI\ | TT(4)|    Space    | TT(5)| LEFT | DOWN |  UP  | RGHT |
 `----------------------------------------------------------------------------------*/

  ALL_T(KC_ESC),  KC_Q,     KC_W,     KC_E,             KC_R,   KC_T,  KC_Y,  KC_U,   KC_I,     KC_O,     KC_P,     KC_BSPC,
  KC_TAB,         KC_A,     KC_S,     KC_D,             KC_F,   KC_G,  KC_H,  KC_J,   KC_K,     KC_L,     KC_SCLN,  KC_QUOTE,
  KC_LSFT,        KC_Z,     KC_X,     KC_C,             KC_V,   KC_B,  KC_N,  KC_M,   KC_COMM,  KC_DOT,   KC_SLSH,  KC_ENT,
  FN,             KC_LCTL,  KC_LALT,  LGUI_T(KC_BSLS),  LOWER,    KC_SPC,     RAISE,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT
),

[_WORKMAN] = LAYOUT_planck_mit(

 /*----------------------------------------------------------------------------------.
 | GUI` |   Q  |   D  |   R  |   W  |   B  |   J  |   F  |   U  |   P  |   ;  |      |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |   A  |   S  |   H  |   T  |   G  |   Y  |   N  |   E  |   O  |   I  |      |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |   Z  |   X  |   M  |   C  |   V  |   K  |   L  |   ,  |   .  |   /  |      |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |      |      |      |      |             |      |      |      |      |      |
 `----------------------------------------------------------------------------------*/

  LGUI(KC_GRV),  KC_Q,     KC_D,     KC_R,     KC_W,     KC_B,  KC_J,  KC_F,     KC_U,     KC_P,     KC_SCLN,  KC_TRNS,
  KC_TRNS,       KC_A,     KC_S,     KC_H,     KC_T,     KC_G,  KC_Y,  KC_N,     KC_E,     KC_O,     KC_I,     KC_TRNS,
  KC_TRNS,       KC_Z,     KC_X,     KC_M,     KC_C,     KC_V,  KC_K,  KC_L,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_TRNS,
  KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS

),

[_LOWER] = LAYOUT_planck_mit(

 /*----------------------------------------------------------------------------------.
 |      |      |      |      |      |      |      |      |      |      |      |      |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |      | PREV | PLAY | NEXT |      |      |RGBTOG| BRI+ | BRI- |      |      |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |      | VOL- | MUTE | VOL+ |      |      | MOD+ | HUE+ | HUE- |      |      |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |      |      |      |      |             |      |      |      |      |      |
 `----------------------------------------------------------------------------------*/

  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  xKC_TRNS,
  KC_TRNS,  KC_TRNS,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_TRNS,  KC_TRNS,  RGB_TOG,  RGB_VAI,  RGB_VAD,  KC_TRNS,  xKC_TRNS,
  KC_TRNS,  KC_TRNS,  KC_VOLD,  KC_MUTE,  KC_VOLU,  KC_TRNS,  KC_TRNS,  RGB_MOD,  RGB_HUI,  RGB_HUD,  KC_TRNS,  xKC_TRNS,
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,         KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  xKC_TRNS
 
),

[_RAISE] = LAYOUT_planck_mit(

 /*----------------------------------------------------------------------------------.
 |   `  |   %  |   &  |   ?  |   +  |   @  |   $  |   _  |   [  |   ]  |   !  |      |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |   /  |   (  |   =  |   0  |   {  |   }  |   1  |   *  |   )  |   -  |   #  |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |   6  |   7  |   8  |   9  |   |  |   \  |   2  |   3  |   4  |   5  |   ^  |
 |------+------+------+------+------+-------------+------+------+------+------+------|
 |      |      |      |      |      |             |      | SFTL | SFTD | SFTU | SFTR |
 `----------------------------------------------------------------------------------*/

  KC_GRV,   KC_PERC,  KC_AMPR,  KC_QUES,  KC_PPLS,  KC_AT,    KC_DLR,   KC_UNDS,  KC_LBRC,        KC_RBRC,        KC_EXLM,      KC_TRNS,
  KC_TRNS,  KC_PSLS,  KC_LPRN,  KC_PEQL,  KC_0,     KC_LCBR,  KC_RCBR,  KC_1,     KC_PAST,        KC_RPRN,        KC_PMNS,      KC_HASH,
  KC_TRNS,  KC_6,     KC_7,     KC_8,     KC_9,     KC_PIPE,  KC_BSLS,  KC_2,     KC_3,           KC_4,           KC_5,         KC_CIRC,
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,         KC_TRNS,  RSFT(KC_LEFT),  RSFT(KC_DOWN),  RSFT(KC_UP),  RSFT(KC_RIGHT)

),

[_ADJUST] = LAYOUT_planck_mit(
 /*----------------------------------------------------------------------------------.
 |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 |------+------+------+------+------+-------------+------+------+------+------+------|
 |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |      |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |  F11 |  F12 |  F13 |  F14 |  F15 |  F16 |  F17 |  F18 |  F19 |  F20 |      |
 |------+------+------+------+------+-------------+------+------+------+------+------|
 |      |      |      |      |      |             |      |      |      |      |      |
 `----------------------------------------------------------------------------------*/

  KC_TRNS,  KC_1,     KC_3,     KC_3,     KC_4,     KC_5,    KC_6,    KC_7,     KC_8,     KC_9,     KC_0,     KC_TRNS,
  KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,   KC_F6,   KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_TRNS,
  KC_TRNS,  KC_F11,   KC_F12,   KC_F13,   KC_F14,   KC_F15,  KC_F16,  KC_F17,   KC_F18,   KC_F19,   KC_F20,   KC_TRNS,
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS

),

[_FN] = LAYOUT_planck_mit(

 /*----------------------------------------------------------------------------------.
 | MOD+ |      |      |      |      |  1   |  2   |  3   |MS CLT|MS CLC|MS CRT| DEL  |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 | BRI+ |      |      |      |      |  4   |  5   |  6   | MSLT | MSUP | MSRT |OSL(6)|
 |------+------+------+------+------+------+------+------+------+------+------+------|
 | BRI- |      |      |      |      |  7   |  8   |  9   |  0   | MSDN |      |      |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |      |      |      |      |             |      |      |      |      |      |
 `----------------------------------------------------------------------------------*/

  RGB_MOD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_1,  KC_2,  KC_3,     KC_BTN1,  KC_BTN3,  KC_BTN2,  KC_DEL,
  RGB_VAI,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_4,  KC_5,  KC_6,     KC_MS_L,  KC_MS_U,  KC_MS_R,  OSL(6),
  RGB_VAD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_7,  KC_8,  KC_9,     KC_0,     KC_MS_D,  KC_TRNS,  KC_TRNS,
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS

),

[_RESET] = LAYOUT_planck_mit(

 /*----------------------------------------------------------------------------------.
 | RSET |      |      |      |      |      |      |      |      |      |      |      |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |      |      |      |      |      |      |      |      |      |      |      |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |      |      |      |      |      |      |      |      |      |      |      |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |      |      |      |      |             |      |      |WRKMAN|QWERTY|      |
 `----------------------------------------------------------------------------------*/

  QK_BOOT,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,      KC_TRNS,        KC_TRNS,  KC_TRNS,  WORKMAN,  QWERTY,   KC_TRNS

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
            break;

        case WORKMAN:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_WORKMAN);
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
            } else {
                layer_off(_FN);
            }
            return false;
            break;

    }

    return true;

};

/*********************     LEDs SECTION     ********************/

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
	rgb_matrix_sethsv(160,160,255);
	rgb_matrix_set_speed(150);
	rgb_matrix_mode(4);

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {

[0] = {\
    {0,151,250},   {0,151,250},   {0,151,250},   {0,151,250},   {0,151,250},   {0,151,250},   {0,151,250},   {0,151,250},   {0,151,250},   {0,151,250},   {0,151,250},   {0,151,250},
    {0,151,250},   {0,151,250},   {0,151,250},   {0,151,250},   {0,151,250},   {0,151,250},   {0,151,250},   {0,151,250},   {0,151,250},   {0,151,250},   {0,151,250},   {0,151,250},
    {0,151,250},   {0,151,250},   {0,151,250},   {0,151,250},   {0,151,250},   {0,151,250},   {0,151,250},   {0,151,250},   {0,151,250},   {0,151,250},   {0,151,250},   {0,151,250},
    {0,151,250},   {0,151,250},   {0,151,250},   {0,151,250},   {0,151,250},          {0,151,250},           {0,151,250},   {0,151,250},   {0,151,250},   {0,151,250},   {0,151,250},
    {0,0,255},     {0,0,255},     {0,0,255},     {0,0,255},     {0,0,255},     {0,0,255}
},

[1] = {\
    {0,249,246},   {0,249,246},   {0,249,246},   {0,249,246},   {0,249,246},   {0,249,246},   {0,249,246},   {0,249,246},   {0,249,246},   {0,249,246},   {0,249,246},   {0,249,246},
    {0,249,246},   {0,249,246},   {106,207,233}, {106,207,233}, {106,207,233}, {0,249,246},   {0,249,246},   {31,255,255},  {31,255,255},  {31,255,255},  {0,249,246},   {0,249,246},
    {0,249,246},   {0,249,246},   {106,207,233}, {106,207,233}, {106,207,233}, {0,249,246},   {0,249,246},   {31,255,255},  {31,255,255},  {31,255,255},  {0,249,246},   {0,249,246},
    {0,249,246},   {0,249,246},   {0,249,246},   {0,249,246},   {0,249,246},          {0,249,246},           {0,249,246},   {0,249,246},   {0,249,246},   {0,249,246},   {0,249,246},
    {0,0,255},     {0,0,255},     {0,0,255},     {0,0,255},     {0,0,255},     {0,0,255}
},

[2] = {\
    {84,240,255},  {84,240,255},  {84,240,255},  {84,240,255},  {84,240,255},  {84,240,255},  {84,240,255},  {84,240,255},  {84,240,255},  {84,240,255},  {84,240,255},  {84,240,255},
    {84,240,255},  {84,240,255},  {84,240,255},  {84,240,255},  {174,199,219}, {84,240,255},  {84,240,255},  {174,199,219}, {84,240,255},  {84,240,255},  {84,240,255},  {84,240,255},
    {84,240,255},  {174,199,219}, {174,199,219}, {174,199,219}, {174,199,219}, {84,240,255},  {84,240,255},  {174,199,219}, {174,199,219}, {174,199,219}, {174,199,219}, {84,240,255},
    {84,240,255},  {84,240,255},  {84,240,255},  {84,240,255},  {84,240,255},         {84,240,255},          {84,240,255},  {84,240,255},  {84,240,255},  {84,240,255},  {84,240,255},
    {0,0,255},     {0,0,255},     {0,0,255},     {0,0,255},     {0,0,255},     {0,0,255}
},

[3] = {\
    {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255},
    {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255},
    {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255},
    {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255},        {173,246,255},         {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255},
    {0,0,255},     {0,0,255},     {0,0,255},     {0,0,255},     {0,0,255},     {0,0,255}
},

[4] = {\
    {0,0,255},     {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {31,255,255},  {31,255,255},  {31,255,255},  {165,159,229}, {165,159,229}, {165,159,229}, {0,0,0},
    {0,0,255},     {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {31,255,255},  {31,255,255},  {31,255,255},  {165,159,229}, {165,159,229}, {165,159,229}, {0,183,238},
    {0,0,255},     {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {31,255,255},  {31,255,255},  {31,255,255},  {31,255,255},  {165,159,229}, {0,0,0},       {0,0,0},
    {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},              {0,0,0},               {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
    {0,0,255},     {0,0,255},     {0,0,255},     {0,0,255},     {0,0,255},     {0,0,255}
},

[5] = {\
    {0,183,238},   {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
    {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
    {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},
    {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},       {0,0,0},               {0,0,0},              {0,0,0},       {0,0,0},       {174,199,219}, {84,240,255},  {0,0,0},
    {0,0,255},     {0,0,255},     {0,0,255},     {0,0,255},     {0,0,255},     {0,0,255}
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
	    rgb_matrix_set_color(12, 0x00, 0xFF, 0x00); // Green for Caps Lock ON
	}

/*
	// Check the Num Lock state
	if (host_keyboard_led_state().num_lock) {
	    rgb_matrix_set_color(11, 0x00, 0xFF, 0x00); // Green for Num Lock ON
	}
*/
  
  switch (biton32(layer_state)) {

    case 0:
        set_layer_color(0);
    break;

    case 1:
        set_layer_color(1);
    break;

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

  default:

    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
       rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
    return false;
}
