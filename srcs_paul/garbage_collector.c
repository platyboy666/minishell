/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulk <paulk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:37:34 by pkorsako          #+#    #+#             */
/*   Updated: 2023/04/23 12:22:14 by paulk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../inc/minishell.h"
#include "petit_shell.h"
char *line;

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

// void ctr_c(int sig)
// {
// 	if (sig == SIGUSR1)
// 		return (1);
// 	else 
// 		return (-1);
// }

void	routine()
{
	char	*line;
	int		i;
	line = readline("le_mien :>");
	if (line != NULL)
		printf("%s\n", line);
	else
		exit(1); //ctr^d pressed ?
	// if (signal(SIGUSR1, &ctr_c))
	// {	
	// 	write(1, "NA\n", 3);
	// 	return ;
	// }
}

int main()
{
	char	*line;
	struct sigaction sig;
	int i = 0;
	
	line = NULL;
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = &signal_handler;
	sigemptyset(&sig.sa_mask);
	line = readline("le_mien :>");
	while (i < 5)
	{
		sigaction(SIGQUIT, &sig, NULL);
		sigaction(SIGINT, &sig, NULL);
		routine();
		// line = readline("le_mien");
		// printf("%s\n", line);
		i ++;
	}
	return (1);
}
