/**
 * File              : srcs/draw_utils.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 17.12.2018
 * Last Modified Date: 17.12.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
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

void		draw_box(int x, int y, int width, int height)
{
  for (int y = 0; y < height; y++)
    {
      for (int x = 0; x < width; x++)
	{
	}
    }
}
