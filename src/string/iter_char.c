/*
** iter_char.c for libmy in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Mon May 11 15:10:52 2015 Louis Person
** Last update Mon May 11 15:41:37 2015 Louis Person
*/

#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include "my.h"

static bool		string_iter_char_has_next(struct s_iterator *i)
{
  struct s_string	*string;

  string  = (struct s_string *) i->holder;
  return ((size_t) i->index < string->len);
}

static void		*string_iter_char_next(struct s_iterator *i)
{
  struct s_string	*string;
  char			data;

  string = (struct s_string *) i->holder;
  data = string->_string[(size_t) i->index];
  i->index = (void *) ((char *) i->index + 1);
  return (data);
}

static void		*string_iter_char_peek(struct s_iterator *i)
{
  struct s_string	*string;

  string = (struct s_string *) i->holder;
  return (string->_string[(size_t) i->index]);
}

struct s_iterator	string_iter_char(struct s_string *string)
{
  struct s_iterator	i;

  assert(string != NULL);
  i.has_next = &string_iter_char_has_next;
  i.next = &string_iter_char_next;
  i.peek = &string_iter_char_peek;
  i.index = (void *) 0;
  i.holder = string;
  return (i);
}
