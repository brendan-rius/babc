/*
** env.h for minishell1 in /home/brendan/rendu/PSU_2014_minishell1
** 
** Made by Brendan Rius
** Login   <rius_b@epitech.net>
** 
** Started on  Sat Jan 31 16:56:59 2015 Brendan Rius
** Last update Sat Jan 31 17:41:39 2015 Brendan Rius
*/

#ifndef ENV_H_
# define ENV_H_

# define AVG_ENV_SIZE 100

/*
** Init the environment.
** Return 0 in case of success.
** Should be called before using another env function
*/
int	init_env();

/*
** Set an env variable and returns it.
** Il the value is NULL, il will destroy the variable
** Returns NULL in case of failure or if the variable has
** been destroyed.
*/
char	*my_setenv(char *key, char *value);

/*
** Get an env variable.
** Returns NULL in case of failure
*/
char	*my_getenv(char *key);

/*
** Returns the environment
*/
char	**get_all_env();

/*
** Destroy the environment
*/
void	destroy_env();

#endif /* !ENV_H_ */
