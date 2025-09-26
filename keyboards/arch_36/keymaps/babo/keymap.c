#include QMK_KEYBOARD_H

#include "split_util.h"

uint8_t is_master;
uint16_t rgb_edit_timer = 0;
uint16_t last_rgb_char = 0;

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
#ifndef SPLIT_KEYBOARD
        if (keycode == RESET && !is_master) {
            return false;
        }
#endif
    }
    return true;
}

void matrix_init_keymap(void) { is_master = (uint8_t)is_keyboard_master(); }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case UG_TOGG:
        case UG_NEXT:
        case UG_PREV:
        case UG_HUEU:
        case UG_HUED:
        case UG_SATU:
        case UG_SATD:
        case UG_VALU:
        case UG_VALD:
            rgb_edit_timer = timer_read();
            last_rgb_char = keycode;
            break;
    }

    return true;
}
