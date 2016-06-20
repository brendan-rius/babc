/*
** dictionnary.c for dictionnary in /home/brendan/dictionnaries
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Wed Jan 21 15:25:51 2015 Brendan Rius
** Last update Sun Feb  1 12:24:33 2015 Brendan Rius
*/

#include <stdlib.h>
#include "dictionnary.h"

t_dict		*dict_new(t_dict_interface *interface,
			  void (*free_value)(),
			  void (*free_key)(),
			  int (*compare_keys)())
{
  t_dict	*dict;

  dict = malloc(sizeof(*dict));
  if (dict == NULL || interface == NULL || compare_keys == NULL)
    return (NULL);
  if (interface->set == NULL || interface->get == NULL ||
      interface->remove == NULL || interface->destroy == NULL ||
      interface->get_entries == NULL || interface->length == NULL)
    return (NULL);
  dict->interface = interface;
  dict->size = 0;
  dict->free_value = free_value;
  dict->free_key = free_key;
  dict->compare_keys = compare_keys;
  return (dict);
}

int	dict_destroy(t_dict *dict)
{
  int	error;

  if (dict == NULL)
    return (DICT_ERR_NULL_DICT);
  error = dict->interface->destroy(dict);
  if (error != OK)
    return (error);
  free(dict->interface);
  free(dict);
  return (OK);
}

int	dict_set(t_dict *dict, void *key, void *value)
{
  if (dict == NULL)
    return (DICT_ERR_NULL_DICT);
  if (key == NULL)
    return (DICT_ERR_NULL_KEY);
  if (value == NULL)
    return (DICT_ERR_NULL_VALUE);
  return (dict->interface->set(dict, key, value));
}

int	dict_remove(t_dict *dict, void *key)
{
  if (dict == NULL)
    return (DICT_ERR_NULL_DICT);
  if (key == NULL)
    return (DICT_ERR_NULL_KEY);
  return (dict->interface->remove(dict, key));
}

void	*dict_get(t_dict *dict, void *key)
{
  if (dict == NULL)
    return (NULL);
  if (key == NULL)
    return (NULL);
  return (dict->interface->get(dict, key));
}
