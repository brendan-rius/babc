/*
** llist_napply.c for llist_napply in /home/brendan/rendu/PSU_2014_my_select
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Dec 22 15:31:14 2014 Brendan Rius
** Last update Mon Dec 22 15:31:14 2014 Brendan Rius
*/

#include "my.h"

int	llist_napply(t_llist *list, int n, void (*payload)())
{
  void	*data;

  if (!list || !payload)
    return (-1);
  data = llist_nget(list, n);
  if (!data)
    return (-1);
  (*payload)(data);
  return (0);
}
