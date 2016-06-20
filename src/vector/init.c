/*
** init.c for libmy in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Mon Apr 27 16:29:16 2015 Louis Person
** Last update Tue Apr 28 14:52:27 2015 Brendan Rius
*/

#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include "vector.h"

int	vec_init(struct s_vec *vec, size_t capacity, void (*free_fct)())
{
  assert(vec != NULL);
  if (capacity == 0)
    capacity = VEC_DEFAULT_SIZE;
  vec->_data = malloc(sizeof(void *) * capacity);
  if (vec->_data == NULL)
    return (-1);
  vec->size = 0;
  vec->_capacity = capacity;
  vec->free_fct = free_fct;
  return (0);
}
