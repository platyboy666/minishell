/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkorsako <pkorsako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:32:40 by pkorsako          #+#    #+#             */
/*   Updated: 2023/01/26 19:11:39 by pkorsako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s)
{
	char	*s2;

	s2 = malloc((sizeof (char)) * ft_strlen(s) + 1);
	if (s2 == 0)
		return (0);
	ft_strlcpy(s2, s, (ft_strlen(s) + 1));
	return (s2);
}
