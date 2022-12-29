/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:05:55 by mmakboub          #+#    #+#             */
/*   Updated: 2022/12/18 20:39:00 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

int check_caract(char *str, char c)
{
    int i = 1;
    if(!str)
        return(0);
    while(str[i])
    {
        if(str[i] == c)
            return(1);
        i++;
    }
    return(0);
}
int check_plus(char *str, char c, char x)
{
    if (!str)
        return(0);
    int i = 0;
    while(str[i] && str[i + 1])
    {
        if(str[i] == c && str[i + 1] == x)
            return(1);
        i++;
    }
    return(0);
}
void	printf_env(t_env **env)
{
	t_env *current = *env;
	while (current != 0)
	{
		printf("declare -x %s", current->name);
        if(current->value)
            printf("=%s\n",current->value);
		current = current->next;
	}
}

char *receive_name_export(char *allstr)// allstr == line . start reading from 0 until len(strchr(=))
{
    return(ft_substr(allstr, 0, strlen(allstr) - strlen(strchr(allstr, '+'))));
}

char *receive_value_export(char *allstr)
{
     return(ft_substr(allstr, strlen(allstr) - strlen(strchr(allstr, '=')) + 1, strlen(allstr)));
}
t_env	*env_finder(t_env	*env, char *name)
{
	while(env && strcmp(env->name, name))
		env = env->next;
	if(env)
		return(env);
	return(NULL);
}
int check_is_valid(char *str)
{
    int i;
    i= 0;
	if (str[0] == '-')
	{
		printf("minishell: export: -%c: invalid option \n", str[1]);
		printf("export: usage: export [name[=value]...] or export \n");
        return 0;
	}
    while(str[i])
    {
	    if (ft_isdigit(str[0]) || (str[i] = '+' && str[i+1] != '=') ||(str[i] < 'A' && str[i] > 'Z') ||(str[i] < 'a' && str[i] > 'z') || (!ft_strcmp(str, "-")))
        {
            printf("minishell: export: `%s': not a valid identifier", str);
            return 0;
        }
    i++;
    }
    return 1;
}

void export(t_env **env, t_command *command)
{
    int i = 1;
    t_env *tmp;
    if(command->nbr_args == 1 || (command->nbr_args == 2 && (!ft_strcmp(command->args[1], "#") || !ft_strcmp(command->args[1], ";" ))))
        printf_env(env);
    while(command->args[i])
    {
        if(check_caract(command->args[i], '=') == 1)
        {
            // if (!check_is_valid(command->args[i]))
            //     return;
            if(check_plus(command->args[i], '+', '='))
            {
                if(env_finder(*env,receive_name_export(command->args[i])))
                {
                    tmp = env_finder(*(env),receive_name_export(command->args[i]));
                    if (tmp->value)
                        tmp->value = ft_strjoin(tmp->value, receive_value_export(command->args[i]));
                    else
                        tmp->value = receive_value_export(command->args[i]); 
                }
                else
                    ft_lstadd_back(ft_lstnew(command->args[i], 2), env);
            }
            else
            {
                if(env_finder(*env,receive_name(command->args[i])))
                    env_finder(*env,receive_name(command->args[i]))->value = receive_value_export(command->args[i]);
                else
                {
                    puts(command->args[i]);
                    ft_lstadd_back(ft_lstnew(command->args[i], 1), env);
                }
            }
        }
        else
        {
            t_env	*newelement;
            newelement = (t_env *)malloc(sizeof(t_env));
            if (newelement == 0)
                return ;
            newelement->name = command->args[i];
            newelement->value = NULL;
            ft_lstadd_back(newelement, env);
        }
        i++;
    }

        printf_env(env);

}