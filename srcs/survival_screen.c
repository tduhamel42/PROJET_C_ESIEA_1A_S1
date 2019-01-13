/**
 * File              : srcs/survival_screen.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 29.12.2018
 * Last Modified Date: 13.01.2019
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdlib.h>
#include <string.h>
#include "screen.h"
#include "player.h"
#include "maze.h"
#include "draw_utils.h"
#include "survival_screen.h"

static int			update(t_game *game)
{
  t_survival_screen_data	*data =
    (t_survival_screen_data *) game->current_screen->data;

  data->level->maze->data[data->player->pos.y][data->player->pos.x] = ' ';
  data->player->update(game, data->level->maze, data->player);
  data->level->maze->data[data->player->pos.y][data->player->pos.x] = 'p';

  if (data->player->pos.x == data->level->maze->end.x
      && data->player->pos.y == data->level->maze->end.y)
    data->level_completed = 1;
  if (data->level_completed && game->key == '\n')
    {
      delete_survival_level(data->level);
      data->level_nbr++;
      system("clear");
      if ((data->level = new_survival_level(data->level_nbr)) == NULL)
	return (1);
      data->level_completed = 0;
      data->player->pos.x = data->level->maze->start.x;
      data->player->pos.y = data->level->maze->start.y;
    }
  return (0);
}

static void			render_gui(t_survival_screen_data *data)
{
  int				box_width = term_width
    - (data->level->maze->size.x * 2) - 1;
  t_player_data			*player_data = (t_player_data *) data->player->data;

  draw_box((data->level->maze->size.x * 2) + 3,
	   1,
	   box_width,
	   20,
	   FG_GREEN);
  attron(BOLD);
  color_printxy((data->level->maze->size.x * 2) + 2 + (box_width / 2),
		3,
		FG_GREEN,
		"%s",
		data->name);
  attroff();
  for (int i = 0; i < (data->player->attributes[HP] / 10); i++)
    {
      color_printxy((data->level->maze->size.x * 2) + (3 + strlen(data->name))
		    + (box_width / 2) + i,
		    3,
		    FG_RED,
		    "❤");
    }
  color_printxy((data->level->maze->size.x * 2) + 4,
		4,
		FG_CYAN,
		"Maze Level: %2d",
		data->level_nbr);
  color_printxy((data->level->maze->size.x * 2) + 4,
		5,
		FG_BLUE,
		"Level: %7d",
		data->player->attributes[LVL]);
  color_printxy((data->level->maze->size.x * 2) + 4,
		6,
		FG_MAGENTA,
		"Attack: %6d",
		data->player->attributes[ATTACK]);
  // DEBUG
  color_printxy((data->level->maze->size.x * 2) + 4,
		8,
		FG_CYAN,
		"Dir: %7s",
		player_data->dir == UP ? "UP" :
		player_data->dir == DOWN ? "DOWN" :
		player_data->dir == LEFT ? "LEFT" :
		player_data->dir == RIGHT ? "RIGHT" : "UNKNOWN");
}

static void			render_level_completed(t_game *game)
{
  t_survival_screen_data	*data =
    (t_survival_screen_data *) game->current_screen->data;
  int				color = (rand() % (FG_WHITE - FG_BLACK)) + FG_BLACK;


    color_printxy((term_width / 2) - 30,
		(term_height / 2) - 5,
		color,
		"██╗    ███████████╗    ██╗         ██████╗ ██████╗███╗   █████████╗");
    color_printxy((term_width / 2) - 30,
		(term_height / 2) - 4,
		color,
		"██║    ████╔════██║    ██║         ██╔══████╔═══██████╗  ████╔════╝");
    color_printxy((term_width / 2) - 30,
		(term_height / 2) - 3,
		color,
		"██║ █╗ ███████╗ ██║    ██║         ██║  ████║   ████╔██╗ ███████╗  ");
    color_printxy((term_width / 2) - 30,
		(term_height / 2) - 2,
		color,
		"██║███╗████╔══╝ ██║    ██║         ██║  ████║   ████║╚██╗████╔══╝  ");
    color_printxy((term_width / 2) - 30,
		(term_height / 2) - 1,
		color,
		"╚███╔███╔█████████████████████╗    ██████╔╚██████╔██║ ╚███████████╗");
    color_printxy((term_width / 2) - 30,
		(term_height / 2),
		color,
		" ╚══╝╚══╝╚══════╚══════╚══════╝    ╚═════╝ ╚═════╝╚═╝  ╚═══╚══════╝");
    color_printxy((term_width / 2) - 15,
		(term_height / 2) + 1,
		FG_BLUE,
		"You survived level %d !", data->level_nbr);
    color_printxy((term_width / 2) - 15,
		(term_height / 2) + 2,
		FG_BLUE,
		"Press enter to continue");
      color_printxy((term_width / 2) - 15,
		(term_height / 2) + 3,
		FG_BLUE,
		"Press escape to quit !");
}

static int			render(t_game *game)
{
  t_survival_screen_data	*data =
    (t_survival_screen_data *) game->current_screen->data;

  if (data->level_completed)
    render_level_completed(game);
  else
    {
      render_survival_level(data->level);
      render_gui(data);
    }
  return (0);
}

t_screen			*new_survival_screen(t_game *game, char *name)
{
  t_screen			*screen;
  t_survival_screen_data	*data;

  (void) game;
  if ((screen = new_screen()) == NULL)
    return (NULL);
  screen->render = render;
  screen->update = update;
  if ((screen->data = malloc(sizeof(t_survival_screen_data))) == NULL)
    return (NULL);
  data = (t_survival_screen_data *) screen->data;
  data->name = strdup(name);
  data->level_nbr = 1;
  if ((data->level = new_survival_level(data->level_nbr)) == NULL)
    return (NULL);
  if ((data->player = new_player(data->level->maze->start, "ABCD ")) == NULL)
    return (NULL);
  data->player->attributes[HP] = 100;
  data->player->attributes[LVL] = 1;
  data->player->attributes[ATTACK] = 2;
  data->level_completed = 0;
  return (screen);
}

void				delete_survival_screen(t_screen *screen)
{
  t_survival_screen_data	*data = (t_survival_screen_data *) screen->data;

  free(data->name);
  free(data);
  delete_screen(screen);
}
