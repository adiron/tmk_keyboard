#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: qerty */
    KEYMAP(TAB,  Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   BSPC, FN1, \
           FN0,   A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,FN0, \
           FN1,LSFT,   Z,   X,   C,   V,   B,   N,   M,   COMM,DOT,SLSH,RSFT, \
           LCTL,        SPC,      FN2),

    /* 1: FN 1 */
    KEYMAP(GRV,  FN4, FN5, FN6, FN7, FN8, FN9,FN10,FN11,FN12,FN13,  DEL, BSPC, \
           TRNS, BSLS,QUOT,MINS, EQL,LBRC,RBRC,DOWN,  UP,LEFT,RGHT,  TRNS, \
           TRNS, TRNS,ESC,FN20,PSCR,TRNS,TRNS,TRNS,MSTP,MPLY,MPRV,MNXT, TRNS, \
           TRNS,    TRNS,     TRNS),

    /* 2: FN 2 */
    KEYMAP(FN3,    1,   2,   3,   4,   5,   6,   7,   8,   9,   0, TRNS, TRNS, \
           ESC, FN14,FN15,FN16,FN17,FN18,FN19,   4,   5,   6,VOLU,  ENT, \
           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,   0,   1,   2,   3,VOLD,  TRNS, \
           TRNS,      TRNS, TRNS),

    /* 3:  Game Mode */
    KEYMAP(TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  F1,  F2,  F3,  F4, TRNS, TRNS, \
           ESC, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  F5,  F6,  F7,  F8,  ENT, \
           TRNS, TRNS,    1,   2,   3,   4,   5,   6,  F9, F10, F11, F12,TRNS, \
           TRNS, TRNS, TRNS),
};

const action_t PROGMEM fn_actions[] = {
    [0]  = ACTION_LAYER_MOMENTARY(1),
    [1]  = ACTION_LAYER_MOMENTARY(2),
    [2]  = ACTION_LAYER_TOGGLE(3),
    [3]  = ACTION_MODS_KEY(MOD_LSFT, KC_GRV),
    [4]  = ACTION_MODS_KEY(MOD_LSFT, KC_1),
    [5]  = ACTION_MODS_KEY(MOD_LSFT, KC_2),
    [6]  = ACTION_MODS_KEY(MOD_LSFT, KC_3),
    [7]  = ACTION_MODS_KEY(MOD_LSFT, KC_4),
    [8]  = ACTION_MODS_KEY(MOD_LSFT, KC_5),
    [9]  = ACTION_MODS_KEY(MOD_LSFT, KC_6),
    [10] = ACTION_MODS_KEY(MOD_LSFT, KC_7),
    [11] = ACTION_MODS_KEY(MOD_LSFT, KC_8),
    [12] = ACTION_MODS_KEY(MOD_LSFT, KC_9),
    [13] = ACTION_MODS_KEY(MOD_LSFT, KC_0),
    [14] = ACTION_MODS_KEY(MOD_LSFT, KC_BSLS),
    [15] = ACTION_MODS_KEY(MOD_LSFT, KC_QUOT),
    [16] = ACTION_MODS_KEY(MOD_LSFT, KC_MINS),
    [17] = ACTION_MODS_KEY(MOD_LSFT, KC_EQL),
    [18] = ACTION_MODS_KEY(MOD_LSFT, KC_LBRC),
    [19] = ACTION_MODS_KEY(MOD_LSFT, KC_RBRC)
};
