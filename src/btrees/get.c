/*
** get.c for btrees in /home/brendan/rendu/42sh
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Thu Apr 30 19:36:48 2015 Brendan Rius
** Last update Thu Apr 30 19:37:21 2015 Brendan Rius
*/

#include <assert.h>
#include <stdlib.h>
#include "btrees.h"

void	*btree_get(struct s_btree *tree)
{
  assert(tree != NULL);
  return (tree->data);
}
