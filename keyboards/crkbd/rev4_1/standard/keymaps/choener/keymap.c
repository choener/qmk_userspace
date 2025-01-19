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
      XXXXXXX,         KC_Q,         KC_W,         KC_F,         KC_P,    KC_B, QK_BOOT,        XXXXXXX,                  KC_J,         KC_L,         KC_U,         KC_Y,      XXXXXXX, XXXXXXX,
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


  //,----------------------------------------------------------.                    ,-----------------------------------------------------.
  //|--------+--------+--------+--------+-------------+--------|                    |--------+--------+--------+--------+--------+--------|
  //|--------+--------+--------+--------+-------------+--------|                    |--------+--------+--------+--------+--------+--------|
  //|--------+--------+--------+--------+-------------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      //`-------------------------------'  `--------------------------'

