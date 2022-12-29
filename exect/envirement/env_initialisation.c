/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_initialisation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 23:42:52 by mmakboub          #+#    #+#             */
/*   Updated: 2022/12/29 18:20:28 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
void env_initialisation(t_env **env)
{
	int shlvl;
	char *pwd;
	t_env *tmp;
	char new_shlvl;

	tmp = *env;
	if(finder_getter(tmp,"PWD") == NULL)
	{
		pwd = getcwd(NULL, 0);
		char *joined = ft_strjoin("PWD=", pwd);
		ft_lstadd_back(ft_lstnew(joined, 1), env);
		free(pwd);
	}
	while (ft_strcmp("SHLVL", tmp->name) && tmp)
		tmp = tmp->next;
	if(tmp)
	{
		shlvl = ft_atoi(ft_strdup(tmp->value));
		printf("%d", shlvl);
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
		printf("%d", shlvl);
	}
	else
	{
		new_shlvl = printf("SHLVL=1");
		ft_lstadd_back((ft_lstnew(&new_shlvl, 1)), &tmp);
	}
}

int	ft_lstsize_env(t_env *lst)

{
	int	len;

	len = 0;
	while (lst)
	{
		lst = lst -> next;
		len++;
	}
	return (len);
}

char **convertto_doublep(t_env *env)
{
	int len;
	int i;
	char **dp;
	i = 0;
	len = ft_lstsize_env(env);
	dp = (char **)malloc(sizeof(char *) * (len +1));
	while (env)
	{
		dp[i] = ft_strjoin(env->name, env->value);
		i++;
		env = env->next;
	}
	dp[i] = NULL;
	return(dp);
}

char *convertto_char(t_env *env)
{
	char *p;
	p = ft_strjoin(env->name, env->value);
	if (p == NULL)
		return (NULL);
	return(p);
}