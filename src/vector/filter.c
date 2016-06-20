/*
** filter.c for libmy in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Tue Apr 28 14:22:12 2015 Louis Person
** Last update Tue Apr 28 12:32:19 2015 Brendan Rius
*/

#include <sys/types.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include "vector.h"

struct s_vec	*vec_filter(struct s_vec *vec, t_filterer_fct f)
{
  struct s_vec	*filtered;
  size_t	i;

  assert(vec != NULL);
  assert(f != NULL);
  if (vec_new(&filtered) == -1)
    return (NULL);
  if (vec_init(filtered, vec->size, vec->free_fct) == -1)
    return (NULL);
  i = 0;
  while (i < vec->size)
    {
      if (f(vec->_data[i]) == true)
	if (vec_push(filtered, vec->_data[i]) == -1)
	  {
	    vec_destroy(filtered);
	    return (NULL);
	  }
      i++;
    }
  return (filtered);
}
