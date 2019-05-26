/* Copyright 2018 'mechmerlin'
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
#define RSFT_CL MT(MOD_RSFT, KC_CAPS)

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

enum layers {
    _BL = 0, // Base Layer
    _FL,     // Function Layer
    _CL      // Control Layer
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |    |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |    |
   * |----------------------------------------------------------------|
   * |_FL    |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |CAPS|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|_CL |
   * |----------------------------------------------------------------|
   * |Ctrl|Win |Alt |        Space          |Alt|_FL|Ctrl|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[_BL] = LAYOUT_65_martin(
  KC_ESC,  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,       KC_9, KC_0,    KC_MINS,  KC_EQL,KC_BSPC, _______, \
  KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,       KC_O, KC_P,    KC_LBRC, KC_RBRC,KC_BSLS, _______, \
  MO(_FL), KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,       KC_L, KC_SCLN, KC_QUOT,          KC_ENT, KC_CAPS, \
  KC_LSFT, KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,           KC_UP, MO(_CL), \
  KC_LCTL, KC_LGUI, KC_LALT,              KC_SPC,                            KC_RALT, MO(_FL), KC_RCTL, KC_LEFT,KC_DOWN,KC_RGHT),

  /* Keymap Fn Layer
   * ,----------------------------------------------------------------.
   * |~ `|F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |Rst |
   * |----------------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |Ins|PSc|SLk|Pau|   |     |    |
   * |----------------------------------------------------------------|
   * |      |   |   |   |   |   |Lef|Dn |Up |Rig|   |Grv|        |    |
   * |----------------------------------------------------------------|
   * |     |  |   |   |   |   |   |   |   |   |   |   |      |PUp|    |
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |Hom|PDn|End |
   * `----------------------------------------------------------------'
   */
[_FL] = LAYOUT_65_martin(
    KC_GRV,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,    KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,_______,\
   _______,_______,_______,_______,_______,_______,_______,_______, KC_INS,  KC_PSCR,KC_SLCK,KC_PAUS,_______,_______,_______,\
   _______,_______,_______,_______,_______,_______,KC_LEFT,KC_DOWN,  KC_UP,  KC_RGHT,_______, KC_GRV,        _______,_______,\
   _______,_______,_______,_______,_______,_______,_______,_______,_______,  _______,_______,        _______,KC_PGUP,_______,\
   _______,_______,_______,                _______,                          _______,_______,_______,KC_HOME,KC_PGDN,KC_END),


[_CL] = LAYOUT_65_martin(
    KC_GRV,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,  RESET,\
   _______,RGB_TOG,RGB_MOD,RGB_HUI,RGB_HUD,RGB_SAI,RGB_SAD,RGB_VAI,RGB_VAD,_______,_______,_______,_______,_______,_______,\
   _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______,_______,\
   _______,_______,_______,_______,_______, BL_DEC,BL_TOGG, BL_INC,BL_STEP,_______,_______,        _______,_______,_______,\
   _______,_______,_______,                 _______,                       _______,_______,_______,_______,_______,_______),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
