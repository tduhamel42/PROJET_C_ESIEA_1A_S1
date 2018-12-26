/**
 * File              : srcs/two_player_screen.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 26.12.2018
 * Last Modified Date: 26.12.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdlib.h>
#include <string.h>
#include "screen.h"
#include "maze_helper.h"
#include "maze.h"
#include "draw_utils.h"
#include "two_player_screen.h"

static int		update(t_maze *maze)
{
  t_two_player_screen_data	*data =
    (t_two_player_screen_data *) maze->current_screen->data;
  
  maze->maze[data->pos_player1.y][data->pos_player1.x] = ' ';
  maze->maze[data->pos_player2.y][data->pos_player2.x] = ' ';
  switch (maze->key)
    {
    case 'A':
      if (data->pos_player1.y - 1 > 0
	  && maze->maze[data->pos_player1.y - 1][data->pos_player1.x] != '#')
	{
	  --data->pos_player1.y;
	  ++data->nbr_move_player1;
	}
      break;
    case 'B':
      if (data->pos_player1.y + 1 < maze->size.y
	  && maze->maze[data->pos_player1.y + 1][data->pos_player1.x] != '#')
	{
	  ++data->pos_player1.y;
	  ++data->nbr_move_player1;
	}
      break;
    case 'C':
      if (data->pos_player1.x + 1 < maze->size.x
	  && maze->maze[data->pos_player1.y][data->pos_player1.x + 1] != '#')
	{
	  ++data->pos_player1.x;
	  ++data->nbr_move_player1;
	}
      break;
    case 'D':
      if (data->pos_player1.x - 1 > 0
	  && maze->maze[data->pos_player1.y][data->pos_player1.x - 1] != '#')
	{
	  --data->pos_player1.x;
	  ++data->nbr_move_player1;
	}
      break;
    case 'z':
      if (data->pos_player2.y - 1 > 0
	  && maze->maze[data->pos_player2.y - 1][data->pos_player2.x] != '#')
	{
	  --data->pos_player2.y;
	  ++data->nbr_move_player2;
	}
      break;
    case 's':
      if (data->pos_player2.y + 1 < maze->size.y
	  && maze->maze[data->pos_player2.y + 1][data->pos_player2.x] != '#')
	{
	  ++data->pos_player2.y;
	  ++data->nbr_move_player2;
	}
      break;
    case 'd':
      if (data->pos_player2.x + 1 < maze->size.x
	  && maze->maze[data->pos_player2.y][data->pos_player2.x + 1] != '#')
	{
	  ++data->pos_player2.x;
	  ++data->nbr_move_player2;
	}
      break;
    case 'q':
      if (data->pos_player2.x - 1 > 0
	  && maze->maze[data->pos_player2.y][data->pos_player2.x - 1] != '#')
	{
	  --data->pos_player2.x;
	  ++data->nbr_move_player2;
	}
      break;
    }
  maze->maze[data->pos_player1.y][data->pos_player1.x] = 'p';
  maze->maze[data->pos_player2.y][data->pos_player2.x] = 'q';
  return (0);
}

static int		render(t_maze *maze)
{
  t_two_player_screen_data	*data =
    (t_two_player_screen_data *) maze->current_screen->data;
  
  // Player 1
  draw_box((maze->size.x * 2) + 5,
	   2,
	   28,
	   8,
	   FG_RED);
  attron(BOLD);
  color_printxy((maze->size.x * 2) + 20 - strlen("Player 1"),
		3,
		FG_RED,
		"Player 1");
  attroff();
  color_printxy((maze->size.x * 2) + 6,
		4,
		FG_RED,
		"Number of steps: %d", data->nbr_move_player1);
  // Player 2
  draw_box((maze->size.x * 2) + 5,
	   11,
	   28,
	   8,
	   FG_YELLOW);
  attron(BOLD);
  color_printxy((maze->size.x * 2) + 20 - strlen("Player 2"),
		12,
		FG_YELLOW,
		"Player 2");
  attroff();
  color_printxy((maze->size.x * 2) + 6,
		13,
		FG_YELLOW,
		"Number of steps: %d", data->nbr_move_player2);
  pretty_maze_print(maze);
  return (0);
}

t_screen			*new_two_player_screen(t_maze *maze)
{
  t_screen			*screen;
  t_two_player_screen_data	*data;

  if ((screen = new_screen()) == NULL)
    return (NULL);
  screen->update = update;
  screen->render = render;
  if ((screen->data = malloc(sizeof(t_two_player_screen_data))) == NULL)
    return (NULL);
  data = (t_two_player_screen_data *) screen->data;
  data->nbr_move_player1 = 0;
  data->nbr_move_player2 = 0;
  data->victory = 0;
  data->pos_player1 = (t_vector2) { .x = maze->start.x, .y = maze->start.y };
  data->pos_player2 = (t_vector2) { .x = maze->start.x, .y = maze->start.y };
  maze->maze[maze->end.y][maze->end.x] = 'e';
  return (screen);
}

void			delete_two_player_screen(t_screen *screen)
{
  delete_screen(screen);
}
