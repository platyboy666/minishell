/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkorsako <pkorsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:21:20 by pkorsako          #+#    #+#             */
/*   Updated: 2023/01/26 19:09:19 by pkorsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;

	while (*s && start)
	{
		s++;
		start--;
	}
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s, len + 1);
	return (dest);
}
