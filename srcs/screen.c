/**
 * File              : srcs/screen.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 17.12.2018
 * Last Modified Date: 17.12.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdlib.h>
#include "screen.h"

t_screen		*new_screen()
{
  t_screen		*screen;

  if ((screen = malloc(sizeof(t_screen))) == NULL)
    return (NULL);
  screen->data = NULL;
  screen->render = NULL;
  screen->update = NULL;
  return (screen);
}

void			delete_screen(t_screen *screen)
{
  free(screen);
}
