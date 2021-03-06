#include QMK_KEYBOARD_H
#include "sendstring_italian.h"
//#include "sendstring_italian_osx_ansi.h"

// Layer Names
enum custom_layers {
    _NUMPAD,
    _MACROSA,
    _MACROSB,
    _RAISE,
    _RESET
};

// Custom keycodes
enum custom_keycodes {
    NUMPAD = SAFE_RANGE,
    MACROSA,
    MACROSB,
    RAISE,
    APT1,
    APT2,
    APT3,
    APT4,
    APT5,
    APT6,
    APT7,
    APT8,
    DPKG1,
    DPKG2,
    DPKG3,
    DPKG4,
    LNAV1,
    LNAV2,
    LNAV3,
    LNAV4,
    MAIL,
    PWD1,
    PWD2,
    PWD3,
    PWD4,
    RUDDER1,
    RUDDER2,
    RUDDER3,
    RUDDER4,
    ZABBIX1,
    ZABBIX2,
    ZABBIX3,
    ZABBIX4,
    SYSRST


};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_NUMPAD] = LAYOUT_ortho_6x4 (

 /*-------------------------------.
  | ESC   | AC    | %     | FN    |
  |       |       |       |       |
  |-------+-------+-------+-------|
  | C     | /     | *     | -     |
  |       |       |       |       |
  |-------+-------+-------+-------|
  | 7     | 8     | 9     |       |
  |       |       |       |       |
  |-------+-------+-------+   +   |
  | 4     | 5     | 6     |       |
  |       |       |       |       |
  |-------+-------+-------+-------|
  | 1     | 2     | 3     |   E   |
  |       |       |       |   N   |
  |-------+-------+-------+   T   |
  | 0             |  .    |   E   |
  |               |       |   R   |
  `-------------------------------*/

   LALT(KC_ESC),  LALT(KC_SLSH),  KC_PERC,         RAISE,
   KC_C,          KC_PSLS,        KC_PAST,         KC_PMNS,
   KC_P7,         KC_P8,          KC_P9,           KC_PPLS,
   KC_P4,         KC_P5,          KC_P6,           KC_PPLS,
   KC_P1,         KC_P2,          KC_P3,           KC_PENT,
   KC_P0,         KC_P0,          KC_DOT,          KC_PENT
),

 [_MACROSA] = LAYOUT_ortho_6x4 (

 /*-------------------------------.
  | Y     | N     | MAIL  |       |
  |       |       |       |       |
  |-------+-------+-------+-------|
  | LNAV4 |ZABBIX4|RUDDER4| BCKSP |
  |       |       |       |       |
  |-------+-------+-------+-------|
  | LNAV3 |ZABBIX3|RUDDER3|       |
  |       |       |       |       |
  |-------+-------+-------+   L   |
  | LNAV2 |ZABBIX2|RUDDER2|       |
  |       |       |       |       |
  |-------+-------+-------+-------|
  | LNAV1 |ZABBIX1|RUDDER1|   E   |
  |       |       |       |   N   |
  |-------+-------+-------+   T   |
  |    CTRL+L     |CTRL+U |   E   |
  |               |       |   R   |
  `-------------------------------*/

   KC_Y,           KC_N,           MAIL,           _______,
   LNAV4,          ZABBIX4,        RUDDER4,        KC_BSPC,
   LNAV3,          ZABBIX3,        RUDDER3,        LCTL(KC_M),
   LNAV2,          ZABBIX2,        RUDDER2,        KC_ENT,
   LNAV1,          ZABBIX1,        RUDDER1,        KC_ENT,
   LCTL(KC_L),     KC_NO,          LCTL(KC_U),     KC_ENT
),

 [_MACROSB] = LAYOUT_ortho_6x4 (

 /*-------------------------------.
  |  Y    |  N    |  MAIL |       |
  |       |       |       |       |
  |-------+-------+-------+-------|
  |  APT4 | DPKG4 |  APT8 | BCKSP |
  |       |       |       |       |
  |-------+-------+-------+-------|
  |  APT3 | DPKG3 |  APT7 |       |
  |       |       |       |       |
  |-------+-------+-------+ CTRL+ |
  |  APT2 | DPKG2 |  APT6 |   M   |
  |       |       |       |       |
  |-------+-------+-------+-------|
  |  APT1 | DPKG1 |  APT5 |   E   |
  |       |       |       |   N   |
  |-------+-------+-------+   T   |
  |    CTRL+L     |CTRL+U |   E   |
  |               |       |   R   |
  `-------------------------------*/

   KC_Y,           KC_N,           MAIL,           _______,
   APT4,           DPKG4,          APT8,           KC_BSPC,
   APT3,           DPKG3,          APT7,           LCTL(KC_M),
   APT2,           DPKG2,          APT6,           KC_ENT,
   APT1,           DPKG1,          APT5,           KC_ENT,
   LCTL(KC_L),     KC_NO,          LCTL(KC_U),     KC_ENT
),

 [_RAISE] = LAYOUT_ortho_6x4 (

 /*-------------------------------.
  | NUMPD |MACROSA|MACROSB|       |
  |       |       |       |       |
  |-------+-------+-------+-------|
  |  PWD1 | PWD2  | PWD3  | PWD4  |
  |       |       |       |       |
  |-------+-------+-------+-------|
  |       |       |       |       |
  |       |       |       |  BL   |
  |-------+-------+-------+       |
  |       |       |       |  INC  |
  |       |       |       |       |
  |-------+-------+-------+-------|
  |       |       |       |       |
  |       |       |       |  BL   |
  |-------+-------+-------+       |
  |   BL TOGGLE   |OSL(4) |  DEC  |
  |               |       |       |
  `-------------------------------*/

   NUMPAD,         MACROSA,        MACROSB,        _______,
   PWD1,           PWD2,           PWD3,           PWD4,
   KC_NO,          KC_NO,          KC_NO,          BL_INC,
   KC_NO,          KC_NO,          KC_NO,          BL_INC,
   KC_NO,          KC_NO,          KC_NO,          BL_DEC,
   BL_TOGG,        KC_NO,          OSL(4),         BL_DEC
),

 [_RESET] = LAYOUT_ortho_6x4 (

 /*-------------------------------.
  |       |       |       |       |
  |       |       |       |       |
  |-------+-------+-------+-------|
  |       |       |       |       |
  |       |       |       |       |
  |-------+-------+-------+-------|
  |       |       |       |       |
  |       |       |       |       |
  |-------+-------+-------+       |
  |       |       |       |       |
  |       |       |       |       |
  |-------+-------+-------+-------|
  |       |       |       |       |
  |       |       |       |       |
  |-------+-------+-------+       |
  |               | RESET |       |
  |               |       |       |
  `-------------------------------*/

   KC_NO,          KC_NO,          KC_NO,          KC_NO,
   KC_NO,          KC_NO,          KC_NO,          KC_NO,
   KC_NO,          KC_NO,          KC_NO,          KC_NO,
   KC_NO,          KC_NO,          KC_NO,          KC_NO,
   KC_NO,          KC_NO,          KC_NO,          KC_NO,
   KC_NO,          KC_NO,          RESET,          KC_NO
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {

        case NUMPAD:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_NUMPAD);
            }
            return false;
            break;

        case MACROSA:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_MACROSA);
            }
            return false;
            break;

        case MACROSB:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_MACROSB);
            }
            return false;
            break;

        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
            } else {
                layer_off(_RAISE);
            }
            return false;
            break;

        case PWD1:  // Notes
            if (record->event.pressed) {
                SEND_STRING("password01");
            }
            return false;
            break;

        case PWD2:  // Notes
            if (record->event.pressed) {
                SEND_STRING("Skywalker72");
            }
            return false;
            break;

        case PWD3:  // Notes
            if (record->event.pressed) {
                SEND_STRING("MainStreaming123");
            }
            return false;
            break;

        case PWD4:  // Notes
            if (record->event.pressed) {
                SEND_STRING("Chrm01");
            }
            return false;
            break;

        case MAIL:  // Notes
            if (record->event.pressed) {
                SEND_STRING("mail.ivanp@gmail.com");
            }
            return false;
            break;

        case LNAV1:  // Notes
            if (record->event.pressed) {
                SEND_STRING("lnav /var/log/dpkg.log");
            }
            return false;
            break;

        case LNAV2:  // Notes
            if (record->event.pressed) {
                SEND_STRING("lnav /mnt/ACCESSLOG/error.log");
            }
            return false;
            break;

        case LNAV3:  // Notes
            if (record->event.pressed) {
                SEND_STRING("lnav /mnt/ACCESSLOG/access.log");
            }
            return false;
            break;

        case LNAV4:  // Notes
            if (record->event.pressed) {
                SEND_STRING("");
            }
            return false;
            break;

        case ZABBIX1:  // Notes
            if (record->event.pressed) {
                SEND_STRING("/usr/sbin/nginx -t 2>/tmp/nginxLogConfigTest ; echo $? > /tmp/nginxConfigTest");
            }
            return false;
            break;

        case ZABBIX2:  // Notes
            if (record->event.pressed) {
                SEND_STRING("mkdir /run/zabbix/; chown zabbix /run/zabbix; systemctl restart zabbix-agent");
            }
            return false;
            break;

        case ZABBIX3:  // Notes
            if (record->event.pressed) {
                SEND_STRING("");
            }
            return false;
            break;

        case ZABBIX4:  // Notes
            if (record->event.pressed) {
                SEND_STRING("");
            }
            return false;
            break;

        case RUDDER1:  // Notes
            if (record->event.pressed) {
                SEND_STRING("sudo rudder agent update -f && sudo rudder agent run -i");
            }
            return false;
            break;

        case RUDDER2:  // Notes
            if (record->event.pressed) {
                SEND_STRING("sudo rudder agent run -i");
            }
            return false;
            break;

        case RUDDER3:  // Notes
            if (record->event.pressed) {
                SEND_STRING("sudo rudder agent update -f");
            }
            return false;
            break;

        case RUDDER4:  // Notes
            if (record->event.pressed) {
                SEND_STRING("");
            }
            return false;
            break;

        case APT1:  // Notes
            if (record->event.pressed) {
                SEND_STRING("sudo apt-get update");
            }
            return false;
            break;

        case APT2:  // Notes
            if (record->event.pressed) {
                SEND_STRING("sudo apt-mark hold ");
            }
            return false;
            break;

        case APT3:  // Notes
            if (record->event.pressed) {
                SEND_STRING("sudo apt-get upgrade");
            }
            return false;
            break;

        case APT4:  // Notes
            if (record->event.pressed) {
                SEND_STRING("sudo apt install ");
            }
            return false;
            break;

        case DPKG1:  // Notes
            if (record->event.pressed) {
                SEND_STRING("dpkg -l | grep delivery");
            }
            return false;
            break;

        case DPKG2:  // Notes
            if (record->event.pressed) {
                SEND_STRING("dpkg -l | grep lua-mainstreaming");
            }
            return false;
            break;

        case DPKG3:  // Notes
            if (record->event.pressed) {
                SEND_STRING("dpkg -l | grep machinecontroller");
            }
            return false;
            break;

        case DPKG4:  // Notes
            if (record->event.pressed) {
                SEND_STRING("dpkg -l | grep nodemanager");
            }
            return false;
            break;

        case APT5:  // Notes
            if (record->event.pressed) {
                SEND_STRING("sudo apt list --upgradable");
            }
            return false;
            break;

        case APT6:  // Notes
            if (record->event.pressed) {
                SEND_STRING("sudo apt autoremove");
            }
            return false;
            break;

        case APT7:  // Notes
            if (record->event.pressed) {
                SEND_STRING("sudo apt-get update --fix-missing");
            }
            return false;
            break;

        case APT8:  // Notes
            if (record->event.pressed) {
                SEND_STRING("sudo apt --only-upgrade install");
            }
            return false;
            break;

        case SYSRST:  // Notes
            if (record->event.pressed) {
                SEND_STRING("sudo systemctl restart ");
            }
            return false;
            break;
    }
    return true;
};
