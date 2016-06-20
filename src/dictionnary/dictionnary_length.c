/*
** dictionnary_length.c for dictionnary in /home/brendan/rendu/PSU_2014_minishell1
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Sun Feb  1 11:26:33 2015 Brendan Rius
** Last update Sun Feb  1 12:32:51 2015 Brendan Rius
*/

#include <stdlib.h>
#include "my.h"

unsigned int	dict_length(t_dict *dict)
{
  if (dict == NULL)
    return (0);
  return (dict->interface->length(dict));
}
