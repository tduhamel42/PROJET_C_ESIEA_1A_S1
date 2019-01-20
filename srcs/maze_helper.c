/**
 * File              : maze_helper.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 18.12.2018
 * Last Modified Date: 20.01.2019
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "vector2.h"
#include "maze.h"
#include "draw_utils.h"
#include "maze_helper.h"

static void	read_maze(t_vector2 size, char maze[size.y][size.x][5])
{
  char		d;

  scanf("%c", &d);
  for (int y = 0; y < size.y; y++)
    {
      for (int x = 0; x < size.x; x++)
	{
	  bzero(maze[y][x], 4);
	  scanf("%4[A-Z | 0-9/-]", maze[y][x]);
	  scanf("%c", &d);
	}
    }
  freopen("/dev/tty", "r", stdin);
}

static void	convert_maze(t_vector2 size, char maze[size.y][size.x][5], char **fmaze)
{
  for (int y = 0; y < size.y * 2 + 1; y++)
    {
      for (int x = 0; x < size.x * 2 + 1; x++)
	{
	  if (x % 2 == 1 && y % 2 == 1)
	    {
	      fmaze[y][x] = ' ';
	      if (maze[y / 2][x / 2][0] == '-')
		if (y - 1 > 0)
		  fmaze[y - 1][x] = ' ';
	      if (maze[y / 2][x / 2][1] == '-')
		if (x + 1 < size.x * 2)
		  fmaze[y][x + 1] = ' ';
	      if (maze[y / 2][x / 2][2] == '-')
		if (y + 1 < size.y * 2)
		  fmaze[y + 1][x] = ' ';
	      if (maze[y / 2][x / 2][3] == '-')
		if (x - 1 > 0)
		  fmaze[y][x - 1] = ' ';
	    }
	}
    }
  for (int y = 0; y < size.y * 2 + 1; y += 2)
    {
      for (int x = 0; x < size.x * 2 + 1; x++)
	{
	  if (x % 2 == 0)
	    if (y - 1 > 0 && y < size.y * 2
		&& y + 1 < size.y * 2
		&& x - 1 > 0
		&& x + 1 < size.x * 2)
	    {
	      if (fmaze[y - 1][x - 1] == ' '
		  && fmaze[y - 1][x] == ' '
		  && fmaze[y - 1][x + 1] == ' '
		  && fmaze[y][x - 1] == ' '
		  && fmaze[y][x + 1] == ' '
		  && fmaze[y + 1][x - 1] == ' '
		  && fmaze[y + 1][x] == ' '
		  && fmaze[y + 1][x + 1] == ' ')
		fmaze[y][x] = ' ';
	    }
	}
    }
}

static int	check_maze(t_vector2 size, char r_maze[size.y][size.x][5])
{
  for (int y = 0; y < size.y; y++)
    {
      for (int x = 0; x < size.x; x++)
	{
	  if (r_maze[y][x][0] == 'M')
	    {
	      if (y > 0 && r_maze[y - 1][x][2] != 'M')
		{
		  printf("Error cell %d %d\n", x, y);
		  return (1);
		}
	    }
	  if (r_maze[y][x][1] == 'M')
	    {
	      if (x < size.x - 1 && r_maze[y][x + 1][3] != 'M')
		{
		  printf("Error cell %d %d\n", x, y);
		  return (1);
		}
	    }
	  if (r_maze[y][x][2] == 'M')
	    {
	      if (y < size.y - 1 && r_maze[y + 1][x][0] != 'M')
		{
		  printf("Error cell %d %d\n", x, y);
		  return (1);
		}
	    }
	  if (r_maze[y][x][3] == 'M')
	    {
	      if (x > 0 && r_maze[y][x - 1][1] != 'M')
		{
		  printf("Error cell %d %d\n", x, y);
		  return (1);
		}
	    }
	}
    }
  return (0);
}

int		load_maze(t_maze *maze)
{
  printf("Waiting for maze !\n");
  if ((scanf("%d %d %d %d %d %d",
	&maze->size.x,
	&maze->size.y,
	&maze->start.x,
	&maze->start.y,
	&maze->end.x,
	&maze->end.y)) != 6)
      {
	dprintf(2, "Error while loading maze !\n");
	return (1);
      }

  char		r_maze[maze->size.y][maze->size.x][5];
  
  read_maze(maze->size, r_maze);
  if (check_maze(maze->size, r_maze))
    return (1);
  if ((maze->data = malloc(sizeof(char *) * (maze->size.y * 2 + 1))) == NULL)
    return (1);
  for (int y = 0; y < maze->size.y * 2 + 1; y++)
    {
      if ((maze->data[y] = malloc(sizeof(char) * (maze->size.x * 2 + 1))) == NULL)
	return (1);
      memset(maze->data[y], '#', maze->size.x * 2 + 1);
    }
  convert_maze(maze->size, r_maze, maze->data);
  maze->size.x = maze->size.x * 2 + 1;
  maze->size.y = maze->size.y * 2 + 1;
  maze->end.x = maze->end.x * 2 + 1;
  maze->end.y = maze->end.y * 2 + 1;
  maze->start.x = maze->start.x * 2 + 1;
  maze->start.y = maze->start.y * 2 + 1;
  return (0);
}

void		basic_maze_print(t_maze *maze)
{
  move_cursor(0, 0);
  for (int y = 0; y < maze->size.y; y++)
    {
      for (int x = 0; x < maze->size.x; x++)
	{
	  printf("%c", maze->data[y][x]);
	}
      printf("\n");
    }
}

void		normal_maze_print(t_maze *maze)
{
  move_cursor(0, 0);
  for (int y = 0; y < maze->size.y; y++)
    {
      for (int x = 0; x < maze->size.x; x++)
	{
	  if (maze->data[y][x] == '#')
	    printf("#");
	  else if (maze->data[y][x] == 'p')
	    printf("☺");
	  else if (maze->data[y][x] == 'e')
	    printf("e");
	  else if (maze->data[y][x] == '1')
	    printf("*");
	  else
	    printf(" ");
	}
      printf("\n");
    }
}

void		pretty_maze_print(t_maze *maze)
{
  move_cursor(0, 0);
  for (int y = 0; y < maze->size.y; y++)
    {
      for (int x = 0; x < maze->size.x; x++)
	{
	  if (maze->data[y][x] == '#' && x % 2 == 0 && y % 2 == 0)
	    printf("██");
	  else if (maze->data[y][x] == '#' && x % 2 == 0 && y % 2 == 1)
	    printf("██");
	  else if (maze->data[y][x] == '#' && x % 2 == 1 && y % 2 == 0)
	    printf("██");
	  else
	    {
	      switch (maze->data[y][x])
		{
		case '3':
		case 'p':
		  attron(FG_RED);
		  printf("웃");
		  break;
		case '4':
		case 'q':
		  attron(FG_YELLOW);
		  printf("웃");
		  break;
		case 'e':
		  printf("☉ ");
		  break;
		case '1':
		  attron(FG_RED);
		  printf("★ ");
		  break;
		case '2':
		  attron(FG_YELLOW);
		  printf("★ ");
		  break;
		default:
		  printf("  ");
		}
	    }
	  attroff();
	}
      printf("\n");
    }
}
