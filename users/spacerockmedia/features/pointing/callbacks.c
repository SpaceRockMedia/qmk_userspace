#include QMK_KEYBOARD_H
#include "features/pointing/config.h"

void pointing_device_init_user(void) {
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
}

// https://discord.com/channels/681309835135811648/872183402579767317/1152534229268303903
// bool is_mouse_record_user(uint16_t keycode, keyrecord_t* record) {
//     switch(keycode) {
//         case DRGSCRL:
//         case SNIPING:
//         case S_D_MOD:
//         case DPI_MOD:
//             return true;
//         default:
//             return false;
//     }
// }
