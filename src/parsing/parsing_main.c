/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbock <fbock@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:38:28 by fbock             #+#    #+#             */
/*   Updated: 2023/12/20 17:53:24 by fbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	isolate_name(char *entered_line, int *line_i, char *buffer)
{
	size_t	buffer_i;

	buffer_i = 0;
	while (entered_line[*line_i] && !ft_isdelimiter(entered_line[*line_i]))
	{
		buffer[buffer_i] = entered_line[*line_i];
		buffer_i++;
		(*line_i)++;
	}
	buffer[buffer_i] = '\0';
}

void	parse_quote(char *entered_line, int *line_i, t_pipe *task, char *buffer)
{

}

static void	check_rest(char *entered_line, int *line_i, t_pipe *task, char *buffer)
{
	size_t	buffer_i;

	buffer_i = 0;
	buffer[0] = '\0';
	if (entered_line[*line_i] == ' ')
	{
		(*line_i)++;
		while (!ft_isdelimiter(entered_line[*line_i]))
		{
			buffer[buffer_i++] = entered_line[*line_i];
			(*line_i)++;
		}
		buffer[buffer_i] = '\0';
		if (ft_strlen(buffer) > 0)
			task->processes[task->p_amount].argv = append_string(task->processes[task->p_amount].argv, buffer);
	}
	else if (entered_line[*line_i] == 39)
	{
		(*line_i)++;
		while (entered_line[*line_i] && entered_line[*line_i] != 39)
		{
			buffer[buffer_i++] = entered_line[*line_i];
			(*line_i)++;
		}
		buffer[buffer_i] = '\0';
		if (ft_strlen(buffer) > 0)
			task->processes[task->p_amount].argv = append_string(task->processes[task->p_amount].argv, buffer);
	}
	else if (entered_line[*line_i] == '"')
	{
		(*line_i)++;
		while (entered_line[*line_i] && entered_line[*line_i] != '"')
		{
			if (entered_line[*line_i] == '$')
				parse_placeholder(entered_line, line_i, &buffer_i, buffer);
			else
			{
				buffer[buffer_i++] = entered_line[*line_i];
				(*line_i)++;
			}
		}
		buffer[buffer_i] = '\0';
		if (ft_strlen(buffer) > 0)
			task->processes[task->p_amount].argv = append_string(task->processes[task->p_amount].argv, buffer);
	}
	else if (entered_line[*line_i] == '$')
		parse_placeholder(entered_line, line_i, &buffer_i, buffer);
	return (false);
}

bool	parse_line(char *entered_line, t_pipe *task)
{
	char	buffer[PROC_FIELD_BUFFER];
	size_t	line_i;
	bool	new_proc;

	line_i = 0;
	new_proc = true;
	while (entered_line && entered_line[line_i])
	{
		// isolate name
		if (new_proc)
		{
			isolate_name(entered_line, &line_i, buffer);
			new_proc = false;
			task->processes[task->p_amount].name = ft_strdup(buffer);
		}
		if (entered_line[line_i] == '|')
		{
			//
			new_proc = true;
		}
		else
		{
			check_rest(entered_line, line_i, task, buffer);
		}
	}

}
