/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _NUM,
    _EMPTY
};

// NOTE: If left and right modifiers are pressed together, they are all interpreted as right modifiers!
// TODO: Have keys that switch completely to a new layer, then the option to switch back to the base layer... fewer layers in total would be great in this case! Maybe the outermost column(s)?, maybe up/reset/leader?
// TODO: Leader key for variety of functions: <L>s[qw] to switch between VTY1,7 (in case I have wakeup problems)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Keep QC_BOOT until we have a stable system
     */
    [_BASE] = LAYOUT_split_3x6_3_ex2(
      XXXXXXX,         KC_Q,         KC_W,         KC_F,         KC_P,     KC_B, QK_BOOT,        QK_BOOT,                  KC_J,         KC_L,         KC_U,         KC_Y,      XXXXXXX, XXXXXXX,
      XXXXXXX, LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T),     KC_G, XXXXXXX,        XXXXXXX,                  KC_M, LSFT_T(KC_N), LCTL_T(KC_E), LALT_T(KC_I), LGUI_T(KC_O), XXXXXXX,
      XXXXXXX,         KC_Z,         KC_X,         KC_C,         KC_D,     KC_V,                                           KC_K,         KC_H,     KC_COMMA,       KC_DOT,      XXXXXXX, XXXXXXX,
                                                            KC_ESCAPE, KC_SPACE, XXXXXXX,       KC_ENTER, LT(_NUM,KC_BACKSPACE),    QK_LEADER
  ),
    /*
     * Shift-9 and Shift-0 provide (,) next to each other
     * TODO: Check if LSFT_T(OSM(MOD_LSFT)) is convenient: one-shot on quick press, but if held then same key but held
     */
    [_NUM] = LAYOUT_split_3x6_3_ex2(
      XXXXXXX,      XXXXXXX,    KC_7,    KC_8,    KC_9,     KC_0, XXXXXXX,    XXXXXXX, XXXXXXX, KC_HOME, KC_PAGE_UP, KC_PAGE_DOWN,   KC_END, XXXXXXX,
      XXXXXXX, KC_SEMICOLON,    KC_4,    KC_5,    KC_6, KC_EQUAL, XXXXXXX,    XXXXXXX, XXXXXXX, KC_LEFT,      KC_UP,      KC_DOWN, KC_RIGHT, XXXXXXX,
      XXXXXXX,     KC_SLASH,    KC_1,    KC_2,    KC_3, KC_MINUS,                      XXXXXXX, XXXXXXX,    _______,      _______,  XXXXXXX,  XXXXXXX,
                                      XXXXXXX, XXXXXXX,  XXXXXXX,                      XXXXXXX, XXXXXXX,    XXXXXXX
  ),
    [_EMPTY] = LAYOUT_split_3x6_3_ex2(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                 XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX
       ),
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif

const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    &delete_key_override
};


/* Leader sequences allow for vim-like command sequences
 */
void leader_end_user(void) {
    if (leader_sequence_three_keys(KC_R, KC_R, KC_B)) {
        // reboot into bootloader
        reset_keyboard();
    };
    if (leader_sequence_three_keys(KC_R, KC_R, KC_J)) {
        // reboot into bootloader
        reset_keyboard();
    };
};


// TODO: Probably need to order these better!
void rgb_matrix_per_index(uint8_t led_min, uint8_t led_max, uint8_t layer, uint8_t mods, uint8_t index, uint16_t keycode) {
    uint8_t basekey = QK_MODS_GET_BASIC_KEYCODE(keycode);
    //always set color to off first
    if (keycode > XXXXXXX) {
        rgb_matrix_set_color(index, RGB_CYAN);
    } else {
        rgb_matrix_set_color(index, RGB_OFF);
    };
    // "unmodified" characters keys (i.e no layer switch or anything fancy)
    if (keycode >= KC_A && keycode <= KC_Z) {
        rgb_matrix_set_color(index, RGB_BLUE);
    };
    // digits and others
    if (basekey >= KC_1 && basekey <= KC_0) {
        rgb_matrix_set_color(index, RGB_GREEN);
    };
    // punctuation, brackets, etc
    if (basekey >= KC_MINUS && basekey <= KC_SLASH) {
        rgb_matrix_set_color(index, RGB_TEAL);
    };
    // movements
    if (basekey >= KC_RIGHT && basekey <= KC_UP) {
        rgb_matrix_set_color(index, RGB_TURQUOISE);
    };
    // any special modifiers
    if (keycode & 0xFF00) {
        rgb_matrix_set_color(index, RGB_GOLDENROD);
    };
    // very special keys
    switch (keycode) {
        case QK_LEADER:
            rgb_matrix_set_color(index, RGB_RED);
            break;
        case QK_BOOT:
            rgb_matrix_set_color(index, RGB_WHITE);
            break;
    };
};

/*
 * Callback function that allows setting up the rgb matrix
 */

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t layer = get_highest_layer(layer_state);
    uint8_t mods = get_mods();
    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t index = g_led_config.matrix_co[row][col];
            uint16_t keycode = keymap_key_to_keycode(layer, (keypos_t){col,row});
            if (index >= led_min && index < led_max && index != NO_LED) {
                rgb_matrix_per_index(led_min, led_max, layer, mods, index, keycode);
            };
        };
    };
    /*
    if (get_highest_layer(layer_state) > 0) {
        uint8_t layer = get_highest_layer(layer_state);

        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index < led_max && index != NO_LED &&
                keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                    rgb_matrix_set_color(index, RGB_GREEN);
                }
            }
        }
    }
    */
    // nothing to be done
    return false;
}

void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
}


  //,----------------------------------------------------------.                    ,-----------------------------------------------------.
  //|--------+--------+--------+--------+-------------+--------|                    |--------+--------+--------+--------+--------+--------|
  //|--------+--------+--------+--------+-------------+--------|                    |--------+--------+--------+--------+--------+--------|
  //|--------+--------+--------+--------+-------------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      //`-------------------------------'  `--------------------------'

