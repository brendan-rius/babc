/*
** iterator.c for btrees in /home/brendan/rendu/42sh
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Thu Apr 30 19:43:22 2015 Brendan Rius
** Last update Fri May 29 23:52:47 2015 Louis Person
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
  if (t->left != NULL)
    return (i->index = t->left, data);
  if (t->right != NULL)
    return (i->index = t->right, data);
  while (t->up != NULL)
    {
      if (t->up->right != NULL && t->up->right != t)
	return (i->index = t->up->right, data);
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

struct s_iterator	btree_iterator_dfl(struct s_btree *tree)
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
