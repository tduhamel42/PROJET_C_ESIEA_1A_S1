/**
 * File              : include/two_player_screen.h
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 26.12.2018
 * Last Modified Date: 26.12.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#ifndef TWO_PLAYER_SCREEN_H_
# define TWO_PLAYER_SCREEN_H_

#include "vector2.h"

typedef struct s_screen	t_screen;
typedef struct s_maze	t_maze;

typedef struct		s_two_player_screen_data
{
  t_vector2		pos_player1;
  t_vector2		pos_player2;
  int			nbr_move_player1;
  int			nbr_move_player2;
  char			victory;
}			t_two_player_screen_data;

t_screen		*new_two_player_screen(t_maze *maze);
void			delete_two_player_screen(t_screen *screen);

#endif /* !TWO_PLAYER_SCREEN_H_ */
