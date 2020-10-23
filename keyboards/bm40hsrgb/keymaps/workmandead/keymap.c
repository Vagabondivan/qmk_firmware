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

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)

// Layer Names
enum custom_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
  _QWERTY,
  _MOUSENUM,
  _RESET,
};

// Custom keycodes
enum custom_keycodes {
  RGB_SLD = SAFE_RANGE,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

// LAYOUTS SECTION     **************************************************************
//
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT_planck_mit(
/*-----------------------------------------------------------------------------------.
 | Tab  |   Q  |   D  |   R  |   W  |   B  |   J  |   F  |   U  |   P  |   ;  | Bksp |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |HYPESC|   A  |   S  |   H  |   T  |   G  |   Y  |   N  |   E  |   O  |   I  |  "   |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |OSL(2)|   Z  |   X  |   M  |   C  |   V  |   K  |   L  |   ,  |   .  |   /  |Enter |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 | TT(5)| TT(4)| LCTL | LALT | GUI\ |    Space    | LEFT | DOWN |  UP  | RGHT | LSFT |
 `-----------------------------------------------------------------------------------*/
  KC_TAB,         KC_Q,      KC_D,     KC_R,     KC_W,             KC_B,    KC_J,   KC_F,     KC_U,     KC_P,    KC_SCLN,   KC_BSPC,
  ALL_T(KC_ESC),  KC_A,      KC_S,     KC_H,     KC_T,             KC_G,    KC_Y,   KC_N,     KC_E,     KC_O,    KC_I,      KC_QUOTE,
  OSL(2),         KC_Z,      KC_X,     KC_M,     KC_C,             KC_V,    KC_K,   KC_L,     KC_COMM,  KC_DOT,  KC_SLSH,   KC_ENT,
  TT(5),          TT(4),     KC_LCTL,  KC_LALT,  LGUI_T(KC_BSLS),     KC_SPC,       KC_LEFT,  KC_DOWN,  KC_UP,   KC_RGHT,   KC_LSFT
  ),

[_LOWER] = LAYOUT_planck_mit(
/*-----------------------------------------------------------------------------------.
 |      |      |      |      |      |      |      |      |      |      |      |      |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |      | PREV | PLAY | NEXT |      |      |RGBTOG| BRI+ | BRI- |      | RSET |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |      | VOL- | MUTE | VOL+ |      |      | MOD+ | HUE+ | HUE- |      |      |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |      |      |      |      |             |      |      |      |      |      |
 `-----------------------------------------------------------------------------------*/
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
  KC_TRNS,  KC_TRNS,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_TRNS,  KC_TRNS,  RGB_TOG,  RGB_VAI,  RGB_VAD,  KC_TRNS,  RESET,
  KC_TRNS,  KC_TRNS,  KC_VOLD,  KC_MUTE,  KC_VOLU,  KC_TRNS,  KC_TRNS,  RGB_MOD,  RGB_HUI,  RGB_HUD,  KC_TRNS,  KC_TRNS,
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  ),

[_RAISE] = LAYOUT_planck_mit(
/*-----------------------------------------------------------------------------------.
 |   `  |   %  |   &  |   ?  |   +  |   @  |   $  |   _  |   [  |   ]  |   !  |      |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |   /  |   (  |   =  |   0  |   {  |   }  |   1  |   *  |   )  |   -  |   #  |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |   6  |   7  |   8  |   9  |   |  |   \  |   2  |   3  |   4  |   5  |   ^  |
 |------+------+------+------+------+-------------+------+------+------+------+------|
 |      |      |      |      |      |             | SFTL | SFTD | SFTU | SFTR |      |
 `-----------------------------------------------------------------------------------*/
  KC_GRV,  KC_PERC,    KC_AMPR,  KC_QUES,   KC_PPLS,  KC_AT,    KC_DLR,   KC_UNDS,        KC_LBRC,        KC_RBRC,      KC_EXLM,         KC_TRNS,
  KC_TRNS,   KC_PSLS,  KC_LPRN,  KC_PEQL,   KC_0,     KC_LCBR,  KC_RCBR,  KC_1,           KC_PAST,        KC_RPRN,      KC_PMNS,         KC_HASH,
  KC_TRNS,   KC_6,     KC_7,     KC_8,      KC_9,     KC_PIPE,  KC_BSLS,  KC_2,           KC_3,           KC_4,         KC_5,            KC_CIRC,
  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,        KC_TRNS,      RSFT(KC_LEFT),  RSFT(KC_DOWN),  RSFT(KC_UP),  RSFT(KC_RIGHT),  KC_TRNS
  ),

[_ADJUST] = LAYOUT_planck_mit(
/*-----------------------------------------------------------------------------------.
 |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 |------+------+------+------+------+-------------+------+------+------+------+------|
 |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | RSET |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |  F11 |  F12 |  F13 |  F14 |  F15 |  F16 |  F17 |  F18 |  F19 |  F20 |      |
 |------+------+------+------+------+-------------+------+------+------+------+------|
 |      |      |      |      |      |             |      |      |      |      |      |
 `-----------------------------------------------------------------------------------*/
    KC_TRNS,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,    KC_7,     KC_8,     KC_9,     KC_0,     KC_TRNS,
    KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,   KC_F7,    KC_F8,    KC_F9,    KC_F10,   RESET,
    KC_TRNS,  KC_F11,   KC_F12,   KC_F13,   KC_F14,   KC_F15,   KC_F16,  KC_F17,   KC_F18,   KC_F19,   KC_F20,   KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
),

[_QWERTY] = LAYOUT_planck_mit(
/*-----------------------------------------------------------------------------------.
 | GUI` |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |      |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |      |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |      |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 |      |      |      |      |      |             |      |      |      |      |      |
 `-----------------------------------------------------------------------------------*/
    LGUI(KC_GRV),  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,   KC_U,     KC_I,      KC_O,     KC_P,       KC_TRNS,
    KC_TRNS,       KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,   KC_J,     KC_K,      KC_L,     KC_SCOLON,  KC_TRNS,
    KC_TRNS,       KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,   KC_M,     KC_COMM,   KC_DOT,   KC_SLSH,    KC_TRNS,
    KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,       KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,    KC_TRNS
),

[_MOUSENUM] = LAYOUT_planck_mit(
    RGB_MOD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_1,     KC_2,     KC_3,  KC_MS_BTN1,     KC_MS_BTN3,     KC_MS_BTN2,   KC_TRNS,         OSL(6),
    RGB_VAI,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_4,     KC_5,     KC_6,  KC_MS_LEFT,     KC_MS_UP,       KC_MS_RIGHT,  KC_TRNS,         KC_TRNS,
    RGB_VAD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_7,     KC_8,     KC_9,  KC_0,           KC_MS_DOWN,     KC_TRNS,      KC_TRNS,         KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,      RSFT(KC_LEFT),  RSFT(KC_DOWN),  RSFT(KC_UP),  RSFT(KC_RIGHT),  KC_RSHIFT
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
    RESET,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
),
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [1] = { {0,249,246}, {0,249,246}, {0,249,246}, {0,249,246}, {0,249,246}, {0,249,246}, {0,249,246}, {0,249,246}, {0,249,246}, {0,249,246}, {0,249,246}, {0,249,246}, {0,249,246}, {0,249,246}, {106,207,233}, {106,207,233}, {106,207,233}, {0,249,246}, {0,249,246}, {31,255,255}, {31,255,255}, {31,255,255}, {0,249,246}, {0,249,246}, {0,249,246}, {0,249,246}, {106,207,233}, {106,207,233}, {106,207,233}, {0,249,246}, {0,249,246}, {31,255,255}, {31,255,255}, {31,255,255}, {0,249,246}, {0,249,246}, {0,249,246}, {0,249,246}, {0,249,246}, {0,249,246}, {0,249,246}, {0,249,246}, {0,249,246}, {0,249,246}, {0,249,246}, {0,249,246}, {0,249,246} },

    [2] = { {84,240,255}, {84,240,255}, {84,240,255}, {84,240,255}, {84,240,255}, {84,240,255}, {84,240,255}, {84,240,255}, {84,240,255}, {84,240,255}, {84,240,255}, {84,240,255}, {84,240,255}, {84,240,255}, {84,240,255}, {84,240,255}, {174,199,219}, {84,240,255}, {84,240,255}, {174,199,219}, {84,240,255}, {84,240,255}, {84,240,255}, {84,240,255}, {84,240,255}, {174,199,219}, {174,199,219}, {174,199,219}, {174,199,219}, {84,240,255}, {84,240,255}, {174,199,219}, {174,199,219}, {174,199,219}, {174,199,219}, {84,240,255}, {84,240,255}, {84,240,255}, {84,240,255}, {84,240,255}, {84,240,255}, {84,240,255}, {84,240,255}, {84,240,255}, {84,240,255}, {84,240,255}, {84,240,255} },

    [3] = { {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255}, {173,246,255} },

    [4] = { {0,151,250}, {0,151,250}, {0,151,250}, {0,151,250}, {0,151,250}, {0,151,250}, {0,151,250}, {0,151,250}, {0,151,250}, {0,151,250}, {14,255,255}, {0,151,250}, {0,151,250}, {0,151,250}, {0,151,250}, {0,151,250}, {0,151,250}, {0,151,250}, {0,151,250}, {141,255,233}, {141,255,233}, {141,255,233}, {0,151,250}, {0,151,250}, {0,151,250}, {0,151,250}, {0,151,250}, {0,151,250}, {0,151,250}, {14,255,255}, {14,255,255}, {14,255,255}, {0,151,250}, {0,151,250}, {14,255,255}, {0,151,250}, {0,151,250}, {0,151,250}, {0,151,250}, {0,151,250}, {0,151,250}, {0,151,250}, {0,151,250}, {0,151,250}, {0,151,250}, {0,151,250}, {0,151,250} },

    [5] = { {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {31,255,255}, {31,255,255}, {31,255,255}, {165,159,229}, {165,159,229}, {165,159,229}, {0,0,0}, {0,183,238}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {31,255,255}, {31,255,255}, {31,255,255}, {165,159,229}, {165,159,229}, {165,159,229}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {31,255,255}, {31,255,255}, {31,255,255}, {31,255,255}, {165,159,229}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [6] = { {84,240,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

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

void rgb_matrix_indicators_user(void) {
//  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
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
    case 6:
      set_layer_color(6);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

#ifdef AUDIO_ENABLE
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo+=1;
            } else {
                muse_tempo-=1;
            }
        }
    } else {
        if (clockwise) {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_DOWN);
            unregister_code(KC_MS_WH_DOWN);
        #else
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        #endif
        } else {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_UP);
            unregister_code(KC_MS_WH_UP);
        #else
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        #endif
        }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
    case RAISE:
    case LOWER:
        return false;
    default:
        return true;
    }
}
#endif

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
