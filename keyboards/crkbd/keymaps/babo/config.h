// generated from users/manna-harbour_miryoku/miryoku.org  -*- buffer-read-only: t -*-

#pragma once

#define EE_HANDS

// default but important
#undef TAPPING_TERM
#define TAPPING_TERM 200

#define PERMISSIVE_HOLD

#if defined(KEYBOARD_crkbd_rev4_1_standard)
#define LAYOUT_miryoku( \
       K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09, \
       K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19, \
       K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29, \
       N30,   N31,   K32,   K33,   K34,   K35,   K36,   K37,   N38,   N39 \
) \
LAYOUT_split_3x6_3_ex2( \
DT_PRNT, K00,   K01,   K02,   K03,   K04,   KC_NO,   KC_NO, K05,   K06,   K07,   K08,   K09,   DT_UP,  \
KC_LSFT, K10,   K11,   K12,   K13,   K14,   KC_NO,   KC_NO, K15,   K16,   K17,   K18,   K19,   KC_RSFT, \
KC_NO,   K20,   K21,   K22,   K23,   K24,                   K25,   K26,   K27,   K28,   K29,   DT_DOWN, \
                       K32,   K33,   K34,                   K35,   K36,   K37 \
)
#else
#define LAYOUT_miryoku( \
       K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09, \
       K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19, \
       K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29, \
       N30,   N31,   K32,   K33,   K34,   K35,   K36,   K37,   N38,   N39 \
) \
LAYOUT( \
DT_PRNT, K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   DT_UP,  \
KC_LSFT, K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19,   KC_RSFT, \
KC_NO,   K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29,   DT_DOWN, \
                       K32,   K33,   K34,   K35,   K36,   K37 \
)
#endif
