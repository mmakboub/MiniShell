/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:19:48 by mmakboub          #+#    #+#             */
/*   Updated: 2023/01/08 09:49:51 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	path_error(char *cmd)
{
	int	fd;

	(void)cmd;
	fd = dup(1);
	dup2(2, 1);
	printf("minishell: command not found\n");
	dup2(fd, 1);
	close(fd);
	g_global.exit_status = 127;
	exit(127);
	return ;
}

void	execve_cmd_error(char *path, t_element *command)
{
	if (command->type != HERDOC && (!path || path[0] == '\0'))
		path_error(command->cmd);
	if (!command->args || !command->args[0])
	{
		exit(0);
	}
}

void	execve_failure(char *cmd)
{
	int	fd;

	(void)cmd;
	fd = dup(1);
	dup2(2, 1);
	if (cmd && cmd[0] == '.' && cmd[1] == '/')
	{
		printf("minishell: %s: %s\n", cmd, strerror(errno));
		exit(126);
	}
	if (access(cmd, W_OK) && !access(cmd, F_OK))
	{
		printf("minishell: %s: is a directory\n", cmd);
		exit(126);
	}
	printf("minishell: %s: %s\n", cmd, strerror(errno));
	dup2(fd, 1);
	close(fd);
	g_global.exit_status = 127;
	return ;
}
