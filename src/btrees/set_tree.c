/*
** set_tree.c for btrees in /home/brendan/rendu/42sh
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Thu Apr 30 19:31:29 2015 Brendan Rius
** Last update Thu Apr 30 20:44:33 2015 Brendan Rius
*/

#include <stdlib.h>
#include <assert.h>
#include "btrees.h"

void	btree_set_tree(struct s_btree *tree,
		       enum btree_position pos,
		       struct s_btree *to_add)
{
  assert(tree != NULL);
  if (pos == LEFT)
    tree->left = to_add;
  else if (pos == RIGHT)
    tree->right = to_add;
  else
    tree->up = to_add;
  to_add->up = tree;
}
