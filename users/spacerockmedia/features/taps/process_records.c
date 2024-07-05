// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "spacerockmedia.h"

#include "features/taps/config.h"
#include "features/taps/process_records.h"

bool process_record_features_taps(uint16_t keycode, keyrecord_t* record) {
    tap_dance_action_t *action;

    switch (keycode) {
        case TD(TD_LSFT_NUM):  // list all tap dance keycodes with tap-hold configurations
            action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
    }
    return true;
}
