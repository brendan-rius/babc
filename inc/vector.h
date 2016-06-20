/*
** vector.h for libmy in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Mon Apr 27 15:51:40 2015 Louis Person
** Last update Sat May 23 03:36:44 2015 Brendan Rius
*/

#ifndef VECTOR_H_
# define VECTOR_H_

# include <sys/types.h>

# define VEC_DEFAULT_SIZE 64

# include "my.h"

struct			s_vec
{
  void			**_data;	/* The array of data */
  size_t		size;		/* The number of elements */
  size_t		_capacity;	/* The maximum number of elements */
  void			(*free_fct)();	/* A function to free elements */
};

typedef void (*t_consumer_fct)(void *data);
typedef void *(*t_mapper_fct)(const void *data);
typedef bool (*t_filterer_fct)(const void *data);

/*
** Create a new vector dynamically allocated. Does not
** initializer it
*/
int		 vec_new(struct s_vec **vec);

/*
** Initialize a vector. If the size is 0 then, a default value will be applied
*/
int		 vec_init(struct s_vec *vec,
			  size_t capacity,
			  void (*free_fct)());

/*
** Create a vector from an array "source". Capacity if the number of
** elements to take from source.
*/
int		 vec_from(struct s_vec *vec,
			  void **source,
			  size_t capacity,
			  void (*free_fct)());

struct s_vec	*vec_map(struct s_vec *vec, t_mapper_fct f);
struct s_vec	*vec_filter(struct s_vec *vec, t_filterer_fct f);
struct s_vec	*vec_concat(struct s_vec *to, ...);
int		 vec_foreach(struct s_vec *vec, t_consumer_fct f);

/*
** Pop the last element
*/
int		 vec_pop(struct s_vec *vec, void **dest);

/*
** Get the last element
*/
int		 vec_last(struct s_vec *vec, void **dest);

/*
** Store "e" into "vec"
*/
int		 vec_push(struct s_vec *vec, void *e);

/*
** Returns an dynamically alloced array containing the elements
** of "vec". Returns NULL on failure.
*/
void		**vec_serialize(struct s_vec *vec);

/*
** Frees all the elements in the array.
*/
int		 vec_empty(struct s_vec *vec);

/*
** Destroys a vector and frees all its elemnt
*/
int		 vec_destroy(struct s_vec *vec);

/*
** Initialize iterator
*/
struct s_iterator	vec_iterator(struct s_vec *vec);

#endif /* !VECTOR_H_ */
