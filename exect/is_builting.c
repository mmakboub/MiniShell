/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 01:38:45 by mmakboub          #+#    #+#             */
/*   Updated: 2022/12/18 20:38:45 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

void	is_builting(t_command *cmd)//CMD = ARGV[0]
{
	if (!ft_strcmp(command->cmd[0], "echo"))
		echo();
    else if (!ft_strcmp(command->cmd, "pwd"))
        pwd();
    else if (!ft_strcmp(command->cmd, "cd"))
		cd();
    else if (!ft_strcmp(command->cmd, "exit"))
		exit();
    else if (!ft_strcmp(command->cmd, "export"))
		export();
    else if (!ft_strcmp(command->cmd, "unset"))
		unset();
    else if (!ft_strcmp(command->cmd, "env"))
		env();
	else
		check_path(cmd);
}
char	*concatenate(const char *s1, const char *s2, const char *s3)
{
	char	*new_str;
	size_t	len_s1;
	size_t	len_s2;
	size_t	len_s3;
	size_t	j;
	size_t	i;

	if (!s1 || !s2 || !s3)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	len_s3 = ft_strlen(s3);
	new_str = (char *)malloc((len_s1 + len_s2 + len_s3 + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		new_str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		new_str[j++] = s2[i++];
	i = 0;
	while(s3[i])
		new_str[j++] = s3[i++];
	new_str[j] = '\0';
	return (new_str);
}

void env_initialisation(t_env **env)
{
	int shlvl;
	char *pwd;
	t_env *tmp;
	char new_shlvl;

	tmp = *env;
	if(finder_getter(env,"PWD") == NULL)
	{
		pwd = printf("PWD=%s",getcwd(NULL, 0);
		ft_lstadd_back(ft_lstnew(pwd), env);
		free(pwd);
	}
	while (strcmp("SHLVL", tmp->name) && tmp)
		tmp = tmp->next;
	if(tmp)
	{
		shlvl = atoi(ft_strdup(tmp->value));
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
		free(shlvl);
	}
	else
	{
		new_shlvl = printf("SHLVL=%s",);
		ft_lstadd_back((ft_lstnew(new_shlvl)), &tmp);
	}
}
