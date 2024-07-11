// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#ifdef SPLIT_KEYBOARD
#    include "features/split/config.h"
#endif

// Tapping
#ifdef TAP_DANCE_ENABLE
#    include "features/taps/config.h"
#endif

#ifdef COMBO_ENABLE
#    include "features/combos/config.h"
#endif

#ifdef LEADER_ENABLE
#    include "features/leader/config.h"
#endif

#ifdef AUDIO_ENABLE
#    include "features/audio/config.h"
#endif

#ifdef OLED_ENABLE
#    include "features/oled/config.h"
#endif

#ifdef CAPS_WORD_ENABLE
#    include "features/caps_word/config.h"
#endif

#ifdef RGB_MATRIX_ENABLE
#    include "features/rgb/config.h"
#endif

#ifdef POINTING_DEVICE_ENABLE
#    include "features/pointing/config.h"
#endif

#ifdef FEATURE_ACHORDION_ENABLE
#    include "features/achordion/config.h"
#endif
