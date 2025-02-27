/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

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

/*Default layout
 *----------------------------------------------------------------------------|
 * ▓▓▓|ESC |▓|~  |1  |2  |3  |4  |5  |6 |▓▓|7  |8  |9  |0  |-  |=  |\  |Del|--|
 * |--------▓---------------------------▓-------------------------------------|
 * ▓▓|PgUp|▓|Tab |Q  |W  |E  |R  |T  |▓▓▓ |Y  |U  |I  |O  |P  |[  | ]  |BSpc |-|
 * |-------▓---------------------------▓▓▓------------------------------------|
 * ▓|PgDn|▓|Caps |A  |S  |D  |F  |G  |▓▓▓▓|H  |J  |K  |L  |;  |'  |  Enter  |-| 
 * |------------------------------------▓▓------------------------------------|
 * ▓▓▓▓▓▓|LShft   |Z  |X  |C  |V  |B  |▓▓▓ |B  |N  |M  |,  |.  |/  |Shift |Fn ||  
 * |-------------------------------------▓▓-----------------------------------|
 * ▓▓▓▓▓▓|Lfalt |▓▓▓▓▓|GUI | Space  |Fn |▓▓▓▓|Space  |GUI |▓▓▓▓▓▓▓▓▓▓▓▓|Alt |-|
 * `--------------------------------------------------------------------------|
 */


extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _FN1 1
#define _FN2 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_default(
    KC_ESC, KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5,      KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_DEL,
    KC_PGUP, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,      KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC,
    KC_PGDN, KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G,     KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,                   KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, MO(_FN2),
    KC_LALT, KC_CAPS, KC_SPC, MO(_FN1),                            KC_SPC, KC_RGUI, KC_RALT
  ),

  [_FN1] = LAYOUT_default(
    KC_VOLU, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,    KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_INS,
    KC_VOLD, KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP, KC_TRNS, KC_TRNS,
    KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_TRNS, KC_LEFT, KC_RGHT, KC_TRNS, KC_TRNS,
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_END, KC_TRNS, KC_DOWN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
      ),

  [_FN2] = LAYOUT_default(
    RGB_TOG,  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,  KC_DEL,
    RGB_MOD,  _______,  _______, KC_UP,  _______, _______, _______,          RGB_SAI, RGB_HUI, RGB_VAI, _______, _______, KC_MEDIA_PLAY_PAUSE, _______, _______,
    RGB_RMOD, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,          RGB_SAD, RGB_HUD, RGB_VAD, _______, KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK,          _______,
              _______, BL_INC,  BL_DEC,  BL_TOGG, BL_BRTG, _______,          _______, _______, _______, _______, _______, KC_MEDIA_STOP, _______, _______,
              KC_SYSTEM_SLEEP,          _______, _______, _______,                            _______,          _______,          RESET
  ),

};
