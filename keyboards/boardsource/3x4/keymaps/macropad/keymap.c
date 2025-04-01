// Copyright 2022 @waffle87
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

// Hitting the keys at the top-right / bottom-left
// corners will put it into boot mode.
//const uint16_t PROGMEM flash_combo[] = {KC_RSFT, KC_RCTL, KC_K, KC_E, COMBO_END};
const uint16_t PROGMEM flash_combo[] = {RCS(KC_K), RCS(KC_E), COMBO_END};
const uint16_t PROGMEM teams_to_anki_combo[] = {RCS(KC_M), RCS(KC_E), COMBO_END};
const uint16_t PROGMEM anki_to_teams_combo[] = {KC_1, KC_SPC, COMBO_END};


const int layer_hues[] = {169, 85};



combo_t key_combos[] = {
    COMBO(flash_combo, QK_BOOT),
    COMBO(teams_to_anki_combo, DF(1)),
    COMBO(anki_to_teams_combo, DF(0))
  };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    // 0 - MS Teams
    // mute, video, X, raise hand
    // open chat
    // screen share, X, X, quick-toggle-mute
    RCS(KC_M), RCS(KC_O), KC_NO, RCS(KC_K),
    RCS(KC_R), KC_NO, KC_NO, KC_NO,
    RCS(KC_E), KC_NO, KC_NO, RCTL(KC_SPC)
  ),
  [1] = LAYOUT(
    // 1 - Anki
    KC_1, KC_2, KC_3, KC_4,
    KC_D, KC_D, KC_S, KC_S,
    KC_SPC, KC_SPC, KC_SPC, KC_SPC
  ),
   [2] = LAYOUT(
    _______, _______, _______, _______,
    _______, _______, _______, _______,
    _______, _______, _______, QK_BOOT
  )
};

void keyboard_post_init_user(void) {
    rgblight_sethsv_noeeprom(169, 255, 10);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING+2);
    rgblight_enable_noeeprom();
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    // Print the new default layer to debug console
    uint8_t active_layer = get_highest_layer(state);

    if (active_layer > 1)
        active_layer = 0;

    rgblight_sethsv_noeeprom(layer_hues[active_layer], 255, 10);

    return state;  // Return the new layer state
}
