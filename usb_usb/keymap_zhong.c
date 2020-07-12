/*
Copyright 2018 BruceZh <xzhong86@??.com>
*/

#include "keymap_zhong.h"
#include "board.h"
#include "led.h"

/**/

enum {
    LAYER_DEFAULT,
    LAYER_SPCFN,
    LAYER_SHIFT,
};
enum {
    KC_mCAPS = KC_FN0,
    KC_WINL ,   KC_WINR ,
    KC_SPCFN,
    KC_mLSFT,   KC_mRSFT,
};

const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
    [LAYER_DEFAULT] = KEYMAP_K60(ESC, GRV, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, MINS, EQL, BSPC, TAB, Q, W, E, R, T, Y, U, I, O, P, LBRC, RBRC, BSLS, mCAPS, A, S, D, F, G, H, J, K, L, SCLN, QUOT, ENT, mLSFT, Z, X, C, V, B, N, M, COMM, DOT, SLSH, mRSFT, LCTL, LGUI, LALT, SPCFN, RALT, RGUI, APP, RCTL),
    [LAYER_SPCFN] = KEYMAP_K60(GRV, TRNS, F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12, TRNS, TRNS, NO, NO, WINL, WINR, NO, NO, PGUP, UP, END, PSCR, TRNS, TRNS, TRNS, TRNS, NO, NO, NO, NO, NO, HOME, LEFT, DOWN, RGHT, NO, NO, TRNS, TRNS, NO, DEL, NO, NO, NO, PGDN, NO, BSPC, DEL, NO, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS),
    [LAYER_SHIFT] = KEYMAP_K60(GRV, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, BSLS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS)
};

const action_t PROGMEM fn_actions[] = {
    [KC_mCAPS - KC_FN0]   = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_CAPS),
    [KC_WINL  - KC_FN0]   = ACTION_MODS_KEY(MOD_LGUI | MOD_LCTL, KC_LEFT),
    [KC_WINR  - KC_FN0]   = ACTION_MODS_KEY(MOD_LGUI | MOD_LCTL, KC_RIGHT),
    [KC_SPCFN - KC_FN0]   = ACTION_LAYER_TAP_KEY(LAYER_SPCFN, KC_SPACE),
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
