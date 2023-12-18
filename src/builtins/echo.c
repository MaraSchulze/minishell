/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbock <fbock@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:58:11 by fbock             #+#    #+#             */
/*   Updated: 2023/12/18 15:12:11 by fbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// takes the string to print after the echo command, or after -n if existing
// if -n exists, newline is false. ENV variables have to be placed in the
// string beforehand.
bool	echo(const char *after_echo, bool n_flag)
{
	if (!n_flag)
		printf("%s\n", after_echo);
	else
		printf("%s", after_echo);
}
