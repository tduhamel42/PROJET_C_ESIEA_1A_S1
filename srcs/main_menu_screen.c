/**
 * File              : main_menu_screen.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 17.12.2018
 * Last Modified Date: 20.01.2019
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdlib.h>
#include <string.h>
#include "maze.h"
#include "screen.h"
#include "draw_utils.h"
#include "ia_screen.h"
#include "player_screen.h"
#include "main_menu_screen.h"

static int		update(t_game *game)
{
  t_main_menu_data	*data = (t_main_menu_data *) game->current_screen->data;

  update_selection_menu(data->menu, game->key);
  update_selection_menu_pos(data->menu,
			    (term_width / 2) - 7,
			    (term_height / 2) - 3);
  switch (game->key)
    {
    case ' ':
      if (game->use_generated)
	game->use_generated = 0;
      else
	game->use_generated = 1;
      break;
    case '\n':
      switch (data->menu->selected)
	{
	case 0:
	  delete_main_menu_screen(game->current_screen);
	  system("clear");
	  if ((game->current_screen = new_ia_screen(game)) == NULL)
	    return (1);
	  break;
	case 1:
	  delete_main_menu_screen(game->current_screen);
	  system("clear");
	  if ((game->current_screen = new_player_screen(game)) == NULL)
	    return (1);
	  break;
	case 2:
	  game->running = 0;
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
		"██████╗ ██╗██╗     ██╗     ██╗   ██╗███████╗    ███╗   ███╗ █████╗ ███████╗███████╗");
  color_printxy((term_width / 2) - 50,
		3,
		color,
		"██╔══██╗██║██║     ██║     ╚██╗ ██╔╝██╔════╝    ████╗ ████║██╔══██╗╚══███╔╝██╔════╝");
  color_printxy((term_width / 2) - 50,
		4,
		color,
		"██████╔╝██║██║     ██║      ╚████╔╝ ███████╗    ██╔████╔██║███████║  ███╔╝ █████╗  ");
  color_printxy((term_width / 2) - 50,
		5,
		color,
		"██╔══██╗██║██║     ██║       ╚██╔╝  ╚════██║    ██║╚██╔╝██║██╔══██║ ███╔╝  ██╔══╝  ");
  color_printxy((term_width / 2) - 50,
		6,
		color,
		"██████╔╝██║███████╗███████╗   ██║   ███████║    ██║ ╚═╝ ██║██║  ██║███████╗███████╗");
  color_printxy((term_width / 2) - 50,
		7,
		color,
		"╚═════╝ ╚═╝╚══════╝╚══════╝   ╚═╝   ╚══════╝    ╚═╝     ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝");
}

static void		print_help()
{
  attron(BOLD);
  color_printxy(5,
		(term_height / 2),
		FG_YELLOW,
		"Help:");
  attroff();
  color_printxy(5,
		(term_height / 2) + 1,
		FG_MAGENTA,
		"Use ⇦ ⇧ ⇨ ⇩ to move around !");
  color_printxy(5,
		(term_height / 2) + 2,
		FG_MAGENTA,
		"Press Escape to quit !");
}

static int		render(t_game *game)
{
  t_main_menu_data	*data = (t_main_menu_data *) game->current_screen->data;
  int			color = (rand() % (FG_WHITE - FG_BLACK)) + FG_BLACK;

  print_title(color);
  print_help();
  draw_box((term_width / 2) - strlen("Where is billy ?") - 2,
	   (term_height / 2) - 6,
	   30,
	   8,
	   color);
  attron(BOLD);
  attron(BLINK);
  color_printxy((term_width / 2) - strlen("Where is billy ?") + 4,
		(term_height / 2) - 5,
		FG_YELLOW,
		"%s\n",
		"Where is billy ?");
  attroff();
  attron(STANDOUT);
  render_selection_menu(data->menu);
  color_printxy(term_width - (strlen("Press SPACE to change !") * 2),
		(term_height / 2),
		FG_YELLOW,
		"Press SPACE to change !\n");
  attron(BOLD);
  if (game->use_generated)
    color_printxy(term_width - (strlen("Press SPACE to change !") * 2),
		  (term_height / 2) + 1,
		  FG_YELLOW,
		  "Using generated maze !\n");
  else
    color_printxy(term_width - (strlen("Press SPACE to change !") * 2),
		  (term_height / 2) + 1,
		  FG_YELLOW,
		  "Using maze from file !\n");
  attroff();
  attron(STANDOUT);
  color_printxy(term_width  - strlen("Created by Tanguy Duhamel"),
		term_height - 1,
		FG_YELLOW,
		"Created by Tanguy Duhamel\n");
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
  if ((data->menu = new_selection_menu((term_width / 2) - 7,
				       (term_height / 2) - 3,
				       UNDERSCORE,
				       3,
				       "IA Mode",
				       "Player mode",
				       "Exit")) == NULL)
    return (NULL);
  return (screen);
}

void			delete_main_menu_screen(t_screen *screen)
{
  t_main_menu_data	*data = (t_main_menu_data *) screen->data;
  
  delete_selection_menu(data->menu);
  delete_screen(screen);
}
