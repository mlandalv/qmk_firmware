/*
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0000
#define DEVICE_VER      0x0002
#define MANUFACTURER    Kodosaurus AB
#define PRODUCT         Martinosaurus
#define DESCRIPTION     A custom keyboard

#define MATRIX_ROWS 5
#define MATRIX_COLS 12

#define DIODE_DIRECTION COL2ROW
#define MATRIX_ROW_PINS { B7, D5, C7, F1, F0 }
#define MATRIX_COL_PINS { D1, D0, D4, C6, D7, E6, B3, B1, F7, F6, F5, F4 }
//#define UNUSED_PINS

#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 300
