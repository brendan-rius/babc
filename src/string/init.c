/*
** init.c for libmy in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Fri May  1 19:14:59 2015 Louis Person
** Last update Sat May  2 08:47:11 2015 Louis Person
*/

#include <sys/types.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "str.h"
#include "my.h"

int	string_init(struct s_string *string)
{
  return (string_init_from_nbytes(string, "", STR_DEFAULT_SIZE));
}

int	string_init_from_bytes(struct s_string *string, const char *bytes)
{
  assert(bytes != NULL);
  return (string_init_from_nbytes(string, bytes, strlen(bytes)));
}

int	string_init_from_nbytes(struct s_string *string,
				const char *bytes,
				size_t n)
{
  assert(bytes != NULL);
  assert(string != NULL);
  string->_capacity = n;
  string->len = MIN(strlen(bytes), n);
  string->_string = malloc(n + 1);
  if (string->_string == NULL)
    return (-1);
  memcpy(string->_string, bytes, string->len);
  string->_string[string->len] = '\0';
  return (0);
}
