/**
 * File              : include/two_player_screen.h
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 26.12.2018
 * Last Modified Date: 27.12.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#ifndef TWO_PLAYER_SCREEN_H_
# define TWO_PLAYER_SCREEN_H_

#include "vector2.h"

typedef struct s_screen	t_screen;
typedef struct s_game	t_game;
typedef struct s_entity	t_entity;

typedef struct		s_two_player_screen_data
{
  t_entity		*player1;
  t_entity		*player2;
  char			victory;
}			t_two_player_screen_data;

t_screen		*new_two_player_screen(t_game *game);
void			delete_two_player_screen(t_screen *screen);

#endif /* !TWO_PLAYER_SCREEN_H_ */
