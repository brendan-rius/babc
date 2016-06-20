/*
** new.c for libmy in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Fri May  1 19:10:40 2015 Louis Person
** Last update Fri May  1 20:39:20 2015 Louis Person
*/

#include <assert.h>
#include <stdlib.h>
#include "str.h"

int	string_new(struct s_string **ptr)
{
  assert(ptr != NULL);
  *ptr = malloc(sizeof(struct s_string));
  if (*ptr == NULL)
    return (-1);
  return (0);
}
