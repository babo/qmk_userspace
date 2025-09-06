/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

#pragma once

#define EE_HANDS

// If you are using an Elite C rev3 on the slave side, uncomment the lines below:
#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 2000
// #define NO_USB_STARTUP_CHECK
#define WAIT_FOR_USB

#ifdef LOCKING_SUPPORT_ENABLE
    #undef LOCKING_SUPPORT_ENABLE
#endif

#ifdef LOCKING_RESYNC_ENABLE
    #undef LOCKING_RESYNC_ENABLE
#endif

// clang-format off
#define LAYOUT_miryoku( \
       K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09, \
       K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19, \
       K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29, \
       N30,   N31,   K32,   K33,   K34,   K35,   K36,   K37,   N38,   N39 \
) LAYOUT( \
       KC_NO, K00,   K01,   K02,   K03,   K04,                               K05,   K06,   K07,   K08,   K09, KC_NO, \
       KC_NO, K10,   K11,   K12,   K13,   K14,                               K15,   K16,   K17,   K18,   K19, KC_NO, \
       KC_NO, K20,   K21,   K22,   K23,   K24,   KC_NO, KC_NO, KC_NO, KC_NO, K25,   K26,   K27,   K28,   K29, KC_NO, \
              N30,   N31,   K32,   K33,   K34,                               K35,   K36,   K37,   N38,   N39 \
    )
// clang-format on
