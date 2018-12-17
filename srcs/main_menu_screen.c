/**
 * File              : srcs/main_menu_screen.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 17.12.2018
 * Last Modified Date: 18.12.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdlib.h>
#include <string.h>
#include "maze.h"
#include "screen.h"
#include "draw_utils.h"
#include "main_menu_screen.h"

static int		update(t_maze *maze)
{
  t_main_menu_data	*data = (t_main_menu_data *) maze->current_screen->data;

  switch (maze->key)
    {
    case  'B':
      data->selection++;
      if (data->selection > 2)
	data->selection = 0;
      break;
    case  'A':
      data->selection--;
      if (data->selection < 0)
	data->selection = 2;
      break;
    case '\n':
      exit(0);
      break;
    }
  return (0);
}

static int		render(t_maze *maze)
{
  t_main_menu_data	*data = (t_main_menu_data *) maze->current_screen->data;

  attron(BOLD);
  attron(BLINK);
  color_printxy((term_width / 2) - strlen("Where is billy ?"),
		(term_height / 2) - 5,
		FG_YELLOW,
		"%s\n",
		"Where is billy ?");
  attroff();
  attron(STANDOUT);
  if (data->selection == 0)
    attron(UNDERSCORE);
  color_printxy((term_width / 2) - 7,
		(term_height / 2) - 3,
		FG_CYAN,
		"IA mode\n");
  attroff();
  if (data->selection == 1)
    attron(UNDERSCORE);
  color_printxy((term_width / 2) - 7,
		(term_height / 2) - 2,
		FG_MAGENTA,
		"Player mode\n");
  attroff();
  if (data->selection == 2)
    attron(UNDERSCORE);
  color_printxy((term_width / 2) - 7,
		(term_height / 2) - 1,
		FG_RED,
		"Exit\n");
  attroff();
  return (0);
}

t_screen		*new_main_menu_screen()
{
  t_screen		*screen;
  t_main_menu_data	*data;

  if ((screen = new_screen()) == NULL)
    return (NULL);
  screen->update = update;
  screen->render = render;
  if ((screen->data = malloc(sizeof(t_main_menu_data))) == NULL)
    return (NULL);
  data = (t_main_menu_data *) screen->data;
  data->selection = 0;
  return (screen);
}
