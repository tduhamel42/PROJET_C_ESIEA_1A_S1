/**
 * File              : single_player_screen.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 26.12.2018
 * Last Modified Date: 20.01.2019
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdlib.h>
#include <string.h>
#include "screen.h"
#include "maze_helper.h"
#include "maze_generator.h"
#include "maze.h"
#include "draw_utils.h"
#include "player.h"
#include "single_player_screen.h"

static int		update(t_game *game)
{
  t_single_player_screen_data	*data =
    (t_single_player_screen_data *) game->current_screen->data;

  game->maze->data[data->player->pos.y][data->player->pos.x] = '1';
  data->player->update(game, game->maze, data->player);
  game->maze->data[data->player->pos.y][data->player->pos.x] = 'p';
  if (data->player->pos.x == game->maze->end.x
      && data->player->pos.y == game->maze->end.y)
    data->victory = 1;
  if (data->victory)
    { 
      if (game->key == 'r')
	{
	  delete_single_player_screen(game->current_screen);
	  system("clear");
	  if ((game->current_screen = new_single_player_screen(game)) == NULL)
	    return (1);
	}
    }
  return (0);
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
t_single_player_screen_data	*data =
  (t_single_player_screen_data *) game->current_screen->data;
t_player_data			*player_data = (t_player_data *) data->player->data;

draw_box((game->maze->size.x * 2) + 5,
	 2,
	 28,
	 8,
	 FG_BLUE);
attron(BOLD);
color_printxy((game->maze->size.x * 2) + 20 - strlen("billy"),
	      3,
	      FG_RED,
	      "Billy");
attroff();
color_printxy((game->maze->size.x * 2) + 6,
	      4,
	      FG_RED,
	      "Number of steps: %4d", player_data->nbr_move);
if (!data->victory)
  pretty_maze_print(game->maze);
if (data->victory == 1)
  print_victory();
return (0);
}

t_screen			*new_single_player_screen(t_game *game)
{
t_screen			*screen;
t_single_player_screen_data	*data;

if ((screen = new_screen()) == NULL)
  return (NULL);
screen->update = update;
screen->render = render;
if ((screen->data = malloc(sizeof(t_single_player_screen_data))) == NULL)
  return (NULL);
data = (t_single_player_screen_data *) screen->data;
if ((data->player = new_player(game->maze->start, "ABCD ")) == NULL)
  return (NULL);
if (game->use_generated)
  {
    game->maze->size.x = game->maze->size.x * 2;
    game->maze->size.y = game->maze->size.y * 2;
    game->maze->data = generate_maze_depth_search(game->maze->size.x,
						  game->maze->size.y);
    game->maze->size.x++;
    game->maze->size.y++;
    game->maze->end.x = game->maze->size.x - 2;
    game->maze->end.y = game->maze->size.y - 2;
  }
game->maze->data[game->maze->end.y][game->maze->end.x] = 'e';
data->victory = 0;
return (screen);
}

void			delete_single_player_screen(t_screen *screen)
{
t_single_player_screen_data	*data = (t_single_player_screen_data *) screen->data;

delete_player(data->player);
free(screen->data);
delete_screen(screen);
}
