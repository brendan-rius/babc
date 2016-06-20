/*
** llist_destroy.c for llist in /home/brendan/hashtables
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Fri Nov 21 20:20:12 2014 Brendan Rius
** Last update Fri Nov 21 20:20:12 2014 Brendan Rius
*/

#include <stdlib.h>
#include "llist.h"

void		llist_destroy(t_llist *list)
{
  t_llist_e	*current;
  t_llist_e	*next;

  if (!list)
    return;
  if (list->size == 0)
    {
      free(list);
      return;
    }
  current = list->front;
  while (current)
    {
      if (list->free_fct)
	list->free_fct(current->data);
      next = current->next;
      free(current);
      current = next;
    }
  free(list);
}
