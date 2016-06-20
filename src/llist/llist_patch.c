/*
** llist_patch.c for llist in /home/brendan/rendu/42sh/src/regex
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Sat Apr 25 17:46:49 2015 Brendan Rius
** Last update Sat Apr 25 17:52:55 2015 Brendan Rius
*/

#include <stdlib.h>
#include "my.h"

t_llist		*llist_patch(t_llist *l1, t_llist *l2)
{
  t_llist	*new;
  t_llist_e	*e;

  if (l1->size == 0)
    return (l2);
  if (l2->size == 0)
    return (l1);
  new = malloc(sizeof(*new));
  if (new == NULL)
    return (NULL);
  e = l1->front;
  while (e != NULL)
    e = e->next;
  e->next = l2->front;
  new->front = l1->front;
  new->size = l1->size + l2->size;
  new->rear = l2->rear;
  new->free_fct = l1->free_fct;
  return (new);
}
