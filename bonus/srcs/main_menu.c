/**
 * File              : srcs/main_menu.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 08.12.2018
 * Last Modified Date: 09.12.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <SDL2/SDL.h>
#include "game.h"
#include "game_screen.h"
#include "main_menu.h"

static int		draw(t_game *game)
{
  SDL_SetRenderDrawColor(game->renderer, 96, 128, 255, 255);
  return (0);
}

static int		input(t_game *game, int key)
{
  switch (key)
    {
    case SDL_SCANCODE_SPACE:
      if ((game->current_screen = new_game_screen()) == NULL)
	return (1);
      break;
    }
  return (0);
}

t_screen		*new_main_menu()
{
  t_screen		*main_menu;

  if ((main_menu = new_screen()) == NULL)
    return (NULL);
  main_menu->draw = draw;
  main_menu->input = input;
  main_menu->data = NULL;
  return (main_menu);
}
