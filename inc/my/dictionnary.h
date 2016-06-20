/*
** dictionnary.h for dictionnary in /home/brendan/dictionnaries
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Wed Jan 21 15:08:38 2015 Brendan Rius
** Last update Sun Feb  1 11:26:26 2015 Brendan Rius
*/

#ifndef DICTIONNARY_H_
# define DICTIONNARY_H_

struct s_dict;

# undef OK

# define DICT_KEY(x, type)	((type) (x)->key)
# define DICT_VALUE(x, type)	((type) (x)->value)

enum	e_dict_errors
  {
    OK,
    NOK,
    DICT_ERR_NULL_DICT,
    DICT_ERR_NULL_KEY,
    DICT_ERR_NULL_VALUE,
    DICT_ERR_NULL_ENTRY,
    DICT_ERR_CANNOT_CREATE_ENTRY,
    DICT_ERR_NO_NODE
  };

typedef struct		s_dict_interface
{
  void			*structure;
  int			(*set)(struct s_dict *dict, void *key, void *value);
  void			*(*get)(struct s_dict *dict, void *key);
  int			(*remove)(struct s_dict *dict, void *key);
  int			(*destroy)(struct s_dict *dict);
  struct s_dict_entry	**(*get_entries)(struct s_dict *dict);
  unsigned int		(*length)(struct s_dict *dict);
}			t_dict_interface;

typedef struct	s_dict_entry
{
  void		*key;
  void		*value;
  void		(*free_value)();
  void		(*free_key)();
}		t_dict_entry;

typedef struct			s_dict
{
  struct s_dict_interface	*interface;
  unsigned int			size;
  void				(*free_value)();
  void				(*free_key)();
  int				(*compare_keys)();
}				t_dict;

/*
** Create a new dictionnary with actions. "free_value" is a function
** to free the values that the dictionnary contains, while "compare_key"
** is  function that should return OK when two keys are equal
*/
t_dict	*dict_new(t_dict_interface *interface,
		  void (*free_value)(),
		  void (*free_key)(),
		  int (*compare_keys)());

/*
** Remove a dictionnary and all its entries
*/
int	dict_destroy(t_dict *dict);

/*
** Insert a new entry to the dictionnary.
** If the key already exists, its value will be overwritten.
** Neither the key nor the value can be NULL.
** Return OK in case of success.
*/
int	dict_set(t_dict *dict, void *key, void *value);

/*
** Remove an entry from a dictionnary.
** The key cannot be NULL.
** Return OK in case of success.
*/
int	dict_remove(t_dict *dict, void *key);

/*
** Get a value from a key in the dictionnary.
** Returns the value on success, NULL otherwise
*/
void	*dict_get(t_dict *dict, void *key);

/*
** Compare the keys of two entries. Returns "OK" on match, "NOK" when
** non matching.
*/
int	dict_compare_entries(t_dict *dict, t_dict_entry *e1, t_dict_entry *e2);

/*
** Create a new dictionnary entry based on the pair (key, value) and returns
** it.
** Returns NULL in case of failure.
*/
t_dict_entry	*dict_new_entry(t_dict *dict, void *key, void *value);

/*
** Compare the key of an entry with a key
*/
int	dict_compare_entry(t_dict *dict, t_dict_entry *e1, void *key);

/*
** Free an entry
*/
void	dict_free_entry(t_dict_entry *entry);

/*
** Get all entries of the dictionnary as an array.
** For each element of the array (t_dict_entry), you
** can access its key with DICT_KEY(x, type) and its value
** with DICT_VALUE(x, type).
*/
t_dict_entry	**dict_get_entries(t_dict *dict);

/*
** Returns the number of entries in the list
*/
unsigned int	dict_length(t_dict *dict);

#endif /* !DICTIONNARY_H_ */
