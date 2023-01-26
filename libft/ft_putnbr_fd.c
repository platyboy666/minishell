/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkorsako <pkorsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 00:55:43 by pkorsako          #+#    #+#             */
/*   Updated: 2023/01/26 19:11:20 by pkorsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putnbr_fd(long int n, int fd, int r)
{
	int long	m;
	int			i;

	i = 0;
	m = n;
	if (m < 0)
	{
		i = 1;
		ft_putchar_fd('-', fd);
		m *= -1;
	}
	if (m >= 10)
		r = ft_putnbr_fd(m / 10, fd, r);
	m %= 10;
	ft_putchar_fd(m + '0', fd);
	return (r + i + 1);
}
