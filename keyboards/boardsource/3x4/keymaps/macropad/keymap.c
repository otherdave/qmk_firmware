// Copyright 2022 @waffle87
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

const uint16_t PROGMEM flash_combo[] = {KC_A, KC_M, COMBO_END};

combo_t key_combos[] = {
    COMBO(flash_combo, QK_BOOT)
  };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_1, KC_2, KC_3, KC_M,
    KC_Q, KC_W, KC_E, KC_R,
    KC_A, KC_S, KC_D, KC_F
  ),
  [1] = LAYOUT(
    _______, _______, _______, _______,
    _______, _______, _______, _______,
    _______, _______, _______, QK_BOOT
  )
};
