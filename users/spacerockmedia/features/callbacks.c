// Copyright 2021 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "spacerockmedia.h"

#ifdef FEATURE_ACHORDION_ENABLE
#    include "features/achordion/callbacks.h"
#endif

void matrix_scan_user(void) {
    #ifdef FEATURE_ACHORDION_ENABLE
        matrix_scan_user_achordion();
    #endif
}
