/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkorsako <pkorsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:33:33 by pkorsako          #+#    #+#             */
/*   Updated: 2023/01/26 19:12:00 by pkorsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	r;
	size_t	i;

	i = 0;
	r = ft_strlen(dest);
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] != 0 && (r + i) < size - 1)
	{
		dest[r + i] = src[i];
		i ++;
	}
	dest[r + i] = 0;
	if (size > r)
		size = r;
	return (ft_strlen(src) + size);
}
