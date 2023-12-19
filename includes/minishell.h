/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbock <fbock@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:07:45 by fbock             #+#    #+#             */
/*   Updated: 2023/12/19 10:07:13 by fbock            ###   ########.fr       */
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
#include "libft.h"

#define SHELL_PROMPT "minishell$ "
#define	CWD_BUFFER_SIZE 1000

typedef struct s_parsing {
	char **tokens;
}	t_parsing;

typedef struct s_process {
	char 	*name;
	char 	**argv;
	char 	**env;
}	t_process;

typedef struct s_pipe {
	t_process	*processes;
	size_t		p_amount;
	char 		*input_file;
	char		*output_file;
}	t_pipe;

// input_utils.c
char	*read_a_line(char *prompt);

// echo.c
bool	echo(const char *after_echo, bool n_flag);

// cd.c
bool	cd(char *entered_path_arg);

// pwd.c
bool	pwd(void);

// export.c
bool	export_one_pair(char *env_pair);
void	free_old_env(char **old_env);
size_t	get_env_length(void);

// unset.c
bool	unset(char *variable_name);

// env.c
bool	env(void);
