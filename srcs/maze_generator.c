/**
 * File              : srcs/maze_generator.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 26.12.2018
 * Last Modified Date: 26.12.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdlib.h>
#include <string.h>
#include "draw_utils.h"
#include "linked_list.h"
#include "maze_generator.h"

static t_vector2	get_random_neighbors(int width,
					     int height,
					     char **maze,
					     t_vector2 cell)
{
  int		r;
  t_vector2	rand_cell = { .x = 0, .y = 0 };

  do
    {
      r = rand() % 4;
      switch (r)
	{
	case 0:
	  if (cell.x - 2 > 0 && maze[cell.y][cell.x - 2] == WALL)
	    rand_cell = ((t_vector2) { cell.x - 2, cell.y });
	  break;
	case 1:
	  if (cell.x + 2 < width && maze[cell.y][cell.x + 2] == WALL)
	    rand_cell = ((t_vector2) {cell.x + 2, cell.y});
	  break;
	case 2:
	  if (cell.y + 2 < height && maze[cell.y + 2][cell.x] == WALL)
	    rand_cell = ((t_vector2) {cell.x, cell.y + 2});
	  break;
	case 3:
	  if (cell.y - 2 > 0 && maze[cell.y - 2][cell.x] == WALL)
	    rand_cell = ((t_vector2) {cell.x, cell.y - 2});
	  break;
	}
    } while (rand_cell.x == 0 && rand_cell.y == 0);
  return (rand_cell);
}

static int	is_every_neighbors_visited(int width,
					   int height,
					   char **maze,
					   t_vector2 cell)
{
  if ((cell.x - 2 > 0 && maze[cell.y][cell.x - 2] == WALL)
      || (cell.x + 2 < width && maze[cell.y][cell.x + 2] == WALL)
      || (cell.y + 2 < height && maze[cell.y + 2][cell.x] == WALL)
      || (cell.y - 2 > 0 && maze[cell.y - 2][cell.x] == WALL))
    return (0);
  return (1);
}

static int	is_every_cell_visited(int width, int height, char **maze)
{
  for (int y = 0; y < height; y++)
    {
      for (int x = 0; x < width; x++)
	{
	  if ((x % 2 == 1 && y % 2 == 1) && maze[y][x] == WALL)
	    return (0);
	}
    } 
  return (1);
}

static void	remove_wall(t_vector2 c_cell, t_vector2 n_cell, int width,
			    int height, char **maze)
{
  if (n_cell.x == c_cell.x - 2 && c_cell.x - 1 > 0)
    maze[c_cell.y][c_cell.x - 1] = REMOVED_WALL;
  if (n_cell.x == c_cell.x + 2 && c_cell.x + 1 < width)
    maze[c_cell.y][c_cell.x + 1] = REMOVED_WALL;
  if (n_cell.y == c_cell.y + 2 && c_cell.y + 1 < height)
    maze[c_cell.y + 1][c_cell.x]= REMOVED_WALL;
  if (n_cell.y == c_cell.y - 2 && c_cell.y - 1 > 0)
    maze[c_cell.y - 1][c_cell.x]= REMOVED_WALL;
}

char		**generate_maze_depth_search(int width, int height)
{
  char		**maze;
  t_vector2	c_cell, tmp_cell, *p_cell;
  t_llist	*stack = NULL;

  if ((maze = malloc(sizeof(char *) * (height + 1))) == NULL)
    return (NULL);
  for (int i = 0; i < height + 1; i++)
    {
      if ((maze[i] = malloc(sizeof(char) * (width + 1))) == NULL)
	return (NULL);
      memset(maze[i], '#', width);
    }
  c_cell.x = 1;
  c_cell.y = 1;
  while (!is_every_cell_visited(width, height, maze))
    {
      maze[c_cell.y][c_cell.x] = VISITED;
      if (!is_every_neighbors_visited(width, height, maze, c_cell))
	{
	  tmp_cell = get_random_neighbors(width, height, maze, c_cell);
	  p_cell = malloc(sizeof(t_vector2));
	  p_cell->x = c_cell.x;
	  p_cell->y = c_cell.y;
	  maze[p_cell->y][p_cell->x] = PUSHED; 
	  llist_push(&stack, p_cell);
	  remove_wall(c_cell, tmp_cell, width, height, maze);
	  c_cell = tmp_cell;
	}
      else if (stack)
	{
	  p_cell = (t_vector2 *) pop(&stack);
	  if (p_cell)
	    {
	      c_cell.x = p_cell->x;
	      c_cell.y = p_cell->y;
	    }
	  free(p_cell);
	}
    }
  for (int y = 0; y < height + 1; y++)
    {
      for (int x = 0; x < width + 1; x++)
	{
	  if (x == width || y == height)
	    maze[y][x] = '#';
	}
    }
  return (maze);
}
