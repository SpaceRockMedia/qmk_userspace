
#include QMK_KEYBOARD_H

#include "features/layers/process_records.h"

#ifdef HAPTIC_ENABLE
#    include "drivers/haptic/drv2605l.h"
#endif

bool process_record_features_layers(uint16_t keycode, keyrecord_t *record) {

    //
    // Deactivte NAV layer if a non nav key is pressed
    if (get_highest_layer(layer_state | default_layer_state) == _NAV) {
        if (record->event.pressed) {
            // if one of the keys below is not pressed then disable _NAV
            switch (keycode) {
                case LY_ADJ:
                // navs
                case KC_PGUP:
                case KC_PGDN:
                case KC_LEFT:
                case KC_RIGHT:
                case KC_DOWN:
                case KC_UP:
                case M_LEFT:
                case M_RIGHT:
                case M_DOWN:
                case M_UP:
                // nums
                case KC_ASTR:
                case KC_SLSH:
                case KC_0:
                case KC_1:
                case KC_2:
                case KC_3:
                case KC_4:
                case KC_5:
                case KC_6:
                case KC_7:
                case KC_8:
                case KC_9:
                case KC_PLUS:
                case KC_MINS:
                case KC_DOT:
                    return true;
                default:
                    layer_off(_NAV);
                    return true;
            }
        }
    }

    switch (keycode) {
        case TG_DEF:
            if (record->event.pressed) {
                layer_clear();
                if (IS_LAYER_ON(_QWERTY)) {
                    set_single_persistent_default_layer(_COLEMAK);
                    layer_move(_COLEMAK);
                } else {
                    set_single_persistent_default_layer(_QWERTY);
                    layer_move(_QWERTY);
                }
                #ifdef HAPTIC_ENABLE
                  drv2605l_pulse(DRV2605L_EFFECT_TRANSITION_HUM_1_100);
                #endif // HAPTIC_ENABLE
            }
            return false;
        case LY_DEF:
            if (record->event.pressed) {
                if (IS_LAYER_ON(_QWERTY)) {
                    layer_clear();
                    layer_move(_QWERTY);
                } else {
                    layer_clear();
                    layer_move(_COLEMAK);
                }
                #ifdef HAPTIC_ENABLE
                  drv2605l_pulse(DRV2605L_EFFECT_TRANSITION_HUM_1_100);
                #endif // HAPTIC_ENABLE
            }
            return false;
    }

    return true;
}
