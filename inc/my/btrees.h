/*
** btrees.h for btrees in /home/brendan/rendu/42sh
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Thu Apr 30 19:19:17 2015 Brendan Rius
** Last update Sun May 24 18:06:20 2015 Brendan Rius
*/

#ifndef BTREES_H_
# define BTREES_H_

struct s_iterator;

struct			s_btree
{
  void			*data;
  struct s_btree	*up;
  struct s_btree	*right;
  struct s_btree	*left;
  void			(*free_fct)();
};

enum	btree_position
  {
    RIGHT,
    LEFT,
    UP
  };

/*
** Creates a binary tree dynamically
*/
int	btree_new(struct s_btree **btreeptr);

/*
** Initialize a tree. "free_fct" is a function that frees the data contained in
** the node.
*/
void	btree_init(struct s_btree *tree, void (*free_fct)(),
		   struct s_btree *left, struct s_btree *right);

/*
** Sets the "pos" position of tree "tree" to "to_add"
*/
void	btree_set_tree(struct s_btree *tree,
		       enum btree_position pos,
		       struct s_btree *to_add);

/*
** Gets the the btree at "pos" from the tree "tree"
*/
struct s_btree	*btree_get_tree(struct s_btree *tree,
				enum btree_position pos);

/*
** Get data from a tree
*/
void	*btree_get(struct s_btree *tree);

/*
** Set data to a tree
*/
void	btree_set(struct s_btree *tree, void *data);

/*
** Destroys a tree recursively, freeing the data contained in each node
** if this node has a free function not set to NULL.
** Free the node containing the data using "free_node" is not null.
*/
void	btree_destroy(struct s_btree *tree, void (*free_node)());

/*
** Set tree as being a root node
*/
void	btree_root(struct s_btree *tree);

/*
** A depth-first left iterator
*/
struct s_iterator	btree_iterator_dfl(struct s_btree *tree);

/*
** A depth-first right iterator
*/
struct s_iterator	btree_iterator_dfr(struct s_btree *tree);

#endif /* BTREES_H_ */
