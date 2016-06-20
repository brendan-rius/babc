/*
** delete.c for libmy in /home/person_l/rendu/42sh/tests/interpreter
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Tue May  5 16:25:13 2015 Louis Person
** Last update Tue May  5 16:38:18 2015 Louis Person
*/

#include <assert.h>
#include <stdlib.h>
#include "str.h"

void	string_delete(struct s_string *string)
{
  assert(string != NULL);
  string_destroy(string);
  free(string);
}
