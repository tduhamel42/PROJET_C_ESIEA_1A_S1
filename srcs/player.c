/**
 * File              : srcs/player.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 27.12.2018
 * Last Modified Date: 29.12.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdlib.h>
#include <string.h>
#include "maze.h"
#include "player.h"

static int		update(t_game *game, t_maze *maze, t_entity *player)
{
  t_player_data		*data = (t_player_data *) player->data;

    if (game->key == data->keys[UP])
      {
	if (player->pos.y - 1 > 0
	    && maze->data[player->pos.y - 1][player->pos.x] != '#')
	  {
	    --player->pos.y;
	    ++data->nbr_move;
	  }
	data->dir = UP;
      }
    else if (game->key == data->keys[DOWN])
      {
	if (player->pos.y + 1 < maze->size.y
	    && maze->data[player->pos.y + 1][player->pos.x] != '#')
	  {
	    ++player->pos.y;
	    ++data->nbr_move;
	  }
	data->dir = DOWN;
      }
    else if (game->key == data->keys[LEFT])
      {
	if (player->pos.x + 1 < maze->size.x
	    && maze->data[player->pos.y][player->pos.x + 1] != '#')
	  {
	    ++player->pos.x;
	    ++data->nbr_move;
	  }
	data->dir = LEFT;
      }
    else if (game->key == data->keys[RIGHT])
      {
	if (player->pos.x - 1 > 0
	    && maze->data[player->pos.y][player->pos.x - 1] != '#')
	  {
	    --player->pos.x;
	    ++data->nbr_move;
	  }
	data->dir = RIGHT;
      }
  return (0);
}

t_entity		*new_player(t_vector2 pos, const char *keys)
{
  t_entity		*player;
  t_player_data		*data;

  if ((player = new_entity()) == NULL
      || (player->data = malloc(sizeof(t_player_data))) == NULL)
    return (NULL);
  data = (t_player_data *) player->data;
  data->keys = strndup(keys, 5);
  data->nbr_move = 0;
  player->pos = pos;
  data->dir = UP;
  player->update = update;
  return (player);
}

void			delete_player(t_entity *player)
{
  t_player_data		*data = (t_player_data *) player->data;

  free(data->keys);
  free(data);
  delete_entity(player);
}
