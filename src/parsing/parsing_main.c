/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbock <fbock@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:03:45 by fbock             #+#    #+#             */
/*   Updated: 2024/01/05 08:36:49 by fbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
				return (free_all_argvs(&p));
			skip_whitespace(&p);
		}
		if (!parse_delimiter(&p))
			return (free_all_argvs(&p));
		if (p.new_proc)
			p.task->p_amount++;
	}
	p.task->p_amount++;
	return (true);
}
