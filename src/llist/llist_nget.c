/*
** llist_nget.c for llist_nget in /home/brendan/rendu/PSU_2014_my_select
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Dec 22 15:32:17 2014 Brendan Rius
** Last update Sun Jan 11 15:00:59 2015 Brendan Rius
*/

#include <stdlib.h>
#include "my.h"

void		*llist_nget(t_llist *list, int n)
{
  t_llist_e	*e;
  int		i;

  if (!list)
    return (NULL);
  e = list->front;
  i = 0;
  while (e && i != n)
    {
      ++i;
      e = e->next;
    }
  if (e)
    return (e->data);
  else
    return (NULL);
}

t_llist_e	*llist_nget_record(t_llist *list, int n)
{
  t_llist_e	*e;
  int		i;

  if (!list)
    return (NULL);
  e = list->front;
  i = 0;
  while (e && i != n)
    {
      ++i;
      e = e->next;
    }
  if (e)
    return (e);
  else
    return (NULL);
}
