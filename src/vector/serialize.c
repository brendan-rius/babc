/*
** serialize.c for libmy in /home/person_l/rendu/42sh
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Tue May  5 12:58:49 2015 Louis Person
** Last update Sat May 23 02:23:26 2015 Brendan Rius
*/

#include <stdlib.h>
#include <sys/types.h>
#include "vector.h"

void			**vec_serialize(struct s_vec *vec)
{
  void			**serialized;
  struct s_iterator	iter;
  size_t		i;
  void			*e;

  iter = vec_iterator(vec);
  i = 0;
  serialized = malloc(sizeof(void *) * (vec->size + 1));
  if (serialized == NULL)
    return (NULL);
  FOREACH(e IN &iter)
    {
      serialized[i] = e;
      i++;
    }
  serialized[i] = NULL;
  return (serialized);
}
