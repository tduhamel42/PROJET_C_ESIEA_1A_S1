/**
 * File              : include/player_screen.h
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 19.12.2018
 * Last Modified Date: 27.12.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#ifndef PLAYER_SCREEN_H_
# define PLAYER_SCREEN_H_

#include "selection_menu.h"
#include "vector2.h"

typedef struct s_screen	t_screen;
typedef struct s_game	t_game;

typedef struct		s_player_screen_data
{
  t_selection_menu	*menu;
}			t_player_screen_data;

t_screen		*new_player_screen(t_game *game);
void			delete_player_screen(t_screen *screen);

#endif /* !PLAYER_SCREEN_H_ */
