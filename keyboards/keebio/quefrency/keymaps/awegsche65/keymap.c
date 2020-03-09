#include QMK_KEYBOARD_H
#include "action_layer.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _FN1 1
#define _FN2 2
#define _FNN 4

layer_state_t _cur_layer = 0;

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_65(
        KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_BSPC, KC_HOME,
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
        KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_PGDOWN,
        LSFT_T(KC_CAPS),    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_ESC), KC_UP, KC_END,
        KC_LCTRL, KC_LALT, KC_LGUI, KC_SPC, TT(_FN1),                    MO(_FN1), KC_BSPC, KC_ALGR, MO(_FN2), KC_RCTRL, KC_LEFT, KC_DOWN, KC_RIGHT),

    [_FN1] = LAYOUT_65(
        _______, _______, KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS, _______,    _______, _______, _______, _______, _______, _______, KC_DEL, KC_DEL, _______,
        _______, _______, KC_P7, KC_P8, KC_P9, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_P4, KC_P5, KC_P6, KC_PDOT, _______, _______, _______, _______, _______, KC_BSLS, _______, _______,
        _______, _______, KC_P1, KC_P2, KC_P3, KC_PCMM, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_SPC, KC_P0, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    [_FN2] = LAYOUT_65(_______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_DEL, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    [_FNN] = LAYOUT_65(KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_NO, KC_NO, KC_NO, KC_NO, RGB_TOG, RGB_MOD, _______, KC_UP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_TILD, _______, _______, _______, TT(_FN1), _______, _______, _______, _______, _______, _______, _______, _______)};

layer_state_t layer_state_set_user(layer_state_t state) {
	_cur_layer = get_highest_layer(state);
	    switch (_cur_layer) {
	    case _FN1:
		rgblight_setrgb (0,255,180);
		break;
	    case _FN2:
		rgblight_setrgb (255,128,0);
		break;
	    case _BASE:
		rgblight_setrgb (255,0,0);
		break;
	    default: //  for any other layers, or the default layer
		rgblight_setrgb (255,0,0);
		break;
	    }
  return state;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	//if (_cur_layer > 0)
	if (record->event.pressed) {
		uint16_t _led = 0;
		uint8_t _colr = 0;
		switch (keycode) {
		case KC_1:
			_led = 2;
			_colr = 1;
			break;
		case KC_Q:
			_led = 2;
			_colr = 2;
			break;
		case KC_A:
			_led = 2;
			_colr = 3;
			break;
		case KC_Z:
			_led = 2;
			_colr = 4;
			break;
		case KC_2:
			_led = 2;
			_colr = 1;
			break;
		case KC_W:
			_led = 2;
			_colr = 2;
			break;
		case KC_S:
			_led = 2;
			_colr = 3;
			break;
		case KC_X:
			_led = 2;
			_colr = 4;
			break;
		case KC_3:
			_led = 1;
			_colr = 1;
			break;
		case KC_E:
			_led = 1;
			_colr = 2;
			break;
		case KC_D:
			_led = 1;
			_colr = 3;
			break;
		case KC_C:
			_led = 1;
			_colr = 4;
			break;
		case KC_4:
			_led = 1;
			_colr = 1;
			break;
		case KC_R:
			_led = 1;
			_colr = 2;
			break;
		case KC_F:
			_led = 0;
			_colr = 3;
			break;
		case KC_V:
			_led = 0;
			_colr = 4;
			break;
		case KC_5:
			_led = 0;
			_colr = 1;
			break;
		case KC_T:
			_led = 0;
			_colr = 2;
			break;
		case KC_G:
			_led = 0;
			_colr = 3;
			break;
		case KC_B:
			_led = 0;
			_colr = 4;
			break;
		default:
			_led = 0;
			_colr = 1;
			break;
		} 
		switch(_colr) {
		case 1:
			setrgb(255,128,0, (LED_TYPE *)&led[_led]);
			break;
		case 2:
			setrgb(255,255,0, (LED_TYPE *)&led[_led]);
			break;
		case 3:
			setrgb(100,255,0, (LED_TYPE *)&led[_led]);
			break;
		case 4:
			setrgb(0,255,50, (LED_TYPE *)&led[_led]);
			break;
		default:
			setrgb(255,0,0, (LED_TYPE *)&led[_led]);
			break;
		}
		rgblight_set();
        }
	else {
	    switch (_cur_layer) {
	    case _FN1:
		rgblight_setrgb (0,255,180);
		break;
	    case _FN2:
		rgblight_setrgb (255,128,0);
		break;
	    case _BASE:
		rgblight_setrgb (255,0,0);
		break;
	    default: //  for any other layers, or the default layer
		rgblight_setrgb (255,0,0);
		break;
	    }
	}
        return true;
}
