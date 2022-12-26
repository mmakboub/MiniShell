/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:34:13 by mmakboub          #+#    #+#             */
/*   Updated: 2022/12/26 17:09:23 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include"minishell.h"

int main(int ac, char **av, char **env)
{
	t_command *line_cmd;
	t_env *envr = build_env(env);
	
	line_cmd = malloc(sizeof(t_command));
	line_cmd->cmd = ft_strdup("cd");
	line_cmd->args = malloc(sizeof(char *));
	line_cmd->nbr_args = 1;
	line_cmd->args[0] = line_cmd->cmd;
	//line_cmd->args[1] = ft_strdup("y0t");
	// line_cmd->args[2] = ft_strdup("44747");
	// // line_cmd->args[3] = ft_strdup("");
	line_cmd->args[1] = NULL;
	cd(line_cmd, &envr);
	return(0);
}