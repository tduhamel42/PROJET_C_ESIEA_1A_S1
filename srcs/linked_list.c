/**
 * File              : srcs/linked_list.c
 * Author            : Tanguy Duhamel <tanguydu@gmail.com>
 * Date              : 19.12.2018
 * Last Modified Date: 19.12.2018
 * Last Modified By  : Tanguy Duhamel <tanguydu@gmail.com>
 */

#include <stdlib.h>
#include "linked_list.h"

int		llist_push(t_llist **list, void *data)
{
  t_llist	*nelem;

  if ((nelem = malloc(sizeof(t_llist))) == NULL)
    return (0);
  nelem = data;
  nelem->next = NULL;
  nelem->prev = (*list);
  if ((*list))
    (*list)->next = nelem;
  (*list) = nelem;
  return (0);
}

void		llist_go_first(t_llist **list)
{
  if ((*list))
    while ((*list)->prev)
      (*list) = (*list)->prev;
}

void		llist_go_last(t_llist **list)
{
  if ((*list))
    while ((*list)->next)
      (*list) = (*list)->next;
}

int		is_empty(t_llist **list)
{
  return (*list == NULL);
}

void		*pop(t_llist **list)
{
  void		*data = NULL;
  t_llist	*elem;

  if (!(*list))
    return (NULL);
  llist_go_last(list);
  data = (*list)->data;
  elem = *list;
  if ((*list)->prev)
    (*list)->prev->next = NULL;
  *list = elem->prev;
  free(elem);
  return (data);
}
