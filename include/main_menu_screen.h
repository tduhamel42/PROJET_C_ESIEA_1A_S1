/**
 * File              : include/main_menu_screen.h
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 17.12.2018
 * Last Modified Date: 26.12.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#ifndef MAIN_MENU_SCREEN_H_
# define MAIN_MENU_SCREEN_H_

#include "selection_menu.h"

typedef struct s_screen	t_screen;

typedef struct		s_main_menu_data
{
  t_selection_menu	*menu;
}			t_main_menu_data;

t_screen		*new_main_menu_screen();
void			delete_main_menu_screen(t_screen *screen);

#endif /* !MAIN_MENU_SCREEN_H_ */
