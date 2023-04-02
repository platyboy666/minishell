/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:30:54 by claclau           #+#    #+#             */
/*   Updated: 2022/02/05 15:38:12 by claclau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_nb(int n)
{
	int	len;

	len = 1;
	while (n / 10 != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res_str;
	int		len_nb;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len_nb = ft_len_nb(n);
	if (n < 0)
		len_nb++;
	res_str = malloc(sizeof(char) * (len_nb + 1));
	if (!res_str)
		return (NULL);
	res_str[len_nb] = '\0';
	if (n == 0)
		res_str[0] = '0';
	if (n < 0)
	{
		res_str[0] = '-';
		n = -n;
	}
	while (n != 0)
	{
		res_str[--len_nb] = n % 10 + 48;
		n /= 10;
	}
	return (res_str);
}
