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

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    M_AO = SAFE_RANGE, // Åå
    M_AE, // Ää
    M_OE, // Öö
    TURBO,
};

char *alt_codes[][2] = {
    {
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_2)SS_TAP(X_KP_9)), // Alt+0229 → å
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_9)SS_TAP(X_KP_7)), // Alt+0197 → Å
    },
    {
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_2)SS_TAP(X_KP_8)), // Alt+0228 → ä
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_9)SS_TAP(X_KP_6)), // Alt+0196 → Ä
    },
    {
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_4)SS_TAP(X_KP_6)), // Alt+0246 → ö
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_1)SS_TAP(X_KP_4)), // Alt+0214 → Ö
    },
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
  KC_LCTL, KC_LGUI, KC_LALT,              KC_SPC,                            KC_RALT, TG(_FL), KC_RCTL, KC_LEFT,KC_DOWN,KC_RGHT),

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
   _______,_______,_______,_______,_______,_______,_______,_______,KC_LEAD,  _______,_______,        _______,KC_PGUP,_______,\
   _______,_______,_______,                _______,                          _______,TG(_FL),_______,KC_HOME,KC_PGDN,KC_END),


[_CL] = LAYOUT_65_martin(
    KC_GRV,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,  RESET,\
   _______,RGB_TOG,RGB_MOD,RGB_HUI,RGB_HUD,RGB_SAI,RGB_SAD,RGB_VAI,RGB_VAD,_______,_______,_______,_______,_______,_______,\
   _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______,_______,\
   _______,_______,_______,_______,_______, BL_DEC,BL_TOGG, BL_INC,BL_STEP,_______,_______,        _______,_______,_______,\
   _______,_______,_______,                 _______,                       _______,_______,_______,_______,_______,_______),
};

//LEADER_EXTERNS();


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
//        case GIT_A:
//            if (record->event.pressed) {
//                // when keycode GIT_A is pressed
//                SEND_STRING("git add -A");
//            } else {
//                // when keycode GIT_A is released
//            }
//            break;
//        case GIT_PT:
//            if (record->event.pressed) {
//                // when keycode GIT_PT is pressed
//                SEND_STRING("git push; git push --tags");
//            } else {
//                // when keycode GIT_PT is released
//            }
//            break;
//        case GIT_CM:
//            if (record->event.pressed) {
//                // when keycode GIT_CM is pressed
//                SEND_STRING("git commit -m \"\"" SS_TAP(X_LEFT));
//            } else {
//                // when keycode GIT_PT is released
//            }
//            break;
    }
    return true;
}

void matrix_init_user(void) {

}

//void matrix_scan_user(void) {
//    LEADER_DICTIONARY() {
//        leading = false;
//        leader_end();
//
//        SEQ_TWO_KEYS(KC_G, KC_A) {
//            SEND_STRING("git add -A");
//        }
//        SEQ_TWO_KEYS(KC_G, KC_P) {
//            SEND_STRING("git push");
//        }
//        SEQ_THREE_KEYS(KC_G, KC_P, KC_T) {
//            SEND_STRING("git push --tags");
//        }
//        SEQ_TWO_KEYS(KC_G, KC_C) {
//            SEND_STRING("git commit -m \"\""SS_TAP(X_LEFT));
//        }
//        SEQ_TWO_KEYS(KC_Y, KC_U) {
//            SEND_STRING("yarn upgrade-interactive --latest");
//        }
//        SEQ_TWO_KEYS(KC_Y, KC_L) {
//            SEND_STRING("yarn lint");
//        }
//        //        SEQ_THREE_KEYS(KC_Y, KC_L, KC_L) {
//        //            SEND_STRING("yarn lint && yarn typecheck");
//        //        }
//        //        SEQ_FOUR_KEYS(KC_Y, KC_L, KC_L, KC_L) {
//        //            SEND_STRING("yarn lint && yarn typecheck && yarn test");
//        //        }
//        //        SEQ_TWO_KEYS(KC_A, KC_S) {
//        //            register_code(KC_LGUI);
//        //            register_code(KC_S);
//        //            unregister_code(KC_S);
//        //            unregister_code(KC_LGUI);
//        //        }
//    }
//}

void led_set_user(uint8_t usb_led) {

}
