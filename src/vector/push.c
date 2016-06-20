/*
** push.c for 42sh in /home/brendan/rendu/42sh
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Tue Apr 28 11:35:21 2015 Brendan Rius
** Last update Fri May  1 19:58:16 2015 Brendan Rius
*/

#include <stdlib.h>
#include <assert.h>
#include "my.h"

int	vec_push(struct s_vec *vec, void *e)
{
  assert(vec != NULL);
  if (vec->size >= vec->_capacity)
    {
      void	*new_area;
      size_t	new_size;

      new_size = vec->_capacity * 2;
      new_area = realloc(vec->_data, sizeof(void *) * new_size);
      if (new_area == NULL)
	return (-1);
      vec->_data = new_area;
      vec->_capacity = new_size;
    }
  vec->_data[vec->size++] = e;
  return (0);
}
