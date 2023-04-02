/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:03:26 by claclau           #+#    #+#             */
/*   Updated: 2023/03/14 14:44:49 by claclau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	init_data(t_data *data, char **envp, char *line)
{
	data->line = line;
	data->envp = envp;
	data->paths = NULL;
	data->nb_cmds = nb_pipes(line) + 1;
	data->cmds = malloc(sizeof(t_cmd) * data->nb_cmds);
	if (!data->cmds)
		return (perror("malloc"), 1);
	data->cmd_options = NULL;
	return (0);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	if (data->paths)
		free_arr(data->paths);
	if (data->cmds)
	{
		while (i < data->nb_cmds)
			free(data->cmds[i++].line);
		free(data->cmds);
	}
	if (data->cmd_options)
		free_arr(data->cmd_options);
}

int	main(int ac, char **av, char **envp)
{
	t_data	data;
	char	*line;
//	int		pid_1;

	(void)ac;
	(void)av;

	line = NULL;
	line = readline("prompt>");
	init_data(&data, envp, line);
	while (1)							//
	{									//elise, ca fait boucler pour qu'on puisse faire plusieurs commandes
		line = readline("prompt>");		//
	}									//
	if (line)
	{
	//	pid_1 = fork();
	//	if (pid_1 == -1)
	//		return (perror("fork"), 1);
	//	if (pid_1 == 0)
	//		exec_cmd(line, &data);
		if (split_piped_cmds(line, &data))
			printf("uh oh\n");
	}
	//waitpid(pid_1, NULL, 0);
	printf("goodbye\n");
	free_data(&data);
	return (0);	
}
