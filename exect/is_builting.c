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

#include <unistd.h>

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

void env_initialisation(t_env **env)
{
	int shlvl;
	char *pwd;
	t_env *tmp;
	int new_shlvl;

	tmp = *env;
	if(finder_getter(env,"PWD") == NULL)
	{
		pwd = printf("PWD=%s",getcwd(NULL, 0);
		ft_lstadd_back(ft_lstnew(pwd), env);
		free(pwd);
	}
	while (strcmp("SHLVL", tmp->name) && tmp)
		tmp = tmp->next;
	if(tmp)
	{
		shlvl = atoi(ft_strdup(tmp->value))
		//new_shlvl = atoi(ft_strdup(tmp->value)) + 1
		free(tmp->value);
		if(shlvl < 0)
			shlvl = 0;
		else if (shlvl == 999)
			shlvl == atoi(ft_strdup(""))
		else if (shlvl >=1000)
		{
			printf("minishell: warning: shell level %s too high, resetting to 1", );
			shlvl = 1;
		}
		else
			tmp->value = ft_itoa(shlvl + 1);
		free(shlvl);
	}
	else
		ft_lstadd_back(FT(ft_lstnew()), &tmp)
	
}