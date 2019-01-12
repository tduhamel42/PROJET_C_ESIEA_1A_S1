/**
 * File              : srcs/maze.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 17.12.2018
 * Last Modified Date: 12.01.2019
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

t_game			*new_game()
{
  t_game		*game;
  struct winsize	w;
  struct termios	newterm;

  if ((game = malloc(sizeof(t_game))) == NULL
      || (game->maze = malloc(sizeof(t_maze))) == NULL) 
    return (NULL);
  game->running = 1;
  game->error = 0;
  game->use_generated = 0;
  if (load_maze(game->maze))
    game->error = 1;

  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  set_cursor(INVISIBLE);
  term_width = w.ws_col;
  term_height = w.ws_row;

  tcgetattr(STDIN_FILENO, &oldterm);
  newterm = oldterm;
  newterm.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newterm);
  atexit(reset_term);

  if ((game->current_screen = new_main_menu_screen()) == NULL)
    return (NULL);
  return (game);
}

void			delete_game(t_game *game)
{
  delete_screen(game->current_screen);
  free(game);
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

int			run_game(t_game *game)
{
  if (game->error)
    return (EXIT_FAILURE);
  system("clear");
  while (game->running)
    {
      game->key = key_pressed();
      if (game->key == 127 || game->key == 8)
	game->key = '\b';
      if (game->key == 27 && key_pressed() == 0)
	game->running = 0;
      if (game->current_screen && game->current_screen->update)
	game->current_screen->update(game);
      if (game->current_screen && game->current_screen->render)
	game->current_screen->render(game);
      usleep(1000);
    }
  return (0);
}
