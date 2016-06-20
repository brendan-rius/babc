/*
** llist.h for llist in /home/brendan/hashtables
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Fri Nov 21 19:04:13 2014 Brendan Rius
** Last update Fri May 29 23:56:25 2015 Louis Person
*/

#ifndef LLIST_H_
# define LLIST_H_

# include <sys/types.h>
# include "dictionnary.h"

typedef struct		s_llist_e
{
  void			*data;
  struct s_llist_e	*next;
  struct s_llist_e	*previous;
}			t_llist_e;

typedef struct s_llist
{
  size_t	size;
  void		(*free_fct)();
  t_llist_e	*front;
  t_llist_e	*rear;
}		t_llist;

/*
** Destroy and free a linked list and its data.
** The data if freed using the free function passed
** at the creation of the list. If this function was
** NULL, the data won't be freed
*/
void	llist_destroy(t_llist *list);

/*
** Create a new linked list and bind a function to
** free its data to it. Note that this function can
** be NULL
*/
t_llist	*llist_new(void (*free_fct)());

/*
** Add an element to the linked list.
** Returns the added element.
*/
void	*llist_add(t_llist *list, void *data);

/*
** Search and returns an element "data" from a linked list.
** The "cmp" function will be used to compare elements. It
** should return 0 when two elements match.
** If nothing is found, it returns NULL.
** Note that the search will be proceeded from front to last
** and that only the first occurence will be returned.
*/
void	*llist_search(t_llist *list, void *data, int (*cmp)());

/*
** Remove all occurences to "data" in the linked list.
** Note that the comparison will me made using the "cmp"
** function, and this function should return 0 when matching.
** Also, note that if a free function was passed when creating
** the linked list, the removed data will automatically be freed.
*/

void	 llist_remove(t_llist *list, void *data, int (*cmp)());

/*
** Same as "llist_remove()" but does not free the data.
*/
void	llist_remove_nofree(t_llist *list, void *data, int (*cmp)());

/*
** Replace the first occurence to "data" by "new".
** Note that the comparison function "cmp" should return
** 0 when matching. If a freeing function has been passed
** when creating the linked list, then, the old data
** will be freed.
** Returns the new data in case of success, NULL in case
** of failure.
*/
void	*llist_replace(t_llist *list,
		       void *data,
		       void *new,
		       int (*cmp)());

/*
** Dump a linked list to an array. Note that the array will
** be allocated. The list will be dumped from front to end.
** Returns NULL in case of failure, or a pointer to the array
** in case of success
*/
void	**llist_to_array(t_llist *list);

/*
** Get the n-th element of the linked list. Returns the element
** in case of success, NULL otherwise
*/
void	*llist_nget(t_llist *list, int n);

/*
** Launch the function "payload" with the n-th eleement of the list
** as only parameter. If this element does not exist, the function won't
** be launched, and llist_napply will return -1.
*/
int	llist_napply(t_llist *list, int n, void (*payload)());

/*
** Remove the n-th element of a list and free its data (if a free
** function is available. In case of failute, this function will
** return -1. On success it returns 0.
*/
int	llist_nremove(t_llist *list, int n);

/*
** Call the function "payload" for each element in the list,
** with the element as the only parameter
*/
void	llist_apply(t_llist *list, void (*payload)());

/*
** Get the n-th element of the list, but returns the node instead of
** the data
*/
t_llist_e	*llist_nget_record(t_llist *list, int n);

/*
** Delete a node from the list
*/
void	llist_remove_node(t_llist *list, t_llist_e *node);

/*
** Concatenate l1 and l2
*/
t_llist	*llist_patch(t_llist *l1, t_llist *l2);

/*
** These functions are used to make the linked-list
** available as a dictionnary
*/
t_dict_interface	*llist_get_dict();
int	llist_dict_set(struct s_dict *dict, void *key, void *value);
void	*llist_dict_get(struct s_dict *dict, void *key);
int	llist_dict_remove(struct s_dict *dict, void *key);
int	llist_dict_destroy(struct s_dict *dict);
unsigned int	llist_dict_length(t_dict *dict);
t_dict_entry	**llist_dict_get_entries(struct s_dict *dict);

/*
** Return an iterator that goes from left to right
*/
struct s_iterator	llist_iterator_ltr(struct s_llist *list);

/*
** Return an iterator that goes from right to left
*/
struct s_iterator	llist_iterator_rtl(struct s_llist *list);

#endif /* !LLIST_H_ */
