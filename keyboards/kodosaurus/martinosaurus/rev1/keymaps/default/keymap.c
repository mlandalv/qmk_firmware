/* Copyright 2019 Martin Landälv
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
    GIT_A = SAFE_RANGE,
    GIT_PT,
    GIT_CM,
};

enum keyboard_layers {
    _CMAK = 0,
    _QWER,
    _FN,
    _RAISE,
    _LOWER,
    _DN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWER] = LAYOUT_125( /* QWERTY */
            KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,       KC_5,                KC_6,    KC_7,      KC_8,    KC_9,    KC_0,    KC_MINS,
            KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,       KC_T,                KC_Y,    KC_U,      KC_I,    KC_O,    KC_P,    KC_BSLS,
            KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,       KC_G,                KC_H,    KC_J,      KC_K,    KC_L,    KC_SCLN, KC_QUOT,
            KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,       KC_B,                KC_N,    KC_M,      KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
            KC_LCTL, KC_LGUI, KC_RALT, KC_LALT, MO(_LOWER), KC_SPC,              KC_ENT, MO(_RAISE), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),
    [_CMAK] = LAYOUT_125( /* Colemak */
            KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,       KC_5,                KC_6,    KC_7,      KC_8,    KC_9,    KC_0,    KC_MINS,
            KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,       KC_B,                KC_J,    KC_L,      KC_U,    KC_Y, KC_SCLN,    KC_BSLS,
            KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,       KC_G,                KC_M,    KC_N,      KC_E,    KC_I,    KC_O,    KC_QUOT,
            KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,       KC_V,                KC_K,    KC_H,      KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
            KC_LCTL, KC_LGUI, KC_RALT, KC_LALT, MO(_LOWER), KC_SPC,              KC_ENT, MO(_RAISE), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),
    [_FN] = LAYOUT_125(
            KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,      KC_F5,               KC_F6,   KC_F7,     KC_NUMLOCK, KC_KP_SLASH,  KC_KP_ASTERISK, KC_KP_MINUS,
            _______, KC_F12,  _______, _______, _______,    _______,             _______, _______,   KC_KP_7,    KC_KP_8,      KC_KP_9,        KC_KP_PLUS,
            KC_DEL,  _______, _______, _______, _______,    _______,             _______, _______,   KC_KP_4,    KC_KP_5,      KC_KP_6,        KC_KP_PLUS,
            _______, _______, _______, _______, _______,    _______,             _______, _______,   KC_KP_1,    KC_KP_2,      KC_KP_3,        KC_KP_ENTER,
            _______, _______, _______, _______, _______,    _______,             _______, _______,   KC_KP_0,    _______,      _______,        KC_KP_ENTER
    ),
    [_RAISE] = LAYOUT_125(
            KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                  KC_F6,   KC_F7,     KC_F8,   KC_F9,   KC_F10,  KC_F11,
            _______, KC_F12,  KC_LPRN, KC_RPRN, _______, _______,                _______, _______,   KC_INS,  KC_LBRC, KC_RBRC, _______,
            KC_DEL,  _______, KC_LCBR, KC_RCBR, _______, _______,                KC_HOME, KC_PGDN,   KC_PGUP, KC_END , _______, KC_GRV ,
            _______, _______, KC_LBRC, KC_RBRC, _______, _______,                _______, _______,   _______, _______, _______, _______,
            KC_RCTL, _______, _______, KC_RALT, MO(_DN), _______,                _______, _______,   _______, _______, _______, _______
    ),
    [_LOWER] = LAYOUT_125(
            KC_GRV,  KC_6,    KC_7,       KC_8,    KC_9,    KC_0,                _______, _______,   _______, _______, _______, KC_EQL,
            _______, _______, _______,    _______, _______, _______,             _______, _______,   _______, _______, _______, _______,
            KC_DEL,  _______, _______,    _______, _______, _______,             KC_LEFT, KC_DOWN,   KC_UP,   KC_RGHT, KC_MINS, KC_EQL,
            _______, _______, _______,    _______, _______, _______,             _______, _______,   KC_LEAD, _______, _______, _______,
            KC_RCTL, _______, MO(_FN),    _______, _______, _______,             _______, MO(_DN),   KC_HOME, KC_PGDN, KC_PGUP, KC_END
    ),
    [_DN] = LAYOUT_125(
            QK_BOOT, _______, _______,   _______,   _______, _______,            _______, _______,   _______, _______, _______, _______,
            _______, _______, _______,   _______,   _______, _______,            _______, _______,   _______, _______, _______, _______,
            KC_CLCK, KC_NLCK, _______,   _______,   _______, _______,            _______, _______,   _______, _______, _______, _______,
            _______, _______, DF(_QWER), DF(_CMAK), _______, _______,            _______, _______,   _______, _______, _______, _______,
            _______, _______, _______,   _______,   _______, _______,            _______, _______,   _______, _______, _______, _______
    ),
};

LEADER_EXTERNS();

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case GIT_A:
      if (record->event.pressed) {
        // when keycode GIT_A is pressed
        SEND_STRING("git add -A");
      } else {
        // when keycode GIT_A is released
      }
      break;
    case GIT_PT:
      if (record->event.pressed) {
        // when keycode GIT_PT is pressed
        SEND_STRING("git push; git push --tags");
      } else {
        // when keycode GIT_PT is released
      }
      break;
    case GIT_CM:
      if (record->event.pressed) {
        // when keycode GIT_CM is pressed
          SEND_STRING("git commit -m \"\"" SS_TAP(X_LEFT));
      } else {
        // when keycode GIT_PT is released
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_TWO_KEYS(KC_G, KC_A) {
            SEND_STRING("git add -A");
        }
        SEQ_TWO_KEYS(KC_G, KC_C) {
            SEND_STRING("git commit -m \"\""SS_TAP(X_LEFT));
        }
        SEQ_TWO_KEYS(KC_Y, KC_U) {
            SEND_STRING("yarn upgrade-interactive --latest");
        }
        SEQ_TWO_KEYS(KC_U, KC_I) {
            SEND_STRING("pnpm update --interactive --latest --recursive");
        }


        SEQ_TWO_KEYS(KC_Y, KC_L) {
            SEND_STRING("yarn lint");
        }
//        SEQ_THREE_KEYS(KC_Y, KC_L, KC_L) {
//            SEND_STRING("yarn lint && yarn typecheck");
//        }
//        SEQ_FOUR_KEYS(KC_Y, KC_L, KC_L, KC_L) {
//            SEND_STRING("yarn lint && yarn typecheck && yarn test");
//        }
//        SEQ_TWO_KEYS(KC_A, KC_S) {
//            register_code(KC_LGUI);
//            register_code(KC_S);
//            unregister_code(KC_S);
//            unregister_code(KC_LGUI);
//        }
    }
}

void led_set_user(uint8_t usb_led) {

}
