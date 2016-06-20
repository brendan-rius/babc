/*
** from.c for libmy in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Mon Apr 27 16:30:36 2015 Louis Person
** Last update Tue Apr 28 12:06:03 2015 Brendan Rius
*/

#include <sys/types.h>
#include <assert.h>
#include <stdlib.h>
#include "vector.h"

int		vec_from(struct s_vec *vec,
			 void **source,
			 size_t capacity,
			 void (*free_fct)())
{
  size_t	i;

  assert(source != NULL);
  assert(vec != NULL);
  if (capacity == 0)
    {
      i = 0;
      while (source[i] != NULL)
	i++;
    }
  vec_init(vec, capacity, free_fct);
  i = 0;
  while (i < capacity)
    {
      if (vec_push(vec, source[i]) == -1)
	{
	  vec_destroy(vec);
	  return (-1);
	}
      i++;
    }
  return (0);
}
