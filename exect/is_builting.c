/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:38:45 by mmakboub          #+#    #+#             */
/*   Updated: 2022/12/18 20:38:45 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	is_builting(t_command *cmd)
{
	if (!ft_strcmp(command->cmd[0], "echo"))
		echo();
    else if (!ft_strcmp(command->cmd[0], "pwd"))
        pwd();
    else if (!ft_strcmp(command->cmd[0], "cd"))
		cd();
    else if (!ft_strcmp(command->cmd[0], "exit"))
		exit();
    else if (!ft_strcmp(command->cmd[0], "export"))
		export();
    else if (!ft_strcmp(command->cmd[0], "unset"))
		unset();
    else if (!ft_strcmp(command->cmd[0], "env"))
		env();
	else
		check_no_builtings(command->cmd)
}

void	check_builtings(t_command **command)
{
	if (ft_strcmp(command->cmd, "echo") && ft_strcmp(command->cmd, "pwd") && ft_strcmp(command->cmd "cd") \
		&& ft_strcmp(command->cmd, "exit") && ft_strcmp(command->cmd, "export") \
		&& ft_strcmp(command->cmd, "unset") && ft_strcmp(command->cmd, "env"))
	{
		check_no_builtings(command)
	}
}
