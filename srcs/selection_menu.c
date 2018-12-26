/**
 * File              : srcs/selection_menu.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 26.12.2018
 * Last Modified Date: 26.12.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include "draw_utils.h"
#include "selection_menu.h"

t_selection_menu	*new_selection_menu(int x,
					    int y,
					    int selected_type,
					    int size,
					    ...)
{
  t_selection_menu		*menu;
  va_list			list;

  if ((menu = malloc(sizeof(t_selection_menu))) == NULL)
    return (NULL);
  if ((menu->entries = malloc(sizeof(char *) * size)) == NULL)
    return (NULL);
  va_start(list, size);
  for (int i = 0; i < size; i++)
    menu->entries[i] = strdup(va_arg(list, char *));
  menu->selected = 0;
  menu->size = size;
  menu->pos.x = x;
  menu->pos.y = y;
  menu->selected_type = selected_type;
  return (menu);
}

void				delete_selection_menu(t_selection_menu *menu)
{
  for (int i = 0; i < menu->size; i++)
    free(menu->entries[i]);
  free(menu);
}

int			update_selection_menu(t_selection_menu *menu, char key)
{
  switch (key)
    {
    case 'A':
      menu->selected--;
      if (menu->selected < 0)
	menu->selected = menu->size - 1;
      break;
    case 'B':
      menu->selected++;
      if (menu->selected > menu->size - 1)
	menu->selected = 0;
      break;
    }
  return (0);
}

int			render_selection_menu(t_selection_menu *menu)
{
  for (int i = 0; i < menu->size; i++)
    {
      if (i == menu->selected)
	attron(menu->selected_type);
      color_printxy(menu->pos.x,
		    menu->pos.y + i,
		    FG_BLACK + (i % FG_WHITE),
		    menu->entries[i]);
      printf("\n");
      attroff();
    }
  return (0);
}
