/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkorsako <pkorsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:10:43 by pkorsako          #+#    #+#             */
/*   Updated: 2023/01/26 19:10:04 by pkorsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	j;

	j = 0;
	i = 0;
	n = 1;
	while ((str[j] >= 9 && str[j] <= 13) || str[j] == 32)
		j ++;
	if (str[j] == '-' || str[j] == '+')
	{
		if (str[j] == '-')
			n *= -1;
		j ++;
	}
	while (str[j] != 0 && ft_isdigit(str[j]))
	{
		i += (str[j] - 48);
		j ++;
		if (str[j] != 0 && ft_isdigit(str[j]) != 0)
			i = i * 10;
	}
	return (i * n);
}
