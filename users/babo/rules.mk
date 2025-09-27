AUTO_SHIFT_ENABLE = yes
CAPS_WORD_ENABLE = yes
EXTRAKEY_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes
MOUSEKEY_ENABLE = yes
TAP_DANCE_ENABLE = yes

INTROSPECTION_KEYMAP_C += users/manna-harbour_miryoku/manna-harbour_miryoku.c

include ${PWD}/users/manna-harbour_miryoku/custom_rules.mk
include ${PWD}/users/manna-harbour_miryoku/post_rules.mk
