/*
Copyright 2016 Kai Ryu <kai1103@gmail.com>

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

#include <avr/pgmspace.h>
#include "keycode.h"
#include "action.h"
#include "keymap_common.h"

#define LAYER_SPCFN    1
#define LAYER_SHIFT    2

// Default
const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
    /* Keymap 0: Default Layer
     *    ,-----------------------------.      ,-----------------------------.
     *    |ESC  |  1|  2|  3|  4|  5|  `|      |  -|  6|  7|  8|  9|  0|    =|
     *    |-----+---+---+---+---+-------|      |---+---+---+---+---+---+-----|
     *    |Tab  |  Q|  W|  E|  R|  T|   |      |   |  Y|  U|  I|  O|  P|   BS|
     *    |-----+---+---+---+---|---| Fn|      |  ]|---+---+---+---+---+-----|
     *    |Caps |  A|  S|  D|  F|  G|---|      |---|  H|  J|  K|  L|  ;|Retur|
     *    |-----+---+---+---+---|---|   |      |   |---+---+---+---+---+-----|
     *    |Shift|  Z|  X|  C|  V|  B| Fn|      |  [|  N|  M|  ,|  .|  /|Shift|
     *    `-----+---+---+---+---+-------'      `-------+---+---+---+---+-----'
     *      |Ctr|Gui|Alt|Lef|Rig| ,-------.  ,-------. |Lef| Up|Dow|Rig|  \|
     *      `-------------------' |Esc|Ins|  |Del|Alt| `-------------------'
     *                        ,---+---+---|  |---+---+---.
     *                        |   |   |Hom|  |PgU|   |   |
     *                        |Spc|BS |---|  |---|Tab|Ent|
     *                        |   |   |End|  |PgD|   |   |
     *                        `-----------'  `-----------'
     */
    [0] = KEYMAP(
        ESC, 1,   2,   3,   4,   5,   GRV,   MINS,   6,   7,   8,   9,   0,  EQL,  \
        TAB, Q,   W,   E,   R,   T,    NO,   RBRC,   Y,   U,   I,   O,   P, BSPC,  \
        FN0, A, FN6,   D,   F,   G,                  H,   J,   K,   L,SCLN,  ENT,  \
        FN2, Z,   X,   C,   V,   B,    NO,   LBRC,   N,   M,COMM, DOT,SLSH, QUOT,  \
        LCTL,NO, NO,LGUI,LALT,                         LEFT,  UP,DOWN,RGHT, BSLS,  \
                                  NO,  NO,     NO,  NO,                           \
                                       NO,     NO,                                \
                            SPC, FN1,  NO,     NO, FN3,FN1                       ),

#define FN_Caps       0
#define FN_Move       1
#define FN_LShiftMap  2
#define FN_RShiftMap  3
#define FN_WinLeft    4
#define FN_WinRight   5
#define FN_Sign       6

#define LAYER_SPCFN   1
#define LAYER_SHIFT   2
#define LAYER_SIGN    3

    /* Keymap 1: Fn Layer
     *    ,-----------------------------.      ,-----------------------------.
     *    |     |F1 |F2 |F3 |F4 |F5 |   |      |   |F6 |F7 |F8 |F9 |F10| BS  |
     *    |-----+---+---+---+---+-------|      |---+---+---+---+---+---+-----|
     *    |     |   |   |   |   |   |   |      |   |   |PgU|up |End|   | DEL |
     *    |-----+---+---+---+---|---|   |      |   |---+---+---+---+---+-----|
     *    |     |   |   |   |   |   |---|      |---|Hom|Lef|Dow|Rig|   |     |
     *    |-----+---+---+---+---|---|   |      |   |---+---+---+---+---+-----|
     *    |     |   |Del|   |   |   |   |      |   |PgD|   |   |   |   |     |
     *    `-----+---+---+---+---+-------'      `-------+---+---+---+---+-----'
     */
    [LAYER_SPCFN] = KEYMAP(
        TRNS,  F1,  F2,  F3,  F4,  F5,  NO,    NO,  F6,  F7,  F8,  F9, F10,BSPC, \
        TRNS,TRNS,TRNS, FN4, FN5,TRNS,TRNS,    NO,  NO,PGUP,  UP, END,PSCR, DEL, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,            HOME,LEFT,DOWN,RGHT,  NO,TRNS, \
        TRNS,TRNS, DEL,TRNS,TRNS,TRNS,TRNS,    NO,PGDN,  NO,  NO,  NO,  NO,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,                      TRNS,TRNS,TRNS,TRNS,TRNS, \
                                 TRNS,TRNS,  TRNS,TRNS,                          \
                                      TRNS,  TRNS,                               \
                            TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS                      ),

    /* Sign Layer Keymap:
     *    ,-----------------------------.      ,-----------------------------.
     *    |     |   |   |   |   |   |   |      |   |  6|   |   |   |   |     |
     *    |-----+---+---+---+---+-------|      |---+---+---+---+---+---+-----|
     *    |     |   |   |   |   |   |   |      |   |   | ` | - | = | \ |     |
     *    |-----+---+---+---+---|---|   |      |   |---+---+---+---+---+-----|
     *    |     |   |   |   |   |   |---|      |---|   | ' | [ | ] | ; |     |
     *    |-----+---+---+---+---|---|   |      |   |---+---+---+---+---+-----|
     *    |     |   |   |   |   |   |   |      |   |   |   | , | . | / |     |
     *    `-----+---+---+---+---+-------'      `-------+---+---+---+---+-----'
     */
    [LAYER_SIGN] = KEYMAP(
          NO,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS, TRNS, TRNS,TRNS,  NO, \
          NO,  NO,  NO,  NO,  NO,  NO,  NO,    NO,  NO, GRV, MINS,  EQL,BSLS,  NO, \
          NO,  NO,  NO,  NO,  NO,  NO,              NO,QUOT, LBRC, RBRC,TRNS,  NO, \
        LSFT,  NO,  NO,  NO,  NO,  NO,  NO,    NO,  NO,  NO, TRNS, TRNS,TRNS,  NO, \
          NO,  NO,  NO,  NO,  NO,                        NO,   NO,   NO,  NO,  NO, \
                                   NO,  NO,    NO,  NO,                          \
                                        NO,    NO,                               \
                              NO,  NO,  NO,    NO,RSFT,  NO                      ),

    [LAYER_SHIFT] = KEYMAP(
         GRV,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,BSLS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,            TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,                      TRNS,TRNS,TRNS,TRNS,TRNS, \
                                 TRNS,TRNS,  TRNS,TRNS,                          \
                                      TRNS,  TRNS,                               \
                            TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS                      ),

};

/*
 * Fn action definition
 */
const action_t PROGMEM fn_actions[] = {
    [FN_Move]        = ACTION_LAYER_MOMENTARY(LAYER_SPCFN),
    [FN_Caps]        = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_CAPS),
    [FN_LShiftMap]   = ACTION_LAYER_MODS(LAYER_SHIFT, MOD_LSFT),
    [FN_RShiftMap]   = ACTION_LAYER_MODS(LAYER_SHIFT, MOD_RSFT),
    [FN_WinLeft]     = ACTION_MODS_KEY(MOD_LGUI | MOD_LCTL, KC_LEFT),
    [FN_WinRight]    = ACTION_MODS_KEY(MOD_LGUI | MOD_LCTL, KC_RIGHT),
    [FN_Sign]        = ACTION_LAYER_TAP_KEY(LAYER_SIGN, KC_S),
};

