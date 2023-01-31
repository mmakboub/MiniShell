/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 08:54:24 by mmakboub          #+#    #+#             */
/*   Updated: 2023/01/08 08:54:54 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_garbage	*new_node(void *mem)
{
	t_garbage	*node;

	node = malloc(sizeof(t_garbage));
	if (!node)
		exit(1);
	node->memory = mem;
	node->next = NULL;
	return (node);
}

t_garbage	*last_memory(t_garbage *mem)
{
	t_garbage	*temp;

	temp = mem;
	if (!mem)
		return (NULL);
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	add_back_memory(void *mem, int i)
{
	t_garbage	*node;

	if (i)
		node = g_global.temp;
	else
		node = g_global.end;
	if (!node)
	{
		node = new_node(mem);
		if (i)
			g_global.temp = node;
		else
			g_global.end = node;
	}
	else
		last_memory(node)->next = new_node(mem);
}

void	free_memory(int i)
{
	t_garbage	*node;
	t_garbage	*temp;

	if (i)
		node = g_global.temp;
	else
		node = g_global.end;
	while (node)
	{
		temp = node;
		node = node->next;
		if (temp->memory)
			free(temp->memory);
		temp->memory = NULL;
		free(temp);
	}
	node = NULL;
	if (i)
		g_global.temp = node;
	else
		g_global.end = node;
}

void	*ft_malloc(size_t len, int type)
{
	void	*ret;

	ret = malloc(len);
	if (!ret)
		exit(1);
	add_back_memory(ret, type);
	return (ret);
}
