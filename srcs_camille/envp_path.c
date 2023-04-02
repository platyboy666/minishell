/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:38:12 by claclau           #+#    #+#             */
/*   Updated: 2023/03/14 12:29:22 by claclau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*get_path_line(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i]);
		i++;
	}
	return (NULL);
}

int	retrieve_paths(t_data *data)
{
	int		i;
	char	*path_line;
	char	*tmp;

	path_line = get_path_line(data->envp);
	if (!path_line)
		return (1);
	data->paths = ft_split(path_line + 5, ':');
	if (!data->paths)
		return (2);
	i = 0;
	while (data->paths[i])
	{
		tmp = data->paths[i];
		data->paths[i] = ft_strjoin(data->paths[i], "/");
		if (!data->paths[i])
			return (free(tmp), 3);
		free(tmp);
		tmp = data->paths[i];
		data->paths[i] = ft_strjoin(data->paths[i], data->cmd_options[0]);
		if (!data->paths[i])
			return (free(tmp), 4);
		free(tmp);
		i++;
	}
	return (0);
}
