/*
** llist_nremove.c for llist_nremove in /home/brendan/rendu/PSU_2014_my_select
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Dec 22 15:38:44 2014 Brendan Rius
** Last update Sun Jan 11 15:04:57 2015 Brendan Rius
*/

#include <stdlib.h>
#include "my.h"

int		llist_nremove(t_llist *list, int n)
{
  t_llist_e	*current;

  if ((current = llist_nget_record(list, n)) == NULL)
    return (-1);
  llist_remove_node(list, current);
  return (0);
}
