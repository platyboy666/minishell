/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkorsako <pkorsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:37:34 by pkorsako          #+#    #+#             */
/*   Updated: 2023/08/18 15:12:28 by pkorsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../inc/minishell.h"
#include "petit_shell.h"
char *line;

static int	ft_is_in_charset(char c, char const *set)
{
	unsigned long	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static unsigned long	ft_count_to_trim(char const *s1, char const *set)
{
	unsigned long	i;
	unsigned long	count;
	unsigned long	len_s1;

	i = 0;
	count = 0;
	if (s1[0] == '\0')
		return (0);
	len_s1 = ft_strlen(s1);
	while (ft_is_in_charset(s1[i], set))
	{
		count++;
		i++;
	}
	while (ft_is_in_charset(s1[--len_s1], set))
		count++;
	return (count);
}

static signed long	ft_last_nonset_index(char const *s1, char const *set)
{
	signed long	index;

	if (s1[0] == '\0')
		return (0);
	index = ft_strlen(s1) - 1;
	while (ft_is_in_charset(s1[index], set) && s1[index])
		index--;
	return (index);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*trimmed_str;
	signed long	i;
	signed long	j;

	if (!s1)
		return (NULL);
	if (ft_last_nonset_index(s1, set) == -1)
		return (ft_strdup(""));
	trimmed_str = ft_malloc(sizeof(char)
			* (ft_strlen(s1) - ft_count_to_trim(s1, set) + 1), ALLOC);
	if (!trimmed_str)
		return (NULL);
	i = 0;
	j = 0;
	while (ft_is_in_charset(s1[i], set))
		i++;
	while (i <= ft_last_nonset_index(s1, set))
	{
		trimmed_str[j] = s1[i];
		j++;
		i++;
	}
	if (s1[0] != '\0')
		trimmed_str[j] = '\0';
	return (trimmed_str);
}

void	free_garbage(t_garbage *alloc_elements)
{
	t_garbage *index;

	alloc_elements = alloc_elements->next;
	index = alloc_elements;
	while(alloc_elements)
	{
		index = alloc_elements;
		free(alloc_elements->element);
		alloc_elements = alloc_elements->next;
		free(index);
	}
}

void	upgrade_list(t_garbage *alloc_elements, void *allocated_element)
{
	t_garbage	*new_struct;
	t_garbage	*index;
	
	new_struct = malloc(sizeof(t_garbage));
	if(!new_struct)
	{
		ft_malloc(0, FREE);
		exit(1);
	}
	index = alloc_elements;
	while (index->next)
		index = index->next;
	index->next = new_struct;
	new_struct->element = allocated_element;
	new_struct->next = NULL;
}

void	*ft_malloc(size_t byte_size, int action)
{
	static t_garbage	alloc_elements;
	void				*allocated_element;
	
	if (action == FREE)
		free_garbage(&alloc_elements);
	else
	{
		allocated_element = malloc(byte_size);
		if (!allocated_element)
			ft_malloc(0, FREE);
		upgrade_list(&alloc_elements, allocated_element);
		return (allocated_element);
	}
	return (NULL);
}

void	whitch_builtin(char *line, t_env *env)//strtrim ' ' + strnstr ?
{
	line = ft_strtrim(line, " ");//enleve les space avant et après
	if (!ft_strcmp(line, "pwd"))
		pwd();
	if (ft_strnstr(line, "echo", 5))//strnstr marche mieux que strcmp
	 	echo(next_word(line), 1, env);
	if (!ft_strcmp(line, "env"))
		ft_env(env);
	if (ft_strnstr(line, "export", 6))
		ft_export(env, line);
	if (ft_strnstr(line, "unset", 5))
		ft_unset(env, line);
	if (ft_strnstr(line, "cd", 2))
		cd(line);
	if (ft_strnstr(line, "exit", 5))
		ft_exit();
}

void	routine(t_env *env)
{
	char	*line;
	int		i;
	
	line = readline("le_mien :>");
	if (line == NULL)
		exit(1);	//ctr^d pressed
	add_history(line);// fait l'historique tout seul ?
	whitch_builtin(line, env);
}

int main(int argc, char **argv, char **envp)
{
	char	*line;
	struct sigaction sig;
	t_env	*env;
	int i = 0;
	
	line = NULL;
	env = create_env(envp);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = &signal_handler;
	sigemptyset(&sig.sa_mask);
	while (1)
	{
		sigaction(SIGQUIT, &sig, NULL);
		sigaction(SIGINT, &sig, NULL);
		routine(env);

	}
	rl_clear_history();// réduit les leaks de realine
	return (1);
}
