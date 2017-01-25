#include "keymap_common.h"

#define ENTFN FN0
#define RAISE FN1
#define UTILS FN2

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: QWERTY */
    KEYMAP(GRV,  Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   BSPC, \
           TAB,   A,   S,   D,   F,   G,   H,   J,   K,   L,  FN10,FN2, \
           LSFT,   Z,   X,   C,   V,   B,   N,   M,  COMM,DOT,SLSH,RSFT, \
           LCTL,  LALT,  LGUI, SPC,    FN0,    FN1, RGUI, RCTL),

    /* 1: Raise layer */
    KEYMAP(CAPS,  1, 2, 3, 4, 5, 6,7,8,9,0,  DEL, \
            ESC, F1,F2,F3, F4,F5,F6, MINS,EQL,LBRC,RBRC,  BSLS, \
           TRNS, F7,F8,F9, F10,F11,F12,NUHS,NUBS,PGUP,PGDN, TRNS, \
           TRNS, TRNS,  TRNS, FN12,    FN13,     TRNS, TRNS, FN3),

    /* 2: ENTFN layer */
    KEYMAP(TRNS,  FN6, FN7, TRNS, TRNS, TRNS, TRNS,TRNS,TRNS,FN8,FN9,  DEL, \
            ESC, TRNS, MS_WH_LEFT, MS_WH_UP, MS_WH_DOWN, MS_WH_RIGHT, LEFT, DOWN, UP, RIGHT, TRNS,  FN11, \
           TRNS, FN4,FN5,TRNS, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, TRNS, \
           TRNS, TRNS,  TRNS, TRNS,    TRNS,     TRNS, TRNS, FN3),

    /* 3: Utils */
    KEYMAP(TRNS,  SLCK,   PAUS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS, \
           TRNS,   VOLU,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS, MEDIA_REWIND, MPLY, MEDIA_FAST_FORWARD, TRNS, TRNS, \
           TRNS,   VOLD,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS, TRNS, TRNS,TRNS,TRNS,TRNS, \
           TRNS, TRNS,  TRNS, TRNS,    TRNS,     TRNS, TRNS, TRNS),
    /* 4: Mousekeys */
    KEYMAP(TRNS,  TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   BTN1,   BTN2,   TRNS,   TRNS,   TRNS,   TRNS, \
           TRNS,  TRNS, MS_WH_LEFT, MS_WH_UP ,MS_WH_DOWN, MS_WH_RIGHT, MS_L, MS_D, MS_U, MS_R, TRNS,TRNS, \
           TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS, TRNS, TRNS,TRNS,TRNS,TRNS, \
           TRNS, TRNS,  TRNS, TRNS,    TRNS,     TRNS, TRNS, TRNS),
};

const action_t PROGMEM fn_actions[] = {
    [0]  = ACTION_LAYER_TAP_KEY(2, KC_ENT), // ENTFN
    [1]  = ACTION_LAYER_MOMENTARY(1), // RAISE
    [2]  = ACTION_LAYER_TAP_KEY(3, KC_QUOT), // UTILS
    [3]  = ACTION_BACKLIGHT_STEP(), // Backlight toggle
    [4]  = ACTION_MACRO(0),
    [5]  = ACTION_MACRO(1),
    [6]  = ACTION_MACRO(2),
    [7]  = ACTION_MACRO(3),
    [8]  = ACTION_MACRO(4),
    [9]  = ACTION_MACRO(5),
    [10] = ACTION_LAYER_TAP_KEY(4, KC_SCLN),
    [11]  = ACTION_MACRO(6),
    [12]  = ACTION_DEFAULT_LAYER_SET(1), // switch default to RAISE
    [13]  = ACTION_DEFAULT_LAYER_SET(0), // switch default to QWERTY
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    keyevent_t event = record->event;

    switch (id) {
        case 0:
            /* Command + [ */
            return (event.pressed ? MACRO( D(LGUI), T(LBRC), U(LGUI), END ) : MACRO(END));
            break;
        case 1:
            /* Command + ] */
            return (event.pressed ? MACRO( D(LGUI), T(RBRC), U(LGUI), END ) : MACRO(END));
            break;
        case 2:
            /* Command + { */
            return (event.pressed ? MACRO( D(LGUI), D(RSFT), T(LBRC), U(RSFT), U(LGUI), END ) : MACRO(END));
            break;
        case 3:
            /* Command + } */
            return (event.pressed ? MACRO( D(LGUI), D(RSFT), T(RBRC), U(RSFT), U(LGUI), END ) : MACRO(END));
            break;
        case 4:
            /* Command + - */
            return (event.pressed ? MACRO( D(LGUI), T(MINS), U(LGUI), END ) : MACRO(END));
            break;
        case 5:
            /* Command + = */
            return (event.pressed ? MACRO( D(LGUI), T(EQL), U(LGUI), END ) : MACRO(END));
            break;
        case 6:
            /* Command + Enter */
            return (event.pressed ? MACRO( D(LGUI), T(ENT), U(LGUI), END ) : MACRO(END));
        default:
            break;
    }
    return MACRO_NONE;
}
