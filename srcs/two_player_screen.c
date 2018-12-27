/**
 * File              : srcs/two_player_screen.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 26.12.2018
 * Last Modified Date: 27.12.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdlib.h>
#include <string.h>
#include "screen.h"
#include "maze_helper.h"
#include "maze.h"
#include "draw_utils.h"
#include "player.h"
#include "two_player_screen.h"

static int		update(t_game *game)
{
  t_two_player_screen_data	*data =
    (t_two_player_screen_data *) game->current_screen->data;
  
  game->maze->data[data->player1->pos.y][data->player1->pos.x] = ' ';
  game->maze->data[data->player2->pos.y][data->player2->pos.x] = ' ';
  data->player1->update(game, data->player1);
  data->player2->update(game, data->player2);
  game->maze->data[data->player1->pos.y][data->player1->pos.x] = 'p';
  game->maze->data[data->player2->pos.y][data->player2->pos.x] = 'q';
  return (0);
}

static int		render(t_game *game)
{
  t_two_player_screen_data	*data =
    (t_two_player_screen_data *) game->current_screen->data;
  t_player_data			*player1_data = (t_player_data *) data->player1->data;
  t_player_data			*player2_data = (t_player_data *) data->player2->data;
  
  // Player 1
  draw_box((game->maze->size.x * 2) + 5,
	   2,
	   28,
	   8,
	   FG_RED);
  attron(BOLD);
  color_printxy((game->maze->size.x * 2) + 20 - strlen("Player 1"),
		3,
		FG_RED,
		"Player 1");
  attroff();
  color_printxy((game->maze->size.x * 2) + 6,
		4,
		FG_RED,
		"Number of steps: %d", player1_data->nbr_move);
  // Player 2
  draw_box((game->maze->size.x * 2) + 5,
	   11,
	   28,
	   8,
	   FG_YELLOW);
  attron(BOLD);
  color_printxy((game->maze->size.x * 2) + 20 - strlen("Player 2"),
		12,
		FG_YELLOW,
		"Player 2");
  attroff();
  color_printxy((game->maze->size.x * 2) + 6,
		13,
		FG_YELLOW,
		"Number of steps: %d", player2_data->nbr_move);
  pretty_maze_print(game->maze);
  return (0);
}

t_screen			*new_two_player_screen(t_game *game)
{
  t_screen			*screen;
  t_two_player_screen_data	*data;

  if ((screen = new_screen()) == NULL)
    return (NULL);
  screen->update = update;
  screen->render = render;
  if ((screen->data = malloc(sizeof(t_two_player_screen_data))) == NULL)
    return (NULL);
  data = (t_two_player_screen_data *) screen->data;
  if ((data->player1 = new_player(game->maze->start, "ABCD ")) == NULL
      || (data->player2 = new_player(game->maze->start, "zsdqf")) == NULL)
    return (NULL);
  data->victory = 0;
  game->maze->data[game->maze->end.y][game->maze->end.x] = 'e';
  return (screen);
}

void			delete_two_player_screen(t_screen *screen)
{
  delete_screen(screen);
}
