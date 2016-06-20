/*
** my.h for my in /home/rius_b/rendu/Piscine_C_J08/ex_04
** 
** Made by brendan rius
** Login   <rius_b@epitech.net>
** 
** Started on  Fri Oct 10 11:18:26 2014 brendan rius
** Last update Sun May 24 00:11:05 2015 Brendan Rius
*/

#ifndef MY_H_
# define MY_H_

# include <sys/types.h>
# include <stddef.h>
# include <stdbool.h>

/*
** Similar as container_of()
*/
# define CNTNR(p, s, m) ((s *) (((char *) (p)) - offsetof(s, m)))

/*
** Maths macros
*/
# define MAX(x, y)	(((x) > (y)) ? (x) : (y))
# define MIN(x, y)	(((x) < (y)) ? (x) : (y))
# define ROUND(x)	(((int) ((x) + 0.5)))
# define FLOOR(x)	(((int) (x)))
# define DEC(x)		((x) - ((int) (x)))
# define CEIL_POS(x)	(DEC((x)) == 0 ? (x) : FLOOR((x) + 1))
# define CEIL_NEG(x)	(DEC((x)) == 0 ? (x) : FLOOR((x) - 1))
# define CEIL(x)	(((x) < 0) ? CEIL_NEG((x)) : CEIL_POS((x)))

# define ARR_PUSH(x, y, size)	((x)[(size)++] = (y))
# define ARR_POP(x, size)	((x)[--(size)])

/*
** ITERATORS
*/
# define _FOREACH(e, i)	while ((i)->has_next(i) && ((e) = (i)->next(i), true))
# define FOREACH(x)	_FOREACH(x)
# define IN		,
# define HAS_NEXT(i)	((i)->has_next(i))
# define NEXT(i)	((i)->next(i))
# define PEEK(i)	((i)->peek(i))

struct		s_iterator
{
  bool		(*has_next)(struct s_iterator *);
  void		*(*next)(struct s_iterator *);
  void		*(*peek)(struct s_iterator *);
  void		*holder;
  void		*index;
};

# include "dictionnary.h"

# include "llist.h"

# include "hashtable.h"

# include "vector.h"

# include "btrees.h"

# include "str.h"

# define GNL_BUFFER_SIZE 1024
char	*get_next_line(const int fd);

#endif /* !MY_H_ */
