/*
** ht_dict_get.c for hastable in /home/brendan/dictionnaries
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Thu Jan 22 14:49:45 2015 Brendan Rius
** Last update Thu Jan 22 14:51:46 2015 Brendan Rius
*/

#include <stdlib.h>
#include "my.h"
#include "hashtable.h"

void		*ht_dict_get(t_dict *dict, void *key)
{
  t_htable	*table;
  unsigned int	hash;

  table = (t_htable *) dict->interface->structure;
  hash = ht_hash(table, key);
  if (table->buckets[hash] == NULL)
    return (NULL);
  return (dict_get(table->buckets[hash], key));
}
