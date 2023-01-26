/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkorsako <pkorsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:36:32 by pkorsako          #+#    #+#             */
/*   Updated: 2023/01/26 19:12:20 by pkorsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	j;

	j = (char)c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (*(s + i) == j)
			return ((char *)s + i);
		i --;
	}
	return (0);
}
