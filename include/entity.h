/**
 * File              : include/entity.h
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 27.12.2018
 * Last Modified Date: 29.12.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#ifndef ENTITY_H_
# define ENTITY_H_

#include "linked_list.h"
#include "vector2.h"

enum			e_attr
{
  HP = 0,
  LVL,
  ATTACK
};

typedef struct s_game	t_game;
typedef struct s_maze	t_maze;
typedef struct s_entity	t_entity;
typedef int		(*t_entity_func)(t_game *game, t_maze *maze, t_entity *);

typedef struct		s_entity
{
  void			*data;
  t_vector2		pos;
  t_llist		*inventory;
  int			attributes[3];
  t_entity_func		update;
}			t_entity;

t_entity		*new_entity();
void			delete_entity(t_entity *e);

#endif /* !ENTITY_H_ */
