/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

#pragma once

//#define USE_MATRIX_I2C

#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_ST7565_ENABLE
#define SPLIT_POINTING_ENABLE
#define SPLIT_ACTIVITY_ENABLE

#define LEADER_NO_TIMEOUT
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 500 // TODO: lower?

//back to base layer after 60 min idle
#define LAYER_LOCK_IDLE_TIMEOUT 60000

/*
 * Activating quick-tap would enable hold via double-tap
 */
#define QUICK_TAP_TERM 100
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY
/*
 * If a hold-key is down, while another key is pressed and released, count as held.
 * If the hold-key is instead released before the other key, then handle as two key press events, without the hold event at all
 */
// TODO: it looks like I quite often accidentally trigger the permissive hold rollover to another key, either opening tabs or switching windows. Consider removing the home row mods or reducing the rollover behaviour. Maybe the held key needs to be held longer before counting as held?
#define PERMISSIVE_HOLD
#define HOLD_ON_OTHER_KEYPRESS
#define CHORDAL_HOLD

// trying combos for the modifier keys
#define COMBO_TERM 25
#define COMBO_MUST_HOLD_MODS
#define COMBO_HOLD_TERM 175

#ifdef RGBLIGHT_ENABLE
//    #define RGBLIGHT_EFFECT_BREATHING
//    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
//    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
//    #define RGBLIGHT_EFFECT_SNAKE
//    #define RGBLIGHT_EFFECT_KNIGHT
//    #define RGBLIGHT_EFFECT_CHRISTMAS
//    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
//    #define RGBLIGHT_EFFECT_RGB_TEST
//    #define RGBLIGHT_EFFECT_ALTERNATING
//    #define RGBLIGHT_EFFECT_TWINKLE
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif


//LEADER_ENABLE = yes
//LAYER_LOCK_ENABLE = yes
//MOUSEKEY_ENABLE = yes
