/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   petit_shell.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:42:51 by pkorsako          #+#    #+#             */
/*   Updated: 2023/04/02 18:55:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PETIT_SHELL_H
# define PETIT_SHELL_H
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <signal.h>
# define ALLOC 1
# define FREE 0

typedef struct s_garbage
{
	void	*element;
	void	*next;
}	t_garbage;

void	signal_handler(int signum, siginfo_t *info, void *other);
void	*ft_malloc(size_t byte_size, int action);

#endif
