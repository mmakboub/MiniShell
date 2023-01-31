/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 09:03:39 by mmakboub          #+#    #+#             */
/*   Updated: 2023/01/09 01:24:02 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

void	dup_1(int in_tmp, int fd[2], int pid, int argc)
{
	int	i;
	int	status;

	i = 1;
	if (dup2(in_tmp, 0) == -1)
	{
		perror("fd : ");
		return ;
	}
	close(in_tmp);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid, &status, 0);
	g_global.exit_status = WEXITSTATUS(status);
	i = 1;
	while (i < argc)
	{
		wait(NULL);
		i++;
	}
}

void	dup_0(int i, int argc, int fd[2])
{
	if (i < argc - 1)
	{
		if (dup2(fd[0], 0) == -1)
		{
			perror("fd : ");
			return ;
		}
		close(fd[1]);
		close(fd[0]);
	}
}
