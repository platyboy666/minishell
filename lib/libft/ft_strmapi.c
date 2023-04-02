/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:31:38 by claclau           #+#    #+#             */
/*   Updated: 2022/02/03 16:36:00 by claclau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res_str;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	res_str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!res_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res_str[i] = f(i, s[i]);
		i++;
	}
	res_str[i] = '\0';
	return (res_str);
}
