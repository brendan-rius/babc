/*
** ht_dict_set.c for hashtable in /home/brendan/dictionnaries
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Thu Jan 22 14:35:05 2015 Brendan Rius
** Last update Sun Feb  1 15:12:47 2015 Brendan Rius
*/

#include <stdlib.h>
#include "my.h"
#include "hashtable.h"

static int	ht_create_bucket(t_dict *dict, t_htable *table, int index)
{
  table->buckets[index] = dict_new(llist_get_dict(),
				   dict->free_value,
				   dict->free_key,
				   dict->compare_keys);
  if (table->buckets[index] == NULL)
    return (1);
  ARR_PUSH(table->taken_buckets_id, index, table->nb_taken_id);
  return (0);
}

int		ht_dict_set(t_dict *dict, void *key, void *value)
{
  t_htable	*table;
  unsigned int	hash;
  int		error;
  unsigned int	oldsize;
  unsigned int	size;

  table = (t_htable *) dict->interface->structure;
  hash = ht_hash(table, key);
  if (table->buckets[hash] == NULL)
    if ((error = ht_create_bucket(dict, table, hash)) != 0)
      return (error);
  oldsize = dict_length(table->buckets[hash]);
  dict_set(table->buckets[hash], key, value);
  size = dict_length(table->buckets[hash]);
  if (size == oldsize + 1)
    ++table->size;
  return (0);
}
