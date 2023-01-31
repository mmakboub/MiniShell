/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 08:42:34 by mmakboub          #+#    #+#             */
/*   Updated: 2023/01/08 08:44:50 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*concat(char *s1, char *s2)
{
	int		size;
	int		i;
	int		y;
	char	*ret;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	ret = ft_malloc(sizeof(char) * size, 1);
	i = -1;
	while (s1[++i])
		ret[i] = s1[i];
	y = -1;
	while (s2[++y])
		ret[i + y] = s2[y];
	ret[i + y] = 0;
	return (ret);
}

char	**double_dup(char **s)
{
	char	**ret;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	ret = ft_malloc(sizeof(char *) * (getsize(s) + 1), 1);
	while (s[i])
	{
		ret[i] = ft_strdup(s[i], 1);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

char	**ft_concat(char **s1, char **s2)
{
	int		len;
	char	**ret;
	int		i;
	int		y;

	len = getsize(s1) + getsize(s2) + 1;
	ret = ft_malloc(sizeof(char *) * len, 1);
	i = 0;
	y = 0;
	while (s1[i])
	{
		ret[i] = ft_strdup(s1[i], 1);
		i++;
	}
	while (s2[y])
	{
		ret[i + y] = ft_strdup(s2[y], 1);
		y++;
	}
	ret[i + y] = NULL;
	return (ret);
}

t_element	*duplicate(t_element *n)
{
	t_element	*ret;

	ret = ft_malloc(sizeof(t_element), 1);
	ret->type = n->type;
	ret->args = double_dup(n->args);
	ret->pip[0] = n->pip[0];
	ret->pip[1] = n->pip[0];
	ret->next = NULL;
	return (ret);
}

void	add_node_back(t_element **node, t_element *el)
{
	t_element	*n;
	t_element	*l;

	n = duplicate(el);
	if (*node == NULL)
	{
		*node = n;
	}
	else
	{
		l = last(*node);
		l->next = n;
		n->prev = l;
	}
}
