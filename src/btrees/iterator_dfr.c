/*
** iterator_bfr.c for btrees in /home/brendan/rendu/42sh/src/parser
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Thu Apr 30 21:32:36 2015 Brendan Rius
** Last update Fri May 29 23:52:51 2015 Louis Person
*/

#include <assert.h>
#include <stdlib.h>
#include "btrees.h"
#include "my.h"

static bool		btree_iterator_has_next(struct s_iterator *i)
{
  return (i->index != NULL);
}

static void		*btree_iterator_next(struct s_iterator *i)
{
  struct s_btree	*t;
  void			*data;

  t = i->index;
  data = t->data;
  if (t->right != NULL)
    return (i->index = t->right, data);
  if (t->left != NULL)
    return (i->index = t->left, data);
  while (t->up != NULL)
    {
      if (t->up->left != NULL && t->up->left != t)
	return (i->index = t->up->left, data);
      t = t->up;
    }
  return (i->index = NULL, data);
}

static void		*btree_iterator_peek(struct s_iterator *i)
{
  struct s_btree	*t;

  t = i->holder;
  return (t->data);
}

struct s_iterator	btree_iterator_dfr(struct s_btree *tree)
{
  struct s_iterator	i;

  assert(tree != NULL);
  i.index = tree;
  i.holder = tree;
  i.next = &btree_iterator_next;
  i.has_next = &btree_iterator_has_next;
  i.peek = &btree_iterator_peek;
  return (i);
}
