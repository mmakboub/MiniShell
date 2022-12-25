/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:34:13 by mmakboub          #+#    #+#             */
/*   Updated: 2022/12/25 20:24:55 by mmakboub         ###   ########.fr       */
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
	line_cmd = malloc(sizeof(t_command));
	line_cmd->cmd = ft_strdup("exit");
	line_cmd->args = malloc(sizeof(char *));
	line_cmd->nbr_args = 2;
	line_cmd->args[0] = line_cmd->cmd;
	line_cmd->args[1] = ft_strdup("y0t");
	// line_cmd->args[2] = ft_strdup("44747");
	// // line_cmd->args[3] = ft_strdup("");
	line_cmd->args[3] = NULL;
	ft_exit(line_cmd);
	return(0);
}