/*
** my_getenv.c for my_getenv in /home/brendan/rendu/PSU_2014_my_select
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Wed Dec 17 19:58:10 2014 Brendan Rius
** Last update Sat Jan 31 17:22:00 2015 Brendan Rius
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char		*my_real_getenv(char *s)
{
  int		size;
  char		**env;
  extern char	**environ;

  env = environ;
  size = my_strlen(s);
  while (*env)
    {
      if (my_strncmp(*env, s, size) == 0)
	if (*((*env) + size) == '=')
	  return ((*env) + size + 1);
      ++env;
    }
  return (NULL);
}
