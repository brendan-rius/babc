/*
** get_next_line.c for get_next_line in /home/brendan/gnl2
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Wed Feb  4 11:26:03 2015 Brendan Rius
** Last update Sun May 24 00:10:31 2015 Brendan Rius
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

static char	*extract_line(char *line, int nl_pos, int *linesize)
{
  char		*newline;
  int		i;

  newline = malloc(nl_pos + 1);
  if (newline == NULL)
    return (NULL);
  i = 0;
  while (i < nl_pos)
    {
      newline[i] = line[i];
      ++i;
    }
  i = nl_pos + 1;
  while (i < *linesize)
    {
      line[i - nl_pos - 1] = line[i];
      ++i;
    }
  newline[nl_pos] = '\0';
  *linesize -= nl_pos + 1;
  return (newline);
}

static char	*add_chunk_to_line(char *line, int *linesize,
				   char *chunk, int chunksize)
{
  int		i;
  int		j;
  char		*newline;

  newline = malloc(*linesize + chunksize);
  if (newline == NULL)
    return (NULL);
  i = 0;
  while (i < *linesize)
    {
      newline[i] = line[i];
      ++i;
    }
  j = 0;
  while (j < chunksize)
    {
      newline[i + j] = chunk[j];
      ++j;
    }
  *linesize += chunksize;
  free(line);
  return (newline);
}

static int	contains_nl(char *s, int size)
{
  int		i;

  if (s == NULL)
    return (-1);
  i = 0;
  while (i < size)
    {
      if (s[i] == '\n')
	return (i);
      ++i;
    }
  return (-1);
}

static char	*code_the_dirty_way(char **line, int *linesize)
{
  char		*save;
  int		i;

  save = malloc(*linesize + 1);
  if (save == NULL)
    return (NULL);
  i = 0;
  while (i < *linesize)
    {
      save[i] = (*line)[i];
      ++i;
    }
  save[*linesize] = '\0';
  free(*line);
  *line = NULL;
  *linesize = 0;
  return (save);
}

/*
** Principle:
** we have a static variable which is a line. The first time
** the function is called, this line is NULL.
** Each time it is called, we check if the line contains a '\n'.
** If so, we extract the line contained in "line" and returns
** all the characters before de '\n', and we then 'shift' the line
** so it does not contain the line we just returned. This is all done
** by using the "extract_line" function.
** If the line did not contain a '\n', we read the file chunk
** by chunk and we add them to the line using "add_chunk_to_line".
** Each time we read a chunk, we also verify if the line has a '\n',
** if it has, we return the line using "extract_line". If not
** but there is no more to read, we return the line
*/
char		*get_next_line(const int fd)
{
  static char	*line;
  static int	linesize;
  char		chunk[GNL_BUFFER_SIZE];
  int		nl_pos;
  int		bytes;

  if ((nl_pos = contains_nl(line, linesize)) != -1)
    return (extract_line(line, nl_pos, &linesize));
  while ((bytes = read(fd, chunk, GNL_BUFFER_SIZE)) >= 0)
    {
      if (bytes == 0 && linesize == 0)
	{
	  free(line);
	  return ((line = NULL));
	}
      line = add_chunk_to_line(line, &linesize, chunk, bytes);
      if ((nl_pos = contains_nl(line, linesize)) != -1)
	return (extract_line(line, nl_pos, &linesize));
      if (bytes == 0)
	return (code_the_dirty_way(&line, &linesize));
    }
  free(line);
  line = NULL;
  linesize = 0;
  return (NULL);
}
