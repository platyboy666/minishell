/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:30:30 by claclau           #+#    #+#             */
/*   Updated: 2023/03/14 15:13:13 by claclau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../lib/libft/libft.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# define ALLOC 1	//define pour le gc
# define FREE 0

typedef struct s_garbage //struct pour le gc
{
	void	*element;
	void	*next;
}	t_garbage;

typedef struct s_cmd
{
	char	*line; // ATTENTION ca c'est malloced, penser a free
	int		fd_in;
	int		fd_out;
}			t_cmd;

typedef struct s_data
{
	char	*line;
	char	**envp;
	char	**paths;
	int		nb_cmds;
	t_cmd	*cmds;
	char	**cmd_options; // here or in s_cmd ?
}			t_data;

// main.c
int		init_data(t_data *data, char **envp, char *line);
void	free_arr(char **arr);
void	free_data(t_data *data);

// parsing.c
int		nb_pipes(char *line);
int		split_piped_cmds(char *line, t_data *data);
int		fill_cmd_line(t_cmd *cmd, char *line, int cmd_start, int cmd_end);

// envp_path.c
char	*get_path_line(char **envp);
int		retrieve_paths(t_data *data);

// cmd_utils.c
int		get_cmd_options(char *cmd, t_data *data);
int		check_access(char *pathname);
int		exec_cmd(char *cmd, t_data *data);

// builtins.c
void	pwd(void);
void	echo(char *str, char option);
void	env(char **envp);

#endif
