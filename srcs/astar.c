/**
 * File              : srcs/astar.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 19.12.2018
 * Last Modified Date: 19.12.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <math.h>
#include <stdlib.h>
#include "maze.h"
#include "astar.h"

static t_node	*new_node(t_vector2 pos, int h)
{
  t_node	*node;

  if ((node = malloc(sizeof(t_node))) == NULL)
    return (NULL);
  node->pos.x = pos.x;
  node->pos.y = pos.y;
  node->h = h;
  return (node);
}

static int	heuristic(t_vector2 a, t_vector2 b)
{
  return (abs(a.x - b.x) + abs(a.y - b.y));
}

int		astar(t_maze *maze, t_llist **list, t_vector2 start_pos, t_vector2 end)
{
  t_llist	*olist = NULL;
  t_llist	*clist = NULL;
  t_node	*start, *current;

  if ((start = new_node(start_pos, 0)) == NULL)
    return (1);
  llist_push(&olist, &start);
  while (is_empty(&olist))
    {
    }
  return (0);
}
