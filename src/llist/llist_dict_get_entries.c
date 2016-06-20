/*
** llist_dict_get_entries.c for llist in /home/brendan/rendu/PSU_2014_minishell1
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Sun Feb  1 11:17:49 2015 Brendan Rius
** Last update Sun Feb  1 11:21:46 2015 Brendan Rius
*/

#include <stdlib.h>
#include "dictionnary.h"
#include "my.h"

t_dict_entry	**llist_dict_get_entries(t_dict *dict)
{
  t_llist	*list;

  list = (t_llist *) dict->interface->structure;
  return ((t_dict_entry **) llist_to_array(list));
}
