#include QMK_KEYBOARD_H

#include "spacerockmedia.h"

#define __________UPPER__THUMB__________ KC_HYPR, KC_MEH, KC_MEH, KC_HYPR

#define LAYOUT_wrapper(...)   LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_COLEMAK] = LAYOUT_wrapper(
    __LPT__, _______________COLEMAK_L_TOP_______________,                                   _______________COLEMAK_R_TOP_______________, __RPT__,
    __LPM__, _______________COLEMAK_L_MID_HRM_____I_____,                                   _______________COLEMAK_R_MID_HRM___________, __RPM__,
    __LPB__, _______________COLEMAK_L_BOT_______________, __________UPPER__THUMB__________, _______________COLEMAK_R_BOT_______________, __RPB__,
                                ______________FIVE_THUMB_LEFT______________, ______________FIVE_THUMB_RIGHT_____________
),

[_QWERTY] = LAYOUT_wrapper(
    __LPT__, _______________QWERTY__L_TOP_______________,                                   _______________QWERTY__R_TOP_______________, __RPT__,
    __LPM__, _______________QWERTY__L_MID_HRM___________,                                   _______________QWERTY__R_MID_HRM___________, __RPM__,
    __LPB__, _______________QWERTY__L_BOT_______________, __________UPPER__THUMB__________, _______________QWERTY__R_BOT_______________, __RPB__,
                                ______________FIVE_THUMB_LEFT______________, ______________FIVE_THUMB_RIGHT_____________
),

[_NAV] = LAYOUT_wrapper(
    SH_TOGG, __________________NAV__LT__________________,                                      _______, _______, _______, _______, _______, SH_TOGG,
    _______, __________________NAV__LM__________________,                                      _______, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, _______,
    SNAP1,   SNAP2,   _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______,
                               _______, _______, _______, LY_DEF,  _______,  _______, _______, LY_DEF,   _______, _______
),

[_NUM] = LAYOUT_wrapper(
    _______, _______, _______, _______, _______, _______,                                      ________________NUM_PAD_TOP________________, _______,
    _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                      ________________NUM_PAD_MID________________, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, ________________NUM_PAD_BOT________________, _______,
                               _______, _______, _______, LY_DEF,  _______,  _______, _______, _______, _______, _______
),

[_ADJUST] = LAYOUT_wrapper(
    TG_DEF,  RGB_TOG, xxxxxxx, xxxxxxx, xxxxxxx, OS_SWAP,                                     HF_TOGG, xxxxxxx, xxxxxxx, xxxxxxx, KC_MPLY, xxxxxxx,
    QK_BOOT, __________________RGB_INC__________________,                                     DB_TOGG, xxxxxxx, KC_MPRV, KC_MNXT, KC_VOLU, xxxxxxx,
    MAKE_H,  __________________RGB_DEC__________________, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, AU_TOGG, xxxxxxx, xxxxxxx, xxxxxxx, KC_VOLD, KC_MUTE,
                               xxxxxxx, xxxxxxx, xxxxxxx, LY_DEF,  xxxxxxx, xxxxxxx, xxxxxxx, LY_DEF,  xxxxxxx, xxxxxxx
),

[_POINTER] = LAYOUT_wrapper(
    _______, _______________POINTER_L_TOP_______________,                                     _______________POINTER_R_TOP_______________, _______,
    _______, _______________POINTER_L_MID_______________,                                     _______________POINTER_R_MID_______________, _______,
    _______, _______________POINTER_L_BOT_______________, _______, _______, _______, _______, _______________POINTER_R_BOT_______________, _______,
                               _______, _______, _______MOUSE_LEFT________, __MOUSE_RIGHT___, _______, _______, _______
),

// /*
//  * Layer template
//  *aa
//  *, -------------------------------------------.,                              -------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.,  -------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, LY_DEF,  _______, _______, _______, _______, _______, _______, _______
//     ),
};

// #if defined(ENCODER_MAP_ENABLE)
// const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
//     [_COLEMAK] = { ENCODER_CCW_CW(KC_WH_U,  KC_WH_D),   ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
//     [_QWERTY] =    { ENCODER_CCW_CW(KC_WH_U,  KC_WH_D),   ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
//     [_NAV] =     { ENCODER_CCW_CW(KC_RIGHT, KC_LEFT),   ENCODER_CCW_CW(KC_MNXT, KC_MPRV) },
//     [_SYM] =     { ENCODER_CCW_CW(RGB_HUI,  RGB_HUD),   ENCODER_CCW_CW(RGB_VAI, RGB_SAI) },
//     [_NUM] =   { ENCODER_CCW_CW(KC_MPRV,  KC_MNXT),   ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
//     [_ADJUST] =  { ENCODER_CCW_CW(RGB_MOD,  RGB_RMOD),  ENCODER_CCW_CW(RGB_SPI, RGB_SPD) },
// };
// #endif
