/**
 * File              : srcs/survival_mode_screen.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 27.12.2018
 * Last Modified Date: 29.12.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdlib.h>
#include <string.h>
#include "maze_generator.h"
#include "survival_screen.h"
#include "maze.h"
#include "draw_utils.h"
#include "survival_mode_screen.h"

static int		update(t_game *game)
{
  t_survival_mode_screen_data	*data =
    (t_survival_mode_screen_data *) game->current_screen->data;
  char				*tmp;

  if ((game->key >= 'a' && game->key <= 'z')
      || (game->key >= 'A' && game->key <= 'Z'))
    {
      if (data->index < 10)
	data->name[data->index++] = game->key;
    }
  switch (game->key)
    {
    case '\b':
      if (data->index > 0)
	{
	  data->name[data->index - 1] = 0;
	  --data->index;
	}
      break;
    case '\n':
	  data->name[10] = 0;
	  tmp = strdup(data->name);
	  delete_survival_mode_screen(game->current_screen);
	  system("clear");
	  if ((game->current_screen = new_survival_screen(game, tmp)) == NULL)
	    return (1);
	  free(tmp);
      break;
    }
  return (0);
} 

static void		print_title(int color)
{
  color_printxy((term_width/2)-25,2,color,"  ██████ █    ██ ██▀███  ██▒   █▓██▓██▒   █▓▄▄▄      ██▓    ");color_printxy((term_width/2)-25,3,color,"▒██    ▒ ██  ▓██▓██ ▒ ██▓██░   █▓██▓██░   █▒████▄   ▓██▒    ");color_printxy((term_width/2)-25,4,color,"░ ▓██▄  ▓██  ▒██▓██ ░▄█ ▒▓██  █▒▒██▒▓██  █▒▒██  ▀█▄ ▒██░    ");color_printxy((term_width/2)-25,5,color,"  ▒   ██▓▓█  ░██▒██▀▀█▄   ▒██ █░░██░ ▒██ █░░██▄▄▄▄██▒██░    ");color_printxy((term_width/2)-25,6,color,"▒██████▒▒▒█████▓░██▓ ▒██▒  ▒▀█░ ░██░  ▒▀█░  ▓█   ▓██░██████▒");color_printxy((term_width/2)-25,7,color,"▒ ▒▓▒ ▒ ░▒▓▒ ▒ ▒░ ▒▓ ░▒▓░  ░ ▐░ ░▓    ░ ▐░  ▒▒   ▓▒█░ ▒░▓  ░");color_printxy((term_width/2)-25,8,color,"░ ░▒  ░ ░░▒░ ░ ░  ░▒ ░ ▒░  ░ ░░  ▒ ░  ░ ░░   ▒   ▒▒ ░ ░ ▒  ░");color_printxy((term_width/2)-25,9,color,"░  ░  ░  ░░░ ░ ░  ░░   ░     ░░  ▒ ░    ░░   ░   ▒    ░ ░   ");color_printxy((term_width/2)-25,10,color,"      ░    ░       ░          ░  ░       ░       ░  ░   ░  ░");color_printxy((term_width/2)-25,11,color,"                             ░          ░                   ");
}

static int			render(t_game *game)
{
  t_survival_mode_screen_data	*data =
    (t_survival_mode_screen_data *) game->current_screen->data;

  print_title(FG_MAGENTA);
  attron(BOLD);
  color_printxy(10,
		(term_height / 2) - 10,
		FG_WHITE,
		"Highscores");
  attroff();
  attron(BLINK);
  color_printxy((term_width / 2) - (strlen("Enter your name:") / 2),
		(term_height / 2) - 10,
		FG_BLUE,
		"Enter your name:");
  attroff();
  draw_box((term_width / 2) - (strlen("Enter your name:") / 2) - 2,
	   (term_height / 2) - 8,
	   20,
	   4,
	   FG_CYAN);
  attron(BOLD);
  color_printxy((term_width / 2) - (strlen("Enter your name:") / 2) + 1,
		(term_height / 2) - 7,
		FG_WHITE,
		"%10s", data->name);
  attroff();
  color_printxy((term_width / 2) - (strlen("Press enter to start !") / 2),
		(term_height / 2),
		FG_RED,
		"Press enter to start !");
  return (0);
} 

t_screen			*new_survival_mode_screen(t_game *game)
{
  t_screen			*screen;
  t_survival_mode_screen_data	*data;

  (void) game;
  if ((screen = new_screen()) == NULL)
    return (NULL);
  screen->render = render;
  screen->update = update;
  if ((screen->data = malloc(sizeof(t_survival_mode_screen_data))) == NULL)
    return (NULL);
  data = (t_survival_mode_screen_data *) screen->data;
  data->index = 0;
  bzero(data->name, 11);
  return (screen);
}

void			delete_survival_mode_screen(t_screen *screen)
{
  delete_screen(screen);
}
