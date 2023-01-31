/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_initialisation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 23:42:52 by mmakboub          #+#    #+#             */
/*   Updated: 2023/01/08 08:30:40 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*put_my_shlvl(char *str)
{
	return (ft_substr(str, \
			ft_strlen(str) - ft_strlen(ft_strchr(str, '=') + 1), \
				ft_strlen(str), 0));
}

void	pwd_emty_env(char *name, t_env **env)
{
	char	*pwd;

	if (ft_strcmp(name, "PWD"))
	{
		pwd = getcwd(NULL, 0);
		add_back_memory(pwd, 1);
		ft_lstadd_back((ft_lstnew(pwd, 1)), env);
	}
}

void	env_initialisation(t_env **env)
{
	t_env	*head;
	char	*shlvl;
	char	*new_shlvl;

	head = *env;
	while (head)
	{
		if (ft_strcmp(head->name, "SHLVL") == 0)
		{
			shlvl = ft_itoa((ft_atoi(put_my_shlvl(head->value)) + 1), 0);
			if (!shlvl)
				return (printf("minishell: memory was not allocated!\n"), \
					g_global.exit_status = 1, (void)0);
			head->value = ft_strjoin("=", shlvl, 0);
			return ;
		}
		head = head->next;
	}
	new_shlvl = ft_strdup("SHLVL=1", 0);
	ft_lstadd_back((ft_lstnew(new_shlvl, 1)), env);
}
