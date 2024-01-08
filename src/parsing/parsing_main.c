/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbock <fbock@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:03:45 by fbock             #+#    #+#             */
/*   Updated: 2024/01/08 11:42:45 by fbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	create_new_process(t_parsing *p)
{
	p->task->p_amount++;
	p->task->processes[p->task->p_amount].argv = NULL;
	p->task->processes[p->task->p_amount].io_amount = 0;
}

bool	parsing_main(char *input, t_pipe *task)
{
	t_parsing	p;

	init_parsing_data(&p, task, input);
	while (input && input[p.inp_i])
	{
		skip_whitespace(&p);
		if (p.new_proc && input[p.inp_i] &&
			!ft_isdelimiter(input[p.inp_i]))
		{
			if (!parse_name(&p))
				return (free_all_argvs(p.task));
			skip_whitespace(&p);
		}
		if (!parse_delimiter(&p))
			return (free_all_argvs(p.task));
		if (p.new_proc)
			create_new_process(&p);
	}
	create_new_process(&p);
	return (true);
}
