/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbock <fbock@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:43:49 by fbock             #+#    #+#             */
/*   Updated: 2023/12/18 16:18:06 by fbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// call for each pair of variable=value to export it to the env
bool	export(const char *env_var, const char *var_val)
{
	extern char **environ;

	for (int i = 0; environ[i]; i++)
	{
		printf("%s\n", environ[i]);
	}
	return (true);
}
