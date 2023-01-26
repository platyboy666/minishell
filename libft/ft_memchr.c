/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkorsako <pkorsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:28:07 by pkorsako          #+#    #+#             */
/*   Updated: 2023/01/26 19:10:54 by pkorsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;

	str = (void *)s;
	while (n && *str != (char)c)
	{
		str++;
		n--;
	}
	if (!n)
		return (NULL);
	return (str);
}
