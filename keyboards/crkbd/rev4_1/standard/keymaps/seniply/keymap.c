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

// TODO: https://docs.qmk.fm/features/caps_word
// TODO: Add qmk repeat and anti-repeat keys, possibly prominently
// TODO: https://github.com/sotte/sotte_qmk_keyboard_layout/blob/main/keyboards/crkbd/keymaps/sotte/keymap.c
// TODO: Sotte has an interesting config, where KC_ESC cancels oneshot layers!
// TODO: use defines to allow enabling and disabling home-row mods?
// TODO: put enter on CD and escape on FP?
// TODO: frequently used keys: .:   ,;   -=   possibly in this configuration; need to modify shift handling for these keys
// TODO: then '" which is already convenient for shifting
// TODO: switch between colemak and gallium layer?

#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _GALLIUM,
    _NAV,
    _SYMBOLS,
    _NUMBERS,
    _FUNCTION,
};

#define OSM_SFT OSM(MOD_LSFT)
#define SPC_NAV LT(_NAV, KC_SPC)

// NOTE: If left and right modifiers are pressed together, they are all interpreted as right modifiers!
// https://github.com/sotte/sotte_qmk_keyboard_layout

/*
 * https://docs.qmk.fm/mod_tap
 */
// NOTE: left-handed thumb hold to toggle nav layer, which has modifier keys on the lhs.
// NOTE: right-handed thumb hold to toggle sy

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌────┬───┬───┬───┬────┬─────────┬───────────────┐   ┌────┬─────────┬────┬───┬───┬───┬────┐
//    │ no │ q │ w │ f │ p  │    b    │ PDF(_GALLIUM) │   │ no │    j    │ l  │ u │ y │ ' │ no │
//    ├────┼───┼───┼───┼────┼─────────┼───────────────┤   ├────┼─────────┼────┼───┼───┼───┼────┤
//    │ no │ a │ r │ s │ t  │    g    │      no       │   │ no │    m    │ n  │ e │ i │ o │ no │
//    ├────┼───┼───┼───┼────┼─────────┼───────────────┘   └────┼─────────┼────┼───┼───┼───┼────┤
//    │ no │ z │ x │ c │ d  │    v    │                        │    k    │ h  │ , │ . │ - │ no │
//    └────┴───┴───┴───┼────┼─────────┼───────────────┐   ┌────┼─────────┼────┼───┴───┴───┴────┘
//                     │ no │ SPC_NAV │      no       │   │ no │ OS_LSFT │ no │
//                     └────┴─────────┴───────────────┘   └────┴─────────┴────┘
[_BASE] = LAYOUT_split_3x6_3_ex2(
  XXXXXXX , KC_Q , KC_W , KC_F , KC_P    , KC_B    , PDF(_GALLIUM) ,     XXXXXXX , KC_J    , KC_L    , KC_U     , KC_Y   , KC_QUOTE , XXXXXXX,
  XXXXXXX , KC_A , KC_R , KC_S , KC_T    , KC_G    , XXXXXXX       ,     XXXXXXX , KC_M    , KC_N    , KC_E     , KC_I   , KC_O     , XXXXXXX,
  XXXXXXX , KC_Z , KC_X , KC_C , KC_D    , KC_V    ,                               KC_K    , KC_H    , KC_COMMA , KC_DOT , KC_MINUS , XXXXXXX,
                                 XXXXXXX , SPC_NAV , XXXXXXX       ,     XXXXXXX , OS_LSFT , XXXXXXX
),

//    ┌────┬───┬───┬───┬────┬─────────┬────────────┐   ┌────┬─────────┬────┬────┬────┬────┬────┐
//    │ no │ b │ l │ d │ c  │    v    │ PDF(_BASE) │   │ no │    j    │ y  │ o  │ u  │ no │ no │
//    ├────┼───┼───┼───┼────┼─────────┼────────────┤   ├────┼─────────┼────┼────┼────┼────┼────┤
//    │ no │ n │ r │ s │ t  │    g    │     no     │   │ no │    p    │ h  │ a  │ e  │ i  │ no │
//    ├────┼───┼───┼───┼────┼─────────┼────────────┘   └────┼─────────┼────┼────┼────┼────┼────┤
//    │ no │ x │ q │ h │ w  │    z    │                     │    k    │ f  │ no │ no │ no │ no │
//    └────┴───┴───┴───┼────┼─────────┼────────────┐   ┌────┼─────────┼────┼────┴────┴────┴────┘
//                     │ no │ SPC_NAV │     no     │   │ no │ OS_LSFT │ no │
//                     └────┴─────────┴────────────┘   └────┴─────────┴────┘
[_GALLIUM] = LAYOUT_split_3x6_3_ex2(
  XXXXXXX , KC_B , KC_L , KC_D , KC_C    , KC_V    , PDF(_BASE) ,     XXXXXXX , KC_J    , KC_Y    , KC_O    , KC_U    , XXXXXXX , XXXXXXX,
  XXXXXXX , KC_N , KC_R , KC_S , KC_T    , KC_G    , XXXXXXX    ,     XXXXXXX , KC_P    , KC_H    , KC_A    , KC_E    , KC_I    , XXXXXXX,
  XXXXXXX , KC_X , KC_Q , KC_H , KC_W    , KC_Z    ,                            KC_K    , KC_F    , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
                                 XXXXXXX , SPC_NAV , XXXXXXX    ,     XXXXXXX , OS_LSFT , XXXXXXX
),

//    ┌────┬─────────┬─────────┬─────────┬─────────┬────┬────┐   ┌────┬───────────┬───────────┬──────┬──────┬────┬────┐
//    │ no │   no    │   no    │   no    │   no    │ no │ no │   │ no │  pAGE_UP  │   home    │  up  │ end  │ no │ no │
//    ├────┼─────────┼─────────┼─────────┼─────────┼────┼────┤   ├────┼───────────┼───────────┼──────┼──────┼────┼────┤
//    │ no │ OS_LALT │ OS_LGUI │ OS_LCTL │ OS_LSFT │ no │ no │   │ no │ pAGE_DOWN │   left    │ down │ rght │ no │ no │
//    ├────┼─────────┼─────────┼─────────┼─────────┼────┼────┘   └────┼───────────┼───────────┼──────┼──────┼────┼────┤
//    │ no │   no    │   no    │   no    │   no    │ no │             │    no     │ bACKSPACE │  no  │  no  │ no │ no │
//    └────┴─────────┴─────────┴─────────┼─────────┼────┼────┐   ┌────┼───────────┼───────────┼──────┴──────┴────┴────┘
//                                       │   no    │ no │ no │   │ no │    ent    │    no     │
//                                       └─────────┴────┴────┘   └────┴───────────┴───────────┘
[_NAV] = LAYOUT_split_3x6_3_ex2(
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , KC_PAGE_UP   , KC_HOME      , KC_UP   , KC_END   , XXXXXXX , XXXXXXX,
  XXXXXXX , OS_LALT , OS_LGUI , OS_LCTL , OS_LSFT , XXXXXXX , XXXXXXX ,     XXXXXXX , KC_PAGE_DOWN , KC_LEFT      , KC_DOWN , KC_RIGHT , XXXXXXX , XXXXXXX,
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                         XXXXXXX      , KC_BACKSPACE , XXXXXXX , XXXXXXX  , XXXXXXX , XXXXXXX,
                                          XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , KC_ENTER     , XXXXXXX
),

//    ┌────┬─────────┬─────────┬─────────┬─────────┬────┬────┐   ┌────┬────┬────┬────┬────┬────┬────┐
//    │ no │    !    │    @    │    #    │    $    │ %  │ ^  │   │ no │ no │ no │ no │ no │ no │ no │
//    ├────┼─────────┼─────────┼─────────┼─────────┼────┼────┤   ├────┼────┼────┼────┼────┼────┼────┤
//    │ no │ OS_LALT │ OS_LGUI │ OS_LCTL │ OS_LSFT │ no │ no │   │ no │ no │ no │ no │ no │ no │ no │
//    ├────┼─────────┼─────────┼─────────┼─────────┼────┼────┘   └────┼────┼────┼────┼────┼────┼────┤
//    │ no │   no    │   no    │   no    │   no    │ no │             │ no │ no │ no │ no │ no │ no │
//    └────┴─────────┴─────────┴─────────┼─────────┼────┼────┐   ┌────┼────┼────┼────┴────┴────┴────┘
//                                       │   no    │ no │ no │   │ no │ no │ no │
//                                       └─────────┴────┴────┘   └────┴────┴────┘
[_SYMBOLS] = LAYOUT_split_3x6_3_ex2(
  XXXXXXX , KC_EXCLAIM , KC_AT   , KC_HASH , KC_DOLLAR , KC_PERC , KC_CIRC ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
  XXXXXXX , OS_LALT    , OS_LGUI , OS_LCTL , OS_LSFT   , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
  XXXXXXX , XXXXXXX    , XXXXXXX , XXXXXXX , XXXXXXX   , XXXXXXX ,                         XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
                                             XXXXXXX   , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX
),

//    ┌────┬────┬────┬────┬────┬────┬────┐   ┌────┬────┬────┬────┬────┬────┬────┐
//    │ no │ no │ no │ no │ no │ no │ no │   │ no │ no │ no │ no │ no │ no │ no │
//    ├────┼────┼────┼────┼────┼────┼────┤   ├────┼────┼────┼────┼────┼────┼────┤
//    │ no │ no │ no │ no │ no │ no │ no │   │ no │ no │ no │ no │ no │ no │ no │
//    ├────┼────┼────┼────┼────┼────┼────┘   └────┼────┼────┼────┼────┼────┼────┤
//    │ no │ no │ no │ no │ no │ no │             │ no │ no │ no │ no │ no │ no │
//    └────┴────┴────┴────┼────┼────┼────┐   ┌────┼────┼────┼────┴────┴────┴────┘
//                        │ no │ no │ no │   │ no │ no │ no │
//                        └────┴────┴────┘   └────┴────┴────┘
[_NUMBERS] = LAYOUT_split_3x6_3_ex2(
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                         XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
                                          XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX
),

//    ┌────┬─────────┬─────────┬─────────┬─────────┬────┬────┐   ┌────┬─────┬────┬────┬────┬────┬────┐
//    │ no │   no    │   no    │   no    │   no    │ no │ no │   │ no │ no  │ no │ no │ no │ no │ no │
//    ├────┼─────────┼─────────┼─────────┼─────────┼────┼────┤   ├────┼─────┼────┼────┼────┼────┼────┤
//    │ no │ OS_LALT │ OS_LGUI │ OS_LCTL │ OS_LSFT │ no │ no │   │ no │ no  │ no │ no │ no │ no │ no │
//    ├────┼─────────┼─────────┼─────────┼─────────┼────┼────┘   └────┼─────┼────┼────┼────┼────┼────┤
//    │ no │   no    │   no    │   no    │   no    │ no │             │ f10 │ f1 │ no │ no │ no │ no │
//    └────┴─────────┴─────────┴─────────┼─────────┼────┼────┐   ┌────┼─────┼────┼────┴────┴────┴────┘
//                                       │   no    │ no │ no │   │ no │ no  │ no │
//                                       └─────────┴────┴────┘   └────┴─────┴────┘
[_FUNCTION] = LAYOUT_split_3x6_3_ex2(
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
  XXXXXXX , OS_LALT , OS_LGUI , OS_LCTL , OS_LSFT , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                         KC_F10  , KC_F1   , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX,
                                          XXXXXXX , XXXXXXX , XXXXXXX ,     XXXXXXX , XXXXXXX , XXXXXXX
)
};

// diferent keys get different tapping terms
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // jesus fuck is alt fucking annoying. Might even have to disable alt tapping altogether.
        case LALT_T(KC_A):
        case LALT_T(KC_O):
            return TAPPING_TERM + 300;
//        case LSFT_T(KC_G):
//            return TAPPING_TERM + 0;
//        case LSFT_T(KC_N):
//            return TAPPING_TERM + 0;
        default:
            return TAPPING_TERM;
    }
}

/*
 */
// TODO: characters should be blue, but with shift,etc modifiers cyan.
// TODO: digits should be dark green, but with shift,etc lightgreen.
// TODO: not rbg, but hues, then change intensity!
// https://github.com/qmk/qmk_firmware/blob/a573931fef26427e761456698de83e58458df17c/quantum/keycodes.h
void rgb_matrix_per_index(uint8_t led_min, uint8_t led_max, uint8_t layer, uint8_t mods, uint8_t index, uint8_t row, uint8_t col, uint16_t keycode) {
    //uint8_t basekey = QK_MODS_GET_BASIC_KEYCODE(keycode);
    // BUG: This should be 8bit?
    uint16_t osm = get_oneshot_mods ();
    uint16_t mds = get_mods();
    hsv_t hsv = {0, 0, 0};

    // TODO: on layer lock, color the appropriate layer key red
    // BUG: only the key on the master side turns red?

    switch(keycode) {
        // normal keys
        case KC_A ... KC_Z:
            hsv = (hsv_t) {HSV_BLUE};
            hsv.v = 100;
            break;
        // homerow mod, shift
        case LSFT_T(KC_A) ... LSFT_T(KC_Z):
        case LSFT_T(KC_1) ... LSFT_T(KC_0):
        case LSFT_T(KC_MINUS) ... LSFT_T(KC_SLASH):
            hsv = (hsv_t) {HSV_GREEN};
            hsv.v = 100;
            break;
        // homerow mod, ctrl
        // TODO: different color?
        case LCTL_T(KC_A) ... LCTL_T(KC_Z):
            hsv = (hsv_t) {HSV_GREEN};
            hsv.v = 100;
            break;
        // digits
        case KC_1 ... KC_0:
            hsv = (hsv_t) {HSV_BLUE};
            hsv.v = 100;
            break;
        case KC_F1 ... KC_F12:
            hsv = (hsv_t) {HSV_YELLOW};
            hsv.v = 100;
            break;
        case KC_MINUS ... KC_SLASH:
            hsv = (hsv_t) {HSV_YELLOW};
            hsv.v = 100;
            break;
        // movements
        case KC_LEFT:
        case KC_UP:
        case KC_DOWN:
        case KC_RIGHT:
            hsv = (hsv_t) {HSV_CYAN};
            hsv.v = 100;
            break;
        case KC_TAB:
        // main thumb keys
        case KC_ENTER:
        case KC_SPACE:
        case KC_BACKSPACE:
        case KC_ESCAPE:
            hsv = (hsv_t) {HSV_ORANGE};
            hsv.v = 120;
            break;
        case KC_DEL:
            hsv = (hsv_t) {HSV_ORANGE};
            hsv.v = 100;
            break;
        case QK_LEAD:
            hsv = (hsv_t) {HSV_MAGENTA};
            hsv.v = 100;
            break;
        case KC_KB_VOLUME_UP:
        case KC_KB_VOLUME_DOWN:
            hsv = (hsv_t) {HSV_YELLOW};
            hsv.v = 100;
        case TO(_BASE):
            hsv = (hsv_t) {HSV_MAGENTA};
            hsv.v = 50;
            // light up when return is possible (it always is...)
            if (layer > 0 || osm) {
                hsv = (hsv_t) {HSV_MAGENTA};
                hsv.v = 250;
            };
            break;
        default:
            if (keycode > XXXXXXX) {
                hsv = (hsv_t) {HSV_WHITE};
                hsv.v = 50;
            };
    };

    // TODO: if oneshot layers (but only those) are on: color heart in red to indicate the way back
    // TODO: Color alt-gr

    // layer information: _MOVE
//    if (keycode == OSL(_MOVE)) {
//        hsv = (hsv_t) {HSV_MAGENTA};
//        hsv.v = 100;
//    };
//    if (row == 3 && col == 5 && layer == _MOVE) {
//        hsv = (hsv_t) {HSV_MAGENTA};
//        hsv.v = 250;
//    };
//    // layer information: _NUM
//    if (keycode == OSL(_NUM)) {
//        hsv = (hsv_t) {HSV_MAGENTA};
//        hsv.v = 100;
//    };
//    if (row == 7 && col == 5 && layer == _NUM) {
//        hsv = (hsv_t) {HSV_MAGENTA};
//        hsv.v = 250;
//    };
    // layer information: _OTHER
//    if (keycode == OSL(_OTHER)) {
//        hsv = (hsv_t) {HSV_MAGENTA};
//        hsv.v = 100;
//    };
//    if (row == 5 && col == 6 && layer == _OTHER) {
//        hsv = (hsv_t) {HSV_MAGENTA};
//        hsv.v = 250;
//    };
    // lock layer: red for locking
    if (keycode == QK_LLCK) {
        hsv = (hsv_t) {HSV_RED};
        hsv.v = 250;
    };

    // the 4 "left" modifier keys
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
    // in case "right" mod (only via ralt) gets activated
    if (keycode == OSM(MOD_RALT)) {
        // slightly darker green
        hsv = (hsv_t) {150, 130, 50};
        if ((mds | osm) & MOD_BIT(4)) {
            hsv.v = 250;
        };
    };

    // leader sequence stuff. Will override everything else
#ifdef LEADER_ENABLE
#then
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
            case QK_LEAD:
                //maybe make it pulse? :-D
                hsv = (hsv_t) {HSV_MAGENTA};
                hsv.v = 250;
        };
    };
#endif


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

/* KEY OVERRIDE
 */

const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BACKSPACE, KC_DEL);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    &delete_key_override
};


/* LEADER KEY
 */


//void leader_start_user(void) {
//    // Do something when the leader key is pressed
//};

/* Leader sequences allow for vim-like command sequences
 * https://docs.qmk.fm/features/leader_key
 */
//void leader_end_user(void) {
//    // noop or abort
//    if (leader_sequence_one_key(KC_ESCAPE)) {
//    };
//    // reboot into bootloader
//    if (leader_sequence_two_keys(KC_Q, KC_B)) {
//        reset_keyboard();
//    };
//    // switch to vty-1 (ctrl-alt-f1) or vty-7
//    if (leader_sequence_two_keys(KC_V, KC_Z)) {
//        tap_code16(LCTL(LALT(KC_F1)));
//    };
//    if (leader_sequence_two_keys(KC_V, KC_X)) {
//        tap_code16(LCTL(LALT(KC_F7)));
//    };
//};

enum combos {
    // left-hand side of the keyboard
    FP_ESCAPE,
    ST_LCTL,
    RT_LGUI,
    AT_LALT,
    RST_LCTLLGUI,
    // right-hand side of the keyboard
    LU_ENTER,
    NE_LCTL,
    NI_LGUI,
    NO_LALT,
    NEI_LCTLLGUI,
    // termination
    COMBO_LENGTH
};

const uint16_t PROGMEM fp_combo[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM st_combo[] = {KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM rt_combo[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM at_combo[] = {KC_A, KC_T, COMBO_END};
const uint16_t PROGMEM rst_combo[] = {KC_R, KC_S, KC_T, COMBO_END};

const uint16_t PROGMEM lu_combo[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM ne_combo[] = {KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM ni_combo[] = {KC_N, KC_I, COMBO_END};
const uint16_t PROGMEM no_combo[] = {KC_N, KC_O, COMBO_END};
const uint16_t PROGMEM nei_combo[] = {KC_N, KC_E, KC_I, COMBO_END};



combo_t key_combos[] = {
    //arst
    [FP_ESCAPE] = COMBO(fp_combo, KC_ESC),
    [ST_LCTL]   = COMBO(st_combo, KC_LCTL),
    [RT_LGUI]   = COMBO(rt_combo, KC_LGUI),
    [AT_LALT]   = COMBO(at_combo, KC_LALT),
    [RST_LCTLLGUI]   = COMBO(rst_combo, LCTL(KC_LGUI)),
    //
    [LU_ENTER] = COMBO(lu_combo, KC_ENTER),
    [NE_LCTL] = COMBO(ne_combo, KC_LCTL),
    [NI_LGUI] = COMBO(ni_combo, KC_LGUI),
    [NO_LALT] = COMBO(no_combo, KC_LALT),
    [NEI_LCTLLGUI] = COMBO(nei_combo, LCTL(KC_LGUI)),
};

