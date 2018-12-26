/**
 * File              : srcs/player_screen.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 19.12.2018
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
#include "two_player_screen.h"
#include "main_menu_screen.h"
#include "player_screen.h"

static int		update(t_maze *maze)
{
  t_player_screen_data	*data = (t_player_screen_data *) maze->current_screen->data;

  update_selection_menu(data->menu, maze->key);
  switch (maze->key)
    {
      case '\n':
	switch (data->menu->selected)
	  {
	  case 0:
	    delete_player_screen(maze->current_screen);
	    system("clear");
	    if ((maze->current_screen = new_single_player_screen(maze)) == NULL)
	      return (1);
	    break;
	  case 1:
	    delete_player_screen(maze->current_screen);
	    system("clear");
	    if ((maze->current_screen = new_two_player_screen(maze)) == NULL)
	      return (1);
	    break;
	  case 3:
	    delete_player_screen(maze->current_screen);
	    system("clear");
	    if ((maze->current_screen = new_main_menu_screen(maze)) == NULL)
	      return (1);
	    break;
	  }
	break;
    }
  return (0);
}

static void		print_title(int color)
{
  color_printxy((term_width / 2) - 50,
		2,
		color,
		"██████╗ ██╗      █████╗ ██╗   ██╗███████╗██████╗     ███╗   ███╗ ██████╗ ██████╗ ███████╗");
  color_printxy((term_width / 2) - 50,
		3,
		color,
		"██╔══██╗██║     ██╔══██╗╚██╗ ██╔╝██╔════╝██╔══██╗    ████╗ ████║██╔═══██╗██╔══██╗██╔════╝");
  color_printxy((term_width / 2) - 50,
		4,
		color,
		"██████╔╝██║     ███████║ ╚████╔╝ █████╗  ██████╔╝    ██╔████╔██║██║   ██║██║  ██║█████╗  ");
  color_printxy((term_width / 2) - 50,
		5,
		color,
		"██╔═══╝ ██║     ██╔══██║  ╚██╔╝  ██╔══╝  ██╔══██╗    ██║╚██╔╝██║██║   ██║██║  ██║██╔══╝  ");
  color_printxy((term_width / 2) - 50,
		6,
		color,
		"██║     ███████╗██║  ██║   ██║   ███████╗██║  ██║    ██║ ╚═╝ ██║╚██████╔╝██████╔╝███████╗");
  color_printxy((term_width / 2) - 50,
		7,
		color,
		"╚═╝     ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚══════╝╚═╝  ╚═╝    ╚═╝     ╚═╝ ╚═════╝ ╚═════╝ ╚══════╝");
  attroff();
}
static int		render(t_maze *maze)
{
  t_player_screen_data	*data = (t_player_screen_data *) maze->current_screen->data;

  print_title(FG_RED);
  render_selection_menu(data->menu);
  return (0);
}

t_screen		*new_player_screen(t_maze *maze)
{
  t_screen		*screen;
  t_player_screen_data	*data;

  if ((screen = new_screen()) == NULL)
    return (NULL);
  screen->update = update;
  screen->render = render;
  if ((screen->data = malloc(sizeof(t_player_screen_data))) == NULL)
    return (NULL);
  data = (t_player_screen_data *) screen->data;
  if ((data->menu = new_selection_menu((term_width / 2) - 7,
				       (term_height / 2) - 3,
				       REVERSE,
				       4,
				       "Normal mode - One player",
				       "Normal mode - Two player",
				       "Adventure mode",
				       "Back")) == NULL)
    return (NULL);
  return (screen);
}

void			delete_player_screen(t_screen *screen)
{
  t_player_screen_data	*data = (t_player_screen_data *) screen->data;

  delete_selection_menu(data->menu);
  delete_screen(screen);
}
