#pragma once

#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR 	    // Sets the default mode, if none has been set
#define RGB_MATRIX_DEFAULT_HUE 180  //purple  alphas with green background when pressed.
// #define RGBLIGHT_HUE_STEP 12        						// Units to step when in/decreasing hue
// #define RGBLIGHT_SAT_STEP 25        						// Units to step when in/decreasing saturation
// #define RGBLIGHT_VAL_STEP 12        						// Units to step when in/decreasing value (brightness)
// #define RGB_DISABLE_WHEN_USB_SUSPENDED 			// turn off effects when suspended
// #define RGB_MATRIX_LED_PROCESS_LIMIT (RGB_MATRIX_LED_COUNT + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
// #define RGB_MATRIX_LED_FLUSH_LIMIT 16 					// limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
#undef RGBLIGHT_EFFECT_ALTERNATING     					// Enable alternating animation mode.
#undef RGBLIGHT_EFFECT_BREATHING
