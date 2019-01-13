/**
 * File              : srcs/ia_screen.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 19.12.2018
 * Last Modified Date: 13.01.2019
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "linked_list.h"
#include "astar.h"
#include "maze.h"
#include "screen.h"
#include "maze_generator.h"
#include "draw_utils.h"
#include "maze_helper.h"
#include "entity.h"
#include "ia_screen.h"

static int		update(t_game *game)
{
  t_ia_screen_data	*data = (t_ia_screen_data *) game->current_screen->data;
  t_node		*node;

  if (data->path)
    {
      node = (t_node *) data->path->data;
      game->maze->data[node->pos.y][node->pos.x] = '1';
      data->path = data->path->prev;
      if (data->path)
	{
	  node = (t_node *) data->path->data;
	  game->maze->data[node->pos.y][node->pos.x] = 'p';
	}
    }
  switch (game->key)
    {
    case '+':
      if (data->speed > 0)
	data->speed -= 10000;
      break;
    case '-':
      data->speed += 10000;
      break;
    }
  if (!data->path)
    {
      if (data->victory == 0)
	system("clear");
      data->victory = 1;
    }
  return (0);
}

static void		render_stats(t_game *game)
{
  t_ia_screen_data	*data = (t_ia_screen_data *) game->current_screen->data;
  t_node		*node;

  draw_box((game->maze->size.x * 2) + 5,
	   2,
	   28,
	   8,
	   FG_BLUE);
  attron(BOLD);
  color_printxy((game->maze->size.x * 2) + 20 - strlen("Stats"),
		3,
		FG_RED,
		"Stats");
  attroff();
  if (data->path)
    {
      node = (t_node *) data->path->data;
      color_printxy((game->maze->size.x * 2) + 6,
		5,
		FG_WHITE,
		"Position: %3d %3d", node->pos.x, node->pos.y);
    }
}

static void		print_no_exit()
{
  int			color = (rand() % (FG_WHITE - FG_BLACK)) + FG_BLACK;

  color_printxy((term_width / 2) - 30,
		(term_height / 2) - 5,
		color,
		"███╗   ██╗██████╗     █████████╗  ████████████╗");
  color_printxy((term_width / 2) - 30,
		(term_height / 2) - 4,
		color,
		"████╗  ████╔═══██╗    ██╔════╚██╗██╔██╚══██╔══╝");
  color_printxy((term_width / 2) - 30,
		(term_height / 2) - 3,
		color,
		"██╔██╗ ████║   ██║    █████╗  ╚███╔╝██║  ██║   ");
  color_printxy((term_width / 2) - 30,
		(term_height / 2) - 2,
		color,
		"██║╚██╗████║   ██║    ██╔══╝  ██╔██╗██║  ██║   ");
  color_printxy((term_width / 2) - 30,
		(term_height / 2) - 1,
		color,
		"██║ ╚████╚██████╔╝    █████████╔╝ ████║  ██║   ");
  color_printxy((term_width / 2) - 30,
		(term_height / 2),
		color,
		"╚═╝  ╚═══╝╚═════╝     ╚══════╚═╝  ╚═╚═╝  ╚═╝   ");
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

static int		render(t_game *game)
{
  t_ia_screen_data	*data = (t_ia_screen_data *) game->current_screen->data;

  if (data->no_exit == 0)
    {
      if (!data->victory)
	{
	  pretty_maze_print(game->maze);
	  render_stats(game);
	  color_printxy((game->maze->size.x * 2) + 5,
			10,
			FG_BLUE,
			"Press + or - to increase or decrease speed !");
	  usleep(data->speed);
	}
      else
	print_victory();
    }
  else
    print_no_exit();
  return (0);
}

t_screen		*new_ia_screen(t_game *game)
{
  t_screen		*screen;
  t_ia_screen_data	*data;

  if ((screen = new_screen()) == NULL)
    return (NULL);
  screen->update = update;
  screen->render = render;
  if ((screen->data = malloc(sizeof(t_ia_screen_data))) == NULL)
    return (NULL);
  data = (t_ia_screen_data *) screen->data;
  if ((data->ia = new_entity()) == NULL)
    return (NULL);
  data->speed = 300000;
  data->no_exit = 0;
  data->victory = 0;
  if (game->use_generated)
    {
      game->maze->size.x = game->maze->size.x * 8;
      game->maze->size.y = game->maze->size.y * 6;
      game->maze->data = generate_maze_depth_search(game->maze->size.x,
						    game->maze->size.y);
      game->maze->size.x++;
      game->maze->size.y++;
      game->maze->end.x = game->maze->size.x - 2;
      game->maze->end.y = game->maze->size.y - 2;
    }
  game->maze->data[game->maze->end.y][game->maze->end.x] = 'e';
  data->path = NULL;
  if (astar(game->maze, &data->path, game->maze->start, game->maze->end))
    data->no_exit = 1;
  llist_go_last(&data->path);
  game->maze->data[game->maze->start.y][game->maze->start.x] = '1';
  return (screen);
}

void			delete_ia_screen(t_screen *screen)
{
  delete_screen(screen);
}
