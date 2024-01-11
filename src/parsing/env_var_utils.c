/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbock <fbock@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:46:10 by fbock             #+#    #+#             */
/*   Updated: 2024/01/11 10:29:55 by fbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fill_buffer(char *buffer, size_t buffer_s,
					char *string, size_t *str_index)
{
	size_t	buffer_i;

	buffer_i = 0;
	ft_memset(buffer, '\0', buffer_s);
	if (buffer_i < buffer_s && string && string[*str_index] == '?')
		buffer[buffer_i++] = string[(*str_index)++];
	while (buffer_i < buffer_s
		&& string && ft_isalnum(string[*str_index]))
	{
		buffer[buffer_i++] = string[(*str_index)++];
	}
}

bool	parse_env_var(t_parsing *p)
{
	char		buffer[PROC_FIELD_BUFFER];
	char		***current_argv;

	p->inp_i++;
	current_argv = &(p->task->processes[p->task->p_amount].argv);
	fill_buffer(buffer, PROC_FIELD_BUFFER, p->u_input, &(p->inp_i));
	if (ft_strlen(buffer) == 0)
	{
		*current_argv = append_string(*current_argv, "$");
		if (!(*current_argv))
			return (false);
		if (p->u_input[p->inp_i])
			p->inp_i++;
		return (true);
	}
	return (fetch_env_var(buffer, current_argv));
}