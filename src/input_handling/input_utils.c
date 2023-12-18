/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbock <fbock@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:38:47 by fbock             #+#    #+#             */
/*   Updated: 2023/12/18 13:39:10 by fbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *read_a_line(char *prompt)
{
	char	*entered_line;

	while (1)
	{
		entered_line = readline(prompt);
		if (!entered_line)
			continue ;
		if (!(*entered_line))
		{
			free(entered_line);
			continue ;
		}
		break ;
	}
	return (entered_line);
}
