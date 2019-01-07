/**
 * File              : srcs/ia_screen.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 19.12.2018
 * Last Modified Date: 07.01.2019
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdlib.h>
#include <string.h>
#include "maze.h"
#include "screen.h"
#include "draw_utils.h"
#include "maze_helper.h"
#include "entity.h"
#include "ia_screen.h"

static int		update(t_game *game)
{
  t_ia_screen_data	*data = (t_ia_screen_data *) game->current_screen->data;

  (void) data;
  return (0);
}

static void		render_stats(t_game *game)
{
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
}

static int		render(t_game *game)
{
  pretty_maze_print(game->maze);
  render_stats(game);
  return (0);
}

t_screen		*new_ia_screen()
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
  return (screen);
}
