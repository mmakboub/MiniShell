/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 21:16:47 by mmakboub          #+#    #+#             */
/*   Updated: 2023/01/08 23:26:35 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_global	g_global;

void	init_var(int *fd, char **str, int ac)
{
	(void)ac;
	(void)str;
	*fd = dup(1);
	g_global.end = NULL;
	g_global.temp = NULL;
	g_global.sig = 0;
}

void	main_utils(char **env, t_env *envr, int fd_1, char *line)
{
	t_element	*element;

	while (1)
	{
		handling_sig();
		g_global.exit_heredoc = 0;
		line = readline("minishell> ");
		lineisempty(line);
		if (*line)
		{
			add_history(line);
			element = parser(line, env);
			if (element)
			{
				if (!envr)
				{
					printf("sadly ! there is no env\n");
					continue ;
				}
				check_cmd(element, &envr);
				free_memory(1);
			}
		}
		dup2(fd_1, 1);
	}
}

int	main(int ac, char **str, char **env)
{
	t_env	*envr;
	int		fd_1;
	char	*line;

	line = NULL;
	init_var(&fd_1, str, ac);
	envr = build_env(env);
	env_initialisation(&envr);
	main_utils(env, envr, fd_1, line);
	return (0);
}
