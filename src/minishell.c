/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbock <fbock@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:28:44 by fbock             #+#    #+#             */
/*   Updated: 2023/12/18 13:06:36 by fbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipe pipe_struct;

	// handlers

	while (1)
	{
		pipe_struct = parse_line(void);
		execute_line(pipe_struct);
	}

	return (0);
}
