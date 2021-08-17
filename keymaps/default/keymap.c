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


// Unused Section
#ifdef COMBO_ENABLE // Change layer combo
#endif
#ifdef TAP_DANCE_ENABLE// Tap Dance definitions. Not VIA compatible.
#endif



bool encoder_update_user(uint8_t index, bool clockwise) { // VIA encoder functionality
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
	return true;
};

// No way to move between layers currently
enum layer_names {
    _LAYER0,
};
	  
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_LAYER0] = LAYOUT(
		KC_VOLD, KC_MPLY, KC_VOLU,
		KC_NLCK, KC_KP_SLASH, KC_KP_ASTERISK, KC_KP_MINUS,
        KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_PLUS,
        KC_KP_4, KC_KP_5, KC_KP_6,
        KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_ENTER,
        KC_KP_0,          KC_KP_DOT
    )
};


void keyboard_post_init_user(void) {	//run as last task in keyboard init
  #ifndef OPENRGB_ENABLE
    //NOTE 1: Layer lighting doesn't work in RGB matrix mode
		//NOTE 2: VIA lighting tab doesn't work and will crash in RGB matrix mode
		//NOTE 3: VIA layers doesn't seem to work properly in RGB matrix mode
		//rgb_matrix_enable_noeeprom(); //turn on RGB matrix based on previous state
		rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE); //set initial RGB matrix mode	
		rgb_matrix_sethsv_noeeprom(50, 255, 80); //sets LED to green-yellow
  #endif
};		
	// This is what the LED layout is.
	// 1,                 0, 
	// 3,                 2, 
	// 9,   8, 7,  6,  5, 4, 
	// 13, 12, 11, 10,   
	// 18, 17, 16, 15,    14,
	// 22, 21, 20, 19,   
	// 27, 26, 25, 24,    23 
