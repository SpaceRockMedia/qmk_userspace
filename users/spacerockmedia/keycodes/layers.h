// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
#include QMK_KEYBOARD_H

typedef enum userspace_layers {
    _QWERTY = 0,
    _COLEMAK,
    _NAV,
    _NUM,
    _ADJUST,
    _WIN,
} CUSTOM_LAYERS_T;
