#include QMK_KEYBOARD_H

enum keyboard_layers {
    _BASE = 0, // Base Layer
    _RAISE,    // Raise
    _LOWER,    // Lower
    _CS,       // CS:GO
    _CS_FN     // CS:GO
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT_martinosaurus(
        KC_GESC,    KC_1,    KC_2,    KC_3,       KC_4,    KC_5,                   KC_6,    KC_7,        KC_8,    KC_9,    KC_0,    KC_MINS, // KC_EQL,           KC_BSPC,
        KC_TAB,     KC_Q,    KC_W,    KC_E,       KC_R,    KC_T,                   KC_Y,    KC_U,        KC_I,    KC_O,    KC_P,    KC_BSLS, //KC_BSLS, // KC_RBRC, KC_BSLS,
        KC_BSPC,    KC_A,    KC_S,    KC_D,       KC_F,    KC_G,                   KC_H,    KC_J,        KC_K,    KC_L,    KC_SCLN, KC_QUOT, //         KC_ENT,
        KC_LSFT,    KC_Z,    KC_X,    KC_C,       KC_V,    KC_B,                   KC_N,    KC_M,        KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, //         MO(_CL),
        KC_LCTL,    KC_LGUI, KC_LALT, MO(_LOWER),     KC_SPC,                      KC_ENT,  MO(_RAISE),  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),
[_RAISE] = LAYOUT_martinosaurus(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  // KC_F12,           KC_DEL,
        _______, KC_F12,  KC_LPRN, KC_RPRN, _______, _______,                _______, _______, KC_INS,  KC_LBRC, KC_RBRC, _______, // KC_EQL,  // KC_PSCR, KC_RBRC,KC_SLCK, //KC_PAUS, RESET,
        KC_DEL, _______, KC_LCBR, KC_RCBR, _______, _______,                 KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, KC_GRV,  // _______,
        _______, _______, KC_LBRC, KC_RBRC, _______, _______,                _______, _______, KC_LEAD, _______, _______, _______, // _______,
        _______, _______, _______, _______,    _______,                       KC_DEL, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),
[_LOWER] = LAYOUT_martinosaurus(
        _______, _______, _______, _______, _______, _______,                _______, _______, _______, _______, _______, KC_EQL,
        _______, _______, _______, _______, _______, _______,                KC_EQL,  KC_MINS, KC_LPRN, KC_RPRN, _______, KC_DEL,
        KC_CAPS, _______, _______, _______, _______, TG(_CS),                KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, KC_EQL,
        _______, _______, _______, _______, _______, _______,                KC_LBRC, _______, _______, KC_GT,   _______, _______,
        _______, _______, _______, _______,     _______,                     _______, _______, _______, _______, _______, _______
),
[_CS] = LAYOUT_martinosaurus(
        _______, _______, _______, _______, _______, _______,                _______, _______, _______, _______, _______, KC_GRV,
        _______, _______, _______, _______, _______, _______,                _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                _______, _______, _______, _______, _______, _______,
        _______, _______, _______, MO(_CS_FN),  _______,                     _______, _______, _______, KC_F2,   KC_F1,   KC_HOME
),
[_CS_FN] = LAYOUT_martinosaurus(
        _______, _______, _______, _______, _______, _______,                _______, _______, KC_NUMLOCK, KC_KP_SLASH, KC_KP_ASTERISK, KC_KP_MINUS,
        _______, _______, _______, _______, _______, _______,                _______, KC_MINS, KC_KP_7,    KC_KP_8,     KC_KP_9,        KC_KP_PLUS,
        _______, _______, _______, _______, _______, TG(_CS),                _______, _______, KC_KP_4,    KC_KP_5,     KC_KP_6,        KC_KP_PLUS,
        _______, _______, _______, _______, _______, _______,                _______, _______, KC_KP_1,    KC_KP_2,     KC_KP_3,        KC_KP_ENTER,
        _______, _______, _______, _______,    _______,                      _______, _______, KC_KP_0,    _______,     _______,        KC_KP_ENTER
)};


LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_TWO_KEYS(KC_G, KC_A) {
            SEND_STRING("git add -A");
        }
        SEQ_TWO_KEYS(KC_G, KC_P) {
            SEND_STRING("git push");
        }
        SEQ_THREE_KEYS(KC_G, KC_P, KC_T) {
            SEND_STRING("git push --tags");
        }
        SEQ_TWO_KEYS(KC_G, KC_C) {
            SEND_STRING("git commit -m \"\""SS_TAP(X_LEFT));
        }
        SEQ_TWO_KEYS(KC_Y, KC_U) {
            SEND_STRING("yarn upgrade-interactive --latest");
        }
//        SEQ_TWO_KEYS(KC_A, KC_S) {
//            register_code(KC_LGUI);
//            register_code(KC_S);
//            unregister_code(KC_S);
//            unregister_code(KC_LGUI);
//        }
    }
}