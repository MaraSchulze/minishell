/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbock <fbock@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:55:26 by marschul          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/01/10 13:50:39 by marschul         ###   ########.fr       */
=======
/*   Updated: 2024/01/10 14:04:25 by fbock            ###   ########.fr       */
>>>>>>> 1bdd4562b4aee04733a267d9ca0017e07957ea32
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	error_wrapper(void)
{
	perror("Minishell");
	return (false);
}

bool	error_wrapper_bool(char *message)
{
	perror(message);
	return (false);
}

bool	error_wrapper_int(char *message)
{
	perror(message);
	return (0);
}

void	error_wrapper_exit(char *message)
{
	perror(message);
	exit(1);
}

void	free_vector(char **vector)
{
	int	i;

	i = 0;
	while (vector && vector[i] != NULL)
	{
		free(vector[i]);
		i++;
	}
	free(vector);
}
