/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2022/11/20 15:55:23 by mmakboub          #+#    #+#             */
/*   Updated: 2022/12/31 01:07:25 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*findevalue(t_env *env, char *name)
{
	while (env && ft_strcmp(env->name, name))
		env = env->next;
	if (env && env->value)
		return (env->value);
	return (NULL);
}

void	pwd(t_env *env, char *name)
{
	char	*path;
	char	*str;

	path = getcwd(NULL, 0);
	add_back_memory(path, 1);
	if (path == NULL)
	{
		str = findevalue(env, name);
		if (str)
			printf("%s\n", &str[1]);
		else
			printf("getcwd couldn't find the pwd\n");
	}
	else
		printf("%s\n", path);
}
