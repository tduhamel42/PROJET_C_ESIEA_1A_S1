/**
 * File              : srcs/ia_screen.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 19.12.2018
 * Last Modified Date: 19.12.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdlib.h>
#include <string.h>
#include "maze.h"
#include "screen.h"
#include "draw_utils.h"
#include "maze_helper.h"
#include "ia_screen.h"

static int		update(t_maze *maze)
{
  return (0);
}

static void		render_stats(t_maze *maze)
{
  draw_box((maze->size.x * 2) + 5,
	   2,
	   28,
	   8,
	   FG_BLUE);
  attron(BOLD);
  color_printxy((maze->size.x * 2) + 20 - strlen("Stats"),
		3,
		FG_RED,
		"Stats");
  attroff();
}

static int		render(t_maze *maze)
{
  pretty_maze_print(maze);
  render_stats(maze);
  return (0);
}

t_screen		*new_ia_screen()
{
  t_screen		*screen;

  if ((screen = new_screen()) == NULL)
    return (NULL);
  screen->update = update;
  screen->render = render;
  return (screen);
}
