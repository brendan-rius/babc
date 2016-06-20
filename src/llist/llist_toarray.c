/*
** llist_toarray.c for llist in /home/brendan/rendu/PSU_2014_my_ls
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Mon Nov 24 11:29:28 2014 Brendan Rius
** Last update Sat May 23 18:33:18 2015 Brendan Rius
*/

#include <stdlib.h>
#include "my.h"

void		**llist_to_array(t_llist *list)
{
  t_llist_e	*current;
  void		**array;
  int		i;

  if (list == NULL)
    return (NULL);
  if ((array = malloc(sizeof(void *) * list->size)) == NULL)
    return (NULL);
  current = list->front;
  i = 0;
  while (current)
    {
      array[i] = current->data;
      current = current->next;
      ++i;
    }
  return (array);
}
