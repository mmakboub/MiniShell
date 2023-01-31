/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 22:57:34 by mmakboub          #+#    #+#             */
/*   Updated: 2023/01/08 12:14:28 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	redirec_out(t_element *tmp, t_element *next_node, int fd, int i)
{
	next_node = tmp->next;
	fd = open(next_node->cmd, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fd < 0)
	{
		perror(next_node->cmd);
		g_global.exit_status = 1;
		if (!i)
			exit(1);
		return (1);
	}
	dup2(fd, 1);
	close(fd);
	return (0);
}

static int	redirec_inp(t_element *tmp, t_element *next_node, int fd, int i)
{
	next_node = tmp->next;
	fd = open(next_node->cmd, O_RDONLY, 0777);
	if (fd < 0)
	{
		perror(next_node->cmd);
		g_global.exit_status = 1;
		if (!i)
			exit(1);
		return (1);
	}
	dup2(fd, 0);
	close(fd);
	return (0);
}

static int	redirec_herdoc(t_element *tmp)
{
	dup2(tmp->pip[0], 0);
	close(tmp->pip[0]);
	return (0);
}

static int	redirec_add(t_element *tmp, t_element *next_node, int fd, int i)
{
	next_node = tmp->next;
	fd = open(next_node->cmd, O_CREAT | O_WRONLY | O_APPEND, 0777);
	if (fd < 0)
	{
		perror(next_node->cmd);
		g_global.exit_status = 1;
		if (!i)
			exit(1);
		return (1);
	}
	dup2(fd, 1);
	close(fd);
	return (0);
}

int	handle_redirection(t_element *red, int i)
{
	t_element	*tmp;
	t_element	*next_node;
	int			fd;
	int			ret;

	tmp = red;
	fd = 0;
	next_node = NULL;
	ret = 0;
	while (tmp)
	{
		if (tmp->type == PIPE)
			break ;
		if (tmp->type == SUP)
			ret = redirec_out(tmp, next_node, fd, i);
		if (tmp->type == INF)
			ret = redirec_inp(tmp, next_node, fd, i);
		if (tmp->type == ADD)
			ret = redirec_add(tmp, next_node, fd, i);
		if (tmp->type == HERDOC)
			ret = redirec_herdoc(tmp);
		tmp = tmp->next;
	}
	return (ret);
}
