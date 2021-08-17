/* Copyright
 *   2021 mikewl
 *   2021 solartempest
 *   2021 QMK
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "ps17.h"


#ifdef RGBLIGHT_ENABLE
	extern rgblight_config_t rgblight_config; // To pull layer status for RGBLIGHT
#endif


// Unused section
#ifdef VIA_ENABLE // VIA specific stuffs
#else
#endif
#ifdef COMBO_ENABLE // Change layer combo
#endif
#ifdef TAP_DANCE_ENABLE// Tap Dance definitions. Not VIA compatible.
#endif



// No way to move between layers currently
enum layer_names {
    _LAYER0,
    _LAYER1,
    _LAYER2,
    _LAYER3
};
	  
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_LAYER0] = LAYOUT(
		KC_VOLD, KC_MPLY, KC_VOLU,
		KC_NLCK, KC_KP_SLASH, KC_KP_ASTERISK, KC_KP_MINUS,
        KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_PLUS,
        KC_KP_4, KC_KP_5, KC_KP_6,
        KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_ENTER,
        KC_KP_0,          KC_KP_DOT
    ),
    [_LAYER1] = LAYOUT(
		KC_RIGHT, KC_TRNS, KC_LEFT,
        TO(0), KC_MEDIA_STOP, KC_SPACE, KC_NUMLOCK,
        KC_KP_7, TG(_LAYER2), TG(_LAYER3), KC_BSPACE,
        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, RESET,
        RESET,          KC_TRNS
    ),
    [_LAYER2] = LAYOUT(
		KC_RBRACKET, KC_TRNS, KC_LBRACKET,
        TO(0), KC_B, KC_T, C(S(KC_N)),
        KC_J, KC_S, KC_D, C(KC_MINS),
        C(KC_C), C(KC_V), KC_M,
        C(KC_N), C(S(KC_Z)), KC_LSHIFT, C(KC_PPLS),
        KC_SPACE,          KC_LALT
    ),
    [_LAYER3] = LAYOUT(
		KC_VOLU, KC_TRNS, KC_VOLD,
        TO(0), KC_WWW_REFRESH, KC_HOME, C(KC_T),
        C(S(KC_TAB)), KC_UP, C(KC_TAB), C(KC_W),
        KC_LEFT, KC_DOWN, KC_RIGHT,
        KC_WWW_BACK, KC_SPACE, KC_WWW_FORWARD, KC_ENTER,
        KC_PGDOWN,          KC_PGUP
    )
};


bool encoder_update_user(uint8_t index, bool clockwise) { // QMK encoder functionality
  #ifdef VIA_ENABLE // Add in VIA setting of rotary encoder keymap
	  if (index == 0) { // First encoder
			if (!clockwise) {
				action_exec((keyevent_t){.key = (keypos_t){.row = 0, .col = 0}, .pressed = true, .time = (timer_read() | 1)  });  // Time is 1 tick otherwise empty event
				action_exec((keyevent_t){.key = (keypos_t){.row = 0, .col = 0}, .pressed = false, .time = (timer_read() | 1)  });
			} 
			else {
				action_exec((keyevent_t){.key = (keypos_t){.row = 0, .col = 2}, .pressed = true, .time = (timer_read() | 1)  });
				action_exec((keyevent_t){.key = (keypos_t){.row = 0, .col = 2}, .pressed = false, .time = (timer_read() | 1)  });
			}
	}
  #endif
	return true;
};

#ifdef RGBLIGHT_ENABLE
	// RGB Layer Light Settings - Note that this will fix the key switch LED colour and brightness
	const rgblight_segment_t PROGMEM my_layer0_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 0, 95,255,90}); //Spring green		(Code is extra for static key lighting of layers)
	const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 0, 5,255,120}); //Yellow-orange	(Code is extra for static key lighting of layers)
	const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 0, 128,255,100}); //Cyan			(Code is extra for static key lighting of layers)
	const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 0, 215,255,120}); //Magenta		(Code is extra for static key lighting of layers)
	const rgblight_segment_t *const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST( //Lighting layers
			my_layer0_layer,
			my_layer1_layer,
			my_layer2_layer,
			my_layer3_layer
	);
#endif

void keyboard_post_init_user(void) {	//run as last task in keyboard init
  #ifdef RGB_MATRIX_ENABLE
    //NOTE 1: Layer lighting doesn't work in RGB matrix mode
		//NOTE 2: VIA lighting tab doesn't work and will crash in RGB matrix mode
		//NOTE 3: VIA layers doesn't seem to work properly in RGB matrix mode
		//rgb_matrix_enable_noeeprom(); //turn on RGB matrix based on previous state
		rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE); //set initial RGB matrix mode	
		rgb_matrix_sethsv_noeeprom(50, 255, 80); //sets LED to green-yellow
  #endif
  #ifdef RGBLIGHT_ENABLE
    rgblight_layers = my_rgb_layers;// Enable the LED layers
		rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_GRADIENT+8); // Set to static gradient 9
		layer_move(0); //start on layer 0 to get the lighting activated
  #endif
};


#ifdef RGBLIGHT_ENABLE
	layer_state_t layer_state_set_user(layer_state_t state) {
		rgblight_set_layer_state(0, layer_state_cmp(state, 0));    // Multiple layers will light up if both kb layers are active
			rgblight_set_layer_state(1, layer_state_cmp(state, 1));
			rgblight_set_layer_state(2, layer_state_cmp(state, 2));
			rgblight_set_layer_state(3, layer_state_cmp(state, 3));
			rgblight_set_layer_state(4, layer_state_cmp(state, 4));
		
	// This is what the LED layout is.
	// 1,                 0, 
	// 3,                 2, 
	// 9,   8, 7,  6,  5, 4, 
	// 13, 12, 11, 10,   
	// 18, 17, 16, 15,    14,
	// 22, 21, 20, 19,   
	// 27, 26, 25, 24,    23 
		
	switch(biton32(state)){ // Change all other LEDs based on layer state as well
		case 0:
			rgblight_sethsv_noeeprom(50,255,80);
			break;
		case 1:
			rgblight_sethsv_noeeprom(5,255,80);
			break;
		case 2:
			rgblight_sethsv_noeeprom(128,255,80);
			break;
		case 3:
			rgblight_sethsv_noeeprom(215,255,80);
			break;
		case 4:
			rgblight_sethsv_noeeprom(15,255,80);
			break;
	  }
    return state;
	};
#endif