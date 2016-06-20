/*
** bst.h for bst in /home/brendan/rendu/common/lib/my/include
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Fri Nov 21 20:34:44 2014 Brendan Rius
** Last update Fri Nov 21 20:34:44 2014 Brendan Rius
*/

#ifndef BST_H_
# define BST_H_

typedef struct		s_btree_e
{
  void			*index;
  void			*data;
  struct s_btree_e	*right;
  struct s_btree_e	*left;
}			t_btree_e;

typedef struct	s_bst
{
  t_btree_e	*root;
  int		(*cmp)();
  void		(*free_index)();
  void		(*free_data)();
}		t_bst;

/*
** Create a new BST and bind freeing functions to it.
** Note that this functions can be NULL.
*/
t_bst	*bst_new(int (*cmp)(),
		 void (*free_index)(),
		 void (*free_data)());

/*
** Free the entire BST using the two freeing functions.
** If they are NULL, it won't be freed
*/
void	bst_destroy(t_bst *map);

/*
** Add an element to the BST, bound to the index.
** Note that the comparison function for insertion
** is the one which you passed when creating the BST
*/
int	bst_add(t_bst *map,
		void *index,
		void *data);

/*
** Search the BST for an index, and returns the value
** bound to this index.
** The comparison function is the one you passed when
** creating the BST
*/
void	*bst_search(t_bst *map, const void *index);

#endif /* !BST_H_ */
