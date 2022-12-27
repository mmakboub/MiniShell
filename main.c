/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 19:31:40 by mmakboub          #+#    #+#             */
/*   Updated: 2022/12/28 00:15:23 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include<stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include"../minishell.h"

int main(int ac, char **av, char **env)
{
	t_command *line_cmd;
	t_env *envr = build_env(env);
	line_cmd = malloc(sizeof(t_command));
	line_cmd->cmd = ft_strdup("unset");
	line_cmd->nbr_args = 2;
	line_cmd->args = malloc(sizeof(char *)*3);
	line_cmd->args[0] = line_cmd->cmd;
	line_cmd->args[1] = ft_strdup("TERM");
	// line_cmd->args[2] = ft_strdup("alsdj");
	// line_cmd->args[2] = ft_strdup("44747");
	// // // line_cmd->args[3] = ft_strdup("");
	line_cmd->args[2] = NULL;
	// cd(line_cmd, &envr);
	// //pwd();
	ft_env2(envr, line_cmd);
	unset(&envr, line_cmd);
	ft_env2(envr, line_cmd);
	return(0);
}