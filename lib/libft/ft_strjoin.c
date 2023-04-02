/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:30:23 by claclau           #+#    #+#             */
/*   Updated: 2022/02/03 16:30:24 by claclau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*join_str;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	join_str = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!join_str)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		join_str[i] = s1[i];
		i++;
	}
	while (i < len_s1 + len_s2)
	{
		join_str[i] = s2[i - len_s1];
		i++;
	}
	join_str[i] = '\0';
	return (join_str);
}
