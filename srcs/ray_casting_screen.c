/**
 * File              : srcs/ray_casting_screen.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 07.01.2019
 * Last Modified Date: 12.01.2019
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

static int			check_pos(t_maze *maze, t_vector2f pos)
{
  if (pos.y < 1 || pos.x < 1)
    return (1);
  if (maze->data[(int) pos.y][(int) pos.x] == '#')
    return (1);
  return (0);
}

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
      if (check_pos(game->maze, data->player_pos))
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
      if (check_pos(game->maze, data->player_pos))
	{
	  data->player_pos.x += sinf(data->player_angle)
	    * SPEED * data->delta_time;
	  data->player_pos.y += cosf(data->player_angle)
	    * SPEED * data->delta_time;
	}
      break;
    case 'C':
      data->player_angle += (SPEED * 0.65) * data->delta_time;
      break;
    case 'D':
      data->player_angle -= (SPEED * 0.65) * data->delta_time;
      break;
    case 'e':
      data->epilepsy = data->epilepsy ? 0 : 1;
      break;
    } 
  game->maze->data[(int)data->player_pos.y][(int)data->player_pos.x] = 'p';
  if ((int) data->player_pos.x == game->maze->end.x
      && (int) data->player_pos.y == game->maze->end.y)
    {
      if (data->victory == 0)
	system("clear");
      data->victory = 1;
    }
  if (data->victory)
    {
      if (game->key == 'r')
	{
	  delete_ray_casting_screen(game->current_screen);
	  system("clear");
	  if ((game->current_screen = new_ray_casting_screen(game)) == NULL)
	    return (1);
	}
    }
  return (0);
}
static void		print_victory()
{
  int			color = (rand() % (FG_WHITE - FG_BLACK)) + FG_BLACK;

  color_printxy((term_width / 2) - 30,
		(term_height / 2) - 5,
		color,
		"██╗   ██╗██╗ ██████╗████████╗ ██████╗ ██████╗ ██╗   ██╗");
  color_printxy((term_width / 2) - 30,
		(term_height / 2) - 4,
		color,
		"██║   ██║██║██╔════╝╚══██╔══╝██╔═══██╗██╔══██╗╚██╗ ██╔╝");
  color_printxy((term_width / 2) - 30,
		(term_height / 2) - 3,
		color,
		"██║   ██║██║██║        ██║   ██║   ██║██████╔╝ ╚████╔╝ ");
  color_printxy((term_width / 2) - 30,
		(term_height / 2) - 2,
		color,
		"╚██╗ ██╔╝██║██║        ██║   ██║   ██║██╔══██╗  ╚██╔╝  ");
  color_printxy((term_width / 2) - 30,
		(term_height / 2) - 1,
		color,
		" ╚████╔╝ ██║╚██████╗   ██║   ╚██████╔╝██║  ██║   ██║   ");
  color_printxy((term_width / 2) - 30,
		(term_height / 2),
		color,
		"  ╚═══╝  ╚═╝ ╚═════╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝   ╚═╝   ");
    color_printxy((term_width / 2) - 15,
		(term_height / 2) + 2,
		FG_BLUE,
		"Press r to restart !");
  color_printxy((term_width / 2) - 15,
		(term_height / 2) + 3,
		FG_BLUE,
		"Press escape to quit !");
}

static int			sort(void *d1, void *d2)
{
  t_vector2f			*v1 = (t_vector2f *) d1;
  t_vector2f			*v2 = (t_vector2f *) d2;

  return (v1->x < v2->x);
}

static char			is_boundary(t_ray_casting_screen_data *data,
					    float test_x, float test_y,
					    float eye_x, float eye_y)
{
  t_llist *tmp = NULL;
  t_vector2f *tmp_vec;

  for (int tx = 0; tx < 2; tx++)
    {
      for (int ty = 0; ty < 2; ty++)
	{
	  float vx = (float) test_x + tx
	    - data->player_pos.x;
	  float vy = (float) test_y + ty
	    - data->player_pos.y;
	  float d = sqrt(vx * vx + vy * vy);
	  float dot = (eye_x * vx / d) + (eye_y * vy / d);
	  if ((tmp_vec = malloc(sizeof(t_vector2f))) == NULL)
	    return (EXIT_FAILURE);
	  tmp_vec->x = d;
	  tmp_vec->y = dot;
	  llist_push(&tmp, tmp_vec);
	}
    }
  llist_sort(&tmp, sort);

  tmp_vec = (t_vector2f *) tmp->data;
  if (acos(tmp_vec->y) < BOUND)
    return (1);
  tmp = tmp->next;
  tmp_vec = (t_vector2f *) tmp->data;
  if (acos(tmp_vec->y) < BOUND)
    return (1);
  tmp = tmp->next;
  tmp_vec = (t_vector2f *) tmp->data;
  if (acos(tmp_vec->y) < BOUND)
    return (1);
  return (0);
}

static void			print_wall(t_game *game,
					   t_ray_casting_screen_data *data,
					   int x,
					   float distance_to_wall,
					   char boundary,
					   char is_end)
{
  int ceiling = (float) (term_height / 2.0)
    - term_height / ((float) distance_to_wall);
  int floor = term_height - ceiling;

  for (int y = 0; y < term_height; y++)
    {
      if (y > game->maze->size.y + 1 || x > game->maze->size.x)
	{
	  int color;
	  if (data->epilepsy)
	    color= (rand() % (FG_WHITE - FG_BLACK)) + FG_BLACK;
	  else
	    color = data->wall_color;
	  if (y <= ceiling)
	    color_printxy(x, y, FG_WHITE, " ");
	  else if (y > ceiling && y < floor)
	    {
	      if (boundary == 1)
		color_printxy(x, y, FG_RED, "█");
	      else if (is_end == 1)
		{
		  color_printxy(x, y, FG_MAGENTA, "█");
		  is_end = 2;
		}
	      else if (is_end == 2)
		{
		  color_printxy(x, y, FG_YELLOW, "█");
		  is_end = 1;
		}
	      else if (distance_to_wall <= DEPTH / 4)
		color_printxy(x, y, color, "█");
	      else if (distance_to_wall < DEPTH / 3)
		color_printxy(x, y, color, "▓");
	      else if (distance_to_wall < DEPTH / 2)
		color_printxy(x, y, color, "▒");
	      else
		color_printxy(x, y, color, "░");
	    }
	  else
	    {
	      color_printxy(x, y, FG_CYAN, "█");
	    }
	}
    }	
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

      float step_size = 0.3f;
      float distance_to_wall = 0.0f;

      char hit_wall = 0;
      char boundary = 0;
      char is_end = 0;

      float eye_x = sinf(ray_angle);
      float eye_y = cosf(ray_angle);
      
      int test_x;
      int test_y;

      while (!hit_wall && distance_to_wall < DEPTH)
	{
	  distance_to_wall += step_size;
	  test_x = (int)(data->player_pos.x + eye_x * distance_to_wall);
	  test_y = (int)(data->player_pos.y + eye_y * distance_to_wall);

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
		  boundary = is_boundary(data, test_x, test_y, eye_x, eye_y);
		}
	      if (game->maze->data[test_y][test_x] == 'e')
		is_end = is_end == 1 ? 2 : 1;
	      else
		is_end = 0;
	    }
	}
      if (test_x % 2 == 0 && test_y % 2 == 0)
	data->wall_color = FG_BLACK;
      else
	data->wall_color = FG_WHITE;
      if (!data->victory)
	print_wall(game, data, x, distance_to_wall, boundary, is_end);
    }
  if (data->victory)
    print_victory();
  else
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
  data->epilepsy = 0;
  data->victory = 0;
  data->player_pos.x = 1;
  data->player_pos.y = 1;
  data->player_angle = 0.0;
  data->wall_color = FG_BLACK;
  data->start_time = clock();
  if (game->use_generated)
    {
      game->maze->size.x = game->maze->size.x * 2;
      game->maze->size.y = game->maze->size.y * 2;
      game->maze->data = generate_maze_depth_search(game->maze->size.x,
						    game->maze->size.y);
      game->maze->size.x++;
      game->maze->size.y++;
      game->maze->end.x = game->maze->size.x - 2;
      game->maze->end.y = game->maze->size.y - 2;
    }
  game->maze->data[game->maze->end.y][game->maze->end.x] = 'e';
  return (screen);
}

void				delete_ray_casting_screen(t_screen *screen)
{
  delete_screen(screen);
}
