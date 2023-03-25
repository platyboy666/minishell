/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   petit_shell.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkorsako <pkorsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:42:51 by pkorsako          #+#    #+#             */
/*   Updated: 2023/03/25 14:48:34 by pkorsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PETIT_SHELL.H
# define PETIT_SHELL.H

typedef struct s_garbage
{
	void	*element;
	t_garbage	*next;
}	t_garbage;

#endif
