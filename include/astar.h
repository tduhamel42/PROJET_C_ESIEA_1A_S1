/**
 * File              : include/astar.h
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 19.12.2018
 * Last Modified Date: 19.12.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#ifndef ASTAR_H_
# define ASTAR_H_

#include "linked_list.h"
#include "vector2.h"

typedef struct s_maze	t_maze;

typedef struct		s_node
{
  t_vector2		pos;
  int			h;
}			t_node;

int			astar(t_maze *maze,
			      t_llist **path,
			      t_vector2 start,
			      t_vector2 end);

#endif /* !ASTAR_H_ */
