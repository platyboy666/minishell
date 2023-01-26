/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkorsako <pkorsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:39:49 by pkorsako          #+#    #+#             */
/*   Updated: 2023/01/26 19:11:36 by pkorsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	j;

	i = 0;
	j = (char)c;
	while (i < ft_strlen(s))
	{
		if (*(s + i) == j)
			return (((char *)s + i));
		i ++;
	}
	if (*(s + i) == j)
		return (((char *)s + i));
	return (0);
}
