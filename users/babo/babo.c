#include "hungarian.h"
#include "config.h"

#if defined (LAYOUT_miryoku)
#include "users/manna-harbour_miryoku/manna-harbour_miryoku.c"
#endif

#ifdef LAYOUT_callum
#include "callum.c"
#endif

#ifdef LAYOUT_seniply
#include "seniply.c"
#endif
