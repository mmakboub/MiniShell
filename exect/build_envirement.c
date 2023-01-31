/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_envirement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2022/11/26 10:39:54 by mmakboub          #+#    #+#             */
/*   Updated: 2022/12/31 00:08:28 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*receive_name(char *allstr)
{
	char	*name;

	name = ft_strchr(allstr, '=');
	if (!name)
		return (allstr);
	return (ft_substr(allstr, 0, ft_strlen(allstr) - ft_strlen(name), 0));
}

char	*receive_value(char *allstr)
{
	return (ft_substr(allstr, \
			ft_strlen(allstr) - ft_strlen(ft_strchr(allstr, '=')), \
			ft_strlen(allstr), 0));
}

t_env	*ft_lstnew(char *allstr, int flag)
{
	t_env	*newelement;

	newelement = (t_env *)ft_malloc(sizeof(t_env), 0);
	if (newelement == 0)
		return (0);
	if (flag == 1)
		newelement->name = receive_name(allstr);
	else
		newelement->name = receive_name_export(allstr);
	newelement->value = receive_value(allstr);
	newelement->next = NULL;
	return (newelement);
}

void	ft_lstadd_back(t_env *new, t_env **alst)
{
	t_env	*node;

	node = *alst;
	if (alst && *alst)
	{
		while (node && node->next)
		{
			node = node->next;
		}
		node->next = new;
	}
	else
		*alst = new;
}

t_env	*build_env(char **env)
{
	int		i;
	t_env	*tmp;
	char	*pwd;

	tmp = NULL;
	i = 0;
	if (env[0] == NULL)
	{
		pwd = ft_strjoin("PWD=", getcwd(NULL, 0), 0);
		ft_lstadd_back((ft_lstnew(pwd, 1)), &tmp);
		ft_lstadd_back(ft_lstnew("PATH=/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:.\
		", 1), &tmp);
	}
	while (env[i])
	{
		ft_lstadd_back(ft_lstnew(env[i], 1), &tmp);
		i++;
	}
	return (tmp);
}
