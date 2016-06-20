/*
** destroy.c for btrees in /home/brendan/rendu/42sh
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Thu Apr 30 19:38:19 2015 Brendan Rius
** Last update Thu Apr 30 21:00:12 2015 Brendan Rius
*/

#include <assert.h>
#include <stdlib.h>
#include "btrees.h"

void			btree_destroy(struct s_btree *tree,
				      void (*free_node)())
{
  struct s_btree	*r;
  struct s_btree	*l;

  assert(tree != NULL);
  r = tree->left;
  l = tree->right;
  if (tree->free_fct != NULL)
    tree->free_fct(tree->data);
  if (free_node != NULL)
    free_node(tree);
  if (r != NULL)
    btree_destroy(r, free_node);
  if (l != NULL)
    btree_destroy(l, free_node);
}
