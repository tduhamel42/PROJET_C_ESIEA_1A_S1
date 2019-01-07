/**
 * File              : include/survival_mode_screen.h
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 27.12.2018
 * Last Modified Date: 27.12.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#ifndef SURVIVAL_MODE_SCREEN_H_
# define SURVIVAL_MODE_SCREEN_H_

typedef struct s_game	t_game;

typedef struct		s_survival_mode_screen_data
{
  char			name[11];
  int			index;
}			t_survival_mode_screen_data;

t_screen		*new_survival_mode_screen(t_game *game);
void			delete_survival_mode_screen(t_screen *screen);

#endif /* !SURVIVAL_MODE_SCREEN_H_ */
