/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:42:42 by claclau           #+#    #+#             */
/*   Updated: 2023/03/14 12:28:50 by claclau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	get_cmd_options(char *cmd, t_data *data)
{
	data->cmd_options = ft_split(cmd, ' ');
	if (!data->cmd_options)
		return (1);
	return (0);
}

int	check_access(char *pathname)
{
	return (access(pathname, F_OK | X_OK) != 0);
}

int	exec_cmd(char *cmd, t_data *data)
{
	int	i;

	if (get_cmd_options(cmd, data))
		return (1);
	if (check_access(data->cmd_options[0]) == 0)
	{
		execve(data->cmd_options[0], data->cmd_options, data->envp);
		perror("execve");
		return (-1);
	}
	// checker si executable existe mais n'est pas executable ?
	i = -1;
	if (retrieve_paths(data))
		return (1);
	while (data->paths[++i])
	{
		// checker l'access ?
		execve(data->paths[i], data->cmd_options, data->envp);
	}
	return (printf("Erreur cmd not found\n"), 2);
}
