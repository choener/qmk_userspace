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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Keep QC_BOOT until we have a stable system
     */
    [_BASE] = LAYOUT_split_3x6_3_ex2(
      XXXXXXX,         KC_Q,         KC_W,         KC_F,         KC_P,    KC_B, QK_BOOT,        QK_BOOT,                  KC_J,         KC_L,         KC_U,         KC_Y,      XXXXXXX, XXXXXXX,
      XXXXXXX, LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T),    KC_G, XXXXXXX,        XXXXXXX,                  KC_M, LSFT_T(KC_N), LCTL_T(KC_E), LALT_T(KC_I), LGUI_T(KC_O), XXXXXXX,
      XXXXXXX,         KC_Z,         KC_X,         KC_C,         KC_D,    KC_V,                                           KC_K,         KC_H,      XXXXXXX,      XXXXXXX,      XXXXXXX, XXXXXXX,
                                                              XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, LT(_NUM,KC_BACKSPACE),      XXXXXXX
  ),
    /*
     * Shift-9 and Shift-0 provide (,) next to each other
     * TODO: Check if LSFT_T(OSM(MOD_LSFT)) is convenient: one-shot on quick press, but if held then same key but held
     */
    [_NUM] = LAYOUT_split_3x6_3_ex2(
      XXXXXXX, XXXXXXX,    KC_7,    KC_8,    KC_9,     KC_0, XXXXXXX,    XXXXXXX, XXXXXXX,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX,    KC_4,    KC_5,    KC_6, KC_EQUAL, XXXXXXX,    XXXXXXX, XXXXXXX, LSFT_T(OSM(MOD_LSFT)), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX,    KC_1,    KC_2,    KC_3, KC_MINUS,                      XXXXXXX,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                 XXXXXXX, XXXXXXX,  XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX
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


void rgb_matrix_per_index(uint8_t led_min, uint8_t led_max, uint8_t layer, uint8_t mods, uint8_t index, uint16_t keycode) {
    rgb_matrix_set_color(index, RGB_OFF);
    // In base layer, light up keys in a fancy way
    if (layer == 0) {
        switch (keycode) {
            case KC_A:
            case KC_R:
            case KC_S:
            case KC_T:
                rgb_matrix_set_color(index, RGB_PURPLE);
                break;
            default:
                if (keycode > XXXXXXX) {
                    rgb_matrix_set_color(index, RGB_BLUE);
                };
        };
        return;
        //if (keycode > XXXXXXX) {
        //    // TODO: calculate color based on: are any modifiers active?
        //    if (mods & MOD_MASK_SHIFT) {
        //        rgb_matrix_set_color(index, RGB_RED);
        //    } else {
        //        rgb_matrix_set_color(index, RGB_GREEN);
        //    };
        //    return;
        //}
    }
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



  //,----------------------------------------------------------.                    ,-----------------------------------------------------.
  //|--------+--------+--------+--------+-------------+--------|                    |--------+--------+--------+--------+--------+--------|
  //|--------+--------+--------+--------+-------------+--------|                    |--------+--------+--------+--------+--------+--------|
  //|--------+--------+--------+--------+-------------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      //`-------------------------------'  `--------------------------'

