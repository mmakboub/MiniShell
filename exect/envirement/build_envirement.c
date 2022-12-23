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

#include"minishell.h"

void	refresh_oldpwd(t_env	**env, char *pwd)
{
	t_env *tmp;
	tmp = *env;
	char *oldpwd;
	while(tmp && strcmp(tmp->name, "OLDPWD"))
		tmp = tmp->next;
	if(tmp && tmp->value)
	{
		free(tmp->value);
		tmp->value = NULL;
		tmp->value = pwd;
	}
	else
		oldpwd = printf("OLDPWD=%s",pwd);
		ft_lstadd_back(ft_lstnew(oldpwd), env);
}

t_env	*finder_getter(t_env	*env, char *name)
{
	while(env && strcmp(env->name, name))
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
	while(head && strcmp(head->name, "PWD"))
		head = head->next;
	if(head && head->value)
	{
		free(head->value);
		head->value == NULL;
		head->value = getcwd(NULL, 0);
	}
	else
		pwd = printf("PWD=%s",getcwd(NULL, 0));
		ft_lstadd_back(ft_lstnew(pwd), env);
}

char receive_name(char *allstr)// allstr == line . start reading from 0 until len(strchr(=))
{
    return(ft_substr(allstr, 0, strlen(allstr) - strlen(strchr(allstr, '='))));
}

char receive_value(char *allstr)
{
     return(ft_substr(allstr, strlen(allstr) - strlen(strchr(allstr, '=')), "\0"));
}

t_env   *build_env(char **env)
{
    int i;
    t_env   *tmp;

    tmp = NULL;
    i = 0;
    while(env[i])
    {
        ft_lstadd_back(ft_lstnew(env[i]), &tmp);
        i++;
    }
    return(tmp);
}
