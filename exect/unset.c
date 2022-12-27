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

int check_special_caract(char **arg)
{
    int i;
    int j;
    i = 1;
    while(arg[i])
    {
        j = 0;
        while(arg[i][j])
        {
            if(arg[i][0] != '#' &&  check_is_digit(arg[i][0]) == 1 && ((arg[i][j] >= 'A' && arg[i][j] <= 'Z') ||(arg[i][j] >= 'a' && arg[i][j] <= 'z')) && arg[i][j] != '_')
            {
                printf("-minishell: unset: -%s: not a valid identifier\n", arg[i]);
                return(1);
            }
            j++;
        }
        i++;
    }
    return(0);
}

t_env *identique_var(char  *arg, t_env **variable)
{
    t_env *tmp;

    while(tmp)
    {
            puts("ok");
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
            printf("-minishell: unset: -%s: invalid option\nunset: usage: unset [-f] [-v] [-n] [-name ...]\n", command->args[1]);
            return ;
        }
        while (command->args[i])
        {
            // if(!check_is_digit(command->args[1][0]) && !check_special_caract(command->args) && identique_var(command->args[i], variable))
               ft_remove_from_env(variable, finder_getter(*variable, command->args[i]));
            i++;
        }
    }
    else
        printf("minishell: unset: there is no variable to be unseted\n");
}