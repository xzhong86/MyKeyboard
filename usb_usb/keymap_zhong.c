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

enum {
	LAYER_DEFAULT,
	LAYER_MAP_SPACEFN,
	LAYER_MAP_FN,
	LAYER_SHIFT_MAP,
	//LAYER_DIS_SPACEFN,
	//LAYER_DIS_CAPSASCTL,
};

#define FN_OpenFnMap     0
#define FN_SpaceFn       1
//#define FN_DisSpaceFn    2
#define FN_DisCapsAsCtl  3
#define FN_ToggleSpcfn   4
//#define FN_KbdLock       4
#define FN_LShiftMap     5
#define FN_RShiftMap     6
#define FN_WinLeft       7
#define FN_WinRight      8

const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
  // RALT => FN0, RGUI => RALT, APP => RGUI, CAPS => LCTL
  [LAYER_DEFAULT] = KEYMAP_K87(
    ESC,      F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,      PSCR,SLCK,BRK,
    GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,     INS, HOME,PGUP,
    TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,     DEL, END, PGDN,
    LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,
    FN5, Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,          FN6,           UP,
    LCTL,LGUI,LALT,          FN1,                     FN0, RALT,RGUI,RCTL,     LEFT,DOWN,RGHT
  ),

  [LAYER_MAP_SPACEFN] = KEYMAP_K87(
    GRV,      NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,    NO,  NO,  NO,
    NO,  F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, TRNS,  NO,  NO,  NO,
    TRNS,FN4, NO,  FN7, FN8, NO,  NO,  PGUP,UP,  END, NO,  NO,  BSPC,DEL,   NO,  NO,  NO,
    TRNS,NO,  NO,  NO,  NO,  NO,  HOME,LEFT,DOWN,RGHT,NO,  GRV,      TRNS,
    TRNS,NO,  DEL, NO,  NO,  SPC, PGDN,NO,  NO,  NO,  NO,            TRNS,       NO,
    TRNS,TRNS,TRNS,               TRNS,               TRNS,TRNS,TRNS,TRNS,  NO,  NO,  NO
  ),

  [LAYER_MAP_FN] = KEYMAP_K87(
    NO,       NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,    NO,  NO,  NO,
    NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,    NO,  NO,  NO,
    CAPS,NO,  FN4, NO,  NO,  NO,  NO,  NO,  NO,  NO,  PSCR,SLCK,PAUS,NO,    NO,  NO,  NO,
    NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,       NO,
    CAPS,NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,            CAPS,       NO,
    NO,  NO,  NO,                 NO,                 NO,  NO,  NO,  NO,    NO,  NO,  NO
  ),

#if 0
  [LAYER_DIS_SPACEFN] = KEYMAP_K87(
    TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS,       TRNS,
    TRNS,TRNS,TRNS,               SPC,                TRNS,TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS
  ),
#endif
#if 0
  [LAYER_DIS_CAPSASCTL] = KEYMAP_K87(
    TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,
    CAPS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS,       TRNS,
    TRNS,TRNS,TRNS,               TRNS,               TRNS,TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS
  ),
#endif

  [LAYER_SHIFT_MAP] = KEYMAP_K87(
    GRV,      TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS,       TRNS,
    TRNS,TRNS,TRNS,               TRNS,               TRNS,TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS
  ),

};

const action_t PROGMEM fn_actions[] = {
    [FN_OpenFnMap]      = ACTION_LAYER_MOMENTARY(LAYER_MAP_FN),
    [FN_SpaceFn]        = ACTION_LAYER_TAP_KEY(LAYER_MAP_SPACEFN, KC_SPACE),
//    [FN_DisSpaceFn]     = ACTION_LAYER_TOGGLE(LAYER_DIS_SPACEFN),
//    [FN_DisCapsAsCtl]   = ACTION_LAYER_TOGGLE(LAYER_DIS_CAPSASCTL),
    [FN_ToggleSpcfn]    = ACTION_LAYER_TOGGLE(LAYER_MAP_SPACEFN),
//    [FN_LGuiAsFn]       = ACTION_LAYER_TOGGLE(LAYER_LGUI_AS_FN),
//    [FN_OpenSpcFnMap]   = ACTION_LAYER_MOMENTARY(LAYER_MAP_SPACEFN),
    [FN_LShiftMap]      = ACTION_LAYER_MODS(LAYER_SHIFT_MAP, MOD_LSFT),
    [FN_RShiftMap]      = ACTION_LAYER_MODS(LAYER_SHIFT_MAP, MOD_RSFT),
    [FN_WinLeft]        = ACTION_MODS_KEY(MOD_LGUI | MOD_LCTL, KC_LEFT),
    [FN_WinRight]       = ACTION_MODS_KEY(MOD_LGUI | MOD_LCTL, KC_RIGHT),
};

void hook_layer_change(uint32_t layer_state)
{
    if (layer_state & (1 << LAYER_MAP_SPACEFN)) {
        LED_SPCFN_ON();
    } else {
        LED_SPCFN_OFF();
    }
}
