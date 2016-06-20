/*
** ht_new.c for hashtable in /home/brendan/dictionnaries
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Thu Jan 22 14:26:29 2015 Brendan Rius
** Last update Sun Feb  1 15:03:59 2015 Brendan Rius
*/

#include <stdlib.h>
#include "my.h"

int	init_buckets_id(t_htable *table)
{
  table->taken_buckets_id =
    malloc(sizeof(*(table->taken_buckets_id)) * table->capacity);
  if (table->taken_buckets_id == NULL)
    return (1);
  table->nb_taken_id = 0;
  return (0);
}

static void	init_buckets(t_htable *table)
{
  unsigned int	i;

  i = 0;
  while (i < table->capacity)
    {
      table->buckets[i] = NULL;
      ++i;
    }
}

t_htable	*ht_new(unsigned int capacity,
			unsigned int (*hash)())
{
  t_htable	*table;

  table = malloc(sizeof(*table));
  if (table == NULL || hash == NULL || capacity == 0)
    return (NULL);
  table->capacity = capacity;
  table->size = 0;
  table->hash = hash;
  table->buckets = malloc(sizeof(*(table->buckets)) * capacity);
  if (table->buckets == NULL || init_buckets_id(table) != 0)
    {
      free(table);
      return (NULL);
    }
  init_buckets(table);
  return (table);
}
