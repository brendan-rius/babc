/*
** split.c for libmy in /home/person_l/rendu/42sh
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Tue May  5 15:15:03 2015 Louis Person
** Last update Fri May 29 23:53:00 2015 Louis Person
*/

#define _BSD_SOURCE
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "str.h"
#include "vector.h"

static int		push_to_vec(struct s_vec *vec, char *str)
{
  struct s_string	*string;

  if (str[0] == '\0')
    return (0);
  if (string_new(&string) == -1)
    return (-1);
  if (string_init_from_bytes(string, str) == -1)
    return (free(string), -1);
  if (vec_push(vec, string) == -1)
      return (string_delete(string), -1);
  return (0);
}

int	string_split(const struct s_string *string,
		     const struct s_string *pattern,
		     struct s_vec *matches)
{
  assert(pattern != NULL);
  return (string_split_str(string, pattern->_string, matches));
}

int	string_split_str(const struct s_string *string,
			 const char *pattern,
			 struct s_vec *matches)
{
  char	*copy;
  char	*token;

  assert(string != NULL);
  assert(pattern != NULL);
  assert(matches != NULL);
  copy = string->_string;
  token = strsep(&copy, pattern);
  if (vec_init(matches, 0, &string_delete) == -1)
    return (-1);
  while (copy != NULL)
    {
      if (push_to_vec(matches, token) == -1)
	return (vec_empty(matches), -1);
      token = strsep(&copy, pattern);
    }
  if (push_to_vec(matches, token) == -1)
    return (vec_empty(matches), -1);
  return (0);
}
