/*
** cat.c for libmy in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Fri May  1 19:34:13 2015 Louis Person
** Last update Sat May 23 01:16:24 2015 Louis Person
*/

#include <sys/types.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "str.h"

int	string_cat(struct s_string *str1, const struct s_string *str2)
{
  assert(str2 != NULL);
  return (string_ncat_str(str1, str2->_string, str2->len));
}

int	strint_ncat(struct s_string *str1,
		    const struct s_string *str2,
		    size_t n)
{
  assert(str2 != NULL);
  return (string_ncat_str(str1, str2->_string, n));
}

int	string_cat_str(struct s_string *string, const char *bytes)
{
  assert(bytes != NULL);
  return (string_ncat_str(string, bytes, strlen(bytes)));
}

int		string_ncat_str(struct s_string *string,
				const char *bytes,
				size_t n)
{
  size_t	capacity;
  char		*new_string;

  assert(string != NULL);
  assert(bytes != NULL);
  capacity = string->_capacity + n;
  new_string = realloc(string->_string, capacity + 1);
  if (new_string == NULL)
    return (-1);
  strncat(new_string, bytes, n);
  string->_string = new_string;
  string->len += n;
  string->_capacity = capacity;
  return (0);
}
