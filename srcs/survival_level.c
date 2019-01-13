/**
 * File              : survival_level.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 29.12.2018
 * Last Modified Date: 13.01.2019
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdlib.h>
#include "maze.h"
#include "maze_helper.h"
#include "maze_generator.h"
#include "draw_utils.h"
#include "survival_level.h"

t_survival_level	*new_survival_level(int lvl)
{
  t_survival_level	*level;

  if ((level = malloc(sizeof(t_survival_level))) == NULL
      || (level->maze = malloc(sizeof(t_maze))) == NULL)
    return (NULL);
  level->level = lvl;
  level->maze->size.x = (((rand() % 10) + 4) * lvl) % (term_width - 90);
  if (level->maze->size.x % 2 != 0)
    level->maze->size.x++;
  level->maze->size.y = (rand() % ((term_height - 5) - 5)) + 5;
  if (level->maze->size.y % 2 != 0)
    level->maze->size.y++;
  if ((level->maze->data = generate_maze_depth_search_print(level->maze->size.x,
						      level->maze->size.y)) == NULL)
    return (NULL);
  level->maze->start.x = 1;
  level->maze->start.y = 1;
  level->maze->size.x++;
  level->maze->size.y++;
  level->maze->end.x = level->maze->size.x - 2;
  level->maze->end.y = level->maze->size.y - 2;
  level->maze->data[level->maze->end.y][level->maze->end.x] = 'e';
  return (level);
}

void			delete_survival_level(t_survival_level *level)
{
  free(level->maze);
  free (level);
}

int			render_survival_level(t_survival_level *level)
{
  pretty_maze_print(level->maze);
  return (0);
}
