/*
** destroy.c for libmy in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Mon Apr 27 16:31:59 2015 Louis Person
** Last update Tue Apr 28 16:45:41 2015 Louis Person
*/

#include <assert.h>
#include <stdlib.h>
#include "vector.h"

int	vec_destroy(struct s_vec *vec)
{
  assert(vec != NULL);
  vec_empty(vec);
  free(vec->_data);
  return (0);
}
