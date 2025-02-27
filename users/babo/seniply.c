#include QMK_KEYBOARD_H

// Seniply layout
// https://stevep99.github.io/seniply

tap_dance_action_t tap_dance_actions[] = {};

enum layers {
    DEF,
    NUM,
    MED,
    EXT,
    FNC,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEF] = LAYOUT_seniply(
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
        KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                          LT(EXT,KC_TAB),   KC_SPC,  KC_LSFT, LT(NUM,KC_ENT)
    ),
    [NUM] = LAYOUT_seniply(
    KC_EXLM, KC_AT,   KC_SCLN, KC_COLN, KC_UNDS,     KC_EQL,  KC_7,    KC_8,    KC_9,    KC_PLUS,
    KC_BSLS, KC_PIPE, KC_LCBR, KC_LPRN, KC_LBRC,     KC_ASTR, KC_4,    KC_5,    KC_6,    KC_MINS,
    KC_NO,   KC_NO,   KC_RCBR, KC_RPRN, KC_RBRC,     KC_0,    KC_1,    KC_2,    KC_3,    KC_SLSH,
                               _______, MO(MED),       _______, _______
    ),
    [MED] = LAYOUT_seniply(
    RALT(KC_1), RALT(KC_2), RALT(KC_3), RALT(KC_4), KC_BRIU,     KC_NO,   KC_AMPR, KC_GRV,  KC_TILD, KC_NO,
    KC_MUTE,    KC_VOLD,    KC_MPLY,    KC_VOLU,    KC_BRID,     KC_NO,   KC_DLR,  KC_PERC, KC_CIRC, KC_UNDS,
    KC_EJCT,    KC_MPRV,    KC_MSTP,    KC_MNXT,    KC_NO,       KC_NO,   KC_EXLM, KC_AT,   KC_HASH, KC_NO,
                                           _______, _______,     _______, _______
    ),
    [EXT] = LAYOUT_seniply(
    KC_ESC,        LALT(KC_LEFT), LCTL(KC_F),    LALT(KC_RGHT), KC_INS,            KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_CAPS,
    OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_LSFT), OSM(MOD_LCTL), OSM(MOD_RALT),     KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,
    LCTL(KC_Z),    LCTL(KC_X),    LCTL(KC_C),    KC_TAB,        LCTL(KC_V),        KC_ENT,  KC_BSPC, KC_RCTL, KC_LALT, KC_APP,
                                                       _______, _______,           _______, MO(FNC)
    ),
    [FNC] = LAYOUT_seniply(
    KC_NO,         KC_NO,         RCS(KC_F),     KC_PSCR,       KC_NO,             KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_NO,
    OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_LSFT), OSM(MOD_LCTL), OSM(MOD_RALT),     KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_NO,
    RCS(KC_Z),     RCS(KC_X),     RCS(KC_C),     LSFT(KC_TAB),  RCS(KC_V),         KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_NO,
                                                       _______, _______,           _______, _______
    )
};
