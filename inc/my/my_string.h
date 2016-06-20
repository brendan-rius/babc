/*
** string.h for string in /home/brendan/rendu/common/lib/my
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Fri Nov 21 20:53:05 2014 Brendan Rius
** Last update Wed Mar 18 17:16:34 2015 Brendan Rius
*/

#ifndef STRING_H_
# define STRING_H_

char	*my_strdup(const char *str);
char	*my_strndup(const char *str, int n);
char	*my_strcapitalize(char *str);
char	*my_strcat(char *dest, char *src);
int	my_strcmp(const char *s1, const char *s2);
char	*my_strcpy(char *dest, char *src);
int	my_str_isalpha(char *str);
int	my_str_islower(char *str);
int	my_str_isnum(char *str);
int	my_str_isprintable(char *str);
int	my_str_isupper(char *str);
int	my_strnlen(const char *str, int n);
int	my_strlen(const char *str);
char	*my_strlowcase(char *str);
char	*my_strncat(char *dest, char *src, int nb);
int	my_strncmp(char *s1, char *s2, int n);
char	*my_strncpy(char *dest, char *src, int n);
char	*my_strstr(const char *str, const char *to_find);
char	*my_strupcase(char *str);
char	*my_strcat_alloc(const char *s1, const char *s2);
int	my_str_count_tokens(const char *src, const char *delim);
char	**my_str_to_tokens(const char *src, const char *delim);
void	*my_memcpy(void *dest, const void *src, int n);

#endif /* !STRING_H_ */
