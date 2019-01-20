/**
 * File              : linked_list.h
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 19.12.2018
 * Last Modified Date: 20.01.2019
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#ifndef LINKED_LIST_H_
# define LINKED_LIST_H_

typedef struct s_llist	t_llist;

typedef int		(*t_llist_func)(void *d1, void *d2);

typedef struct		s_llist
{
  void			*data;
  struct s_llist	*next;
  struct s_llist	*prev;
}			t_llist;

/*
** Adds an element to the linked list
*/
int			llist_push(t_llist **list, void *data);
/*
** Moves the pointer to the first element of the list
*/
void			llist_go_first(t_llist **list);
/*
** Moves the pointer to the last element of the list
*/
void			llist_go_last(t_llist **list);
/*
** Checks if the list is empty
*/
int			llist_is_empty(t_llist **list);
/*
** Removes and returns the last added elements of the list
*/
void			*llist_pop(t_llist **list);
/*
** Sorts the list using the given function
*/
int			llist_sort(t_llist **list, t_llist_func func);

#endif /* !LINKED_LIST_H_ */
