// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "features/taps/taps.h"

// Initialize tap structute associated with example tap dance key
// static td_tap_t ql_tap_state = {
//     .is_press_action = true,
//     .state = TD_NONE
// };

// Function associated with all tap dances

// Functions associated with individual tap dances
// void ql_finished(tap_dance_state_t *state, void *user_data);
// void ql_reset(tap_dance_state_t *state, void *user_data);

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


// Associate our tap dance key with its functionality
tap_dance_action_t tap_dance_actions[] = {
    [TD_LSFT_NUM] = ACTION_TAP_DANCE_TAP_HOLD(TO(_NAV), KC_LSFT),
    [TD_RSFT_NAV] = ACTION_TAP_DANCE_TAP_HOLD(TO(_NUM), KC_RSFT),
};
