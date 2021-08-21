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

#include "ps17.h"
#include QMK_KEYBOARD_H


#ifdef RGB_MATRIX_ENABLE //Add in addressable LED underglow support with physical locations
	/*led_config_t g_led_config = { {
		//Key matrix to LED index
		{	NO_LED,	NO_LED,	NO_LED, NO_LED, },
		{	0,	1,	2,	3,	},
		{	4,	5,	6,	7,	},
		{	8,	9,	10,	NO_LED,	},
		{	11,	12,	13,	14,	},
		{	15,	NO_LED,	16,	NO_LED,	},
		
		//Underglow matrix to LED index
		{	21,	NO_LED,	NO_LED,	22,	},
		{	20,	NO_LED,	NO_LED,	23,	},
		{	19,	NO_LED,	NO_LED,	24,	},
		{	18,	NO_LED,	NO_LED,	25,	},
		{	17,	27,	NO_LED,	26,	}
	}, {
	  // LED Key Index to Physical Position, calculated with Plot Digitizer and scaled PCB Image with center at {126,126}
	  {74,165},{108,165},{144,165},{179,165},{74,129},{109,129},{143,129},{188,121},{74,95},{109,95},{143,95},{73,60},{109,60},{144,60},{188,51},{91,25},{144,25},
	 
	  // LED underglow
	  {61,26},{61,88},{61,158},{61,197},{61,232},{192,232},{192,196},{192,158},{192,87},{183,26},{127,24}
	}, {
	  4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4, // LED Index to Flag. 4 for key backlight.
      2,2,2,2,2,2,2,2,2,2,2 // 2 for case underglow.
	} };*/

		led_config_t g_led_config = { {
		//Key matrix to LED index
		{	NO_LED,	NO_LED,	NO_LED, NO_LED, },
		{	0,	1,	2,	3,	},
		{	4,	5,	6,	7,	},
		{	8,	9,	10,	NO_LED,	},
		{	11,	12,	13,	14,	},
		{	15,	NO_LED,	16,	NO_LED,	}
		
	}, {
	  // LED Key Index to Physical Position, calculated with Plot Digitizer and scaled PCB Image with center at {126,126}

		// Per-key lighting - diagram matches values
		/*// Original "correct" values
	  {74,25},{108,25},{144,25},{179,25},
		{74,60},{109,60},{143,60},{188, 51},
		{74,95},{109,95},{143,95},
		{73,129},{109,129},{144,129},{188,121},
		{91,165},{144,165},*/

		// Reshaped for OpenRGB - get + aand enter on correct space
	  {74,25},{108,25},{144,25},{179,25},
		{74,60},{109,60},{143,60},{188, 60},
		{74,95},{109,95},{143,95},
		{73,129},{109,129},{144,129},{188,129},
		{91,165},{144,165},
	 
	  // LED underglow - left side bottom -> top then right side bottom -> top then finally middle bottom
		/* // Original "correct" values
	  {61,232},{61,197},{61,158},{61,88},{61,26},
		{192,26},{192,88},{192,158},{192,197},{183,232},
		{127,232}*/
		// Reshaped for OpenRGB  - 19 out of position
		{61,232},{61,197},{19,158},{61,88},{61,26},
		{192,26},{192,88},{192,158},{192,197},{183,232},
		{127,232}


	}, {
		// LED Index to Flag. 4 for key backlight.
	  4,4,4,4,
		4,4,4,4,
		4,4,4,
		4,4,4,4,
		4,4,
    // 2 for case underglow.
		2,    2,
		2,    2,
		2,    2,
		2,    2,
		2, 2, 2 
	} };
#endif
