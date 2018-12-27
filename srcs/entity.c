/**
 * File              : srcs/entity.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 27.12.2018
 * Last Modified Date: 27.12.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdlib.h>
#include <string.h>
#include "maze.h"
#include "entity.h"

t_entity		*new_entity()
{
  t_entity		*e;

  if ((e = malloc(sizeof(t_entity))) == NULL)
    return (NULL);
  e->pos.x = 0;
  e->pos.y = 0;
  bzero(e->attibutes, 3);
  e->update = NULL;
  e->data = NULL;
  return (e);
}

void			delete_entity(t_entity *e)
{
  free(e);
}
