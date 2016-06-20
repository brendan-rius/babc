/*
** ht_hash.c for hashtable in /home/brendan/dictionnaries
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Thu Jan 22 14:36:45 2015 Brendan Rius
** Last update Thu Jan 22 14:37:43 2015 Brendan Rius
*/

#include <stdlib.h>
#include "hashtable.h"

unsigned int	ht_hash(t_htable *table, void *key)
{
  if (table == NULL)
    return (0);
  return (table->hash(key) % table->capacity);
}
