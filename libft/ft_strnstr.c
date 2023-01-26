/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkorsako <pkorsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:54:37 by pkorsako          #+#    #+#             */
/*   Updated: 2023/01/26 19:12:17 by pkorsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[j] != 0 && j < len)
	{
		i = 0;
		while (haystack[j + i] == needle[i] && i + j < len)
		{
			i++;
			if (needle[i] == '\0' && len != 0)
				return ((char *) &haystack[j]);
		}
		j++;
	}
	return (0);
}
