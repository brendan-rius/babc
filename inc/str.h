/*
** string.h for libmy in /home/person_l
** 
** Made by Louis Person
** Login   <person_l@epitech.net>
** 
** Started on  Fri May  1 18:59:25 2015 Louis Person
** Last update Thu May 14 21:44:36 2015 Antoine Ouvrans
*/

#ifndef STR_H_
# define STR_H_

# include <sys/types.h>
# include <stdbool.h>

# define STR_DEFAULT_SIZE	64

struct s_vec;
struct s_iterator;

struct		s_string
{
  char		*_string;
  size_t	len;
  size_t	_capacity;
};

/*
** Allocates a new string object.
*/
int	string_new(struct s_string **ptr);

/*
** Initializes a new string. Default size is 64 bytes.
*/
int	string_init(struct s_string *string);

/*
** Initializes a new string from an existing char *.
** Uses strlen to get the char * length.
*/
int	string_init_from_bytes(struct s_string *string, const char *bytes);

/*
** Initializes a new string from an existing char * with a length of n.
*/
int	string_init_from_nbytes(struct s_string *string,
				const char *bytes,
				size_t n);

/*
** Concatenates a string object with another string object.
*/
int	string_cat(struct s_string *str1, const struct s_string *str2);

/*
** Concatenates a string objects with another string object over n characters.
*/
int	string_ncat(struct s_string *str1,
		    const struct s_string *str2,
		    size_t n);

/*
** Concatenates a string object with a char *.
*/
int	string_cat_str(struct s_string *string, const char *bytes);

/*
** Concatenates a string object with a char * over n bytes.
*/
int	string_ncat_str(struct s_string *string, const char *bytes, size_t n);

/*
** Returns true if the string needle is found in the string haystack.
*/
bool	string_contains(const struct s_string *haystack,
			const struct s_string *needle);

/*
** Returnes true if the char * needle is found in the string haystack.
*/
bool	string_contains_str(const struct s_string *haystack,
			    const char *needle);

/*
** Replaces every occurences of the string pattern in the string string
** by the string filler.
*/
int	string_replace(struct s_string *string,
		       const struct s_string *pattern,
		       const struct s_string *filler);
/*
** Replaces every occurences of the char * pattern in the string string
** by the char * filler.
*/
int	string_replace_str(struct s_string *string,
			   const char *pattern,
			   const char *filler);

/*
** Splits a string on every pattern occurences and stores them in matches.
*/
int	string_split(const struct s_string *string,
		     const struct s_string *pattern,
		     struct s_vec *matches);

/*
** Splits a string on every pattern occurences and stores them in matches.
*/
int	string_split_str(const struct s_string *string,
			 const char *pattern,
			 struct s_vec *matches);

/*
** Deletes leading & trailing whitespaces.
** @todo: not implemented
*/
int	string_trim(struct s_string *string);

/*
** Deletes leading whitespaces.
** @todo: not implemented
*/
int	string_trim_left(struct s_string *string);

/*
** Deletes trailing whitespaces.
** @todo: not implemented
*/
int	string_trim_right(struct s_string *string);

/*
** Destroys a string object.
*/
int	string_destroy(struct s_string *string);

/*
** Destroys and destructs a string object.
*/
void	string_delete(struct s_string *string);

/*
** Pushes a character at the end of a string
*/
int	string_push(struct s_string *string, char c);

/*
** Returns an iterator which iterates over the string character by character.
*/
struct s_iterator	string_iter_char(struct s_string *string);

#endif /* !STR_H_ */
