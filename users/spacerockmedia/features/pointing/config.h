// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "features/taps/config.h"

// in config.h:
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
// only required if not setting mouse layer elsewhere
#define AUTO_MOUSE_DEFAULT_LAYER _POINTER
// Time layer remains active after activation
// default 650
#define AUTO_MOUSE_TIME 650
// Lockout time after non-mouse key is pressed
// default 200
#define AUTO_MOUSE_DELAY TAPPING_TERM
// Amount of mouse movement required to switch layers
// default 10 units
#define AUTO_MOUSE_THRESHOLD 10
