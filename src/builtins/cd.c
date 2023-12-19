/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbock <fbock@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:16:14 by fbock             #+#    #+#             */
/*   Updated: 2023/12/19 09:49:16 by fbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// returns absolute path
bool	cd(char *entered_path_arg)
{
	int	error;

	if (entered_path_arg == NULL)
		entered_path_arg = getenv("HOME");
	if (entered_path_arg == NULL)
		return (false);
	error = chdir(entered_path_arg);
	if (error == -1)
	{
		perror("Error changing directory.");
		return (false);
	}
	return (true);
}
