// Copyright 2021 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "spacerockmedia.h"

// TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            return 275;
        // case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            // if (QK_MOD_TAP_GET_MODS(keycode) & MOD_LGUI) {
                // return 300;
            // }
        default:
            return TAPPING_TERM;
    }
}

// RETRO_TAPPING_PER_KEY
// https://docs.qmk.fm/#/tap_hold?id=retro-tapping
// bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case LT(2, KC_SPC):
//             return true;
//         default:
//             // use retro functionality by default
//             return true;
//     }
// }

// -----------------------------------------------------------------------------
// https://docs.qmk.fm/#/tap_hold
// https://docs.qmk.fm/#/tap_hold?id=tapping-term
// -----------------------------------------------------------------------------

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    // returning `true` will auto select the hold action when another key is
    // pressed
    switch (keycode) {
        case LT(1, KC_BSPC):
            // Immediately select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}

// HOLD_ON_OTHER_KEY_PRESS_PER_KEY
// https://docs.qmk.fm/#/tap_hold?id=hold-on-other-key-press
// bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
//     // if `true` is returned with a given code, it will force use the hold action
//     // this applies if the sequence happens before the TAPPING_TERM limit
//     switch (keycode) {
//         case HRM_GUI_A:
//         case HRM_ALT_S:
//         case HRM_CTL_D:
//             // Immediately select the hold action when another key is pressed.
//             return true;
//         default:
//             // Do not select the hold action when another key is pressed.
//             return false;
//     }
// }

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t* record) {
  // If you quickly hold a tap-hold key after tapping it, the tap action is
  // repeated. Key repeating is useful e.g. for Vim navigation keys, but can
  // lead to missed triggers in fast typing. Here, returning 0 means we
  // instead want to "force hold" and disable key repeating.
    switch (keycode) {
        // Repeating is useful for Vim navigation keys.
        case HRM_SFT_J:
        case HRM_CTL_K:
        case HRM_ALT_L:
        case HRM_GUI_SCLN:
        case HRM_SFT_N:
        case HRM_CTL_E:
        case HRM_ALT_I:
        case HRM_GUI_O:
            return QUICK_TAP_TERM;  // Enable key repeating.
        default:
            return 0;  // Otherwise, force hold and disable key repeating.
    }
}
