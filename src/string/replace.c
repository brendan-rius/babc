/*
** replace.c for libmy in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Fri May  1 20:39:31 2015 Louis Person
** Last update Sat May  2 16:25:00 2015 Brendan Rius
*/

#include <stddef.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "str.h"

int	string_replace(struct s_string *string,
		       const struct s_string *pattern,
		       const struct s_string *filler)
{
  assert(pattern != NULL);
  assert(filler != NULL);
  return (string_replace_str(string, pattern->_string, filler->_string));
}

int			string_replace_str(struct s_string *string,
					   const char *pattern,
					   const char *filler)
{
  struct s_string	final;
  size_t		i;
  size_t		plen;

  if (string_init(&final) == -1)
    return (-1);
  i = 0;
  plen = strlen(pattern);
  while (i < string->len)
    {
      if (strncmp(string->_string + i, pattern, plen) == 0)
	{
	  if (string_cat_str(&final, filler) == -1)
	    return (-1);
	  i += plen;
	}
      else
	{
	  if (string_push(&final, string->_string[i]) == -1)
	    return (-1);
	  ++i;
	}
    }
  memcpy(string, &final, sizeof(struct s_string));
  return (0);
}
