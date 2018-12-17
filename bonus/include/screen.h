/**
 * File              : include/screen.h
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 08.12.2018
 * Last Modified Date: 09.12.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#ifndef SCREEN_H_
# define SCREEN_H_

typedef struct s_game	t_game;

typedef int		(*t_draw_func)(t_game *game);
typedef int		(*t_input_func)(t_game *game, int key);

typedef struct		s_screen
{
  void			*data;
  t_draw_func		draw;
  t_input_func		input;
}			t_screen;

t_screen		*new_screen();

#endif /* !SCREEN_H_ */
