/**
 * File              : srcs/main.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 08.12.2018
 * Last Modified Date: 08.12.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdio.h>
#include "game.h"

int		main()
{
  t_game	*game;

  if ((game = new_game()) == NULL)
    return (1);
  return (loop(game));
}
