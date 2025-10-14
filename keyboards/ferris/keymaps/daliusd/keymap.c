/* Copyright 2021 @daliusd
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

#include "flow.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layers {
    _GALLIUM,
    _SYM,
    _NAV,
    _MISC,
    _HUN,
    _MOUSE,
    _FUNC,
    _LT_MAC,
};

enum custom_keycodes {
  OS_MISC = SAFE_RANGE,
  OS_HUN,
  OS_FUNC,
};

// Shortcut to make keymap more readable

#define L_NAV       MO(_NAV)
#define L_SYM       MO(_SYM)
#define L_MOUSE     MO(_MOUSE)

#define K_PRINT     (QK_LCTL | QK_LSFT | QK_LGUI | KC_4)
#define K_VIDEO     (QK_LSFT | QK_LGUI | KC_5)

// flow_config should correspond to following format:
// * layer keycode
// * modifier keycode
const uint16_t flow_config[FLOW_COUNT][2] = {
    {L_NAV, KC_LALT},
    {L_NAV, KC_LGUI},
    {L_NAV, KC_LCTL},
    {L_SYM, KC_RCTL},
    {L_SYM, KC_RGUI},
    {L_SYM, KC_RALT},
};

const uint16_t flow_layers_config[FLOW_LAYERS_COUNT][2] = {
    {OS_MISC, _MISC},
    {OS_HUN, _HUN},
    {OS_FUNC, _FUNC},
};

// Unicode characters
enum unicode_names {
    SNEK,
    EURO,
    HU_A_AC,
    HU_E_AC,
    HU_I_AC,
    HU_O_AC,
    HU_O_DA,
    HU_O_DI,
    HU_U_AC,
    HU_U_DA,
    HU_U_DI,
    HU_a_AC,
    HU_e_AC,
    HU_i_AC,
    HU_o_AC,
    HU_o_DA,
    HU_o_DI,
    HU_u_AC,
    HU_u_DA,
    HU_u_DI,
};

const uint32_t unicode_map[] PROGMEM = {
    [SNEK]  = 0x1F40D, // 🐍
    [EURO]  = 0x20ac, // €

    [HU_A_AC] = 0x00C1, // Á
    [HU_E_AC] = 0x00C9, // É
    [HU_I_AC] = 0x00CD, // Í
    [HU_O_AC] = 0x00D3, // Ó
    [HU_O_DA] = 0x0150, // Ő
    [HU_O_DI] = 0x00D6, // Ö
    [HU_U_AC] = 0x00DA, // Ú
    [HU_U_DA] = 0x0170, // Ű
    [HU_U_DI] = 0x00DC, // Ü

    [HU_a_AC] = 0x00E1, // á
    [HU_e_AC] = 0x00E9, // é
    [HU_i_AC] = 0x00ED, // í
    [HU_o_AC] = 0x00F3, // ó
    [HU_o_DA] = 0x0151, // ő
    [HU_o_DI] = 0x00F6, // ö
    [HU_u_AC] = 0x00FA, // ú
    [HU_u_DA] = 0x0171, // ű
    [HU_u_DI] = 0x00FC, // ü
};

#define K_SNEK      UM(SNEK)
#define K_EURO      UM(EURO)

#define HU_AAC      UP(HU_a_AC, HU_A_AC)
#define HU_EAC      UP(HU_e_AC, HU_E_AC)
#define HU_IAC      UP(HU_i_AC, HU_I_AC)
#define HU_OAC      UP(HU_o_AC, HU_O_AC)
#define HU_ODA      UP(HU_o_DA, HU_O_DA)
#define HU_ODI      UP(HU_o_DI, HU_O_DI)
#define HU_UAC      UP(HU_u_AC, HU_U_AC)
#define HU_UDA      UP(HU_u_DA, HU_U_DA)
#define HU_UDI      UP(HU_u_DI, HU_U_DI)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_GALLIUM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
     KC_B    ,KC_L    ,KC_D    ,KC_C    ,KC_V,                              KC_J    ,KC_Y    ,KC_O    ,KC_U    ,KC_COMM,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     KC_N    ,KC_R    ,KC_T    ,KC_S    ,KC_G    ,                          KC_P    ,KC_H    ,KC_A    ,KC_E    ,KC_I    ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     KC_X    ,KC_Q    ,KC_M    ,KC_W    ,KC_Z    ,                          KC_K    ,KC_F    ,KC_QUOT ,KC_SLSH ,KC_DOT,
  //└────────┴────────┴────────┴────┬───┴────┬───┼────────┐       ┌────────┼───┬────┴───┬────┴────────┴────────┴────────┘
                                     L_NAV   ,    KC_SPC  ,        KC_RSFT ,    L_SYM
  //                                └────────┘   └────────┘       └────────┘   └────────┘
  ),

  [_SYM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
     KC_EXLM ,KC_AT   ,KC_HASH ,KC_DLR  ,KC_PERC ,                          KC_CIRC ,KC_AMPR ,KC_ASTR ,KC_LPRN ,KC_RPRN ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     KC_SCLN ,KC_GRV  ,KC_LBRC ,KC_RBRC ,KC_PLUS ,                          KC_MINS ,KC_PIPE ,KC_RCTL ,KC_RGUI ,KC_RALT ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     KC_DEL  ,KC_BSPC ,KC_LCBR ,KC_RCBR ,KC_EQL  ,                          KC_UNDS ,KC_QUOT ,KC_DQT  ,OS_MISC ,KC_BSLS ,
  //└────────┴────────┴────────┴────┬───┴────┬───┼────────┐       ┌────────┼───┬────┴───┬────┴────────┴────────┴────────┘
                                     _______ ,    _______ ,        _______ ,    XXXXXXX
  //                                └────────┘   └────────┘       └────────┘   └────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
     KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                          KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     KC_LALT ,KC_LGUI ,KC_LCTL ,KC_TAB  ,KC_ENT  ,                          KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RIGHT,KC_PGUP ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_BSPC ,KC_ESC  ,KC_TILDE,OS_HUN ,                          OS_FUNC ,L_MOUSE ,KC_COMM ,KC_DOT  ,KC_PGDN ,
  //└────────┴────────┴────────┴────┬───┴────┬───┼────────┐       ┌────────┼───┬────┴───┬────┴────────┴────────┴────────┘
                                     XXXXXXX ,    _______ ,        _______ ,    _______
  //                                └────────┘   └────────┘       └────────┘   └────────┘
  ),

  [_MISC] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
     QK_BOOT ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          KC_BRID ,KC_BRIU ,KC_PSCR ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,DB_TOGG ,XXXXXXX ,XXXXXXX ,                          KC_MPRV ,KC_MPLY ,KC_MNXT ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          KC_VOLD ,KC_VOLU ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //└────────┴────────┴────────┴────┬───┴────┬───┼────────┐       ┌────────┼───┬────┴───┬────┴────────┴────────┴────────┘
                                     XXXXXXX ,    XXXXXXX ,        XXXXXXX ,    XXXXXXX
  //                                └────────┘   └────────┘       └────────┘   └────────┘
  ),

  [_HUN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,HU_ODA  ,HU_UDA  ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX, HU_OAC  ,HU_UAC  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,HU_ODI  ,HU_UDI  ,XXXXXXX ,XXXXXXX  ,                         XXXXXXX ,XXXXXXX ,HU_AAC  ,HU_EAC  ,HU_IAC  ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_BSPC ,XXXXXXX ,K_SNEK  ,XXXXXXX ,                          XXXXXXX ,K_EURO  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //└────────┴────────┴────────┴────┬───┴────┬───┼────────┐       ┌────────┼───┬────┴───┬────┴────────┴────────┴────────┘
                                     XXXXXXX ,    XXXXXXX ,        _______ ,    XXXXXXX
  //                                └────────┘   └────────┘       └────────┘   └────────┘
  ),

  [_MOUSE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,MS_UP   ,MS_BTN3 ,MS_WHLU ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,MS_LEFT ,MS_DOWN ,MS_RGHT ,MS_WHLD ,                          XXXXXXX ,XXXXXXX ,KC_RCTL ,KC_RGUI ,KC_RALT ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //└────────┴────────┴────────┴────┬───┴────┬───┼────────┐       ┌────────┼───┬────┴───┬────┴────────┴────────┴────────┘
                                     MS_BTN1 ,    MS_BTN2 ,        _______ ,    XXXXXXX
  //                                └────────┘   └────────┘       └────────┘   └────────┘
  ),

  [_FUNC] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
     KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,                          XXXXXXX ,XXXXXXX ,KC_RCTL ,KC_RGUI ,KC_RALT ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     KC_F11  ,KC_F12  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //└────────┴────────┴────────┴────┬───┴────┬───┼────────┐       ┌────────┼───┬────┴───┬────┴────────┴────────┴────────┘
                                     XXXXXXX ,    XXXXXXX ,        XXXXXXX ,    XXXXXXX
  //                                └────────┘   └────────┘       └────────┘   └────────┘
  ),

  [_LT_MAC] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,HU_ODA  ,HU_UDA  ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX, HU_OAC  ,HU_UAC  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,HU_ODI  ,HU_UDI  ,XXXXXXX ,XXXXXXX  ,                         XXXXXXX ,XXXXXXX ,HU_AAC  ,HU_EAC  ,HU_IAC  ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_BSPC ,XXXXXXX ,K_SNEK  ,XXXXXXX ,                          XXXXXXX ,K_EURO  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //└────────┴────────┴────────┴────┬───┴────┬───┼────────┐       ┌────────┼───┬────┴───┬────┴────────┴────────┴────────┘
                                     XXXXXXX ,    XXXXXXX ,        _______ ,    XXXXXXX
  //                                └────────┘   └────────┘       └────────┘   └────────┘
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!update_flow(keycode, record->event.pressed, record->event.key)) return false;

    return true;
}

void matrix_scan_user(void) {
    flow_matrix_scan();
}

layer_state_t layer_state_set_user(layer_state_t state) {
   return update_tri_layer_state(state, _SYM, _NAV, _LT_MAC);
}
