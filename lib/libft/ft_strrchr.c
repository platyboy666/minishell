/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:50:32 by claclau           #+#    #+#             */
/*   Updated: 2022/02/04 18:49:22 by claclau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	res;

	i = 0;
	res = -1;
	while (s[i])
	{
		if (s[i] == (char)c)
			res = i;
		i++;
	}
	if (res != -1)
		return ((char *)s + res);
	if (c == '\0')
		return ((char *)s + i);
	return (0);
}
