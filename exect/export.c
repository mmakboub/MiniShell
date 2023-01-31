/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2022/11/21 11:05:55 by mmakboub          #+#    #+#             */
/*   Updated: 2022/12/18 20:39:00 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	export1(t_env **env, t_element *command, int i)
{
	t_env	*newelement;

	newelement = (t_env *)ft_malloc(sizeof(t_env), 0);
	if (newelement == 0)
		return ;
	newelement->name = ft_strdup(command->args[i], 0);
	newelement->value = NULL;
	newelement->next = NULL;
	ft_lstadd_back(newelement, env);
}

void	export_main(t_element	*command, t_env **env, int i)
{
	t_env	*tmp;

	if (check_plus(command->args[i], '+', '='))
	{
		if (env_finder(*env, receive_name_export(command->args[i])))
		{
			tmp = env_finder(*(env), receive_name_export(command->args[i]));
			if (tmp->value)
				tmp->value = ft_strjoin(tmp->value,
						receive_value_export(command->args[i]), 0);
			else
				tmp->value = receive_value_export(command->args[i]);
		}
		else
			ft_lstadd_back(ft_lstnew(command->args[i], 2), env);
	}
	else
	{
		if (env_finder(*env, receive_name(command->args[i])))
			env_finder(*env, receive_name(command->args[i]))->value \
			= receive_value(command->args[i]);
		else
			ft_lstadd_back(ft_lstnew(command->args[i], 1), env);
	}
}

void	export(t_env **env, t_element *command)
{
	int	i;

	i = 1;
	if (command->nbr_args == 1 || (command->nbr_args == 2 && \
	(command->args[1][0] == '#' || !ft_strcmp(command->args[1], ";"))))
		return (printf_env(env), (void)0);
	while (command->args[i])
	{
		if (!check_is_valid(command->args[i]))
			return ;
		if (env_finder(*env, receive_name(command->args[i])))
		{
			env_finder(*env, receive_name(command->args[i]))->value \
			= receive_value(command->args[i]);
			i++;
			g_global.exit_status = 0;
			continue ;
		}
		if (check_caract(command->args[i], '=') == 1)
			export_main(command, env, i);
		else
			export1(env, command, i);
		i++;
	}
	g_global.exit_status = 0;
}
