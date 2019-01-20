/**
 * File              : selection_menu.h
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 26.12.2018
 * Last Modified Date: 20.01.2019
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#ifndef SELECTION_MENU_H_
# define SELECTION_MENU_H_

#include "vector2.h"

typedef struct		s_selection_menu
{
  t_vector2		pos;
  int			selected_type;
  int			size;
  char			**entries;
  int			selected;
}			t_selection_menu;

t_selection_menu	*new_selection_menu(int x,
					    int y,
					    int selected_type,
					    int size,
					    ...);
void			delete_selection_menu(t_selection_menu *menu);
int			update_selection_menu(t_selection_menu *selection_menu,
					      char key);
int			update_selection_menu_pos(t_selection_menu *menu, int x, int y);
int			render_selection_menu(t_selection_menu *selection_menu);

#endif /* !SELECTION_MENU_H_ */
