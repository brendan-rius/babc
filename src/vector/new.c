/*
** vector.c for libmy in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Mon Apr 27 15:43:51 2015 Louis Person
** Last update Tue Apr 28 11:36:27 2015 Brendan Rius
*/

#include <stdlib.h>
#include <assert.h>
#include "my.h"

int	vec_new(struct s_vec **vec)
{
  assert(vec != NULL);
  *vec = malloc(sizeof(struct s_vec));
  if (*vec == NULL)
    return (-1);
  return (0);
}
