/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2022/11/18 12:44:01 by mmakboub          #+#    #+#             */
/*   Updated: 2022/12/18 20:24:21 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_remove_from_env(t_env **begin_list, t_env *data_ref)
{
	t_env	*tmp;

	if (begin_list == NULL || *begin_list == NULL)
		return ;
	tmp = *begin_list;
	if (ft_strcmp(tmp->name, data_ref->name) == 0)
	{
		*begin_list = tmp->next;
		return ;
	}
	ft_remove_from_env(&((*begin_list)->next), data_ref);
}

int	check_is_digit(int x)
{
	if (x >= '0' && x <= '9')
		return (1);
	return (0);
}

int	check_special_caract(char *arg)
{
	int	i;

	i = 0;
	if (ft_strlen(arg) == 0)
		return (0);
	else if (arg[0] == '#')
		return (1);
	else if (check_is_digit(arg[0]) || arg[0] == '-')
		return (0);
	while (arg[i])
	{
		if ((i != 0 && arg[i] == '#') || (arg[i] == '=') || ((arg[i] < 'A'
					&& arg[i] > 'Z') || (arg[i] < 'a' && arg[i] > 'z')))
			return (0);
		i++;
	}
	return (1);
}

void	unset(t_env **variable, t_element *command)
{
	int	i;

	i = 1;
	if (!variable)
		return ;
	if (command->nbr_args >= 2)
	{
		while (command->args[i])
		{
			if (check_special_caract(command->args[i]))
			{
				if (env_finder(*variable, command->args[i]))
					ft_remove_from_env(variable, env_finder(*variable, \
								command->args[i]));
			}
			else
				return (printf("minishell: unset: `%s': \
				not a valid identifier\n", command->args[1]), (void)0);
			i++;
		}
	}
}
