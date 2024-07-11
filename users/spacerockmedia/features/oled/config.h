// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#if defined(WPM_ENABLE)
    // #define WPM_LAUNCH_CONTROL
    // #define WPM_UNFILTERED
    #define WPM_ALLOW_COUNT_REGRESSION
    #define WPM_SAMPLE_SECONDS 10
    #define WPM_SAMPLE_PERIODS 50
    #define WPM_ESTIMATED_WORD_SIZE 5
#endif

#ifndef OLED_UPDATE_INTERVAL
#    ifdef SPLIT_KEYBOARD
#        define OLED_UPDATE_INTERVAL 60
#    elif defined(OLED_DISPLAY_128X128)
#        define OLED_UPDATE_INTERVAL 30
#    else
#        define OLED_UPDATE_INTERVAL 15
#    endif
#endif
#define OLED_DISABLE_TIMEOUT

#undef OLED_FONT_H
// #define OLED_FONT_H "features/oled/fonts/drashna.h"
// klor font
#define OLED_FONT_H  "features/oled/fonts/klor.c"
// #define OLED_FONT_END 255
// #    define OLED_FONT_5X5
// #    define OLED_FONT_AZTECH
// #    define OLED_FONT_BMPLAIN
// #    define OLED_FONT_CRACKERS
// #define OLED_FONT_DEAD_MEAL
// #    define OLED_FONT_EIN
// #    define OLED_FONT_HISKYF21
// #    define OLED_FONT_SQUASH
// #    define OLED_FONT_ZXPIX
// #    define OLED_FONT_SUPER_DIGG

// #    define OLED_LOGO_BEBOP
// #    define OLED_LOGO_CORNE
// #    define OLED_LOGO_GMK_BAD
// #    define OLED_LOGO_GOTHAM
// #    define OLED_LOGO_HUE_MANITEE
// #    define OLED_LOGO_LOOSE
// #define OLED_LOGO_SCIFI
// #    define OLED_LOGO_SETS3N
// #    define OLED_LOGO_SKEEB
