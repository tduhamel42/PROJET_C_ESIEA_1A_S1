/**
 * File              : include/ia_screen.h
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 19.12.2018
 * Last Modified Date: 03.01.2019
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#ifndef IA_SCREEN_H_
# define IA_SCREEN_H_

typedef struct s_screen	t_screen;
typedef struct s_entity	t_entity;

typedef struct		s_ia_screen_data
{
  t_entity		*ia;
}			t_ia_screen_data;

t_screen		*new_ia_screen();

#endif /* !IA_SCREEN_H_ */
