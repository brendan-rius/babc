/*
** map.c for libmy in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Tue Apr 28 14:10:48 2015 Louis Person
** Last update Tue Apr 28 14:29:17 2015 Louis Person
*/

#include <sys/types.h>
#include <assert.h>
#include <stdlib.h>
#include "vector.h"

struct s_vec	*vec_map(struct s_vec *vec, t_mapper_fct f)
{
  struct s_vec	*mapped;
  size_t	i;

  assert(vec != NULL);
  assert(f != NULL);
  if (vec_new(&mapped) == -1)
    return (NULL);
  if (vec_init(mapped, vec->size, vec->free_fct) == -1)
    return (NULL);
  i = 0;
  while (i < vec->size)
    {
      if (vec_push(mapped, f(vec->_data[i])) == -1)
	{
	  vec_destroy(mapped);
	  return (NULL);
	}
      i++;
    }
  return (mapped);
}
