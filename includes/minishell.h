/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:07:45 by fbock             #+#    #+#             */
/*   Updated: 2023/12/27 12:22:57 by marschul         ###   ########.fr       */
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
#include <assert.h>
// #include <stdint.h>
#include "../libs/libft/includes/libft.h"

#define SHELL_PROMPT "minishell$ "
#define	CWD_BUFFER_SIZE 1000
#define	PROC_FIELD_BUFFER 1000
#define MAX_PROC_AMOUNT 1000

typedef bool (*t_function_pointer)(char **argv);

typedef struct s_process {
	char 	*name;
	char 	**argv;
	char	**env;
	t_function_pointer	builtin;
}	t_process;

typedef struct s_pipe {
	t_process	processes[MAX_PROC_AMOUNT];
	size_t		p_amount;
	char 		*input_file;  //NULL
	char		*here_file;
	char		*output_file;
	char		*output_file_append;
	int			last_exit_value;
}	t_pipe;

typedef struct s_parsing {
	char	buffer[PROC_FIELD_BUFFER];
	char	*entered_line;
	size_t	line_i;
	size_t	buffer_i;
	bool	new_proc;
	t_pipe	*task;
}	t_parsing;

// input_utils.c
char	*read_a_line(char *prompt);

// builtins
bool	echo(char **argv);
bool	cd(char **argv);
bool	pwd(char **argv);
bool	export_one_pair(char *env_pair);
void	free_old_env(char **old_env);
size_t	get_env_length(void);
bool	export(char **argv);
bool	unset(char **argv);
bool	env(char **argv);

// parsing.c
bool	parse_line(char *entered_line, t_pipe *task);

// execute line
int	execute_line(t_pipe *pipe_struct);

// parsing_utils.c
char 	**append_string(char **orig, char *str);
bool	ft_isdelimiter(char c);
bool	parse_placeholder(t_parsing *pd);

// helper_functions.c
bool	error_wrapper(void);

// in_out_parsing.c
bool	parse_infile(t_parsing *pd);
bool	parse_outfile(t_parsing *pd);
bool	parse_heredoc(t_parsing *pd);
