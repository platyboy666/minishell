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

void	signal_handler(int signum, siginfo_t *siginfo, void *other)
{
	printf("sig :%d\n", signum);
	exit(1);
}