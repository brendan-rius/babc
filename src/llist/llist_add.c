/*
** llist_add.c for llist in /home/brendan/hashtables
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Fri Nov 21 20:22:52 2014 Brendan Rius
** Last update Fri Nov 21 20:22:52 2014 Brendan Rius
*/

#include <stdlib.h>
#include "llist.h"

static t_llist_e	*create_elem(void *data,
				     t_llist_e *previous,
				     t_llist_e *next)
{
  t_llist_e		*elem;

  if ((elem = malloc(sizeof(t_llist_e))) == NULL)
    return (NULL);
  elem->next = next;
  elem->previous = previous;
  elem->data = data;
  if (next)
    next->previous = elem;
  if (previous)
    previous->next = elem;
  return (elem);
}

void		*llist_add(t_llist *list, void *data)
{
  t_llist_e	*new;

  if (!list)
    return (NULL);
  if (list->size == 0)
    {
      if (!(list->front = list->rear = create_elem(data, NULL, NULL)))
	return (NULL);
    }
  else
    {
      if (!(new = create_elem(data, list->rear, NULL)))
	return (NULL);
      list->rear = new;
    }
  list->size++;
  return (data);
}
