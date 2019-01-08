/**
 * File              : include/ray_casting_screen.h
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 07.01.2019
 * Last Modified Date: 08.01.2019
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#ifndef RAY_CASTING_SCREEN_H_
# define RAY_CASTING_SCREEN_H_

#include "vector2.h"

typedef struct s_game		t_game;
typedef struct s_screen		t_screen;
typedef struct s_entity		t_entity;

# define FOV (3.14156f / 4.0f)
# define DEPTH (16.0f)
# define BOUND 0.005f
# define SPEED 0.5f

typedef struct			s_ray_casting_screen_data
{
  t_vector2f			player_pos;
  int				epilepsy;
  char				victory;
  float				player_angle;
  long				delta_time;
  long				start_time;
  long				end_time;
}				t_ray_casting_screen_data;

t_screen			*new_ray_casting_screen(t_game *game);
void				delete_ray_casting_screen(t_screen *screen);

#endif /* RAY_CASTING_SCREEN_H_ */
