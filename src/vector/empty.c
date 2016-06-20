/*
** empty.c for libmy in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Mon Apr 27 16:31:29 2015 Louis Person
** Last update Sat May 23 23:58:30 2015 Adrien Paris
*/

#include <sys/types.h>
#include <assert.h>
#include <stdlib.h>
#include "vector.h"

int		vec_empty(struct s_vec *vec)
{
  size_t	i;

  assert(vec != NULL);
  i = 0;
  while (i < vec->size)
    {
      if (vec->free_fct != NULL)
	vec->free_fct(vec->_data[i]);
      i++;
    }
  vec->size = 0;
  return (0);
}
