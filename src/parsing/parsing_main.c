/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbock <fbock@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:17:21 by fbock             #+#    #+#             */
/*   Updated: 2023/12/20 10:20:29 by fbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_process	*alloc_task(char *name, char **argv)
{
	t_process	*task;

	task = malloc(sizeof(t_process));
	if (!task)
		return (NULL);
	task->name = malloc(ft_strlen(name) * sizeof(char));
	if (!task->name)
	{
		free(task);
		return (NULL);
	}
	// task->argv = malloc();
}

bool	contains_delimiter(char *string)
{
	while (string && *string)
	{
		if (ft_isdelimiter(*string))
			return (true);
		string++;
	}
	return (false);
}

bool	ft_isdelimiter(char c)
{
	if (c == '|' || c == '<' || c == '>' || c == 39 || c == '"')
		return (true);
	return (false);
}

void	parse_delimiter(char **rem_tokens, t_pipe *task)
{
	char	before_buffer[1000];
	char	after_buffer[1000];
	size_t	index = 0;

	while (**rem_tokens && !ft_isdelimiter(**rem_tokens))
	{
		before_buffer[index] = **rem_tokens;
		(*rem_tokens)++;
	}

}



// non functional prototype
bool	parse_line(char *entered_line, t_pipe *task)
{
	char		name_buf[PROC_FIELD_BUFFER];
	char		argv_buf[PROC_FIELD_BUFFER];
	size_t		proc_i;

	proc_i = 0;
	while (entered_line && *entered_line)
	{

	}

	return (true);
}

// bool	check_builtin(t_parsing *input)
// {
// 	if (ft_strcmp(*(input->tokens), "cd") == 0)
// 		cd(*(++input->tokens));
// 	else if (ft_strcmp(string, "echo") == 0)
// 	{

// 	}
// 	else if (ft_strcmp(string, "env") == 0)
// 	{

// 	}
// 	else if (ft_strcmp(string, "export") == 0)
// 	{

// 	}
// 	else if (ft_strcmp(string, "pwd") == 0)
// 	{

// 	}
// 	else if (ft_strcmp(string, "unset") == 0)
// 	{

// 	}
// 	return (false);
// }
