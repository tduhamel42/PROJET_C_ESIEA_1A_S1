/**
 * File              : include/adventure_mode_screen.h
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 26.12.2018
 * Last Modified Date: 27.12.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#ifndef ADVENTURE_MODE_SCREEN_H_
# define ADVENTURE_MODE_SCREEN_H_

#include "selection_menu.h"

typedef struct s_game	t_game;

typedef struct		s_adventure_mode_screen_data
{
  t_selection_menu	*menu;
}			t_adventure_mode_screen_data;

t_screen		*new_adventure_mode_screen(t_game *game);
void			delete_adventure_mode_screen(t_screen *screen);

#endif /* !ADVENTURE_MODE_SCREEN_H_ */
