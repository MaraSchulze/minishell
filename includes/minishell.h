/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbock <fbock@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:07:45 by fbock             #+#    #+#             */
/*   Updated: 2023/12/18 13:39:23 by fbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>
#include <stdbool.h>
#include <signal.h>
#include <sys/stat.h>
#include <string.h>
#include <termios.h>

typedef struct s_process {
	char *name;
	char **argv;
	char **env;
}	t_process;

typedef struct s_pipe {
	t_process	*processes;
	size_t		p_amount;
	char 		*input_file;
	char		*output_file;
}	t_pipe;

// input_utils.c
char	*read_a_line(char *prompt);
