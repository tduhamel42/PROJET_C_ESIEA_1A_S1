/**
 * File              : include/survival_level.h
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 29.12.2018
 * Last Modified Date: 29.12.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#ifndef SURVIVAL_LEVEL_H_
# define SURVIVAL_LEVEL_H_

typedef struct s_maze		t_maze;

typedef struct		s_survival_level
{
  int			level;
  t_maze		*maze;
}			t_survival_level;

t_survival_level	*new_survival_level(int level);
void			delete_survival_level(t_survival_level *level);
int			render_survival_level(t_survival_level *level);

#endif /* !SURVIVAL_LEVEL_H_ */
