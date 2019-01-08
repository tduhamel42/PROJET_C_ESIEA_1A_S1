/**
 * File              : include/player.h
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 27.12.2018
 * Last Modified Date: 08.01.2019
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#ifndef PLAYER_H_
# define PLAYER_H_

#include "entity.h"

enum		e_player_key
{
  UP = 0,
  DOWN,
  LEFT,
  RIGHT,
  FIRE
};

typedef struct		s_player_data
{
  char			*keys;
  int			nbr_move;
  int			dir;
}			t_player_data;

t_entity		*new_player(t_vector2 pos, const char *keys);
void			delete_player(t_entity *player);

#endif /* !PLAYER_H_ */
