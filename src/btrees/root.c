/*
** root.c for btrees in /home/brendan/rendu/42sh/src/parser
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Thu Apr 30 21:17:02 2015 Brendan Rius
** Last update Thu Apr 30 21:21:41 2015 Brendan Rius
*/

#include <assert.h>
#include <stdlib.h>
#include "btrees.h"

void	btree_root(struct s_btree *tree)
{
  assert(tree != NULL);
  tree->up = NULL;
}
