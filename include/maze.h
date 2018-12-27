/**
 * File              : include/maze.h
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 17.12.2018
 * Last Modified Date: 27.12.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#ifndef MAZE_H_
# define MAZE_H_

#include "vector2.h"
#include "screen.h"

extern int		term_width;
extern int		term_height;

typedef struct		s_maze
{
  t_vector2		size;
  t_vector2		start;
  t_vector2		end;
  char			**data;
}			t_maze;

typedef struct		s_game
{
  char			running;
  t_screen		*current_screen;
  char			key;
  t_maze		*maze;
  int			use_generated;
}			t_game;

t_game			*new_game();
void			delete_game(t_game *game);
int			run_game(t_game *game);

#endif /* !MAZE_H_ */
