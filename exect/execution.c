/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:18:27 by mmakboub          #+#    #+#             */
/*   Updated: 2023/01/08 11:52:27 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_lstsize_elem(t_element *lst)
{
	int	len;

	len = 1;
	while (lst)
	{
		if (lst->type == PIPE)
			len++;
		lst = lst->next;
	}
	return (len);
}

void	execve_cmd(t_element *command, t_env **env, char **argv)
{
	char	*path;
	int		pid;

	if (!env || !command)
		return ;
	pid = fork();
	if (pid < 0)
		return (g_global.exit_status = 1, (void)0);
	path = execute_cmd(command, env);
	if (pid == 0)
	{
		sig_default();
		handle_redirection(command, 0);
		if (path && path[0] == '\0')
		{
			if (pid)
				return ;
			exit(0);
		}
		execve_cmd_error(path, command);
		if (execve(path, argv, convertto_doublep(*env)) == -1)
			execve_failure(command->cmd);
		exit(g_global.exit_status);
	}
	handle_exit_status(pid, command);
}

void	check_cmd(t_element *command, t_env **envv)
{
	char	**env;

	env = convertto_doublep(*envv);
	if (finder_getter(*envv, "PATH") == NULL)
	{
		if (check_builtings(command))
			is_builting(command, envv);
		else
		{
			printf("minishell: %s: no such file or directory\n", command->cmd);
			g_global.exit_status = 127;
			return ;
		}
		return ;
	}
	if (ft_lstsize_elem(command) > 1)
		handle_pipe(command, envv);
	else
	{
		expender(command, env);
		if (check_builtings(command))
			is_builting(command, envv);
		else
			execve_cmd(command, envv, command->args);
	}
}
