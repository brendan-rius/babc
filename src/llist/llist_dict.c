/*
** llist_dict.c for llist in /home/brendan/dictionnaries
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Wed Jan 21 20:35:37 2015 Brendan Rius
** Last update Sun Feb  1 11:56:24 2015 Brendan Rius
*/

#include <stdlib.h>
#include "dictionnary.h"
#include "my.h"

t_dict_interface	*llist_get_dict()
{
  t_dict_interface	*actions;
  t_llist		*list;

  actions = malloc(sizeof(*actions));
  if (actions == NULL)
    return (NULL);
  list = llist_new(&dict_free_entry);
  if (list == NULL)
    {
      free(actions);
      return (NULL);
    }
  actions->structure = list;
  actions->set = &llist_dict_set;
  actions->get = &llist_dict_get;
  actions->remove = &llist_dict_remove;
  actions->destroy = &llist_dict_destroy;
  actions->length = &llist_dict_length;
  actions->get_entries = &llist_dict_get_entries;
  return (actions);
}

int		llist_dict_destroy(t_dict *dict)
{
  t_llist	*list;

  list = (t_llist *) dict->interface->structure;
  if (list == NULL)
    return (DICT_ERR_NULL_DICT);
  llist_destroy(list);
  return (OK);
}

int		llist_dict_remove(t_dict *dict, void *key)
{
  t_llist	*list;
  t_llist_e	*node;
  t_dict_entry	*entry;

  list = (t_llist *) dict->interface->structure;
  node = list->front;
  while (node != NULL)
    {
      entry = (t_dict_entry *) node->data;
      if (dict->compare_keys(key, entry->key) == 0)
	{
	  llist_remove_node(list, node);
	  return (OK);
	}
      node = node->next;
    }
  return (DICT_ERR_NO_NODE);
}

int		llist_dict_set(t_dict *dict, void *key, void *value)
{
  t_llist	*list;
  t_llist_e	*node;
  t_dict_entry	*entry;

  list = (t_llist *) dict->interface->structure;
  node = list->front;
  while (node != NULL)
    {
      entry = (t_dict_entry *) node->data;
      if (dict->compare_keys(key, entry->key) == 0)
	{
	  entry->value = value;
	  return (OK);
	}
      node = node->next;
    }
  entry = dict_new_entry(dict, key, value);
  if (entry == NULL)
    {
      free(entry);
      return (DICT_ERR_CANNOT_CREATE_ENTRY);
    }
  llist_add(list, entry);
  return (OK);
}

void		*llist_dict_get(t_dict *dict, void *key)
{
  t_llist	*list;
  t_llist_e	*node;
  t_dict_entry	*entry;

  list = (t_llist *) dict->interface->structure;
  node = list->front;
  while (node != NULL)
    {
      entry = (t_dict_entry *) node->data;
      if (dict->compare_keys(entry->key, key) == OK)
	return (entry->value);
      node = node->next;
    }
  return (NULL);
}
