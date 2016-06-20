/*
** destroy.c for libmy in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Fri May  1 19:24:39 2015 Louis Person
** Last update Sat May  2 16:25:38 2015 Brendan Rius
*/

#include <stdlib.h>
#include <assert.h>
#include "str.h"

int	string_destroy(struct s_string *string)
{
  assert(string != NULL);
  free(string->_string);
  return (0);
}
