/**
 * File              : include/single_player_screen.h
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 26.12.2018
 * Last Modified Date: 26.12.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#ifndef SINGLE_PLAYER_SCREEN_H_
# define SINGLE_PLAYER_SCREEN_H_

#include "vector2.h"

typedef struct s_screen	t_screen;
typedef struct s_maze	t_maze;

typedef struct		s_single_player_screen_data
{
  t_vector2		pos;
  int			nbr_move;
  char			victory;
}			t_single_player_screen_data;

t_screen		*new_single_player_screen(t_maze *maze);
void			delete_single_player_screen(t_screen *screen);

#endif /* !SINGLE_PLAYER_SCREEN_H_ */
