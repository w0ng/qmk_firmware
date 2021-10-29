/* Copyright 2021 Andrew Wong
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _RAISE,
};

#define RAISE LM(_RAISE, MOD_LSFT)

 /**
 * Convenience initializer to create a shift mod override for custom keys defined in _RAISE layer.
 */
#define shift_ko_make(trigger_key) \
    ko_make_basic(MOD_MASK_SHIFT, trigger_key, trigger_key)

/**
 *
 * ,-------------------------------------------------------------------------------------------------------------------.
 * | Esc    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F8  |  F9  |  F10 |  F12 | PSCR | SLCK | PAUS |  FN0 | RESET  |
 * |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------|
 * | |`     |  +1  |  [2  |  {3  |  (4  |  &5  |                           |  =6  |  )7  |  }8  |  ]9  |  *0  | !%     |
 * |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
 * | Tab    |  ;:  |  ,<  |  .>  |   P  |   Y  |                           |   F  |   G  |   C  |   R  |   L  | \#     |
 * |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
 * | Ctrl   |   A  |   O  |   E  |   U  |   I  |                           |   D  |   H  |   T  |   N  |   S  | -_     |
 * |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
 * | Shift  |  '"  |   Q  |   J  |   K  |   X  |                           |   B  |   M  |   W  |   V  |   Z  | Shift  |
 * `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'
 *          | $~   |  \|  | Left | Right|                                         | Down |  Up  |   /?  |  @^ |
 *          `---------------------------'                                         `---------------------------'
 *                                        ,-------------.         ,-------------.
 *                                        | Gui  | Ctrl |         | Ctrl | Gui  |
 *                                 ,------|------|------|         |------+------+------.
 *                                 |      |      | Alt  |         | Alt  |      |      |
 *                                 | BkSp | Del  |------|         |------|Return| Space|
 *                                 |      |      | Shift|         | Shift|      |      |
 *                                 `--------------------'         `--------------------'
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT(
    // Left Hand
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,
    KC_PIPE, KC_PLUS, KC_LBRC, KC_LCBR, KC_LPRN, KC_AMPR,
    KC_TAB,  KC_SCLN, KC_COMM, KC_DOT,  KC_P,    KC_Y,
    KC_LCTL, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,
    RAISE,   KC_QUOT, KC_Q,    KC_J,    KC_K,    KC_X,
             KC_DLR,  KC_BSLS, KC_LEFT, KC_RGHT,
    // Left Thumb
             KC_LGUI, KC_LCTL,
                      KC_LALT,
    KC_BSPC, KC_DEL,  RAISE,
    // Right Hand
    KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SLCK, KC_PAUS, KC_FN0,  RESET,
    KC_EQL,  KC_RPRN, KC_RCBR, KC_RBRC, KC_ASTR, KC_EXLM,
    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSLS,
    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    RAISE,
             KC_DOWN, KC_UP,   KC_SLSH, KC_AT,
    // Right Thumb
    KC_RCTL, KC_RGUI,
    KC_RALT,
    RAISE,   KC_ENTER, KC_SPC
),

[_RAISE] = LAYOUT(
    // Left Hand
    _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
             KC_TILD, _______, _______, _______,
    // Left Thumb
             _______, _______,
                      _______,
    _______, _______, _______,
    // Right Hand
    _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PERC,
    _______, _______, _______, _______, _______, KC_HASH,
    _______, _______, _______, _______, _______, KC_UNDS,
    _______, _______, _______, _______, _______, _______,
             _______, _______, KC_QUES, KC_CIRC,
    // Right Thumb
    _______, _______,
    _______,
    _______, _______, _______
),

};

// Shift override: _RAISE left hand keys
const key_override_t shift_grave_override = shift_ko_make(KC_GRV);
const key_override_t shift_1_override = shift_ko_make(KC_1);
const key_override_t shift_2_override = shift_ko_make(KC_2);
const key_override_t shift_3_override = shift_ko_make(KC_3);
const key_override_t shift_4_override = shift_ko_make(KC_4);
const key_override_t shift_5_override = shift_ko_make(KC_5);
const key_override_t shift_tilde_override = shift_ko_make(KC_TILD);

// Shift override: _RAISE right hand keys
const key_override_t shift_6_override = shift_ko_make(KC_6);
const key_override_t shift_7_override = shift_ko_make(KC_7);
const key_override_t shift_8_override = shift_ko_make(KC_8);
const key_override_t shift_9_override = shift_ko_make(KC_9);
const key_override_t shift_0_override = shift_ko_make(KC_0);
const key_override_t shift_percent_override = shift_ko_make(KC_PERC);
const key_override_t shift_hash_override = shift_ko_make(KC_HASH);
const key_override_t shift_underscore_override = shift_ko_make(KC_UNDS);
const key_override_t shift_question_override = shift_ko_make(KC_QUES);
const key_override_t shift_circumflex_override = shift_ko_make(KC_CIRC);

const key_override_t **key_overrides = (const key_override_t *[]) {
    &shift_grave_override,
    &shift_1_override,
    &shift_2_override,
    &shift_3_override,
    &shift_4_override,
    &shift_5_override,
    &shift_tilde_override,
    &shift_6_override,
    &shift_7_override,
    &shift_8_override,
    &shift_9_override,
    &shift_0_override,
    &shift_percent_override,
    &shift_hash_override,
    &shift_underscore_override,
    &shift_question_override,
    &shift_circumflex_override,
    NULL
};
