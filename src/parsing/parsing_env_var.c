/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_env_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbock <fbock@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:01:57 by fbock             #+#    #+#             */
/*   Updated: 2024/01/05 08:52:47 by fbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	fetch_env_var(t_parsing *p, char *buffer, char ***current_argv)
{
	char	*env_var;

	env_var = getenv(buffer);
	if (env_var == NULL)
		return (true);
	*current_argv = append_string(*current_argv, env_var);
	if (!(*current_argv))
		return (false);
	return (true);
}

void	fill_buffer(char *buffer, size_t buffer_s,
					char *string, size_t *str_index)
{
	size_t	buffer_i;

	buffer_i = 0;
	ft_memset(buffer, '\0', buffer_s);
	while (buffer_i < buffer_s &&
			string && ft_isalnum(string[*str_index]))
	 	buffer[buffer_i++] = string[(*str_index)++];
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
		p->inp_i++;
		return (true);
	}
	return (fetch_env_var(p, buffer, current_argv));
}

static void	parse_dq_assignment(t_parsing *p, char *assignment_buffer,
								size_t *ass_buff_i)
{
	char	env_key_buffer[PROC_FIELD_BUFFER];
	char	*env_var;

	p->inp_i++;
	if (p->u_input[p->inp_i] == ' ' || p->u_input[p->inp_i] == '"')
	{
		assignment_buffer[(*ass_buff_i)++] = '$';
		return ;
	}
	fill_buffer(env_key_buffer, PROC_FIELD_BUFFER,
							p->u_input, &(p->inp_i));
	env_var = getenv(env_key_buffer);
	if (env_var != NULL)
	{
		ft_strlcat(assignment_buffer, env_var, PROC_FIELD_BUFFER);
		*ass_buff_i += ft_strlen(env_var);
	}
}
// needs to be tested, not done yet
void	parse_env_assignment(t_parsing *p, char *buffer, size_t *buffer_i)
{
	buffer[(*buffer_i)++] = p->u_input[p->inp_i++];
	if (p->u_input[p->inp_i] == 39)  // value in single quotes -> parse as chars
	{
		p->inp_i++;
		while (p->u_input[p->inp_i] && p->u_input[p->inp_i] != ' '
				&& p->u_input[p->inp_i] != 39)
			buffer[(*buffer_i)++] = p->u_input[p->inp_i++];
		p->inp_i++;
	}
	else if (p->u_input[p->inp_i] == '"')  // value in double quotes -> parse env vars
	{
		p->inp_i++;
		while (p->u_input[p->inp_i] && p->u_input[p->inp_i] != '"')
		{
			if (p->u_input[p->inp_i] == '$')
				parse_dq_assignment(p, buffer, buffer_i);
			else
				buffer[(*buffer_i)++] = p->u_input[p->inp_i++];
		}
		p->inp_i++;
	}
	else if (ft_isalnum(p->u_input[p->inp_i]))  // value without quotes
	{
		while (p->u_input[p->inp_i] && p->u_input[p->inp_i] != ' ')
			buffer[(*buffer_i)++] = p->u_input[p->inp_i++];
	}
}
