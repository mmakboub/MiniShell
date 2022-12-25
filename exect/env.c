/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:20:23 by mmakboub          #+#    #+#             */
/*   Updated: 2022/12/22 18:58:26 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"


void env(t_env **env, t_command *command) //to do : add a condition if THERE IS MORE THAN 1 arg it should print to nmany args 
{
    t_env *tmp;
    tmp = env;
    if(command->nbr_args > 1)
        printf("env: %s: No such file or directory\n", command->args[1]);
    else 
    {      
        while(tmp)
        {
            if(tmp->value)
            {
                printf("%s",tmp->name);
                write(1, '=', 1);
                printf("%s\n", tmp->value);
            }
        }
        tmp = tmp->next;
    }
}