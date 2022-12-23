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

#include"minishell.h"

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
	else
		check_cmd(cmd);// check if herdoc , redirection or pipe or command or command not found;
}

void env_initialisation(t_env **env)
{
	int shlvl;
	char *pwd;
	t_env *tmp;
	char new_shlvl;

	tmp = *env;
	if(finder_getter(env,"PWD") == NULL)
	{
		pwd = printf("PWD=%s",getcwd(NULL, 0));
		ft_lstadd_back(ft_lstnew(pwd), env);
		free(pwd);
	}
	while (strcmp("SHLVL", tmp->name) && tmp)
		tmp = tmp->next;
	if(tmp)
	{
		shlvl = atoi(ft_strdup(tmp->value));
		//new_shlvl = atoi(ft_strdup(tmp->value)) + 1;
		free(tmp->value);
		if(shlvl < 0)
			shlvl = 0;
		//else if (shlvl == 999)
			//shlvl == atoi(ft_strdup(""));
		// else if (shlvl >=1000)
		// {
		// 	printf("minishell: warning: shell level %s too high, resetting to 1", );
		// 	shlvl = 1;
		// }
		else
			tmp->value = ft_itoa(shlvl) + 1;
		free(shlvl);
	}
	else
	{
		new_shlvl = printf("SHLVL=1");
		ft_lstadd_back((ft_lstnew(new_shlvl)), &tmp);
	}
}
