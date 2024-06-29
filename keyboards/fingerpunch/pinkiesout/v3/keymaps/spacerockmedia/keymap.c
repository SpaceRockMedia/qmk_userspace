#include QMK_KEYBOARD_H
#include "spacerockmedia.h"

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_QWERTY] = LAYOUT_pinkiesout(
    __LPN__, ____________________FN_ROW_LEFT_____________________,                    ____________________FN_ROW_RIGHT____________________, __RPN__,
    __LPT__, _______________QWERTY__L_TOP_______________, KC_LBRC,                    KC_RBRC, _______________QWERTY__R_TOP_______________, __RPT__,
    __LPM__, _______________QWERTY__L_TOP_______________, KC_LCBR,                    KC_RCBR, _______________QWERTY__R_MID_______________, __RPM__,
    __LPB__, _______________COLEMAK_L_BOT_______________, LY_ADJ,                     LY_ADJ,  _______________QWERTY__R_BOT_______________, __RPB__,
                      KC_LCTL,  KC_LGUI, _______THUMB_LEFT________,   LF_ENC, RT_ENC, _______THUMB_RIGHT_______,  KC_RGUI,  KC_RCTL
),


[_COLEMAK] = LAYOUT_pinkiesout(
    __LPN__, ____________________FN_ROW_LEFT_____________________,                   ____________________FN_ROW_RIGHT____________________, __RPN__,
    __LPT__, _______________COLEMAK_L_TOP_______________, KC_LBRC,                   KC_RBRC, _______________COLEMAK_R_TOP_______________, __RPT__,
    __LPM__, _______________COLEMAK_L_MID_______________, KC_LCBR,                   KC_RCBR, _______________COLEMAK_R_MID_______________, __RPM__,
    __LPB__, _______________COLEMAK_L_BOT_______________, LY_ADJ,                    LY_ADJ,  _______________QWERTY__L_BOT_______________, __RPB__,
                       C_LCTL, KC_LGUI, _______THUMB_LEFT________, _______, _______, _______THUMB_RIGHT_______, KC_RGUI,KC_RCTL
),

[_NAV] = LAYOUT_pinkiesout(
    KC_GRV,  ____________________NUM_ROW_LEFT____________________,                   ____________________NUM_ROW_RIGHT___________________, _______,
    _______, __________________NAV__LT__________________, _______,                   _______, ________________NUM_PAD_TOP________________, SH_TOGG,
    _______, __________________NAV__LM__________________, _______,                   _______, ________________NUM_PAD_MID________________, _______,
    _______, _______, _______, _______, _______, _______, _______,                   _______, ________________NUM_PAD_BOT________________, _______,
                               _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),


[_MEDIA] = LAYOUT_pinkiesout(
    KC_GRV,  ____________________NUM_ROW_LEFT____________________,                   ____________________NUM_ROW_RIGHT___________________, _______,
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
                               _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_ADJUST] =  LAYOUT_pinkiesout(
    QK_BOOT, ____________________NUM_ROW_LEFT____________________,                   ____________________NUM_ROW_RIGHT___________________, _______,
    _______, RGB_TOG, _______, _______, _______, _______, TG(_QWERTY),               _______, _______, _______, _______, _______, _______, _______,
    _______, __________________RGB_INC__________________, TG(_COLEMAK),              _______, _______, _______, _______, _______, _______, _______,
    QK_BOOT, __________________RGB_DEC__________________, _______,                   _______, _______, _______, _______, _______, _______, _______,
                               _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)
};

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case LOWER:
//             if (record->event.pressed) {
//                 layer_on(_MEDIA);
//                 update_tri_layer(_MEDIA, _NAV, _ADJUST);
//             } else {
//                 layer_off(_MEDIA);
//                 update_tri_layer(_MEDIA, _NAV, _ADJUST);
//             }
//             return false;
//             break;
//         case RAISE:
//             if (record->event.pressed) {
//                 layer_on(_NAV);
//                 update_tri_layer(_MEDIA, _NAV, _ADJUST);
//             } else {
//                 layer_off(_NAV);
//                 update_tri_layer(_MEDIA, _NAV, _ADJUST);
//             }
//             return false;
//             break;
//         case ADJUST:
//             if (record->event.pressed) {
//                 layer_on(_ADJUST);
//             } else {
//                 layer_off(_ADJUST);
//             }
//             return false;
//             break;
//         default:
//             break;
//     }

//     return true;
// }
