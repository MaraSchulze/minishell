/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbock <fbock@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:43:49 by fbock             #+#    #+#             */
/*   Updated: 2023/12/18 19:09:25 by fbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	size_t	get_env_length(void)
{
	extern char	**environ;
	size_t		env_size;

	env_size = 0;
	while (environ && environ[env_size] != NULL)
		env_size++;
	return (env_size);
}

static bool	copy_old_env(char **old_env, char **new_env, size_t env_size)
{
	long	index;

	index = 0;
	while (index < env_size)
	{
		new_env[index] = ft_strdup(old_env[index]);
		if (!new_env[index])
		{
			index--;
			while (index > 0)
			{
				free(new_env[index]);
				index--;
			}
			return (false);
		}
		index++;
	}
	return (true);
}

static bool	set_new_environ(char *new_pair, char **new_environ,
								char **old_environ, size_t size)
{
	char	*new_env_var_heap;

	new_env_var_heap = ft_strdup(new_pair);
	if (!new_env_var_heap)
	{
		free(new_environ);
		return (false);
	}
	if (!copy_old_env(old_environ, new_environ, size))
	{
		free(new_env_var_heap);
		return (false);
	}
	new_environ[size] = new_env_var_heap;
	new_environ[size + 1] = NULL;
	return (true);
}

// first time is system memory and can't be freed, 2nd+ is self allocated.
void	free_old_env(char **old_env)
{
	size_t			index;
	extern char		**environ;
	static size_t	called = 0;

	index = 0;
	called++;
	if (!old_env)
		old_env = environ;
	if (called > 1)
	{
		while (old_env && old_env[index])
		{
			free(old_env[index]);
			index++;
		}
		free(old_env);
	}
}

// call for each pair of variable=value to export it to the env
bool	export(char *env_pair)
{
	extern char	**environ;
	char		**old_env_buffer;
	char		**new_environ;
	size_t		env_size;
	char		*new_env_var_heap;

	env_size = get_env_length();
	if (env_size < 1)
		return (false);
	new_environ = malloc((sizeof(char *) * (env_size + 1)) + sizeof(void *));
	if (!new_environ)
		return (false);
	if (!set_new_environ(env_pair, new_environ, environ, env_size))
	{
		free(new_environ);
		return (false);
	}
	old_env_buffer = environ;
	environ = new_environ;
	free_old_env(old_env_buffer);
	return (true);
}