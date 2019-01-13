/**
 * File              : include/survival_screen.h
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 29.12.2018
 * Last Modified Date: 13.01.2019
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#ifndef SURVIVAL_SCREEN_H_
# define SURVIVAL_SCREEN_H_

#include "linked_list.h"
#include "survival_level.h"

typedef struct s_game		t_game;
typedef struct s_screen		t_screen;
typedef struct s_entity		t_entity;

typedef struct			s_survival_screen_data
{
  t_entity			*player;
  char				*name;
  t_survival_level		*level;
  int				level_nbr;
  char				level_completed;
}				t_survival_screen_data;

t_screen		*new_survival_screen(t_game *game, char *name);
void			delete_survival_screen(t_screen *screen);

#endif /* !SURVIVAL_SCREEN_H_ */
