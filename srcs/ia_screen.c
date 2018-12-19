/**
 * File              : srcs/ia_screen.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 19.12.2018
 * Last Modified Date: 19.12.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdlib.h>
#include "screen.h"
#include "ia_screen.h"

static int		update(t_maze *maze)
{
  return (0);
}

static int		render(t_maze *maze)
{
  return (0);
}

t_screen		*new_ia_screen()
{
  t_screen		*screen;

  if ((screen = new_screen()) == NULL)
    return (NULL);
  screen->update = update;
  screen->render = render;
  return (screen);
}
