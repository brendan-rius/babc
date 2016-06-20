/*
** foreach.c for libmy in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Tue Apr 28 14:38:58 2015 Louis Person
** Last update Tue Apr 28 14:41:32 2015 Louis Person
*/

#include <sys/types.h>
#include <assert.h>
#include <stdlib.h>
#include "vector.h"

int		vec_foreach(struct s_vec *vec, t_consumer_fct f)
{
  size_t	i;

  assert(vec != NULL);
  assert(f != NULL);
  i = 0;
  while (i < vec->size)
    {
      f(vec->_data[i]);
      i++;
    }
  return (0);
}
