/**
 * File              : srcs/astar.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 19.12.2018
 * Last Modified Date: 12.01.2019
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

static int	init_nodes(t_maze *maze, t_llist **nodes)
{
  t_node	*tmp;
  t_vector2	pos;

  for (int y = 0; y < maze->size.y; y++)
    {
      for (int x = 0; x < maze->size.x; x++)
	{
	  pos.x = x;
	  pos.y = y;
	  if ((tmp = new_node(pos, 0, 0)) == NULL)
	    return (1);
	  if (llist_push(nodes, tmp))
	    return (1);
	}
    }
  return (0);
}

static int	heuristic(t_vector2 a, t_vector2 b)
{
  return (10 * (abs(a.x - b.x) + abs(a.y - b.y)));
}

static void	get_adjs(t_llist **nodes, t_node *adjs[4], t_vector2 pos)
{
  t_node	*tmp;
  t_vector2	p;

  adjs[0] = NULL;
  adjs[1] = NULL;
  adjs[2] = NULL;
  adjs[3] = NULL;
  llist_go_first(nodes);
  p.x = pos.x + 1;
  p.y = pos.y;
  if ((tmp = get_node(nodes, p)) != NULL)
    adjs[0] = tmp;
  llist_go_first(nodes);
  p.x = pos.x;
  p.y = pos.y - 1;
  if ((tmp = get_node(nodes, p)) != NULL)
    adjs[1] = tmp;
  llist_go_first(nodes);
  p.x = pos.x - 1;
  p.y = pos.y;
  if ((tmp = get_node(nodes, p)) != NULL)
    adjs[2] = tmp;
  llist_go_first(nodes);
  p.x = pos.x;
  p.y = pos.y + 1;
  if ((tmp = get_node(nodes, p)) != NULL)
    adjs[3] = tmp;
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

static void	update_cell(t_node *adj, t_node *n, t_vector2 end)
{
  adj->g = n->g + 10;
  adj->h = heuristic(adj->pos, end);
  adj->parent = n;
  adj->f = adj->h + adj->g;
}

static void	do_path(t_llist **nodes, t_llist **path,
			t_vector2 end, t_vector2 start)
{
  t_node	*node;

  node = get_node(nodes, end);
  while (node && (node->pos.x != start.x || node->pos.y != start.y))
    {
      llist_push(path, node);
      node = node->parent;
    }
}

int		astar(t_maze *maze, t_llist **path, t_vector2 start_pos, t_vector2 end)
{
  t_llist	*nodes = NULL, *olist = NULL, *clist = NULL;
  t_node	*start, *current;

  init_nodes(maze, &nodes);
  start = get_node(&nodes, start_pos);
  llist_push(&olist, start);
  while (!llist_is_empty(&olist))
    {
      current = (t_node *) llist_pop(&olist);
      llist_go_last(&clist);
      llist_push(&clist, current);

      if (current->pos.x == end.x && current->pos.y == end.y)
	{
	  do_path(&nodes, path, end, start_pos);
	  return (0);
	}
      t_node *adjs[4];
      get_adjs(&nodes, adjs, current->pos);
      for (int i = 0; i < 4; i++)
	{
	  if (adjs[i] == NULL)
	    continue ;
	  if (!is_in_list(&clist, adjs[i]->pos)
	      && maze->data[adjs[i]->pos.y][adjs[i]->pos.x] != '#')
	    {
	      if (is_in_list(&olist, adjs[i]->pos))
		{
		  if (adjs[i]->g > current->g + 10)
		    update_cell(adjs[i], current, end);
		}
	      else
		{
		  update_cell(adjs[i], current, end);
		  llist_go_last(&olist);
		  llist_push(&olist, adjs[i]);
		}
	    }
	}
      llist_sort(&olist, sort);
    }
  return (1);
}
