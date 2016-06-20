/*
** ht_dict_get_entries.c for htable in /home/brendan/rendu/PSU_2014_minishell1/lib/my
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Sun Feb  1 11:46:18 2015 Brendan Rius
** Last update Sun Feb  1 15:38:01 2015 Brendan Rius
*/

#include <stdlib.h>
#include "my.h"

static void	bucket_to_entries(t_htable *table,
				  t_dict_entry **entries,
				  unsigned int bucket_id,
				  unsigned int *entries_size)
{
  unsigned int	i;
  unsigned int	bucket_size;
  t_dict_entry	**bucket_entries;
  t_dict	*bucket;

  bucket = table->buckets[bucket_id];
  bucket_size = dict_length(bucket);
  bucket_entries = dict_get_entries(bucket);
  if (bucket_entries == NULL)
    return;
  i = 0;
  while (i < bucket_size)
    {
      ARR_PUSH(entries, bucket_entries[i], *entries_size);
      ++i;
    }
  free(bucket_entries);
}

t_dict_entry	**ht_dict_get_entries(t_dict *dict)
{
  unsigned int	i;
  unsigned int	entries_size;
  t_dict_entry	**entries;
  t_htable	*table;

  table = (t_htable *) dict->interface->structure;
  entries = malloc(sizeof(*entries) * dict_length(dict));
  if (entries == NULL)
    return (NULL);
  entries_size = 0;
  i = 0;
  while (i < table->nb_taken_id)
    {
      bucket_to_entries(table, entries,
			table->taken_buckets_id[i], &entries_size);
      ++i;
    }
  return (entries);
}
