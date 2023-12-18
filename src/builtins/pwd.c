/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbock <fbock@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:31:48 by fbock             #+#    #+#             */
/*   Updated: 2023/12/18 15:42:42 by fbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	pwd(void)
{
	char	buffer[CWD_BUFFER_SIZE];
	char	*getcwd_retv;
	int		error;

	getcwd_retv = getcwd(buffer, CWD_BUFFER_SIZE);
	if (getcwd_retv == NULL)
	{
		perror("Error getting path.");
		return (false);
	}
	error = printf("%s\n", buffer);
	if (error < 0)
	{
		perror("Error printing path.");
		return (false);
	}
	return (true);
}
