/*
** hashtable.c for hashtable in /home/brendan/dictionnaries
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Thu Jan 22 14:23:14 2015 Brendan Rius
** Last update Sun Feb  1 12:22:30 2015 Brendan Rius
*/

#include <stdlib.h>
#include "hashtable.h"
#include "my.h"

t_dict_interface	*ht_get_dict(unsigned int size,
				     unsigned int (*hash)())
{
  t_dict_interface	*interface;

  interface = malloc(sizeof(*interface));
  if (interface == NULL)
    return (NULL);
  interface->set = &ht_dict_set;
  interface->get = &ht_dict_get;
  interface->remove = &ht_dict_remove;
  interface->destroy = &ht_dict_destroy;
  interface->length = &ht_dict_length;
  interface->get_entries = &ht_dict_get_entries;
  interface->structure = ht_new(size, hash);
  if (interface->structure == NULL)
    {
      free(interface);
      return (NULL);
    }
  return (interface);
}
