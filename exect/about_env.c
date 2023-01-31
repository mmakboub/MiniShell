/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:04:39 by mmakboub          #+#    #+#             */
/*   Updated: 2023/01/08 05:41:40 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*finder_getter(t_env *env, char *name)
{
	while (env && ft_strcmp(env->name, name))
		env = env->next;
	if (env && env->value)
		return (env);
	return (NULL);
}

int	ft_lstsize_env(t_env *lst)
{
	int	len;

	len = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}

t_env	*env_finder(t_env *env, char *name)
{
	while (env && ft_strcmp(env->name, name))
		env = env->next;
	if (env)
		return (env);
	return (NULL);
}

void	printf_env(t_env **env)
{
	t_env	*current;

	current = *env;
	sort_env(current);
	while (current != 0)
	{
		if (current->value)
		{
			printf("declare -x %s", current->name);
			printf("%s\n", current->value);
		}
		else
			printf("declare -x %s\n", current->name);
		current = current->next;
	}
	g_global.exit_status = 0;
}

t_env	*sort_env(t_env *env)
{
	char	*tmp_name;
	char	*tmp_value;
	t_env	*temp_head;
	int		i;

	temp_head = env;
	i = ft_lstsize_env(temp_head);
	while (i-- > 0)
	{
		temp_head = env;
		while (temp_head != NULL && temp_head->next != NULL)
		{
			if (temp_head->name[0] > temp_head->next->name[0])
			{
				tmp_name = temp_head->name;
				tmp_value = temp_head->value;
				temp_head->name = temp_head->next->name;
				temp_head->value = temp_head->next->value;
				temp_head->next->name = tmp_name;
				temp_head->next->value = tmp_value;
			}
			temp_head = temp_head->next;
		}
	}
	return (env);
}
