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
    _MOVE,
};

// NOTE: If left and right modifiers are pressed together, they are all interpreted as right modifiers!
// TODO: Use QK_LEAD on other layers to fix those. Move alt-gr to lhs, upper right position. Move l-gui to lhs, upper left position, move alt to rhs, upper left position.
// TODO: maybe switch modifier keys to rhs as well? There are 4 /5 spaces in place of the arrow keys
// TODO: Consider better handling / moving of tab-hold keys
// TODO: Consider freezing all modifiers with qk-lead freeze key?

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌───────────────┬───────────┬───────────┬───────────┬───────────┬─────┬────────────┐   ┌───────────┬─────┬───────────┬───────────┬───────────┬───────────┬──────┐
//    │ OSM(MOD_RALT) │     q     │     w     │     f     │     p     │  b  │     no     │   │    no     │  j  │     l     │     u     │     y     │    tab    │  up  │
//    ├───────────────┼───────────┼───────────┼───────────┼───────────┼─────┼────────────┤   ├───────────┼─────┼───────────┼───────────┼───────────┼───────────┼──────┤
//    │ OSM(MOD_LSFT) │ LGUI_T(a) │ LALT_T(r) │ LCTL_T(s) │ LSFT_T(t) │  g  │ TO(_BASE)  │   │  QK_LEAD  │  m  │ LSFT_T(n) │ LCTL_T(e) │ LALT_T(i) │ LGUI_T(o) │ down │
//    ├───────────────┼───────────┼───────────┼───────────┼───────────┼─────┼────────────┘   └───────────┼─────┼───────────┼───────────┼───────────┼───────────┼──────┤
//    │ OSM(MOD_LCTL) │     z     │     x     │     c     │     d     │  v  │                            │  k  │     h     │     ,     │     .     │   left    │ rght │
//    └───────────────┴───────────┴───────────┴───────────┼───────────┼─────┼────────────┐   ┌───────────┼─────┼───────────┼───────────┴───────────┴───────────┴──────┘
//                                                        │    esc    │ spc │ OSL(_MOVE) │   │ OSL(_NUM) │ ent │ bACKSPACE │
//                                                        └───────────┴─────┴────────────┘   └───────────┴─────┴───────────┘
[_BASE] = LAYOUT_split_3x6_3_ex2(
  OSM(MOD_RALT) , KC_Q         , KC_W         , KC_F         , KC_P         , KC_B     , XXXXXXX    ,     XXXXXXX   , KC_J     , KC_L         , KC_U         , KC_Y         , KC_TAB       , KC_UP   ,
  OSM(MOD_LSFT) , LGUI_T(KC_A) , LALT_T(KC_R) , LCTL_T(KC_S) , LSFT_T(KC_T) , KC_G     , TO(_BASE)  ,     QK_LEAD   , KC_M     , LSFT_T(KC_N) , LCTL_T(KC_E) , LALT_T(KC_I) , LGUI_T(KC_O) , KC_DOWN ,
  OSM(MOD_LCTL) , KC_Z         , KC_X         , KC_C         , KC_D         , KC_V     ,                              KC_K     , KC_H         , KC_COMMA     , KC_DOT       , KC_LEFT      , KC_RIGHT,
                                                               KC_ESCAPE    , KC_SPACE , OSL(_MOVE) ,     OSL(_NUM) , KC_ENTER , KC_BACKSPACE
),

//    ┌───────────────┬───────────────────┬───────────┬───────────┬───────────┬─────┬───────────┐   ┌─────────┬─────┬───────────┬───────────┬───────────┬────────────┬────┐
//    │      no       │         \         │     7     │     8     │     9     │  0  │  QK_LLCK  │   │ QK_LLCK │ no  │    no     │    no     │    no     │     no     │ no │
//    ├───────────────┼───────────────────┼───────────┼───────────┼───────────┼─────┼───────────┤   ├─────────┼─────┼───────────┼───────────┼───────────┼────────────┼────┤
//    │ OSM(MOD_LSFT) │ LGUI_T(sEMICOLON) │ LALT_T(4) │ LCTL_T(5) │ LSFT_T(6) │  =  │ TO(_BASE) │   │   no    │ no  │ LSFT_T(') │ LCTL_T([) │ LALT_T(]) │ LGUI_T(no) │ no │
//    ├───────────────┼───────────────────┼───────────┼───────────┼───────────┼─────┼───────────┘   └─────────┼─────┼───────────┼───────────┼───────────┼────────────┼────┤
//    │ OSM(MOD_LCTL) │         /         │     1     │     2     │     3     │  -  │                         │ no  │     `     │     ,     │     .     │     no     │ no │
//    └───────────────┴───────────────────┴───────────┴───────────┼───────────┼─────┼───────────┐   ┌─────────┼─────┼───────────┼───────────┴───────────┴────────────┴────┘
//                                                                │    esc    │ spc │    no     │   │   no    │ ent │ bACKSPACE │
//                                                                └───────────┴─────┴───────────┘   └─────────┴─────┴───────────┘
[_NUM] = LAYOUT_split_3x6_3_ex2(
  XXXXXXX       , KC_BACKSLASH         , KC_7         , KC_8         , KC_9         , KC_0     , QK_LLCK   ,     QK_LLCK , XXXXXXX  , XXXXXXX          , XXXXXXX         , XXXXXXX         , XXXXXXX         , XXXXXXX,
  OSM(MOD_LSFT) , LGUI_T(KC_SEMICOLON) , LALT_T(KC_4) , LCTL_T(KC_5) , LSFT_T(KC_6) , KC_EQUAL , TO(_BASE) ,     XXXXXXX , XXXXXXX  , LSFT_T(KC_QUOTE) , LCTL_T(KC_LBRC) , LALT_T(KC_RBRC) , LGUI_T(XXXXXXX) , XXXXXXX,
  OSM(MOD_LCTL) , KC_SLASH             , KC_1         , KC_2         , KC_3         , KC_MINUS ,                           XXXXXXX  , KC_GRAVE         , KC_COMMA        , KC_DOT          , XXXXXXX         , XXXXXXX,
                                                                       KC_ESCAPE    , KC_SPACE , XXXXXXX   ,     XXXXXXX , KC_ENTER , KC_BACKSPACE
),

//    ┌───────────────┬────────────┬────────────┬────────────┬────────────┬─────┬───────────┐   ┌─────────┬─────┬───────────┬─────────┬───────────┬─────────┬────┐
//    │      no       │     no     │     no     │     no     │     no     │ no  │  QK_LLCK  │   │ QK_LLCK │ no  │   home    │ pAGE_UP │ pAGE_DOWN │   end   │ no │
//    ├───────────────┼────────────┼────────────┼────────────┼────────────┼─────┼───────────┤   ├─────────┼─────┼───────────┼─────────┼───────────┼─────────┼────┤
//    │ OSM(MOD_LSFT) │ LGUI_T(no) │ LALT_T(no) │ LCTL_T(no) │ LSFT_T(no) │ no  │ TO(_BASE) │   │   no    │ no  │   left    │   up    │   down    │  rght   │ no │
//    ├───────────────┼────────────┼────────────┼────────────┼────────────┼─────┼───────────┘   └─────────┼─────┼───────────┼─────────┼───────────┼─────────┼────┤
//    │ OSM(MOD_LCTL) │     no     │     no     │  MS_BTN3   │  MS_BTN2   │ no  │                         │ no  │  MS_LEFT  │  MS_UP  │  MS_DOWN  │ MS_RGHT │ no │
//    └───────────────┴────────────┴────────────┴────────────┼────────────┼─────┼───────────┐   ┌─────────┼─────┼───────────┼─────────┴───────────┴─────────┴────┘
//                                                           │    esc     │ spc │    no     │   │ MS_BTN1 │ ent │ bACKSPACE │
//                                                           └────────────┴─────┴───────────┘   └─────────┴─────┴───────────┘
[_MOVE] = LAYOUT_split_3x6_3_ex2(
  XXXXXXX       , XXXXXXX         , XXXXXXX         , XXXXXXX         , XXXXXXX         , XXXXXXX  , QK_LLCK   ,     QK_LLCK , XXXXXXX  , KC_HOME      , KC_PAGE_UP , KC_PAGE_DOWN , KC_END   , XXXXXXX,
  OSM(MOD_LSFT) , LGUI_T(XXXXXXX) , LALT_T(XXXXXXX) , LCTL_T(XXXXXXX) , LSFT_T(XXXXXXX) , XXXXXXX  , TO(_BASE) ,     XXXXXXX , XXXXXXX  , KC_LEFT      , KC_UP      , KC_DOWN      , KC_RIGHT , XXXXXXX,
  OSM(MOD_LCTL) , XXXXXXX         , XXXXXXX         , MS_BTN3         , MS_BTN2         , XXXXXXX  ,                           XXXXXXX  , MS_LEFT      , MS_UP      , MS_DOWN      , MS_RGHT  , XXXXXXX,
                                                                        KC_ESCAPE       , KC_SPACE , XXXXXXX   ,     MS_BTN1 , KC_ENTER , KC_BACKSPACE
)
};

const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BACKSPACE, KC_DEL);
const key_override_t escape_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_SPACE, KC_TAB);
// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    &delete_key_override,
    &escape_key_override,
};

void leader_start_user(void) {
    // Do something when the leader key is pressed
};

/* Leader sequences allow for vim-like command sequences
 */
void leader_end_user(void) {
    // noop
    if (leader_sequence_one_key(KC_ESCAPE)) {
    };
    // reboot into bootloader
    if (leader_sequence_two_keys(KC_Q, KC_B)) {
        reset_keyboard();
    };
    // switch to vty-1 (ctrl-alt-f1) or vty-7
    if (leader_sequence_two_keys(KC_V, KC_Z)) {
        tap_code16(LCTL(LALT(KC_F1)));
    };
    if (leader_sequence_two_keys(KC_V, KC_X)) {
        tap_code16(LCTL(LALT(KC_F7)));
    };
};

/*
 */
// TODO: characters should be blue, but with shift,etc modifiers cyan.
// TODO: digits should be dark green, but with shift,etc lightgreen.
// TODO: not rbg, but hues, then change intensity!
void rgb_matrix_per_index(uint8_t led_min, uint8_t led_max, uint8_t layer, uint8_t mods, uint8_t index, uint16_t keycode) {
    uint8_t basekey = QK_MODS_GET_BASIC_KEYCODE(keycode);
    //uint16_t modbits = keycode & (MOD_BIT(KC_LGUI | KC_LALT | KC_LCTL | KC_LSFT));
    //always set color to off first
    if (keycode > XXXXXXX) {
        rgb_matrix_set_color(index, RGB_WHITE);
    } else {
        rgb_matrix_set_color(index, RGB_OFF);
    };

    // "unmodified" characters keys (i.e no layer switch or anything fancy)
    if (basekey >= KC_A && basekey <= KC_Z) {
        if (keycode & 0xFF00) {
            rgb_matrix_set_color(index, RGB_CYAN);
        } else
        {
            rgb_matrix_set_color(index, RGB_BLUE);
        };
    };

    // digits and others
    if (basekey >= KC_1 && basekey <= KC_0) {
        if (keycode & 0xFF00) {
            rgb_matrix_set_color(index, RGB_SPRINGGREEN);
        } else {
            rgb_matrix_set_color(index, RGB_GREEN);
        };
    };

    // punctuation, brackets, etc
    if (basekey >= KC_MINUS && basekey <= KC_SLASH) {
        if (keycode & 0xFF00) {
            rgb_matrix_set_color(index, RGB_GOLD);
        } else {
            rgb_matrix_set_color(index, RGB_YELLOW);
        };
    };

    // movements
    if (basekey >= KC_RIGHT && basekey <= KC_UP) {
        if (keycode & 0xFF00) {
            rgb_matrix_set_color(index, RGB_CYAN);
        } else {
            rgb_matrix_set_color(index, RGB_TURQUOISE);
        };
    };

    if (keycode == QK_LLCK && (is_layer_locked(_NUM) || is_layer_locked(_MOVE))) {
            rgb_matrix_set_color(index, RGB_RED);
    };
    // TODO: on layer lock, color the appropriate layer key red
    // BUG: only the key on the master side turns red?

    // once leader is active, I should also switch other keys off and only bound keys on
    if (keycode == QK_LEAD) {
        if (leader_sequence_active()) {
            rgb_matrix_set_color(index, RGB_CORAL);
        } else {
            rgb_matrix_set_color(index, RGB_RED);
        };
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


