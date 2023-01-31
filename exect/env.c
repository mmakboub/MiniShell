/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2022/11/23 15:20:23 by mmakboub          #+#    #+#             */
/*   Updated: 2022/12/31 00:50:10 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_env2(t_env *env, t_element *command)
{
	if (command->nbr_args > 1)
	{
		printf("env: %s: No such file or directory\n", command->args[1]);
		g_global.exit_status = 127;
		return ;
	}
	else
	{
		while (env)
		{
			if (env->value)
				printf("%s%s\n", env->name, env->value);
			env = env->next;
		}
		g_global.exit_status = 0;
	}
}
