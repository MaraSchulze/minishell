/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbock <fbock@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:28:44 by fbock             #+#    #+#             */
/*   Updated: 2023/12/18 14:00:50 by fbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipe 	pipe_struct;
	char	*entered_line;
	// handlers

	while (1)
	{
		entered_line = read_a_line(SHELL_PROMPT);

		// testing of readline
		printf("%s\n", entered_line);
		add_history(entered_line);
		free(entered_line);
		continue ;

		// pipe_struct = parse_line(entered_line);
		// execute_line(pipe_struct);
	}

	return (0);
}
