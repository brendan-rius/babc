/*
** llist_dict_get_length.c for llist in /home/brendan/rendu/PSU_2014_minishell1
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Sun Feb  1 11:28:54 2015 Brendan Rius
** Last update Sun Feb  1 11:56:00 2015 Brendan Rius
*/

#include <stdlib.h>
#include "my.h"

unsigned int	llist_dict_length(t_dict *dict)
{
  t_llist	*list;

  list = (t_llist *) dict->interface->structure;
  return (list->size);
}
