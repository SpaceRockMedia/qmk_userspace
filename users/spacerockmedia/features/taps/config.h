// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "features/taps/process_records.h"
#include "features/taps/tap_dances.h"



#ifdef TAPPING_TERM
#   undef TAPPING_TERM
#endif
#define TAPPING_TERM 250
#define TAPPING_TERM_PER_KEY

/* Miryoku */
// https://github.com/manna-harbour/qmk_firmware/pull/56

// https://docs.qmk.fm/#/tap_hold?id=tap-or-hold-decision-modes
// The PERMISSIVE_HOLD option is not noticeable if you also enable
// HOLD_ON_OTHER_KEY_PRESS because the latter option considers both the "nested
// tap" and "rolling press" sequences like shown above as a hold action, not the
// tap action. HOLD_ON_OTHER_KEY_PRESS makes the Tap-Or-Hold decision earlier in
// the chain of key events, thus taking a precedence over PERMISSIVE_HOLD.
#define PERMISSIVE_HOLD
// #define PERMISSIVE_HOLD_PER_KEY

// https://docs.qmk.fm/#/tap_hold?id=hold-on-other-key-press
// #define HOLD_ON_OTHER_KEY_PRESS
// #define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

// #define RETRO_TAPPING
// #define RETRO_TAPPING_PER_KEY

#define QUICK_TAP_TERM_PER_KEY

// Our custom TD keys
enum {
    TD_LSFT_NUM,
    TD_RSFT_NAV
};

// Tap Dance States
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

// Tap dance status
typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

// Record if is tap action
typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data);

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data);

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }


#include "features/taps/taps.h"
