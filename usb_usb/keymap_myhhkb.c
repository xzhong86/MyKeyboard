/*
Copyright 2018 BruceZh <xzhong86@??.com>

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

#include "keymap_common.h"
#include "board.h"

/*         ,---------------. ,---------------. ,---------------. ,-----------.
 *         |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau|
 *         `---------------' `---------------' `---------------' `-----------'
 * ,-----------------------------------------------------------. ,-----------.
 * |ESC|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  `|  \| |Ins|Hom|PgU|
 * |-----------------------------------------------------------| |-----------|
 * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  Bsp| |Del|End|PgD|
 * |-----------------------------------------------------------| `-----------'
 * |Ctl   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  Return|              
 * |-----------------------------------------------------------|     ,---.    
 * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /|Shift |   |     |Up |    
 * |-----------------------------------------------------------' ,-----------.
 *     |Gui|Alt|           Space               |Alt|Gui|         |Lef|Dow|Rig|
 *     `-----------------------------------------------'         `-----------'
 */
#define KEYMAP_HHKB( \
        K3A,K3B,K3C,K3D,  K3E,K3F,K40,K41,  K42,K43,K44,K45,      K46,K47,K48,  \
    K29,K1E,K1F,K20,K21,K22,K23,K24,K25,K26,K27,K2D,K2E,K35,K31,  K49,K4A,K4B,  \
    K2B,K14,K1A,K08,K15,K17,K1C,K18,K0C,K12,K13,K2F,K30,    K2A,  K4C,K4D,K4E,  \
    KE0,K04,K16,K07,K09,K0A,K0B,K0D,K0E,K0F,K33,K34,        K28,                \
    KE1,K1D,K1B,K06,K19,K05,K11,K10,K36,K37,K38,            KE5,      K52,      \
        KE3,KE2,        K2C,                KE6,KE7,              K50,K51,K4F   \
) KEYMAP_ALL( \
             NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO,                                               \
    K29,     K3A,K3B,K3C,K3D,K3E,K3F,K40,K41,K42,K43,K44,K45,      K46,K47,K48,  VOLD,VOLU,MUTE,PWR,NO,      \
    K35, K1E,K1F,K20,K21,K22,K23,K24,K25,K26,K27,K2D,K2E,NO, K2A,  K49,K4A,K4B,  NO, NO, NO, NO,    NO, NO,  \
    K2B, K14,K1A,K08,K15,K17,K1C,K18,K0C,K12,K13,K2F,K30,    K31,  K4C,K4D,K4E,  NO, NO, NO, NO,    NO, NO,  \
    CAPS,K04,K16,K07,K09,K0A,K0B,K0D,K0E,K0F,K33,K34,    NO, K28,                NO, NO, NO, NO,    NO, NO,  \
    KE1, NO, K1D,K1B,K06,K19,K05,K11,K10,K36,K37,K38,    NO, KE5,      K52,      NO, NO, NO, NO,    NO, NO,  \
    KE0, KE3,KE2,NO, NO,     K2C,    NO, NO, NO, KE6,KE7,APP,RCTL, K50,K51,K4F,  NO,     NO, NO,    NO, NO \
)


enum {
	LAYER_DEFAULT,
	LAYER_MAP_SPACEFN,
	LAYER_MAP_FN,
	LAYER_SHIFT_MAP
};

const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
  // (FN+p)BRK=>PSCR, (FN+i)PSCR=>BRK
  // RALT=>FN0
  [LAYER_DEFAULT] = KEYMAP_HHKB(
         F1,  F2,  F3,  F4,     F5,  F6,  F7,  F8,    F9,  F10, F11, F12,       BRK, SLCK,PSCR,
    ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, GRV,BSLS,  INS, HOME,PGUP,
    TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,    BSPC,  DEL, END, PGDN,
    LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,         ENT,
    FN2, Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,              FN3,        UP,
         LGUI,LALT,          FN1,                FN0, RGUI,                     LEFT,DOWN,RGHT
  ),
#define FN_OpenFnMap  0
#define FN_SpaceFn    1
#define FN_LShiftMap  2
#define FN_RShiftMap  3

  [LAYER_MAP_SPACEFN] = KEYMAP_HHKB(
         NO,  NO,  NO,  NO,     NO,  NO,  NO,  NO,    NO,  NO,  NO,  NO,        NO,  NO,  NO,
    GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,TRNS,TRNS,  NO,  NO,  NO,
    TRNS,NO,  NO,  NO,  NO,  NO,  NO,  PGUP,UP,  END, NO,  NO,  BSPC,    DEL,   NO,  NO,  NO,
    TRNS,NO,  NO,  NO,  NO,  NO,  HOME,LEFT,DOWN,RGHT,NO,  GRV,          TRNS,
    TRNS,NO,  DEL, NO,  NO,  SPC, PGDN,NO,  NO,  NO,  NO,                TRNS,       NO,
         TRNS,TRNS,               TRNS,          TRNS,TRNS,                     NO,  NO,  NO
  ),


  [LAYER_MAP_FN] = KEYMAP_HHKB(
         NO,  NO,  NO,  NO,     NO,  NO,  NO,  NO,    NO,  NO,  NO,  NO,        NO,  NO,  NO,
    NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,   NO,  NO,  NO,
    NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  PSCR,SLCK,PAUS,     NO,   NO,  NO,  NO,
    NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,            NO,
    CAPS,NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,                 CAPS,      NO,
         NO,  NO,                 NO,            NO,  NO,                       NO,  NO,  NO
  ),

  [LAYER_SHIFT_MAP] = KEYMAP_HHKB(
         TRNS,TRNS,TRNS,TRNS,   TRNS,TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,TRNS,      TRNS,TRNS,TRNS,
    GRV, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     BSLS, TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS,
    LSFT,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,               RSFT,      TRNS,
         TRNS,TRNS,               TRNS,          TRNS,TRNS,                     TRNS,TRNS,TRNS
  ),

};

const action_t PROGMEM fn_actions[] = {
    [FN_OpenFnMap]      = ACTION_LAYER_MOMENTARY(LAYER_MAP_FN),
    [FN_SpaceFn]        = ACTION_LAYER_TAP_KEY(LAYER_MAP_SPACEFN, KC_SPACE),
    [FN_LShiftMap]      = ACTION_LAYER_MODS(LAYER_SHIFT_MAP, MOD_LSFT),
    [FN_RShiftMap]      = ACTION_LAYER_MODS(LAYER_SHIFT_MAP, MOD_RSFT),
};

void hook_layer_change(uint32_t layer_state)
{
    if (layer_state & (1 << LAYER_MAP_SPACEFN)) {
        LED_SPCFN_ON();
    } else {
        LED_SPCFN_OFF();
    }
}
