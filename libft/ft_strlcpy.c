/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkorsako <pkorsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:57:00 by pkorsako          #+#    #+#             */
/*   Updated: 2023/01/26 19:12:03 by pkorsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (*src == '\0' && size != 0)
		*dest = '\0';
	if (size == 0)
		return (ft_strlen(src));
	while (*(src + i) != '\0' && i < (size - 1))
	{
		*(dest + i) = *(src + i);
		i ++;
	}
	*(dest + i) = '\0';
	return (ft_strlen(src));
}
