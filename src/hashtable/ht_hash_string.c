/*
** ht_hash_string.c for htable in /home/brendan/rendu/PSU_2014_minishell1
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Sat Jan 31 16:48:33 2015 Brendan Rius
** Last update Sat Jan 31 17:30:14 2015 Brendan Rius
*/

#include <stdlib.h>

unsigned int	ht_hash_string(char *s)
{
  unsigned int	hash;
  unsigned int	i;

  if (s == NULL)
    return (0);
  hash = 1;
  i = 0;
  while (s[i])
    {
      hash ^= s[i];
      ++i;
    }
  return (hash);
}
