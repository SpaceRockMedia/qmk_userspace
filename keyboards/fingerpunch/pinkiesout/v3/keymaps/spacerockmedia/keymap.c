#include QMK_KEYBOARD_H

// #include "spacerockmedia.h"

// clang-format off

typedef enum userspace_layers {
    _QWERTY = 0,
    _COLEMAK,
    _NAV,
    _NUM,
    _ADJUST,
    _WIN,
} CUSTOM_LAYERS_T;


#define LAYOUT_wrapper(...)   LAYOUT_pinkiesout(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_QWERTY] = LAYOUT_pinkiesout(
    EE_CLR,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F6,                      KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  EE_CLR,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_LBRC,                    KC_RBRC,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_P,
    KC_ESC,  KC_A,    KC_S,    KC_D,    EE_CLR,  KC_G,   KC_LCBR,                    KC_RCBR,  KC_H,    EE_CLR,  KC_K,    KC_L,    KC_SCLN, HYPR_T(QK_LEAD),
    KC_LGUI, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_LCBR,                    KC_RCBR,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUES, KC_RGUI,
             KC_LCTL, KC_LGUI, MEH_T(KC_BSPC),   KC_SPC, KC_LSFT, KC_BSPC,  KC_DEL,  KC_RSFT,  KC_ENT,  MEH_T(KC_DEL),  KC_RGUI,  KC_RCTL
),


// [_QWERTY] = LAYOUT_wrapper(
//     __LPN__, ____________________FN_ROW_LEFT_____________________,                   ____________________FN_ROW_RIGHT____________________, __RPN__,
//     __LPT__, _______________QWERTY__L_TOP_______________, KC_LBRC,                   KC_RBRC, _______________QWERTY__R_TOP_______________, __RPT__,
//     __LPM__, _______________QWERTY__L_MID_HRM___________, KC_LCBR,                   KC_RCBR, _______________QWERTY__R_MID_HRM___________, __RPM__,
//     __LPB__, _______________QWERTY__L_BOT_______________, LY_ADJ,                    LY_ADJ,  _______________QWERTY__R_BOT_______________, __RPB__,
//                      KC_LCTL,  KC_LGUI, _______THUMB_LEFT________, LF_ENC,  RT_ENC,  _______THUMB_RIGHT_______,  KC_RGUI,  KC_RCTL
// ),


// [_COLEMAK] = LAYOUT_wrapper(
//     __LPN__, ____________________FN_ROW_LEFT_____________________,                   ____________________FN_ROW_RIGHT____________________, __RPN__,
//     __LPT__, _______________COLEMAK_L_TOP_______________, KC_LBRC,                   KC_RBRC, _______________COLEMAK_R_TOP_______________, __RPT__,
//     __LPM__, _______________COLEMAK_L_MID_HRM_____I_____, KC_LCBR,                   KC_RCBR, _______________COLEMAK_R_MID_HRM___________, __RPM__,
//     __LPB__, _______________COLEMAK_L_BOT_______________, LY_ADJ,                    LY_ADJ,  _______________COLEMAK_L_BOT_______________, __RPB__,
//                       KC_LCTL, KC_LGUI, _______THUMB_LEFT________, _______, _______, _______THUMB_RIGHT_______, KC_RGUI,KC_RCTL
// ),
[_COLEMAK] =  LAYOUT_pinkiesout(
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
[_NAV] =  LAYOUT_pinkiesout(
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
[_NUM] =  LAYOUT_pinkiesout(
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
[_ADJUST] =  LAYOUT_pinkiesout(
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
[_WIN] =  LAYOUT_pinkiesout(
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

// [_NAV] = LAYOUT_wrapper(
//     KC_GRV,  ____________________NUM_ROW_LEFT____________________,                   ____________________NUM_ROW_RIGHT___________________, _______,
//     _______, __________________NAV__LT__________________, _______,                   _______, _______, _______, _______, _______, _______, SH_TOGG,
//     _______, __________________NAV__LM__________________, _______,                   _______, _______, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, _______,
//     _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
//                       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
// ),


// [_NUM] = LAYOUT_wrapper(
//     KC_GRV,  ____________________NUM_ROW_LEFT____________________,                   ____________________NUM_ROW_RIGHT___________________, _______,
//     _______, _______, _______, _______, _______, _______, _______,                   _______, ________________NUM_PAD_TOP________________, _______,
//     _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______, _______,                   _______, ________________NUM_PAD_TOP________________, _______,
//     _______, _______, _______, _______, _______, _______, _______,                   _______, ________________NUM_PAD_BOT________________, _______,
//                       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
// ),

// [_ADJUST] =  LAYOUT_wrapper(
//     QK_BOOT, ____________________NUM_ROW_LEFT____________________,                   ____________________NUM_ROW_RIGHT___________________, _______,
//     _______, RGB_TOG, _______, _______, _______, _______, TG(_QWERTY),               _______, _______, _______, _______, _______, _______, _______,
//     _______, __________________RGB_INC__________________, TG(_COLEMAK),              _______, _______, _______, _______, _______, _______, _______,
//     QK_BOOT, __________________RGB_DEC__________________, _______,                   _______, _______, _______, _______, _______, _______, _______,
//                       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
// ),

// [_WIN] =  LAYOUT_wrapper(
//     _______, ____________________NUM_ROW_LEFT____________________,                   ____________________NUM_ROW_RIGHT___________________, _______,
//     _______, _______, WS_LEFT, W_UP,    WS_RGHT, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
//     _______, _______, W_LEFT,  W_DOWN,  W_RGHT,  _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
//     _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
//                       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
// )
};
