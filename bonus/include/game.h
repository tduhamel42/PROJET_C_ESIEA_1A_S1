/**
 * File              : include/game.h
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 08.12.2018
 * Last Modified Date: 08.12.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#ifndef GAME_H_
# define GAME_H_

#include <SDL2/SDL.h>
#include "screen.h"

# define SCREEN_WIDTH 1080
# define SCREEN_HEIGHT 720

typedef struct		s_game
{
  SDL_Renderer		*renderer;
  SDL_Window		*window;
  char			running;
  t_screen		*current_screen;
}			t_game;

t_game			*new_game();
int			loop(t_game *game);

#endif /* !GAME_H_ */
