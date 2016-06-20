/*
** llist_new.c for llist in /home/brendan/hashtables
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Fri Nov 21 20:19:32 2014 Brendan Rius
** Last update Sat May 23 20:02:38 2015 Brendan Rius
*/

#include <stdlib.h>
#include "llist.h"

t_llist		*llist_new(void (*free_fct)())
{
  t_llist	*list;

  if ((list = malloc(sizeof(struct s_llist))) == NULL)
    return (NULL);
  list->front = NULL;
  list->rear = NULL;
  list->free_fct = free_fct;
  list->size = 0;
  return (list);
}
