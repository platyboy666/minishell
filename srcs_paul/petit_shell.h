/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   petit_shell.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkorsako <pkorsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:42:51 by pkorsako          #+#    #+#             */
/*   Updated: 2023/10/14 16:36:07 by pkorsako         ###   ########.fr       */
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
# define YES 1
# define NO 0
# define UPDATE 1

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

typedef struct s_data
{
	char	**cmd_lines;
	char	**separator;
	t_env	*env;
	t_env	*second_element;
}	t_data;

void	signal_handler(int signum, siginfo_t *info, void *other);
void	routine();
void	*ft_malloc(size_t byte_size, int action);

t_env	*create_env(char **envp);

void	ft_env(t_env *env);
void	pwd(void);
void	echo(char *str, char option, t_env *env);
void	ft_exit();
void	cd(char *str);
int	ft_strcmp(const char *s1, const char *s2);
char	*ft_strnstr(const char *big, const char *little, size_t len);
void	ft_export(t_env *env, char *data);
char	*remove_extra_space(char *line);
size_t	ft_strlen(const char *string);
char	*ft_strdup(const char *s);
char	*next_word(char *str);
t_env	*ft_unset(t_env *env, char *rm_data);
t_data	*parsing(char *get_line, char **envp);
int		how_much_cmd(char *line);
char *get_path(t_env *env);

#endif
