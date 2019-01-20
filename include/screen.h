/**
 * File              : screen.h
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 17.12.2018
 * Last Modified Date: 20.01.2019
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#ifndef SCREEN_H_
# define SCREEN_H_

/*
** The t_screen struct allows me to change easily from
** a screen to another 
**
** see maze.c run_game
*/

typedef struct s_game	t_game;

typedef int		(*t_screen_func)(t_game *game);

typedef struct		s_screen
{
  void			*data;
  t_screen_func		render;
  t_screen_func		update;
}			t_screen;

t_screen		*new_screen();
void			delete_screen(t_screen *screen);

#endif /* !SCREEN_H_ */
