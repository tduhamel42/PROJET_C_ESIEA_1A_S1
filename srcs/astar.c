/**
 * File              : srcs/astar.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 19.12.2018
 * Last Modified Date: 08.01.2019
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <math.h>
#include <stdlib.h>
#include "maze.h"
#include "astar.h"

static t_node	*new_node(t_vector2 pos, int h, int g)
{
  t_node	*node;

  if ((node = malloc(sizeof(t_node))) == NULL)
    return (NULL);
  node->pos.x = pos.x;
  node->pos.y = pos.y;
  node->h = h;
  node->g = g;
  node->f = g + h;
  node->parent = NULL;
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

static int	sort(void *d1, void *d2)
{
  t_node	*n1 = (t_node *) d1;
  t_node	*n2 = (t_node *) d2;

  return (n1->f < n2->f);
}

char		is_in_list(t_llist **list, t_vector2 pos)
{
  t_llist	*tmp;
  t_node	*node;

  llist_go_first(list);
  tmp = (*list);
  while (tmp)
    {
      node = (t_node *) tmp->data;
      if (node->pos.x == pos.x && node->pos.y == pos.y)
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

int		astar(t_maze *maze, t_llist **list, t_vector2 start_pos, t_vector2 end)
{
  t_llist	*olist = NULL, *clist = NULL;
  t_node	*start, *current, adjs[4];
  int		h;

  h = heuristic(start_pos, end);
  if ((start = new_node(start_pos, h, 0)) == NULL)
    return (1);
  llist_push(&olist, &start);
  while (llist_is_empty(&olist))
    {
      current = (t_node *) llist_pop(&olist);
      llist_push(&clist, current);

      if (current->pos.x == end.x && current->pos.y == end.y)
	break;
      t_node adjs[4];
      get_adjs(maze, adjs, current->pos);
      for (int i = 0; i < 4; i++)
	{
	  if (is_in_list(&olist, adjs[i].pos))
	    {
	    }
	}
      llist_sort(&olist, sort);
    }
  return (0);
}
