/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 01:38:45 by mmakboub          #+#    #+#             */
/*   Updated: 2022/12/18 20:38:45 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"


int	check_builtin(t_command *command)
{
	if (!ft_strcmp(command->cmd, "cd") || !ft_strcmp(command->cmd, "echo")
	|| !ft_strcmp(command->cmd, "pwd") || !ft_strcmp(command->cmd, "env")
	|| !ft_strcmp(command->cmd, "export") || !ft_strcmp(command->cmd, "unset") 
	|| !ft_strcmp(command->cmd, "exit"))
		return (1);
	return (0);
}

void	is_builting(t_command *cmd, t_env **envv)//CMD = ARGV[0]
{
	if (!ft_strcmp(cmd->cmd, "echo"))
		echo(cmd->args);
    else if (!ft_strcmp(cmd->cmd, "pwd"))
        pwd();
    else if (!ft_strcmp(cmd->cmd, "cd"))
		cd(cmd, envv);
    else if (!ft_strcmp(cmd->cmd, "exit"))
		exit(cmd);
    else if (!ft_strcmp(cmd->cmd, "export"))
		export(cmd, envv);
    else if (!ft_strcmp(cmd->cmd, "unset"))
		unset(envv, cmd);
    else if (!ft_strcmp(cmd->cmd, "env"))
		env(envv, cmd);
}


