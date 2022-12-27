/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_envirement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:39:54 by mmakboub          #+#    #+#             */
/*   Updated: 2022/12/22 19:01:03 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"


void	refresh_oldpwd(t_env	**env, t_env *pwd)
{
	t_env *tmp;
	tmp = *env;
	char *joined;
	while(tmp && ft_strcmp(tmp->name, "OLDPWD"))
		tmp = tmp->next;
	if(tmp && tmp->value)
	{
		free(tmp->value);
		tmp->value = NULL;
		tmp->value = pwd->value;
	}
	else
		joined = ft_strjoin("OLDPWD=",pwd->value);
		ft_lstadd_back(ft_lstnew(joined, 1), env);
}

t_env	*finder_getter(t_env	*env, char *name)
{
	while(env && ft_strcmp(env->name, name))
		env = env->next;
	if(env && env->value)
		return(env);
	return(NULL);
}
void	refresh_pwd(t_env **env)
{
	char *pwd;
	t_env	*head;
	head = *env;
	while(head && ft_strcmp(head->name, "PWD"))
		head = head->next;
	if(head && head->value)
	{
		free(head->value);
		head->value = NULL;
		head->value = getcwd(NULL, 0);
	}
	else
		pwd = getcwd(NULL, 0);
		char *joined = ft_strjoin("PWD=", pwd);
		ft_lstadd_back(ft_lstnew(joined, 1), env);
}

char *receive_name(char *allstr)// allstr == line . start reading from 0 until len(strchr(=))
{
    return(ft_substr(allstr, 0, ft_strlen(allstr) - ft_strlen(ft_strchr(allstr, '='))));
}

char *receive_value(char *allstr)
{
     return(ft_substr(allstr, ft_strlen(allstr) - ft_strlen(ft_strchr(allstr, '=')), ft_strlen(allstr)));
}

t_env   *build_env(char **env)
{
    int i;
    t_env   *tmp;

    tmp = NULL;
    i = 0;
    while(env[i])
    {
        ft_lstadd_back(ft_lstnew(env[i], 1), &tmp);
        i++;
    }
    return(tmp);
}
