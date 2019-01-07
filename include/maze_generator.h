/**
 * File              : include/maze_generator.h
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 26.12.2018
 * Last Modified Date: 27.12.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#ifndef MAZE_GENERATOR_H_
# define MAZE_GENERATOR_H_

#include "vector2.h"

enum		e_cell_type
{
  END = 0,
  VISITED = ' ',
  PUSHED = 42,
  WALL = '#',
  REMOVED_WALL
};

typedef struct	s_cell
{
  t_vector2	pos;
}		t_cell;

char		**generate_maze_depth_search(int width, int height);
char		**generate_maze_depth_search_print(int width, int height);

#endif /* !MAZE_GENERATOR_H_ */
