/*
** push.c for strings in /home/brendan/rendu/42sh/lib/my
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Sat May  2 16:20:45 2015 Brendan Rius
** Last update Sat May  2 16:23:06 2015 Brendan Rius
*/

#include "str.h"

int	string_push(struct s_string *string, char c)
{
  return (string_ncat_str(string, &c, 1));
}
