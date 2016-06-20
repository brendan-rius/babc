/*
** llist_search.c for llist in /home/brendan/hashtables
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Fri Nov 21 20:24:03 2014 Brendan Rius
** Last update Fri Nov 21 20:24:03 2014 Brendan Rius
*/

#include <stdlib.h>
#include "llist.h"

void		*llist_search(t_llist *list, void *data, int (*cmp)())
{
  t_llist_e	*current;

  if (!list)
    return (NULL);
  current = list->front;
  while (current)
    {
      if ((*cmp)(current->data, data) == 0)
	return (current->data);
      current = current->next;
    }
  return (NULL);
}
