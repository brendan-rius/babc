/*
** llist_apply.c for llist_apply in /home/brendan/rendu/PSU_2014_my_select
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Dec 22 20:35:41 2014 Brendan Rius
** Last update Mon Dec 22 20:35:41 2014 Brendan Rius
*/

#include "my.h"

void		llist_apply(t_llist *list, void (*payload)())
{
  t_llist_e	*e;

  if (!list || !payload)
    return;
  e = list->front;
  while (e)
    {
      (*payload)(e->data);
      e = e->next;
    }
}
