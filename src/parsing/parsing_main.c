/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbock <fbock@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:17:21 by fbock             #+#    #+#             */
/*   Updated: 2023/12/18 15:17:38 by fbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	parse_line(char *entered_line, t_pipe parsed_command)
{
	pipe_struct	parsed_args;
	char		**tokens;

	tokens = ft_split(entered_line, ' ');

	while (*tokens)  // check if token is builtin before creating processes...
	{
		return (true);
	}
}
