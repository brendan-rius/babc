/*
** set.c for btrees in /home/brendan/rendu/42sh
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Thu Apr 30 19:37:38 2015 Brendan Rius
** Last update Thu Apr 30 19:38:07 2015 Brendan Rius
*/

#include <assert.h>
#include <stdlib.h>
#include "btrees.h"

void	btree_set(struct s_btree *tree, void *data)
{
  assert(tree != NULL);
  tree->data = data;
}
