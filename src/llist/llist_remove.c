/*
** llist_remove.c for llist in /home/brendan/hashtables
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Fri Nov 21 20:26:34 2014 Brendan Rius
** Last update Sun Jan 11 15:05:13 2015 Brendan Rius
*/

#include <stdlib.h>
#include "llist.h"

void	llist_remove_node(t_llist *list, t_llist_e *node)
{
  if (node->previous)
    node->previous->next = node->next;
  if (node->next)
    node->next->previous = node->previous;
  if (list->free_fct)
    list->free_fct(node->data);
  if (node == list->front)
    list->front = node->next;
  if (node == list->rear)
    list->rear = node->previous;
  list->size--;
  free(node);
}

void		llist_remove(t_llist *list, void *data, int (*cmp)())
{
  t_llist_e	*current;
  t_llist_e	*next;

  if (!list || list->size <= 0)
    return;
  current = list->front;
  while (current)
    {
      next = current->next;
      if ((*cmp)(current->data, data) == 0)
	{
	  if (list->free_fct)
	    list->free_fct(current->data);
	  llist_remove_node(list, current);
	}
      current = next;
    }
}

void		llist_remove_nofree(t_llist *list, void *data, int (*cmp)())
{
  t_llist_e	*current;
  t_llist_e	*next;

  if (!list || list->size <= 0)
    return;
  current = list->front;
  while (current)
    {
      next = current->next;
      if ((*cmp)(current->data, data) == 0)
	llist_remove_node(list, current);
      current = next;
    }
}
