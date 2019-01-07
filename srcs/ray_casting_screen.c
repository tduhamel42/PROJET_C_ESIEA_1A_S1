/**
 * File              : srcs/ray_casting_screen.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 07.01.2019
 * Last Modified Date: 07.01.2019
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "maze.h"
#include "maze_generator.h"
#include "draw_utils.h"
#include "screen.h"
#include "entity.h"
#include "maze_helper.h"
#include "ray_casting_screen.h"

static int			update(t_game *game)
{
  t_ray_casting_screen_data	*data =
    (t_ray_casting_screen_data *) game->current_screen->data;

  game->maze->data[(int)data->player_pos.y][(int)data->player_pos.x] = ' ';
  switch (game->key)
    {
    case 'A':
      data->player_pos.x += sinf(data->player_angle)
	* SPEED * data->delta_time;
      data->player_pos.y += cosf(data->player_angle)
	* SPEED * data->delta_time;
      if ((data->player_pos.x > game->maze->size.x || data->player_pos.y > game->maze->size.y)
	&& game->maze->data[(int)data->player_pos.y][(int)data->player_pos.x] != '#')
	{
	  data->player_pos.x -= sinf(data->player_angle)
	    * SPEED * data->delta_time;
	  data->player_pos.y -= cosf(data->player_angle)
	    * SPEED * data->delta_time;
	}
      break;
    case 'B':
      data->player_pos.x -= sinf(data->player_angle)
	* SPEED * data->delta_time;
      data->player_pos.y -= cosf(data->player_angle)
	* SPEED * data->delta_time;
      if ((data->player_pos.x < 0 || data->player_pos.y < 0)
	  && game->maze->data[(int)data->player_pos.y][(int)data->player_pos.x] != '#')
	{
	  data->player_pos.x += sinf(data->player_angle)
	    * SPEED * data->delta_time;
	  data->player_pos.y += cosf(data->player_angle)
	    * SPEED * data->delta_time;
	}
      break;
    case 'C':
      data->player_angle += (SPEED * 0.75) * data->delta_time;
      break;
    case 'D':
      data->player_angle -= (SPEED * 0.75) * data->delta_time;
      break;
    } 
  game->maze->data[(int)data->player_pos.y][(int)data->player_pos.x] = 'p';
  return (0);
}

static int			render(t_game *game)
{
  t_ray_casting_screen_data	*data =
    (t_ray_casting_screen_data *) game->current_screen->data;

  data->end_time = clock();
  data->delta_time = (data->end_time - data->start_time)
    / CLOCKS_PER_SEC * 1000;
  data->delta_time += 1;
  data->start_time = data->end_time;
  for (int x = 0; x < term_width; x++)
    {
      float ray_angle = (data->player_angle - FOV / 2) +
	((float) x /  (float) term_width) * FOV;

      float step_size = 0.1f;
      float distance_to_wall = 0.0f;

      char hit_wall = 0;
      char boundary = 0;

      float eye_x = sinf(ray_angle);
      float eye_y = cosf(ray_angle);

      while (!hit_wall && distance_to_wall < DEPTH)
	{
	  distance_to_wall += step_size;
	  int test_x = (int)(data->player_pos.x + eye_x * distance_to_wall);
	  int test_y = (int)(data->player_pos.y + eye_y * distance_to_wall);

	  if (test_y < 0 || test_x >= game->maze->size.x
	      || test_y < 0 || test_y >= game->maze->size.y)
	    {
	      hit_wall = 1;
	      distance_to_wall = DEPTH;
	    }
	  else
	    {
	      if (game->maze->data[test_y][test_x] == '#')
		{
		  hit_wall = 1;

		  t_vector2f tab[5];
		  int i = 0;
		  for (int tx = 0; tx < 2; tx++)
		    {
		      for (int ty = 0; ty < 2; ty++)
			{
			  float vx = (float) test_x + tx
			    - data->player_pos.x;
			  float vy = (float) test_y + ty
			    - data->player_pos.y;
			  tab[i].x = sqrt(vx * vx + vy * vy);
			  tab[i].y = (eye_x * vx / tab[i].x)
			    + (eye_y * vy / tab[i].x);
			  ++i;
			}
		    }
		}
	    }
	}

      int ceiling = (float) (term_height / 2.0)
	- term_height / ((float) distance_to_wall);
      int floor = term_height - ceiling;

      for (int y = 0; y < term_height; y++)
	{
	  if (y > game->maze->size.y + 1 || x > game->maze->size.x)
	    {
	      if (y <= ceiling)
		color_printxy(x, y, FG_WHITE, " ");
	      else if (y > ceiling && y < floor)
		{
		  if (boundary == 1)
		    color_printxy(x, y, FG_WHITE, " ");
		  else if (distance_to_wall <= DEPTH / 4)
		    color_printxy(x, y, FG_WHITE, "█");
		  else if (distance_to_wall < DEPTH / 3)
		    color_printxy(x, y, FG_WHITE, "▓");
		  else if (distance_to_wall < DEPTH / 2)
		    color_printxy(x, y, FG_WHITE, "▒");
		  else
		    color_printxy(x, y, FG_WHITE, "░");
		}
	      else
		{
		  if (boundary == 1)
		    color_printxy(x, y, FG_CYAN, " ");
		  else
		    color_printxy(x, y, FG_CYAN, "█");
		}
	    }
	}	
    }
  normal_maze_print(game->maze);
  return (0);
}

t_screen			*new_ray_casting_screen(t_game *game)
{
  t_screen			*screen;
  t_ray_casting_screen_data	*data;

  if ((screen = new_screen()) == NULL)
    return (NULL);
  screen->render = render;
  screen->update = update;
  if ((screen->data = malloc(sizeof(t_ray_casting_screen_data))) == NULL)
    return (NULL);
  data = (t_ray_casting_screen_data *) screen->data;
  data->player_pos.x = 1;
  data->player_pos.y = 1;
  data->player_angle = 0.0;
  data->start_time = clock();
  if (game->use_generated)
    {
      game->maze->size.x = game->maze->size.x * 2;
      game->maze->size.y = game->maze->size.y * 2;
      game->maze->data = generate_maze_depth_search(game->maze->size.x,
						    game->maze->size.y);
      game->maze->size.x++;
      game->maze->size.y++;
    }
  return (screen);
}

void				delete_ray_casting_screen(t_screen *screen)
{
  delete_screen(screen);
}
