/**
 * File              : srcs/single_player_screen.c
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
#include "single_player_screen.h"

static int		update(t_maze *maze)
{
  t_single_player_screen_data	*data =
    (t_single_player_screen_data *) maze->current_screen->data;
  
  maze->maze[data->pos.y][data->pos.x] = ' ';
  switch (maze->key)
    {
    case 'A':
      if (data->pos.y - 1 > 0 && maze->maze[data->pos.y - 1][data->pos.x] != '#')
	{
	  --data->pos.y;
	  ++data->nbr_move;
	}
      break;
    case 'B':
      if (data->pos.y + 1 < maze->size.y
	  && maze->maze[data->pos.y + 1][data->pos.x] != '#')
	{
	  ++data->pos.y;
	  ++data->nbr_move;
	}
      break;
    case 'C':
      if (data->pos.x + 1 < maze->size.x
	  && maze->maze[data->pos.y][data->pos.x + 1] != '#')
	{
	  ++data->pos.x;
	  ++data->nbr_move;
	}
      break;
    case 'D':
      if (data->pos.x - 1 > 0
	  && maze->maze[data->pos.y][data->pos.x - 1] != '#')
	{
	  --data->pos.x;
	  ++data->nbr_move;
	}
      break;
    }
  maze->maze[data->pos.y][data->pos.x] = 'p';
  if (data->pos.x == maze->end.x && data->pos.y == maze->end.y)
    data->victory = 1;
  if (data->victory)
    { 
      if (maze->key == 'r')
	{
	  delete_single_player_screen(maze->current_screen);
	  system("clear");
	  if ((maze->current_screen = new_single_player_screen(maze)) == NULL)
	    return (1);
	}
    }
  return (0);
}

static void		print_victory()
{
  int			color = (rand() % (FG_WHITE - FG_BLACK)) + FG_BLACK;

  color_printxy((term_width / 2) - 30,
		(term_height / 2) - 5,
		color,
		"██╗   ██╗██╗ ██████╗████████╗ ██████╗ ██████╗ ██╗   ██╗");
  color_printxy((term_width / 2) - 30,
		(term_height / 2) - 4,
		color,
		"██║   ██║██║██╔════╝╚══██╔══╝██╔═══██╗██╔══██╗╚██╗ ██╔╝");
  color_printxy((term_width / 2) - 30,
		(term_height / 2) - 3,
		color,
		"██║   ██║██║██║        ██║   ██║   ██║██████╔╝ ╚████╔╝ ");
  color_printxy((term_width / 2) - 30,
		(term_height / 2) - 2,
		color,
		"╚██╗ ██╔╝██║██║        ██║   ██║   ██║██╔══██╗  ╚██╔╝  ");
  color_printxy((term_width / 2) - 30,
		(term_height / 2) - 1,
		color,
		" ╚████╔╝ ██║╚██████╗   ██║   ╚██████╔╝██║  ██║   ██║   ");
  color_printxy((term_width / 2) - 30,
		(term_height / 2),
		color,
		"  ╚═══╝  ╚═╝ ╚═════╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝   ╚═╝   ");
  color_printxy((term_width / 2) - 15,
		(term_height / 2) + 2,
		FG_BLUE,
		"Press r to restart !");
  color_printxy((term_width / 2) - 15,
		(term_height / 2) + 3,
		FG_BLUE,
		"Press escape to quit !");
}

static int		render(t_maze *maze)
{
  t_single_player_screen_data	*data =
    (t_single_player_screen_data *) maze->current_screen->data;

  draw_box((maze->size.x * 2) + 5,
	   2,
	   28,
	   8,
	   FG_BLUE);
  attron(BOLD);
  color_printxy((maze->size.x * 2) + 20 - strlen("billy"),
		3,
		FG_RED,
		"Billy");
  attroff();
  color_printxy((maze->size.x * 2) + 6,
		4,
		FG_RED,
		"Number of steps: %d", data->nbr_move);
  pretty_maze_print(maze);
  if (data->victory == 1)
    print_victory();
  return (0);
}

t_screen			*new_single_player_screen(t_maze *maze)
{
  t_screen			*screen;
  t_single_player_screen_data	*data;

  if ((screen = new_screen()) == NULL)
    return (NULL);
  screen->update = update;
  screen->render = render;
  if ((screen->data = malloc(sizeof(t_single_player_screen_data))) == NULL)
    return (NULL);
  data = (t_single_player_screen_data *) screen->data;
  data->pos.x = maze->start.x;
  data->pos.y = maze->start.y;
  if (maze->use_generated)
    {
      maze->size.x = maze->size.x * 2;
      maze->size.y = maze->size.y * 2;
      maze->maze = generate_maze_depth_search(maze->size.x, maze->size.y);
      maze->size.x++;
      maze->size.y++;
    }
  maze->maze[maze->end.y][maze->end.x] = 'e';
  data->nbr_move = 0;
  data->victory = 0;
  return (screen);
}

void			delete_single_player_screen(t_screen *screen)
{
  free(screen->data);
  delete_screen(screen);
}
