/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handleur.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:02:58 by marvin            #+#    #+#             */
/*   Updated: 2023/04/02 18:02:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "petit_shell.h"
// #include "../inc/minishell.h"
void	ft_bzero(char *line)
{
	int i = 0;

	while(line[i])
	{
		line = 0;
		i ++;
	}
}

void	signal_handler(int signum, siginfo_t *siginfo, void *other)
{
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	// write(1, "\b", 2);
	// kill(siginfo->si_pid, SIGUSR1);
	// printf("sig :%d\n", signum);
	// routine();
	// exit(1);
}