/**
 * File              : srcs/draw_utils.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 17.12.2018
 * Last Modified Date: 19.12.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "vector2.h"
#include <wchar.h>
#include "draw_utils.h"

void			color_printxy(int x, int y, int color, char *format, ...)
{
  va_list		ap, ap_cpy;
  char			*str;
  int			size;

  va_start(ap, format);
  va_copy(ap_cpy, ap);
  size = vsnprintf(NULL, 0, format, ap_cpy) + 1;
  va_end(ap_cpy);
  if ((str = malloc(sizeof(char) * size)) == NULL)
    return ;
  vsnprintf(str, size, format, ap);
  va_end(ap);
  printf("\033[%d;%dH\033[%dm%s\033[%dm", y, x, color, str, FG_RESET);
  free(str);
}

void			attron(int attr)
{
  printf("\033[%dm", attr);
}

void			attroff()
{
  printf("\033[%dm", RESET);
}

void		set_cursor(int attr)
{
  if (attr == VISIBLE)
    printf("\033[?25h\n");
  else
    printf("\033[?25l\n");
}

void		draw_box(int start_x, int start_y, int width, int height, int color)
{
  t_vector2	cpos;

  for (int y = start_y; y < (start_y + height); y++)
    {
      for (int x = start_x; x < (start_x + width); x++)
	{
	  cpos.x = x;
	  cpos.y = y;
	  if (y == start_y && x == start_x)
	    printf("\033[%d;%dH\033[%dm╔", cpos.y, cpos.x, color);
	  else if (x == start_x && y == (start_y + height) - 1)
	    printf("\033[%d;%dH\033[%dm╚", cpos.y, cpos.x, color);
	  else if (x == (start_x + width) - 1 && y == start_y)
	    printf("\033[%d;%dH\033[%dm╗", cpos.y, cpos.x, color);
	  else if (x == (start_x + width) - 1 && y == (start_y + height) - 1)
	    printf("\033[%d;%dH\033[%dm╝", cpos.y, cpos.x, color);
	  else if (x == start_x || x == (start_x + width) - 1)
	    printf("\033[%d;%dH\033[%dm║", cpos.y, cpos.x, color);
	  else if (y == start_y || y == (start_y + height) - 1)
	    printf("\033[%d;%dH\033[%dm═", cpos.y, cpos.x, color);
	}
    }
  attroff();
}

void		move_cursor(int x, int y)
{
  printf("\033[%d;%dH\n", y, x);
}
