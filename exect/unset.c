/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:44:01 by mmakboub          #+#    #+#             */
/*   Updated: 2022/12/18 20:24:21 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

void  ft_remove_from_env(t_env **begin_list, t_env *data_ref)
{
	if (begin_list == NULL || *begin_list == NULL)
		return;

	t_env *tmp = *begin_list;
    printf("%s\n%s\n", tmp->name, data_ref->name);
	if(ft_strcmp(tmp->name, data_ref->name)==0)
	{
		*begin_list = tmp->next;
        free(tmp->name);
        free(tmp->value);
		free(tmp);
		return;
	}
	ft_remove_from_env(&((*begin_list)->next), data_ref);
}

int check_is_digit(int x)
{
    if (x >= '0' && x <= '9')
		return (1);
	return (0);
}

int check_special_caract(char *arg)
{
    int i;
    int j;
    i = 0;
    while(arg[i])
    {
        if(arg[0] != '#' && (check_is_digit(arg[i])) && ((arg[i]< 'A' && arg[i] > 'Z') ||(arg[i] < 'a' && arg[i] > 'z')) && arg[i] != '_')
            return(0);
        i++;
    }
    return(1);
}

t_env *identique_var(char  *arg, t_env **variable)
{
    t_env *tmp;

    while(tmp)
    {
        if(strcmp((*variable)->name, arg) == 0)
        {
            tmp = *variable;
            return(tmp);
        }
        variable = &(*variable)->next;
    }
    return(NULL);
}

void    unset(t_env **variable ,t_command *command)
{
    int i;
    i = 1;
    if(!variable)
        return ;
    if(command->nbr_args >= 2)
    {
        if(command->args[1] && command->args[1][0] == '-')
        {
            printf("-minishell: unset: -%c: invalid option\nunset: usage: unset [-f] [-v] [-n] [-name ...]\n", command->args[1][1]);
            return ;
        }
        while (command->args[i])
        {
            if(!check_is_digit(command->args[i][0]) && check_special_caract(command->args[i]))// && identique_var(command->args[i], variable))
            {
                if(finder_getter(*variable, command->args[i]))
                    ft_remove_from_env(variable, finder_getter(*variable, command->args[i]));
            }
            else
                printf("minishell: unset: `%s': not a valid identifier\n", command->args[1]);
            i++;
        }
    }
    else
        printf("minishell: unset: there is no variable to be unseted\n");
}