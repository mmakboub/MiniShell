/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 19:31:40 by mmakboub          #+#    #+#             */
/*   Updated: 2022/12/29 15:48:05 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include<stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include"./exect/minishell.h"

int main(int ac, char **av, char **env)
{
	t_command *line_cmd;
	t_env *envr = build_env(env);
	line_cmd = malloc(sizeof(t_command));
	//line_cmd->cmd = readline("minishell ->: ");
	line_cmd->cmd = ft_strdup("export");
	line_cmd->nbr_args = 2;
	line_cmd->args = malloc(sizeof(char *)*6);
	line_cmd->args[0] = line_cmd->cmd;
	// //line_cmd->args[1] = NULL;
	line_cmd->args[1] = ft_strdup("xngn");
	//line_cmd->args[2] = ft_strdup("l22ss=jkj");
	//line_cmd->args[3] = ft_strdup("l22ss=jkj");
	// // // // line_cmd->args[3] = ft_strdup("");
	line_cmd->args[2] = NULL;
	// // cd(line_cmd, &envr);
	// // //pwd();
	// //ft_env2(envr, line_cmd);
	// unset(&envr, line_cmd);
	export(&envr, line_cmd);
	ft_env2(envr, line_cmd);
	// return(0);
	//printf("%s\n",getenv("PWD"));
}