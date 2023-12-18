/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbock <fbock@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:16:14 by fbock             #+#    #+#             */
/*   Updated: 2023/12/18 17:30:27 by fbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// returns absolute path
bool	cd(const char *entered_path_arg)
{
	int error;

	error = chdir(entered_path_arg);
	if (error == -1)
	{
		perror("Error changing directory.");
		return (false);
	}
	return (true);
}
