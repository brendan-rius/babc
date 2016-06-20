/*
** ht_dict_remove.c for hashtable in /home/brendan/dictionnaries
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Thu Jan 22 14:40:57 2015 Brendan Rius
** Last update Sun Feb  1 15:19:04 2015 Brendan Rius
*/

#include <stdlib.h>
#include "my.h"
#include "hashtable.h"

int		ht_dict_remove(t_dict *dict, void *key)
{
  t_htable	*table;
  unsigned int	hash;
  unsigned int	oldsize;
  unsigned int	size;
  int		error;

  table = (t_htable *) dict->interface->structure;
  hash = ht_hash(table, key);
  oldsize = dict_length(table->buckets[hash]);
  error = dict_remove(table->buckets[hash], key);
  size = dict_length(table->buckets[hash]);
  if (error == 0 && size == oldsize - 1)
    --table->size;
  if (size == 0)
    --table->nb_taken_id;
  return (error);
}
