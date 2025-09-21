// Copyright 2023 Massdrop, Inc.
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum alt_keycodes {
    MD_BOOT  = SAFE_RANGE,               //Restart into bootloader after hold timeout
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_65_ansi_blocker(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_CAPS,
        KC_TAB,  KC_B,    KC_L,    KC_D,    KC_C,    KC_V,    KC_J,    KC_Y,    KC_O,    KC_U,    KC_COMM, KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME,
        KC_DEL , KC_N,    KC_R,    KC_T,    KC_S,    KC_G,    KC_P,    KC_H,    KC_A,    KC_E,    KC_I,    KC_QUOT,          KC_ENT,  KC_PGUP,
        KC_LSFT, KC_X,    KC_Q,    KC_M,    KC_W,    KC_Z,    KC_K,    KC_F,    KC_QUOT, KC_SLSH, KC_DOT,  KC_RSFT,          KC_UP,   KC_PGDN,
        KC_LGUI, KC_LCTL, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT_65_ansi_blocker(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_MUTE,
        _______, RGB_SPD, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, _______, _______,_______,_______,   KC_PSCR, KC_SCRL, KC_PAUS, _______, KC_END,
        _______, RGB_RMOD,RGB_VAD, RGB_MOD, RGB_HUD, RGB_SAD, _______, _______, _______, _______, _______, _______,          _______, KC_VOLU,
        _______, RGB_TOG, _______, _______, _______, QK_BOOT, NK_TOGG, _______, _______, _______, _______, _______,          KC_PGUP, KC_VOLD,
        _______, _______, _______,                            _______,                            _______, _______, KC_HOME, KC_PGDN, KC_END
    )
};


// EEPROM storage mode
enum alt_rgb_mode {
    RGB_MODE_ALL,
    RGB_MODE_KEYLIGHT,
    RGB_MODE_UNDERGLOW,
    RGB_MODE_NONE,
};

// EEPROM storage type
typedef union {
    uint32_t raw;
    struct {
        uint8_t rgb_mode :8;
    };
} alt_config_t;

alt_config_t alt_config;

// Read from EEPROM on init to load the last saved mode
void keyboard_post_init_kb(void) {
    alt_config.raw = eeconfig_read_user();
    switch (alt_config.rgb_mode) {
        case RGB_MODE_ALL:
            rgb_matrix_set_flags(LED_FLAG_ALL);
            rgb_matrix_enable_noeeprom();
            break;
        case RGB_MODE_KEYLIGHT:
            rgb_matrix_set_flags(LED_FLAG_KEYLIGHT);
            rgb_matrix_set_color_all(0, 0, 0);
            break;
        case RGB_MODE_UNDERGLOW:
            rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
            rgb_matrix_set_color_all(0, 0, 0);
            break;
        case RGB_MODE_NONE:
            rgb_matrix_set_flags(LED_FLAG_NONE);
            rgb_matrix_disable_noeeprom();
            break;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    switch (keycode) {
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        case RGB_TOG:
            if (record->event.pressed) {
              switch (rgb_matrix_get_flags()) {
                case LED_FLAG_ALL: {
                    rgb_matrix_set_flags(LED_FLAG_KEYLIGHT);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_KEYLIGHT: {
                    rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_UNDERGLOW: {
                    rgb_matrix_set_flags(LED_FLAG_NONE);
                    rgb_matrix_disable_noeeprom();
                  }
                  break;
                default: {
                    rgb_matrix_set_flags(LED_FLAG_ALL);
                    rgb_matrix_enable_noeeprom();
                  }
                  break;
              }
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}
