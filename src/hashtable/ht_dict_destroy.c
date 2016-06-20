/*
** ht_dict_destroy.c for hashtable in /home/brendan/dictionnaries
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Thu Jan 22 14:42:08 2015 Brendan Rius
** Last update Sun Feb  1 14:56:51 2015 Brendan Rius
*/

#include <stdlib.h>
#include "my.h"
#include "hashtable.h"

int		ht_dict_destroy(t_dict *dict)
{
  t_htable	*table;
  unsigned int	i;
  int		error;

  table = (t_htable *) dict->interface->structure;
  i = 0;
  while (i < table->capacity)
    {
      error = dict_destroy(table->buckets[i]);
      if (error != OK)
	return (error);
      ++i;
    }
  free(table->taken_buckets_id);
  free(table->buckets);
  free(table);
  return (OK);
}
