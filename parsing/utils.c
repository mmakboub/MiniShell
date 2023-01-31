/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 21:23:29 by mmakboub          #+#    #+#             */
/*   Updated: 2023/01/08 08:45:53 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	norm_one_rest(t_element *node, t_element *n)
{
	char	**temp;
	char	*t;
	int		i;

	i = getsize(node->args) - 1;
	if (n->space == 0)
	{
		t = node->args[i];
		node->args[i] = concat(node->args[i], n->args[0]);
	}
	else
	{
		temp = node->args;
		node->args = ft_concat(node->args, n->args);
	}
}

t_element	*norm_one(t_element *el)
{
	t_element	*temp;
	t_element	*ret;
	t_element	*prev;

	temp = el;
	ret = NULL;
	while (el)
	{
		prev = el->prev;
		if (prev == NULL)
			add_node_back(&ret, el);
		else if ((el->type == CMD || el->type == SQUOT || el->type == DQUOT) \
				&& (prev->type == CMD || prev->type == SQUOT \
					|| prev->type == DQUOT))
			norm_one_rest(last(ret), el);
		else
			add_node_back(&ret, el);
		el = el->next;
	}
	ret->prev = NULL;
	norm_two(&ret);
	return (ret);
}

void	add_front(t_element **node, char **cmd, t_element **el)
{
	t_element	*prev;
	t_element	*n;

	n = ft_malloc(sizeof(t_element), 1);
	n->args = double_dup(cmd);
	n->type = CMD;
	prev = (*node)->prev;
	(*node)->prev = n;
	n->next = *node;
	n->prev = prev;
	if (prev)
		prev->next = n;
	else
		*el = n;
}

void	norm_two(t_element **el)
{
	t_element	*temp;
	char		**t;

	temp = *el;
	while (temp)
	{
		if ((temp->type == INF || temp->type == ADD || temp->type == SUP
				|| temp->type == HERDOC) && getsize(temp->next->args) > 1)
		{
			if (temp->prev == NULL || temp->prev->type == PIPE)
				add_front(&temp, &temp->next->args[1], el);
			else
			{
				t = temp->prev->args;
				temp->prev->args = ft_concat(temp->prev->args,
						&temp->next->args[1]);
			}
		}
		if (temp->args)
		{
			temp->nbr_args = getsize(temp->args);
			temp->cmd = ft_strdup(temp->args[0], 1);
		}
		temp = temp->next;
	}
}

int	getsize(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
