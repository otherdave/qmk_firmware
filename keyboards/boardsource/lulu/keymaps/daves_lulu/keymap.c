// Copyright 2022 Cole Smith <cole@boadsource.xyz>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _RAISE,
    _LOWER,
    _ADJUST
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM ow_combo[] = {KC_O, KC_W, COMBO_END};
const uint16_t PROGMEM om_combo[] = {KC_O, KC_M, COMBO_END};

combo_t key_combos[] = {
    COMBO(ow_combo, QK_MAGIC_SWAP_CTL_GUI),
    COMBO(om_combo, QK_MAGIC_UNSWAP_CTL_GUI)
  };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /BackSP /       \Space \  |RAISE |Enter | RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_LCTL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                          KC_LALT,    KC_LGUI, LOWER, KC_BSPC, KC_SPC,   RAISE,   KC_ENT, KC_RGUI
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F12 |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  | F9   | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   <- |   |  |   ^  |   -> |      |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |   _  |   +  |   {  |   }  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______,_______, _______, _______,
  KC_GRV, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                    KC_LEFT, KC_DOWN, KC_UP  ,KC_RIGHT,_______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
                             _______, _______, _______, _______, _______,  _______, _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |MOD   | MODR |  S+  |  S-  |  B+  |  B-  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|RM_TOGG|    |    ]  |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  RM_NEXT, RM_PREV, RM_SATU, RM_SATD, RM_VALU, RM_VALD,                     RM_HUEU, RM_HUED, _______, _______, _______, _______,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                       XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   RM_TOGG, _______,  KC_PLUS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, RM_HUEU, RM_SATU, RM_VALU, RM_SPDU, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RM_HUED, RM_SATD, RM_VALD, RM_SPDD, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

os_variant_t current_os = OS_UNSURE;
bool flip_flop = true;
bool flip_flop2 = true;

bool process_detected_host_os_kb(os_variant_t detected_os) {
    flip_flop = !flip_flop;

    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }

    current_os = detected_os;
    return true;
}

void render_os(void){
    flip_flop2 = !flip_flop2;
    switch (current_os) {
        case OS_MACOS:
        case OS_IOS:
            oled_write_P(PSTR("MAC"), false);
            break;
        case OS_WINDOWS:
            oled_write_P(PSTR("WIN"), false);
            break;
        case OS_LINUX:
            oled_write_P(PSTR("LIN"), false);
            break;
        case OS_UNSURE:
            oled_write_P(PSTR("???"), false);
            break;
    }
    if (flip_flop)
        oled_write_ln_P(PSTR("..."), false);
    else
        oled_write_ln_P(PSTR("###"), false);
    if (flip_flop2)
        oled_write_ln_P(PSTR(",,,"), false);
    else
        oled_write_ln_P(PSTR("@@@"), false);

    return ;
}

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        153,154,10,
        185,186,0
    };

    oled_write_P(qmk_logo, false);
}

void render_default_layer_state(void) {
    oled_write_P(PSTR("Layer"), false);
    oled_write_P(PSTR(" "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("QRTY"), false);
            break;
        case _LOWER:
            oled_write_ln_P(PSTR("LOW"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("HIGH"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("ADJ"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
    }
}

void render_keylock_status(led_t led_state) {
    oled_write_ln_P(PSTR("Lock"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("N"), led_state.num_lock);
    oled_write_P(PSTR("C"), led_state.caps_lock);
    oled_write_ln_P(PSTR("S"), led_state.scroll_lock);
}

void render_mod_status(uint8_t modifiers) {
    oled_write_ln_P(PSTR("Mods"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("S"), (modifiers & MOD_MASK_SHIFT));
    oled_write_P(PSTR("C"), (modifiers & MOD_MASK_CTRL));
    oled_write_P(PSTR("A"), (modifiers & MOD_MASK_ALT));
    oled_write_P(PSTR("G"), (modifiers & MOD_MASK_GUI));
}

void render_status_main(void) {
    // Show keyboard layout
    render_default_layer_state();
    // Add a empty line
    oled_write_P(PSTR("-----"), false);

    // Show host keyboard led status
    //render_keylock_status(host_keyboard_led_state());
    // Add a empty line
    //oled_write_P(PSTR("-----"), false);

    // Show modifier status
    render_mod_status(get_mods());

    oled_write_P(PSTR("-----"), false);
    uint8_t m = rgb_matrix_get_mode();
    char buffer[12];
    sprintf(buffer, "E:%d", m);
    oled_write_ln_P(PSTR(buffer), false);
    oled_write_P(PSTR("-----"), false);

    char colBuf[6];
    uint8_t hue = rgb_matrix_get_hue();
    uint8_t sat = rgb_matrix_get_sat();
    uint8_t val = rgb_matrix_get_val();
    sprintf(colBuf, "H:%d", hue);
    oled_write_ln_P(PSTR(colBuf), false);
    sprintf(colBuf, "S:%d", sat);
    oled_write_ln_P(PSTR(colBuf), false);
    sprintf(colBuf, "V:%d", val);
    oled_write_ln_P(PSTR(colBuf), false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status_main();
    } else {
        render_logo();
        oled_write_ln_P(PSTR("-"), false);
        render_os();
        oled_write_ln_P(PSTR("-"), false);
        render_os();

        uint8_t m = get_current_wpm();
        char buffer[12];
        sprintf(buffer, "w: %d", m);
        oled_write_ln_P(PSTR(buffer), false);
    }
    return false;
}

#endif // OLED_ENABLE


// Rotary encoder related code
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { // Encoder on master side
        if(IS_LAYER_ON(_RAISE)) { // on Raise layer
            // Cursor control
            if (clockwise) {
                tap_code(KC_MNXT);
            } else {
                tap_code(KC_MPRV);
            }
        }
        else {
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        }
    }
    else if (index == 1) { // Encoder on slave side
        if(IS_LAYER_ON(_LOWER)) { // on Lower layer
            //
            if (clockwise) {
                tap_code(KC_RIGHT);
            } else {
                tap_code(KC_LEFT);
            }
        }
        else {
            if (clockwise) {
                tap_code(KC_DOWN);
            } else {
                tap_code(KC_UP);
            }
        }
    }
    return true;
}
#endif
