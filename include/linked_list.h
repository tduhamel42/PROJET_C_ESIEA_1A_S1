/**
 * File              : include/linked_list.h
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 19.12.2018
 * Last Modified Date: 08.01.2019
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

int			llist_push(t_llist **list, void *data);
void			llist_go_first(t_llist **list);
void			llist_go_last(t_llist **list);
int			llist_is_empty(t_llist **list);
void			*llist_pop(t_llist **list);
int			llist_sort(t_llist **list, t_llist_func func);

#endif /* !LINKED_LIST_H_ */
