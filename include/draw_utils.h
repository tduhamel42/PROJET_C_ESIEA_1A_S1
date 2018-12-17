/**
 * File              : include/draw_utils.h
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 17.12.2018
 * Last Modified Date: 17.12.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#ifndef DRAW_UTILS_H_
# define DRAW_UTILS_H_

enum		e_color
{
  FG_BLACK = 31,
  FG_RED,
  FG_GREEN,
  FG_YELLOW,
  FG_BLUE,
  FG_MAGENTA,
  FG_CYAN,
  FG_WHITE,
  FG_RESET = 39,

  BG_BLACK,
  BG_RED,
  BG_GREEN,
  BG_YELLOW,
  BG_BLUE,
  BG_MAGENTA,
  BG_CYAN,
  BG_WHITE,
  BG_RESET = 49
};

enum		e_mode
{
  RESET = 0,
  BOLD,
  DIM,
  STANDOUT,
  UNDERSCORE,
  BLINK,
  REVERSE
};

void		color_printxy(int x, int y, int color, char *format, ...);
void		attron(int attr);
void		attroff();
void		draw_box(int x, int y, int width, int height);

#endif /* !DRAW_UTILS_H_ */
