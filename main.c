/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 19:31:40 by mmakboub          #+#    #+#             */
/*   Updated: 2022/12/29 18:31:45 by mmakboub         ###   ########.fr       */
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
	t_command *line_cmd1;
	t_command *line_cmd2;
	t_env *envr = build_env(env);


	
	line_cmd = malloc(sizeof(t_command));
	line_cmd->cmd = ft_strdup("ls");
	line_cmd->nbr_args = 2;
	line_cmd->args = malloc(sizeof(char *)*3);
	line_cmd->args[0] = line_cmd->cmd;
	line_cmd->args[1] = strdup("-lRa");
	line_cmd->args[2] = NULL;

	line_cmd1 = malloc(sizeof(t_command));
	line_cmd1->cmd = ft_strdup("grep");
	line_cmd1->nbr_args = 2;
	line_cmd1->args = malloc(sizeof(char *)*3);
	line_cmd1->args[0] = line_cmd1->cmd;
	line_cmd1->args[1] = strdup(".");
	line_cmd1->args[2] = NULL;
	line_cmd->next = line_cmd1;


	line_cmd2 = malloc(sizeof(t_command));
	line_cmd2->cmd = ft_strdup("wc");
	line_cmd2->nbr_args = 1;
	line_cmd2->args = malloc(sizeof(char *)*3);
	line_cmd2->args[0] = line_cmd2->cmd;
	// line_cmd2->args[1] = strdup("");
	line_cmd2->args[1] = NULL;
	line_cmd1->next = line_cmd2;
	handle_pipe(line_cmd, &envr);
	//line_cmd->cmd = readline("minishell ->: ");
	// // cd(line_cmd, &envr);
	// // //pwd();
	// //ft_env2(envr, line_cmd);
	// unset(&envr, line_cmd);
	//export(&envr, line_cmd);
	// execve_cmd(line_cmd, &envr, line_cmd->args);
	// //line_cmd->args[1] = NULL;
	//line_cmd->args[1] = ft_strdup("ee+=lrl");
	//line_cmd->args[2] = ft_strdup("xn+=rergr");
	//line_cmd->args[3] = ft_strdup("xn=+eiej");
	// // // // line_cmd->args[3] = ft_strdup("");
	// return(0);
	//printf("%s\n",getenv("PWD"));
}