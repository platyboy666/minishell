/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkorsako <pkorsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 00:27:05 by pkorsako          #+#    #+#             */
/*   Updated: 2023/01/26 19:11:24 by pkorsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putstr_fd(char *c, int fd)
{
	int	r;

	if (c)
	{
		r = ft_strlen(c);
		while (*c != 0)
		{
			ft_putchar_fd(*c, fd);
			c ++;
		}
		return (r);
	}
	else
		ft_putstr_fd("(null)", 1);
	return (6);
}
