/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_initialisation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 23:42:52 by mmakboub          #+#    #+#             */
/*   Updated: 2022/12/25 23:05:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include<string.h>
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
		ft_lstadd_back(ft_lstnew(pwd, 1), env);
		free(pwd);
	}
	while (ft_strcmp("SHLVL", tmp->name) && tmp)
		tmp = tmp->next;
	if(tmp)
	{
		shlvl = ft_atoi(ft_strdup(tmp->value));
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
		ft_lstadd_back((ft_lstnew(new_shlvl, 1)), &tmp);
	}
}