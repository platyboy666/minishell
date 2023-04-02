/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 20:54:51 by claclau           #+#    #+#             */
/*   Updated: 2022/11/03 15:03:49 by claclau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

size_t	ft_strlen2(const char *string)
{
	size_t	len;

	len = 0;
	if (!string)
		return (0);
	while (string && string[len])
		len++;
	return (len);
}

char	*ft_strdup2(const char *s)
{
	size_t	str_len;
	size_t	i;
	char	*dup_str;

	str_len = ft_strlen2(s);
	i = 0;
	dup_str = malloc(sizeof(char) * (str_len + 1));
	if (dup_str == NULL)
		return (NULL);
	if (!s)
		return (dup_str);
	while (s[i])
	{
		dup_str[i] = s[i];
		i++;
	}
	dup_str[i] = '\0';
	return (dup_str);
}

char	*ft_substr2(char *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen2(s))
		return (free(s), ft_strdup2(""));
	if (len > ft_strlen2(s) - start)
		len = ft_strlen2(s) - start;
	substr = malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (free(s), NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	free(s);
	return (substr);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*join_str;
	size_t	i;

	if (!s1)
		s1 = ft_strdup2("");
	len_s1 = ft_strlen2(s1);
	len_s2 = ft_strlen2(s2);
	join_str = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!join_str)
		return (free(s1), NULL);
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
	return (free(s1), join_str);
}

char	*ft_strchr2(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	return (0);
}
