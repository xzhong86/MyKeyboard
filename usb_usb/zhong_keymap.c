/*
Copyright 2018 BruceZh <xzhong86@??.com>
*/

#include "keymap_zhong.h"
#include "board.h"
#include "led.h"

/*<%
load './gen-keymap.rb'
k60 = Keymap.new("
  KEYMAP_K60( ESC, 
    GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC, 
    TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS, 
    CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,  
    LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,          RSFT, 
    LCTL,LGUI,LALT,               SPC,                RALT,RGUI,APP, RCTL  
  )")
k60_num2fn = k60.map_key({
  '1' => 'F1', '2' => 'F2', '3' => 'F3', '4' => 'F4', '5' => 'F5', '6' => 'F6',
  '7' => 'F7', '8' => 'F8', '9' => 'F9', '0' => 'F10', MINS: 'F11', EQL: 'F12',
  others: 'TRNS'
})
k60_move = k60.map_key({
  I: 'UP', K: 'DOWN', J: 'LEFT', L: 'RGHT', U: 'PGUP', N: 'PGDN', H: 'HOME', O: 'END',
  others: 'TRNS'
})
k60_spcfn = k60.map_key({
  ESC: 'GRV', X: 'DEL', B: 'SPC', COMM: 'BSPC', DOT: 'DEL',
  SCLN: 'NO', QUOT: 'NO', SLSH: 'NO',
  trans_keys: [/[A-Z]/, 'NO'],
  others: 'TRNS'
}).merge(k60_num2fn) #.merge(k60_move)
k60_edit = k60.map_key({
  D: 'LSFT', S: 'LCTL', A: 'LALT', W: 'TAB', COMM: 'BSPC', DOT: 'DEL',
  SCLN: 'NO', QUOT: 'NO', SLSH: 'NO',
  trans_keys: [/[A-Z]/, 'NO'],
  others: 'TRNS'
}).merge(k60_move)
#k60_spcfn.dump
%>*/

enum {
    LAYER_DEFAULT,
    LAYER_SPCFN,
    LAYER_SHIFT,
    LAYER_EDIT,
    LAYER_SCLN,
};
enum {
    KC_mCAPS = KC_FN0,
    KC_WINL ,   KC_WINR ,
    KC_SPCFN,
    KC_mLSFT,   KC_mRSFT,
    KC_mEdit,
    KC_mSCLN,
};

const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
    [LAYER_DEFAULT] = <%= k60.map_key(CAPS: "mCAPS", SPC: "SPCFN", LSFT: "mLSFT", RSFT: "mRSFT", F: "mEdit").to_code %>,
    [LAYER_SPCFN] = <%= k60.map_key(E: "WINL", R: "WINR", P: "PSCR", others: "TRNS").merge(k60_spcfn).to_code %>,
    [LAYER_SHIFT] = <%= k60.map_key(ESC: "GRV", BSPC: "BSLS", F: "F", others: "TRNS").to_code %>,
    [LAYER_EDIT]  = <%= k60_edit.to_code %>,
    //[LAYER_SCLN]  = <%= k60_move.to_code %>,
};

const action_t PROGMEM fn_actions[] = {
    [KC_mCAPS - KC_FN0]   = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_CAPS),
    [KC_WINL  - KC_FN0]   = ACTION_MODS_KEY(MOD_LGUI | MOD_LCTL, KC_LEFT),
    [KC_WINR  - KC_FN0]   = ACTION_MODS_KEY(MOD_LGUI | MOD_LCTL, KC_RIGHT),
    [KC_SPCFN - KC_FN0]   = ACTION_LAYER_TAP_KEY(LAYER_SPCFN, KC_SPACE),
    //[KC_mSCLN - KC_FN0]   = ACTION_LAYER_TAP_KEY(LAYER_SCLN, KC_SCLN),
    [KC_mEdit - KC_FN0]   = ACTION_LAYER_TAP_KEY(LAYER_EDIT, KC_F),
    [KC_mLSFT - KC_FN0]   = ACTION_LAYER_MODS(LAYER_SHIFT, MOD_LSFT),
    [KC_mRSFT - KC_FN0]   = ACTION_LAYER_MODS(LAYER_SHIFT, MOD_RSFT),
};

void hook_layer_change(uint32_t layer_state)
{
    if (layer_state & (1 << LAYER_SPCFN))
        LED_SPCFN_ON();
    else
        LED_SPCFN_OFF();
}

void board_led_set(uint8_t usb_led)
{
    if (usb_led & (1<<USB_LED_CAPS_LOCK))
        LED_CAPS_ON();
    else
        LED_CAPS_OFF();
    //if (usb_led & (1<<USB_LED_NUM_LOCK))
    //if (usb_led & (1<<USB_LED_SCROLL_LOCK))
}
