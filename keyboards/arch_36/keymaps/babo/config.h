#pragma once

#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
#endif

#ifdef RGBLIGHT_ENABLE
  // #define RGBLIGHT_ANIMATIONS
  #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
#endif

#define LAYOUT_miryoku( \
       K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09, \
       K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19, \
       K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29, \
       N30,   N31,   K32,   K33,   K34,   K35,   K36,   K37,   N38,   N39 \
) \
LAYOUT_split_3x5_3( \
    K00,   K01,   K02,   K03,   K04,      K05,   K06,   K07,   K08,   K09, \
    K10,   K11,   K12,   K13,   K14,      K15,   K16,   K17,   K18,   K19, \
    K20,   K21,   K22,   K23,   K24,      K25,   K26,   K27,   K28,   K29, \
                  K32,   K33,   K34,      K35,   K36,   K37    \
)

#undef TAPPING_TERM
#define TAPPING_TERM 220
#define PERMISSIVE_HOLD

#define COMBO_VARIABLE_LEN
#define COMBO_TERM 50

#define UNICODE_SELECTED_MODES UC_MAC, UC_LNX, UC_WINC
