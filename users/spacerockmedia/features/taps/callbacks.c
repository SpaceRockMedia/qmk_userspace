// Copyright 2021 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

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

// Quick Tap Term
// https://docs.qmk.fm/tap_hold#quick-tap-term
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


void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}
