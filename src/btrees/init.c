/*
** init.c for btrees in /home/brendan/rendu/42sh
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Thu Apr 30 19:41:46 2015 Brendan Rius
** Last update Thu Apr 30 20:57:31 2015 Brendan Rius
*/

#include <stdlib.h>
#include <assert.h>
#include "btrees.h"

void	btree_init(struct s_btree *tree, void (*free_fct)(),
		   struct s_btree *left, struct s_btree *right)
{
  assert(tree != NULL);
  tree->free_fct = free_fct;
  tree->left = left;
  if (left != NULL)
    left->up = tree;
  tree->right = right;
  if (right != NULL)
    right->up = tree;
}
