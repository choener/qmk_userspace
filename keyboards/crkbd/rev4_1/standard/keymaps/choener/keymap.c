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

/*
 * https://github.com/foostan/crkbd
 *
 * https://github.com/qmk/qmk_firmware/blob/master/quantum/keycodes.h
 * https://github.com/qmk/qmk_firmware/blob/master/quantum/quantum_keycodes.h
 */

#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _NUM,
    _MOVE,
};

// NOTE: If left and right modifiers are pressed together, they are all interpreted as right modifiers!
// TODO: Consider better handling / moving of tab-hold keys
// TODO: Consider freezing all modifiers with qk-lead freeze key?
// TODO: single tap (, double tap [, triple tap {

/*
 * https://docs.qmk.fm/mod_tap
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌───────────────┬───────────┬───────────┬───────────┬───────────┬─────┬───────────────┐   ┌───────────────┬─────┬───────────┬───────────┬───────────┬───────────────┬───────────────┐
//    │ OSM(MOD_LGUI) │     q     │     w     │     f     │     p     │  b  │ OSM(MOD_LALT) │   │ OSM(MOD_RALT) │  j  │     l     │     u     │     y     │      tab      │ OSM(MOD_LGUI) │
//    ├───────────────┼───────────┼───────────┼───────────┼───────────┼─────┼───────────────┤   ├───────────────┼─────┼───────────┼───────────┼───────────┼───────────────┼───────────────┤
//    │ OSM(MOD_LSFT) │ LGUI_T(a) │ LALT_T(r) │ LCTL_T(s) │ LSFT_T(t) │  g  │   TO(_BASE)   │   │    QK_LEAD    │  m  │ LSFT_T(n) │ LCTL_T(e) │ LALT_T(i) │   LGUI_T(o)   │ OSM(MOD_LSFT) │
//    ├───────────────┼───────────┼───────────┼───────────┼───────────┼─────┼───────────────┘   └───────────────┼─────┼───────────┼───────────┼───────────┼───────────────┼───────────────┤
//    │ OSM(MOD_LCTL) │     z     │     x     │     c     │     d     │  v  │                                   │  k  │     h     │     ,     │     .     │ OSM(MOD_LALT) │ OSM(MOD_LCTL) │
//    └───────────────┴───────────┴───────────┴───────────┼───────────┼─────┼───────────────┐   ┌───────────────┼─────┼───────────┼───────────┴───────────┴───────────────┴───────────────┘
//                                                        │    esc    │ spc │  OSL(_MOVE)   │   │   OSL(_NUM)   │ ent │ bACKSPACE │
//                                                        └───────────┴─────┴───────────────┘   └───────────────┴─────┴───────────┘
[_BASE] = LAYOUT_split_3x6_3_ex2(
  OSM(MOD_LGUI) , KC_Q         , KC_W         , KC_F         , KC_P         , KC_B     , OSM(MOD_LALT) ,     OSM(MOD_RALT) , KC_J     , KC_L         , KC_U         , KC_Y         , KC_TAB        , OSM(MOD_LGUI),
  OSM(MOD_LSFT) , LGUI_T(KC_A) , LALT_T(KC_R) , LCTL_T(KC_S) , LSFT_T(KC_T) , KC_G     , TO(_BASE)     ,     QK_LEAD       , KC_M     , LSFT_T(KC_N) , LCTL_T(KC_E) , LALT_T(KC_I) , LGUI_T(KC_O)  , OSM(MOD_LSFT),
  OSM(MOD_LCTL) , KC_Z         , KC_X         , KC_C         , KC_D         , KC_V     ,                                     KC_K     , KC_H         , KC_COMMA     , KC_DOT       , OSM(MOD_LALT) , OSM(MOD_LCTL),
                                                               KC_ESCAPE    , KC_SPACE , OSL(_MOVE)    ,     OSL(_NUM)     , KC_ENTER , KC_BACKSPACE
),

//    ┌───────────────┬───────────────────┬───────────┬───────────┬───────────┬─────┬───────────────┐   ┌───────────────┬─────┬───────────┬───────────┬───────────┬───────────────┬───────────────┐
//    │ OSM(MOD_LGUI) │         \         │     7     │     8     │     9     │  0  │ OSM(MOD_LALT) │   │ OSM(MOD_RALT) │ no  │    no     │    no     │    no     │      no       │ OSM(MOD_LGUI) │
//    ├───────────────┼───────────────────┼───────────┼───────────┼───────────┼─────┼───────────────┤   ├───────────────┼─────┼───────────┼───────────┼───────────┼───────────────┼───────────────┤
//    │ OSM(MOD_LSFT) │ LGUI_T(sEMICOLON) │ LALT_T(4) │ LCTL_T(5) │ LSFT_T(6) │  =  │   TO(_BASE)   │   │    QK_LLCK    │ no  │ LSFT_T(') │ LCTL_T([) │ LALT_T(]) │  LGUI_T(no)   │ OSM(MOD_LSFT) │
//    ├───────────────┼───────────────────┼───────────┼───────────┼───────────┼─────┼───────────────┘   └───────────────┼─────┼───────────┼───────────┼───────────┼───────────────┼───────────────┤
//    │ OSM(MOD_LCTL) │         /         │     1     │     2     │     3     │  -  │                                   │ no  │     `     │     ,     │     .     │ OSM(MOD_LALT) │ OSM(MOD_LCTL) │
//    └───────────────┴───────────────────┴───────────┴───────────┼───────────┼─────┼───────────────┐   ┌───────────────┼─────┼───────────┼───────────┴───────────┴───────────────┴───────────────┘
//                                                                │    esc    │ spc │      no       │   │      no       │ ent │ bACKSPACE │
//                                                                └───────────┴─────┴───────────────┘   └───────────────┴─────┴───────────┘
[_NUM] = LAYOUT_split_3x6_3_ex2(
  OSM(MOD_LGUI) , KC_BACKSLASH         , KC_7         , KC_8         , KC_9         , KC_0     , OSM(MOD_LALT) ,     OSM(MOD_RALT) , XXXXXXX  , XXXXXXX          , XXXXXXX         , XXXXXXX         , XXXXXXX         , OSM(MOD_LGUI),
  OSM(MOD_LSFT) , LGUI_T(KC_SEMICOLON) , LALT_T(KC_4) , LCTL_T(KC_5) , LSFT_T(KC_6) , KC_EQUAL , TO(_BASE)     ,     QK_LLCK       , XXXXXXX  , LSFT_T(KC_QUOTE) , LCTL_T(KC_LBRC) , LALT_T(KC_RBRC) , LGUI_T(XXXXXXX) , OSM(MOD_LSFT),
  OSM(MOD_LCTL) , KC_SLASH             , KC_1         , KC_2         , KC_3         , KC_MINUS ,                                     XXXXXXX  , KC_GRAVE         , KC_COMMA        , KC_DOT          , OSM(MOD_LALT)   , OSM(MOD_LCTL),
                                                                       KC_ESCAPE    , KC_SPACE , XXXXXXX       ,     XXXXXXX       , KC_ENTER , KC_BACKSPACE
),

//    ┌───────────────┬────────────┬────────────┬────────────┬────────────┬─────┬───────────────┐   ┌───────────────┬─────┬───────────┬─────────┬───────────┬─────────┬───────────────┐
//    │ OSM(MOD_LGUI) │     no     │     no     │     no     │     no     │ no  │ OSM(MOD_LALT) │   │ OSM(MOD_RALT) │ no  │   home    │ pAGE_UP │ pAGE_DOWN │   end   │ OSM(MOD_LGUI) │
//    ├───────────────┼────────────┼────────────┼────────────┼────────────┼─────┼───────────────┤   ├───────────────┼─────┼───────────┼─────────┼───────────┼─────────┼───────────────┤
//    │ OSM(MOD_LSFT) │ LGUI_T(no) │ LALT_T(no) │ LCTL_T(no) │ LSFT_T(no) │ no  │   TO(_BASE)   │   │    QK_LLCK    │ no  │   left    │   up    │   down    │  rght   │ OSM(MOD_LSFT) │
//    ├───────────────┼────────────┼────────────┼────────────┼────────────┼─────┼───────────────┘   └───────────────┼─────┼───────────┼─────────┼───────────┼─────────┼───────────────┤
//    │ OSM(MOD_LCTL) │     no     │     no     │  MS_BTN3   │  MS_BTN2   │ no  │                                   │ no  │  MS_LEFT  │  MS_UP  │  MS_DOWN  │ MS_RGHT │ OSM(MOD_LCTL) │
//    └───────────────┴────────────┴────────────┴────────────┼────────────┼─────┼───────────────┐   ┌───────────────┼─────┼───────────┼─────────┴───────────┴─────────┴───────────────┘
//                                                           │    esc     │ spc │      no       │   │    MS_BTN1    │ ent │ bACKSPACE │
//                                                           └────────────┴─────┴───────────────┘   └───────────────┴─────┴───────────┘
[_MOVE] = LAYOUT_split_3x6_3_ex2(
  OSM(MOD_LGUI) , XXXXXXX         , XXXXXXX         , XXXXXXX         , XXXXXXX         , XXXXXXX  , OSM(MOD_LALT) ,     OSM(MOD_RALT) , XXXXXXX  , KC_HOME      , KC_PAGE_UP , KC_PAGE_DOWN , KC_END   , OSM(MOD_LGUI),
  OSM(MOD_LSFT) , LGUI_T(XXXXXXX) , LALT_T(XXXXXXX) , LCTL_T(XXXXXXX) , LSFT_T(XXXXXXX) , XXXXXXX  , TO(_BASE)     ,     QK_LLCK       , XXXXXXX  , KC_LEFT      , KC_UP      , KC_DOWN      , KC_RIGHT , OSM(MOD_LSFT),
  OSM(MOD_LCTL) , XXXXXXX         , XXXXXXX         , MS_BTN3         , MS_BTN2         , XXXXXXX  ,                                     XXXXXXX  , MS_LEFT      , MS_UP      , MS_DOWN      , MS_RGHT  , OSM(MOD_LCTL),
                                                                        KC_ESCAPE       , KC_SPACE , XXXXXXX       ,     MS_BTN1       , KC_ENTER , KC_BACKSPACE
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
 * https://docs.qmk.fm/features/leader_key
 */
void leader_end_user(void) {
    // noop or abort
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
// https://github.com/qmk/qmk_firmware/blob/a573931fef26427e761456698de83e58458df17c/quantum/keycodes.h
void rgb_matrix_per_index(uint8_t led_min, uint8_t led_max, uint8_t layer, uint8_t mods, uint8_t index, uint8_t row, uint8_t col, uint16_t keycode) {
    uint8_t basekey = QK_MODS_GET_BASIC_KEYCODE(keycode);
    // BUG: This should be 8bit?
    uint16_t osm = get_oneshot_mods ();
    uint16_t mds = get_mods();
    hsv_t hsv = {0, 0, 0};
    //uint16_t modbits = keycode & (MOD_BIT(KC_LGUI | KC_LALT | KC_LCTL | KC_LSFT));
    //always set color to off first
    //TODO: New system: use hsv, dim led's, too. Then brighten up some
    if (keycode > XXXXXXX) {
        hsv = (hsv_t) {HSV_WHITE}; //white
    } else {
        hsv = (hsv_t) {HSV_OFF};
    };

    // "unmodified" characters keys (i.e no layer switch or anything fancy)
    if (basekey >= KC_A && basekey <= KC_Z) {
        if (keycode & 0xFF00) {
            hsv = (hsv_t) {HSV_CYAN};
        } else
        {
            hsv = (hsv_t) {HSV_BLUE};
        };
    };

    // digits and others
    if (basekey >= KC_1 && basekey <= KC_0) {
        if (keycode & 0xFF00) {
            hsv = (hsv_t) {HSV_SPRINGGREEN};
        } else {
            hsv = (hsv_t) {HSV_GREEN};
        };
    };

    // punctuation, brackets, etc
    if (basekey >= KC_MINUS && basekey <= KC_SLASH) {
        if (keycode & 0xFF00) {
            hsv = (hsv_t) {HSV_GOLD};
        } else {
            hsv = (hsv_t) {HSV_YELLOW};
        };
    };


    // TODO: on layer lock, color the appropriate layer key red
    // BUG: only the key on the master side turns red?

    hsv.v = MIN(hsv.v, 100);

    switch(keycode) {
        // movements
        case KC_LEFT:
        case KC_UP:
        case KC_DOWN:
        case KC_RIGHT:
            hsv = (hsv_t) {HSV_CYAN};
            hsv.v = 100;
            break;
        // main thumb keys
        case KC_ENTER:
        case KC_SPACE:
            hsv = (hsv_t) {HSV_PINK};
            hsv.v = 120;
            break;
        // BUG: Probably won't work for shift-thumb since that is done via key-mod
        case KC_TAB:
            hsv = (hsv_t) {HSV_PURPLE};
            hsv.v = 100;
            break;
        case KC_BACKSPACE:
        case KC_ESCAPE:
            hsv = (hsv_t) {HSV_ORANGE};
            hsv.v = 120;
            break;
        case KC_DEL:
            hsv = (hsv_t) {HSV_ORANGE};
            hsv.v = 100;
            break;
    };

    // TODO: if oneshot layers (but only those) are on: color heart in red to indicate the way back
    // TODO: Color alt-gr

    if (leader_sequence_active()) {
        //BUG: leader_sequence_active is *not* transferred to slave side of keyboard?
        // disable all LEDs
        hsv.v = 0;
        // enable active ones.
        // TODO: Can I color code? And can I change color based on the number of entered keys?
        switch (keycode) {
            case KC_Q:
            case KC_B:
                hsv = (hsv_t) {HSV_RED};
                break;
            case KC_ESCAPE:
                hsv = (hsv_t) {HSV_RED};
                hsv.v = 250;
                break;
        };
    };
    if (keycode == QK_LEAD) {
        hsv = (hsv_t) {HSV_MAGENTA};
        hsv.v = 50;
        if (leader_sequence_active()) {
            hsv.v = 250;
        };
    };

    // layer information: _MOVE
    if (keycode == OSL(_MOVE)) {
        hsv = (hsv_t) {HSV_MAGENTA};
        hsv.v = 50;
    };
    if (row == 3 && col == 5 && is_layer_locked(_MOVE)) {
        hsv = (hsv_t) {HSV_MAGENTA};
        hsv.v = 250;
    };
    // layer information: _NUM
    if (keycode == OSL(_NUM)) {
        hsv = (hsv_t) {HSV_MAGENTA};
        hsv.v = 50;
    };
    if (row == 7 && col == 5 && is_layer_locked(_NUM)) {
        hsv = (hsv_t) {HSV_MAGENTA};
        hsv.v = 250;
    };
    // lock layer
    if (keycode == QK_LLCK) {
        hsv = (hsv_t) {HSV_MAGENTA};
        hsv.v = 250;
    };

    // the 4 modifier keys
    for (uint16_t k = KC_LEFT_CTRL; k <= KC_LEFT_GUI; k++) {
        // m = 0..3, which is the bit to be interested in.
        uint8_t m = k - KC_LEFT_CTRL;
        if (keycode == OSM(1<<m)) {
            hsv = (hsv_t) {HSV_GREEN};
            hsv.v = 50;
            if ((mds | osm) & MOD_BIT(k)) {
                hsv.v = 250;
            };
        };
    };

    rgb_t rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);

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
                rgb_matrix_per_index(led_min, led_max, layer, mods, index, row, col, keycode);
            };
        };
    };
    // nothing to be done
    return false;
}

void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TO(_BASE):
            // we handle to->base special. It first disables all one-shot modifiers, then (via return true) still returns us to the base layer.
            reset_oneshot_layer();
            clear_oneshot_mods();
            return true;
        default:
            return true;
    };
};

