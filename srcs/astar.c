/**
 * File              : srcs/astar.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 19.12.2018
 * Last Modified Date: 05.01.2019
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

static t_node	*get_node(t_llist **nodes, t_vector2 pos)
{
  t_llist	*e = NULL;
  t_node	*node;

  llist_go_first(nodes);
  e = (*nodes);
  while (e)
    {
      node = (t_node *) e->data;
      if (node->pos.x == pos.x && node->pos.y == pos.y)
	return (node);
      e = e->next;
    }
  return (NULL);
}

static int	heuristic(t_vector2 a, t_vector2 b)
{
  return (10 * (abs(a.x - b.x) + abs(a.y - b.y)));
}

static void	get_adjs(t_maze *maze, t_node adjs[4], t_vector2 pos)
{
  if (pos.y + 1 < maze->size.y)
    {
      adjs[0].pos.x = pos.x;
      adjs[0].pos.y = pos.y + 1;
    }
  if (pos.x + 1 < maze->size.x)
    {
      adjs[1].pos.x = pos.x + 1;
      adjs[1].pos.y = pos.y;
    }
  if (pos.y - 1 > 0)
    {
      adjs[2].pos.x = pos.x;
      adjs[2].pos.y = pos.y - 1;
    }
  if (pos.x - 1 > 0)
    {
      adjs[3].pos.x = pos.x - 1;
      adjs[3].pos.y = pos.y;
    }
}

int		astar(t_maze *maze, t_llist **list, t_vector2 start_pos, t_vector2 end)
{
  t_llist	*olist = NULL;
  t_llist	*clist = NULL;
  t_node	*start, *current, adjs[4];

  (void) maze; (void) list; (void) clist; (void) current;
  heuristic(start_pos, end);
  if ((start = new_node(start_pos, 0)) == NULL)
    return (1);
  llist_push(&olist, &start);
  while (is_empty(&olist))
    {
      /*
      current = (t_node *) llist_pop(&olist);
      llist_push(&clist, current);

      if (current->pos.x == end.x && current->pos.y == end.y)
	return (1);*/
    }
  return (0);
}
