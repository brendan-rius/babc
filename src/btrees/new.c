/*
** new.c for btrees in /home/brendan/rendu/42sh
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Thu Apr 30 19:30:13 2015 Brendan Rius
** Last update Thu Apr 30 20:28:18 2015 Brendan Rius
*/

#include <assert.h>
#include <stdlib.h>
#include "btrees.h"

int			btree_new(struct s_btree **btreeptr)
{
  struct s_btree	*t;

  assert(btreeptr != NULL);
  t = malloc(sizeof(struct s_btree));
  if (t == NULL)
    return (-1);
  *btreeptr = t;
  return (0);
}
