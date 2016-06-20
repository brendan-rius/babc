/*
** ht_dict_length.c for htable in /home/brendan/rendu/PSU_2014_minishell1/lib/my
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Sun Feb  1 11:33:31 2015 Brendan Rius
** Last update Sun Feb  1 11:59:54 2015 Brendan Rius
*/

#include <stdlib.h>
#include "my.h"

unsigned int	ht_dict_length(t_dict *dict)
{
  t_htable	*table;

  table = (t_htable *) dict->interface->structure;
  return (table->size);
}
