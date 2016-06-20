/*
** llist_replace.c for llist in /home/brendan/hashtables/lib/my/llist
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Sat Nov 22 11:01:40 2014 Brendan Rius
** Last update Sat Nov 22 11:01:40 2014 Brendan Rius
*/

#include <stdlib.h>
#include "llist.h"

void		*llist_replace(t_llist *list,
			       void *data,
			       void *new,
			       int (*cmp)())
{
  t_llist_e	*current;

  if (!list)
    return (NULL);
  current = list->front;
  while (current)
    {
      if ((*cmp)(current->data, data) == 0)
	{
	  if (list->free_fct)
	    (*(list->free_fct))(current->data);
	  current->data = new;
	  return (current->data);
	}
      current = current->next;
    }
  return (NULL);
}
