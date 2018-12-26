/**
 * File              : include/maze.h
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 17.12.2018
 * Last Modified Date: 26.12.2018
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
  char			running;
  t_vector2		size;
  t_vector2		start;
  t_vector2		end;
  char			**maze;
  t_screen		*current_screen;
  char			key;
  int			use_generated;
}			t_maze;

t_maze			*new_maze();
void			delete_maze(t_maze *maze);
int			run_maze(t_maze *maze);

#endif /* !MAZE_H_ */
