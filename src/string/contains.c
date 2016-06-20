/*
** contains.c for libmy in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Fri May  1 20:08:43 2015 Louis Person
** Last update Fri May  1 21:44:45 2015 Louis Person
*/

#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include "str.h"

bool	string_contains(const struct s_string *haystack,
			const struct s_string *needle)
{
  assert(haystack != NULL);
  assert(needle != NULL);
  return (string_contains_str(haystack, needle->_string));
}

bool	string_contains_str(const struct s_string *haystack,
			    const char *needle)
{
  assert(haystack != NULL);
  assert(needle != NULL);
  return (strstr(haystack->_string, needle) != NULL);
}
