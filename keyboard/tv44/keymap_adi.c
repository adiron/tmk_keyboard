#include "keymap_common.h"

enum macro_id {
    EMAIL,
    FUCK
};

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: qwerty */
    KEYMAP(GRV,  Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   BSPC, \
           TAB,   A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT, \
           LSFT,   Z,   X,   C,   V,   B,   N,   M,   COMM,DOT,SLSH,RSHIFT, \
           LCTL,  LALT,  LGUI, SPC,      ENTER,      RGUI,  FN1, FN2, FN2),

    /* 1: FN 1  - functions and extras layer. */
    KEYMAP(F1,  F2, F3, F4, F5, F6, F7, F8, F9, F10, F11,   F12, \
           TRNS, TRNS,TRNS,TRNS, TRNS,TRNS,TRNS,MPRV,  MPLY,MNXT,TRNS,  TRNS, \
           TRNS, FN5,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,VOLD,VOLU,BSLASH, RSFT, \
           TRNS, TRNS,  TRNS, TRNS,    TRNS,     TRNS, TRNS, TRNS, FN0),

    /* 2: FN 2  - Mousekeys!!! */
   KEYMAP(FN7,FN8,TRNS,TRNS,TRNS,TRNS,TRNS,BTN1, BTN2,TRNS,TRNS, TRNS, \
          TRNS,TRNS,TRNS,TRNS,MS_WH_UP,MS_WH_DOWN,TRNS,  MS_DOWN,  MS_UP,  MS_RIGHT,  TRNS,  TRNS, \
          TRNS,    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,  TRNS, TRNS, TRNS, TRNS,TRNS, \
          TRNS, TRNS,     TRNS,  TRNS,       TRNS,      TRNS, TRNS, TRNS, TRNS),

    /* 3: FN 3 - Spacebar modifier layer thing  */
    KEYMAP(ESC, 1,2,3,4,5,6,7,  8,  9,  0,  DELETE, \
           CAPS, MINUS,EQUAL,LBRACKET,RBRACKET,TRNS,LEFT,  DOWN,  UP,  RIGHT,  FN6,  TRNS, \
           TRNS,    TRNS,   TRNS,   FN5,   TRNS,   TRNS,   END,  PGDOWN, PGUP, HOME, BSLASH,TRNS, \
           TRNS, TRNS,     TRNS,  TRNS,       FN4,      TRNS, TRNS, TRNS, TRNS),

    /* 4: Numpad! */
   KEYMAP(TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,KP_7, KP_8,KP_9,TRNS, TRNS, \
          TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  KP_4,  KP_5,  KP_6,  TRNS,  TRNS, \
          TRNS,    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,  KP_1, KP_2, KP_3, TRNS,TRNS, \
          TRNS, TRNS,     TRNS,  TRNS,       KP_0,      KP_DOT, TRNS, TRNS, TRNS),

   /* 5:  LED Mode */
   KEYMAP(TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, TRNS, \
          TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  TRNS,  TRNS,  TRNS,  TRNS,  TRNS, \
          TRNS,    TRNS,   TRNS,   TRNS,   TRNS,   TRNS,   TRNS,  TRNS, TRNS, TRNS, TRNS,TRNS, \
          TRNS, TRNS,     TRNS,  TRNS,       TRNS,      TRNS, TRNS, TRNS, TRNS),
};

const uint16_t PROGMEM fn_actions[] = {
    [0]  = ACTION_LAYER_TOGGLE(1), // L1 lock
    [1]  = ACTION_LAYER_MOMENTARY(1), // L1 normal
    [2]  = ACTION_LAYER_TAP_TOGGLE(2), //  L2 lock or toggle
    [3]  = ACTION_LAYER_TAP_KEY(3, KC_SPC), // L3 space
    [4]  = ACTION_LAYER_TOGGLE(3), // L3 lock
    [5]  = ACTION_BACKLIGHT_TOGGLE(), // Backlight toggle
    [6]  = ACTION_LAYER_TOGGLE(4), // Toggle the numpad layer
    [7]  = ACTION_MACRO(EMAIL), // Type out my email address.
    [8]  = ACTION_MACRO(FUCK), // Type out fuck because I'm 12
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
    [19] = ACTION_MODS_KEY(MOD_LSFT, KC_RBRC),
    [20] = ACTION_LAYER_TOGGLE(4),
    [21] = ACTION_LAYER_TAP_KEY(1, KC_QUOT),
    [22] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_ESC)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    keyevent_t event = record->event;
    //uint8_t tap_count = record->tap_count;

    switch (id) {
        case EMAIL:
            return (event.pressed ?
                    MACRO( T(A), T(D), T(I), D(RSHIFT), T(2), U(RSHIFT),  T(A), T(D), T(I), T(R), T(O), T(N), T(DOT), T(M), T(E)) :
                    MACRO( END ));
        case FUCK:
            return (event.pressed ?
                    MACRO( T(F), T(U), T(C), T(K) ) :
                    MACRO( END ));
    }
    return MACRO_NONE;
};
