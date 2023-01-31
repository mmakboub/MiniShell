/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2022/11/21 20:14:40 by mmakboub          #+#    #+#             */
/*   Updated: 2022/12/31 00:31:36 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	back_to_home(t_env **env, t_env *oldpwd)
{
	t_env	*home;

	if (!oldpwd)
		return ;
	home = finder_getter(*env, "HOME");
	if (!home)
	{
		printf("Minishell: cd: HOME not set\n");
		return ;
	}
	if (chdir(&home->value[1]) == -1)
		printf("minishell: cd: %s\n", strerror(errno));
}

int	cd_home(t_element *command)
{
	if ((!ft_strcmp(command->args[0], "cd") && command->nbr_args == 1) \
	|| (!ft_strcmp(command->cmd, "cd") && (!ft_strcmp(command->args[1], "--") \
	|| !ft_strcmp(command->args[1], "~") || (command->args[1][0] == '#'))))
		return (0);
	else
		return (1);
}

void	cd_error(void)
{
	printf("minishell: cd: error retrieving current directory: \
getcwd: cannot access parent directories\n");
	chdir("~");
	return ;
}

void	cd2(t_element *command, t_env **env, t_env *pwd, t_env *oldpwd)
{
	if (!cd_home(command))
		back_to_home(env, oldpwd);
	else if (command->nbr_args > 1)
	{
		if (chdir(command->args[1]) == -1)
		{
			printf("minishell: cd: %s\n", strerror(errno));
			g_global.exit_status = 1;
			return ;
		}
		else
		{
			if (!pwd)
			{
				refresh_oldpwd(env, pwd);
				return ;
			}
			if (!oldpwd)
				return ;
		}
	}
	refresh_oldpwd(env, pwd);
	refresh_pwd(env);
	g_global.exit_status = 0;
}

void	cd(t_element *command, t_env **env)
{
	t_env	*pwd;
	char	*ret;
	t_env	*oldpwd;

	pwd = finder_getter(*env, "PWD");
	oldpwd = finder_getter(*env, "OLDPWD");
	ret = getcwd(NULL, 0);
	add_back_memory(ret, 1);
	if (!ret && !ft_strcmp(command->args[1], "."))
		cd_error();
	cd2(command, env, pwd, oldpwd);
}
