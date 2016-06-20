/*
** hashtable.h for hashtable in /home/brendan/dictionnaries
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Thu Jan 22 14:26:44 2015 Brendan Rius
** Last update Sun Feb  1 14:56:31 2015 Brendan Rius
*/

#ifndef HASHTABLE_H_
# define HASHTABLE_H_

struct s_dict;
struct s_dict_interface;

typedef struct	s_htable
{
  unsigned int	capacity;
  unsigned int	size;
  unsigned int	*taken_buckets_id;
  unsigned int	nb_taken_id;
  struct s_dict	**buckets;
  unsigned int	(*hash)();
}		t_htable;

/*
** Create a new hash table.
** The capacity should be correct so the table is fast.
** If we add more element than the capacity of the table, it will work,
** but it will slow the table down a bit.
** Returns it in case of success.
** Returns NULL in case of failure
*/
t_htable	*ht_new(unsigned int capacity,
			unsigned int (*hash)());

/*
** Hash a key using the hash function of the data structure and returns
** it
*/
unsigned int	ht_hash(t_htable *table, void *key);

/*
** Hash a string in O(n)
*/
unsigned int	ht_hash_string(char *s);

/*
** Inteface to use hashtable as dictionnary
*/
struct s_dict_interface	*ht_get_dict(unsigned int size,
				     unsigned int (*hash)());
int	ht_dict_set(struct s_dict *dict, void *key, void *value);
void	*ht_dict_get(struct s_dict *dict, void *key);
int	ht_dict_remove(struct s_dict *dict, void *key);
int	ht_dict_destroy(struct s_dict *dict);
unsigned int	ht_dict_length(struct s_dict *dict);
struct s_dict_entry	**ht_dict_get_entries(struct s_dict *dict);

#endif /* !HASHTABLE_H_ */
