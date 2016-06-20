/*
** dictionnary_get_entries.c for dictionnary in /home/brendan/rendu/PSU_2014_minishell1
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Sun Feb  1 11:09:06 2015 Brendan Rius
** Last update Sun Apr 12 17:40:29 2015 Louis Person
*/

#include <stdlib.h>
#include "my.h"

t_dict_entry	**dict_get_entries(t_dict *dict)
{
  if (dict == NULL)
    return (NULL);
  return (dict->interface->get_entries(dict));
}
