/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   petit_shell.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulk <paulk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:42:51 by pkorsako          #+#    #+#             */
/*   Updated: 2023/05/05 12:58:37 by paulk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PETIT_SHELL_H
# define PETIT_SHELL_H
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# define ALLOC 1
# define FREE 0

extern char *line;

typedef struct s_garbage
{
	void	*element;
	void	*next;
}	t_garbage;

typedef struct s_env
{
	char			*data;
	struct s_env	*next;
}	t_env;

void	signal_handler(int signum, siginfo_t *info, void *other);
void	routine();
void	*ft_malloc(size_t byte_size, int action);

t_env	*create_env(char **envp);

void	ft_env(t_env *env);
void	pwd(void);
void	echo(char *str, char option);
void	ft_exit(int i);
void	cd(char *str);
int	ft_strcmp(const char *s1, const char *s2);
void	ft_export(t_env *env);


#endif
