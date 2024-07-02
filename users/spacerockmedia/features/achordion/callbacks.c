#include "spacerockmedia.h"
#include "features/achordion/achordion.h"
#include "features/achordion/callbacks.h"

void matrix_scan_user_achordion(void) {
        achordion_task();
}

// The default definition of achordion_chord() returns true if the two keys are
// on opposite hands, producing an effect like Bilateral Combinations
bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
  return achordion_opposite_hands(tap_hold_record, other_record);
}

bool achordion_eager_mod(uint8_t mod) {
  switch (mod) {
    case MOD_LSFT:
    case MOD_RSFT:
    case MOD_LCTL:
    case MOD_RCTL:
      return true;  // Eagerly apply Shift and Ctrl mods.

    default:
      return false;
  }
}


uint16_t achordion_streak_chord_timeout(uint16_t tap_hold_keycode, uint16_t next_keycode) {
  if (IS_QK_LAYER_TAP(tap_hold_keycode)) {
    return 0;  // Disable streak detection on layer-tap keys.
  }

  // Otherwise, tap_hold_keycode is a mod-tap key.
  uint8_t mod = mod_config(QK_MOD_TAP_GET_MODS(tap_hold_keycode));
  if ((mod & MOD_LSFT) != 0) {
    return 100;  // A shorter streak timeout for Shift mod-tap keys.
  } else {
    return TAPPING_TERM;  // A longer timeout otherwise.
  }
}
