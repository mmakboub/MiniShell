/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 21:22:28 by mmakboub          #+#    #+#             */
/*   Updated: 2023/01/09 02:34:40 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_error(int type, int next)
{
	if (next == PIPE)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 1);
		return (1);
	}
	if (next == HERDOC && type != PIPE)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `<<'\n", 1);
		return (1);
	}
	if (check_rest_error(type, next))
		return (1);
	return (0);
}

int	check_quote(char *str, int type)
{
	int	c;
	int	i;

	i = 1;
	if (type == SQUOT)
		c = '\'';
	else
		c = '"';
	while (str[i] && str[i] != c)
		i++;
	if (!str[i] || ft_strlen(str) == 1)
	{
		ft_putstr_fd("minishell: You must close quote\n", 1);
		return (1);
	}
	return (0);
}

int	checklast(t_element *node)
{
	t_element	*lst;

	lst = last(node);
	if (lst->type == PIPE || lst->type == INF || lst->type == SUP
		|| lst->type == ADD || lst->type == HERDOC)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token\n", 1);
		return (1);
	}
	return (0);
}

int	grammar(t_element *node, char **env)
{
	t_element	*s;

	s = node;
	if (node->type == PIPE || last(node)->type == HERDOC)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token \n", 1);
		return (1);
	}
	while (s)
	{
		if (s->type != CMD && s->type != SQUOT && s->type != DQUOT)
			if (s->next && check_error(s->type, s->next->type))
				return (1);
		if (s->type == SQUOT || s->type == DQUOT)
			if (check_quote(s->args[0], s->type))
				return (1);
		if (s->type == HERDOC)
			herdoc(s, env);
		s = s->next;
	}
	if (checklast(node))
		return (1);
	return (0);
}
