// Copyright 2021 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "spacerockmedia.h"

// Determine the current tap dance state
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        return TD_DOUBLE_TAP;
    } else {
        return TD_UNKNOWN;
    }
}

// Initialize tap structute associated with example tap dance key
static td_tap_t ql_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// Functions that control what our tap dance key does
// void HYP_NAV_finished(tap_dance_state_t *state, void *user_data) {
//     ql_tap_state.state = cur_dance(state);
//     switch (ql_tap_state.state) {
//         case TD_SINGLE_TAP:
//             // Check to see if the layer is already set
//             if (layer_state_is(_NAV)) {
//                 // If already set, then switch it off
//                 layer_off(_NAV);
//             } else {
//                 // If not already set, then switch the layer on
//                 layer_on(_NAV);
//             }
//             break;
//         case TD_SINGLE_HOLD:
//             register_code16(KC_HYPR);
//             break;
//         default:
//             break;
//     }
// }

// void HYP_NAV_reset(tap_dance_state_t *state, void *user_data) {
//     // If the key was held down and now is released then switch off the layer
//     if (ql_tap_state.state == TD_SINGLE_HOLD) {
//         unregister_code16(_NAV);
//     }
//     ql_tap_state.state = TD_NONE;
// }

// Functions that control what our tap dance key does
// void MEH_SYM_finished(tap_dance_state_t *state, void *user_data) {
//     ql_tap_state.state = cur_dance(state);
//     switch (ql_tap_state.state) {
//         case TD_SINGLE_TAP:
//             // Check to see if the layer is already set
//             if (layer_state_is(_SYM)) {
//                 // If already set, then switch it off
//                 layer_off(_SYM);
//             } else {
//                 // If not already set, then switch the layer on
//                 layer_on(_SYM);
//             }
//             break;
//         case TD_SINGLE_HOLD:
//             register_code16(KC_MEH);
//             break;
//         default:
//             break;
//     }
// }

// void MEH_SYM_reset(tap_dance_state_t *state, void *user_data) {
//     // If the key was held down and now is released then switch off the layer
//     if (ql_tap_state.state == TD_SINGLE_HOLD) {
//         unregister_code16(KC_MEH);
//     }
//     ql_tap_state.state = TD_NONE;
// }

// ┌─────────────────────────────────────────────────┐
// │ T A P S :  l a y e r s                          │
// └─────────────────────────────────────────────────┘

