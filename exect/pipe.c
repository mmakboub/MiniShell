/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:54:30 by mmakboub          #+#    #+#             */
/*   Updated: 2023/01/08 09:04:16 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	child_for_pipe(t_args args)
{
	if (args.pid == 0)
	{
		if (args.i < args.argc - 1)
		{
			if (dup2(args.fd[1], 1) == -1)
			{
				perror("fd : ");
				return ;
			}
			close(args.fd[1]);
			close(args.fd[0]);
		}
		expender(args.node, args.envv);
		if (check_builtings(args.node))
			is_builting(args.node, args.env);
		else
			execve_cmd(args.node, args.env, args.node->args);
		exit(g_global.exit_status);
	}
	else
		signal(SIGINT, SIG_IGN);
}

void	ft_init_pipe(t_element *node, t_env **env, t_pipe *pipe1)
{
	pipe1->i = 0;
	pipe1->argc = ft_lstsize_elem(node);
	pipe1->in_tmp = dup(0);
	pipe1->envv = convertto_doublep(*env);
}

void	last_one(t_args ar1, t_pipe pipe1)
{
	child_for_pipe(ar1);
	dup_0(pipe1.i, pipe1.argc, pipe1.fd);
}

void	handle_pipe(t_element *node, t_env **env)
{
	t_pipe	pipe1;
	t_args	ar1;

	ft_init_pipe(node, env, &pipe1);
	while (node != NULL)
	{
		if (pipe1.i < pipe1.argc - 1)
			if (pipe(pipe1.fd) == -1)
				return (perror("fd: "), (void)0);
		pipe1.pid = fork();
		ar1.i = pipe1.i;
		ar1.pid = pipe1.pid;
		ar1.argc = pipe1.argc;
		ar1.fd = pipe1.fd;
		ar1.envv = pipe1.envv;
		ar1.env = env;
		ar1.node = node;
		last_one(ar1, pipe1);
		pipe1.i++;
		while (node && node->type != PIPE)
			node = node->next;
		if (node)
			node = node->next;
	}
	dup_1(pipe1.in_tmp, pipe1.fd, pipe1.pid, pipe1.argc);
}
