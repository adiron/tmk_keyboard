#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: qerty */
    KEYMAP(KP_7,  KP_8,   KP_9,   KP_PLUS, \
           KP_4,  KP_5,   KP_6,   KP_MINUS, \
           KP_1,  KP_2,   KP_3,   KP_ENTER, \
           KP_0,  KP_DOT, FN0,    BSPC ),

    /* 1: FN 1 */
    KEYMAP(NUMLOCK,  FN1,   TRNS,   VOLU, \
           TRNS,  UP,   TRNS,   VOLD, \
           LEFT,  DOWN,   RIGHT,   TRNS, \
           TRNS,  TRNS,   TRNS, TRNS ),

};

const action_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_TOGGLE(1),
    [1] = ACTION_BACKLIGHT_STEP(),
};
