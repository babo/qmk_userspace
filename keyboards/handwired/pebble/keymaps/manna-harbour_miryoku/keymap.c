#include "pebble.h"

#define LAYOUT_miryoku( \
    K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09, \
    K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19, \
    K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29, \
    N30,   N31,   K32,   K33,   K34,   K35,   K36,   K37,   N38,   N39 \
) \
LAYOUT( \
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  \
    KC_NO, K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   KC_NO, \
    KC_LSFT, K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19,   KC_RSFT, \
    KC_NO, K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29,   KC_NO, \
    KC_NO, K32,   K33,   K34,   K35,   K36,   K37,   KC_NO \
)

#include "manna-harbour_miryoku.c"
