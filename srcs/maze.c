/**
 * File              : srcs/maze.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 17.12.2018
 * Last Modified Date: 26.12.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdlib.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <signal.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "draw_utils.h"
#include "main_menu_screen.h"
#include "maze_helper.h"
#include "maze.h"

int			term_width = 0;
int			term_height = 0;
struct termios		oldterm;

void			reset_term()
{
  tcsetattr(STDIN_FILENO, TCSANOW, &oldterm);
  set_cursor(VISIBLE);
  printf("Bye !\n");
}

t_maze			*new_maze()
{
  t_maze		*maze;
  struct winsize	w;
  struct termios	newterm;

  if ((maze = malloc(sizeof(t_maze))) == NULL)
    return (NULL);
  maze->running = 1;
  maze->use_generated = 0;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  set_cursor(INVISIBLE);
  term_width = w.ws_col;
  term_height = w.ws_row;
  load_maze(maze);

  tcgetattr(STDIN_FILENO, &oldterm);
  newterm = oldterm;
  newterm.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newterm);
  atexit(reset_term);

  if ((maze->current_screen = new_main_menu_screen()) == NULL)
    return (NULL);
  return (maze);
}

void			delete_maze(t_maze *maze)
{
  free(maze);
}

static char		key_pressed()
{
  int			oldfd;
  char			c, result = 0;

  oldfd = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl (STDIN_FILENO, F_SETFL, oldfd | O_NONBLOCK);
  c = getchar();
  fcntl (STDIN_FILENO, F_SETFL, oldfd);
  if (c != EOF) {ungetc(c, stdin); result = getchar();}
  return result;
}

int			run_maze(t_maze *maze)
{
  system("clear");
  while (maze->running)
    {
      maze->key = key_pressed();
      if (maze->key == 27 && key_pressed() == 0)
	maze->running = 0;
      if (maze->current_screen && maze->current_screen->update)
	maze->current_screen->update(maze);
      if (maze->current_screen && maze->current_screen->render)
	maze->current_screen->render(maze);
      usleep(1000);
    }
  return (0);
}
