#include QMK_KEYBOARD_H

#include "spacerockmedia.h"

/** \brief Automatically enable sniping-mode on the pointer layer. */
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER _POINTER

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#endif     // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

// #define LAYOUT_wrapper(...)   LAYOUT(__VA_ARGS__)
#define LAYOUT_wrapper(...)   LAYOUT_charybdis_3x6(__VA_ARGS__)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_wrapper(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       __LPT__, _______________QWERTY__L_TOP_______________,    _______________QWERTY__R_TOP_______________, __RPT__,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       __LPM__, _______________QWERTY__L_MID_HRM___________,    _______________QWERTY__R_MID_HRM___________, __RPM__,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       __LPB__, _______________QWERTY__L_BOT_______________,    _______________QWERTY__R_BOT_______________, __RPB__,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  ____THREE_THUMB_LEFT_____,    _TWO_THUMB_RGHT_
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [_COLEMAK] = LAYOUT_wrapper(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       __LPT__, _______________COLEMAK_L_TOP_______________,    _______________COLEMAK_R_TOP_______________, __RPT__,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       __LPM__, _______________COLEMAK_L_MID_HRM_____I_____,    _______________COLEMAK_R_MID_HRM___________, __RPM__,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       __LPB__, _______________COLEMAK_L_BOT_______________,    _______________COLEMAK_L_BOT_______________, __RPB__,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  ____THREE_THUMB_LEFT_____,    _TWO_THUMB_RGHT_
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [_NAV] = LAYOUT_wrapper(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       _______, __________________NAV__LT__________________,    _______, _______, _______, _______, _______, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, __________________NAV__LM__________________,    _______, _______________SCAG_______________, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, _______, _______,    _______, _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [_NUM] = LAYOUT_wrapper(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       _______, _______, _______, _______, _______, _______,    ________________NUM_PAD_TOP________________, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, _______________GACS_______________, _______,    ________________NUM_PAD_MID________________, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, _______, _______, _______, _______, _______,    ________________NUM_PAD_BOT________________, _______,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, _______, _______,    _______, _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [_ADJUST] = LAYOUT_wrapper(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       _______, __________________RGB_TOP__________________,    _______, _______, _______, _______, _______, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       QK_BOOT, __________________RGB_INC__________________,    _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, QK_BOOT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       EE_CLR,  __________________RGB_DEC__________________,    _______, _______, _______, _______, _______, EE_CLR,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, _______, _______,    _______, _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),


  [_POINTER] = LAYOUT_wrapper(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       _______, _______________POINTER_L_TOP_______________,    _______________POINTER_R_TOP_______________, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, _______________POINTER_L_MID_______________,    _______________POINTER_R_MID_______________, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, _______________POINTER_R_BOT_______________,    _______________POINTER_R_BOT_______________, _______,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______MOUSE_LEFT________,    __MOUSE_RIGHT___
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
};
// clang-format on
#ifdef POINTING_DEVICE_ENABLE
#    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
        if (auto_pointer_layer_timer == 0) {
            layer_on(_POINTER);
#        ifdef RGB_MATRIX_ENABLE
            rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
            rgb_matrix_sethsv_noeeprom(HSV_GREEN);
#        endif // RGB_MATRIX_ENABLE
        }
        auto_pointer_layer_timer = timer_read();
    }
    return mouse_report;
}

void matrix_scan_user(void) {
    if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
        auto_pointer_layer_timer = 0;
        layer_off(_POINTER);
#        ifdef RGB_MATRIX_ENABLE
        rgb_matrix_mode_noeeprom(RGB_MATRIX_DEFAULT_MODE);
#        endif // RGB_MATRIX_ENABLE
    }
}
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif
