/**
 * File              : srcs/game.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 08.12.2018
 * Last Modified Date: 09.12.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdlib.h>
#include <stdio.h>
#include "screen.h"
#include "main_menu.h"
#include "game.h"

t_game		*new_game()
{
  t_game	*game;

  if ((game = malloc(sizeof(t_game))) == NULL)
    return (NULL);
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
      dprintf(2, "Error init sdl: %s\n", SDL_GetError());
      return (NULL);
    }
  if ((game->window = SDL_CreateWindow("dev_Billy",
				       SDL_WINDOWPOS_UNDEFINED,
				       SDL_WINDOWPOS_UNDEFINED,
				       SCREEN_WIDTH,
				       SCREEN_HEIGHT,
				       0)) == NULL)
    {
      dprintf(2, "Cannot open window: %s\n", SDL_GetError());
      return (NULL);
    }
  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
  if ((game->renderer = SDL_CreateRenderer(game->window,
					  -1,
					  SDL_RENDERER_ACCELERATED)) == NULL)
    {
      dprintf(2, "Cannot create renderer: %s\n", SDL_GetError());
      return (NULL);
    }
  game->running = 1;
  if ((game->current_screen = new_main_menu()) == NULL)
    return (NULL);
  return (game);
}

static void	handle_event(t_game *game)
{
  SDL_Event	event;

  while (SDL_PollEvent(&event))
    {
      switch (event.type)
	{
	case SDL_QUIT:
	  game->running = 0;
	  break;

	case SDL_KEYDOWN:
	  if (game->current_screen && game->current_screen->input)
	    game->current_screen->input(game, event.key.keysym.scancode);
	  break;

	default:
	  break;
	}
    }
}

int		loop(t_game *game)
{
  while (game->running)
    {
      SDL_RenderClear(game->renderer);

      handle_event(game);

      if (game->current_screen && game->current_screen->draw)
	game->current_screen->draw(game);

      SDL_RenderPresent(game->renderer);
      SDL_Delay(16);
    }
  SDL_Quit();
  return (0);
}
