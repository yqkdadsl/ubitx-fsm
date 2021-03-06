/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
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

#ifndef __MENU_H__
#define __MENU_H__

#include <stdint.h>

typedef bool (*select_menu_func)(int16_t val, bool selected);
typedef void (*format_menu_func)(char *buf, const char *original_text, bool change_val, int16_t val);
typedef int16_t (*get_menu_value_func)();
typedef void (*format_menu_value_func)(char *buf, int16_t val);
typedef int16_t (*get_next_menu_value_func)(int16_t val, bool forward);

typedef struct {
  char text[10];
  int16_t submenu_count;
  select_menu_func select_menu_f;
  format_menu_func format_menu_f;
  get_menu_value_func get_menu_value_f;
  format_menu_value_func format_menu_value_f;
  get_next_menu_value_func get_next_menu_value_f;
} Menu_Item;

extern const Menu_Item *menu;
extern uint8_t menu_item_count;

void active_main_menu();
void active_system_menu();

#endif // __MENU_H__

