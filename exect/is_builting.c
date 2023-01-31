/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2022/11/19 01:38:45 by mmakboub          #+#    #+#             */
/*   Updated: 2022/12/31 01:12:59 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	all_lower(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i++])
		cmd[i] = ft_tolower(cmd[i]);
}

int	check_builtings(t_element *command)
{
	if (!command->args || !command->args[0])
		return (0);
	if (!ft_strcmp(command->cmd, "cd") || !ft_strcmp(command->cmd, "echo")
		|| !ft_strcmp(command->cmd, "pwd") || !ft_strcmp(command->cmd, "env")
		|| !ft_strcmp(command->cmd, "export") || !ft_strcmp(command->cmd,
			"unset") || !ft_strcmp(command->cmd, "exit"))
		return (1);
	return (0);
}

void	is_builting(t_element *cmd, t_env **envv)
{
	if (handle_redirection(cmd, 1) == 0)
	{
		if (!ft_strcmp(cmd->cmd, "echo"))
			echo2(cmd->args);
		else if (!ft_strcmp(cmd->cmd, "pwd"))
			pwd(*envv, "PWD");
		else if (!ft_strcmp(cmd->cmd, "cd"))
			cd(cmd, envv);
		else if (!ft_strcmp(cmd->cmd, "exit"))
			ft_exit(cmd);
		else if (!ft_strcmp(cmd->cmd, "export"))
			export(envv, cmd);
		else if (!ft_strcmp(cmd->cmd, "unset"))
			unset(envv, cmd);
		else if (!ft_strcmp(cmd->cmd, "env"))
			ft_env2(*envv, cmd);
	}
}
