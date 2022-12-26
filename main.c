/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:34:13 by mmakboub          #+#    #+#             */
/*   Updated: 2022/12/26 19:26:03 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include"minishell.h"

int main(int ac, char **av, char **env)
{
	t_command *line_cmd0;
	t_command *line_cmd1;
	t_command *line_cmd2;
	// t_env *envr = build_env(env);
	
	line_cmd0 = malloc(sizeof(t_command));
	line_cmd0->args = malloc(sizeof(char *) * 3);
	line_cmd0->cmd = ft_strdup("ls");
	line_cmd0->args[0] = line_cmd0->cmd;
	line_cmd0->args[1] = ft_strdup("-la");;
	line_cmd0->args[2] = NULL;
	line_cmd1 = malloc(sizeof(t_command));
	line_cmd1->args = malloc(sizeof(char *) * 2);
	line_cmd1->cmd = ft_strdup("cat");
	line_cmd1->args[0] = line_cmd1->cmd;
	line_cmd1->args[1] = NULL;
	// line_cmd1->args[1] = ft_strdup("-l");;
	line_cmd0->next = line_cmd1;
	line_cmd2 = malloc(sizeof(t_command));
	line_cmd2->args = malloc(sizeof(char *) * 2);
	line_cmd2->cmd = ft_strdup("ls");
	line_cmd2->args[0] = line_cmd2->cmd;
	line_cmd2->args[1] = NULL;
	// line_cmd2->args[1] = ft_strdup("");;
	line_cmd1->next = line_cmd2;
	handle_pipe(line_cmd0 ,"/bin/ls" , "/bin/cat","/bin/ls",env, line_cmd0->args, line_cmd1->args,line_cmd2->args);
	// line_cmd1->nbr_args = 2;
	// // line_cmd->args[3] = ft_strdup("");
	// cd(line_cmd, &envr);
	// printf("%s", getcwd(NULL,0));
	// ft_env(envr, line_cmd);

	
	return(0);
}