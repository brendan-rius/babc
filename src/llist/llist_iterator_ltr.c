/*
** llist_iterator_ltr.c for llist in /home/brendan/rendu/42sh
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Thu Apr 30 21:39:43 2015 Brendan Rius
** Last update Thu Apr 30 21:43:17 2015 Brendan Rius
*/

#include <assert.h>
#include <stdlib.h>
#include "llist.h"
#include "my.h"

static bool	llist_iterator_has_next(struct s_iterator *i)
{
  return (i->index != NULL);
}

static void		*llist_iterator_next(struct s_iterator *i)
{
  struct s_llist_e	*e;

  e = i->index;
  i->index = e->next;
  return (e->data);
}

static void		*llist_iterator_peek(struct s_iterator *i)
{
  struct s_llist_e	*e;

  e = i->index;
  return (e->data);
}

struct s_iterator	llist_iterator_ltr(struct s_llist *list)
{
  struct s_iterator	i;

  assert(list != NULL);
  i.index = list->front;
  i.holder = list;
  i.next = &llist_iterator_next;
  i.has_next = &llist_iterator_has_next;
  i.peek = &llist_iterator_peek;
  return (i);
}
