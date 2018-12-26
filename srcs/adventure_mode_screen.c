/**
 * File              : srcs/adventure_mode_screen.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 26.12.2018
 * Last Modified Date: 26.12.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdlib.h>
#include "screen.h"
#include "maze.h"
#include "draw_utils.h"
#include "player_screen.h"
#include "adventure_mode_screen.h"

static int		update(t_maze *maze)
{
  t_adventure_mode_screen_data	*data =
    (t_adventure_mode_screen_data *) maze->current_screen->data;

  update_selection_menu(data->menu, maze->key);
  switch (maze->key)
    {
    case '\n':
      switch (data->menu->selected)
	{
	case 0:
	  break;
	case 1:
	  break;
	case 2:
	  delete_adventure_mode_screen(maze->current_screen);
	  system("clear");
	  if ((maze->current_screen = new_player_screen(maze)) == NULL)
	    return (1);
	  break;
	}
      break;
    }
  return (0);
} 

static void		print_title(int color)
{
  color_printxy(10,1,color,"   ▄████████ ████████▄   ▄█    █▄     ▄████████ ███▄▄▄▄       ███     ███    █▄     ▄████████    ▄████████        ▄▄▄▄███▄▄▄▄    ▄██████▄  ████████▄     ▄████████ ");color_printxy(10,2,color,"  ███    ███ ███   ▀███ ███    ███   ███    ███ ███▀▀▀██▄ ▀█████████▄ ███    ███   ███    ███   ███    ███      ▄██▀▀▀███▀▀▀██▄ ███    ███ ███   ▀███   ███    ███ ");color_printxy(10,3,color,"  ███    ███ ███    ███ ███    ███   ███    █▀  ███   ███    ▀███▀▀██ ███    ███   ███    ███   ███    █▀       ███   ███   ███ ███    ███ ███    ███   ███    █▀  ");color_printxy(10,4,color,"  ███    ███ ███    ███ ███    ███  ▄███▄▄▄     ███   ███     ███   ▀ ███    ███  ▄███▄▄▄▄██▀  ▄███▄▄▄          ███   ███   ███ ███    ███ ███    ███  ▄███▄▄▄     ");color_printxy(10,5,color,"▀███████████ ███    ███ ███    ███ ▀▀███▀▀▀     ███   ███     ███     ███    ███ ▀▀███▀▀▀▀▀   ▀▀███▀▀▀          ███   ███   ███ ███    ███ ███    ███ ▀▀███▀▀▀     ");color_printxy(10,6,color,"  ███    ███ ███    ███ ███    ███   ███    █▄  ███   ███     ███     ███    ███ ▀███████████   ███    █▄       ███   ███   ███ ███    ███ ███    ███   ███    █▄  ");color_printxy(10,7,color,"  ███    ███ ███   ▄███ ███    ███   ███    ███ ███   ███     ███     ███    ███   ███    ███   ███    ███      ███   ███   ███ ███    ███ ███   ▄███   ███    ███ ");color_printxy(10,8,color,"  ███    █▀  ████████▀   ▀██████▀    ██████████  ▀█   █▀     ▄████▀   ████████▀    ███    ███   ██████████       ▀█   ███   █▀   ▀██████▀  ████████▀    ██████████ ");
}

static int			render(t_maze *maze)
{
  t_adventure_mode_screen_data	*data =
    (t_adventure_mode_screen_data *) maze->current_screen->data;

  print_title(FG_RED);
  draw_box((term_width / 2) - 20,
	   (term_height / 2) - 5,
	   30,
	   8,
	   FG_GREEN);
  attron(BLINK);
  color_printxy((term_width / 2) - 15,
	   (term_height / 2) - 4,
	   FG_GREEN,
	   "Will you survive ?");
  attroff();
  render_selection_menu(data->menu);
  return (0);
} 

t_screen			*new_adventure_mode_screen(t_maze *maze)
{
  t_screen			*screen;
  t_adventure_mode_screen_data	*data;

  (void) maze;
  if ((screen = new_screen()) == NULL)
    return (NULL);
  screen->render = render;
  screen->update = update;
  if ((screen->data = malloc(sizeof(t_adventure_mode_screen_data))) == NULL)
    return (NULL);
  data = (t_adventure_mode_screen_data *) screen->data;
  if ((data->menu = new_selection_menu((term_width / 2) - 18,
				       (term_height / 2) - 2,
				       BOLD,
				       3,
				       "Normal mode",
				       "Survival Mode",
				       "Back")) == NULL)
    return (NULL);
  return (screen);
}

void			delete_adventure_mode_screen(t_screen *screen)
{
  t_adventure_mode_screen_data	*data = (t_adventure_mode_screen_data *) screen->data;

  delete_selection_menu(data->menu);
  delete_screen(screen);
}
