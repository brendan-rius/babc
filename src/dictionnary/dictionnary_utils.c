/*
** dictionnary_utils.c for dictionnary in /home/brendan/dictionnaries
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Wed Jan 21 18:15:46 2015 Brendan Rius
** Last update Wed Jan 21 19:46:55 2015 Brendan Rius
*/

#include <stdlib.h>
#include "dictionnary.h"

int	dict_compare_entries(t_dict *dict, t_dict_entry *e1, t_dict_entry *e2)
{
  if (dict == NULL)
    return (DICT_ERR_NULL_DICT);
  if (e1 == NULL || e2 == NULL)
    return (DICT_ERR_NULL_ENTRY);
  if (dict->compare_keys(e1->key, e2->key) == 0)
    return (OK);
  return (NOK);
}

int	dict_compare_entry(t_dict *dict, t_dict_entry *e, void *key)
{
  if (dict == NULL)
    return (DICT_ERR_NULL_DICT);
  if (e == NULL || key == NULL)
    return (DICT_ERR_NULL_ENTRY);
  if (dict->compare_keys(e->key, key) == 0)
    return (OK);
  return (NOK);
}

void	dict_free_entry(t_dict_entry *entry)
{
  if (entry == NULL)
    return;
  if (entry->free_value != NULL)
    entry->free_value(entry->value);
  if (entry->free_key != NULL)
    entry->free_key(entry->key);
  free(entry);
}

t_dict_entry	*dict_new_entry(t_dict *dict, void *key, void *value)
{
  t_dict_entry	*entry;

  if (key == NULL || value == NULL)
    return (NULL);
  entry = malloc(sizeof(*entry));
  if (entry == NULL)
    return (NULL);
  entry->key = key;
  entry->value = value;
  entry->free_value = dict->free_value;
  entry->free_key = dict->free_key;
  return (entry);
}
