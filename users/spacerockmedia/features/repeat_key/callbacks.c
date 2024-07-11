

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    bool shifted = (mods & MOD_MASK_SHIFT);  // Was Shift held?
    bool controlled = (mods & MOD_MASK_CTRL);
    switch (keycode) {
        case KC_Y & controlled: return C(KC_Z);  // Ctrl + Y reverses to Ctrl + Z.
        case KC_Z & controlled: return C(KC_Y);  // Ctrl + Z reverses to Ctrl + Y.
        case KC_TAB:
            if (shifted) {      // If the last key was Shift + Tab,
                return KC_TAB;    // ... the reverse is Tab.
            } else {            // Otherwise, the last key was Tab,
                return S(KC_TAB); // ... and the reverse is Shift + Tab.
            }
        return true;
    }

    return KC_TRNS;  // Defer to the defaults.
}
