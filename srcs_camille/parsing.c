/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claclau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:45:07 by claclau           #+#    #+#             */
/*   Updated: 2023/03/14 15:17:11 by claclau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	nb_pipes(char *line)
{
	int	i;
	int	nb_pipes;

	i = 0;
	nb_pipes = 0;
	while (line[i])
	{
		if (line[i] == '|')
			nb_pipes++;
		i++;
	}
	return (nb_pipes);
}

int	split_piped_cmds(char *line, t_data *data)
{
	int	i;
	int	cmd_start;
	int	cmd_id;
	int	pipe_fd[2];
	int	prev_pipe_fd[2];

	i = 0;
	cmd_start = 0;
	cmd_id = 0;
	if (line[0] == '|')
		return (printf("syntax error near unexpected token '|'\n"), 1);
	while (line[i])
	{
		if (line[i] == '|')
		{
			if (fill_cmd_line(&data->cmds[cmd_id], line, cmd_start, i - cmd_start))
				return (1);; // err mess
			if (pipe(pipe_fd) == -1)
				return (perror("pipe"), 2);
			// create fill_cmd_fds, try to separer les differents cas de figure
			data->cmds[cmd_id].fd_out = pipe_fd[1];
			if (cmd_id == 0)
				data->cmds[cmd_id].fd_in = STDIN_FILENO;
			else
				data->cmds[cmd_id].fd_in = prev_pipe_fd[0];
			cmd_id++;
			cmd_start = i + 1;
			prev_pipe_fd[0] = pipe_fd[0];
			prev_pipe_fd[1] = pipe_fd[1];
		}
		i++;
	}
	if (fill_cmd_line(&data->cmds[cmd_id], line, cmd_start, i - cmd_start))
				return (1);; // err mess
	data->cmds[cmd_id].fd_out = STDOUT_FILENO;
	data->cmds[cmd_id].fd_in = prev_pipe_fd[0];
	return (0);
}

int	fill_cmd_line(t_cmd *cmd, char *line, int cmd_start, int cmd_end)
{
	cmd->line = ft_substr(line, cmd_start, cmd_end - cmd_start);
	if (!cmd->line)
		return (1); // maybe err mess
	return (0);
}
