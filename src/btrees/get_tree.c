/*
** get_tree.c for btrees in /home/brendan/rendu/42sh
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Thu Apr 30 19:34:29 2015 Brendan Rius
** Last update Thu Apr 30 20:42:37 2015 Brendan Rius
*/

#include <stdlib.h>
#include <assert.h>
#include "btrees.h"

struct s_btree	*btree_get_tree(struct s_btree *tree,
				enum btree_position pos)
{
  assert(tree != NULL);
  if (pos == LEFT)
    return (tree->left);
  else if (pos == RIGHT)
    return (tree->right);
  else
    return (tree->up);
}
