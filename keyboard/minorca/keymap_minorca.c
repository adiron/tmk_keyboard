#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: ctrl/shift switch */
	 KEYMAP(ESC,   Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P, BSPC, \
			TAB,   A,   S,   D,   F,   G,   H,   J,   K,   L,   ENT, \
			LCTL,  Z,   X,   C,   V,   B,   	N,   M,   COMM,DOT, SLSH, \
			LSFT,  LALT,FN2,	  SPC,	    SPC,      FN0, QUOT, FN1),
    /* 1: colemak */
	 KEYMAP(ESC,   Q,   W,   F,   P,   G,   J,   L,   U,   Y, RGUI, BSPC, \
			BSPC,  A,   R,   S,   T,   D,   H,   N,   E,   I,   O, \
			LSFT,  Z,   X,   C,   V,   B,   K,   M,   COMM,DOT, SLSH, \
			LCTL,  LALT,FN2,	  SPC,	    CAPS,    FN0, QUOT, FN1),
    /* 2: dvorak */
	 KEYMAP(GRV,   QUOT,COMM,DOT, P,   Y,   F,   G,   C,   R,   L, BSPC, \
			TAB,   A,   O,   E,   U,   I,   D,   H,   T,   N,   S, \
			LSFT,  SCLN,Q,   J,   K,   X,   B,   M,   W,   V,   Z, \
			LCTL,  LALT,FN2,	  SPC,	    DEL,     FN0, QUOT, FN1),
    /* 3: hhkb */
	 KEYMAP(GRV,   Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P, DEL, \
			TAB,   A,   S,   D,   F,   G,   H,   J,   K,   L,   ENT, \
			LCTL,  Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH, \
			LSFT,  LALT,FN2,	  CAPS,	    SPC,      FN0, QUOT,FN1),
    /* 4: minorca */
	 KEYMAP(ESC,   Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P, BSPC, \
			TAB,   A,   S,   D,   F,   G,   H,   J,   K,   L,   ENT, \
			LSFT,  Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH, \
			LCTL,  LALT,FN2,	  SPC,	     SPC,     FN0, QUOT, FN1),
    /* 5 arrow */
	 KEYMAP(ESC,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, TRNS, \
			TRNS, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  \
			TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,LEFT,UP, RIGHT, \
			TRNS,  TRNS,FN2,	  FN9,	     TRNS,  FN0, DOWN, FN1),
    /* 6 numfunc */
	 KEYMAP(GRV,   1,   2,   3,   4,   5,   6,   7,   8,   9,   0, DEL, \
			CAPS,  HOME,TRNS,TRNS,PGUP,HOME,MINS,EQL,  LBRC,RBRC, ENT, \
			TRNS,  END, FN9, INS, PGDN, END,  SCLN, BSLS, LEFT,UP, RIGHT, \
			TRNS,   TRNS,FN2,	   LCTL,	        SPC,        FN0, DOWN, RSFT),
    /* 7: layout */
	 KEYMAP(FN5, FN6, FN7, FN8,FN3,TRNS,TRNS,TRNS,TRNS,PGUP,HOME,ESC, \
			PGUP, FN5,FN8,LSFT,RSFT,PAUS,FN29,FN28,PGDN,END,INS,  \
			PGDN,FN11,FN7,FN6, LGUI,L,   TRNS,TRNS,LEFT,UP, RIGHT, \
			FN30,  FN31,FN2,	  FN12,	     FN13,  FN14, DOWN, TRNS),
    /* 8: OSX */
	 KEYMAP(ESC,   Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P, BSPC, \
			TAB,   A,   S,   D,   F,   G,   H,   J,   K,   L,   ENT, \
			LGUI,  Z,   X,   C,   V,   B,   	N,   M,   COMM,DOT, SLSH, \
			LSFT,  LCTL,LALT,	  SPC,	    SPC,      FN0, QUOT, FN14),
    /* 9 numfunc V2 */
	 KEYMAP(UP,   1,   2,   3,   4,   5,   6,   7,   8,   9,   0, DEL, \
			RIGHT,  HOME,PGUP,TRNS,PGUP,HOME,MINS,EQL,  LBRC,RBRC, ENT, \
			LEFT,  END, PGDN, INS, PGDN, END,  SCLN, BSLS, LEFT,UP, RIGHT, \
			DOWN,   FN31,FN2,	   LCTL,	   SPC,        FN0, DOWN, FN1),
};
const action_t PROGMEM fn_actions[] = {
    /* Minorca Layout */
    [0] = ACTION_LAYER_MOMENTARY(6),  // to numfunc overlay
    [1] = ACTION_LAYER_TOGGLE(5),     // toggle arrow overlay
    [2] = ACTION_LAYER_MOMENTARY(7),  // to Layout selector
    [9] = ACTION_LAYER_TOGGLE(4),  // toggle ctrl/shift switch overlay
    [14] = ACTION_LAYER_TOGGLE(4),  // toggle OSX overlay
    [3] = ACTION_LAYER_SET_CLEAR(0),  // back to original minorca layout
    [5] = ACTION_DEFAULT_LAYER_SET(0),  // set minorca layout
    [6] = ACTION_DEFAULT_LAYER_SET(1),  // set colemak layout
    [7] = ACTION_DEFAULT_LAYER_SET(2),  // set dvorak layout
    [8] = ACTION_DEFAULT_LAYER_SET(3),  // set hhkb layout
    [11] = ACTION_DEFAULT_LAYER_SET(0),  // set minorca layout
    [12] = ACTION_LAYER_SET_CLEAR(0),  // back to original minorca layout
    [13] = ACTION_LAYER_SET_CLEAR(4),  // back to original minorca layout
    [30] = ACTION_MODS_KEY(MOD_LALT | MOD_LCTL, KC_DEL),  // lock screen
    [31] = ACTION_LAYER_MOMENTARY(9),  // go up to the other numfunc layer
	};