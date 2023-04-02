/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 20:52:07 by claclau           #+#    #+#             */
/*   Updated: 2022/09/12 20:52:27 by claclau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "get_next_line.h"

void	free_malloc(char **str, char **str2)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
	if (str2 && *str2)
	{
		free(*str2);
		*str2 = NULL;
	}
}

char	*get_new_line(char *to_keep)
{
	int		i;
	char	*newline;

	if (!to_keep)
		return (NULL);
	i = 0;
	while (to_keep[i] && to_keep[i] != '\n')
		i++;
	if (to_keep[i] && to_keep[i] == '\n')
		i++;
	newline = ft_substr2(to_keep, 0, i);
	return (newline);
}

char	*read_buffer_line(int fd, char *to_keep)
{
	char	*buffer;
	int		cr_found;
	int		read_ret;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	cr_found = 0;
	read_ret = 1;
	while (!cr_found && read_ret > 0)
	{
		read_ret = read(fd, buffer, BUFFER_SIZE);
		if (read_ret == -1)
			return (free(buffer), free(to_keep), NULL);
		buffer[read_ret] = '\0';
		to_keep = ft_strjoin2(to_keep, buffer);
		if (ft_strchr2(to_keep, '\n'))
			cr_found = 1;
	}
	free(buffer);
	return (to_keep);
}

char	*get_next_line(int fd)
{
	static char	*to_keep;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, NULL, 0) == -1)
		return (NULL);
	to_keep = read_buffer_line(fd, to_keep);
	line = get_new_line(ft_strdup2(to_keep));
	to_keep = ft_substr2(to_keep, ft_strlen2(line),
			ft_strlen2(to_keep) - ft_strlen2(line));
	if (!line || *line == '\0')
	{
		free_malloc(&to_keep, &line);
		return (NULL);
	}
	return (line);
}
