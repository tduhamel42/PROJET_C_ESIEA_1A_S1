/**
 * File              : srcs/survival_screen.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 29.12.2018
 * Last Modified Date: 05.01.2019
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
		5,
		FG_BLUE,
		"Level: %5d",
		data->player->attributes[LVL]);
  color_printxy((data->level->maze->size.x * 2) + 4,
		6,
		FG_MAGENTA,
		"Attack: %4d",
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

static int			render(t_game *game)
{
  t_survival_screen_data	*data =
    (t_survival_screen_data *) game->current_screen->data;

  render_survival_level(data->level);
  render_gui(data);
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
  if ((data->level = new_survival_level(10)) == NULL)
    return (NULL);
  if ((data->player = new_player(data->level->maze->start, "ABCD ")) == NULL)
    return (NULL);
  data->player->attributes[HP] = 100;
  data->player->attributes[LVL] = 1;
  data->player->attributes[ATTACK] = 2;
  return (screen);
}

void				delete_survival_screen(t_screen *screen)
{
  t_survival_screen_data	*data = (t_survival_screen_data *) screen->data;

  free(data->name);
  free(data);
  delete_screen(screen);
}
