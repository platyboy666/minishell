/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:31:58 by claclau           #+#    #+#             */
/*   Updated: 2022/02/05 15:10:03 by claclau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	if (size <= 0)
		return (ft_strlen(src));
	if (size < dst_len)
		return (ft_strlen(src) + size);
	i = 0;
	while (dst_len + i < size -1)
	{
		dst[dst_len + i] = src[i];
		if (src[i] == '\0')
			return (dst_len + i);
		i++;
	}
	dst[i + dst_len] = '\0';
	if (dst_len > size)
		return (size + ft_strlen(src));
	return (dst_len + ft_strlen(src));
}
