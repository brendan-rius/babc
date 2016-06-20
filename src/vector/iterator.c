/*
** iterator.c for 42sh in /home/brendan/rendu/42sh/lib/my
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Tue Apr 28 12:10:39 2015 Brendan Rius
** Last update Mon May 11 15:15:26 2015 Louis Person
*/

#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include "my.h"

static bool	vec_iterator_has_next(struct s_iterator *i)
{
  struct s_vec	*vec;

  vec = (struct s_vec *) i->holder;
  return ((size_t) i->index < vec->size);
}

static void	*vec_iterator_next(struct s_iterator *i)
{
  struct s_vec	*vec;
  void		*data;

  vec = (struct s_vec *) i->holder;
  data = vec->_data[(size_t) i->index];
  i->index = (void *) ((char *) i->index + 1);
  return (data);
}

static void	*vec_iterator_peek(struct s_iterator *i)
{
  struct s_vec	*vec;

  vec = (struct s_vec *) i->holder;
  return (vec->_data[(size_t) i->index]);
}

struct s_iterator	vec_iterator(struct s_vec *vec)
{
  struct s_iterator	i;

  assert(vec != NULL);
  i.has_next = &vec_iterator_has_next;
  i.next = &vec_iterator_next;
  i.peek = &vec_iterator_peek;
  i.index = (void *) 0;
  i.holder = vec;
  return (i);
}
