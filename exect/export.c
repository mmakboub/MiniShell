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

#include"minishell.h"
void    display_sorted_env(t_env **env)
{
    
	// t_env *tmp = *env;
    // while (tmp != 0)
    // {
    //     printf("%s\n", tmp->data);
    //     tmp= tmp->next;
}

void export(t_command *command, t_env **env)
{
    if((command->nbr_args < 2))
        display_sorted_env(env);
    else
        added_display_env(env) // to do : mnin nji ntraiter l argument tani if condition ila kan arg[2][0] mashi alphabet treturner bash: export: `8=k': not a valid identifier / or !strchr(=)skip it 
}