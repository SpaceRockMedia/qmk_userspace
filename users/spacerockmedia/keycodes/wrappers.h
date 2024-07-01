// Copyright 2023 Shawn McElroy, aka Autoferrit  (@autoferrit)
// Copyright 2023 @autoferrit
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
#include "spacerockmedia.h"
/*
Since our quirky block definitions are basically a list of comma separated
arguments, we need a wrapper in order for these definitions to be
expanded before being used as arguments to the LAYOUT_xxx macro.
*/

/*
Blocks for each of the four major keyboard layouts
Organized so we can quickly adapt and modify all of them
at once, rather than for each keyboard, one at a time.
And this allows for much cleaner blocks in the keymaps.
For instance Tap/Hold for Control on all of the layouts

NOTE: These are all the same length.  If you do a search/replace
  then you need to add/remove underscores to keep the
  lengths consistent.
*/

// QWERTY
#define HRM_GUI_A    LGUI_T(KC_A)
#define HRM_ALT_S    LALT_T(KC_S)
#define HRM_CTL_D    LCTL_T(KC_D)
#define HRM_SFT_F    LSFT_T(KC_F)
#define HRM_SFT_J    RSFT_T(KC_J)
#define HRM_CTL_K    RCTL_T(KC_K)
#define HRM_ALT_L    RALT_T(KC_L)
#define HRM_GUI_SCLN RGUI_T(KC_SCLN)

// COLEMAK
#define HRM_ALT_R    LALT_T(KC_R)
#define HRM_CTL_S    LCTL_T(KC_S)
#define HRM_SFT_T    LSFT_T(KC_T)
#define HRM_SFT_N    RSFT_T(KC_N)
#define HRM_CTL_E    RCTL_T(KC_E)
#define HRM_ALT_I    RALT_T(KC_I)
#define HRM_GUI_O    RGUI_T(KC_O)


#define __________COLEMAK_GACS___________ HRM_GUI_A, HRM_ALT_R, HRM_CTL_S, HRM_SFT_T
#define __________COLEMAK_SCAG___________ HRM_SFT_N, HRM_CTL_E, HRM_ALT_I, HRM_GUI_O
#define ___________QWERTY_GACS___________ HRM_GUI_A, HRM_ALT_S, HRM_CTL_D, HRM_SFT_F
#define ___________QWERTY_SCAG___________ HRM_SFT_J, HRM_CTL_K, HRM_ALT_L, HRM_GUI_SCLN

// clang-format off
#define _______________QWERTY__L_TOP_______________ KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _______________QWERTY__L_MID_______________ KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _______________QWERTY__L_MID_HRM___________ ___________QWERTY_GACS___________,  KC_G
#define _______________QWERTY__L_BOT_______________ KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _______________QWERTY__R_TOP_______________ KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _______________QWERTY__R_MID_______________ KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _______________QWERTY__R_MID_HRM___________ KC_H, ___________QWERTY_SCAG___________
#define _______________QWERTY__R_BOT_______________ KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUES

#define _______________COLEMAK_L_TOP_______________ KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#define _______________COLEMAK_L_MID_______________ KC_A,    KC_R,    KC_S,    KC_T,    KC_G
#define _______________COLEMAK_L_MID_HRM_____I_____ __________COLEMAK_GACS___________,  KC_G
#define _______________COLEMAK_L_BOT_______________ KC_Z,    KC_X,    KC_C,    KC_D,    KC_V

#define _______________COLEMAK_R_TOP_______________ KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define _______________COLEMAK_R_MID_______________ KC_M,    KC_N,    KC_E,    KC_I,    KC_O
#define _______________COLEMAK_R_MID_HRM___________ KC_M, __________COLEMAK_SCAG___________
#define _______________COLEMAK_R_BOT_______________ KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_QUES

#define _______THUMB_LEFT________                   LY_NAV, MEH_T(KC_SPC), KC_LSFT
#define _______THUMB_RIGHT_______                   KC_RSFT, MEH_T(KC_ENT), LY_NAV

#define ______FOUR_THUMB_LEFT____________           KC_LCTL, ____THREE_THUMB_LEFT_____
#define ______FOUR_THUMB_RIGHT___________           ____THREE_THUMB_RIGHT____, KC_RCTL

#define ______________FIVE_THUMB_LEFT______________ KC_LCTL, ______FOUR_THUMB_LEFT____________
#define ______________FIVE_THUMB_RIGHT_____________ ______FOUR_THUMB_RIGHT___________, KC_RCTL

#define ____________________FN_ROW_LEFT_____________________ KC_F1, KC_F2, KC_F3, KC_F4,  KC_F5,  KC_F6
#define ____________________FN_ROW_RIGHT____________________ KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12

#define ____________________NUM_ROW_LEFT____________________ KC_1, KC_2, KC_3, KC_4, KC_5,    KC_6
#define ____________________NUM_ROW_RIGHT___________________ KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQUAL

#define __________________RGB_INC__________________ RGB_MOD,  RGB_SPI, RGB_HUI, RGB_SAI, RGB_VAI
#define __________________RGB_DEC__________________ RGB_RMOD, RGB_SPD, RGB_HUD, RGB_SAD, RGB_VAD

#define __________________NAV__LT__________________ KC_PGUP, M_LEFT,  KC_UP,   M_RIGHT, M_UP
#define __________________NAV__LM__________________ KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, M_DOWN

#define ________________NUM_PAD_TOP________________ KC_ASTR,  KC_7, KC_8, KC_9, KC_PLUS
#define ________________NUM_PAD_MID________________ KC_SLSH, KC_4, KC_5, KC_6, KC_MINS
#define ________________NUM_PAD_BOT________________ KC_ASTR,  KC_7, KC_8, KC_9, KC_PLUS


#define __LPN__ KC_GRV
#define __LPT__ KC_TAB
#define __LPM__ HYPR_T(QK_LEAD)
#define __LPB__ KC_LGUI

#define __RPN__ LY_ADJ
#define __RPT__ LY_ADJ
#define __RPM__ HYPR_T(QK_LEAD)
#define __RPB__ KC_RGUI

#define LF_ENC KC_MUTE
#define RT_ENC KC_MUTE
