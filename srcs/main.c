/**
 * File              : srcs/main.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 17.12.2018
 * Last Modified Date: 17.12.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdlib.h>
#include "maze.h"

int		main()
{
  t_maze	*maze;

  if ((maze = new_maze()) == NULL)
    return (EXIT_FAILURE);
  run_maze(maze);
  return (EXIT_SUCCESS);
}
