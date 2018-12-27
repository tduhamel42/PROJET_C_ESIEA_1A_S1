/**
 * File              : srcs/main.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 17.12.2018
 * Last Modified Date: 27.12.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "maze.h"

int		main()
{
  t_game	*game;

  setlocale(LC_ALL, "en_US.UTF-8");
  srand(time(NULL));
  if ((game = new_game()) == NULL)
    return (EXIT_FAILURE);
  run_game(game);
  delete_game(game);
  return (EXIT_SUCCESS);
}
