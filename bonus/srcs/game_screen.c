/**
 * File              : srcs/game_screen.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 09.12.2018
 * Last Modified Date: 09.12.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <SDL2/SDL.h>
#include <stdlib.h>
#include "game.h"
#include "game_screen.h"

static int		draw(t_game *game)
{
  SDL_SetRenderDrawColor(game->renderer, 96, 255, 255, 255);
  return (0);
}

static int		input(t_game *game, int key)
{
  return (0);
}

t_screen		*new_game_screen()
{
  t_screen		*game_screen;
  
  if ((game_screen = new_screen()) == NULL)
    return (NULL);
  game_screen->draw = draw;
  game_screen->input = input;
  game_screen->data = NULL;
  return (game_screen);
}
