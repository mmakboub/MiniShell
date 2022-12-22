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

	if(cmp(tmp->value, data_ref->value) == 0)
	{
		*begin_list = tmp->next;
		free(tmp);
		ft_remove_from_env(begin_list, data_ref);
	}
	tmp = *begin_list;
	ft_remove_fron_env(tmp, data_ref);
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
    i = 0;
    while(arg[i])
    {
        j = 0;
        while(arg[i][j])
        {
            if(arg[i][0] != '#' &&  check_is_digit(arg[i][0]) == 1 && /
                ((arg[i][j] >= 'A' && arg[i][j] <= 'Z') ||(arg[i][j] >= 'a' && arg[i][j] <= 'z')) && arg[i][j] != '_')
                {
                    printf("-minishell: unset: -%s: not a valid identifier\n", command->args[1]);
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
        if(strcmp((*variable)->name, arg) == 0)
        {
            tmp = *variable;
            return(tmp);
        }
        variable = (*variable)->next;
    }
    return(NULL);
}

void    unset(t_env **variable ,t_command *command)
{
    int i;

    i = 1;
    if(!variable)
        return ;
    if(command->nb_args >= 2)
    {
        if(command->args[1] && command->args[1][0] == '-')
        {
            printf("-minishell: unset: -%s: invalid option\n", command->args[1]);
            printf("unset: usage: unset [-f] [-v] [-n] [-name ...]");
        }
        while (command->args[i])
        {
            if(!check_is_digit(command->args[i][0]) && !check_special_caract(command->args[i]) && identique_var(command->arg[i], variable))
            {
               remove_from_env(variable, finder_getter(&variable, command->args[i]));
            }
            i++;
        }
    }      
}