/**
 * File              : include/maze_helper.h
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 18.12.2018
 * Last Modified Date: 19.12.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#ifndef MAZE_HELPER_H_
# define MAZE_HELPER_H_

typedef struct	s_maze t_maze;

int		load_maze(t_maze *maze);
void		basic_maze_print(t_maze *maze);
void		normal_maze_print(t_maze *maze);
void		pretty_maze_print(t_maze *maze);

#endif /* !MAZE_HELPER_H_ */
